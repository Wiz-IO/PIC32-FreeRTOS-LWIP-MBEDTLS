/*
		FileName: uart.h
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

#ifndef UART_H
#define	UART_H

#include <xc.h>
#include <GenericTypeDefs.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Constants & Data Types
// *****************************************************************************
// *****************************************************************************
    
/* UART Interrupt defines */    
#define  UART_FAULT_INT_EN          (0x00000001)  /* SPI Fault Interrupt Enable     */
#define  UART_FAULT_INT_DIS         (0x00000000)  /* SPI Fault Interrupt Disable    */

#define  UART_RX_INT_EN             (0x00000002)  /* SPI Rx Interrupt Enable        */
#define  UART_RX_INT_DIS			(0x00000000)  /* SPI Rx Interrupt Disable       */    
 
#define  UART_TX_INT_EN             (0x00000004)  /* SPI Tx Interrupt Enable        */
#define  UART_TX_INT_DIS            (0x00000000)  /* SPI Tx Interrupt Disable       */      

// *****************************************************************************
/* UART Module

  Summary:
    UART modules supported.

  Description:
    This enumeration identifies the available UART modules.
*/

typedef enum
{
#if defined(_UART1)    
    // UART1 Module ID.
    UART1 = 0,
#endif   
#if defined(_UART2)
    // UART2 Module ID.
    UART2 = 1,
#endif   
#if defined(_UART3)
    // UART3 Module ID.
    UART3 = 2,
#endif   
#if defined(_UART4)
    // UART4 Module ID (not available if UART1 CTS/RTS used).
    UART4 = 3,
#endif   
#if defined(_UART5)
    // UART5 Module ID (not available if UART2 CTS/RTS used).
    UART5 = 4,
#endif   
#if defined(_UART6)
    // UART6 Module ID.
    UART6 = 5,
#endif   
    // Number of available UART modules.
    UART_NUMBER_OF_MODULES = 0
#if defined(_UART1)
                + 1
#endif
#if defined(_UART2)
                + 1
#endif   
#if defined(_UART3)
                + 1
#endif
#if defined(_UART4)
                + 1
#endif             
#if defined(_UART5)
                + 1
#endif
#if defined(_UART6)
                + 1
#endif                
} UART_MODULE;


// *****************************************************************************
/* UART Enable Modes

  Summary:
    Operating modes of UART.

  Description:
    This enumeration defines the supported modes in which the UART may be
    enabled or disbled.

  Remarks:
    Enabling the UART trasnmitter may cause an immediate UART TX interrupt
    request (if the UART TX interrupt is enabled), unless the transmit buffer
    has been pre-loaded with data.

    The caller should not rely on the specific numbers assigned to any of these
    values as they may change from one processor to the next.
*/

typedef enum
{
    // Disables UART module functionality, must be OR'd with UART_MODULE, UART_RX, or UART_TX.
    UART_DISABLE        /*DOM-IGNORE-BEGIN*/= 0x00/*DOM-IGNORE-END*/,

    // Enables UART module functionality, must be OR'd with UART_MODULE, UART_RX, or UART_TX.
    UART_ENABLE         /*DOM-IGNORE-BEGIN*/= 0x80/*DOM-IGNORE-END*/,


    // UART Module, receiver and transmitter functionality is not.
    // enabled or disabled
    UART_PERIPHERAL     /*DOM-IGNORE-BEGIN*/= 0x01/*DOM-IGNORE-END*/,

    // UART Module receiver.
    UART_RX             /*DOM-IGNORE-BEGIN*/= 0x02/*DOM-IGNORE-END*/,

    // UART Module transmitter.
    UART_TX             /*DOM-IGNORE-BEGIN*/= 0x04/*DOM-IGNORE-END*/


} UART_ENABLE_MODE;

// *****************************************************************************
/* UART Enable Helper Macro

  Summary:
    Macro for enabling module operating modes.

  Description:
    This macro creates the proper flags for enabling operating modes of the UART module.

  Example:
    <code>
    UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX));
    </code>

  Remarks:
    Enabling the UART trasnmitter may cause an immediate UART TX interrupt
    request (if the UART TX interrupt is enabled), unless the transmit buffer
    has been pre-loaded with data.
*/
#define UART_ENABLE_FLAGS(a)    /*DOM-IGNORE-BEGIN*/(UART_ENABLE | (a))/*DOM-IGNORE-END*/

// *****************************************************************************
/* UART Disable Helper Macro

  Summary:
    Macro for disabling module operating modes.

  Description:
    This macro creates the proper flags for disabling operating modes of the UART module.

  Example:
    <code>
    UARTEnable(UART1, UART_DISABLE_FLAGS(UART_TX));
    </code>

*/
#define UART_DISABLE_FLAGS(a)    /*DOM-IGNORE-BEGIN*/(UART_DISABLE | (a))/*DOM-IGNORE-END*/

// *****************************************************************************
/* UART Configuration Settings

  Summary:
    Supported configuration flags for the UART module.

  Description:
    This enumeration defines the various configuration options for the UART
    module.  These values can be OR'd together to create a configuration mask
    passed to the UARTConfigure routine.

  Remarks:
    Several of the configuration options are mutually exclusive:
    * Only one of the "ENABLE_PINS" modes can be used at a time
    * Only one of the "RTS_WHEN" modes can be used at a time
    * Only one of the "INTERRUPT_ON_TX" modes can be used at a time
    * Only one of the "INTERRUPT_ON_RX" modes can be used at a time

    The caller should not rely on the specific numbers assigned to any of these
    values as they may change from one processor ot the next.
*/

