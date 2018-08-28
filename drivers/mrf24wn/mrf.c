#include "mrf.h"
#include "mrf_api.h"

SemaphoreHandle_t wifi_connected;
SemaphoreHandle_t wifi_ip_ready;

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

static uint32_t s_wdrvext_config[] = {
    0u, // MODULE_EVENT_PRINT, 
    TASK_PRIORITY_NORMAL, // WDRV_EXT_RTOS_INIT_TASK_PRIORITY, 
    TASK_PRIORITY_NORMAL, // WDRV_EXT_RTOS_MAIN_TASK_PRIORITY,
    512u, // WDRV_EXT_RTOS_INIT_TASK_SIZE, 
    2048u, // WDRV_EXT_RTOS_MAIN_TASK_SIZE, 
    5u, // WDRV_BOARD_TYPE 5=DRV_BD_TYPE_CUSTOM
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

static void ScanDoneCB(uint32_t status) {
#if 0
    TRACE("[MRF] ScanDoneCB( %d )", status);
    if (status == 0) { // 0 means success
        WDRV_EXT_ScanDoneSet();
        WDRV_EXT_CmdScanGet(&g_wdrv_scanStatus.numberOfResults);
        g_wdrv_priv.isScanDone = true;
        g_wdrv_scanStatus.scanInProgress = false;
    }
#endif
}

static void WPSDoneCB(void) {
#if 0
    uint32_t status;
    WDRV_EXT_WPSResultsRead(p_wdrv_configData, &status);
    TRACE("[MRF] WDRV_EXT_WPSResultsRead( %d )", status);
    if (WDRV_CONFIG_PARAMS(securityMode) != WDRV_SECURITY_WPS_PUSH_BUTTON &&
            WDRV_CONFIG_PARAMS(securityMode) != WDRV_SECURITY_WPS_PIN) {
        //WDRV_CONFIG_Save();
        //WDRV_Connect();
    }
#endif
}

static void RFReadyCB(uint8_t const * const addr) {
    g_wdrv_priv.updateMacAddressRequired = 1;
    memcpy(g_wdrv_priv.macAddr, addr, sizeof (g_wdrv_priv.macAddr));
    memcpy(wlan.hwaddr, addr, ETHARP_HWADDR_LEN);
    TRACE_HEX("[MRF] MAC: %s", addr, sizeof (g_wdrv_priv.macAddr));
}

static void InitDoneCB(void) {
    TRACE("[MRF] Init Done\n");
    WDRV_Connect();
}

static void ReceiveCB(uint32_t len, uint8_t const *const frame) {
    if (!WDRV_isPacketValid(frame))
        return;
    //TRACE("[MRF] ReceiveCB()\n");  
    struct pbuf * pb = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
    if (pb) {
        pbuf_take(pb, frame, len);
        wifi_receive(&wlan, pb);
        //WIFI_SendMessageFromISR(MSG_WIFI_RECEIVE, (uint32_t) pb, 0);
        //WIFI_SendMessage(MSG_WIFI_RECEIVE, (uint32_t) pb, 0);
    } else {
        TRACE("[ERROR] ReceiveCB() NO MEMORY\n");
    }
}

static void ConnectionStateUpdate(bool connected, uint8_t reason) {
    TRACE("[MRF] ConnectionStateUpdate( %d ) %s\n", (int) connected, s_connect_failure_reason[reason]);
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
            TRACE("[MRF] Connected to AP\n");
        } else if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_SOFT_AP) {
            if (!softAPStarted) {
                softAPStarted = true;
                ConnectionStateUpdate(connected, reason);
                TRACE("[MRF] SoftAP network is enabled\r\n");
            } else {
                MRF_ClientCacheUpdate(connected, mac);
                TRACE("A client is connected\n");
            }
        }
    } else if (connected == false) {
        if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_INFRASTRUCTURE) {
            ConnectionStateUpdate(connected, reason);
            TRACE("[MRF] Connection failed - %s\n", s_connect_failure_reason[reason]);
        } else if (WDRV_CONFIG_PARAMS(networkType) == WDRV_NETWORK_TYPE_SOFT_AP) {
            if (memcmp(mac, macAllFF, 6) == 0) {
                softAPStarted = false;
                ConnectionStateUpdate(connected, reason);
                TRACE("[MRF] SoftAP network is disabled\n");
            } else {
                MRF_ClientCacheUpdate(connected, mac);
                TRACE("[MRF] A client has left\n");
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


    wifi_connected = xSemaphoreCreateBinary();
    wifi_ip_ready = xSemaphoreCreateBinary();
}

void wifi_begin(int d) {
    xSemaphoreTake(wifi_connected, portMAX_DELAY);
    if (d)
        xSemaphoreTake(wifi_ip_ready, portMAX_DELAY);
    vTaskDelay(10);
}

void WDRV_DeInit(void) {
    //TODO
}
