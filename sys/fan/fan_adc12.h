/*
		FileName: adc12.h
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

#ifndef ADC12_H
#define	ADC12_H

#include <xc.h>
#include <GenericTypeDefs.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

    
typedef enum
{
    ADC0 = 0,
    ADC1 = 1,
    ADC2 = 2,
    ADC3 = 3,
    ADC4 = 4,
    ReservADC5 = 5,
    ReservADC6 = 6,
    ADC7 = 7,
    ADC_NUM
}ADC12_MODULE;    
    
typedef enum {

    ADC12_AN0 = 0,
    ADC12_AN1 = 1,
    ADC12_AN2 = 2,
    ADC12_AN3 = 3,
    ADC12_AN4 = 4,
    ADC12_AN5 = 5,
    ADC12_AN6 = 6,
    ADC12_AN7 = 7,
    ADC12_AN8 = 8,
    ADC12_AN9 = 9,
    ADC12_AN10 = 10,
    ADC12_AN11 = 11,
    ADC12_AN12 = 12,
    ADC12_AN13 = 13,
    ADC12_AN14 = 14,
    ADC12_AN15 = 15,
    ADC12_AN16 = 16,
    ADC12_AN17 = 17,
    ADC12_AN18 = 18,
    ADC12_AN19 = 19,
    ADC12_AN20 = 20,
    ADC12_AN21 = 21,
    ADC12_AN22 = 22,
    ADC12_AN23 = 23,
    ADC12_AN24 = 24,
    ADC12_AN25 = 25,
    ADC12_AN26 = 26,
    ADC12_AN27 = 27,
    ADC12_AN28 = 28,
    ADC12_AN29 = 29,
    ADC12_AN30 = 30,
    ADC12_AN31 = 31,
    ADC12_AN32 = 32,
    ADC12_AN33 = 33,
    ADC12_AN34 = 34,
    ADC12_AN35 = 35,
    ADC12_AN36 = 36,
    ADC12_AN37 = 37,
    ADC12_AN38 = 38,
    ADC12_AN39 = 39,
    ADC12_AN40 = 40,
    ADC12_AN41 = 41,
    ADC12_AN42 = 42,
    ADC12_AN43 = 43,
    ADC12_AN44 = 44,       
    ADC12_AN45 = 45,
    ADC12_AN46 = 46,
    ADC12_AN47 = 47,
    ADC12_AN48 = 48,
    ADC12_AN49 = 49
} ADC12_AN_INPUT;   
    
typedef enum {
    ADC12_CHANNEL_0_DEF_INP_AN0 = 0,
    ADC12_CHANNEL_1_DEF_INP_AN1 = 4,
    ADC12_CHANNEL_2_DEF_INP_AN2 = 8,
    ADC12_CHANNEL_3_DEF_INP_AN3 = 12,
    ADC12_CHANNEL_4_DEF_INP_AN4 = 16,
    ADC12_CHANNEL_0_ALT_INP_AN45 = 1,
    ADC12_CHANNEL_1_ALT_INP_AN46 = 5,
    ADC12_CHANNEL_2_ALT_INP_AN47 = 9,
    ADC12_CHANNEL_3_ALT_INP_AN48 = 13,
    ADC12_CHANNEL_4_ALT_INP_AN49 = 17
} ADC12_ALT_CHANNEL_INP_SEL;

typedef enum {
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_0_BITS = 0,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_1_BITS = 1,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_2_BITS = 2,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_3_BITS = 3,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_4_BITS = 4,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_5_BITS = 5,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_6_BITS = 6,
    ADC12_INTERRUPT_BIT_SHIFT_LEFT_7_BITS = 7
} ADC12_INTERRUPT_BIT_SHIFT_LEFT;

typedef enum {
    ADC12_DATA_6BIT = 0,
    ADC12_DATA_8BIT = 1,
    ADC12_DATA_10BIT = 2,
    ADC12_DATA_12BIT = 3
} ADC12_DATA_RESOLUTION;    
    
typedef enum {
    ADC12_CHARGEPUMP_DISABLE = 0,
    ADC12_CHARGEPUMP_ENABLE = 1
} ADC12_CHARGEPUMP_MODE;    

typedef enum {
    ADC12_FAST_SYNC_SYSTEM_CLOCK_DISABLE = 0,
    ADC12_FAST_SYNC_SYSTEM_CLOCK_ENABLE = 1
} ADC12_FAST_SYNC_SYSTEM_CLOCK;

typedef enum {
    ADC12_FAST_SYNC_PERIPHERAL_CLOCK_DISABLE = 0,
    ADC12_FAST_SYNC_PERIPHERAL_CLOCK_ENABLE = 1
} ADC12_FAST_SYNC_PERIPHERAL_CLOCK;

typedef enum {
    ADC12_OUTPUT_DATA_FORMAT_INTEGER = 0,
    ADC12_OUTPUT_DATA_FORMAT_FRACTIONAL = 1
} ADC12_OUTPUT_DATA_FORMAT;

typedef enum {
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_1 = 0,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_2 = 1,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_3 = 2,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_4 = 3,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_5 = 4,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_6 = 5,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_7 = 6,
    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK_8 = 7
} ADC12_EARLY_INTERRUPT_PRIOR_CLOCK;

typedef enum {
    ADC12_CLOCK_SOURCE_PBCLK3   = 0,
    ADC12_CLOCK_SOURCE_SYSCLK   = 1,
    ADC12_CLOCK_SOURCE_RFCLK3   = 2,
    ADC12_CLOCK_SOURCE_FRC      = 3
} ADC12_CLOCK_SOURCE;

typedef enum {
    ADC12_VREF_AVDD_AVSS = 0,
    ADC12_VREF_EXTVREFP_AVSS = 1,
    ADC12_VREF_AVDD_EXTVREFN = 2,
    ADC12_VREF_EXTVREFP_EXTVREFN = 3
} ADC12_VREF_SOURCE;

typedef enum {
    ADC12_CHANNEL_UNSYNC_TRIGGER_UNSYNC_SAMPLING = 0,
    ADC12_CHANNEL_SYNC_SAMPLING = 1,
    ADC12_CHANNEL_SYNC_TRIGGER_UNSYNC_SAMPLING = 2
} ADC12_CHANNEL_TRIGGER_SAMPLING_SEL;

typedef enum {
    ADC12_INPUT_MODE_SINGLE_ENDED_UNSIGNED = 0,
    ADC12_INPUT_MODE_SINGLE_ENDED_SIGNED = 1,
    ADC12_INPUT_MODE_DIFFERENTIAL_UNSIGNED = 2,
    ADC12_INPUT_MODE_DIFFERENTIAL_SIGNED = 3
} ADC12_INPUT_MODE;

typedef enum {
    ADC12_WARMUP_CLOCK_16 = 0,
    ADC12_WARMUP_CLOCK_32 = 5,
    ADC12_WARMUP_CLOCK_64 = 6,
    ADC12_WARMUP_CLOCK_128 = 7,
    ADC12_WARMUP_CLOCK_256 = 8,
    ADC12_WARMUP_CLOCK_512 = 9,
    ADC12_WARMUP_CLOCK_1024 = 10,
    ADC12_WARMUP_CLOCK_2048 = 11,
    ADC12_WARMUP_CLOCK_4096 = 12,
    ADC12_WARMUP_CLOCK_8192 = 13,
    ADC12_WARMUP_CLOCK_16384 = 14,
    ADC12_WARMUP_CLOCK_32768 = 15
} ADC12_WARMUP_CLOCK;


//******************************************************************************
/* Function :  ADC12SelectAltChannelInput

  Summary:
    Implements Default variant of ADC12SelectAltChannelInput 

  Description:
    This template implements the Default variant of the ADC12SelectAltChannelInput function.
    Operation is not atomic.
*/   
extern __inline__ ADC12_MODULE __attribute__((always_inline)) 
ADC12GetChannel( ADC12_AN_INPUT analogInput )
{
    ADC12_MODULE channel;

    if( (ADC12_AN5 <= analogInput) && (ADC12_AN44 >= analogInput) )
    {
        channel = ADC7;
    }
    else if( (ADC12_AN0 == analogInput) || (ADC12_AN45 == analogInput) )
    {
       channel = ADC0; 
    }
    else if( (ADC12_AN1 == analogInput) || (ADC12_AN46 == analogInput) )
    {
       channel = ADC1; 
    }
    else if( (ADC12_AN2 == analogInput) || (ADC12_AN47 == analogInput) )
    {
       channel = ADC2; 
    }
    else if( (ADC12_AN3 == analogInput) || (ADC12_AN48 == analogInput) )
    {
       channel = ADC3; 
    }
    else if( (ADC12_AN4 == analogInput) || (ADC12_AN49 == analogInput) )
    {
       channel = ADC4; 
    }    
    
    return channel;
}