typedef enum
{
    // Enables high-speed range of the UART (see UARTSetBitRate).
    UART_ENABLE_HIGH_SPEED              /*DOM-IGNORE-BEGIN*/= 0x00000008/*DOM-IGNORE-END*/,

    // Inverts polarity of data interpretation the received (RX) pin.
    UART_INVERT_RECEIVE_POLARITY        /*DOM-IGNORE-BEGIN*/= 0x00000010/*DOM-IGNORE-END*/,

    // Enables UART TX-to-RX Loop-back mode.
    UART_ENABLE_LOOPBACK                /*DOM-IGNORE-BEGIN*/= 0x00000040/*DOM-IGNORE-END*/,

    // Enables Wake-up of the part when a start bit is received.
    UART_ENABLE_WAKE_ON_START           /*DOM-IGNORE-BEGIN*/= 0x00000080/*DOM-IGNORE-END*/,

    // Enable Bit-clock for external IrDA transceiver support (Note:  CTS and RTS
    // cannot be used in bit-clock/IrDA mode).
    UART_ENABLE_PINS_BIT_CLOCK          /*DOM-IGNORE-BEGIN*/= 0x00000300/*DOM-IGNORE-END*/,

    // Enable Request-To-Send and Clear-To-Send signals (Note: The bit-clock
    // cannot be used in CTS/RTS mode).
    UART_ENABLE_PINS_CTS_RTS            /*DOM-IGNORE-BEGIN*/= 0x00000200/*DOM-IGNORE-END*/,

    // Enable Request-To-send signal only (Note: The bit-clock and CTS cannot
    // be used in RTS-Only mode).
    UART_ENABLE_PINS_RTS                /*DOM-IGNORE-BEGIN*/= 0x00000100/*DOM-IGNORE-END*/,

    // Disables use of Clear-To-Send and Request-To-Send signals (Note: This is
    // the default mode and this parameter can be left out if it is desired).
    UART_ENABLE_PINS_TX_RX_ONLY         /*DOM-IGNORE-BEGIN*/= 0x00000000/*DOM-IGNORE-END*/,

    // If RTS is enabled, it is asserted (driven low) when the receive buffer
    // is not full (i.e., the UART is ready to receive data).  This is also known
    // as "RTS Flow-Control Mode".
    UART_RTS_WHEN_RX_NOT_FULL           /*DOM-IGNORE-BEGIN*/= 0x00000000/*DOM-IGNORE-END*/,

    // If RTS is enabled, it is asserted (driven low) when the transmit buffer
    // is not empty (i.e., when the UART has data ready to send).  This is also
    // known as "RTS Simplex Mode".
    UART_RTS_WHEN_TX_NOT_EMPTY          /*DOM-IGNORE-BEGIN*/= 0x00000800/*DOM-IGNORE-END*/,

    // Enable the IrDA encoder/decoder.
    UART_ENABLE_IRDA                    /*DOM-IGNORE-BEGIN*/= 0x00001000/*DOM-IGNORE-END*/,

    // Enables stopping of the UART operation to save power when the core has
    // been put in idle mode.
    UART_ENABLE_STOP_ON_IDLE            /*DOM-IGNORE-BEGIN*/= 0x00002000/*DOM-IGNORE-END*/,

    // Inverts the polarity of data sent on the transmit (TX) pin.
    UART_INVERT_TRANSMIT_POLARITY       /*DOM-IGNORE-BEGIN*/= 0x20000000/*DOM-IGNORE-END*/,

    // Enables support for IEEE-485 protocol (equivalent the following OR'd
    // together: UART_RTS_WHEN_TX_NOT_EMPTY | UART_ENABLE_PINS_RTS )
    // Note:  The address must still be set using UARTEnableAddressDetect
    // to support IEEE-485 protocol.
    UART_SUPPORT_IEEE_485               /*DOM-IGNORE-BEGIN*/= 0x00000900/*DOM-IGNORE-END*/

} UART_CONFIGURATION;


// *****************************************************************************
/* UART FIFO Modes

  Summary:
    Supported FIFO modes for the UART module.

  Description:
    This enumeration defines supported FIFO modes that determine when the Tx
    and Rx interrupts will occur.

  Remarks:
    These modes consist of two sets of mutially exclusive modes:
    * Only one of the "INTERRUPT_ON_TX" modes can be used at a time
    * Only one of the "INTERRUPT_ON_RX" modes can be used at a time

    The caller should not rely on the specific numbers assigned to any of these
    values as they may change from one processor ot the next.

*/

typedef enum
{
    // If enabled, the TX interrupt will occur when the TX buffer is empty.
    UART_INTERRUPT_ON_TX_BUFFER_EMPTY   /*DOM-IGNORE-BEGIN*/= 0x8000/*DOM-IGNORE-END*/,

    // If enabled, the TX interrupt will occur when all data has been transmitted.
    UART_INTERRUPT_ON_TX_DONE           /*DOM-IGNORE-BEGIN*/= 0x4000/*DOM-IGNORE-END*/,

    // If enabled, the TX interrupt will occur whenever the TX buffer is not
    // full (i.e. there is space available for more data)  This is the default.
    UART_INTERRUPT_ON_TX_NOT_FULL       /*DOM-IGNORE-BEGIN*/= 0x0000/*DOM-IGNORE-END*/,

    // If enabled, the RX interrupt will occur whenever the RX buffer is
    // completely full.  (Not supported on PIC32MX5xx, PIC32MX6xx, or PIC32MX7xx.).
    UART_INTERRUPT_ON_RX_FULL           /*DOM-IGNORE-BEGIN*/= 0x00C0/*DOM-IGNORE-END*/,

    // If enabled, the RX interrupt will occur whenever the RX buffer is 3/4
    // (three-quarter) full.
    UART_INTERRUPT_ON_RX_3_QUARTER_FULL /*DOM-IGNORE-BEGIN*/= 0x0080/*DOM-IGNORE-END*/,

    // If enabled, the RX interrupt will occur wheneer the RX buffer is half
    // full.  (Not supported on PIC32X3xx or PIC32MX4xx.).
    UART_INTERRUPT_ON_RX_HALF_FULL      /*DOM-IGNORE-BEGIN*/= 0x0040/*DOM-IGNORE-END*/,

    // If enabled, the RX interrupt will occur whenever the RX buffer has any
    // data.
    UART_INTERRUPT_ON_RX_NOT_EMPTY      /*DOM-IGNORE-BEGIN*/= 0x0000/*DOM-IGNORE-END*/

} UART_FIFO_MODE;


// *****************************************************************************
/* UART Line Control Mode

  Summary:
    UART line control mode.

  Description:
    This data type defines the supported line control modes for the UART.

  Remarks:
    Some of the line-control options are mutually exclusive:
    * Only one of the "DATA_SIZE" options can be used at a time
    * Only one of the "PARITY" options can be used at a time
    * Only one of the "STOP_BITS" options can be used at a time

    The caller should not rely on the specific numbers assigned to any of these
    values as they may change from one processor ot the next.
*/

