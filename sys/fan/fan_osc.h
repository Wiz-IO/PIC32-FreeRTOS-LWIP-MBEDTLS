/*
		FileName: osc.h
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

#ifndef OSC_H
#define	OSC_H

#include <xc.h>
#include "fan_common.h"

#ifdef	__cplusplus
extern "C" {
#endif


// *****************************************************************************
/* Oscillator Peripheral Bus Clock Divisor Value Type

  Summary:
    Type of the oscillator PB Clock divisor value.

  Description:
    This macro defines the type of the oscillator PB Clock divisor value.

  Remarks:
    None
*/

//#define OSC_PB_CLOCK_DIV_TYPE						SFR_TYPE

typedef enum {
    OSC_PB_CLOCK_DIV_32 = (SFR_TYPE)0x0000001F,
    OSC_PB_CLOCK_DIV_31 = (SFR_TYPE)0x0000001E,
    OSC_PB_CLOCK_DIV_30 = (SFR_TYPE)0x0000001D,
    OSC_PB_CLOCK_DIV_29 = (SFR_TYPE)0x0000001C,    
    OSC_PB_CLOCK_DIV_28 = (SFR_TYPE)0x0000001B,
    OSC_PB_CLOCK_DIV_27 = (SFR_TYPE)0x0000001A,
    OSC_PB_CLOCK_DIV_26 = (SFR_TYPE)0x00000019,
    OSC_PB_CLOCK_DIV_25 = (SFR_TYPE)0x00000018,
    OSC_PB_CLOCK_DIV_24 = (SFR_TYPE)0x00000017,
    OSC_PB_CLOCK_DIV_23 = (SFR_TYPE)0x00000016,
    OSC_PB_CLOCK_DIV_22 = (SFR_TYPE)0x00000015,
    OSC_PB_CLOCK_DIV_21 = (SFR_TYPE)0x00000014,    
    OSC_PB_CLOCK_DIV_20 = (SFR_TYPE)0x00000013,
    OSC_PB_CLOCK_DIV_19 = (SFR_TYPE)0x00000012,
    OSC_PB_CLOCK_DIV_18 = (SFR_TYPE)0x00000011,
    OSC_PB_CLOCK_DIV_17 = (SFR_TYPE)0x00000010,
    OSC_PB_CLOCK_DIV_16 = (SFR_TYPE)0x0000000F,
    OSC_PB_CLOCK_DIV_15 = (SFR_TYPE)0x0000000E,
    OSC_PB_CLOCK_DIV_14 = (SFR_TYPE)0x0000000D,
    OSC_PB_CLOCK_DIV_13 = (SFR_TYPE)0x0000000C,    
    OSC_PB_CLOCK_DIV_12 = (SFR_TYPE)0x0000000B,
    OSC_PB_CLOCK_DIV_11 = (SFR_TYPE)0x0000000A,
    OSC_PB_CLOCK_DIV_10 = (SFR_TYPE)0x00000009,
    OSC_PB_CLOCK_DIV_9  = (SFR_TYPE)0x00000008,
    OSC_PB_CLOCK_DIV_8  = (SFR_TYPE)0x00000007,
    OSC_PB_CLOCK_DIV_7  = (SFR_TYPE)0x00000006,
    OSC_PB_CLOCK_DIV_6  = (SFR_TYPE)0x00000005,
    OSC_PB_CLOCK_DIV_5  = (SFR_TYPE)0x00000004,    
    OSC_PB_CLOCK_DIV_4  = (SFR_TYPE)0x00000003,
    OSC_PB_CLOCK_DIV_3  = (SFR_TYPE)0x00000002,
    OSC_PB_CLOCK_DIV_2  = (SFR_TYPE)0x00000001,
    OSC_PB_CLOCK_DIV_1  = (SFR_TYPE)0x00000000
} OSC_PB_CLOCK_DIV_TYPE;    
    

// *****************************************************************************
/* Oscillator Peripheral Bus count

  Summary:
    The number of Peripheral buses in available in the device.

  Description:
    This macro gives the number of Peripheral buses in available in the device.

  Remarks:
    None
*/

#define PERIPHERAL_BUSES_MAX						8    
    
    
typedef enum {
    OSC_ID_0 = 0,
    OSC_NUMBER_OF_MODULES = 1
} OSC_MODULE_ID;

typedef enum {
    OSC_ON_WAIT_IDLE = 0x00,
    OSC_ON_WAIT_SLEEP = 0x01
} OSC_OPERATION_ON_WAIT;

