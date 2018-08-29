#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "sntp.h"

void entrySNTP(void * arg) {
    (void) arg;
    TRACE("[APP] - SNTP TEST -\n");  
    wifi_config(0, 0, 0);
    wifi_begin(1);
    TRACE("[APP] WIFI READY\n"); 
    ip_addr_t ip_addr;
    ip_addr.addr = 0;
    inet_aton("87.97.157.120", &ip_addr.addr);
    sntp_setserver(0, &ip_addr);  
    sntp_init();
    vTaskDelete(NULL);
}
