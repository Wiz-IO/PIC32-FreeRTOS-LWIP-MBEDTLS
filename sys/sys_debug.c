#include "sys.h"
#include "osal.h"

static xSemaphoreHandle dbg_mutex = 0;

static void dbg_init(uint32_t brg) {
    if (!dbg_mutex)
        dbg_mutex = xSemaphoreCreateMutex();
    SystemUnlock();
    RPD15R = 1;
    U1RXR = 3;
    SystemLock();
    U1MODE = U1STA = 0;
    U1BRG = (unsigned short) (((float) SYS_CLK_BUS_PERIPHERAL_1 / (4.0 * brg))-(float) 0.5);
    U1STASET = _U1STA_UTXEN_MASK | _U1STA_URXEN_MASK;
    U1MODESET = _U1MODE_ON_MASK | _U1MODE_BRGH_MASK;
    IPC28CLR = _IPC28_U1RXIP_MASK;
    IPC28SET = (2 << _IPC28_U1RXIP_POSITION);
    IPC28CLR = _IPC28_U1RXIS_MASK;
    IPC28SET = (0 << _IPC28_U1RXIS_POSITION);
    IFS3CLR = _IFS3_U1RXIF_MASK;
    //IEC3SET = _IEC3_U1RXIE_MASK;
}

void debug_arg(const char * frm, va_list arg){
    if (!frm)
        return;
    if (!dbg_mutex)
        dbg_init(115200);
    if (dbg_mutex && xSemaphoreTake(dbg_mutex, portMAX_DELAY) == 1) {
        vprintf(frm, arg);
        xSemaphoreGive(dbg_mutex);
    } else {
        printf("[ERROR] TRACE\n");
    }
}

void debug(char * frm, ...) {
    if (!frm)
        return;
    if (!dbg_mutex)
        dbg_init(115200);
    if (dbg_mutex && xSemaphoreTake(dbg_mutex, portMAX_DELAY) == 1) {
        va_list arg;
        va_start(arg, frm);
        vprintf(frm, arg);
        va_end(arg);
        xSemaphoreGive(dbg_mutex);
    } else {
        printf("[ERROR] TRACE\n");
    }
}

void debug_hex(char * frm, unsigned char * src, unsigned char size) {
    if (!frm)
        return;
    if (!dbg_mutex)
        dbg_init(115200);
    if (dbg_mutex && xSemaphoreTake(dbg_mutex, portMAX_DELAY) == 1) {
        char hex[256];
        int len = size;
        if (len > 127) len = 127;
        ByteToHexStr(src, hex, len);
        printf(frm, hex);
        if (size > 127)
            printf("...");
        printf("\n");
        xSemaphoreGive(dbg_mutex);
    } else {
        fprintf(stderr, "[ERROR] TRACE\n");
    }
}

void _mon_putc(char c) {
    while (U1STA & _U1STA_UTXBF_MASK);
    U1TXREG = c;
    while (!(U1STA & _U1STA_TRMT_MASK));
}