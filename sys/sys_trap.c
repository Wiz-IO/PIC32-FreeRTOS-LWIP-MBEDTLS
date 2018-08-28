#include "sys.h"

#ifdef DEBUG
static unsigned int _excep_code;
static unsigned int _excep_addr;
static char *_cause_str;
static char *cause[] = {
    "Interrupt",
    "Undefined",
    "Undefined",
    "Undefined",
    "Load/Fetch address error",
    "Store address error",
    "Instruction bus error",
    "Data bus error",
    "Syscall",
    "Breakpoint",
    "Reserved instruction",
    "Coprocessor unusable",
    "Arithmetic overflow",
    "Trap",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};
#endif

void _general_exception_handler ( void ) {
#ifdef DEBUG   
    _excep_code = (_CP0_GET_CAUSE() & 0x0000007C) >> 2;
    _excep_addr = _CP0_GET_EPC();
    _cause_str  = cause[_excep_code];
    TRACE("[TRAP] General Exception %s (cause=%d, addr=%x).", _cause_str, _excep_code, _excep_addr);
#endif
    LED_RED_ON();
    while (1);
}

