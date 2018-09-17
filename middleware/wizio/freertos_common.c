/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys.h"
#include "osal.h"

/* Used from MRF24 LIB */
BaseType_t xQueueGenericReceive(QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait, const BaseType_t xJustPeeking) {
    xQueueReceive(xQueue, pvBuffer, xTicksToWait);
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    portDISABLE_INTERRUPTS();
    LOG("\n[ASSERT] Stack overflow: 0x%x %s\n", (unsigned int) xTask, (portCHAR *) pcTaskName);
    LED_RED_ON();
    while (1);
}

void vAssertCalled( const char * const pcFileName, unsigned long ulLine) {
    portDISABLE_INTERRUPTS();
    LOG("\n[ASSERT] Called: %s, Line: %u\n", pcFileName, ulLine);
    LED_RED_ON();
    while (1);
}