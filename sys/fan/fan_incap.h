/*
		FileName: incap.h
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

#ifndef INCAP_H
#define	INCAP_H

#include <xc.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

/*********************************************************************
 * <combinewith OpenCapture2, OpenCapture3, OpenCapture4, OpenCapture5>
 *
 * Function:        OpenCapturex()
 *
 * Description:     Configures specified capture channel
 *
 * PreCondition:    None
 *
 * Inputs:          config - see below
 *
 * Output:          None
 *
 * Example:         OpenCapture1(IC_ON | IC_FEDGE_RISE | IC_TIMER2_SRC);
 *
 ********************************************************************/
#ifdef _ICAP1
    #define  OpenCapture1(config)       (IC1CON = (config))
#endif

#ifdef _ICAP2
    #define  OpenCapture2(config)       (IC2CON = (config))
#endif

#ifdef _ICAP3
    #define  OpenCapture3(config)       (IC3CON = (config))
#endif

#ifdef _ICAP4
    #define  OpenCapture4(config)       (IC4CON = (config))
#endif

#ifdef _ICAP5
    #define  OpenCapture5(config)       (IC5CON = (config))
#endif

#ifdef _ICAP6
    #define  OpenCapture6(config)       (IC6CON = (config))
#endif

#ifdef _ICAP7
    #define  OpenCapture7(config)       (IC7CON = (config))
#endif

#ifdef _ICAP8
    #define  OpenCapture8(config)       (IC8CON = (config))
#endif    
    
#ifdef _ICAP9
    #define  OpenCapture9(config)       (IC9CON = (config))
#endif      
    
    
    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Module On/off control - values are mutually exclusive
        #define IC_ON                   (1 << _IC1CON_ON_POSITION)
        #define IC_OFF                  0

        // Module Stop-In-Idle control - values are mutually exclusive
        #define IC_IDLE_CON             (1 << _IC1CON_SIDL_POSITION)    /* IC operates in sleep mode */
        #define IC_IDLE_STOP            0                               /* IC stop in sleep mode */

        // First Edge control - values are mutually exclusive
        #define IC_FEDGE_RISE           (1 << _IC1CON_FEDGE_POSITION)   /* Capture Rising Edge First */
        #define IC_FEDGE_FALL           0                               /* Capture Falling Edge First */

        // 16- or 32-bit - values are mutually exclusive
        #define IC_CAP_32BIT            (1 << _IC1CON_C32_POSITION)     /* 32-bit timer resource capture */
        #define IC_CAP_16BIT            0                               /* 16-bit timer resource capture */

        // Timer select - values are mutually exclusive
        #define IC_TIMER3_SRC    (0)                                    /* Timer 3 is the clock source for Capture */
        #define IC_TIMER2_SRC    (1 << _IC1CON_ICTMR_POSITION)          /* Timer2 is the clock source for Capture */


        // Capture interrupt control - values are mutually exclusive
        #define IC_INT_4CAPTURE         (3 << _IC1CON_ICI0_POSITION)    /* Interrupt on fourth Capture*/
        #define IC_INT_3CAPTURE         (2 << _IC1CON_ICI0_POSITION)    /* Interrupt on third Capture */
        #define IC_INT_2CAPTURE         (1 << _IC1CON_ICI0_POSITION)    /* Interrupt on second Capture*/
        #define IC_INT_1CAPTURE         (0 << _IC1CON_ICI0_POSITION)    /* Interrupt on first Capture */

        // Mode select - values are mutually exclusive
        #define IC_INTERRUPT            (7 << _IC1CON_ICM_POSITION)     /* Interrupt pin only in CPU sleep and idle mode */
        #define IC_SP_EVERY_EDGE        (6 << _IC1CON_ICM_POSITION)     /* Specified edge first, then every rising/falling edge */
        #define IC_EVERY_16_RISE_EDGE   (5 << _IC1CON_ICM_POSITION)     /* Every 16th rising edge */
        #define IC_EVERY_4_RISE_EDGE    (4 << _IC1CON_ICM_POSITION)     /* Every 4th rising edge  */
        #define IC_EVERY_RISE_EDGE      (3 << _IC1CON_ICM_POSITION)     /* Every rising edge      */
        #define IC_EVERY_FALL_EDGE      (2 << _IC1CON_ICM_POSITION)     /* Every falling edge      */
        #define IC_EVERY_EDGE           (1 << _IC1CON_ICM_POSITION)     /* Every rising/falling edge */
        #define IC_INPUTCAP_OFF         (0)                             /* Input Capture Off      */
    /***********************************
     * End config parameter values
     ************************************/
    
    