typedef enum {
    OSC_FRC_DIV_256 = 0x07,
    OSC_FRC_DIV_64 = 0x06,
    OSC_FRC_DIV_32 = 0x05,
    OSC_FRC_DIV_16 = 0x04,
    OSC_FRC_DIV_8 = 0x03,
    OSC_FRC_DIV_4 = 0x02,
    OSC_FRC_DIV_2 = 0x01,
    OSC_FRC_DIV_1 = 0x00
} OSC_FRC_DIV;

typedef enum {
    OSC_FRC = 0,
    OSC_FRC_WITH_PLL = 1,
    OSC_PRIMARY = 2,
    OSC_PRIMARY_WITH_PLL = 3,
    OSC_SECONDARY = 4,
    OSC_LPRC = 5,
    OSC_BFRC = 6,
    OSC_FRC_BY_FRCDIV = 7      
} OSC_SYS_TYPE;

typedef enum {
    OSC_REF_BASECLOCK_SYSCLK = 0x00,
    OSC_REF_BASECLOCK_PBCLK = 0x01,
    OSC_REF_BASECLOCK_PRIMARY = 0x02,
    OSC_REF_BASECLOCK_FRC = 0x03,
    OSC_REF_BASECLOCK_LPRC = 0x04,
    OSC_REF_BASECLOCK_SOSC = 0x05,
    OSC_REF_BASECLOCK_SYSPLLOUT = 0x07,
    OSC_REF_BASECLOCK_EXT = 0x08,
    OSC_REF_BASECLOCK_BFRC = 0x09
} OSC_REF_BASECLOCK;

typedef enum {
    OSC_USBCLOCK_SOURCE_NONE
} OSC_USBCLOCK_SOURCE;

typedef enum {
    OSC_SYSPLL_OUT_DIV_32 = 0x05,
    OSC_SYSPLL_OUT_DIV_16 = 0x04,
    OSC_SYSPLL_OUT_DIV_8 = 0x03,
    OSC_SYSPLL_OUT_DIV_4 = 0x02,
    OSC_SYSPLL_OUT_DIV_2 = 0x01
} OSC_SYSPLL_OUT_DIV;

typedef enum {
    OSC_UPLL_OUT_DIV_NONE
} OSC_UPLL_OUT_DIV;

typedef enum {
    OSC_BTPLL_OUT_DIV_NONE
} OSC_BTPLL_OUT_DIV;

typedef enum {
    OSC_PLL_SELECT_NONE
} OSC_PLL_SELECT;

typedef enum {
    OSC_PERIPHERAL_BUS_1 = 0x00,
    OSC_PERIPHERAL_BUS_2 = 0x01,
    OSC_PERIPHERAL_BUS_3 = 0x02,
    OSC_PERIPHERAL_BUS_4 = 0x03,
    OSC_PERIPHERAL_BUS_5 = 0x04,
    OSC_PERIPHERAL_BUS_7 = 0x06,
    OSC_PERIPHERAL_BUS_8 = 0x07
} OSC_PERIPHERAL_BUS;

typedef enum {
    OSC_REFERENCE_1 = 0x00,
    OSC_REFERENCE_2 = 0x01,
    OSC_REFERENCE_3 = 0x02,
    OSC_REFERENCE_4 = 0x03
} OSC_REFERENCE;

typedef enum {
    OSC_SYSPLL_IN_DIV_8 = 0x07,
    OSC_SYSPLL_IN_DIV_7 = 0x06,
    OSC_SYSPLL_IN_DIV_6 = 0x05,
    OSC_SYSPLL_IN_DIV_5 = 0x04,
    OSC_SYSPLL_IN_DIV_4 = 0x03,
    OSC_SYSPLL_IN_DIV_3 = 0x02,
    OSC_SYSPLL_IN_DIV_2 = 0x01,
    OSC_SYSPLL_IN_DIV_1 = 0x00
} OSC_SYSPLL_IN_DIV;

typedef enum {
    OSC_UPLL_IN_DIV_NONE
} OSC_UPLL_IN_DIV;

typedef enum {
    OSC_BTPLL_IN_DIV_NONE
} OSC_BTPLL_IN_DIV;