typedef enum
{
    // Sets the data transfer size to 8-bits per frame.
    UART_DATA_SIZE_8_BITS   /*DOM-IGNORE-BEGIN*/= 0x0000/*DOM-IGNORE-END*/,

    // Sets the data transfer size to 9-bits per frame.
    UART_DATA_SIZE_9_BITS   /*DOM-IGNORE-BEGIN*/= 0x0006/*DOM-IGNORE-END*/,

    // Enables parity bit generation for odd parity.
    UART_PARITY_ODD         /*DOM-IGNORE-BEGIN*/= 0x0004/*DOM-IGNORE-END*/,

    // Enables parity bit generation for even parity.
    UART_PARITY_EVEN        /*DOM-IGNORE-BEGIN*/= 0x0002/*DOM-IGNORE-END*/,

    // Disables parity bit generation.
    UART_PARITY_NONE        /*DOM-IGNORE-BEGIN*/= 0x0000/*DOM-IGNORE-END*/,

    // Enables generation of 2 stop bits per frame.
    UART_STOP_BITS_2        /*DOM-IGNORE-BEGIN*/= 0x0001/*DOM-IGNORE-END*/,

    // Enables generation of 1 stop bit per frame (default).
    UART_STOP_BITS_1        /*DOM-IGNORE-BEGIN*/= 0x0000/*DOM-IGNORE-END*/

} UART_LINE_CONTROL_MODE;


// *****************************************************************************
/* UART Line Status Flags

  Summary:
    UART line-status bitmask flags.

  Description:
    This enumeration defines the UART line-status bits.  These values are
    OR'd together to make up the bitmask returned by UARTGetLineStatus.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of these
    values as they may change from one processor ot the next.
*/

typedef enum
{
    // The transmitter is able to accept data to transmit.
    UART_TRANSMITTER_NOT_FULL   /*DOM-IGNORE-BEGIN*/= 0x00000200/*DOM-IGNORE-END*/,

    // The transmitter is empty (no data is available to transmit).
    UART_TRANSMITTER_EMPTY      /*DOM-IGNORE-BEGIN*/= 0x00000100/*DOM-IGNORE-END*/,

    // The receiver is currently idle.
    UART_RECEIVER_IDLE          /*DOM-IGNORE-BEGIN*/= 0x00000010/*DOM-IGNORE-END*/,

    // A received data parity error was detected.
    UART_PARITY_ERROR           /*DOM-IGNORE-BEGIN*/= 0x00000008/*DOM-IGNORE-END*/,

    // Data was received that violated the framing protocol (the data word did
    // not start or stop at the appropriate place).  Note:  A break condition
    // will always indicate a framing error.
    UART_FRAMING_ERROR          /*DOM-IGNORE-BEGIN*/= 0x00000004/*DOM-IGNORE-END*/,

    // The UART has received more data than it can buffer.  Data has been lost.
    UART_OVERRUN_ERROR          /*DOM-IGNORE-BEGIN*/= 0x00000002/*DOM-IGNORE-END*/,

    // UART data has been received and is avaiable in the FIFO.
    UART_DATA_READY             /*DOM-IGNORE-BEGIN*/= 0x00000001/*DOM-IGNORE-END*/

} UART_LINE_STATUS;

#define UART_LINE_STATUS_MASK   (UART_TRANSMITTER_NOT_FULL | UART_TRANSMITTER_EMPTY |\
                                UART_RECEIVER_IDLE | UART_PARITY_ERROR | UART_FRAMING_ERROR |\
                                UART_OVERRUN_ERROR | UART_DATA_READY)


// *****************************************************************************
/* UART Data

  Summary:
    UART data.

  Description:
    This data type defines the supported data sizes for the UART.
*/

typedef union
{
    // 8-bit data
    struct
    {
        UINT16  data8bit    : 8;
    };

    // 9-bit data
    struct
    {
        UINT16  data9bit    : 9;
    };

    UINT16 __data;
} UART_DATA;


// *****************************************************************************
/* Interrupt Muli-Channel Converter

  Summary:
    Interrupt muli-channel converter definitions.

  Description:
    These definitions can be used to convert a channel into the correct INT_SOURCE value.

    These macros can be used by
      void INTClearFlag(INT_SOURCE source)
      void INTSetFlag(INT_SOURCE source)
      unsigned int INTGetFlag(INT_SOURCE source)
      void INTEnable(INT_SOURCE source, INT_EN_DIS enable)
      unsigned int INTGetEnable(INT_SOURCE source)


*/
// UART Interrupt Channel.
extern inline INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_UART( UART_MODULE chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_src = INT_SOURCE_USART_1_ERROR;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_src = INT_SOURCE_USART_2_ERROR;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_src = INT_SOURCE_USART_3_ERROR;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_src = INT_SOURCE_USART_4_ERROR;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_src = INT_SOURCE_USART_5_ERROR;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_src = INT_SOURCE_USART_6_ERROR;
            break;
#endif                     
    }
    return ret_src;
}

// UART Error Interrupt Channel.
extern inline INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_UART_ERROR( UART_MODULE chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_src = INT_SOURCE_USART_1_ERROR;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_src = INT_SOURCE_USART_2_ERROR;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_src = INT_SOURCE_USART_3_ERROR;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_src = INT_SOURCE_USART_4_ERROR;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_src = INT_SOURCE_USART_5_ERROR;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_src = INT_SOURCE_USART_6_ERROR;
            break;
#endif                     
    }
    return ret_src;
}

// UART Receive Interrupt Channel.
extern inline INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_UART_RX( UART_MODULE chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_src = INT_SOURCE_USART_1_RECEIVE;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_src = INT_SOURCE_USART_2_RECEIVE;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_src = INT_SOURCE_USART_3_RECEIVE;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_src = INT_SOURCE_USART_4_RECEIVE;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_src = INT_SOURCE_USART_5_RECEIVE;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_src = INT_SOURCE_USART_6_RECEIVE;
            break;
#endif                     
    }
    return ret_src;
}