/*********************************************************************
 * <combinewith ConfigIntCapture2, ConfigIntCapture3, ConfigIntCapture4, ConfigIntCapture5>
 *
 * Function:        ConfigIntCapturex(unsigned int)
 *
 * Description:     Configures specified capture channel
 *
 * PreCondition:    None
 *
 * Inputs:          config - see below
 *
 * Output:          None
 *
 * Example:         ConfigIntCapture1(IC_INT_ON | IC_INT_PRIOR_4 | IC_INT_SUB_PRIOR_3);
 *
 ********************************************************************/
#ifdef _ICAP1
    #define ConfigIntCapture1(config) (mIC1ClearIntFlag(), mIC1SetIntPriority((config)&7), mIC1SetIntSubPriority(((config)&3)>>3), mIC1IntEnable((config)>>15))
#endif

#ifdef _ICAP2
    #define ConfigIntCapture2(config) (mIC2ClearIntFlag(), mIC2SetIntPriority((config)&7), mIC2SetIntSubPriority(((config)&3)>>3), mIC2IntEnable((config)>>15))
#endif

#ifdef _ICAP3
    #define ConfigIntCapture3(config) (mIC3ClearIntFlag(), mIC3SetIntPriority((config)&7), mIC3SetIntSubPriority(((config)&3)>>3), mIC3IntEnable((config)>>15))
#endif

#ifdef _ICAP4
    #define ConfigIntCapture4(config) (mIC4ClearIntFlag(), mIC4SetIntPriority((config)&7), mIC4SetIntSubPriority(((config)&3)>>3), mIC4IntEnable((config)>>15))
#endif

#ifdef _ICAP5
    #define ConfigIntCapture5(config) (mIC5ClearIntFlag(), mIC5SetIntPriority((config)&7), mIC5SetIntSubPriority(((config)&3)>>3), mIC5IntEnable((config)>>15))
#endif    

#ifdef _ICAP6
    #define ConfigIntCapture6(config) (mIC6ClearIntFlag(), mIC6SetIntPriority((config)&7), mIC6SetIntSubPriority(((config)&3)>>3), mIC6IntEnable((config)>>15))
#endif

#ifdef _ICAP7
    #define ConfigIntCapture7(config) (mIC7ClearIntFlag(), mIC7SetIntPriority((config)&7), mIC7SetIntSubPriority(((config)&3)>>3), mIC7IntEnable((config)>>15))
#endif

#ifdef _ICAP8
    #define ConfigIntCapture8(config) (mIC8ClearIntFlag(), mIC8SetIntPriority((config)&7), mIC8SetIntSubPriority(((config)&3)>>3), mIC8IntEnable((config)>>15))
#endif

#ifdef _ICAP9
    #define ConfigIntCapture9(config) (mIC9ClearIntFlag(), mIC9SetIntPriority((config)&7), mIC9SetIntSubPriority(((config)&3)>>3), mIC9IntEnable((config)>>15))
#endif 


    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt enable/disable - values are mutually exclusive
        #define IC_INT_ON               (1<<15)     /* Input Capture Int Enable  */
        #define IC_INT_OFF              (0)         /* Input Capture Int Disable */

        // Interrupt priority values - values are mutually exclusive
        #define IC_INT_PRIOR_0          (0)
        #define IC_INT_PRIOR_1          (1)
        #define IC_INT_PRIOR_2          (2)
        #define IC_INT_PRIOR_3          (3)
        #define IC_INT_PRIOR_4          (4)
        #define IC_INT_PRIOR_5          (5)
        #define IC_INT_PRIOR_6          (6)
        #define IC_INT_PRIOR_7          (7)

        // Interrupt sub-priority values - values are mutually exclusive
        #define IC_INT_SUB_PRIOR_0      (0<<3)
        #define IC_INT_SUB_PRIOR_1      (1<<3)
        #define IC_INT_SUB_PRIOR_2      (2<<3)
        #define IC_INT_SUB_PRIOR_3      (3<<3)
    /***********************************
     * End config parameter values
     ************************************/

    
