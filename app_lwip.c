#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "lwip/netif.h"
#include "lwip/tcpip.h"
#include "lwip/sockets.h"
#include "lwip/opt.h"
#include "lwip/dns.h"
#include "lwip/netdb.h"

void entryLWIP(void * arg) {
    (void) arg;
    TRACE("[APP] - LWIP -\n");
    wifi_config(0, 0, 0);
    while (1) {
        delay_ms(100);        
        LED_ORANGE_TOGGLE();
    }
}