//******************************************************************************
/* Function :  ADC12SelectAltChannelInput

  Summary:
    Implements Default variant of ADC12SelectAltChannelInput 

  Description:
    This template implements the Default variant of the ADC12SelectAltChannelInput function.
    Operation is not atomic.
*/        
extern __inline__ BOOL __attribute__((always_inline)) 
ADC12SelectAltChannelInput( ADC12_MODULE channel, ADC12_ALT_CHANNEL_INP_SEL sel )
{
    
    if( (ReservADC5 == channel) || (ReservADC6 == channel) || (ADC_NUM <= channel) ) return FALSE;
    ADCTRGMODE &= ~(3 << (2 * channel)  <<16); 
    ADCTRGMODE |= (sel - 4 * channel) << (2 * channel)  << 16; 
    return TRUE;
}

/*********************************************************************
 * Function:        SetChanADC12(config)
 *
 * Description:     Configures the ADC MUX inputs
 *
 * PreCondition:    None
 *
 * Inputs:          Desired input configuration for muxes
 *                   An absent symbol is automatically taken as off or default value.
 *                          See below for available options for each input
 *
 * Output:          None
 *
 * Example:         SetChanADC12( ADC12_AN49 )
 *
 ********************************************************************/
extern __inline__ BOOL __attribute__((always_inline)) 
SetChanADC12( ADC12_AN_INPUT analogInput )
{
ADC12_MODULE channel;
ADC12_ALT_CHANNEL_INP_SEL sel;

    if(ADC12_AN49 < analogInput) return FALSE;
    if(ADC12_AN45 > analogInput) return TRUE;
    
    switch(analogInput)
    {
        case ADC12_AN45:
            channel = ADC0;
            sel = ADC12_CHANNEL_0_ALT_INP_AN45;
            break;
            
        case ADC12_AN46:
            channel = ADC1;
            sel = ADC12_CHANNEL_1_ALT_INP_AN46;
            break;
            
        case ADC12_AN47:
            channel = ADC2;
            sel = ADC12_CHANNEL_2_ALT_INP_AN47;
            break;
            
        case ADC12_AN48:
            channel = ADC3;
            sel = ADC12_CHANNEL_3_ALT_INP_AN48;
            break;
            
        case ADC12_AN49:
            channel = ADC4;
            sel = ADC12_CHANNEL_4_ALT_INP_AN49;
            break;
        default:
            return FALSE;
            break;
    }
    return ADC12SelectAltChannelInput(channel, sel );
}