typedef enum {
    OSC_SYSPLL_FREQ_RANGE_34M_TO_68M = 0x05,
    OSC_SYSPLL_FREQ_RANGE_21M_TO_42M = 0x04,
    OSC_SYSPLL_FREQ_RANGE_13M_TO_26M = 0x03,
    OSC_SYSPLL_FREQ_RANGE_8M_TO_16M = 0x02,
    OSC_SYSPLL_FREQ_RANGE_5M_TO_10M = 0x01,
    OSC_SYSPLL_FREQ_RANGE_BYPASS = 0x00
} OSC_SYSPLL_FREQ_RANGE;

typedef enum {
    OSC_SYSPLL_IN_CLK_SOURCE_FRC = 0x1,
    OSC_SYSPLL_IN_CLK_SOURCE_PRIMARY = 0x0
} OSC_SYSPLL_IN_CLK_SOURCE;

typedef enum {
    OSC_UPLL_FREQ_RANGE_NONE
} OSC_UPLL_FREQ_RANGE;

typedef enum {
    OSC_BTPLL_FREQ_RANGE_NONE
} OSC_BTPLL_FREQ_RANGE;

typedef enum {
    OSC_BTPLL_IN_CLK_SOURCE_NONE
} OSC_BTPLL_IN_CLK_SOURCE;

typedef enum {
    OSC_SLEEP_TO_STARTUP_CLK_FRC = 0x1,
    OSC_SLEEP_TO_STARTUP_NO_ADDITIONAL_CLK = 0x0
} OSC_SLEEP_TO_STARTUP_CLK_TYPE;

typedef enum {
    OSC_CLOCK_FAST_RC = 0x0,
    OSC_CLOCK_PRIMARY_OSC = 0x2,
    OSC_CLOCK_SECONDARY_OSC = 0x4,
    OSC_CLOCK_LOW_POWER_RC = 0x5,
    OSC_CLOCK_SYSTEM_PLL = 0x1
} OSC_CLOCK_ID;

typedef enum {
    OSC_CLOCK_DIAG_NONE
} OSC_CLOCK_DIAG;

typedef enum {
    OSC_CLOCK_SLEW_DOWNWARD = 0x0000,
    OSC_CLOCK_SLEW_UPWARD = 0x0001
} OSC_CLOCK_SLEW_TYPE;    
    
    
    
//******************************************************************************
/* Function :  OSCSysClockSelect

  Summary:
    Implements Mz variant of OSCSysClockSelect 

  Description:
    This template implements the Mz variant of the OSCSysClockSelect function.
*/
extern inline void __attribute__((always_inline))
OSCSysClockSelect( OSC_SYS_TYPE new_OscType )
{

    /* If the selection is either of the two, then the system PLL
       also need to be controlled */
    if ( new_OscType == OSC_FRC_WITH_PLL )
    {
        SPLLCONSET = _SPLLCON_PLLICLK_MASK;
    }
    else if ( new_OscType == OSC_PRIMARY_WITH_PLL )
    {
        SPLLCONCLR = _SPLLCON_PLLICLK_MASK;

        /* Load the value to select the System PLL */
        new_OscType = OSC_FRC_WITH_PLL;
    }

    OSCCONbits.NOSC = new_OscType;

    /* Trigger the clock change */
    OSCCONSET = _OSCCON_OSWEN_MASK;

    Nop();
    Nop();
}
    
//******************************************************************************
/* Function :  OscFRCDivisorSelect_Default

  Summary:
    Implements Default variant of OscFRCDivisorSelect 

  Description:
    This template implements the Default variant of the OosFRCDivisorSelect function.
*/
extern inline void __attribute__((always_inline)) 
OscFRCDivisorSelect(OSC_FRC_DIV divisorFRC )
{
    
    OSCCONbits.FRCDIV = divisorFRC;
}

//******************************************************************************
/* Function :  OSCGetFRCDivisor

  Summary:
    Implements Default variant of OSCGetFRCDivisor

  Description:
    This template implements the Default variant of the OSCGetFRCDivisor function.
*/
extern inline uint16_t __attribute__((always_inline)) 
OSCGetFRCDivisor( void )
{
    uint16_t returnValue  = 0u;

    if ( OSCCONbits.FRCDIV != 7u )
    {
        returnValue = ( 1u << OSCCONbits.FRCDIV );
    }
    else
    {
        returnValue = 256u;
    }

    return returnValue;
}

//******************************************************************************
/* Function :  OSCPLLClockLock

  Summary:
    Implements Default variant of OSCPLLClockLock 

  Description:
    This template implements the Default variant of the OSCPLLClockLock function.
*/
extern inline void __attribute__((always_inline)) 
OSCPLLClockLock( void )
{
    OSCCONSET = _OSCCON_CLKLOCK_MASK;
}

