/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "sys.h"
#include "fan_system.h"

volatile bool g_interrupt_enabled = false;

/* Used from MRF24 LIB */
bool SYS_INT_Disable(void) {
    g_interrupt_enabled = false;
    return (bool) GET_INT_DISABLE();
}

void SYS_INT_Enable(void) {
    g_interrupt_enabled = true;
    INT_ENABLE();
}

/* Used from MRF24 LIB */
void SYS_CMD_MESSAGE(const char * message) {
    (void) message;
    //TRACE("[MRF] SYS_CMD_MESSAGE: %s\n", message);
}

/* Used from MRF24 LIB */
void SYS_CMD_PRINT(const char * f, ...) {
    va_list a;
    va_start(a, f);
    vprintf(f, a);
    va_end(a);
}

static void HardwareUseMultiVectoredInterrupts(void) {
    ENTER_CRITICAL();
    _CP0_BIS_CAUSE(0x00800000U);
    INTCONSET = _INTCON_MVEC_MASK;
    EXIT_CRITICAL();
}

void __attribute__((noreturn)) SYS_SoftReset(void) {
    GET_INT_DISABLE();
    /* perform a system unlock sequence ,starting critical sequence*/
    SYSKEY = 0x00000000; //write invalid key to force lock
    SYSKEY = 0xAA996655; //write key1 to SYSKEY
    SYSKEY = 0x556699AA; //write key2 to SYSKEY
    /* set SWRST bit to arm reset */
    RSWRSTSET = 1;
    /* read RSWRST register to trigger reset */
    unsigned int dummy;
    dummy = RSWRST;
    /* prevent any unwanted code execution until reset occurs*/
    while (1);
}

uint32_t ElapsedTime(uint32_t startTime, uint32_t currentTime) {
    /* ROLLOVER SAFE */
    if (currentTime >= startTime) {
        return ( currentTime - startTime);
    } else {
        return ( ((uint32_t) 0xffffffff) - currentTime) +startTime;
    }
}

void DelayMS(uint32_t t) {
    uint32_t startTime = TickMS();
    do {
        if (ElapsedTime(startTime, TickMS()) > t)
            return;
    } while (1);
}

void DelayUS(uint32_t t) {
    uint32_t startTime = TickUS();
    do {
        if (ElapsedTime(startTime, TickMS()) > t)
            return;
    } while (1);
}

uint32_t sys_rand(void) {
    // This module does not have SET, CLR, INV registers because the PIC32MZ supports the MIPS MCU ASE.
    RNGCONbits.TRNGEN = 1;
    RNGCONbits.TRNGMODE = 1;
    while (RNGCNT < 16); // up to 64 bits; we'll get 16 here
    return (uint16_t) RNGSEED1 ^ GetSystemClock() ^ RNGSEED2;
}

////////////////////////////////////////////////////////////////////////////////

int SYS_Init(void) {
    SysPerformanceConfig(SYS_CLK_FREQ, PCACHE_PREFETCH_ENABLE_ALL);
    HardwareUseMultiVectoredInterrupts();    
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    INIT_LED();
#ifdef DEBUG
    sys_log_init(DBG_SPEED);
#endif
}