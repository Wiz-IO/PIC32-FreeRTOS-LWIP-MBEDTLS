#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "lwip/sockets.h"
#include "lwip/opt.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

static SemaphoreHandle_t dns_ready;
static char * GET = "GET /index.php HTTP/1.0\r\n\r\n";
static char response[1024];
static ip_addr_t resolved;

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
    if (!arg) return;
    char str[17] = {0};
    resolved.addr = ip_addr->addr;
    if (NULL != inet_ntoa(ip_addr)) {
        strcpy(str, inet_ntoa(ip_addr));
        TRACE("[DNS] %s IP: %s\n", name, str);
    } else {
        TRACE("[ERROR] DNS: %u IP: %s\n", ip_addr->addr);
    }
    xSemaphoreGive(dns_ready);
}

void entryWIFI(void * arg) {
    (void) arg;
    TRACE("[APP] - WIFI -\n");
    int rc;
    struct sockaddr_in a;
    dns_ready = xSemaphoreCreateBinary();
    LED_ORANGE_OFF();
    wifi_config(0, 0, 0);
    wifi_begin(1);
    TRACE("[APP] WIFI READY\n");
    PrintAddress();
START:
    LED_ORANGE_ON();
    memset(&a, 0, sizeof (a));
    a.sin_len = sizeof (a);
    a.sin_family = AF_INET;
    a.sin_port = PP_HTONS(80);
    rc = dns_gethostbyname("google.com", &resolved, dns_cb, dns_ready);
    switch (rc) {
        case ERR_OK:
            TRACE("[DNS] OK\n");
            LED_ORANGE_ON();
            break;
        case ERR_INPROGRESS:
            TRACE("[DNS] INPROGRESS\n");
            xSemaphoreTake(dns_ready, portMAX_DELAY);
            TRACE("[DNS] DONE\n");
            break;
        default:
            TRACE("[ERROR] dns_gethostbyname( %d )\n", rc);
            goto END;
    }
    a.sin_addr.s_addr = resolved.addr;

    int soc = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (soc < 0) {
        TRACE("[ERROR] lwip_socket()\n");
        goto END;
    }

    rc = lwip_connect(soc, (struct sockaddr*) &a, sizeof (a));
    if (rc) {
        TRACE("[ERROR] lwip_connect( %d )\n", rc);
        goto ERR;
    }

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

    memset(response, 0, sizeof (response));
    total = sizeof (response) - 1;
    int received = 0;
    do {
        rc = lwip_read(soc, response + received, total - received);
        if (rc < 0) {
            TRACE("[ERROR] lwip_read( %d )", rc);
            goto ERR;
        }
        if (rc == 0)
            break;
        received += rc;
    } while (received < total);
    TRACE("%s", response);
ERR:
    lwip_close(soc);
END:            
    rc = 100;
    while (rc--) {
        LED_ORANGE_TOGGLE();
        delay_ms(100);
    }
    goto START;

    while (1) {
        LED_ORANGE_TOGGLE();
        delay_ms(100);
    }
}
