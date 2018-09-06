#include "sys.h"

#ifdef FREERTOS
#include "osal.h"
static SemaphoreHandle_t log_mutex = NULL;
static SemaphoreHandle_t log_dma_mutex = NULL;
static SemaphoreHandle_t log_dma_sem = NULL;
#else
#define xSemaphoreCreateMutex()     1
#define xSemaphoreTake(a, b)        1
#define xSemaphoreGive(a)           1
#define xSemaphoreGiveFromISR(a,b)  1
#define xTaskGetSchedulerState()    0
static int dbg_mutex = 0;
static int log_dma_mutex = 0;
static int log_dma_sem = 0;
#endif

#ifdef DBG_USE_DMA
static char __attribute__((coherent)) log_buffer[DBG_BUF_MAX];
#endif

void _mon_putc (char c) {
    if (NULL == log_mutex) {
        while (U1STA & _U1STA_UTXBF_MASK);
        U1TXREG = c;
    } else {
        while (U1STA & _U1STA_UTXBF_MASK);
        U1TXREG = c;
    }
}

#ifdef FREERTOS 
static void entryLog(void * arg) {
    while (1) vTaskDelay(100);
}
#endif

void sys_log_init(int32_t brg) {
    SYS_SystemUnlock();
    RPD15R = 1;
    U1RXR = 3;
    SYS_SystemLock();
    U1MODE = U1STA = 0;
    U1BRG = (uint32_t) (((float) SYS_CLK_BUS_PERIPHERAL_1 / (4.0 * brg))-(float) 0.5);    
    U1STASET = _U1STA_UTXEN_MASK | _U1STA_URXEN_MASK;
    U1MODESET = _U1MODE_ON_MASK | _U1MODE_BRGH_MASK;
    U1TXREG = '\n';
#ifdef DBG_USE_DMA 
    U1STAbits.UTXISEL = 1; 
    dbg_init_dma();
#endif      
#ifdef FREERTOS     
    log_mutex = xSemaphoreCreateMutex();    
    //xTaskCreate(entryLog, "LOG", 1024, NULL, TASK_PRIORITY_LOW, NULL);
#endif
}

int Printf(const char * frm, ...) {
    if (!frm)
        return -1;
    va_list a;
    va_start(a, frm);
#ifdef FREERTOS
    if (log_mutex && xTaskGetSchedulerState() > 1) // taskSCHEDULER_RUNNING
        xSemaphoreTake(log_mutex, portMAX_DELAY); // LOCK
#endif
    vprintf(frm, a); //---> _mon_putc
#ifdef FREERTOS    
    if (log_mutex && xTaskGetSchedulerState() > 1) // taskSCHEDULER_RUNNING
        xSemaphoreGive(log_mutex); // UNLOCK
#endif
    return 0;
}

////////////////////////////////////////////////////////////////////////////////

#ifdef DBG_USE_DMA

#ifdef FREERTOS

void ISR_DMA0(void) {
    IEC4CLR = _IEC4_DMA0IE_MASK;
    IFS4CLR = _IFS4_DMA0IF_MASK;
    static long xHigherPriorityTaskWoken = 0;
    xHigherPriorityTaskWoken = 0;
    xSemaphoreGiveFromISR(dma_sem, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken)
        portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}

#else

#include <sys/attribs.h>

void __ISR_AT_VECTOR(_DMA0_VECTOR, IPL2AUTO) ISR_DMA0(void) {
    IEC4CLR = _IEC4_DMA0IE_MASK;
    IFS4CLR = _IFS4_DMA0IF_MASK;
    static long xHigherPriorityTaskWoken = 0;
    xHigherPriorityTaskWoken = 0;
    xSemaphoreGiveFromISR(dma_mutex, &xHigherPriorityTaskWoken);
    if (xHigherPriorityTaskWoken != 0);
}

#endif /*FREERTOS*/

#endif /*DBG_USE_DMA*/