/*********************************************************************
 * <combinewith SetPriorityIntIC2, SetPriorityIntIC3, SetPriorityIntIC4, SetPriorityIntIC5>
 *
 * Function:        SetPriorityIntICx(priority)
 *
 * Description:     Sets priority and sub-priority for specified capture channel
 *
 * PreCondition:    None
 *
 * Inputs:          config - see below
 *
 * Output:          None
 *
 * Example:         SetPriorityIntIC1(IC_INT_PRIOR_4 | IC_INT_SUB_PRIOR_3);
 *
 ********************************************************************/
#ifdef _ICAP1
    #define SetPriorityIntIC1(priority)     (mIC1SetIntPriority((priority)&7), mIC1SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP2
    #define SetPriorityIntIC2(priority)     (mIC2SetIntPriority((priority)&7), mIC2SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP3
    #define SetPriorityIntIC3(priority)     (mIC3SetIntPriority((priority)&7), mIC3SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP4
    #define SetPriorityIntIC4(priority)     (mIC4SetIntPriority((priority)&7), mIC4SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP5
    #define SetPriorityIntIC5(priority)     (mIC5SetIntPriority((priority)&7), mIC5SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP6
    #define SetPriorityIntIC6(priority)     (mIC6SetIntPriority((priority)&7), mIC6SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP7
    #define SetPriorityIntIC7(priority)     (mIC7SetIntPriority((priority)&7), mIC7SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP8
    #define SetPriorityIntIC8(priority)     (mIC8SetIntPriority((priority)&7), mIC8SetIntSubPriority(((priority)&3)>>3))
#endif

#ifdef _ICAP9
    #define SetPriorityIntIC9(priority)     (mIC9SetIntPriority((priority)&7), mIC9SetIntSubPriority(((priority)&3)>>3))
#endif


    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt priority values - values are mutually exclusive
        // Use same options from ConfigIntCapturex macro

        // Interrupt sub-priority values - values are mutually exclusive
        // Use same options from ConfigIntCapturex macro
    /***********************************
     * End config parameter values
     ************************************/


/*********************************************************************
 * <combinewith DisableIntIC1, EnableIntIC2, DisableIntIC2, EnableIntIC3, DisableIntIC3, EnableIntIC4, DisableIntIC4, EnableIntIC5, DisableIntIC5>
 *
 * Function:        void EnableIntICx
 *                  void DisableIntICx
 *
 * Description:     Enables/Disables interrupt for specified capture channel
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntIC1;
 *
 ********************************************************************/
#ifdef _ICAP1
    #define EnableIntIC1                    mIC1IntEnable(1)
    #define DisableIntIC1                   mIC1IntEnable(0)
#endif

#ifdef _ICAP2
    #define EnableIntIC2                    mIC2IntEnable(1)
    #define DisableIntIC2                   mIC2IntEnable(0)
#endif

#ifdef _ICAP3
    #define EnableIntIC3                    mIC3IntEnable(1)
    #define DisableIntIC3                   mIC3IntEnable(0)
#endif

#ifdef _ICAP4
    #define EnableIntIC4                    mIC4IntEnable(1)
    #define DisableIntIC4                   mIC4IntEnable(0)
#endif

#ifdef _ICAP5
    #define EnableIntIC5                    mIC5IntEnable(1)
    #define DisableIntIC5                   mIC5IntEnable(0)
#endif

#ifdef _ICAP6
    #define EnableIntIC6                    mIC6IntEnable(1)
    #define DisableIntIC6                   mIC6IntEnable(0)
#endif

