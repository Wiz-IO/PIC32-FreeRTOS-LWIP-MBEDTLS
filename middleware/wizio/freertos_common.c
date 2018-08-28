#include "sys.h"
#include "osal.h"

/* Used from MRF24 LIB */
BaseType_t xQueueGenericReceive(QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait, const BaseType_t xJustPeeking) {
    xQueueReceive(xQueue, pvBuffer, xTicksToWait);
}

void platform_assert(const char *expr, const char *file, int line) {
    TRACE("[ASSERT] %s, %s at %d\n", expr, file, line);
    portDISABLE_INTERRUPTS();
    for (;;);
}

void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    TRACE("[ASSERT] Stack overflow: %x %s\n", (unsigned int) xTask, (portCHAR *) pcTaskName);
    for (;;);
}
