/*
		FileName: spi.h
*/
/*
    plib_mz for PIC32MZ microcontrollers - Copyright (C) 2016
                                            Spas Spasov.

    This file is part of plib_mz.

    "plib_mz" is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    "plib_mz" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
   Concepts and parts of this file have been contributed by Spas Spasov.
 */

#ifndef SPI_H
#define	SPI_H

#include <xc.h>
#include <GenericTypeDefs.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

#undef  _SPI_DEF_CHN_       // symbol used for SPI channel detection/definition
    
// This definition need only in mask macros
#if defined(_SPI1)
    #define _SPI_DEF_CHN_       1
#elif defined(_SPI2)
    #define _SPI_DEF_CHN_       2
#endif  // getting a valid SPI channel definition

/* SPI Interrupt defines */    
#define  SPI_FAULT_INT_EN       (0x00000001)  /* SPI Fault Interrupt Enable     */
#define  SPI_FAULT_INT_DIS      (0x00000000)  /* SPI Fault Interrupt Disable    */

#define  SPI_RX_INT_EN			(0x00000002)  /* SPI Rx Interrupt Enable        */
#define  SPI_RX_INT_DIS			(0x00000000)  /* SPI Rx Interrupt Disable       */    
 
#define  SPI_TX_INT_EN			(0x00000004)  /* SPI Tx Interrupt Enable        */
#define  SPI_TX_INT_DIS         (0x00000000)  /* SPI Tx Interrupt Disable       */    
    
// SPI channels definition
// this enumerated value can be used in any function that requires
// an SPI channel as an input parameter

typedef enum
{
#if defined(_SPI1)
    SPI_CHANNEL1 = 0,        
#endif  // _SPI1
#if defined(_SPI2)
    SPI_CHANNEL2 = 1,
#endif  // _SPI2
#if defined(_SPI3)
    SPI_CHANNEL3 = 2,
#endif  // _SPI3            
#if defined(_SPI4)
    SPI_CHANNEL4 = 3,
#endif  // _SPI4            
#if defined(_SPI5)
    SPI_CHANNEL5 = 4,
#endif  // _SPI5            
#if defined(_SPI6)
    SPI_CHANNEL6 = 5,
#endif  // _SPI6            
    SPI_CHANNELS = 0
#if defined(_SPI1)
                + 1
#endif
#if defined(_SPI2)
                + 1
#endif   
#if defined(_SPI3)
                + 1
#endif
#if defined(_SPI4)
                + 1
#endif             
#if defined(_SPI5)
                + 1
#endif
#if defined(_SPI6)
                + 1
#endif                  
}SpiChannel;    
    

// macros to translate internal SPI register definition to more user friendly interface definitions
#define _SPI_CON_MASK_(x, m)        _SPI ## x ## CON_ ## m
#define X_SPI_CON_MASK_(x, m)       _SPI_CON_MASK_(x, m)            // concatenation macro
#define _SPIxCON_MASK_(m)       X_SPI_CON_MASK_(_SPI_DEF_CHN_, m)

#define _SPI_STAT_MASK_(x, m)       _SPI ## x ## STAT_ ## m
#define X_SPI_STAT_MASK_(x, m)      _SPI_STAT_MASK_(x, m)           // concatenation macro
#define _SPIxSTAT_MASK_(m)      X_SPI_STAT_MASK_(_SPI_DEF_CHN_, m)

#define _SPI_CON2_MASK_(x, m)    _SPI ## x ## CON2_ ## m
#define X_SPI_CON2_MASK_(x, m)   _SPI_CON2_MASK_(x, m)            // concatenation macro
#define _SPIxCON2_MASK_(m)       X_SPI_CON2_MASK_(_SPI_DEF_CHN_, m)

#define _SPIxSTAT_RXBUFELM_POSITION     _SPI1STAT_RXBUFELM_POSITION
#define _SPIxSTAT_TXBUFELM_POSITION     _SPI1STAT_TXBUFELM_POSITION
#define _SPIxSTAT_SPITUR_POSITION       _SPI1STAT_SPITUR_POSITION
        
