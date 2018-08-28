#include "sys.h"
#include "osal.h"

extern void entryDRIVER(void * arg);
extern void entryLWIP(void * arg);

void entryBlink(void * arg) {
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
    TRACE("[APP] --- BEGIN ---\n");
    xTaskCreate(entryBlink, "BLINK", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_LOW, NULL);
    //xTaskCreate(entryDRIVER, "DRV", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    xTaskCreate(entryLWIP, "LWIP", 10*1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    vTaskStartScheduler();
}