#ifdef _ICAP7
    #define EnableIntIC7                    mIC7IntEnable(1)
    #define DisableIntIC7                   mIC7IntEnable(0)
#endif

#ifdef _ICAP8
    #define EnableIntIC8                    mIC8IntEnable(1)
    #define DisableIntIC8                   mIC8IntEnable(0)
#endif

#ifdef _ICAP9
    #define EnableIntIC9                    mIC9IntEnable(1)
    #define DisableIntIC9                   mIC9IntEnable(0)
#endif   


/*********************************************************************
 * <combinewith  CloseCapture2, CloseCapture3, CloseCapture4, CloseCapture5>
 *
 * Function:        void CloseCapturex(void)
 *
 * Description:     Closes specified capture channel
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseCapture1();
 *
 ********************************************************************/
#ifdef _ICAP1
    #define CloseCapture1() (mIC1IntEnable(0), mIC1ClearIntFlag(), IC1CONCLR = _IC1CON_ICM_MASK)
#endif

#ifdef _ICAP2
    #define CloseCapture2() (mIC2IntEnable(0), mIC2ClearIntFlag(), IC2CONCLR = _IC2CON_ICM_MASK)
#endif

#ifdef _ICAP3
    #define CloseCapture3() (mIC3IntEnable(0), mIC3ClearIntFlag(), IC3CONCLR = _IC3CON_ICM_MASK)
#endif

#ifdef _ICAP4
    #define CloseCapture4() (mIC4IntEnable(0), mIC4ClearIntFlag(), IC4CONCLR = _IC4CON_ICM_MASK)
#endif

#ifdef _ICAP5
    #define CloseCapture5() (mIC5IntEnable(0), mIC5ClearIntFlag(), IC5CONCLR = _IC5CON_ICM_MASK)
#endif

#ifdef _ICAP6
    #define CloseCapture6() (mIC6IntEnable(0), mIC6ClearIntFlag(), IC6CONCLR = _IC6CON_ICM_MASK)
#endif

#ifdef _ICAP7
    #define CloseCapture7() (mIC7IntEnable(0), mIC7ClearIntFlag(), IC7CONCLR = _IC7CON_ICM_MASK)
#endif

#ifdef _ICAP8
    #define CloseCapture8() (mIC8IntEnable(0), mIC8ClearIntFlag(), IC8CONCLR = _IC8CON_ICM_MASK)
#endif

#ifdef _ICAP9
    #define CloseCapture9() (mIC9IntEnable(0), mIC9ClearIntFlag(), IC9CONCLR = _IC9CON_ICM_MASK)
#endif
    

/*********************************************************************
 * <combinewith  ReadCapture2, ReadCapture3, ReadCapture4, ReadCapture5>
 *
 * Function:        void ReadCapture1x(void)
 *
 * Description:     Reads specified capture channel, waits if data is not ready
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         ReadCapture11();
 *
 ********************************************************************/
#ifdef _ICAP1
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture1(unsigned int * buffer)
    {
        while (IC1CONbits.ICBNE)
        {
            *buffer++ = IC1BUF; /* reads the input capture buffer */
        }
    }
#endif

#ifdef _ICAP2
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture2(unsigned int * buffer)
    {
        while (IC2CONbits.ICBNE)
        {
            *buffer++ = IC2BUF; /* reads the input capture buffer */
        }
    }
#endif

#ifdef _ICAP3
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture3(unsigned int * buffer)
    {
        while (IC3CONbits.ICBNE)
        {
            *buffer++ = IC3BUF; /* reads the input capture buffer */
        }
    }
#endif

#ifdef _ICAP4
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture4(unsigned int * buffer)
    {
        while (IC4CONbits.ICBNE)
        {
            *buffer++ = IC4BUF; /* reads the input capture buffer */
        }
    }
#endif

#ifdef _ICAP5
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture5(unsigned int * buffer)
    {
        while (IC5CONbits.ICBNE)
        {
            *buffer++ = IC5BUF; /* reads the input capture buffer */
        }
    }
#endif    