// open flags
typedef enum
{
    // master opening mode
    SPI_OPEN_MSTEN =        _SPIxCON_MASK_(MSTEN_MASK), // set the Master mode
    SPI_OPEN_SMP_END =      _SPIxCON_MASK_(SMP_MASK),   // Master Sample Phase for the input bit at the end of the data out time. Otherwise data is sampled in the middle.
    SPI_OPEN_MSSEN =        _SPIxCON_MASK_(MSSEN_MASK), // enable the driving of the Slave Select (SS) output pin by the Master
    SPI_OPEN_MSSEN_HIGH =   _SPIxCON_MASK_(FRMPOL_MASK),    // Master driven SS output active high. Otherwise low.

    // slave opening mode
    SPI_OPEN_SLVEN =        0,              // set the Slave mode
    SPI_OPEN_SSEN =         _SPIxCON_MASK_(SSEN_MASK),  // enable the SS input pin.

    SPI_OPEN_MCLKSEL =      _SPIxCON_MASK_(MCLKSEL_MASK),

    // clocking opening mode
    SPI_OPEN_CKP_HIGH = _SPIxCON_MASK_(CKP_MASK),  // set the clock polarity to (idle-high, active-low). Otherwise is (idle-low, active-high).
    SPI_OPEN_CKE_REV  = _SPIxCON_MASK_(CKE_MASK), // set the Clock Edge reversed: transmit from active to idle. Otherwise transmit when clock goes from idle to active

    // data characters opening mode
    SPI_OPEN_MODE8 =        0,              // set 8 bits/char
    SPI_OPEN_MODE16 =       _SPIxCON_MASK_(MODE16_MASK),    // set 16 bits/char
    SPI_OPEN_MODE32 =       _SPIxCON_MASK_(MODE32_MASK),    // set 32 bits/char

    // framed mode opening mode
    SPI_OPEN_FRMEN =        _SPIxCON_MASK_(FRMEN_MASK), // Enable the Framed SPI support. Otherwise the Framed SPI is disabled.
    SPI_OPEN_FSP_IN =       _SPIxCON_MASK_(FRMSYNC_MASK),   // Frame Sync Pulse (FSP) direction set to input (Frame Slave).
                                        // Otherwise the FSP is output and the SPI channel operates as a Frame Master.
    SPI_OPEN_FSP_HIGH =     _SPIxCON_MASK_(FRMPOL_MASK),    // FSP polarity set active high. Otherwise the FSP is active low.
    SPI_OPEN_FSP_CLK1 =     _SPIxCON_MASK_(SPIFE_MASK), // Set the FSP to coincide with the 1st bit clock.
                                        // Otherwise the FSP precedes the 1st bit clock
    SPI_OPEN_FSP_WIDE =     _SPIxCON_MASK_(FRMSYPW_MASK),   // set the FSP one character wide. Otherwise the FSP is one clock wide.

    SPI_OPEN_FRM_CNT1 =     (0 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the number of characters per frame (Frame Counter) to 1 (default)
    SPI_OPEN_FRM_CNT2 =     (1 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 2
    SPI_OPEN_FRM_CNT4 =     (2 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 4
    SPI_OPEN_FRM_CNT8 =     (3 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 8
    SPI_OPEN_FRM_CNT16 =    (4 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 16
    SPI_OPEN_FRM_CNT32 =    (5 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 32

    // enhanced buffer (FIFO) opening mode
    SPI_OPEN_ENHBUF =       _SPIxCON_MASK_(ENHBUF_MASK),    // enable the enhanced buffer mode

    SPI_OPEN_TBE_NOT_FULL =   (3 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer not full (at least one slot empty)
    SPI_OPEN_TBE_HALF_EMPTY = (2 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer >= 1/2 empty
    SPI_OPEN_TBE_EMPTY =      (1 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer completely empty
    SPI_OPEN_TBE_SR_EMPTY =   (0 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when the last character is shifted out of the internal Shift Register
                                            // and the transmit is complete

    SPI_OPEN_RBF_FULL =      (3 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is full
    SPI_OPEN_RBF_HALF_FULL = (2 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is >= 1/2 full
    SPI_OPEN_RBF_NOT_EMPTY = (1 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is not empty
    SPI_OPEN_RBF_EMPTY =     (0 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is empty (the last character in the buffer is read).

    // general opening mode
    SPI_OPEN_DISSDO = _SPIxCON_MASK_(DISSDO_MASK), // disable the usage of the SDO pin by the SPI
    SPI_OPEN_DISSDI = _SPIxCON_MASK_(DISSDI_MASK), // disable the usage of the SDI pin by the SPI
    SPI_OPEN_SIDL =   _SPIxCON_MASK_(SIDL_MASK  ), // enable the Halt in the CPU Idle mode. Otherwise the SPI will be still active when the CPU is in Idle mode.
    SPI_OPEN_ON =     _SPIxCON_MASK_(ON_MASK    ), // turn ON the SPI (not used in SpiChnOpen)
}SpiOpenFlags;  // open flags that can be used with SpiChnOpen. Defined in the processor header file.

typedef enum {
    SPI_OPEN2_SPISGNEXT = _SPIxCON2_MASK_(SPISGNEXT_MASK), // Sign Extend Read Data from the RX FIFO bit
    SPI_OPEN2_FRMERREN  = _SPIxCON2_MASK_(FRMERREN_MASK),  // Enable Interrupt Events via FRMERR bit
    SPI_OPEN2_SPIROVEN  = _SPIxCON2_MASK_(SPIROVEN_MASK),  // Enable Interrupt Events via SPIROV bit
    SPI_OPEN2_SPITUREN  = _SPIxCON2_MASK_(SPITUREN_MASK),  // Enable Interrupt Events via SPITUR bit
    SPI_OPEN2_IGNROV    = _SPIxCON2_MASK_(IGNROV_MASK),    // Ignore Receive Overflow bit (for Audio Data Transmissions):
    SPI_OPEN2_IGNTUR    = _SPIxCON2_MASK_(IGNTUR_MASK),    // Ignore Transmit Underrun bit (for Audio Data Transmissions)
    SPI_OPEN2_AUDEN     = _SPIxCON2_MASK_(AUDEN_MASK),     // Enable Audio CODEC Support bit
    SPI_OPEN2_AUDMONO   = _SPIxCON2_MASK_(AUDMONO_MASK),   // Transmit monoaural, i.e. left channel = right channel
    SPI_OPEN2_AUDMOD    = _SPIxCON2_MASK_(AUDMOD_MASK),    // Audio Protocol Mode bits
    SPI_OPEN2_AUDMOD_DSP =  _SPIxCON2_MASK_(AUDMOD_MASK),    // Audio Protocol Mode bits = 11 => PCM/DSP mode
    SPI_OPEN2_AUDMOD0   = _SPIxCON2_MASK_(AUDMOD0_MASK),   // Audio Protocol Mode bits, Bit 0
    SPI_OPEN2_AUDMOD_LJ = _SPIxCON2_MASK_(AUDMOD0_MASK),   // Audio Protocol Mode bits, Bit 0 = 1 => Left Justified mode
    SPI_OPEN2_AUDMOD1   = _SPIxCON2_MASK_(AUDMOD1_MASK),   // Audio Protocol Mode bits, Bit 1
    SPI_OPEN2_AUDMOD_RJ = _SPIxCON2_MASK_(AUDMOD1_MASK),   // Audio Protocol Mode bits, Bit 1 = 1 => Right Justified mode
    SPI_OPEN2_AUDMOD_I2S = 0x0,                            // Audio Protocol Mode bits = 0x0 => I2S mode
} SpiOpen2Flags;

typedef enum
{
    SPI_STAT_SPIRBF =  _SPIxSTAT_MASK_(SPIRBF_MASK),   // receive buffer full
    SPI_STAT_SPITBF =  _SPIxSTAT_MASK_(SPITBF_MASK),   // transmit buffer full
    SPI_STAT_SPITBE =  _SPIxSTAT_MASK_(SPITBE_MASK),   // transmit buffer empty
    SPI_STAT_SPIRBE =  _SPIxSTAT_MASK_(SPIRBE_MASK),   // receive buffer empty
    SPI_STAT_FRMERR =  _SPIxSTAT_MASK_(FRMERR_MASK),   // receive buffer empty
    SPI_STAT_SPIROV =  _SPIxSTAT_MASK_(SPIROV_MASK),   // receive overflow
    SPI_STAT_SPISRMT = _SPIxSTAT_MASK_(SRMT_MASK),     // shift register empty
    SPI_STAT_SPITUR =  _SPIxSTAT_MASK_(SPITUR_MASK),   // transmit underrun
    SPI_STAT_SPIBUSY = _SPIxSTAT_MASK_(SPIBUSY_MASK),  // busy with transaction
}SpiStatusFlags;        // possible SPI status flags


// *****************************************************************************
/* Interrupt Muli-Channel Converter

  Summary:
    Interrupt Muli-Channel Converter definitions

  Description:
    These definitions can be used to convert a channel into the correct INT_SOURCE value.

    These macros can be used by
      void INTClearFlag(INT_SOURCE source)
      void INTSetFlag(INT_SOURCE source)
      unsigned int INTGetFlag(INT_SOURCE source)
      void INTEnable(INT_SOURCE source, INT_EN_DIS enable)
      unsigned int INTGetEnable(INT_SOURCE source)

*/
// SPI Interrupt Channel ( return INT_SOURCE_SPI_x_ERROR source)
extern __inline__ INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_SPI( SpiChannel chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#if defined(_SPI1)        
        case 0:          
            ret_src = INT_SOURCE_SPI_1_ERROR;            
            break;
#endif
#if defined(_SPI2)
        case 1:            
            ret_src = INT_SOURCE_SPI_2_ERROR;           
            break;
#endif 
        
#if defined(_SPI3)
        case 2:
            ret_src = INT_SOURCE_SPI_3_ERROR;
            break;
#endif                                       
#if defined(_SPI4)
        case 3:
            ret_src = INT_SOURCE_SPI_4_ERROR;
            break;
#endif                           
#if defined(_SPI5)
        case 4:
            ret_src = INT_SOURCE_SPI_5_ERROR;
            break;
#endif                   
#if defined(_SPI6)    
        case 5:
            ret_src = INT_SOURCE_SPI_6_ERROR;
            break;
#endif                     
    }
    return ret_src;
}

// SPI Fault Interrupt Channel ( return INT_SOURCE_SPI_x_ERROR source)
extern __inline__ INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_SPI_ERROR( SpiChannel chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#if defined(_SPI1)        
        case 0:          
            ret_src = INT_SOURCE_SPI_1_ERROR;            
            break;
#endif
#if defined(_SPI2)
        case 1:            
            ret_src = INT_SOURCE_SPI_2_ERROR;           
            break;
#endif 
        
#if defined(_SPI3)
        case 2:
            ret_src = INT_SOURCE_SPI_3_ERROR;
            break;
#endif                                       
#if defined(_SPI4)
        case 3:
            ret_src = INT_SOURCE_SPI_4_ERROR;
            break;
#endif                           
#if defined(_SPI5)
        case 4:
            ret_src = INT_SOURCE_SPI_5_ERROR;
            break;
#endif                   
#if defined(_SPI6)    
        case 5:
            ret_src = INT_SOURCE_SPI_6_ERROR;
            break;
#endif                     
    }
    return ret_src;
}

// SPI RX Interrupt Channel ( return INT_SOURCE_SPI_x_RECEIVE source)
extern __inline__ INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_SPI_RX( SpiChannel chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#if defined(_SPI1)        
        case 0:          
            ret_src = INT_SOURCE_SPI_1_RECEIVE;            
            break;
#endif
#if defined(_SPI2)
        case 1:            
            ret_src = INT_SOURCE_SPI_2_RECEIVE;           
            break;
#endif 
        
#if defined(_SPI3)
        case 2:
            ret_src = INT_SOURCE_SPI_3_RECEIVE;
            break;
#endif                                       
#if defined(_SPI4)
        case 3:
            ret_src = INT_SOURCE_SPI_4_RECEIVE;
            break;
#endif                           
#if defined(_SPI5)
        case 4:
            ret_src = INT_SOURCE_SPI_5_RECEIVE;
            break;
#endif                   
#if defined(_SPI6)    
        case 5:
            ret_src = INT_SOURCE_SPI_6_RECEIVE;
            break;
#endif                     
    }
    return ret_src;
}

// SPI TX Interrupt Channel ( return INT_SOURCE_SPI_x_TRANSMIT source)
extern __inline__ INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_SPI_TX( SpiChannel chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#if defined(_SPI1)        
        case 0:          
            ret_src = INT_SOURCE_SPI_1_TRANSMIT;            
            break;
#endif
#if defined(_SPI2)
        case 1:            
            ret_src = INT_SOURCE_SPI_2_TRANSMIT;           
            break;
#endif 
        
#if defined(_SPI3)
        case 2:
            ret_src = INT_SOURCE_SPI_3_TRANSMIT;
            break;
#endif                                       
#if defined(_SPI4)
        case 3:
            ret_src = INT_SOURCE_SPI_4_TRANSMIT;
            break;
#endif                           
#if defined(_SPI5)
        case 4:
            ret_src = INT_SOURCE_SPI_5_TRANSMIT;
            break;
#endif                   
#if defined(_SPI6)    
        case 5:
            ret_src = INT_SOURCE_SPI_6_TRANSMIT;
            break;
#endif                     
    }
    return ret_src;
}


/*********************************************************************
 * Function:        void SpiChnOpen(SpiChannel chn, SpiOpenFlags oFlags, unsigned int srcClkDiv)
 *
 * PreCondition:    srcClkDiv  - valid value between 2 and 1024
 *                  chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set
 *                  oFlags - any of the values from SpiOpenFlags:
 *                             master slave opening mode: SPI_OPEN_MSTEN, SPI_OPEN_SLVEN, SPI_OPEN_SSEN
 *                             clocking and character opening mode: SPI_OPEN_CKP_HIGH, SPI_OPEN_CKE_REV, SPI_OPEN_SMP_END, SPI_OPEN_MODE8, SPI_OPEN_MODE16, SPI_OPEN_MODE32
 *                             framed mode opening mode: SPI_OPEN_FSP_CLK1, SPI_OPEN_FSP_HIGH, SPI_OPEN_FSP_IN, SPI_OPEN_FRMEN
 *                             general opening mode: SPI_OPEN_DISSDO, SPI_OPEN_SIDL, SPI_OPEN_ON
 *                  srcClkDiv - Source Clock divisor to extract the bitrate=srcClk/srcClkDiv.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function opens the SPI channel: turns the channel on and initializes it according to the oFlags input parameter.
 *                  After that the channel is enabled.
 *                  It also sets the brg register.
 *                  The SPI bitrate is given by: bitrate=srcClk/(2*(SPIBRG+1))
 *                  The input parametes srcClkDiv specifies the srcClk divisor term (2*(SPIBRG+1)),
 *                  so the BRG is calculated as SPIBRG=srcClkDiv/2-1.
 *
 * Note:            - The channel is turned off, the pending interrupts are cleared, interrupts are disabled. After that it is configured
 *                  - The bitrate is always obtained by dividing the srcClk by srcClkDiv, an even number
 *                  between 2 and 1024.
 *                  - For a specific SPI bitrate, the srcClkDiv that has to be passed is:
 *                  srcClkDiv=srcClk/bitrate;
 *                  - When selecting the number of bits per character, SPI_OPEN_MODE32 has the highest priority.
 *                  If SPI_OPEN_MODE32 is not set, then SPI_OPEN_MODE16 selects the character width.
 *                  - The function properly sets the SPI pins as digital i/o pins.
 *                  - The SS pin is set as a digital pin only if in frame mnode or if the SPI_OPEN_SSEN is set.
 *                  Even in master mode the library will properly se the SS pin as an digital output
 *                  if the SPI_OPEN_SSEN is set.
 *                  - The SPI channel is turned ON after it is configured. The use of SPI_OPEN_ON is not needed.
 *                  - For PIC32MX the srcClk is the peripheral bus clock.
 *
 * Example:        int srcClk=GetPBusFrequency(); SpiChnOpen(SPI_CHANNEL1, SPI_OPEN_MSTEN|SPI_OPEN_SMP_END|SPI_OPEN_MODE32, srcClk/20000000);
 *                 will open the SPI1 and set the bit rate to 20MHz.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnOpen( SpiChannel chn, SpiOpenFlags oFlags, unsigned int srcClkDiv )
{
    unsigned int dummyRd;
    unsigned int configR;
    
    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF 
    volatile UINT *spi_brg      = (volatile UINT *)(0xBF821030 + (0x200*((UINT)chn)));     //SPIxBRG 

    INTEnable(INT_SOURCE_SPI_ERROR(chn), INT_DISABLED);     // disable the fault-channel interrupts
    INTEnable(INT_SOURCE_SPI_RX(chn), INT_DISABLED);        // disable the rx-channel interrupts
    INTEnable(INT_SOURCE_SPI_TX(chn), INT_DISABLED);        // disable the tx-channel interrupts
    spi_con++;
    *spi_con = _SPIxCON_MASK_(ON_MASK);                     // turn off and reset
    configR = oFlags | _SPIxCON_MASK_(ON_MASK);             // channel configuration. make sure we turn the channel on
    INTClearFlag(INT_SOURCE_SPI_ERROR(chn));                // clear the existing fault-channel interrupt flags
    INTClearFlag(INT_SOURCE_SPI_RX(chn));                   // clear the existing rx-channel interrupt flags
    INTClearFlag(INT_SOURCE_SPI_TX(chn));                   // clear the existing tx-channel interrupt flags
    *spi_brg = (srcClkDiv>>1) - 1;                          // set the brg
    dummyRd = *spi_buf;                                     // clear the receive buffer
    spi_stat++;
    *spi_stat = _SPIxSTAT_MASK_(SPIROV_MASK);               // clear overflow
    spi_con--;
    *spi_con = configR;                                     // set the configuration word
}

/*********************************************************************
 * Function:        void    SpiChnOpenEx(SpiChannel chn, SpiOpenFlags oFlags, SpiOpen2Flags oFlags2, unsigned int srcClkDiv)
 *
 * PreCondition:    srcClkDiv  - valid value between 2 and 1024
 *                  chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set
 *                  oFlags - any of the values from SpiOpenFlags:
 *                             master slave opening mode: SPI_OPEN_MSTEN, SPI_OPEN_SLVEN, SPI_OPEN_SSEN
 *                             clocking and character opening mode: SPI_OPEN_CKP_HIGH, SPI_OPEN_CKE_REV, SPI_OPEN_SMP_END, SPI_OPEN_MODE8, SPI_OPEN_MODE16, SPI_OPEN_MODE32
 *                             framed mode opening mode: SPI_OPEN_FSP_CLK1, SPI_OPEN_FSP_HIGH, SPI_OPEN_FSP_IN, SPI_OPEN_FRMEN
 *                             general opening mode: SPI_OPEN_DISSDO, SPI_OPEN_SIDL, SPI_OPEN_ON
 *                  oFlags2 - any of the values from SpiOpen2Flags
 *                  srcClkDiv - Source Clock divisor to extract the bitrate=srcClk/srcClkDiv.
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function opens the SPI channel: turns the channel on and initializes it according to the oFlags input parameter.
 *                  After that the channel is enabled.
 *                  It also sets the brg register.
 *                  The SPI bitrate is given by: bitrate=srcClk/(2*(SPIBRG+1))
 *                  The input parametes srcClkDiv specifies the srcClk divisor term (2*(SPIBRG+1)),
 *                  so the BRG is calculated as SPIBRG=srcClkDiv/2-1.
 *
 * Note:            - The channel is turned off, the pending interrupts are cleared, interrupts are disabled. After that it is configured
 *                  - The bitrate is always obtained by dividing the srcClk by srcClkDiv, an even number
 *                  between 2 and 1024.
 *                  - For a specific SPI bitrate, the srcClkDiv that has to be passed is:
 *                  srcClkDiv=srcClk/bitrate;
 *                  - When selecting the number of bits per character, SPI_OPEN_MODE32 has the highest priority.
 *                  If SPI_OPEN_MODE32 is not set, then SPI_OPEN_MODE16 selects the character width.
 *                  - The function properly sets the SPI pins as digital i/o pins.
 *                  - The SS pin is set as a digital pin only if in frame mnode or if the SPI_OPEN_SSEN is set.
 *                  Even in master mode the library will properly se the SS pin as an digital output
 *                  if the SPI_OPEN_SSEN is set.
 *                  - The SPI channel is turned ON after it is configured. The use of SPI_OPEN_ON is not needed.
 *                  - For PIC32MX the srcClk is the peripheral bus clock.
 *
 * Example:        int srcClk=GetPBusFrequency(); SpiChnOpen(SPI_CHANNEL1, SPI_OPEN_MSTEN|SPI_OPEN_SMP_END|SPI_OPEN_MODE32, SPI_OPEN2_AUDEN|SPI_OPEN2_AUDMOD_I2S, srcClk/20000000);
 *                 will open the SPI1 and set the bit rate to 20MHz.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnOpenEx( SpiChannel chn, SpiOpenFlags oFlags, SpiOpen2Flags oFlags2, unsigned int srcClkDiv )
{ 
    unsigned int dummyRd;
    unsigned int configR;
    unsigned int configR2;
    
    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF 
    volatile UINT *spi_brg      = (volatile UINT *)(0xBF821030 + (0x200*((UINT)chn)));     //SPIxBRG 
    volatile UINT *spi_con2     = (volatile UINT *)(0xBF821040 + (0x200*((UINT)chn)));     //SPIxCON2

    INTEnable(INT_SOURCE_SPI_ERROR(chn), INT_DISABLED);     // disable the fault-channel interrupts
    INTEnable(INT_SOURCE_SPI_RX(chn), INT_DISABLED);        // disable the rx-channel interrupts
    INTEnable(INT_SOURCE_SPI_TX(chn), INT_DISABLED);        // disable the tx-channel interrupts    
    spi_con++;
    *spi_con = _SPIxCON_MASK_(ON_MASK);                     // turn off and reset
    configR  = oFlags | _SPIxCON_MASK_(ON_MASK);            // channel configuration. make sure we turn the channel on
    configR2 = oFlags2;
    INTClearFlag(INT_SOURCE_SPI_ERROR(chn));                // clear the existing fault-channel interrupt flags
    INTClearFlag(INT_SOURCE_SPI_RX(chn));                   // clear the existing rx-channel interrupt flags
    INTClearFlag(INT_SOURCE_SPI_TX(chn));                   // clear the existing tx-channel interrupt flags
    *spi_brg = (srcClkDiv>>1) - 1;                          // set the brg
    dummyRd = *spi_buf;                                     // clear the receive buffer
    spi_stat++;
    *spi_stat = _SPIxSTAT_MASK_(SPIROV_MASK);               // clear overflow
    *spi_con2 = configR2;                                   // set configuration 2
    spi_con--;
    *spi_con = configR;                                     // set the configuration word
}

/*********************************************************************
 * Function:        void SpiChnClose(SpiChannel chn)
 *
 * PreCondition:    chn - a valid SPI channel number
 *
 * Input:           chn     - the channel to close
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function closes the SPI channel. Some previous error conditions are cleared.
 *                  Channel interrupts are disabled.
 *
 * Note:        - The I/O pins used by the SPI module are returned to their reset configuration.
 *          - The SPI_OPEN_SSEN is used to decide if the SS pin has to be returned to the reset state.
 *
 * Example:         SpiChnClose(SPI_CHANNEL2);
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnClose( SpiChannel chn )
{
    volatile UINT *spi_con_clr  = (volatile UINT *)(0xBF821004 + (0x200*((UINT)chn)));     //SPIxCONCLR
    
    *spi_con_clr = _SPIxCON_MASK_(ON_MASK);                 // turn off and reset

    INTEnable(INT_SOURCE_SPI_ERROR(chn), INT_DISABLED);     // disable the fault-channel interrupts
    INTEnable(INT_SOURCE_SPI_RX(chn), INT_DISABLED);        // disable the rx-channel interrupts
    INTEnable(INT_SOURCE_SPI_TX(chn), INT_DISABLED);        // disable the tx-channel interrupts 
    INTClearFlag(INT_SOURCE_SPI_ERROR(chn));                // clear the existing fault-channel interrupt flags
    INTClearFlag(INT_SOURCE_SPI_RX(chn));                   // clear the existing rx-channe interrupt flags
    INTClearFlag(INT_SOURCE_SPI_TX(chn));                   // clear the existing tx-channel interrupt flags
}

/*********************************************************************
 * Function:        void SpiChnChangeMode(SpiChannel chn, int isMaster, int isFrmMaster, int waitBusy)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to set
 *                  isMaster    - master/slave mode
 *                  isFrmMaster - frame master/slave mode
 *                  waitBusy    - boolean to wait/no wait for the current transfer to finish
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function changes the SPI channel mode on the fly.
 *
 * Note:            - If waitBusy is TRUE, the function blocks until the current transfer, if any, is completed.
 *                    What it means is that the data is not available in the SPIRxBUFF at the moment that SPIBUSY is cleared.
 *                    The function will wait for the SPIBUSY to be cleared.
 *                    For high SPIxBRG and PBDIV values note that the number of CPU clock cycles that have to be spent in this function could be significant.
 *                  - If waitBusy is FALSE, the function performs the mode switching immediately. It assumes that no transfer is currently on.
 *                    The caller must make sure that the current transfer, if any, is completed.
 *                  - isFrmMaster is relevant only if the SPI channel is operating in frame mode
 *                  - The SCK is properly configured as an digital I/O pin
 *                  - The SS is configured as a digital pin only if in frame mode or if the SSEN configuration bit is set.
 *
 * Example:         SpiChnChangeMode(SPI_CHANNEL2A, TRUE, TRUE, TRUE);
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnChangeMode( SpiChannel chn, int isMaster, int isFrmMaster, int waitBusy )
{
    int WasOn = 0;

    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT
    
    if(*spi_con & _SPIxCON_MASK_(ON_MASK))
    {
        if(waitBusy)
        {
            while(*spi_stat & _SPIxSTAT_MASK_(SPIBUSY_MASK));       // wait current txfer to finish
        }
        spi_con++;
        *spi_con = _SPIxCON_MASK_(ON_MASK);                         // turn off
        WasOn = 1;
    }
    else
    {
        spi_con++;        
    }

    // reconfigure the SPI channel
    if(isMaster)
    {
        spi_con++;
        *spi_con = _SPIxCON_MASK_(MSTEN_MASK);                      // SET
        spi_con--;
    }
    else
    {
        *spi_con = _SPIxCON_MASK_(MSTEN_MASK);                      // CLR        
    }

    if(isFrmMaster)
    {
        *spi_con = _SPIxCON_MASK_(FRMSYNC_MASK);                    // CLR
        spi_con++;
    }
    else
    {
        spi_con++;
        *spi_con = _SPIxCON_MASK_(FRMSYNC_MASK);                    // SET
    }

    if(WasOn)
    {
        *spi_con = _SPIxCON_MASK_(ON_MASK);                         // turn on
    }
}

// Helper function _SpiIsRxAvlbl
extern __inline__ int __attribute__((always_inline))   
_SpiIsRxAvlbl( SpiChannel chn )
{
    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    if(*spi_con & _SPIxCON_MASK_(ENHBUF_MASK))
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBE_MASK)) == 0);
    }
    else
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBF_MASK)) != 0);
    }
}

// Helper function _SpiIsTxAvlbl
extern __inline__ int __attribute__((always_inline))  
_SpiIsTxAvlbl( SpiChannel chn )
{
    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    if(*spi_con & _SPIxCON_MASK_(ENHBUF_MASK))
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPITBF_MASK)) == 0);
    }
    else
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPITBE_MASK)) != 0);
    }
}

/*********************************************************************
 * Function:        int SpiChnDataRdy(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to check
 *
 * Output:          TRUE        - if data available
 *                  FALSE       otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function reads the SPI channel data ready condition.
 *
 * Note:            None
 *
 * Example:         int isDataAvlbl=SpiChnDataRdy(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnDataRdy( SpiChannel chn )
{
    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    if(*spi_con & _SPIxCON_MASK_(ENHBUF_MASK))
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBE_MASK)) == 0);
    }
    else
    {
        return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBF_MASK)) != 0);
    }
}

/*********************************************************************
 * Function:        unsigned int SpiChnReadC(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to use
 *
 * Output:          data available in the SPI rx buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function returns immediately the data from the SPI buffer.
 *                  It does not check if there's any new data available.
 *
 * Note:            When a new data word has been shifted into shift register SPIxSR and
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  then the Rx Overflow (SPIROV) bit will be set.
 *                  The module will not transfer the received data from SPIxSR to the SPIxRXB.
 *                  Further data reception is disabled until the SPIROV bit is cleared.
 *                  The SPIROV bit is not cleared automatically by the module and must be
 *                  cleared by the user software (using SpiChnGetRov()).
 *
 * Example:         unsigned int newData=SpiChnReadC(SPI_CHANNEL2);
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
SpiChnReadC( SpiChannel chn )
{
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF   
    
    return (*spi_buf);      // return data in the buffer
}

/*********************************************************************
 * Function:        unsigned int SpiChnGetC(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to check
 *
 * Output:          data available in the SPI rx buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function waits for data to be available and returns it.
 *
 * Note:            When a new data word has been shifted into shift register SPIxSR and
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit will be set.
 *                  The module will not transfer the received data from SPIxSR to the SPIxRXB.
 *                  Further data reception is disabled until the SPIROV bit is cleared.
 *                  The SPIROV bit is not cleared automatically by the module and must be
 *                  cleared by the user software (using SpiChnGetRov()).
 *
 * Example:         int newData=SpiChnGetC(SPI_CHANNEL2);
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
SpiChnGetC( SpiChannel chn )
{
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF  
    
    while(!_SpiIsRxAvlbl(chn));     // wait data ready
    return (*spi_buf);              // return data in the buffer
}

/*********************************************************************
 * Function:        void SpiChnGetS(SpiChannel chn, unsigned int *pBuff, unsigned int nChars)
 *
 * PreCondition:    pBuff has to be a valid pointer to a buffer large enough to store all the received characters
 *
 * Input:           chn             - the SPI channel
 *                  pBuff           - address of buffer to store data
 *                  nChars          - number of characters expected
 *
 * Output:          None

 * Side Effects:    None
 *
 * Overview:        This routine reads a buffer of characters from the corresponding SPI channel receive buffer.
 *                  The number of byte/hword/word to be read is determined by parameter nChars.
 *                  Waits for RX data available for each character.
 *
 * Note:            - pBuff is considered to be 8/16/32 bits data pointer, according to the
 *                  current SPI mode!
 *                  - The function blocks waiting for the whole buffer to be received.
 *
 *                  When a new data word has been shifted into shift register SPIxSR and
 *                  the previous contents of receive register SPIxRXB have not been read
 *                  by the user software, then SPIROV bit will be set.
 *                  The module will not transfer the received data from SPIxSR to the SPIxRXB.
 *                  Further data reception is disabled until the SPIROV bit is cleared.
 *                  The SPIROV bit is not cleared automatically by the module and must be
 *                  cleared by the user software (using SpiChnGetRov()).
 *
 * Example:         unsigned short myBuff[100]; SpiChnGetS(SPI_CHANNEL2, myBuff, sizeof(myBuff)/sizeof(*myBuff));   // receive 16 bit characters
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnGetS( SpiChannel chn, unsigned int *pBuff, unsigned int nChars )
{
	unsigned int    rxData;
	unsigned int    conBits;
	unsigned char   *pBuff8     = (unsigned char*)pBuff;
	unsigned short  *pBuff16    = (unsigned short*)pBuff;

    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF     
    
	conBits = *spi_con;

	while(nChars--)
	{
		while(!_SpiIsRxAvlbl(chn));                 // wait data ready

		rxData = *spi_buf;
		if(conBits & _SPIxCON_MASK_(MODE32_MASK))
		{
			*pBuff++ = rxData;                       // 32 bits
		}
		else if(conBits & _SPIxCON_MASK_(MODE16_MASK))
		{
			*pBuff16++ = (unsigned short)rxData;     // 16 bits
		}
		else
		{
			*pBuff8++ = (unsigned char)rxData;		// 8 bits
		}
    }    
}

/*********************************************************************
 * Function:        int SpiChnTxBuffEmpty(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to check
 *
 * Output:          TRUE        - if transmit buffer empty
 *                  FALSE       otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function reads the SPI channel transmit buffer empty condition.
 *
 * Note:            None
 *
 * Example:         int canTransmit=SpiChnTxBuffEmpty(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnTxBuffEmpty( SpiChannel chn )
{  
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT     
    
    return ((*spi_stat & _SPIxSTAT_MASK_(SPITBE_MASK)) != 0);
}

/*********************************************************************
 * Function:        int SpiChnRxBuffEmpty(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to check
 *
 * Output:          TRUE - if the RX buffer is empty
 *                  FALSE otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel RX Buffer empty condition.
 *
 * Note:            Valid only in enhanced buffer (FIFO) mode.
 *
 * Example:         int isRxEmpty=SpiChnRxBuffEmpty(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnRxBuffEmpty( SpiChannel chn )
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT     
    
    return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBE_MASK)) != 0);    
}

/*********************************************************************
 * Function:        int SpiChnRxBuffFull(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to check
 *
 * Output:          TRUE - if the RX buffer is full
 *                  FALSE otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel RX Buffer full condition.
 *
 * Note:            Valid in both standard and enhanced buffer (FIFO) mode.
 *                  In enhanced buffer mode it signals that the whole FIFO is full.
 *
 * Example:         int isRxFull=SpiChnRxBuffFull(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnRxBuffFull(SpiChannel chn)
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT     
    
    return ((*spi_stat & _SPIxSTAT_MASK_(SPIRBF_MASK)) != 0);     
}

/*********************************************************************
 * Function:        int SpiChnRxBuffCount(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to check
 *
 * Output:          the number of characters available in the RX buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the number of characters available in the SPI channel RX Buffer.
 *
 * Note:            Valid only in enhanced buffer (FIFO) mode.
 *
 * Example:         int nCharsAvlbl=SpiChnRxBuffCount(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnRxBuffCount( SpiChannel chn )
{
    int tmp_RXBUFELM;
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    tmp_RXBUFELM = (int)((*spi_stat & _SPIxSTAT_MASK_(RXBUFELM_MASK)) >> _SPIxSTAT_RXBUFELM_POSITION);
    return tmp_RXBUFELM;
}

/*********************************************************************
 * Function:        int SpiChnTxBuffCount(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn - the channel to check
 *
 * Output:          the number of characters available in the TX buffer
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the number of characters in the SPI channel TX Buffer.
 *
 * Note:            Valid only in enhanced buffer (FIFO) mode.
 *
 * Example:         int nCharsToTx=SpiChnTxBuffCount(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnTxBuffCount( SpiChannel chn )
{
    int tmp_TXBUFELM;
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    tmp_TXBUFELM = (int)((*spi_stat & _SPIxSTAT_MASK_(TXBUFELM_MASK)) >> _SPIxSTAT_TXBUFELM_POSITION);
    return tmp_TXBUFELM;        
}

/*********************************************************************
 * Function:        int SpiChnIsSrEmpty(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the channel to check
 *
 * Output:          TRUE  - if the channel shift register is empty
 *                  FALSE - otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel shift register condition (SRMT).
 *                  Whenever the transmit shift register is empty, the SRMT status bit will be set.
 *
 * Note:            None
 *
 * Example:         int isEmpty=SpiChnIsSrEmpty(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnIsSrEmpty( SpiChannel chn )
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT     
    
    return ((*spi_stat & _SPIxSTAT_MASK_(SRMT_MASK)) != 0);
}

/*********************************************************************
 * Function:        int SpiChnGetTur(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the channel to check
 *
 * Output:          TRUE  - if channel transmit underrun occurred
 *                  FALSE - otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel transmit underrun condition.
 *                  This condition can occur only in framed mode when there's more than 1 characters per frame.
 *                  If the SPI channel has to transmit another character for the current frame and the character is not available,
 *                  a TX underrun condition occurs.
 *
 * Note:            The Tx Underrun condition must be cleared by disabling /re-enabling the Spi channel.
 *                  No transmission can further occur once this condition is set.
 *
 * Example:         int isUnderrun=SpiChnGetTur(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnGetTur( SpiChannel chn )
{
    int tmp_SPITUR;
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT    
    
    tmp_SPITUR = (int)((*spi_stat & _SPIxSTAT_MASK_(SPITUR_MASK)) >> _SPIxSTAT_SPITUR_POSITION);
    return tmp_SPITUR;     
}

/*********************************************************************
 * Function:        void SpiChnWriteC(SpiChannel chn, unsigned int data)
 *
 * PreCondition:    None
 *
 * Input:           chn  - the channel to use
 *                  data - the data to be written to the port
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine writes inmmediately a character (byte/half word/word) to the SPI buffer register.
 *
 * Note:            byte/hword/word accesses will perform correctly.
 *
 * Example:         SpiChnWriteC(SPI_CHANNEL1, 0x1b);       // send an ESC character
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnWriteC( SpiChannel chn, unsigned int data )
{
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF  
    
    *spi_buf = data;
}

/*********************************************************************
 * Function:        void SpiChnPutC(SpiChannel chn, unsigned int data)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to check
 *                  data    - the data to be written to the port
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This routine writes a single byte/half word/word to the SPI bus.
 *                  It waits for TX buffer empty, so that it doesn't overwrite the previous untransmitted data.
 *
 * Note:            byte/hword/word accesses will perform correctly.
 *
 * Example:         SpiChnPutC(SPI_CHANNEL1, 0x1b);     // send an ESC character
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnPutC( SpiChannel chn, unsigned int data )
{
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF 
    
    while(!_SpiIsTxAvlbl(chn));         // wait tx buff not full
    *spi_buf = data;                    // write data to the buffer    
}

/*********************************************************************
 * Function:        void SpiChnPutS(SpiChannel chn, unsigned int* pBuff, unsigned int nChars)
 *
 * PreCondition:    None
 *
 * Input:           chn     - the SPI channel
 *                  pBuff   - address of buffer storing the data to be transmitted.
 *                  nChars  - number of characters to be transmitted

 * Output:          None

 * Side Effects:    None

 * Overview:        This function writes the specified number of 8/16/32 bit characters
 *                  from the specified buffer.
 *                  It waits for Tx buffer empty so the characters are not overwritten.

 * Note:            pBuff is considered to be 8/16/32 bits data pointer, according to the
 *                  current SPI mode!
 *
 * Example:         SpiChnPutS(SPI_CHANNEL1, myBuff, 100);
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnPutS(SpiChannel chn, unsigned int* pBuff, unsigned int nChars)
{
	unsigned int    conBits;
	unsigned char   *pBuff8     = (unsigned char*)pBuff;
	unsigned short  *pBuff16    = (unsigned short*)pBuff;

    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF     
    
	conBits = *spi_con;

	while(nChars--)
	{
		while(!_SpiIsTxAvlbl(chn));                 /* wait until there's room in the buffer */
		if(conBits & _SPIxCON_MASK_(MODE32_MASK))
		{
            *spi_buf = *pBuff++;                    // 32 bits                      
		}
		else if(conBits & _SPIxCON_MASK_(MODE16_MASK))
		{
			*spi_buf = *pBuff16++;                  // 16 bits
		}
		else
		{
			*spi_buf = *pBuff8++;                   // 8 bits
		}
    }       
}

/*********************************************************************
 * Function:        int SpiChnGetRov(SpiChannel chn, int clear)
 *
 * PreCondition:    None
 *
 * Input:           chn         - the channel to check
 *                  clear       - if TRUE, the overflow condition has to be cleared, if present
 *
 * Output:          TRUE        - if overflow
 *                  FALSE       otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function reads the SPI channel overflow condition (SPIROV bit)
 *                  and clears it, if required.
 *
 * Note:            None
 *
 * Example:         int isOvfl=SpiChnGetRov(SPI_CHANNEL1, FALSE);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnGetRov(SpiChannel chn, int clear)
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT   
    
	if(*spi_stat * _SPIxSTAT_MASK_(SPIROV_MASK))
	{
		if(clear)
		{
            spi_stat++;
			*spi_stat = _SPIxSTAT_MASK_(SPIROV_MASK);
		}	
		return 1;
	}
	
	return 0;    
}

/*********************************************************************
 * Function:        int SpiChnIsBusy(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the channel to check
 *
 * Output:          TRUE  - if channel is busy with a transaction
 *                  FALSE - otherwise
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the SPI channel busy condition (SPIBUSY).
 *                  Whenever there is an ongoing transaction, the SPIBUSY status bit will be set.
 *
 * Note:            None
 *
 * Example:         int isBusy=SpiChnIsBusy(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
SpiChnIsBusy(SpiChannel chn)
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT   

    return ((*spi_stat & _SPIxSTAT_MASK_(SPIBUSY_MASK)) != 0);
}

/*********************************************************************
 * Function:        int SpiChnGetStatus(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the channel to check
 *
 * Output:          the current value of the SPI status
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the complete SPI channel status in one single call.
 *
 * Note:            None
 *
 * Example:         SpiStatusFlags chnStat=SpiChnGetStatus(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ SpiStatusFlags __attribute__((always_inline)) 
SpiChnGetStatus( SpiChannel chn )
{
    volatile UINT *spi_stat     = (volatile UINT *)(0xBF821010 + (0x200*((UINT)chn)));     //SPIxSTAT      
    
    return (SpiStatusFlags)(*spi_stat);
}

/*********************************************************************
 * Function:        volatile void* SpiChnBuffer(SpiChannel chn)
 *
 * PreCondition:    None
 *
 * Input:           chn   - the required channel
 *
 * Output:          the address of the SPI buffer associated to the selected channel.
 *
 * Side Effects:    None
 *
 * Overview:        This function returns the address of the SPI channel buffer.
 *
 * Note:            The same address is valid for both read and write operations.
 *
 *                  The function is useful when the corresponding SPI channel
 *                  has to be used as the source or destination of a DMA transfer.
 *
 * Example:         volatile unsigned short* spiBuffAdd=(unsigned short*)SpiChnBuffer(SPI_CHANNEL1);
 ********************************************************************/
extern __inline__ volatile void* __attribute__((always_inline)) 
SpiChnBuffer(SpiChannel chn)
{
    return (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF
}


/********************************************************************
 * Low Level SPI functions
 * Direct configuration and Clock/bitrate helpers.
 ********************************************************************/

// configuration flags
typedef enum
{
    // master configuration
    SPI_CONFIG_MSTEN =      _SPIxCON_MASK_(MSTEN_MASK), // set the Master mode
    SPI_CONFIG_SMP_END =    _SPIxCON_MASK_(SMP_MASK),   // Master Sample Phase for the input bit at the end of the data out time. Otherwise data is sampled in the middle.
    SPI_CONFIG_MSSEN =      _SPIxCON_MASK_(MSSEN_MASK), // enable the driving of the Slave Select (SS) output pin by the Master
    SPI_CONFIG_MSSEN_HIGH = _SPIxCON_MASK_(FRMPOL_MASK),// Master driven SS output active high. Otherwise low.

    // slave configuration
    SPI_CONFIG_SLVEN = 0,              // set the Slave mode
    SPI_CONFIG_SSEN  = _SPIxCON_MASK_(SSEN_MASK),  // enable the SS input pin.

    // clocking configuration
    SPI_CONFIG_CKP_HIGH = _SPIxCON_MASK_(CKP_MASK),   // set the clock polarity to (idle-high, active-low). Otherwise is (idle-low, active-high).
    SPI_CONFIG_CKE_REV  = _SPIxCON_MASK_(CKE_MASK),   // set the Clock Edge reversed: transmit from active to idle. Otherwise transmit when clock goes from idle to active

    // data characters configuration
    SPI_CONFIG_MODE8 =      0,              // set 8 bits/char
    SPI_CONFIG_MODE16 = _SPIxCON_MASK_(MODE16_MASK),    // set 16 bits/char
    SPI_CONFIG_MODE32 = _SPIxCON_MASK_(MODE32_MASK),    // set 32 bits/char

    // framed mode configuration
    SPI_CONFIG_FRMEN =   _SPIxCON_MASK_(FRMEN_MASK), // Enable the Framed SPI support. Otherwise the Framed SPI is disabled.
    SPI_CONFIG_FSP_IN =  _SPIxCON_MASK_(FRMSYNC_MASK),   // Frame Sync Pulse (FSP) direction set to input (Frame Slave).
                                        // Otherwise the FSP is output and the SPI channel operates as a Frame Master.
    SPI_CONFIG_FSP_HIGH = _SPIxCON_MASK_(FRMPOL_MASK),    // FSP polarity set active high. Otherwise the FSP is active low.
    SPI_CONFIG_FSP_CLK1 = _SPIxCON_MASK_(SPIFE_MASK), // Set the FSP to coincide with the 1st bit clock.
                                  // Otherwise the FSP precedes the 1st bit clock
    SPI_CONFIG_FSP_WIDE = _SPIxCON_MASK_(FRMSYPW_MASK),   // set the FSP one character wide. Otherwise the FSP is one clock wide.

    SPI_CONFIG_FRM_CNT1 =  (0 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the number of characters per frame (Frame Counter) to 1 (default)
    SPI_CONFIG_FRM_CNT2 =  (1 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 2
    SPI_CONFIG_FRM_CNT4 =  (2 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 4
    SPI_CONFIG_FRM_CNT8 =  (3 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 8
    SPI_CONFIG_FRM_CNT16 = (4 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 16
    SPI_CONFIG_FRM_CNT32 = (5 << _SPIxCON_MASK_(FRMCNT_POSITION)), // set the Frame Counter to 32

    // enhanced buffer (FIFO) configuration
    SPI_CONFIG_ENHBUF =         _SPIxCON_MASK_(ENHBUF_MASK),    // enable the enhanced buffer mode

    SPI_CONFIG_TBE_NOT_FULL =   (3 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer not full (at least one slot empty)
    SPI_CONFIG_TBE_HALF_EMPTY = (2 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer >= 1/2 empty
    SPI_CONFIG_TBE_EMPTY =      (1 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when Tx buffer completely empty
    SPI_CONFIG_TBE_SR_EMPTY =   (0 << _SPIxCON_MASK_(STXISEL_POSITION)),    // Tx Buffer event issued when the last character is shifted out of the internal Shift Register
                                            // and the transmit is complete

    SPI_CONFIG_RBF_FULL =       (3 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is full
    SPI_CONFIG_RBF_HALF_FULL =  (2 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is >= 1/2 full
    SPI_CONFIG_RBF_NOT_EMPTY =  (1 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is not empty
    SPI_CONFIG_RBF_EMPTY =      (0 << _SPIxCON_MASK_(SRXISEL_POSITION)),    // Rx Buffer event issued when RX buffer is empty (the last character in the buffer is read).

    // general configuration
    SPI_CONFIG_DISSDO = _SPIxCON_MASK_(DISSDO_MASK), // disable the usage of the SDO pin by the SPI
    SPI_CONFIG_DISSDI = _SPIxCON_MASK_(DISSDI_MASK), // disable the usage of the SDI pin by the SPI
    SPI_CONFIG_SIDL =   _SPIxCON_MASK_(SIDL_MASK),   // enable the Halt in the CPU Idle mode. Otherwise the SPI will be still active when the CPU is in Idle mode.
    SPI_CONFIG_ON =     _SPIxCON_MASK_(ON_MASK),     // turn ON the SPI (not used in SpiChnOpen)
} SpiConfigFlags;    // configuration flags that can be used with SpiChnConfigure. Defined in the processor header file.

typedef enum {
    SPI_CONFIG2_SPISGNEXT = _SPIxCON2_MASK_(SPISGNEXT_MASK), // Sign Extend Read Data from the RX FIFO bit
    SPI_CONFIG2_FRMERREN  = _SPIxCON2_MASK_(FRMERREN_MASK),  // Enable Interrupt Events via FRMERR bit
    SPI_CONFIG2_SPIROVEN  = _SPIxCON2_MASK_(SPIROVEN_MASK),  // Enable Interrupt Events via SPIROV bit
    SPI_CONFIG2_SPITUREN  = _SPIxCON2_MASK_(SPITUREN_MASK),  // Enable Interrupt Events via SPITUR bit
    SPI_CONFIG2_IGNROV    = _SPIxCON2_MASK_(IGNROV_MASK),    // Ignore Receive Overflow bit (for Audio Data Transmissions):
    SPI_CONFIG2_IGNTUR    = _SPIxCON2_MASK_(IGNTUR_MASK),    // Ignore Transmit Underrun bit (for Audio Data Transmissions)
    SPI_CONFIG2_AUDEN     = _SPIxCON2_MASK_(AUDEN_MASK),     // Enable Audio CODEC Support bit
    SPI_CONFIG2_AUDMONO   = _SPIxCON2_MASK_(AUDMONO_MASK),   // Transmit monoaural, i.e. left channel = right channel
    SPI_CONFIG2_AUDMOD    = _SPIxCON2_MASK_(AUDMOD_MASK),    // Audio Protocol Mode bits
    SPI_CONFIG2_AUDMOD_DSP =
                          _SPIxCON2_MASK_(AUDMOD_MASK),    // Audio Protocol Mode bits = 11 => PCM/DSP mode
    SPI_CONFIG2_AUDMOD0   = _SPIxCON2_MASK_(AUDMOD0_MASK),   // Audio Protocol Mode bits, Bit 0
    SPI_CONFIG2_AUDMOD_LJ = _SPIxCON2_MASK_(AUDMOD0_MASK),   // Audio Protocol Mode bits, Bit 0 = 1 => Left Justified mode
    SPI_CONFIG2_AUDMOD1   = _SPIxCON2_MASK_(AUDMOD1_MASK),   // Audio Protocol Mode bits, Bit 1
    SPI_CONFIG2_AUDMOD_RJ = _SPIxCON2_MASK_(AUDMOD1_MASK),   // Audio Protocol Mode bits, Bit 1 = 1 => Right Justified mode
    SPI_CONFIG2_AUDMOD_I2S = 0x0,                            // Audio Protocol Mode bits = 0x0 => I2S mode
} SpiConfig2Flags;


/*********************************************************************
 * Function:        void SpiChnConfigure(SpiChannel chn, SpiConfigFlags config)
 *
 * PreCondition:    chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set
 *                  config - any of the values from SpiConfigFlags:
 *                             master slave configure: SPI_CONFIG_MSTEN, SPI_CONFIG_SLVEN, SPI_CONFIG_SSEN
 *                             clocking and character configuration: SPI_CONFIG_CKP, SPI_CONFIG_CKE, SPI_CONFIG_SMP_END, SPI_CONFIG_MODE8, SPI_CONFIG_MODE16, SPI_CONFIG_MODE32
 *                             framed mode configuration: SPI_CONFIG_SPIFE, SPI_CONFIG_FRMPOL, SPI_CONFIG_FRMSYNC, SPI_CONFIG_FRMEN
 *                             general configuration: SPI_CONFIG_DISSDO, SPI_CONFIG_SIDL, SPI_CONFIG_ON
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is an alternative to SpiChnOpen. The application can first configure and then turn ON the channel.
 *                  The function performs the configuration of the SPI channel according to the config input parameter.
 *
 * Note:            - The channel is NOT turned off by this function; It should be turned off before calling this function.
 *                  - The pending interrupts are NOT cleared or disabled.
 *                  - The function does NOT set the SPI pins as digital i/o pins.
 *                  - The SPI channel is configured but NOT turned ON. Use SpiChnEnable(chn, 1) to turn ON the channel.
 *                  - When selecting the number of bits per character, SPI_CONFIG_MODE32 has the highest priority.
 *                  If SPI_CONFIG_MODE32 is not set, then SPI_CONFIG_MODE16 selects the character width.
 *
 * Example:        SpiChnEnable(SPI_CHANNEL1, 0);
 *                 SpiChnConfigure(SPI_CHANNEL1, SPI_CONFIG_MSTEN|SPI_CONFIG_SMP_END|SPI_CONFIG_MODE32);
 *                 SpiChnEnable(SPI_CHANNEL1, 1);
 *                 will configure and then enable the SPI1.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnConfigure( SpiChannel chn, SpiConfigFlags config )
{
	unsigned int		dummyRd;
	unsigned int		configR;

    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat_clr = (volatile UINT *)(0xBF821014 + (0x200*((UINT)chn)));     //SPIxSTATCLR    
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF
    
	configR = config&(~ _SPIxCON_MASK_(ON_MASK));           // channel configuration. make sure we don't turn the channel on

	dummyRd = *spi_buf;                                     // clear the receive buffer
	*spi_stat_clr = _SPIxSTAT_MASK_(SPIROV_MASK);           // clear overflow
	*spi_con = configR;                                     // set the configuration word
}

/*********************************************************************
 * Function:        void SpiChnConfigureEx(SpiChannel chn, SpiConfigFlags config, SpiConfig2Flags config)
 *
 * PreCondition:    chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set
 *                  config - any of the values from SpiConfigFlags:
 *                             master slave configure: SPI_CONFIG_MSTEN, SPI_CONFIG_SLVEN, SPI_CONFIG_SSEN
 *                             clocking and character configuration: SPI_CONFIG_CKP, SPI_CONFIG_CKE, SPI_CONFIG_SMP_END, SPI_CONFIG_MODE8, SPI_CONFIG_MODE16, SPI_CONFIG_MODE32
 *                             framed mode configuration: SPI_CONFIG_SPIFE, SPI_CONFIG_FRMPOL, SPI_CONFIG_FRMSYNC, SPI_CONFIG_FRMEN
 *                             general configuration: SPI_CONFIG_DISSDO, SPI_CONFIG_SIDL, SPI_CONFIG_ON
 *                  config2 - any of the values from SpiConfig2Flags
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is an alternative to SpiChnOpen. The application can first configure and then turn ON the channel.
 *                  The function performs the configuration of the SPI channel according to the config input parameter.
 *
 * Note:            - The channel is NOT turned off by this function; It should be turned off before calling this function.
 *                  - The pending interrupts are NOT cleared or disabled.
 *                  - The function does NOT set the SPI pins as digital i/o pins.
 *                  - The SPI channel is configured but NOT turned ON. Use SpiChnEnable(chn, 1) to turn ON the channel.
 *                  - When selecting the number of bits per character, SPI_CONFIG_MODE32 has the highest priority.
 *                  If SPI_CONFIG_MODE32 is not set, then SPI_CONFIG_MODE16 selects the character width.
 *
 * Example:        SpiChnEnable(SPI_CHANNEL1, 0);
 *                 SpiChnConfigureEx(SPI_CHANNEL1, SPI_CONFIG_MSTEN|SPI_CONFIG_SMP_END|SPI_CONFIG_MODE32, SPI_CONFIG2_AUDEN|SPI_CONFIG2_AUDMOD_I2S);
 *                 SpiChnEnable(SPI_CHANNEL1, 1);
 *                 will configure and then enable the SPI1.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnConfigureEx( SpiChannel chn, SpiConfigFlags config, SpiConfig2Flags config2 )
{
    unsigned int            dummyRd;
    unsigned int            configR;

    volatile UINT *spi_con      = (volatile UINT *)(0xBF821000 + (0x200*((UINT)chn)));     //SPIxCON
    volatile UINT *spi_stat_clr = (volatile UINT *)(0xBF821014 + (0x200*((UINT)chn)));     //SPIxSTATCLR    
    volatile UINT *spi_buf      = (volatile UINT *)(0xBF821020 + (0x200*((UINT)chn)));     //SPIxBUF
    volatile UINT *spi_con2     = (volatile UINT *)(0xBF821040 + (0x200*((UINT)chn)));     //SPIxCON2
    
    configR = config&(~ _SPIxCON_MASK_(ON_MASK));           // channel configuration. make sure we don't turn the channel on
    dummyRd = *spi_buf;                                     // clear the receive buffer
    *spi_stat_clr = _SPIxSTAT_MASK_(SPIROV_MASK);           // clear overflow
    *spi_con2 = config2;
    *spi_con = configR;                                     // set the configuration word
}

/*********************************************************************
 * Function:        void SpiChnEnable(SpiChannel chn, int enable)
 *
 * PreCondition:    chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to enable/disable
 *                  enable - boolean to enable/disable the channel
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function enables or disables the SPI channel.
 *
 * Note:            - Before enabling the channel, proper configuration should be done.
 *
 * Example:        SpiChnConfigure(SPI_CHANNEL1, SPI_CONFIG_MSTEN|SPI_CONFIG_SMP_END|SPI_CONFIG_MODE32);
 *                 SpiChnEnable(SPI_CHANNEL1, 1);
 *                 will configure and enable the SPI1 channel.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnEnable( SpiChannel chn, int enable )
{
    volatile UINT *spi_con_clr  = (volatile UINT *)(0xBF821004 + (0x200*((UINT)chn)));     //SPIxCONCLR
    
	if(enable)
	{
        spi_con_clr++;
		*spi_con_clr = _SPIxCON_MASK_(ON_MASK);		// turn on
	}
	else
	{
		*spi_con_clr = _SPIxCON_MASK_(ON_MASK);		// turn off and reset
	}
}

/*********************************************************************
 * Function:        unsigned int SpiChnSetBitRate(SpiChannel chn, unsigned int srcClk, unsigned int spiClk)
 *
 * PreCondition:    srcClk/1024 <= spiClk <= srcClk/2;
 *                  chn        - a valid SPI channel number
 *
 * Input:           chn    - the channel to set the bitrate for
 *                  srcClk - the SPI module Source Clock, Hz
 *                  spiClk - the desired SPI bitrate frequency, Hz
 *
 * Output:          the actual selected bitrate, Hz
 *
 * Side Effects:    None
 *
 * Overview:        This function configures the SPI channel with a desired bitrate.
 *                  The SPI bitrate is given by: spiClk=srcClk/(2*(SPIBRG+1))
 *                  The proper SPIBRG value is calculated as SPIBRG=(srcClk/spiClk)/2-1.
 *
 * Note:            - The channel has to be first configured with a valid bitrate and then enabled.
 *                  The bitrate can be changed dynamically, when no transaction is in progress.
 *                  - The bitrate is irrelevant for the Slave operation mode since the clock is provided externally, by the Master.
 *                  - For PIC32MX the srcClk is the peripheral bus clock.
 *
 * Example:        SpiChnEnable(SPI_CHANNEL1, 0);
 *                 SpiChnConfigure(SPI_CHANNEL1, SPI_CONFIG_MSTEN|SPI_CONFIG_SMP_END|SPI_CONFIG_MODE32);
 *                 SpiChnSetBitRate(SPI_CHANNEL1, GetPBusFrequency(), 20000000);
 *                 SpiChnEnable(SPI_CHANNEL1, 1);
 *                 will configure the SPI1, set the bitrate to 20MHz.
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
SpiChnSetBitRate( SpiChannel chn, unsigned int srcClk, unsigned int spiClk )
{
	unsigned int	clkDiv  = srcClk/spiClk;
    volatile UINT *spi_brg  = (volatile UINT *)(0xBF821030 + (0x200*((UINT)chn)));     //SPIxBRG
 
    *spi_brg = clkDiv/2-1;
	return srcClk/clkDiv;
}

/*********************************************************************
 * Function:        void SpiChnSetBrg(SpiChannel chn, unsigned int brg)
 *
 * PreCondition:    None
 *
 * Input:           chn     - the channel to set
 *                  brg     - value for the brg register
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function updates the values for the SPI channel brg/prescalers.
 *
 * Note:            None
 *
 * Example:         SpiChnSetBrg(SPI_CHANNEL1, 0x12);
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
SpiChnSetBrg( SpiChannel chn, unsigned int brg )
{
    volatile UINT *spi_brg  = (volatile UINT *)(0xBF821030 + (0x200*((UINT)chn)));     //SPIxBRG  
    
    *spi_brg = brg;	// write back
}


/******************************************************************************
 * Function:        unsigned int SpiBrgVal(unsigned int srcClk, unsigned int spiClk)
 *
 * Description:     Calculates the BRG values needed for the SPI configuration
 *
 * PreCondition:    srcClk/1024 <= spiClk <= srcClk/2;
 *
 * Inputs:          srcClk:   - the source clock to the SPI module, Hz
 *                  spiClk:   - the desired SPI clock frequency, Hz
 *
 * Output:          The proper BRG value.
 *                  For PIC32MZ the srcClk is the PBCLK2 value.
 *
 * Example:         SpiChnSetBrg(SPI_CHANNEL1, SpiBrgVal(72000000, 9000000));
 *
 *****************************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
SpiBrgVal( unsigned int srcClk, unsigned int spiClk )
{
    return (srcClk / (2 * spiClk)) - 1;
}


#ifdef	__cplusplus
}
#endif

#endif	/* SPI_H */

