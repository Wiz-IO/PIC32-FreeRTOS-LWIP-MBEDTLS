#include "sys.h"

volatile bool g_interrupt_enabled = false;

uint32_t SYS_INT_StatusGetAndDisable(void) {
    GET_INT_DISABLE();  
    g_interrupt_enabled = false;
    return g_interrupt_enabled;
}

/* Used from MRF24 LIB */
bool SYS_INT_Disable(void) {
    return (bool) (SYS_INT_StatusGetAndDisable()& 0x01);
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
    debug_arg(f, a);
    va_end(a);
}

static void HardwareUseMultiVectoredInterrupts( void ) {
    SYS_INT_Disable(); 
	_CP0_BIS_CAUSE( 0x00800000U );
	INTCONSET = _INTCON_MVEC_MASK;
	SYS_INT_Enable();
} 

int SYS_Init(void) {
    HardwareUseMultiVectoredInterrupts();
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    ANSELF = 0;
    mINIT_LED();
}

void __attribute__((noreturn)) SYS_SoftReset(void) {
    DISABLE_INT();
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