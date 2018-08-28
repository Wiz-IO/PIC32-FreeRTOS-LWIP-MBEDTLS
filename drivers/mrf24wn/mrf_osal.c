#include "mrf_osal.h"

OSAL_RESULT OSAL_SEM_Create(OSAL_SEM_HANDLE_TYPE* semID, OSAL_SEM_TYPE type, uint8_t maxCount, uint8_t initialCount) {
    switch (type) {
        case OSAL_SEM_TYPE_BINARY:
            vSemaphoreCreateBinary(*(SemaphoreHandle_t*) semID);
            break;
        case OSAL_SEM_TYPE_COUNTING:
            *(SemaphoreHandle_t*) semID = xSemaphoreCreateCounting((UBaseType_t) maxCount, (UBaseType_t) initialCount);
            break;
        default:
            *(SemaphoreHandle_t*) semID = NULL;
            return OSAL_RESULT_NOT_IMPLEMENTED;
    }
    if (*(SemaphoreHandle_t*) semID == NULL) {
        return OSAL_RESULT_FALSE;
    }
    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_SEM_Delete(OSAL_SEM_HANDLE_TYPE* semID) {
    vSemaphoreDelete(*(SemaphoreHandle_t*) semID);
    *(SemaphoreHandle_t*) semID = NULL;
    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_SEM_Pend(OSAL_SEM_HANDLE_TYPE* semID, uint16_t waitMS) {
    TickType_t timeout = 0;
    if (waitMS == OSAL_WAIT_FOREVER) {
        timeout = portMAX_DELAY;
    } else {
        timeout = (TickType_t) (waitMS / portTICK_PERIOD_MS);
    }
    if (xSemaphoreTake(*(SemaphoreHandle_t*) semID, timeout) == pdTRUE)
        return OSAL_RESULT_TRUE;
    else
        return OSAL_RESULT_FALSE;
}

OSAL_RESULT OSAL_SEM_Post(OSAL_SEM_HANDLE_TYPE* semID) {
    if (xSemaphoreGive(*(SemaphoreHandle_t*) semID) == pdTRUE) {
        return OSAL_RESULT_TRUE;
    }
    return OSAL_RESULT_FALSE;
}

OSAL_RESULT OSAL_SEM_PostISR(OSAL_SEM_HANDLE_TYPE* semID) {
    BaseType_t _taskWoken = pdFALSE;
    if (xSemaphoreGiveFromISR(*(SemaphoreHandle_t*) semID, &_taskWoken)) {
        portEND_SWITCHING_ISR(_taskWoken);
        return OSAL_RESULT_TRUE;
    }
    return OSAL_RESULT_FALSE;
}

OSAL_RESULT OSAL_MUTEX_Create(OSAL_MUTEX_HANDLE_TYPE* mutexID) {
    /* mutex may already have been created so test before creating it */
    if (*(SemaphoreHandle_t*) mutexID != NULL) {
        return OSAL_RESULT_FALSE;
    }
    *(SemaphoreHandle_t*) mutexID = xSemaphoreCreateMutex();
    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_MUTEX_Delete(OSAL_MUTEX_HANDLE_TYPE* mutexID) {
    if (*(SemaphoreHandle_t*) mutexID == NULL) {
        return OSAL_RESULT_FALSE;
    }
    vSemaphoreDelete(*(SemaphoreHandle_t*) mutexID);
    *(SemaphoreHandle_t*) mutexID = NULL;
    return OSAL_RESULT_TRUE;
}

OSAL_RESULT OSAL_MUTEX_Lock(OSAL_MUTEX_HANDLE_TYPE* mutexID, uint16_t waitMS) {
    TickType_t timeout = 0;
    if (waitMS == OSAL_WAIT_FOREVER) {
        timeout = portMAX_DELAY;
    } else {
        timeout = (TickType_t) (waitMS / portTICK_PERIOD_MS);
    }
    if (xSemaphoreTake(*(SemaphoreHandle_t*) mutexID, timeout) == pdTRUE)
        return OSAL_RESULT_TRUE;
    else
        return OSAL_RESULT_FALSE;
}

OSAL_RESULT OSAL_MUTEX_Unlock(OSAL_MUTEX_HANDLE_TYPE* mutexID) {
    if (xSemaphoreGive(*(SemaphoreHandle_t*) mutexID) == pdTRUE) {
        return OSAL_RESULT_TRUE;
    }
    return OSAL_RESULT_FALSE;
}

uint32_t WDRV_MutexInit(OSAL_MUTEX_HANDLE_TYPE **mutex_ptr) {
    *mutex_ptr = malloc(sizeof (OSAL_MUTEX_HANDLE_TYPE));
    OSAL_MUTEX_Create(*mutex_ptr);
    return 0;
}

uint32_t WDRV_MutexDestroy(OSAL_MUTEX_HANDLE_TYPE **mutex_ptr) {
    OSAL_MUTEX_Delete(*mutex_ptr);
    free(*mutex_ptr);
    return 0;
}

uint32_t WDRV_MutexLock(OSAL_MUTEX_HANDLE_TYPE *mutex_ptr, uint32_t tick_count) {
    OSAL_MUTEX_Lock(mutex_ptr, OSAL_WAIT_FOREVER);
    return 0;
}

uint32_t WDRV_MutexUnlock(OSAL_MUTEX_HANDLE_TYPE *mutex_ptr) {
    OSAL_MUTEX_Unlock(mutex_ptr);
    return 0;
}

bool WDRV_SemInit(OSAL_SEM_HANDLE_TYPE *SemID) {
    if (OSAL_SEM_Create(SemID, OSAL_SEM_TYPE_COUNTING, 10, 0) == OSAL_RESULT_TRUE)
        return true;
    else
        return false;
}

void WDRV_SemTake(OSAL_SEM_HANDLE_TYPE *SemID, uint16_t timeout) {
    OSAL_SEM_Pend(SemID, timeout);
}

void WDRV_SemGive(OSAL_SEM_HANDLE_TYPE *SemID) {
    OSAL_SEM_Post(SemID);
}

void WDRV_SemGiveFromISR(OSAL_SEM_HANDLE_TYPE *SemID) {
    OSAL_SEM_PostISR(SemID);
}

void WDRV_SemDeInit(OSAL_SEM_HANDLE_TYPE *SemID) {
    OSAL_SEM_Delete(SemID);
}

static WDRV_OSAL_STATUS ErrorCodeGet(uint32_t os_err) {
    WDRV_OSAL_STATUS osal_ret;
    switch (os_err) {
        case pdPASS:
            osal_ret = WDRV_SUCCESS;
            break;
        case pdFAIL:
            osal_ret = WDRV_ERROR;
            break;
        default:
            osal_ret = WDRV_ERROR;
    }
    return osal_ret;
}

WDRV_OSAL_STATUS WDRV_TaskCreate(void Task(void *), const char *task_name, int stack_size, void *param,
        unsigned long task_priority, TaskHandle_t *task_handle, bool auto_start) {
    WDRV_OSAL_STATUS ret = WDRV_SUCCESS;
    uint32_t os_ret;
    os_ret = xTaskCreate((TaskFunction_t) Task, /* pointer to the task entry code */
            task_name, /* task name */
            stack_size, /* task stack size */
            param, /* parameters to pass */
            task_priority, /* task priority - lower no= lower priority */
            task_handle); /* handle by which task can be referenced */
    if (os_ret == pdFAIL)
        return WDRV_SUCCESS;
    ret = ErrorCodeGet(os_ret);
    return ret;
}

WDRV_OSAL_STATUS WDRV_TaskDestroy(TaskHandle_t task_handle) {
    WDRV_OSAL_STATUS ret = WDRV_SUCCESS;
    vTaskDelete(task_handle);
    return ret;
}

void WDRV_UsecDelay(uint32_t uSec) {
    unsigned long xUnblockPeriod = uSec / 1000;
    if (!xUnblockPeriod) 
        xUnblockPeriod = 1;
    vTaskDelay(xUnblockPeriod * portTICK_PERIOD_MS);
    return;
}
