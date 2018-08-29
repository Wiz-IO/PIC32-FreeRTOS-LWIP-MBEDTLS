#include "sys.h"
#include "osal.h"

extern void entryDRIVER(void * arg);
extern void entrySOCKET(void * arg);
extern void entryHTTP(void * arg);
extern void entryPING(void * arg);
extern void entrySNTP(void * arg);

void entryBLINK(void * arg) {
    (void) arg;
    TRACE("[APP] - BLINK -\n");
    while (1) {
        delay_ms(1000);        
        LED_GREEN_TOGGLE();
    }
}

int main(void) {
    SYS_Init();
    tcpip_init(0, 0);
    TRACE("[APP] - BEGIN -\n");
    xTaskCreate(entryBLINK, "BLINK", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_LOW, NULL);
    
    //xTaskCreate(entryDRIVER, "DRV", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    //xTaskCreate(entrySOCKET, "SOCK", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    //xTaskCreate(entryHTTP, "HTTP", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    //xTaskCreate(entryPING, "PING", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    xTaskCreate(entrySNTP, "SNTP", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    
    vTaskStartScheduler();
}