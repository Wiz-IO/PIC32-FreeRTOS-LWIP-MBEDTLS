/* 
 * File:   mrf_osal.h
 * Author: Georgi Angelov
 *
 * Created on 28 Август 2018, 09:56
 */

#ifndef MRF_OSAL_H
#define	MRF_OSAL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "sys.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"

typedef SemaphoreHandle_t              OSAL_SEM_HANDLE_TYPE;
typedef SemaphoreHandle_t              OSAL_MUTEX_HANDLE_TYPE;
typedef BaseType_t                     OSAL_CRITSECT_DATA_TYPE;
    
#define OSAL_WAIT_FOREVER               (uint16_t)0xFFFF
#define OSAL_SEM_DECLARE(semID)         OSAL_SEM_HANDLE_TYPE   semID
#define OSAL_MUTEX_DECLARE(mutexID)     OSAL_MUTEX_HANDLE_TYPE mutexID
    
typedef enum OSAL_SEM_TYPE {
    OSAL_SEM_TYPE_BINARY,
    OSAL_SEM_TYPE_COUNTING
} OSAL_SEM_TYPE;

typedef enum OSAL_CRIT_TYPE {
    OSAL_CRIT_TYPE_LOW,
    OSAL_CRIT_TYPE_HIGH
} OSAL_CRIT_TYPE;

typedef enum OSAL_RESULT {
    OSAL_RESULT_NOT_IMPLEMENTED = -1,
    OSAL_RESULT_FALSE = 0,
    OSAL_RESULT_TRUE = 1
} OSAL_RESULT;


#define WDRV_ASSERT(FLAG, MSG)          TRACE(MSG);while(FLAG)
#define WDRV_TIME_DELAY(msec)           WDRV_UsecDelay(msec * 1000)
#define WDRV_TASK_CREATE(func, alias, stackDepth, param, prio, handle) WDRV_TaskCreate(func, alias, stackDepth, param, prio, handle, 0)
#define WDRV_TASK_DELETE(handle)        WDRV_TaskDestroy(handle)
#define WDRV_MALLOC(x)                  pvPortMalloc((x))
#define WDRV_FREE(x)                    vPortFree((x))
#define WDRV_MUTEX_CREATE(handle)       WDRV_MutexInit(handle)
#define WDRV_MUTEX_LOCK(handle, waitMS) WDRV_MutexLock(handle, waitMS)
#define WDRV_MUTEX_UNLOCK(handle)       WDRV_MutexUnlock(handle)
#define WDRV_MUTEX_DELETE(handle)       WDRV_MutexDestroy(handle)

typedef enum {
    WDRV_ERROR                = -1,
    WDRV_SUCCESS              = 0,
    WDRV_INVALID_TASK_ID      = 1,
    WDRV_INVALID_PARAMETER    = 2,
    WDRV_INVALID_POINTER      = 3,
    WDRV_ALREADY_EXISTS       = 4,
    WDRV_INVALID_EVENT        = 5,
    WDRV_EVENT_TIMEOUT        = 6,
    WDRV_INVALID_MUTEX        = 7,
    WDRV_TASK_ALREADY_LOCKED  = 8,
    WDRV_MUTEX_ALREADY_LOCKED = 9,
    WDRV_OUT_OF_MEMORY        = 10,
} WDRV_OSAL_STATUS;

#ifdef	__cplusplus
}
#endif

#endif	/* MRF_OSAL_H */

