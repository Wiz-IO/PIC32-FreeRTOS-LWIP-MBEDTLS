#include "mrf.h"
#include "mrf_api.h"
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/mem.h"
#include "lwip/pbuf.h"
#include "lwip/inet.h"
#include "lwip/dhcp.h"
#include "lwip/prot/dhcp.h"
#include "netif/etharp.h"

struct netif wlan;
struct netif * pWlan = &wlan;
ip_addr_t ip_addr;
ip_addr_t ip_mask;
ip_addr_t ip_gw;

err_t wifi_send(struct netif * interface, struct pbuf *pb) {
    struct netif * netif;
    uint8_t result;
    for (netif = netif_list; (netif != NULL) && (netif->state != (void*) interface); netif = netif->next);
    if (netif == NULL) {
        result = pbuf_free(pb);
        LWIP_ASSERT("[IF] pbuf_free", (result != 0));
        pb = NULL;
        return;
    }
    int rc = WDRV_EXT_DataSend(pb->len, pb->payload);
    if (rc) {
        TRACE("[ERROR] wlan_send( %d )\n", rc);
    }
    return (err_t) rc;
}

void wifi_receive(struct netif * interface, struct pbuf * pb) {
    if (!pb) return;
    struct netif * netif;
    uint8_t result;
    for (netif = netif_list; (netif != NULL) && (netif->state != (void*) interface); netif = netif->next);
    if (netif == NULL) {
        result = pbuf_free(pb);
        LWIP_ASSERT("[IF] pbuf_free", (result != 0));
        pb = NULL;
        LINK_STATS_INC(link.drop);
        return;
    }
    LINK_STATS_INC(link.recv);
    if (netif->input(pb, netif)) {
        LWIP_DEBUGF(NETIF_DEBUG, ("[IF] ethernetif_input: IP input error\n"));
        pbuf_free(pb);
        pb = NULL;
    }
}

static void wifi_low_level_init(struct netif *netif) {
    netif->mtu = MAX_IP_PACKET_SIZE;
    netif->hwaddr_len = ETHARP_HWADDR_LEN;
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_LINK_UP;
    WDRV_Init();
}

static err_t wifi_init(struct netif * netif) {
    netif->name[0] = 'w';
    netif->name[1] = '0';
    netif->output = etharp_output;
#if LWIP_IPV6
    netif->output_ip6 = ethip6_output;
#endif /* LWIP_IPV6 */
    netif->linkoutput = wifi_send;
    wifi_low_level_init(netif);
    return ERR_OK;
}

void wifi_config(char * str_ip, char * str_mask, char * str_gw) {
    ip_addr.addr = 0;
    ip_gw.addr = 0;
    ip_mask.addr = 0;
    if (str_ip)
        inet_aton(str_ip, &ip_addr.addr);
    if (str_gw)
        inet_aton(str_gw, &ip_gw.addr);
    if (str_mask)
        inet_aton(str_mask, &ip_mask.addr);
    if (!netif_add(&wlan, &ip_addr, &ip_mask, &ip_gw, &wlan, wifi_init, ethernet_input)) {
        TRACE(("[MRF] Could not add WLAN interface\n"));
    }
}

static void wifi_ip_ready_callback(struct netif * netif){
    if (!ip4_addr_isany_val(netif->ip_addr)) {
        char ip_addr[17] = {0};
        if (NULL != inet_ntoa(netif->ip_addr)) {
            strcpy(ip_addr, inet_ntoa(netif->ip_addr));
            TRACE("[MRF] DHCP GOT IP: %s\n", ip_addr);
            xSemaphoreGive(wifi_ip_ready);
        } else {
            TRACE("[ERROR] DHCP got Failed\n");
        }
    }
}

void wifi_set_state(bool connected) {
    if (connected) {
        netif_set_status_callback(&wlan, wifi_ip_ready_callback);
        netif_set_link_up(&wlan);
        netif_set_up(&wlan);
        netif_set_default(&wlan);
        if (dhcp_start(&wlan) != ERR_OK) {
            TRACE("[ERROR] DHCP failed\n");
        }
        TRACE("[MRF] DHCP started\n");
        xSemaphoreGive(wifi_connected);
    } else
        netif_set_down(&wlan);
}