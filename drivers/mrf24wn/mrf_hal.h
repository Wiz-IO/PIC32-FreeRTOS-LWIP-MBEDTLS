/* 
 * File:   mrf_hal.h
 * Author: Georgi Angelov
 * Created on 21 Август 2018, 13:55
 */

#ifndef MRF_HAL_H
#define	MRF_HAL_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "sys.h"
    
#define WF_HIBERNATE_BIT            0
#define WF_HIBERNATE_DIR            TRISA
#define WF_HIBERNATE_LAT            LATA
#define WF_HIBERNATE_MASK           MASK(WF_HIBERNATE_BIT)
#define WD_IS_HIBERNATE()           (WF_HIBERNATE_LAT & WF_HIBERNATE_MASK)
#define WD_HIBERNATE_LO()           LO(WF_HIBERNATE_LAT, WF_HIBERNATE_MASK) 
#define WD_HIBERNATE_HI()           HI(WF_HIBERNATE_LAT, WF_HIBERNATE_MASK) 
#define WD_HIBERNATE_DIR_OUTPUT()   LO(WF_HIBERNATE_DIR, WF_HIBERNATE_MASK)

#define WF_CS_BIT_POS               8
#define WF_CS_DIR                   TRISB
#define WF_CS_LAT                   LATB
#define WF_CS_MASK                  1 << WF_CS_BIT_POS
#define WD_CS_LO()                  LO(WF_CS_LAT, WF_CS_MASK)
#define WD_CS_HI()                  HI(WF_CS_LAT, WF_CS_MASK) 
#define WD_CS_DIR_OUTPUT()          LO(WF_CS_DIR, WF_CS_MASK)

#define WF_INT_BIT_POS               4
#define WF_INT_DIR                   TRISF
#define WF_INT_PIN                   PORTF
#define WF_INT_MASK                  1 << WF_INT_BIT_POS
#define WD_INT_DIR_INPUT()           HI(WF_INT_DIR, WF_INT_MASK) 
#define WF_INT_READ_PIN()            (WF_INT_PIN & WF_INT_MASK)    

#define WD_INT_ENABLE()             IEC0SET = _IEC0_INT3IE_MASK
#define WD_INT_DISABLE()            IEC0CLR = _IEC0_INT3IE_MASK
#define WD_INT_CLEAR()              IFS0CLR = _IFS0_INT3IF_MASK
    
void WDRV_SPI_Init(void);
void WDRV_SPI_Deinit(void);
void WDRV_SPI_In(uint8_t * const OutBuf, uint16_t OutSize, uint8_t * const InBuf, uint16_t InSize);
void WDRV_GPIO_PowerUp(void);
void WDRV_GPIO_PowerDown(void);
void WDRV_HibernateEnable(void);
void WDRV_HibernateDisable(void);
bool WDRV_InHibernateMode(void);
void WDRV_SPI_Out(uint8_t * const OutBuf, uint16_t OutSize);
    
#ifdef	__cplusplus
}
#endif
#endif	/* MRF_HAL_H */

