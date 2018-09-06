/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys.h"
#include "osal.h"
#include "lwip/tcpip.h"

void entryHTTP(void * arg);

void entryBLINK(void * arg) {
    (void) arg;
    LOG("[BLINK] BEGIN\n");
    while (1) {
        delay_ms(100);
        LED_GREEN_TOGGLE();
    }
}

int main(void) {
    SYS_Init();
    LOG("[MAIN] BEGIN\n");   
    tcpip_init(0, 0);
    WIFI_Start(NULL, NULL, NULL);
    xTaskCreate(entryBLINK, "BLINK", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_LOW, NULL);
    xTaskCreate(entryHTTP, "HTTP", 6 * 1024, NULL, TASK_PRIORITY_NORMAL, NULL);
    vTaskStartScheduler();
}