//******************************************************************************
/* Function :  ADC12SelectAnalogInputMode

  Summary:
    Implements Default variant of ADC12SelectAnalogInputMode 

  Description:
    This template implements the Default variant of the ADC12SelectAnalogInputMode function.
    Operation is not atomic.
*/
extern __inline__ BOOL __attribute__((always_inline)) 
ADC12SelectAnalogInputMode( ADC12_AN_INPUT analogInput , ADC12_INPUT_MODE mode )
{
    UINT ainput;
    volatile UINT *adcmicon;

    if( (ADC12_AN49 < analogInput) || (ADC12_INPUT_MODE_DIFFERENTIAL_SIGNED < mode) ) return FALSE;
    
    /* see if we are using alternate inputs */
    if(ADC12_AN44 < analogInput)
    {
        analogInput -= 45;    
    }
    ainput = analogInput & 0x0F;
    adcmicon  = (volatile UINT *)(0xBF84B010 + (4*((UINT)analogInput / 16)));     //ADCIMCONx

    *adcmicon &= ~(3 << (ainput * 2));
    *adcmicon |= (mode << (ainput * 2));
    
    return TRUE;
}

//******************************************************************************
/* Function :  ADC12GetAnalogInputMode

  Summary:
    Implements Default variant of ADC12GetAnalogInputMode 

  Description:
    This template implements the Default variant of the ADC12GetAnalogInputMode function.
    Operation is atomic.
*/
extern __inline__ ADC12_INPUT_MODE __attribute__((always_inline)) 
ADC12GetAnalogInputMode( ADC12_AN_INPUT analogInput )
{
    UINT ainput;
    volatile UINT *adcmicon;

    /* see if we are using alternate inputs */
    if(ADC12_AN44 < analogInput)
    {
        analogInput -= 45;    
    }
    ainput = analogInput & 0x0F;
    adcmicon  = (volatile UINT *)(0xBF84B010 + (4*((UINT)analogInput / 16)));     //ADCIMCONx
    return (ADC12_INPUT_MODE)(((*adcmicon) >> (ainput * 2)) & 0x3);
}