// UART Transmit Interrupt Channel.
extern inline INT_SOURCE __attribute__((always_inline)) 
INT_SOURCE_UART_TX( UART_MODULE chn )
{
INT_SOURCE ret_src = INT_SOURCE_NOSRC;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_src = INT_SOURCE_USART_1_TRANSMIT;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_src = INT_SOURCE_USART_2_TRANSMIT;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_src = INT_SOURCE_USART_3_TRANSMIT;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_src = INT_SOURCE_USART_4_TRANSMIT;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_src = INT_SOURCE_USART_5_TRANSMIT;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_src = INT_SOURCE_USART_6_TRANSMIT;
            break;
#endif
    }
    return ret_src;
}





// *****************************************************************************
/* Interrupt Muli-Channel Converter

  Summary:
    Interrupt Muli-Channel Converter definitions

  Description:
    These definitions can be used to convert a channel into the correct INT_VECTOR value.

    These macros can be used by:
      void INTSetVectorPriority(INT_VECTOR vector, INT_PRIORITY priority)
      INT_PRIORITY INTGetVectorPriority(INT_VECTOR vector)
      void INTSetVectorSubPriority(INT_VECTOR vector, INT_SUB_PRIORITY subPriority)
      INT_SUB_PRIORITY INTGetVectorSubPriority(INT_VECTOR vector)

  WARNING:
    Do not use with the __IPL(v,ipl) macro.

*/
// UART Interrupt Channel.
extern inline INT_VECTOR __attribute__((always_inline)) 
INT_VECTOR_UART( UART_MODULE chn )
{
INT_VECTOR ret_vect = INT_VECTOR_NOVECT;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_vect = INT_VECTOR_UART1_FAULT;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_vect = INT_VECTOR_UART2_FAULT;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_vect = INT_VECTOR_UART3_FAULT;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_vect = INT_VECTOR_UART4_FAULT;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_vect = INT_VECTOR_UART5_FAULT;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_vect = INT_VECTOR_UART6_FAULT;
            break;
#endif                     
    }
    return ret_vect;
}

// UART Error Interrupt Channel.
extern inline INT_VECTOR __attribute__((always_inline)) 
INT_VECTOR_UART_ERROR( UART_MODULE chn )
{
INT_VECTOR ret_vect = INT_VECTOR_NOVECT;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_vect = INT_VECTOR_UART1_FAULT;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_vect = INT_VECTOR_UART2_FAULT;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_vect = INT_VECTOR_UART3_FAULT;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_vect = INT_VECTOR_UART4_FAULT;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_vect = INT_VECTOR_UART5_FAULT;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_vect = INT_VECTOR_UART6_FAULT;
            break;
#endif                     
    }
    return ret_vect;
}

// UART Receive Interrupt Channel.
extern inline INT_VECTOR __attribute__((always_inline)) 
INT_VECTOR_UART_RX( UART_MODULE chn )
{
INT_VECTOR ret_vect = INT_VECTOR_NOVECT;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_vect = INT_VECTOR_UART1_RX;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_vect = INT_VECTOR_UART2_RX;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_vect = INT_VECTOR_UART3_RX;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_vect = INT_VECTOR_UART4_RX;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_vect = INT_VECTOR_UART5_RX;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_vect = INT_VECTOR_UART6_RX;
            break;
#endif                     
    }
    return ret_vect;
}

// UART Transmit Interrupt Channel.
extern inline INT_VECTOR __attribute__((always_inline)) 
INT_VECTOR_UART_TX( UART_MODULE chn )
{
INT_VECTOR ret_vect = INT_VECTOR_NOVECT;    

    switch( (unsigned char)chn )
    {
#ifdef _UART1       
        case 0:          
            ret_vect = INT_VECTOR_UART1_TX;            
            break;
#endif
#ifdef _UART2
        case 1:            
            ret_vect = INT_VECTOR_UART2_TX;           
            break;
#endif 
#ifdef _UART3
        case 2:
            ret_vect = INT_VECTOR_UART3_TX;
            break;
#endif                                       
#ifdef _UART4
        case 3:
            ret_vect = INT_VECTOR_UART4_TX;
            break;
#endif                           
#ifdef _UART5
        case 4:
            ret_vect = INT_VECTOR_UART5_TX;
            break;
#endif                   
#ifdef _UART6   
        case 5:
            ret_vect = INT_VECTOR_UART6_TX;
            break;
#endif                     
    }
    return ret_vect;
}


// *****************************************************************************
// *****************************************************************************
// Section: UART Peripheral Library Interface Routines
// *****************************************************************************
// *****************************************************************************


