/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#ifndef __LANGUAGE_ASSEMBLY__
typedef enum {
    TASK_PRIORITY_IDLE = 0,                   
    TASK_PRIORITY_LOW ,             
    TASK_PRIORITY_NORMAL,                                 
    TASK_PRIORITY_HIGH,    
    TASK_PRIORITY_RTOS_LOW,
    TASK_PRIORITY_RTOS_HIGH,
} TASK_PRIORITY_E;
#endif
#define configMAX_PRIORITIES                    ( 8 )

#define configUSE_PREEMPTION                    1
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1
#define configUSE_TICKLESS_IDLE                 0
#define configCPU_CLOCK_HZ                      ( 200000000UL )
#define configPERIPHERAL_CLOCK_HZ               ( 100000000UL )
#define configTICK_RATE_HZ                      ( ( TickType_t ) 1000 )
#define configMINIMAL_STACK_SIZE                ( 200 )
#define configISR_STACK_SIZE                    ( 400 )
#define configSUPPORT_DYNAMIC_ALLOCATION        1
#define configSUPPORT_STATIC_ALLOCATION         0
#define configTOTAL_HEAP_SIZE                   ( ( size_t ) 256 * 1024UL )
#define configMAX_TASK_NAME_LEN                 ( 16 )
#define configUSE_16_BIT_TICKS                  0
#define configIDLE_SHOULD_YIELD                 1
#define configUSE_MUTEXES                       1
#define configUSE_RECURSIVE_MUTEXES             0
#define configUSE_COUNTING_SEMAPHORES           1
#define configUSE_TASK_NOTIFICATIONS            1
#define configQUEUE_REGISTRY_SIZE               0
#define configUSE_QUEUE_SETS                    0
#define configUSE_TIME_SLICING                  0
#define configUSE_NEWLIB_REENTRANT              0
//#define configENABLE_BACKWARD_COMPATIBILITY   0
#define configUSE_TASK_FPU_SUPPORT              0

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0
#define configCHECK_FOR_STACK_OVERFLOW          2
#define configUSE_MALLOC_FAILED_HOOK            0

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS           0
#define configUSE_TRACE_FACILITY                0
#define configUSE_STATS_FORMATTING_FUNCTIONS    0

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                   0
#define configMAX_CO_ROUTINE_PRIORITIES         2

/* Software timer related definitions. */
#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               ( TASK_PRIORITY_RTOS_HIGH )
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            ( configMINIMAL_STACK_SIZE * 2 )
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0

/* Misc */
#define configUSE_APPLICATION_TASK_TAG          0

/* Interrupt nesting behaviour configuration. */

/* The priority at which the tick interrupt runs.  This should probably be kept at 1. */
#define configKERNEL_INTERRUPT_PRIORITY         1 /* IPC1bits.T1IP */

/* The maximum interrupt priority from which FreeRTOS.org API functions can be called.  
Only API functions that end in ...FromISR() can be used within interrupts. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    3 /* TODO EDIT */

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                1
#define INCLUDE_uxTaskPriorityGet               1
#define INCLUDE_vTaskDelete                     1
#define INCLUDE_vTaskSuspend                    1
#define INCLUDE_vTaskDelayUntil                 1
#define INCLUDE_vTaskDelay                      1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTaskGetCurrentTaskHandle       0
#define INCLUDE_uxTaskGetStackHighWaterMark     1
#define INCLUDE_xTaskGetIdleTaskHandle          1
#define INCLUDE_eTaskGetState                   0
#define INCLUDE_xEventGroupSetBitFromISR        0
#define INCLUDE_xTimerPendFunctionCall          0
#define INCLUDE_xTaskAbortDelay                 0
#define INCLUDE_xTaskGetHandle                  0

#ifndef __LANGUAGE_ASSEMBLY__
extern void vAssertCalled( const char * pcFile, unsigned long ulLine );
#define configASSERT( x )    if( ( x ) == 0 ) vAssertCalled( __FILE__, __LINE__ )
#endif

#endif /* FREERTOS_CONFIG_H */
