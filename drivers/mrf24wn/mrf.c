/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "mrf.h"
#include "osal.h"

struct netif wlan;
static err_t wifi_send(struct netif * interface, struct pbuf * pb);
static void wifi_receive(struct netif * interface, struct pbuf * pb);
static void wifi_set_state(bool connected);
static bool wifi_ready = false;
static bool wifi_started = false;
SemaphoreHandle_t sem_wifi_connected;
SemaphoreHandle_t sem_wifi_ip_ready;

static uint32_t s_wdrvext_config[] = {
    0u, // MODULE_EVENT_PRINT, 
    TASK_PRIORITY_NORMAL, // WDRV_EXT_RTOS_INIT_TASK_PRIORITY, 
    TASK_PRIORITY_HIGH, // WDRV_EXT_RTOS_MAIN_TASK_PRIORITY,
    512u, // WDRV_EXT_RTOS_INIT_TASK_SIZE, 
    2048u, // WDRV_EXT_RTOS_MAIN_TASK_SIZE, 
    5u, // WDRV_BOARD_TYPE 5=DRV_BD_TYPE_CUSTOM
};

static void WPSDoneCB(void);
static void ScanDoneCB(uint32_t status);
static void InitDoneCB(void);
static void RFReadyCB(uint8_t const *const addr);
static void ReceiveCB(uint32_t len, uint8_t const *const frame);
static void ProceedConnectEventCB(uint32_t connected, uint8_t devID, uint8_t *mac, bool macConn, uint8_t reason);
static WDRV_CALLBACKS MRF_CB = {
    .CopyFrameToStackPacketBuffer_CB = ReceiveCB,
    .ProceedConnectEvent_CB = ProceedConnectEventCB,
    .RFReady_CB = RFReadyCB,
    .ScanDone_CB = ScanDoneCB,
    .InitDone_CB = InitDoneCB,
    .WPSDone_CB = WPSDoneCB
};

static char * s_connect_failure_reason[] = {
    "",
    "NO_NETWORK_AVAIL",
    "LOST_LINK",
    "DISCONNECT_CMD",
    "BSS_DISCONNECTED",
    "AUTH_FAILED",
    "ASSOC_FAILED",
    "NO_RESOURCES_AVAIL",
    "CONNECTION_DENIED",
    "",
    "INVALID_PROFILE",
    "",
    "PROFILE_MISMATCH",
    "CONNECTION_EVICTED",
};

// CALLBACKS ///////////////////////////////////////////////////////////////////

static void ScanDoneCB(uint32_t status) {
}

static void WPSDoneCB(void) {
}

static void RFReadyCB(uint8_t const * const addr) {
    g_wdrv_priv.updateMacAddressRequired = 1;
    memcpy(g_wdrv_priv.macAddr, addr, sizeof (g_wdrv_priv.macAddr));
    memcpy(wlan.hwaddr, addr, ETHARP_HWADDR_LEN);
    //LOG_HEX("[MRF] MAC: %s", addr, sizeof (g_wdrv_priv.macAddr));
}

static void InitDoneCB(void) {
    LOG("[MRF] Init Done\n");
    WDRV_Connect();
}

static void ReceiveCB(uint32_t len, uint8_t const *const frame) {
    if (!WDRV_isPacketValid(frame))
        return;
    //LOG("[MRF] ReceiveCB()\n");  
    struct pbuf * pb = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
    if (pb) {
        pbuf_take(pb, frame, len);
        wifi_receive(&wlan, pb);
    } else {
        LOG_ERROR();
    }
}

static void ConnectionStateUpdate(bool connected, uint8_t reason) {
    static bool _conn_state = false;
    if (connected != _conn_state) {
        wifi_set_state(connected);
        _conn_state = connected;
    }
}

static void ProceedConnectEventCB(uint32_t connected, uint8_t devID, uint8_t *mac, bool macConn, uint8_t reason) {
    const uint8_t macAllFF[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    static bool softAPStarted = false;
    if (connected == true) {
        if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_INFRASTRUCTURE) {
            ConnectionStateUpdate(connected, reason);
            LOG("[MRF] WIFI Connected to AP\n");
        } else if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_SOFT_AP) {
            if (!softAPStarted) {
                softAPStarted = true;
                ConnectionStateUpdate(connected, reason);
                LOG("[MRF] SoftAP network is enabled\r\n");
            } else {
                MRF_ClientCacheUpdate(connected, mac);
                LOG("A client is connected\n");
            }
        }
    } else if (connected == false) {
        if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_INFRASTRUCTURE) {
            ConnectionStateUpdate(connected, reason);
            LOG("[MRF] Connection failed - %s\n", s_connect_failure_reason[reason]);
        } else if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_SOFT_AP) {
            if (memcmp(mac, macAllFF, 6) == 0) {
                softAPStarted = false;
                ConnectionStateUpdate(connected, reason);
                LOG("[MRF] SoftAP network is disabled\n");
            } else {
                MRF_ClientCacheUpdate(connected, mac);
                LOG("[MRF] A client has left\n");
            }
        }
    }
}

