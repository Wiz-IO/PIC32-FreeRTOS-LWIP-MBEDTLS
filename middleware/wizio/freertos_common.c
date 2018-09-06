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

void platform_assert(const char *expr, const char *file, int line) {
    LOG("[ASSERT] %s, %s at %d\n", expr, file, line);
    portDISABLE_INTERRUPTS();
    for (;;);
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    LOG("[ASSERT] Stack overflow: %x %s\n", (unsigned int) xTask, (portCHAR *) pcTaskName);
    for (;;);
}

void vAssertCalled(unsigned long ulLine, const char * const pcFileName) {
    //static portBASE_TYPE xPrinted = pdFALSE;
    volatile uint32_t ulSetToNonZeroInDebuggerToContinue = 0;
    taskENTER_CRITICAL();
    {
        /* You can step out of this function to debug the assertion by using the debugger to set ulSetToNonZeroInDebuggerToContinue to a non-zero value. */
        LOG("[RTOS-ASSERT] %s %s", pcFileName, ulLine);
        while (ulSetToNonZeroInDebuggerToContinue == 0) {
        }
    }
    taskEXIT_CRITICAL();
}