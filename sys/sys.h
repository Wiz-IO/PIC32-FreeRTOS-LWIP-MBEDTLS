#ifndef SYS_H
#define	SYS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>  
#include <stdio.h>    
#include <string.h>   
#include <time.h>
#include "sys_debug.h" 
#include "sys_common.h"
 
#define SYS_CLK_FREQ                (200000000ul)
#define SYS_CLK_BUS_PERIPHERAL_1    (100000000ul)    
    
#define GetSystemClock()            (SYS_CLK_FREQ)   
#define ReadCoreTimer()             _CP0_GET_COUNT()
#define SetCoreTimer(V)             _CP0_SET_COUNT(V)
#define us_SCALE                    (uint32_t)(GetSystemClock()/2000000ul)
#define ms_SCALE                    (uint32_t)(GetSystemClock()/2000ul)    
    
#define GET_INT_DISABLE()  (int)__builtin_disable_interrupts()
#define INT_ENABLE()       __builtin_mtc0(12,0,(__builtin_mfc0(12,0) | 0x0001))

#define DISABLE_INT()       int F = GET_INT_DISABLE()
#define ENABLE_INT()        if (F) INT_ENABLE()
    
//uint32_t SYS_INT_StatusGetAndDisable(void);
        
static inline __attribute__((always_inline)) void SysKeyUnlock(void) {	
	SYSKEY = 0x00000000;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;
}

static inline __attribute__((always_inline)) void SysKeyLock(void) {
	SYSKEY = 0x33333333;
}
    
static inline __attribute__((always_inline)) void SystemUnlock(void) {
    DISABLE_INT();
    SysKeyUnlock();
    ENABLE_INT();
}

static inline __attribute__((always_inline)) void SystemLock(void) {
    DISABLE_INT();
    SysKeyLock();
    ENABLE_INT();
}

typedef unsigned long _paddr_t; /* a physical address */
typedef unsigned long _vaddr_t; /* a virtual address */
#define KVA_TO_PA(v) 	((_paddr_t)(v) & 0x1fffffff)
#define PA_TO_KVA0(pa)	((void *) ((pa) | 0x80000000))
#define PA_TO_KVA1(pa)	((void *) ((pa) | 0xa0000000))
#define KVA0_TO_KVA1(v)	((void *) ((unsigned)(v) | 0x20000000))
#define KVA1_TO_KVA0(v)	((void *) ((unsigned)(v) & ~0x20000000))
#define IS_KVA(v)       ((int)(v) < 0)
#define IS_KVA0(v)      (((unsigned)(v) >> 29) == 0x4)
#define IS_KVA1(v)      (((unsigned)(v) >> 29) == 0x5)
#define IS_KVA01(v)     (((unsigned)(v) >> 30) == 0x2)

#define mSET( REG_NAME, BIT_NAME)   REG_NAME##SET = _##REG_NAME##_##BIT_NAME##_MASK
#define mCLR( REG_NAME, BIT_NAME)   REG_NAME##CLR = _##REG_NAME##_##BIT_NAME##_MASK
#define mINV( REG_NAME, BIT_NAME)   REG_NAME##INV = _##REG_NAME##_##BIT_NAME##_MASK

#define MASK(_B_)               (1 << _B_)
#define MASK_CLR(_P_, _M_)      _P_##CLR = _M_      
#define MASK_SET(_P_, _M_)      _P_##SET = _M_ 
#define MASK_INV(_P_, _M_)      _P_##INV = _M_ 

#define LO(_p_, _m_)            MASK_CLR( _p_, _m_ ) 
#define HI(_p_, _m_)            MASK_SET( _p_, _m_ )
#define TG(_p_, _m_)            MASK_INV( _p_, _m_ )

#define LED_RED_OFF()           LATECLR = _LATE_LATE3_MASK 
#define LED_RED_ON()            LATESET = _LATE_LATE3_MASK 
#define LED_RED_TOGGLE()        LATEINV = _LATE_LATE3_MASK 

#define LED_GREEN_OFF()         LATECLR = _LATE_LATE4_MASK 
#define LED_GREEN_ON()          LATESET = _LATE_LATE4_MASK 
#define LED_GREEN_TOGGLE()      LATEINV = _LATE_LATE4_MASK
   
#define LED_ORANGE_OFF()        LATECLR = _LATE_LATE6_MASK 
#define LED_ORANGE_ON()         LATESET = _LATE_LATE6_MASK 
#define LED_ORANGE_TOGGLE()     LATEINV = _LATE_LATE6_MASK
#define LED_ORANGE_GET()        LATE & _LATE_LATE6_MASK

#define mINIT_LED()                     \
    TRISECLR = _TRISE_TRISE3_MASK;      \
    TRISECLR = _TRISE_TRISE4_MASK;      \
    TRISECLR = _TRISE_TRISE6_MASK;      \
    LED_RED_OFF();                      \
    LED_GREEN_OFF();                    \
    LED_ORANGE_OFF();                   \

int SYS_Init(void);
void __attribute__((noreturn)) SYS_SoftReset(void);

inline __attribute__((always_inline)) uint32_t TickMS(void) {
    return ReadCoreTimer() / ms_SCALE;
}
inline __attribute__((always_inline)) uint32_t TickUS(void) {
    return ReadCoreTimer() / us_SCALE;
}
uint32_t ElapsedTime(uint32_t startTime, uint32_t currentTime);
void DelayMS(uint32_t t);
void DelayUS(uint32_t t);

#ifdef	__cplusplus
}
#endif

#endif	/* SYS_H */