#ifdef _ICAP6
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture6(unsigned int * buffer)
    {
        while (IC6CONbits.ICBNE)
        {
            *buffer++ = IC6BUF; /* reads the input capture buffer */
        }
    }
#endif      

#ifdef _ICAP7
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture7(unsigned int * buffer)
    {
        while (IC7CONbits.ICBNE)
        {
            *buffer++ = IC7BUF; /* reads the input capture buffer */
        }
    }
#endif      

#ifdef _ICAP8
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture8(unsigned int * buffer)
    {
        while (IC8CONbits.ICBNE)
        {
            *buffer++ = IC8BUF; /* reads the input capture buffer */
        }
    }
#endif      

#ifdef _ICAP9
    extern __inline__ void __attribute__((always_inline)) 
    ReadCapture9(unsigned int * buffer)
    {
        while (IC9CONbits.ICBNE)
        {
            *buffer++ = IC9BUF; /* reads the input capture buffer */
        }
    }
#endif      


/*********************************************************************
 * <combinewith  mIC2CaptureReady, mIC3CaptureReady, mIC4CaptureReady, mIC5CaptureReady>
 *
 * Function:        int mICxCaptureReady(void)
 *
 * Description:     Checks to see if specified channel has captured anything
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          '1' if there is a captured data
 *                  '0' otherwise
 *
 * Example:         if ( mIC1CaptureReady1() )
 *                      // There is some data
 *                  else
 *                      // There is no data
 *
 ********************************************************************/
#ifdef _ICAP1
    #define mIC1CaptureReady()              (IC1CONbits.ICBNE)
#endif

#ifdef _ICAP2
    #define mIC2CaptureReady()              (IC2CONbits.ICBNE)
#endif

#ifdef _ICAP3
    #define mIC3CaptureReady()              (IC3CONbits.ICBNE)
#endif

#ifdef _ICAP4
    #define mIC4CaptureReady()              (IC4CONbits.ICBNE)
#endif

#ifdef _ICAP5
    #define mIC5CaptureReady()              (IC5CONbits.ICBNE)
#endif    

#ifdef _ICAP6
    #define mIC6CaptureReady()              (IC6CONbits.ICBNE)
#endif

#ifdef _ICAP7
    #define mIC7CaptureReady()              (IC7CONbits.ICBNE)
#endif

#ifdef _ICAP8
    #define mIC8CaptureReady()              (IC8CONbits.ICBNE)
#endif

#ifdef _ICAP9
    #define mIC9CaptureReady()              (IC9CONbits.ICBNE)
#endif      
    

/*********************************************************************
 * <combinewith  mIC2ReadCapture, mIC3ReadCapture, mIC4ReadCapture, mIC5ReadCapture>
 *
 * Function:        int mIC1ReadCapture(void)
 *
 * Description:     Reads the captured data
 *
 * PreCondition:    mIC1CaptureReady() must be '1'
 *
 * Inputs:          None
 *
 * Output:          Captured data
 *
 * Example:         if ( mIC1CaptureReady1() )
 *                      // There is some data
 *                      myData = mIC1ReadCapture();
 *                  else
 *                      // There is no data
 *
 ********************************************************************/
#ifdef _ICAP1
    #define mIC1ReadCapture()               (IC1BUF)
#endif

#ifdef _ICAP2
    #define mIC2ReadCapture()               (IC2BUF)
#endif

#ifdef _ICAP3
    #define mIC3ReadCapture()               (IC3BUF)
#endif

#ifdef _ICAP4
    #define mIC4ReadCapture()               (IC4BUF)
#endif

#ifdef _ICAP5
    #define mIC5ReadCapture()               (IC5BUF)
#endif    

#ifdef _ICAP6
    #define mIC6ReadCapture()               (IC6BUF)
#endif

#ifdef _ICAP7
    #define mIC7ReadCapture()               (IC7BUF)
#endif

#ifdef _ICAP8
    #define mIC8ReadCapture()               (IC8BUF)
#endif

#ifdef _ICAP9
    #define mIC9ReadCapture()               (IC9BUF)
#endif  
    

#ifdef	__cplusplus
}
#endif

#endif	/* INCAP_H */