//******************************************************************************
/* Function :  ADC12Setup

  Summary:
    Implements Default variant of ADC12Setup 

  Description:
    This template implements the Default variant of the ADC12Setup function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12Setup( ADC12_VREF_SOURCE voltageRefSelect , 
            ADC12_CHARGEPUMP_MODE chargePump , 
            ADC12_OUTPUT_DATA_FORMAT outputFormat , 
            BOOL stopInIdle , 
            ADC12_FAST_SYNC_SYSTEM_CLOCK sysClk , 
            ADC12_FAST_SYNC_PERIPHERAL_CLOCK periClk , 
            ADC12_INTERRUPT_BIT_SHIFT_LEFT intVectorShift , 
            uint16_t intVectorBase , 
            ADC12_CLOCK_SOURCE adcClockSource , 
            int8_t adcClockDivider , 
            ADC12_WARMUP_CLOCK warmUpClock )
{

    ADCCON1bits.AICPMPEN = chargePump;
    ADCCON1bits.IRQVS = intVectorShift;
    ADCCON1bits.FRACT = outputFormat;
    ADCCON1bits.SIDL = stopInIdle;
    ADCCON1bits.FSSCLKEN = sysClk;
    ADCCON1bits.FSPBCLKEN = periClk;

    ADCCON3bits.VREFSEL = voltageRefSelect;
    ADCCON3bits.ADCSEL = adcClockSource;
    ADCCON3bits.CONCLKDIV = adcClockDivider;

    ADCBASE = intVectorBase;
    ADCANCONbits.WKUPCLKCNT = warmUpClock;
}

//******************************************************************************
/* Function :  ADC12SetupChannel

  Summary:
    Implements Default variant of ADC12SetupChannel 

  Description:
    This template implements the Default variant of the ADC12SetupChannel function.
    Operation is not atomic.
*/
extern __inline__ BOOL __attribute__((always_inline)) 
ADC12SetupChannel(  ADC12_MODULE channel, 
                    ADC12_DATA_RESOLUTION res, 
                    uint8_t	channelClockDivider, 
                    uint16_t sampleTimeCount, 
                    ADC12_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk )
{
    uint32_t tempVal = 0;
    volatile UINT *adcxtime;                                                    //ADCxTIME
    
    if( (ReservADC5 == channel) || (ReservADC6 == channel) || (ADC_NUM <= channel) ) return FALSE;
    if( channel == ADC7 ) 
    {
        tempVal = ADCCON2;
        tempVal &= ~(0x0000007F | 0x03FF0000 | 0x00000700);
        tempVal |= (uint32_t)(channelClockDivider);
        tempVal |= (uint32_t)(sampleTimeCount << 16);
        tempVal |= (uint32_t)(earlyInterruptClk << 8);
        ADCCON2 = tempVal;
        ADCCON1bits.SELRES = res;
    } 
    else 
    {
        adcxtime  = (volatile UINT *)(0xBF84B0D4 + (4*(UINT)channel ));       //ADCxTIME
        tempVal = *adcxtime;
        tempVal &= ~(0x000003FF | 0x007F0000 | 0x1C0000000 | 0x03000000);
        tempVal |= (uint32_t)(sampleTimeCount);
        tempVal |= (uint32_t)(channelClockDivider << 16);
        tempVal |= (uint32_t)(earlyInterruptClk << 26);
        tempVal |= (uint32_t)(res << 24);
        *adcxtime = tempVal;
    }
    
    return TRUE;
}