/*******************************************************************************
  Function:
    void UARTEnable( UART_MODULE id, UART_ENABLE_MODE mode )

  Summary:
    Enables or disables the given UART module in the desired mode.

  Description:
    This routine enables or disables the given UART module in the desired mode.

  Precondition:
    The UART module should be appropriately configured before being enabled.

  Parameters:
    id    - Identifies the desired UART module.

    mode  - Identifies the desired mode of UART operation.

  Returns:
    None

  Example:
    UARTEnable(UART1, UART_ENABLE_FLAGS(UART_PERIPHERAL | UART_RX | UART_TX));

  Remarks:
    Enabling UART transmissions will immediately cause a TX interrupt to
    indicate that the transmitter needs data, unless the transmitter FIFO/buffer
    was pre-loaded with data.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTEnable( UART_MODULE id, UART_ENABLE_MODE mode )
{
    volatile UINT   *uart_mode;
    volatile UINT   *uart_sta;

    if(mode & UART_ENABLE)
    {
        uart_mode = (volatile UINT *)(0xBF822008 + (0x200*((UINT)id)));     //UxMODESET
        uart_sta = (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));      //UxSTASET
    }else
    {
        uart_mode = (volatile UINT *)(0xBF822004 + (0x200*((UINT)id)));     //UxMODECLR
        uart_sta = (volatile UINT *)(0xBF822014 + (0x200*((UINT)id)));      //UxSTACLR
    }


    if(mode & UART_RX)
        *uart_sta = _U1STA_URXEN_MASK;

    if(mode & UART_TX)
        *uart_sta = _U1STA_UTXEN_MASK;

    if(mode & UART_PERIPHERAL)
        *uart_mode = _U1MODE_ON_MASK;
}

/*******************************************************************************
  Function:
    void UARTConfigure ( UART_MODULE id, UART_CONFIGURATION flags )

  Summary:
    UART module configuration routine.

  Description:
    This routine allows the caller to configure various features of the UART
    module for desired operation.

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module.

    flags   - Bit-wise OR of the desired module configuration settings.

  Returns:
    None

  Example:
    UARTConfigure(UART1, UART_RTS_WHEN_RX_NOT_FULL|UART_ENABLE_PINS_CTS_RTS);

  Remarks:
    Refer to the UART_CONFIGURATION enumerated data type for details on each
    configuration flag.  Note that the bitmask resulting from the bit-wise OR
    of these values will result in a value that is not explicitly defined in
    the enumeration.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTConfigure ( UART_MODULE id, UART_CONFIGURATION flags )
{
    volatile UINT   *uart_mode_set  =   (volatile UINT *)(0xBF822008 + (0x200*((UINT)id)));     //UxMODESET
    volatile UINT   *uart_mode_clr  =   (volatile UINT *)(0xBF822004 + (0x200*((UINT)id)));     //UxMODECLR
    volatile UINT   *uart_sta_set   =   (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));     //UxSTASET
    volatile UINT   *uart_sta_clr   =   (volatile UINT *)(0xBF822014 + (0x200*((UINT)id)));     //UxSTACLR

    *uart_mode_clr = UART_ENABLE_HIGH_SPEED | UART_INVERT_RECEIVE_POLARITY | UART_ENABLE_LOOPBACK |  UART_ENABLE_WAKE_ON_START | \
                         UART_ENABLE_PINS_BIT_CLOCK | UART_RTS_WHEN_TX_NOT_EMPTY | UART_ENABLE_IRDA | \
                         UART_SUPPORT_IEEE_485 | UART_ENABLE_STOP_ON_IDLE;

    *uart_sta_clr = (UART_INVERT_TRANSMIT_POLARITY) >> 16;

    *uart_mode_set = flags & 0x0000FFFF;

    *uart_sta_set = (flags >> 16) & 0x0000FFFF;
}

/*******************************************************************************
  Function:
    void UARTSetFifoMode ( UART_MODULE id, UART_FIFO_MODE mode )

  Summary:
    Controls UART module TX and RX FIFO operation.

  Description:
    This routine allows the caller to configure when interrupts occur relative
    to different "watermark" levels in the UART TX and RX FIFOs (i.e., how full
    or empty the FIFOs are).

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module.

    mode    - Bit-wise OR of the desired FIFO mode values.

  Returns:
    None

  Example:
    UARTSetFifoMode(UART1, UART_INTERRUPT_ON_TX_DONE|UART_INTERRUPT_ON_RX_NOT_EMPTY);

  Remarks:
    Refer to the UART_FIFO_MODE enumerated data type for details on each
    mode flag.  Note that the bitmask resulting from the bit-wise OR
    of these values will result in a value that is not explicitly defined in
    the enumeration.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSetFifoMode ( UART_MODULE id, UART_FIFO_MODE mode )
{
    volatile UINT   *uart_sta_set   =   (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));     //UxSTASET
    volatile UINT   *uart_sta_clr   =   (volatile UINT *)(0xBF822014 + (0x200*((UINT)id)));     //UxSTACLR

    *uart_sta_clr = UART_INTERRUPT_ON_TX_BUFFER_EMPTY | UART_INTERRUPT_ON_TX_DONE | UART_INTERRUPT_ON_RX_FULL;

    *uart_sta_set = mode;
}

/*******************************************************************************
  Function:
    UINT UARTSetDataRate( UART_MODULE id, UINT sourceClock, UINT dataRate )

  Summary:
    Routine to set the UART module's desired data data rate.

  Description:
    This routine allows the caller to set the desired data rate for the UART.

  Precondition:
    The source clock's frequency must be operating at the frequency passed in the
    "sourceClock" parameter.

  Parameters:
    id          - Identifies the desired UART module.

    sourceClock - Frequency (Hz) of the source clock being provided to the
                  UART module.

    dataRate     - Desired data rate (bits per second).

  Returns:
    Actual bit rate selected

  Example:
    #define PERIPHERAL_CLOCK    10000000
    #define DESIRED_DATA_RATE   19200

    UINT    actualDataRate;

    actualDataRate = UARTSetDataRate(UART1, PERIPHERAL_CLOCK, DESIRED_DATA_RATE);

  Remarks:
    Actual data rate selected may be slightly different than the data rate
    requested due to truncation error.

    Note:  In normal mode, the maximum possible data rate is sourceClock/16.  If
    the UART_ENABLE_HIGH_SPEED flag is sent to the UARTConfigure routine, then
    the maximum data rate is sourceClock/4. 
    In the code is included auto select of the BRGH bit.
  *****************************************************************************/
extern inline UINT __attribute__((always_inline)) 
UARTSetDataRate ( UART_MODULE id, UINT sourceClock, UINT dataRate )
{
    UINT brg_value;
    UINT brgValueLow = 0;
    UINT brgValueHigh = 0;
    volatile UINT   *uart_mode  =   (volatile UINT *)(0xBF822000 + (0x200*((UINT)id)));     //UxMODE
    volatile UINT   *uart_brg   =   (volatile UINT *)(0xBF822040 + (0x200*((UINT)id)));     //UxBRG
     
    brgValueLow  = ( (sourceClock/dataRate) >> 4 ) - 1;
    brgValueHigh = ( (sourceClock/dataRate) >> 2 ) - 1;    

    /* Check if the baud value can be set with high baud settings */
    if( (brgValueHigh >= 0) && (brgValueHigh <= UINT16_MAX) )
    {
        uart_mode +=2;                  //UxBRGSET
        *uart_mode = _U1MODE_BRGH_MASK;        
        brg_value = ( ((sourceClock >> 2) + (dataRate >> 1)) / dataRate ) - 1; 
        *uart_brg = brg_value;
    }
    /* Check if the baud value can be set with low baud settings */
    else if( (brgValueLow >= 0) && (brgValueLow <= UINT16_MAX) )
    {
        uart_mode++;                    //UxBRGCLR
        *uart_mode = _U1MODE_BRGH_MASK;        
        brg_value = ( ((sourceClock >> 4) + (dataRate >> 1)) / dataRate ) - 1;
        *uart_brg = brg_value;        
    }
    else
    {
        dataRate = 0;
    }    
    return dataRate;
}