//******************************************************************************
/* Function :  OSCPLLClockUnlock

  Summary:
    Implements Default variant of OSCPLLClockUnlock 

  Description:
    This template implements the Default variant of the OSCPLLClockUnlock function.
*/
extern inline void __attribute__((always_inline)) 
OSCPLLClockUnlock( void )
{
    OSCCONCLR = _OSCCON_CLKLOCK_MASK;
}

//******************************************************************************
/* Function :  OSCPLLClockIsLocked

  Summary:
    Implements Default variant of OSCPLLClockIsLocked 

  Description:
    This template implements the Default variant of the OSCPLLClockIsLocked function.
*/
extern inline BOOL __attribute__((always_inline)) 
OSCPLLClockIsLocked( void )
{
    return (BOOL)OSCCONbits.CLKLOCK;
}

//******************************************************************************
/* Function :  OSCAbortClockSwitching

  Summary:
    Implements Default variant of OSCAbortClockSwitching 

  Description:
    This template implements the Default variant of the OSCAbortClockSwitching function.
*/
extern inline void __attribute__((always_inline)) 
OSCAbortClockSwitching( void )
{
    OSCCONCLR = _OSCCON_OSWEN_MASK;
}

//******************************************************************************
/* Function :  OSCIsClockSwitchingComplete

  Summary:
    Implements Default variant of OSCIsClockSwitchingComplete 

  Description:
    This template implements the Default variant of the OSCIsClockSwitchingComplete function.
*/
extern inline BOOL __attribute__((always_inline)) 
OSCIsClockSwitchingComplete( void )
{
    return !( (BOOL)OSCCONbits.OSWEN );
}

//******************************************************************************
/* Function :  OSCSetSysPLLFrequencyRange

  Summary:
    Implements Default variant of OSCSetSysPLLFrequencyRange

  Description:
    This template implements the Default variant of the OSCSetSysPLLFrequencyRange function.
*/
extern inline void __attribute__((always_inline)) 
OSCSetSysPLLFrequencyRange( OSC_SYSPLL_FREQ_RANGE PLLFrequencyRange )
{
    
    SPLLCONbits.PLLRANGE = PLLFrequencyRange;
    Nop();
    Nop();
}

//******************************************************************************
/* Function :  OSCGetSysPLLFrequencyRange

  Summary:
    Implements Default variant of OSCGetSysPLLFrequencyRange

  Description:
    This template implements the Default variant of the OSCGetSysPLLFrequencyRange function.
*/
extern inline OSC_SYSPLL_FREQ_RANGE __attribute__((always_inline)) 
OSCGetSysPLLFrequencyRange( void )
{
     return (OSC_SYSPLL_FREQ_RANGE)SPLLCONbits.PLLRANGE;
}

