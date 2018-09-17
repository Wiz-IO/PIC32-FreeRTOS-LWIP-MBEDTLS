#include "sys.h"

#ifdef FREERTOS
#include "osal.h"
//static SemaphoreHandle_t log_mutex = NULL;
//static SemaphoreHandle_t log_dma_mutex = NULL;
//static SemaphoreHandle_t log_dma_sem = NULL;
#else

#endif

#ifdef DBG_USE_DMA
static char __attribute__((coherent)) log_buffer[DBG_BUF_MAX];
#endif

void _mon_putc(char c) {
    while (U1STA & _U1STA_UTXBF_MASK);
    U1TXREG = c;
    //while (!(U1STA & _U1STA_TRMT_MASK));
}

void sys_log_init(int32_t brg) {
    SYS_SystemUnlock();
    RPD15R = 1;
    U1RXR = 3;
    SYS_SystemLock();
    U1MODE = U1STA = 0;
    U1BRG = (uint32_t) (((float) SYS_CLK_BUS_PERIPHERAL_1 / (4.0 * brg))-(float) 0.5);
    U1STASET = _U1STA_UTXEN_MASK | _U1STA_URXEN_MASK;
    U1MODESET = _U1MODE_ON_MASK | _U1MODE_BRGH_MASK;
#ifdef DBG_USE_DMA 
    U1STAbits.UTXISEL = 1;
    dbg_init_dma();
#endif      
}

int Printf(const char * frm, ...) {
    if (NULL == frm || (0 == U1STA & _U1STA_UTXEN_MASK)) return -1;
    int flag = (int) __builtin_disable_interrupts();
    va_list ar;
    va_start(ar, frm);
    vprintf(frm, ar); //---> _mon_putc
    va_end(ar);
    if (flag)__builtin_mtc0(12, 0, (__builtin_mfc0(12, 0) | 0x0001));
    return 0;
}

void PrintHex(char * begin, char * buffer, int size, char * end) {
    if (begin) Printf(begin);
    int i = 0;
    while (size--)
        Printf("%02X", buffer[i++]&0xFF);
    if (end) Printf(end);
}