/*******************************************************************************
  Function:
    UINT32 UARTGetDataRate ( UART_MODULE id, UINT32 sourceClock )

  Summary:
    Routine to get the UART module's current data data rate.

  Description:
    This routine allows the caller to get the current data rate for the UART module.

  Precondition:
    The source clock's frequency must be operating at the frequency passed in the
    "sourceClock" parameter.

  Parameters:
    id          - Identifies the desired UART module.

    sourceClock - Frequency (Hz) of the source clock being provided to the
                  UART module.

  Returns:
    The UART's current data rate (bits per second).

  Example:
    #define PERIPHERAL_CLOCK    10000000

    UINT32    currentDataRate;

    currentDataRate = UARTGetDataRate(UART1, PERIPHERAL_CLOCK);

  Remarks:
    The current (actual) data rate returned may be slightly different than bit
    rate requested due to truncation error.
  *****************************************************************************/
extern inline UINT32 __attribute__((always_inline)) 
UARTGetDataRate ( UART_MODULE id, UINT32 sourceClock )
{
    UINT32      dataRate;
    volatile UINT   *uart_mode  =   (volatile UINT *)(0xBF822000 + (0x200*((UINT)id)));     //UxMODE
    volatile UINT   *uart_brg   =   (volatile UINT *)(0xBF822040 + (0x200*((UINT)id)));     //UxBRG

    if((*uart_mode) & _U1MODE_BRGH_MASK)
    {
        sourceClock >>= 2;
    }else
    {
        sourceClock >>= 4;
    }

    dataRate = sourceClock / ( (*uart_brg) + 1 );

    return dataRate;
}

/*******************************************************************************
  Function:
        void UARTSetLineControl ( UART_MODULE id, UART_LINE_CONTROL_MODE mode )

  Summary:
    Routine to set the UART module's desired line control parameters.

  Description:
    This routine allows the caller to select the desired size of the UART data
    frame, the generation of parity and framing parameters (collectively
    referred to as the "line control" mode).

  Precondition:

  Parameters:
    id      - Identifies the desired UART module.

    mode    - This is a bit-wise OR of the desired line control mode flags.

  Returns:
    None

  Example:
    UARTSetLineControl(UART1, UART_DATA_SIZE_8_BITS|UART_PARITY_NONE|UART_STOP_BITS_1);

  Remarks:
    Refer to the UART_LINE_CONTROL_MODE enumerated data type for details on
    each mode flag.  Note that the bitmask resulting from the bit-wise OR
    of these values will result in a value that is not explicitly defined in
    the enumeration.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSetLineControl ( UART_MODULE id, UART_LINE_CONTROL_MODE mode )
{
    volatile UINT   *uart_mode_set  =   (volatile UINT *)(0xBF822008 + (0x200*((UINT)id)));     //UxMODESET
    volatile UINT   *uart_mode_clr  =   (volatile UINT *)(0xBF822004 + (0x200*((UINT)id)));     //UxMODECLR

    *uart_mode_clr = UART_DATA_SIZE_9_BITS | UART_STOP_BITS_2;
    *uart_mode_set = mode;
}

/*******************************************************************************
  Function:
    UART_LINE_STATUS UARTGetLineStatus ( UART_MODULE id )

  Summary:
    Provides current UART line status.

  Description:
    This routine allows the caller to get the current line status of the UART,
    indicating the current state of the transmitter and receiver buffers, and
    if any errors have occurred.

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    A bit-wise OR of the current line status flags.

  Example:
    UART_LINE_STATUS lineStatus;

    lineStatus = UARTGetLineStatus(UART1);
    if ( (UART_PARITY_ERROR|UART_FRAMING_ERROR|UART_OVERRUN_ERROR) & lineStatus )
    {
        // Handle receiver error
    }

  Remarks:
    Refer to the UART_LINE_STATUS enumerated data type for details on each
    status flag.

    The receiver line status flags are only valid when data has been received
    and for the data at the top of the RX FIFO.

    Note that the bitmask resulting from the bit-wise OR of these values will
    result in a value that is not explicitly defined in the enumeration.
  *****************************************************************************/
extern inline UART_LINE_STATUS __attribute__((always_inline)) 
UARTGetLineStatus ( UART_MODULE id )
{
    volatile UINT   *uart_sta   =   (volatile UINT *)(0xBF822010 + (0x200*((UINT)id)));     //UxSTA   
    
    return (UART_LINE_STATUS)((*uart_sta) & (UART_LINE_STATUS_MASK));
}

/*******************************************************************************
  Function:
    BOOL UARTTransmitterIsReady ( UART_MODULE id )

  Summary:
    Routine to detect if the transmitter is ready to accept data to transmit.

  Description:
    This routine determines if the transmitter is ready to accept more data to
    be transmitted.

  Precondition:
    The UART module should have been appropriately configured and enabled.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    Boolean identifying whether or not the transmitter is ready:
    * TRUE    - If the transmitter is ready to accept more data
    * FALSE   - If the transmitter is not ready to accept more data

  Example:
    unsigned char data;

    data = 'a';

    if (UARTTransmitterIsReady(UART1))
    {
        UARTSendDataByte(UART1, data);
    }

  Remarks:
  *****************************************************************************/
extern inline BOOL __attribute__ ((always_inline)) 
UARTTransmitterIsReady ( UART_MODULE id )
{
    volatile UINT   *uart_sta   =   (volatile UINT *)(0xBF822010 + (0x200*((UINT)id)));     //UxSTA    
    
    return (BOOL)(!((*uart_sta) & _U1STA_UTXBF_MASK));
}