//******************************************************************************
/* Function :  OSCPLLMultiplierSelect

  Summary:
    Implements PIC32_2 variant of OSCPLLMultiplierSelect 

  Description:
    This template implements the PIC32_2 variant of the OSCPLLMultiplierSelect function.
*/
extern inline BOOL __attribute__((always_inline)) 
OSCPLLMultiplierSelect( unsigned int pll_multiplier )
{
    
    if( pll_multiplier < 129u )
    {
        SPLLCONbits.PLLMULT = (pll_multiplier - 1u);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//******************************************************************************
/* Function :  OSCSysGetPLLMultiplier

  Summary:
    Implements PIC32_2 variant of OSCSysGetPLLMultiplier 

  Description:
    This template implements the PIC32_2 variant of the OSCSysGetPLLMultiplier function.
*/
extern inline unsigned int __attribute__((always_inline)) 
OSCSysGetPLLMultiplier( void )
{
    return (unsigned int)(SPLLCONbits.PLLMULT + 1u);
}

//******************************************************************************
/* Function :  OSCSetPLLOutputDivisor

  Summary:
    Implements PIC32_2 variant of OSCSetPLLOutputDivisor 

  Description:
    This template of the OSCSetPLLOutputDivisor function.
*/
extern inline void __attribute__((always_inline)) 
OSCSetPLLOutputDivisor( OSC_SYSPLL_OUT_DIV PLLOutDiv )
{
    SPLLCONbits.PLLODIV = PLLOutDiv;
}

//******************************************************************************
/* Function :  OSCGetSysPLLOutputDivisor

  Summary:
    Implements PIC32_2 variant of OSCGetSysPLLOutputDivisor 

  Description:
    This template of the OSCGetSysPLLOutputDivisor function.
*/
extern inline uint16_t __attribute__((always_inline)) 
OSCGetSysPLLOutputDivisor( void )
{
    uint16_t regValue, returnValue;

    regValue = SPLLCONbits.PLLODIV;

    if ( regValue == 0u )
    {
        returnValue = 2u;
    }
    else if( regValue > 5u )
    {
        returnValue = 32u;
    }
    else
    {
        returnValue = ( 0x01u << regValue );
    }

    return returnValue;
}

//******************************************************************************
/* Function :  OSCSetSysPLLInputDivisor

  Summary:
    Implements Default variant of OSCSetSysPLLInputDivisor

  Description:
    This template implements the Default variant of the OSCSetSysPLLInputDivisor function.
*/
extern inline void __attribute__((always_inline)) 
OSCSetSysPLLInputDivisor( OSC_SYSPLL_IN_DIV PLLInDiv )
{ 
    
    SPLLCONbits.PLLIDIV = PLLInDiv;
    Nop();
    Nop();
}

//******************************************************************************
/* Function :  OSCGetSysPLLInputDivisor

  Summary:
    Implements Default variant of OSCGetSysPLLInputDivisor

  Description:
    This template implements the Default variant of the OSCGetSysPLLInputDivisor function.
*/
extern inline OSC_SYSPLL_IN_DIV __attribute__((always_inline)) 
OSCGetSysPLLInputDivisor( void )
{
    return (OSC_SYSPLL_IN_DIV)SPLLCONbits.PLLIDIV;
}

/******************************************************************************
  Function:
    int8_t OSCClockSourceSwitch( SYS_CLK_SOURCE clockSource, ... )

  Summary:
    Initiates the clock switch for the system clock.

  Description:
    This function initiates the clock switch for the system clock.

  Remarks:
    None.
*/
extern inline int8_t __attribute__((always_inline)) 
OSCClockSourceSwitch( OSC_SYS_TYPE clockSource,
                        OSC_SYSPLL_FREQ_RANGE PLLFrequencyRange,
                        OSC_SYSPLL_IN_DIV PLLInDiv,
                        unsigned int PLLMULT_or_FRCDIV,
                        OSC_SYSPLL_OUT_DIV PLLODIV,
                        BOOL waitUntilComplete )
{
    uint32_t delay = 400;
    
    /* Check whether PLL and clock selections are locked */
    if( OSCPLLClockIsLocked() != TRUE )
    {
        /* Unlock before you switch */
        SystemUnlock();

        /* Special treatment if the source is a PLL based source. Do not change
        multipliers after switching. Switch to a FRC source first, then alter
        the multiplier values. */
        if( (clockSource == OSC_PRIMARY_WITH_PLL) || (clockSource == OSC_FRC_WITH_PLL) )
        {
            OSCSysClockSelect(OSC_FRC);

            /* Ensure that we are not on a PLL based source before switching */
            while(!OSCIsClockSwitchingComplete());
            
            /* Write the values before switching. Datasheet says so. */
            OSCSetSysPLLFrequencyRange(PLLFrequencyRange);
            OSCSetSysPLLInputDivisor(PLLInDiv);
            OSCPLLMultiplierSelect(PLLMULT_or_FRCDIV);
            OSCSetPLLOutputDivisor(PLLODIV);

            /* Switch to a PLL source */
            OSCSysClockSelect(clockSource);
       
            /* Device expects this delay. We are changing the System clock source here,
            On debugging sometimes the code just stops without this delay. Have to
            understand this further and fine tune this delay. */
            Nop();
            Nop();
            Nop();

            /* Ensure that we are source switching */
            while(!OSCIsClockSwitchingComplete()); 

            if( waitUntilComplete == TRUE )
            {
                while( delay-- );
            }
        }
        else
        {
            /* If the new oscillator is not a PLL source, the one we are running on may
            be. So switch first before setting the divisor */
            OSCSysClockSelect(clockSource);

            if( clockSource == OSC_FRC_BY_FRCDIV )
            {
                OscFRCDivisorSelect((OSC_FRC_DIV)PLLMULT_or_FRCDIV);
                
                /* Ensure that we are source switching */
                while(!OSCIsClockSwitchingComplete());                 
            }
        }   
        /* Lock it before going back */
        SystemLock();

        /* Return something which is not equal to '-1'. Let us return the clock source
        itself */
        return clockSource;
    }
    /* Unlock error */
    return(-1);
}

//******************************************************************************
/* Function :  OscPBClockDivisorSet_PIC32_2

  Summary:
    Implements PIC32_2 variant of OscPBClockDivisorSet

  Description:
    This template implements the PIC32_2 variant of the OscPBClockDivisorSet function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline))  
OscPBClockDivisorSet( OSC_PERIPHERAL_BUS peripheralBusNumber , OSC_PB_CLOCK_DIV_TYPE peripheralBusClkDiv )
{
    SFR_TYPE tmp_peripheralBusClkDiv = (SFR_TYPE)peripheralBusClkDiv;
    volatile uint32_t *reg = &PB1DIV + (peripheralBusNumber * 0x04u);
    
    *reg = ( *reg & (~_PB1DIV_PBDIV_MASK) ) | ( _PB1DIV_PBDIV_MASK & (tmp_peripheralBusClkDiv << _PB1DIV_PBDIV_POSITION) );
}

//******************************************************************************
/* Function :  OscPBOutputClockEnable_Default

  Summary:
    Implements Default variant of OscPBOutputClockEnable 

  Description:
    This template implements the Default variant of the OscPBOutputClockEnable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline))  
OscPBOutputClockEnable( OSC_PERIPHERAL_BUS peripheralBusNumber )
{
    volatile uint32_t *reg = &PB2DIV + ((peripheralBusNumber - 1u) * 0x04u);

    if (peripheralBusNumber == OSC_PERIPHERAL_BUS_1)
    {
        PLIB_ASSERT(false, "Peripheral Bus 1 is always enabled by default");
    }
    else
    {
        *(reg + 2u) = _PB2DIV_ON_MASK;
    }
}

//******************************************************************************
/* Function :  OscPBOutputClockDisable

  Summary:
    Implements Default variant of OscPBOutputClockDisable 

  Description:
    This template implements the Default variant of the OscPBOutputClockDisable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
OSCPBOutputClockDisable( OSC_PERIPHERAL_BUS peripheralBusNumber )
{
    volatile uint32_t *reg = &PB2DIV + ((peripheralBusNumber - 1u) * 0x04u);

    if (peripheralBusNumber == OSC_PERIPHERAL_BUS_1)
    {
        PLIB_ASSERT(false, "Peripheral Bus 1 can not be disabled");
    }
    else
    {
        *(reg + 1u) = _PB2DIV_ON_MASK;
    }  
}

//******************************************************************************
/* Function :  OscReferenceOscEnable

  Summary:
    Implements PIC32_2 variant of OscReferenceOscEnable 

  Description:
    This template implements the PIC32_2 variant of the OscReferenceOscEnable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline))  
OscReferenceOscEnable( OSC_REFERENCE referenceOsc )
{
    volatile uint32_t *reg = &REFO1CON + (referenceOsc * 0x08u) + 2u;

    *reg = _REFO1CON_ON_MASK;
}

//******************************************************************************
/* Function :  OscReferenceOscDisable

  Summary:
    Implements PIC32_2 variant of OscReferenceOscDisable 

  Description:
    This template implements the PIC32_2 variant of the OscReferenceOscDisable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
OscReferenceOscDisable( OSC_REFERENCE referenceOsc )
{
    volatile uint32_t *reg = &REFO1CON + (referenceOsc * 0x08u) + 1u;

    *reg = _REFO1CON_ON_MASK;
}

//******************************************************************************
/* Function :  OscReferenceOutputEnable_PIC32_2

  Summary:
    Implements PIC32_2 variant of OscReferenceOutputEnable 

  Description:
    This template implements the PIC32_2 variant of the OscReferenceOutputEnable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
OscReferenceOutputEnable( OSC_REFERENCE referenceOsc )
{
    volatile uint32_t *reg = &REFO1CON + (referenceOsc * 0x08u) + 2u;

    *reg = _REFO1CON_OE_MASK;
}

//******************************************************************************
/* Function :  OscReferenceOutputDisable_PIC32_2

  Summary:
    Implements PIC32_2 variant of OscReferenceOutputDisable 

  Description:
    This template implements the PIC32_2 variant of the OscReferenceOutputDisable function.
*/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
OscReferenceOutputDisable( OSC_REFERENCE referenceOsc )
{
    volatile uint32_t *reg = &REFO1CON + (referenceOsc * 0x08u) + 1u;

    *reg = _REFO1CON_OE_MASK;
}


#ifdef	__cplusplus
}
#endif

#endif	/* OSC_H */

