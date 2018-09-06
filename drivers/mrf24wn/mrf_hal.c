/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#include "mrf_hal.h"

static inline __attribute__((__always_inline__)) void SPI3_WaitForDataByte(void) {
    while ((SPI3STAT & _SPI3STAT_SPITBF_MASK) || (!(SPI3STAT & _SPI3STAT_SPIRBF_MASK)));
}

static void SPI3_Write(uint8_t * buf, uint16_t size) {
    while (size--) {
        SPI3BUF = *buf++;
        SPI3_WaitForDataByte();
        SPI3BUF;
    };
}

static void SPI3_Read(uint8_t * buf, uint16_t size) {
    while (size--) {
        SPI3BUF = 0xFF;
        SPI3_WaitForDataByte();
        *buf++ = SPI3BUF;
    }
}

static void GPIO_OutLow(uint32_t channel, uint32_t bit_pos) {
    //s_GPIOOutLow(channel, bit_pos);
}

static void GPIO_OutHigh(uint32_t channel, uint32_t bit_pos) {
    //s_GPIOOutHigh(channel, bit_pos);
}

void WDRV_GPIO_Init(void) {

}

/*LIB*/
void WDRV_GPIO_PowerUp(void) {
    WD_HIBERNATE_HI();
}

/*LIB*/
void WDRV_GPIO_PowerDown(void) {
    WD_HIBERNATE_LO();
}

void WDRV_HibernateEnable(void) {
    WDRV_GPIO_PowerDown();
}

void WDRV_HibernateDisable(void) {
    WDRV_GPIO_PowerUp();
}

bool WDRV_InHibernateMode(void) {
    return (bool) WD_IS_HIBERNATE();
}

void WDRV_SPI_Out(uint8_t * const OutBuf, uint16_t OutSize) {
    WD_INT_DISABLE();
    WD_CS_LO();
    SPI3_Write(OutBuf, OutSize);
    WD_CS_HI();
    WD_INT_ENABLE();
}

void WDRV_SPI_In(uint8_t * const OutBuf, uint16_t OutSize, uint8_t * const InBuf, uint16_t InSize) {
    WD_INT_DISABLE();
    WD_CS_LO();
    if (OutSize > 0)
        SPI3_Write(OutBuf, OutSize);
    if (InSize > 0)
        SPI3_Read(InBuf, InSize);
    WD_CS_HI();
    WD_INT_ENABLE();
}

void WDRV_SPI_Init(void) {
    SYS_SystemUnlock();
    INT3R = 2; // RPF4 INT3 RF4 
    SDI3R = 6; // SDI3 RB10 MISO INPUT
    RPB9R = 7; // SDO3 RB9 MOSI OUTPUT
    TRISBCLR = MASK(14); // CLK output
    TRISBCLR = MASK(9); // MOSI output
    TRISBSET = MASK(10); // MISO input    
    SYS_SystemLock();

    WD_INT_DIR_INPUT();
    WD_HIBERNATE_LO();
    WD_HIBERNATE_DIR_OUTPUT();
    WD_CS_HI();
    WD_CS_DIR_OUTPUT();

    SPI3CON = 0;
    int i, dumy;
    for (i = 0; i < 16; i++) dumy = SPI3BUF;
    SPI3BRG = spi_calutate_brg(SYS_CLK_BUS_PERIPHERAL_1, 8000000);
    SPI3CONSET = _SPI3CON_MSTEN_MASK | _SPI3CON_CKE_MASK;
    SPI3CONSET = _SPI3CON_ON_MASK; /* Enable SPI */

    IPC4bits.INT3IP = 1;
    WD_INT_CLEAR();
}

void WDRV_SPI_Deinit(void) {
    WD_INT_DISABLE();
    SPI3CON = 0;
    SPI3CONSET = 0;
    WDRV_GPIO_PowerDown();
}

/* LIB */
void WDRV_INTR_SourceEnable(void) {
    WD_INT_CLEAR();
    WD_INT_ENABLE();
}

/* LIB */
void WDRV_INTR_SourceDisable(void) {
    WD_INT_DISABLE();
    WD_INT_CLEAR();
}

/* LIB */
void WDRV_INTR_Init(void) {
    WDRV_INTR_SourceDisable();
}

/* LIB */
void WDRV_INTR_Deinit(void) {
    WDRV_INTR_SourceDisable();
}

/* LIB, 
 * add mrf_isr.S !!! 
 */
extern void WDRV_EXT_HWInterruptHandler(void const *pointer);
void ISR_MRF24WN(void) {
    WD_INT_DISABLE(); // disable further interrupts
    WD_INT_CLEAR();
    LED_RED_ON();
    WDRV_EXT_HWInterruptHandler(NULL);
    LED_RED_OFF();
}