/*******************************************************************************
  Function:
    void UARTSendDataByte ( UART_MODULE id, BYTE data )

  Summary:
    Routine to send a byte of data.

  Description:
    This routine allows the caller to send a byte of data.

  Precondition:
    The UART should have been appropriately configured.  The configuration must
    have been for 8-bit data (see UART_DATA_SIZE_8_BITS).  The transmitter must
    have been ready, although not necessarily enabled yet.

  Parameters:
    id      - Identifies the desired UART module.

    data    - Data byte to be sent.

  Returns:
    None

  Example:
    unsigned char data;

    data = 'a';

    if (UARTTransmitterIsReady(UART1))
    {
        UARTSendDataByte(UART1, data);
    }

  Remarks:
    This routine is optimized to send 8-bit (1-byte) data through the UART.
    This is an optimization of the "UARTSendData" routine for 8-bit (or less)
    data.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSendDataByte ( UART_MODULE id, BYTE data )
{
    volatile UINT   *uart_txreg   =   (volatile UINT *)(0xBF822020 + (0x200*((UINT)id)));     //UxTXREG  
    
    *uart_txreg = data;
}


/*******************************************************************************
  Function:
    void UARTSendData ( UART_MODULE id, UART_DATA data )

  Summary:
    Routine to send data through the UART.

  Description:
    This routine allows the caller to send data of any permitted size through
    the UART.

  Precondition:
    The UART module should have been appropriately configured.  The configuration must
    have been for desired data size.  The transmitter must have been ready,
    although not necessarily enabled yet.

  Parameters:
    id      - Identifies the desired UART module.

    data    - Data to be sent.

  Returns:
    None

  Example:
    UART_DATA data = 0x1ff; //can be 8-bit or 9-bit word, depending on how UART is configured

    if (UARTTransmitterIsReady(UART1))
    {
        UARTSendData(UART1, data);
    }

  Remarks:
    Size of the data word size depends on the current configuration (see
    UARTSetLineControl and UART_LINE_CONTROL_MODE).
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSendData( UART_MODULE id, UART_DATA data )
{
    volatile UINT   *uart_txreg   =   (volatile UINT *)(0xBF822020 + (0x200*((UINT)id)));     //UxTXREG 
    
    *uart_txreg = data.__data;
}

/*******************************************************************************
  Function:
    BOOL UARTTransmissionHasCompleted ( UART_MODULE id )

  Summary:
    Routine to detect if the UART module has finshed transmitting the most recent
    data.

  Description:
    This routine determines if the transmitter has finished sending all
    available data.

  Preconditions:
    The UART module should have been appropriately configured and enabled and data
    sent to the UART TX buffer.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    Boolean identifying if the transmission has completed:
    * TRUE    - If the transmitter has completed sending the data
    * FALSE   - If the transmitter is still busy sending the data

  Example:
    if (UARTTransmissionHasCompleted(UART1))
    {
        // Perform any tasks necessary when all data has been sent
    }

  Remarks:
  *****************************************************************************/
extern inline BOOL __attribute__((always_inline)) 
UARTTransmissionHasCompleted ( UART_MODULE id )
{
    volatile UINT   *uart_sta   =   (volatile UINT *)(0xBF822010 + (0x200*((UINT)id)));     //UxSTA    
    
    return (BOOL)(_U1STA_TRMT_MASK == ((*uart_sta) & _U1STA_TRMT_MASK));
}


/*******************************************************************************
  Function:
    BOOL UARTReceivedDataIsAvailable ( UART_MODULE id )

  Summary:
    Routine to detect if the receiver has data available.

  Description:
    This routine determines if the receiver has data available to be read.

  Precondition:
    The UART module must have been configured appropriately and enabled. A complete
    data frame must have been sent to the UART before it will return a TRUE.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    Boolean identifying whether or not data is available:
    * TRUE    - If the receiver has data available
    * FALSE   - If the receiver does not have data availble

  Example:
    UART_DATA data;

    if (UARTReceivedDataIsAvailable(UART1))
    {
        data = UARTGetData(UART1);
    }

  Remarks:
    This routine provides the same information as the UART_DATA_READY line
    status flag.
  *****************************************************************************/
extern inline BOOL __attribute__((always_inline)) 
UARTReceivedDataIsAvailable ( UART_MODULE id )
{
    volatile UINT   *uart_sta   =   (volatile UINT *)(0xBF822010 + (0x200*((UINT)id)));     //UxSTA   
    
    return (BOOL)(_U1STA_URXDA_MASK == ((*uart_sta) & _U1STA_URXDA_MASK));
}


/*******************************************************************************
  Function:
    BYTE UARTGetDataByte ( UART_MODULE id )

  Summary:
    Routine to get a byte of data received by the UART.

  Description:
    This routine allows the caller to read a byte of data received by the UART.

  Precondition:
    The UART module must have been appropriately configured, the configuration must
    have been for 8-bit data (see UART_DATA_SIZE_8_BITS), and the UART must have
    been enabled.  Also, a complete data frame must have been received by the UART.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    A byte of data received by the UART.

  Example:
    unsigned char data;

    if (UARTReceivedDataIsAvailable(UART1))
    {
        data = UARTGetDataByte(UART1);
    }

  Remarks:
    This routine is optimized for receiving 8-bit data through the UART.
  *****************************************************************************/
extern inline BYTE __attribute__((always_inline)) 
UARTGetDataByte ( UART_MODULE id )
{
    volatile UINT   *uart_rxreg   =   (volatile UINT *)(0xBF822030 + (0x200*((UINT)id)));     //UxRXREG     
    
    return (BYTE)(*uart_rxreg);
}


/*******************************************************************************
  Function:
    UART_DATA UARTGetData ( UART_MODULE id )

  Summary:
    Routine to get data received by the UART.

  Description:
    This routine allows the caller to read a data word received by the UART.

  Precondition:
    The module must have been appropriately configured, the UART module must have been
    enabled, and a complete data frame must have been received by the UART.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    Data received by the UART.

  Example:
    UART_DATA data;

    if (UARTReceivedDataIsAvailable(UART1))
    {
        data = UARTGetData(UART1);
    }

  Remarks:
    Size of the data word depends on the current configuration (see
    UARTSetLineControl).
  *****************************************************************************/
extern inline UART_DATA __attribute__((always_inline)) 
UARTGetData ( UART_MODULE id )
{
    UART_DATA data;
    volatile UINT   *uart_rxreg   =   (volatile UINT *)(0xBF822030 + (0x200*((UINT)id)));     //UxRXREG 
    
    data.__data = *uart_rxreg;

    return data;
}