//******************************************************************************
/* Function :  ADC12EnableChannelAnalogFeature

  Summary:
    Implements Default variant of ADC12EnableChannelAnalogFeature 

  Description:
    This template implements the Default variant of the ADC12EnableChannelAnalogFeature function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12EnableChannelAnalog( ADC12_MODULE channel )
{

    ADCANCON |= (1<<channel);
}

//******************************************************************************
/* Function :  ADC12DisableChannelAnalogFeature

  Summary:
    Implements Default variant of ADC12DisableChannelAnalogFeature 

  Description:
    This template implements the Default variant of the ADC12DisableChannelAnalogFeature function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12DisableChannelAnalog( ADC12_MODULE channel )
{

    ADCANCON &= ~(1<<channel);
}

//******************************************************************************
/* Function :  ADC12IsChannelReady

  Summary:
    Implements Default variant of ADC12IsChannelReady 

  Description:
    This template implements the Default variant of the ADC12IsChannelReady function.
    Operation is not atomic.
*/
extern __inline__ BOOL __attribute__((always_inline)) 
ADC12IsChannelReady( ADC12_MODULE channel )
{

    return (BOOL)(ADCANCON & (1<<(channel + 8)));
}

//******************************************************************************
/* Function :  ADC12EnableChannelIsReadyInterrupt

  Summary:
    Implements Default variant of ADC12EnableChannelIsReadyInterrupt 

  Description:
    This template implements the Default variant of the ADC12EnableChannelIsReadyInterrupt function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12EnableChannelIsReadyInterrupt( ADC12_MODULE channel )
{

    ADCANCON |= (1<<(channel + 16));
}

//******************************************************************************
/* Function :  ADCHS_ChannelIsReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelIsReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelIsReadyInterruptDisable function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12DisableChannelIsReadyInterrupt( ADC12_MODULE channel )
{

   ADCANCON &= ~(1<<(channel + 16));
}

//******************************************************************************
/* Function :  ADC12EnableChannelDigitalFeature

  Summary:
    Implements Default variant of ADC12EnableChannelDigitalFeature 

  Description:
    This template implements the Default variant of the ADC12EnableChannelDigitalFeature function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12EnableChannelDigital( ADC12_MODULE channel )
{

    ADCCON3 |= (1<<(channel + 16));
}

//******************************************************************************
/* Function :  ADC12DisableChannelDigitalFeature

  Summary:
    Implements Default variant of ADC12DisableChannelDigitalFeature 

  Description:
    This template implements the Default variant of the ADC12DisableChannelDigitalFeature function.
    Operation is not atomic.
*/
extern __inline__ void __attribute__((always_inline)) 
ADC12DisableChannelDigital( ADC12_MODULE channel )
{

    ADCCON3 &= ~(1<<(channel + 16));
}

/*********************************************************************
 * Function:        void OpenADC10(unsigned int config1,
 *                                 unsigned int config2,
 *                                 unsigned int config3,
 *                                 unsigned int configport,
 *                                 unsigned int configscan)
 *
 * Description:     Configures ADC using passed parameters
 *
 * PreCondition:    None
 *
 * Inputs:          AD1CON1 config, AD1CON2 config, AD1CON3 config, port pin config, AD1CSSL config
 *                   An absent symbol is automatically taken as off or default value.
 *                          See below for available options for each input
 *
 * Output:          None
 *
 * Example:         OpenADC10(ADC_MODULE_ON | ADC_IDLE_CONTINUE | ADC_FORMAT_FRACT16 | ADC_CLK_AUTO |  ADC_AUTO_SAMPLING_ON ,
 *                   ADC_VREF_AVDD_AVSS | ADC_OFFSET_CAL_DISABLE | ADC_SCAN_ON | ADC_SAMPLES_PER_INT_2 |  ADC_BUF_16,
 *                   ADC_CONV_CLK_INTERNAL_RC | ADC_SAMPLE_TIME_12,
 *                   ENABLE_AN0_ANA |  ENABLE_AN1_ANA,
 *                   SKIP_SCAN_AN2 | SKIP_SCAN_AN3 | SKIP_SCAN_AN4 | SKIP_SCAN_AN5 | SKIP_SCAN_AN6 | SKIP_SCAN_AN7 | SKIP_SCAN_AN8
 *                   SKIP_SCAN_AN9 | SKIP_SCAN_AN10 | SKIP_SCAN_AN11 | SKIP_SCAN_AN12 | SKIP_SCAN_AN13 | SKIP_SCAN_AN14 | SKIP_SCAN_AN15)
 *
 ********************************************************************/