void WDRV_Init(void) {
    WDRV_Config();
    memset(g_wdrv_priv.macAddr, 0, sizeof (g_wdrv_priv.macAddr));
    g_wdrv_priv.isDriverOpen = false;
    g_wdrv_priv.updateMacAddressRequired = false;
    g_wdrv_priv.isScanDone = false;
    g_wdrv_priv.isConnReestablished = false;
    g_wdrv_priv.isDisconnectRequested = true;
    WDRV_SemInit(&g_wdrv_priv.disconnectDoneSync);
    WDRV_MUTEX_CREATE(&g_wdrv_priv.debugConsoleLock);
    WDRV_SPI_Init();
    WDRV_HibernateDisable();
    WDRV_EXT_Misc_Config(s_wdrvext_config);
    WDRV_EXT_Initialize(&MRF_CB);
}

// NETIF ///////////////////////////////////////////////////////////////////////

err_t wifi_send(struct netif * interface, struct pbuf * pb) {
    if (!pb) return ERR_ARG;
    struct netif * netif;
    for (netif = netif_list; (netif != NULL) && (netif->state != (void*) interface); netif = netif->next);
    if (netif == NULL) {
        pbuf_free(pb);
        pb = NULL;
        return ERR_IF;
    }
    if (WDRV_EXT_DataSend(pb->len, pb->payload)) {
        LWIP_ASSERT("MRF-TX", 1);
        return ERR_IF;
    }
    return 0;
}

void wifi_receive(struct netif * interface, struct pbuf * pb) {
    if (!pb) return;
    struct netif * netif;
    for (netif = netif_list; (netif != NULL) && (netif->state != (void*) interface); netif = netif->next);
    if (netif == NULL) {
        pbuf_free(pb);
        pb = NULL;
        LINK_STATS_INC(link.drop);
        return;
    }
    LINK_STATS_INC(link.recv);
    if (netif->input(pb, netif)) {
        pbuf_free(pb);
        pb = NULL;
    }
}

static void dhcp_ip_ready_callback(struct netif * netif) {
    if (!netif) return;
    if (!ip4_addr_isany_val(netif->ip_addr)) {
        if (NULL != inet_ntoa(netif->ip_addr)) {
            if (sem_wifi_ip_ready)
                xSemaphoreGive(sem_wifi_ip_ready);
        } else {
            LOG_ERROR();
        }
    }
}

void wifi_set_state(bool connected) {
    if (connected) {
        netif_set_status_callback(&wlan, dhcp_ip_ready_callback);
        netif_set_link_up(&wlan);
        netif_set_up(&wlan);
        netif_set_default(&wlan);
        if (0 == wlan.ip_addr.addr)
            if (dhcp_start(&wlan) != ERR_OK) {
                LOG_ERROR();
            }
        if (sem_wifi_connected)
            xSemaphoreGive(sem_wifi_connected);
    } else {
        netif_set_down(&wlan);
    }
}

static err_t wifi_low_level_init(struct netif * netif) {
    if (!netif) return ERR_ARG;
    netif->name[0] = 'w';
    netif->name[1] = '0';
    netif->output = etharp_output;
#if LWIP_IPV6
    netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */
    netif->linkoutput = wifi_send;
    netif->mtu = MRF_MAX_PACKET_SIZE;
    netif->hwaddr_len = ETHARP_HWADDR_LEN;
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;
    WDRV_Init();
    return ERR_OK;
}

static void wifi_netif_init(const char * IP, const char * GATEWAY, const char * MASK) {
    ip4_addr_t my_ip = {.addr = 0};
    ip4_addr_t my_mk = {.addr = 0};
    ip4_addr_t my_gw = {.addr = 0};
    if (IP) inet_aton(IP, &my_ip);
    if (GATEWAY) inet_aton(GATEWAY, &my_gw);
    if (MASK) inet_aton(MASK, &my_mk);
    if (NULL == netif_add(&wlan, &my_ip, &my_mk, &my_gw, &wlan, wifi_low_level_init, ethernet_input)) {
        LOG_ERROR();
    }
}

////////////////////////////////////////////////////////////////////////////////

typedef struct {
    const char * str_ip;
    const char * str_mask;
    const char * str_gw;
} wifi_conf_t;
static wifi_conf_t cfg;

static void entryWifiApp(void * user) {
    if (!user) goto END;
    LOG("[WIFI] BEGIN\n");
    sem_wifi_connected = xSemaphoreCreateBinary();
    if (!sem_wifi_connected) {
        LOG("[ERROR] create sem_wifi_connected\n");
    }
    sem_wifi_ip_ready = xSemaphoreCreateBinary();
    if (!sem_wifi_ip_ready) {
        LOG("[ERROR] create sem_wifi_ip_ready\n");
    }
    wifi_conf_t * p = (wifi_conf_t*) user;
    wifi_netif_init(p->str_ip, p->str_mask, p->str_gw);
    // WAIT CONNECT
    if (sem_wifi_connected) 
        xSemaphoreTake(sem_wifi_connected, portMAX_DELAY);
    // WAIT DHCP
    if (0 == wlan.ip_addr.addr && sem_wifi_ip_ready)
        xSemaphoreTake(sem_wifi_ip_ready, portMAX_DELAY);
    wifi_ready = true;
END:
    LOG("[WIFI] READY\n");
    vTaskDelete(NULL);
}

void WIFI_Start(const char * str_ip, const char * str_gw, const char * str_mask) {
    if (wifi_started) return;
    wifi_started = true;
    wifi_ready = false;
    cfg.str_ip = str_ip;
    cfg.str_gw = str_gw;
    cfg.str_mask = str_mask;
    xTaskCreate(entryWifiApp, "WiFiApp", 512, &cfg, TASK_PRIORITY_NORMAL, NULL);
}

void WIFI_waitReady(void) {
    while (!wifi_ready)
        delay_ms(100);
}