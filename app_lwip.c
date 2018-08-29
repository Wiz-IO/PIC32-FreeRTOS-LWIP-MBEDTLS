#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "lwip/sockets.h"
#include "lwip/opt.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

#define HOST    "www.wizio.eu"
static SemaphoreHandle_t dns_ready;
static char * GET = "GET /test.php HTTP/1.0\r\nHost: "HOST"\r\n\r\n";
static char response[256];
static struct sockaddr_in server;

void PrintAddress(void) {
    TRACE("[APP] - IP: %s\n", inet_ntoa(wlan.ip_addr));
    TRACE("[APP] - GW: %s\n", inet_ntoa(wlan.gw));
    TRACE("[APP] - MS: %s\n", inet_ntoa(wlan.netmask));
    const ip_addr_t * d0 = dns_getserver(0);
    const ip_addr_t * d1 = dns_getserver(1);
    TRACE("[APP] - D0: %s\n", inet_ntoa(d0));
    TRACE("[APP] - D1: %s\n", inet_ntoa(d1));
}

void dns_cb(const char * name, const ip_addr_t * ip_addr, void * arg) {
    server.sin_addr.s_addr = ip_addr->addr;
    TRACE("[DNS] %s IP: %s\n", name, inet_ntoa(ip_addr));
    if (dns_ready)
        xSemaphoreGive(dns_ready);
}

void entrySOCKET(void * arg) {
    (void) arg;
    TRACE("[APP] - SOCKET -\n");
    int rc;
    ip_addr_t resolved;
    dns_ready = xSemaphoreCreateBinary();
    LED_ORANGE_OFF();
    wifi_config(0, 0, 0);
    wifi_begin(1);
    TRACE("[APP] WIFI READY\n");
    PrintAddress();
    memset(&server, 0, sizeof (server));
    server.sin_len = sizeof (server);
    server.sin_family = AF_INET;
    server.sin_port = PP_HTONS(80);
START:
    // --- RESOLVE URL ---
    rc = dns_gethostbyname(HOST, &resolved, dns_cb, NULL);
    switch (rc) {
        case ERR_OK:
            LED_ORANGE_ON();
            break;
        case ERR_INPROGRESS:
            xSemaphoreTake(dns_ready, portMAX_DELAY);
            break;
        default:
            TRACE("[ERROR] dns_gethostbyname( %d )\n", rc);
            goto END;
    }
    // CREATE SOCKET
    int soc = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (soc < 0) {
        TRACE("[ERROR] lwip_socket( %d )\n", soc);
        goto END;
    }
    // CONNECT
    rc = lwip_connect(soc, (struct sockaddr*) &server, sizeof (server));
    if (rc) {
        TRACE("[ERROR] lwip_connect( %d )\n", rc);
        goto ERR;
    }
    // SEND DATA
    int total = strlen(GET), sent = 0;
    do {
        rc = lwip_write(soc, GET + sent, total - sent);
        if (rc < 0) {
            TRACE("[ERROR] lwip_write( %d )\n", rc);
            goto ERR;
        }
        if (rc == 0)
            break;
        sent += rc;
    } while (sent < total);
    // RECEIVE DATA
    memset(response, 0, sizeof (response));
    total = sizeof (response) - 1;
    int received = 0;
    do {
        rc = lwip_read(soc, response + received, total - received);
        if (rc < 0) {
            TRACE("[ERROR] lwip_read( %d )\n", rc);
            goto ERR;
        }
        if (rc == 0)
            break;
        received += rc;
    } while (received < total);
    TRACE("%s", response);
    TRACE("\n[APP] DONE\n\n", rc);
ERR:
    lwip_close(soc);
END:
    rc = 60;
    while (rc--) {
        LED_ORANGE_TOGGLE();
        delay_ms(1000);
    }
    goto START;
}