//#define OpenADC10(config1, config2, config3, configport, configscan) (mPORTBSetPinsAnalogIn(configport), AD1CSSL = ~(configscan), AD1CON3 = (config3), AD1CON2 = (config2), AD1CON1 = (config1) )    
extern __inline__ BOOL __attribute__((always_inline)) 
OpenADC12( ADC12_AN_INPUT analogInput )
{
ADC12_MODULE channel;

    if(ADC12_AN49 < analogInput) return FALSE;
    
    /* Wait for voltage reference to be stable */
    while(!ADCCON2bits.BGVRRDY);        // Wait until the reference voltage is ready
    while(ADCCON2bits.REFFLT);          // Wait if there is a fault with the reference voltage

    /* Get ADC channel */
    channel = ADC12GetChannel(analogInput);
    /* Enable clock to analog circuit */
    ADC12EnableChannelAnalog(channel);
    /* Wait for ADC to be ready */
    while(!ADC12IsChannelReady(channel));
    /* Enable the ADC module */
    ADC12EnableChannelDigital(channel);
}

/*********************************************************************
 * Function:        EnableADC12()
 *
 * Description:     Enables ADC
 *
 * PreCondition:    ADC should be configured
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableADC12()
 *
 ********************************************************************/
#define EnableADC12() ( ADCCON1bits.ON = 1 )
  
/*********************************************************************
 * Function:        ReadADC12
 *
 * Description:     This function reads from one of the 16 ADC Buffers (ADCBUF0 - ADCBUFF)
 *
 * PreCondition:    None
 *
 * Inputs:          Offset from base (ADC1BUF0) of desired buffer
 *
 * Output:          value contained in desired buffer location
 *
 * Example:         result = ReadADC12(3)
 *
 * Note:        ADC result registers are spaced 4 registers apart
 *
 ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
ReadADC12( ADC12_AN_INPUT analogInput )
{ 
    uint32_t mask;
    uint8_t vcn = analogInput;                      // assume our vitual channel number is the real one
    uint32_t adcTRGmode = ADCTRGMODE;               // save trigger mode

    if(ADC12_AN49 < analogInput) return (0);
            
    /* see if we are using alternate inputs */
    if(ADC12_AN44 < analogInput)
    {
        vcn -= 45;    
    }
    
    ADCCON3bits.ADINSEL   = vcn;                    // say which channel to manually trigger
    ADCCON3bits.RQCNVRT  = 1;                       // manually trigger it.

    /* wait for completion of the conversion */
    if(vcn < 32)
    {
        mask = 0x1 << vcn;
        while((ADCDSTAT1 & mask) == 0);
    }
    else
    {
        mask = 0x1 << (vcn - 32);
        while((ADCDSTAT2 & mask) == 0);
    }

    /* return the trigger mode to what it was */
    ADCTRGMODE = adcTRGmode;

    /* return the converted data */
    return((int) ((uint32_t *) &ADCDATA0)[vcn]);
}
     
/*********************************************************************
 * Function:        CloseADC12(void)
 *
 * Description:     Switches off the ADC and disables the interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseADC12()
 *
 ********************************************************************/
#define CloseADC12() ( ADCCON1bits.ON = 0 )
    
    
#ifdef	__cplusplus
}
#endif

#endif	/* ADC12_H */

