/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys.h"
#include "osal.h"
#include "lwip/tcpip.h"

void ssl_test(void);
void entryHTTP(void * arg);

void entryMAIN(void * arg) {
    LOG("[MAIN] BEGIN\n");
    while (1) {
        delay_ms(100);
        LED_GREEN_TOGGLE();
    }
    (void) arg;
}

char * p = 0;

int main(void) {
    SYS_Init();
    LOG("[SYS] BEGIN\n");  
    //ssl_test();
    
    tcpip_init(0, 0);
    WIFI_Start(NULL, NULL, NULL);     
    xTaskCreate(entryHTTP, "HTTP", 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    xTaskCreate(entryMAIN, "MAIN",  200, NULL, TASK_PRIORITY_NORMAL, NULL);    
    
    //LOG("[RTOS] xPortGetFreeHeapSize:            %u\n", xPortGetFreeHeapSize());   
    vTaskStartScheduler();
}
