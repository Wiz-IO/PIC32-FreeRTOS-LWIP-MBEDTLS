#include "sys.h"
#include "osal.h"
#include "mrf.h"
#include "ping.h"

static char * ping_address = "8.8.8.8";

void entryPING(void * arg) {
    (void) arg;
    TRACE("[APP] - PING TEST -\n");  
    wifi_config(0, 0, 0);
    wifi_begin(1);
    TRACE("[APP] WIFI READY\n");      
    ping_init(1, ping_address, strlen(ping_address), 32);
    vTaskDelete(NULL);
}
