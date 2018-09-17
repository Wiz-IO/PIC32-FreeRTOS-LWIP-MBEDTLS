#include "osal.h"

extern volatile bool g_interrupt_enabled;

void mutex_free(SemaphoreHandle_t p) {
    if (p) vQueueDelete(p);
}

int mutex_create(SemaphoreHandle_t * pp) {
    if (!pp) return 1;
    *pp = xSemaphoreCreateMutex();
    return (*pp) ? 0 : 1;
}

int mutex_lock(SemaphoreHandle_t p) {
    if (!p) return 1;
    return (pdTRUE == xSemaphoreTake(p, portMAX_DELAY)) ? 0 : 1;
}

int mutex_unlock(SemaphoreHandle_t p) {
    if (!p) return 1;
    return pdTRUE == xSemaphoreGive(p) ? 0 : 1;
}

void sem_free(SemaphoreHandle_t p) {
    if (p) vQueueDelete(p);
}

int sem_create(SemaphoreHandle_t * pp) {
    if (!pp) return 1;
    *pp = xSemaphoreCreateBinary();
    return (*pp) ? 0 : 1;
}

void sem_wait(SemaphoreHandle_t p) {
    if (!p) return;
    while (xSemaphoreTake(p, portMAX_DELAY) != pdTRUE);
}

uint32_t sem_wait_ex(SemaphoreHandle_t p, uint32_t ms) {
    if (!p) return 1;
    ms /= portTICK_PERIOD_MS;
    TickType_t xStartTime = xTaskGetTickCount();
    if (pdTRUE == xSemaphoreTake(p, ms))
        return (xTaskGetTickCount() - xStartTime) * portTICK_PERIOD_MS; // elapsed
    else
        return -1; //timeout
}

void sem_signal(SemaphoreHandle_t p) {
    if (!p) return;
    xSemaphoreGive(p);
}

BaseType_t sem_signal_from_isr(SemaphoreHandle_t p) {
    if (!p) return pdFALSE;
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    xSemaphoreGiveFromISR(p, &xHigherPriorityTaskWoken);
    return xHigherPriorityTaskWoken;
}