/*******************************************************************************
  Function:
    void UARTSetAddress ( UART_MODULE id, BYTE address, BOOL watch )

  Summary:
    Routine to program the address for which the UART module may watch.

  Description:
    This routine programs the 8-bit address for which the module may watch.

  Precondition:
    None

  Parameters:
    id      - Identifies the desired UART module.

    address - 8-bit address for which the module will watch.

    watch   - Determines if the "address watch" mode will be enabled or disabled:
              * TRUE - Enable address watch mode
              * FALSE - Disable address watch mode

  Returns:
    None.

  Example:
    #define SLAVE_ADDRESS  0x42

    UARTSetAddress(UART1, SLAVE_ADDRESS, TRUE);

  Remarks:
    The module can be placed into a mode where it will ignore all data received
    until it identifies the programmed adress.  After the programmed address
    has been identified, it will begin receiving data normally.  This mode is
    particularly useful for supporting the IEEE-485 protocol.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSetAddress ( UART_MODULE id, BYTE address, BOOL watch )
{
    volatile UINT   *uart_sta_set   =   (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));     //UxSTASET
    volatile UINT   *uart_sta_clr   =   (volatile UINT *)(0xBF822014 + (0x200*((UINT)id)));     //UxSTACLR


    *uart_sta_clr = _U1STA_ADDR_MASK | _U1STA_ADM_EN_MASK;
    *uart_sta_set = ((UINT32)address) << _U1STA_ADDR_POSITION;

    if(watch)
        *uart_sta_set = _U1STA_ADM_EN_MASK;
}

/*******************************************************************************
  Function:
    void UARTWatchForAddress ( UART_MODULE id, BOOL watch )

  Summary:
    Routine to enable or disable recognition of the programmed address byte.

  Description:
    This routine can enable or disable the "address watch" mode.  In this mode,
    the UART module will ignore all data until it recognizes the programmed address.

  Precondition:
    UART should have already been enabled and set with watch address.

  Parameters:
    id      - Identifies the desired UART module.

    watch   - Determines if the "address watch" mode will be enabled or
              disabled.
              * TRUE - Enable address watch mode
              * FALSE - Disable address watch mode

  Returns:
    None.

  Example:
    #define SLAVE_ADDRESS 0x42

    // Set the address, but don't enable the watch until later,
    // UART continues to receive data normally
    UARTSetAddress(UART1, SLAVE_ADDRESS, FALSE);

    // ...

    // Now begin to ignore all UART traffic until we are addressed
    UARTWatchForAddress(UART1, TRUE);

  Remarks:
    The UART module can be placed into a mode where it will ignore all data received
    until it identifies the programmed address.  After the programmed address
    has been identified, it will begin receiving data normally.  This mode is
    particularly useful for supporting the IEEE-485 protocol.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTWatchForAddress ( UART_MODULE id, BOOL watch )
{
    volatile UINT   *uart_sta_set   =   (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));     //UxSTASET
    volatile UINT   *uart_sta_clr   =   (volatile UINT *)(0xBF822014 + (0x200*((UINT)id)));     //UxSTACLR

    if(watch)
        *uart_sta_set = _U1STA_ADM_EN_MASK;
    else
        *uart_sta_clr = _U1STA_ADM_EN_MASK;
}

/*******************************************************************************
  Function:
    void UARTSendBreak ( UART_MODULE id )

  Summary:
    Routine to send a break signal from the UART.

  Description:
    This routine allows the caller to send a break signal (12-bits of '0' data).

  Precondition:
    The UART should have been appropriately configured.  The transmitter should
    be idle, although not necessarily enabled yet.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    None

  Example:
    if (UARTTransmissionHasCompleted(UART1))
    {
        UARTSendBreak(UART1);
    }

  Remarks:
    After calling UARTSendBreak (and ensuring that the transmitter is enabled),
    data may be pre-loaded into the FIFO and it will be send immediately
    following the break signal.
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTSendBreak ( UART_MODULE id )
{
    volatile UINT   *uart_sta_set   =   (volatile UINT *)(0xBF822018 + (0x200*((UINT)id)));     //UxSTASET    
    
    *uart_sta_set = _U1STA_UTXBRK_MASK;
}

/*******************************************************************************
  Function:
    void UARTStartAutoDataRateDetect ( UART_MODULE id )

  Summary:
    Routine to automatically determine the data rate (bits-per-second) of an
    external transmitter to the UART.

  Description:
    This routine initiates the process of automatically determining the data
    rate (bits-per-second) of an external transmitter to the UART.

  Precondition:
    The UART should have been appropriately configured.  The transmitter should
    be idle, although not necessarily enabled yet.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    None

  Example:
    // See "PIC32 Family Reference Manual, Sect. 21 UART" for information on
    // methods to detect a Break.

    if (breakDetected && useAutoRateDetect)
    {
        UARTStartAutoDataRateDetect (UART1);
    }

  Remarks:
    The UART module begins measuring the data rate beginning at the next start
    bit.  The external transmitter should send an alternating pattern (0x55)
    for the byte to be measured for an effective rate detection.  To ensure
    an effective measurement sequence, this can be done immediately following
    a break reception. It is important that this UART module is not
    transmitting data while it is trying to detect RX baud rate, see the
    "PIC32 Family Reference Manual, Sect. 21 UART".
  *****************************************************************************/
extern inline void __attribute__((always_inline)) 
UARTStartAutoDataRateDetect ( UART_MODULE id )
{
    volatile UINT   *uart_mode_set  =   (volatile UINT *)(0xBF822008 + (0x200*((UINT)id)));     //UxMODESET    
    
    *uart_mode_set = _U1MODE_ABAUD_MASK;
}

/*******************************************************************************
  Function:
    BOOL UARTDataRateDetected ( UART_MODULE id )

  Summary:
    Routine to identify when automatic data rate detection has completed.

  Description:
    This routine checks to see if automatic data rate detection has completed.

  Precondition:
    Automatic rate detection should have been previously started.

  Parameters:
    id      - Identifies the desired UART module.

  Returns:
    * TRUE    - Indicates that automatic rate detection has completed.
    * FALSE   - Indicates that automatic rate detection is still ongoing.

  Example:
    #define PERIPHERAL_CLOCK    10000000

    UINT32 currentRate;

    if (UARTDataRateDetected(UART1))
    {
        currentRate = UARTGetDataRate(UART1, PERIPHERAL_CLOCK);
    }

  Remarks:
    This routine returns FALSE after automatic rate detection
    has been started but before rate is detectdd, it will return TRUE
    at any other time.
  *****************************************************************************/
extern inline BOOL __attribute__((always_inline)) 
UARTDataRateDetected ( UART_MODULE id )
{
    volatile UINT   *uart_mode  =   (volatile UINT *)(0xBF822000 + (0x200*((UINT)id)));     //UxMODE     
    
    return (BOOL)(!((*uart_mode) & _U1MODE_ABAUD_MASK));
}


#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

