/*
		FileName: timer.h
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

#ifndef TIMER_H
#define	TIMER_H

#include <xc.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

/*********************************************************************
 * Core Timer Control Interrupt Functions
 *
 * Function:        void OpenCoreTimer(unsigned int period)
 *
 * PreCondition:    None
 *
 * Inputs:          period - 32 bit value for the timer
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
OpenCoreTimer( unsigned int period )
{
	// clear the count reg
    asm volatile("mtc0   $0,$9");
    // set up the period in the compare reg
    asm volatile("mtc0   %0,$11" : "+r"(period));
}

/*********************************************************************
 * Core Timer
 *
 * Function:        void UpdateCoreTimer(unsigned int period)
 *
 * PreCondition:    None
 *
 * Inputs:          period - 32 bit value for the timer
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
UpdateCoreTimer(unsigned int period)
{
    unsigned int old_period;

    // get the old compare time
    asm volatile("mfc0   %0, $11" : "=r"(old_period));
    period += old_period;
    // set up the period in the compare reg
    asm volatile("mtc0   %0,$11" : "+r"(period));
}


/******************************************************************************
 * Function:        void ConfigIntCoreTimer(int config)
 *
 * Description:     Configures Core Timer  interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of CT_INT_XXX, CT_INT_PRIOR_XXX
 *                            and CT_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntCoreTimer(CT_INT_ON | CT_INT_PRIOR_3 | CT_INT_SUB_PRIOR_1)
 *
 *****************************************************************************/
#define mConfigIntCoreTimer(config)      (mCTClearIntFlag(), mCTSetIntPriority(((config) & 7)),\
        mCTSetIntSubPriority((((config) >> 4) & 3)), mCTIntEnable(((config) >> 15)))

    /******************************************************************************
     * Available options for config parameter. values are mutually exclusive.
     *****************************************************************************/
        #define CT_INT_ON                       (1 << 15)
        #define CT_INT_OFF                      (0) // Coretimer Int off

        #define CT_INT_PRIOR_7                  (7) // Coretimer Int priority 7
        #define CT_INT_PRIOR_6                  (6) // Coretimer Int priority 6
        #define CT_INT_PRIOR_5                  (5) // Coretimer Int priority 5
        #define CT_INT_PRIOR_4                  (4) // Coretimer Int priority 4
        #define CT_INT_PRIOR_3                  (3) // Coretimer Int priority 3
        #define CT_INT_PRIOR_2                  (2) // Coretimer Int priority 2
        #define CT_INT_PRIOR_1                  (1) // Coretimer Int priority 1
        #define CT_INT_PRIOR_0                  (0) // Coretimer Int priority 0

        #define CT_INT_SUB_PRIOR_3              (3 << 4)  // Coretimer Int sub priority 3
        #define CT_INT_SUB_PRIOR_2              (2 << 4)  // Coretimer Int sub priority 2
        #define CT_INT_SUB_PRIOR_1              (1 << 4)  // Coretimer Int sub priority 1
        #define CT_INT_SUB_PRIOR_0              (0 << 4)  // Coretimer Int sub priority 0
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntCoreTimer(void)
 *
 * Description:     Enables Core Timer interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntCoreTimer();
 *****************************************************************************/
#define mEnableIntCoreTimer()            mCTIntEnable(1)


/******************************************************************************
 * Function:        DisableIntCoreTimer(void)
 *
 * Description:     Disables Core Timer interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntCoreTimer();
 *****************************************************************************/
#define mDisableIntCoreTimer()           mCTIntEnable(0)

/******************************************************************************
 * Function:        void SetPriorityIntCoreTimer(int priority)
 *
 * Description:     Sets the priority for Core Timer interrupt
 *                  The ConfigIntCoreTimer() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of CT_INT_PRIOR_XXX
 *
 * Output:          None
 *
 *
 * Example:         SetPriorityIntCoreTimer(CT_INT_PRIORITY_3);
 *****************************************************************************/
#define mSetPriorityIntCoreTimer(priority)  mCTSetIntPriority(priority)

/******************************************************************************
 * Function:        unsigned int ReadCoreTimer(void)
 *
 * Description:     Returns the current Core Timer value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          Count value.
 *
 * Example:         ReadCoreTimer();
 *
 *****************************************************************************/
//unsigned int extern inline __attribute__((nomips16,nomicromips,always_inline)) 
unsigned int extern inline __attribute__((always_inline)) 
ReadCoreTimer( void )
{
    unsigned int timer;

    // get the count reg
    asm volatile("mfc0   %0, $9" : "=r"(timer));

    return timer;
}

/******************************************************************************
 * Function:        void WriteCoreTimer(unsigned int value)
 *
 * Description:     Loads 32-bit value into CoreTimer.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteCoreTimer(0x1234);
 *
 *****************************************************************************/
//void  extern inline __attribute__((nomips16,nomicromips,always_inline))
void  extern inline __attribute__((always_inline))
WriteCoreTimer( unsigned int timer )
{
    /* get the count reg */
    asm volatile("mtc0   %0, $9": "+r"(timer));
}

/*********************************************************************
 * Core Timer
 *
 * Function:        void TickDelayCoreTimer(unsigned int tics)
 *
 * PreCondition:    None
 *
 * Inputs:          tics - 32 bit value for the tics of the timer
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
TickDelayCoreTimer(unsigned int tics)
{
    WriteCoreTimer(0);
    while(ReadCoreTimer() < tics );
}

/******************************************************************************
 * Function:        void CloseCoreTimer(void)
 *
 * Description:     Loads 32-bit value into CoreTimer.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteCoreTimer(0x1234);
 *
 *****************************************************************************/
#define CloseCoreTimer()        (mCTIntEnable(0))


// *****************************************************************************
/* UART Module

  Summary:
    UART modules supported.

  Description:
    This enumeration identifies the available UART modules.
*/

typedef enum
{  
    // TMR1 Module ID.
    TIMER1 = 0,

    // TMR2 Module ID.
    TIMER2 = 1,

    // TMR3 Module ID.
    TIMER3 = 2,

    // TMR4 Module ID.
    TIMER4 = 3,

    // TMR5 Module ID.
    TIMER5 = 4,

    // TMR6 Module ID.
    TIMER6 = 5,

    // TMR6 Module ID.
    TIMER7 = 6,

    // TMR6 Module ID.
    TIMER8 = 7,

    // TMR6 Module ID.
    TIMER9 = 8,
     
    // Number of available TMR modules.
    TIMER_NUMBER_OF_MODULES = 9
    
} TIMER_MODULE;


#if defined _TMR1

/******************************************************************************
 * Function:        void OpenTimer1(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 1
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T1_ON/OFF, T1_IDLE_XXX,
 *                          T1_GATE_XXX, T1_PS_XXX, T1_SYC_EXT_XXX,
 *                          T1_SOURCE_XXX.
 *                  period: A value between 0 - 0xffff inclusive
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         OpenTimer1(T1_ON | T1_IDLE_ON | T1_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer1(config, period)  (T1CON = ((config)&~(T1_ON)), TMR1 = 0, PR1 = (period), T1CONSET=((config)&(T1_ON)) )

/******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T1_ON                           (1 << _T1CON_ON_POSITION)       /* Timer1 ON */
        #define T1_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T1_IDLE_STOP                    (1 << _T1CON_SIDL_POSITION)     /* stop during idle */
        #define T1_IDLE_CON                     (0)                             /* operate during idle */

        // Asynchronous write control - values are mutually exclusive
        #define T1_TMWDIS_ON                    (1 << _T1CON_TWDIS_POSITION)    /* Asynchronous Write Disable */
        #define T1_TMWDIS_OFF                   (0)

        // Timer gate control - values are mutually exclusive
        #define T1_GATE_ON                      (1 << _T1CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T1_GATE_OFF                     (0)

        // Timer prescaler control - values are mutually exclusive
        #define T1_PS_1_256                     (3 << _T1CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T1_PS_1_64                      (2 << _T1CON_TCKPS_POSITION)    /*           1:64 */
        #define T1_PS_1_8                       (1 << _T1CON_TCKPS_POSITION)    /*           1:8 */
        #define T1_PS_1_1                       (0)                             /*           1:1 */

        // Sync option - values are mutually exclusive
        #define T1_SYNC_EXT_ON                  (1 << _T1CON_TSYNC_POSITION)    /* Synch external clk input */
        #define T1_SYNC_EXT_OFF                 (0)

        // Source selection - values are mutually exclusive
        #define T1_SOURCE_EXT                   (1 << _T1CON_TCS_POSITION)      /* External clock source */
        #define T1_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        CloseTimer1()
 *
 * Description:     Switches off the Timer1
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer1();
 *
 *****************************************************************************/
#define CloseTimer1()   (mT1IntEnable(0), T1CON = 0)


/******************************************************************************
 * Function:        void ConfigIntTimer1(unsigned int config)
 *
 * Description:     Configures Timer 1 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T1_INT_XXX, T1_INT_PRIOR_XXX
 *                            and T1_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer1(T1_INT_ON | T1_INT_PRIOR_3 | T1_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer1(config) (mT1ClearIntFlag(), mT1SetIntPriority((config) & 7),\
        mT1SetIntSubPriority(((config) >> 4) & 3), mT1IntEnable((config) >> 15))


    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T1_INT_ON                       (1 << 15)
        #define T1_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T1_INT_PRIOR_7                  (7) // Timer int priority 7
        #define T1_INT_PRIOR_6                  (6) // Timer int priority 6
        #define T1_INT_PRIOR_5                  (5) // Timer int priority 5
        #define T1_INT_PRIOR_4                  (4) // Timer int priority 4
        #define T1_INT_PRIOR_3                  (3) // Timer int priority 3
        #define T1_INT_PRIOR_2                  (2) // Timer int priority 2
        #define T1_INT_PRIOR_1                  (1) // Timer int priority 1
        #define T1_INT_PRIOR_0                  (0) // Timer int priority 0

        // Interrupt sub-priority - values are mutually exclusive
        #define T1_INT_SUB_PRIOR_3              (3 << 4) // Timer int sub priority 3
        #define T1_INT_SUB_PRIOR_2              (2 << 4) // Timer int sub priority 2
        #define T1_INT_SUB_PRIOR_1              (1 << 4) // Timer int sub priority 1
        #define T1_INT_SUB_PRIOR_0              (0 << 4) // Timer int sub priority 0
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT1
 *
 * Description:     Enables Timer1 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT1;
 *****************************************************************************/
#define EnableIntT1                 mT1IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT1
 *
 * Description:     Disables Timer1 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT1;
 *****************************************************************************/
#define DisableIntT1                mT1IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT1(int priority)
 *
 * Description:     Sets the priority for Timer 1 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T1_INT_PRIOR_XXX
 *
 * Output:          None
 *
 *
 * Example:         SetPriorityIntT1(T1_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT1(priority)  mT1SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer1(void)
 *
 * Description:     Returns the current Timer1 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR1 value.
 *
 * Example:         ReadTimer1();
 *
 *****************************************************************************/
#define ReadTimer1()    (TMR1)


/******************************************************************************
 * Function:        void WriteTimer1(unsigned int value)
 *
 * Description:     Loads given value into Timer1 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer1(1234);
 *
 *****************************************************************************/
#define WriteTimer1(value)  TMR1 = ((value))


/******************************************************************************
 * Function:        unsigned int ReadPeriod1(void)
 *
 * Description:     Returns the current Period1 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR1 value.
 *
 * Example:         ReadPeriod1();
 *
 *****************************************************************************/
#define ReadPeriod1()   (PR1)


/******************************************************************************
 * Function:        void WritePeriod1(unsigned int value)
 *
 * Description:     Loads given value into Period1 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod1(1234);
 *
 *****************************************************************************/
#define WritePeriod1(value) PR1 = ((value))

#endif      // _TMR1

#if defined _TMR2

/******************************************************************************
 * Function:        void OpenTimer2(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 2
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T2_ON/OFF, T2_IDLE_XXX,
 *                          T2_GATE_XXX, T1_PS_XXX, T2_32BIT_MODE_ON, and
 *                          T2_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer2(T2_ON | T2_IDLE_ON | T2_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer2(config, period)  (T2CON = ((config)&~(T2_ON)), TMR2 = 0, PR2 = (period), T2CONSET=((config)&(T2_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T2_ON                           (1 << _T2CON_ON_POSITION)       /* Timer2 ON */
        #define T2_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T2_IDLE_STOP                    (1 << _T2CON_SIDL_POSITION)     /* stop during idle */
        #define T2_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T2_GATE_ON                      (1 << _T2CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T2_GATE_OFF                     (0)

        // Prescale values - values are mutually exclusive
        #define T2_PS_1_256                     (7 << _T2CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T2_PS_1_64                      (6 << _T2CON_TCKPS_POSITION)    /*           1:64 */
        #define T2_PS_1_32                      (5 << _T2CON_TCKPS_POSITION)    /*           1:32 */
        #define T2_PS_1_16                      (4 << _T2CON_TCKPS_POSITION)    /*           1:16 */
        #define T2_PS_1_8                       (3 << _T2CON_TCKPS_POSITION)    /*           1:8 */
        #define T2_PS_1_4                       (2 << _T2CON_TCKPS_POSITION)    /*           1:4 */
        #define T2_PS_1_2                       (1 << _T2CON_TCKPS_POSITION)    /*           1:2 */
        #define T2_PS_1_1                       (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T2_32BIT_MODE_ON                (1 << _T2CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T2_32BIT_MODE_OFF               (0)

        // Sync external clock option - values are mutually exclusive
        #define T2_SOURCE_EXT                   (1 << _T2CON_TCS_POSITION)      /* External clock source */
        #define T2_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        CloseTimer2()
 *
 * Description:     Switches off the Timer2
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer2();
 *
 *****************************************************************************/
#define CloseTimer2()   (mT2IntEnable(0), T2CON = 0)


/******************************************************************************
 * Function:        void ConfigIntTimer2(unsigned int config)
 *
 * Description:     Configures Timer 2 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T2_INT_XXX, T2_INT_PRIOR_XXX
 *                            and T2_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer2(T2_INT_ON | T2_INT_PRIOR_3 | T2_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer2(config) (mT2ClearIntFlag(), mT2SetIntPriority(((config) & 7)),\
        mT2SetIntSubPriority(((config) >> 4) & 3), mT2IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T2_INT_ON                       (1 << 15)       /* T2 Interrupt Enable */
        #define T2_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T2_INT_PRIOR_7                  (7)
        #define T2_INT_PRIOR_6                  (6)
        #define T2_INT_PRIOR_5                  (5)
        #define T2_INT_PRIOR_4                  (4)
        #define T2_INT_PRIOR_3                  (3)
        #define T2_INT_PRIOR_2                  (2)
        #define T2_INT_PRIOR_1                  (1)
        #define T2_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T2_INT_SUB_PRIOR_3              (3 << 4)
        #define T2_INT_SUB_PRIOR_2              (2 << 4)
        #define T2_INT_SUB_PRIOR_1              (1 << 4)
        #define T2_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT2
 *
 * Description:     Enables Timer2 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT2;
 *****************************************************************************/
#define EnableIntT2                 mT2IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT2
 *
 * Description:     Disables Timer2 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT2;
 *****************************************************************************/
#define DisableIntT2                mT2IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT2(int priority)
 *
 * Description:     Sets the priority for Timer 2 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T2_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT2(T2_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT2(priority)  mT2SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer2(void)
 *
 * Description:     Returns the current Timer2 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR2 value.
 *
 * Example:         ReadTimer2();
 *
 *****************************************************************************/
#define ReadTimer2()    (TMR2)


/******************************************************************************
 * Function:        void WriteTimer2(unsigned int value)
 *
 * Description:     Loads given value into Timer2 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer2(1234);
 *
 *****************************************************************************/
#define WriteTimer2(value)  TMR2 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod2(void)
 *
 * Description:     Returns the current Period2 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR2 value.
 *
 * Example:         ReadPeriod2();
 *
 *****************************************************************************/
#define ReadPeriod2()   (PR2)


/******************************************************************************
 * Function:        void WritePeriod2(unsigned int value)
 *
 * Description:     Loads given value into Period2 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod2(1234);
 *
 *****************************************************************************/
#define WritePeriod2(value) PR2 = ((value))



#endif  // _TMR2


#if defined _TMR3

/******************************************************************************
 * Function:        void OpenTimer3(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 3
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T3_ON/OFF, T3_IDLE_XXX,
 *                          T3_GATE_XXX, T3_PS_XXX, T3_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer3(T3_ON | T3_IDLE_ON | T3_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer3(config, period)  (T3CON = ((config)&~(T3_ON)), TMR3 = 0, PR3 = (period), T3CONSET=((config)&(T3_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T3_ON                           (1 << _T3CON_ON_POSITION)       /* Timer3 ON */
        #define T3_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T3_IDLE_STOP                    (1 << _T3CON_SIDL_POSITION)     /* stop during idle */
        #define T3_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T3_GATE_ON                      (1 << _T3CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T3_GATE_OFF                     (0)

        // Timer prescaler control - values are mutually exclusive
        #define T3_PS_1_256                     (7 << _T3CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T3_PS_1_64                      (6 << _T3CON_TCKPS_POSITION)    /*           1:64 */
        #define T3_PS_1_32                      (5 << _T3CON_TCKPS_POSITION)    /*           1:32 */
        #define T3_PS_1_16                      (4 << _T3CON_TCKPS_POSITION)    /*           1:16 */
        #define T3_PS_1_8                       (3 << _T3CON_TCKPS_POSITION)    /*           1:8 */
        #define T3_PS_1_4                       (2 << _T3CON_TCKPS_POSITION)    /*           1:4 */
        #define T3_PS_1_2                       (1 << _T3CON_TCKPS_POSITION)    /*           1:2 */
        #define T3_PS_1_1                       (0)                             /*           1:1 */

        // Source selection - values are mutually exclusive
        #define T3_SOURCE_EXT                   (1 << _T3CON_TCS_POSITION)      /* External clock source */
        #define T3_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        CloseTimer3()
 *
 * Description:     Switches off the Timer3
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer3();
 *
 *****************************************************************************/
#define CloseTimer3()   (mT3IntEnable(0), T3CON = 0)



/******************************************************************************
 * Function:        void ConfigIntTimer3(unsigned int config)
 *
 * Description:     Configures Timer 3 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T3_INT_XXX, T3_INT_PRIOR_XXX
 *                            and T3_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer3(T3_INT_ON | T3_INT_PRIOR_3 | T3_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer3(config) (mT3ClearIntFlag(), mT3SetIntPriority(((config) & 7)),\
        mT3SetIntSubPriority(((config) >> 4) & 3), mT3IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T3_INT_ON                       (1<<15)     /* Interrupt Enable */
        #define T3_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T3_INT_PRIOR_7                  (7)
        #define T3_INT_PRIOR_6                  (6)
        #define T3_INT_PRIOR_5                  (5)
        #define T3_INT_PRIOR_4                  (4)
        #define T3_INT_PRIOR_3                  (3)
        #define T3_INT_PRIOR_2                  (2)
        #define T3_INT_PRIOR_1                  (1)
        #define T3_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T3_INT_SUB_PRIOR_3              (3 << 4)
        #define T3_INT_SUB_PRIOR_2              (2 << 4)
        #define T3_INT_SUB_PRIOR_1              (1 << 4)
        #define T3_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT3()
 *
 * Description:     Enables Timer3 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT3;
 *****************************************************************************/
#define EnableIntT3                 mT3IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT3
 *
 * Description:     Disables Timer3 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT3;
 *****************************************************************************/
#define DisableIntT3                mT3IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT3(unsigned int priority)
 *
 * Description:     Sets the priority for Timer 3 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T3_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT3(T3_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT3(priority)  mT3SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer3(void)
 *
 * Description:     Returns the current Timer3 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR3 value.
 *
 * Example:         ReadTimer3();
 *
 *****************************************************************************/
#define ReadTimer3()    (TMR3)


/******************************************************************************
 * Function:        void WriteTimer3(unsigned int value)
 *
 * Description:     Loads given value into Timer3 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer3(1234);
 *
 *****************************************************************************/
#define WriteTimer3(value)  TMR3 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod3(void)
 *
 * Description:     Returns the current Period3 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR3 value.
 *
 * Example:         ReadPeriod3();
 *
 *****************************************************************************/
#define ReadPeriod3()   (PR3)


/******************************************************************************
 * Function:        void WritePeriod3(unsigned int value)
 *
 * Description:     Loads given value into Period3 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod3(1234);
 *
 *****************************************************************************/
#define WritePeriod3(value) PR3 = ((value))



/******************************************************************************
 * Function:        void OpenTimer23(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 23 - A 32-bit time by pairing
 *                  Timer 2 & 3.
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T2_ON/OFF, T2_IDLE_XXX,
 *                          T2_GATE_XXX, T2_PS_XXX, T2_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffffffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer23(T2_ON | T2_IDLE_ON | T2_PS_1_4, 123);
 *****************************************************************************/
#define OpenTimer23(config, period) \
( OpenTimer2((config) | T2_32BIT_MODE_ON, (period)))

/******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T23_ON                          (1 << _T2CON_ON_POSITION)       /* Timer2 ON */
        #define T23_OFF                         (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T23_IDLE_STOP                   (1 << _T2CON_SIDL_POSITION)     /* stop during idle */
        #define T23_IDLE_CON                    (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T23_GATE_ON                     (1 << _T2CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T23_GATE_OFF                    (0)

        // Prescale values - values are mutually exclusive
        #define T23_PS_1_256                    (7 << _T2CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T23_PS_1_64                     (6 << _T2CON_TCKPS_POSITION)    /*           1:64 */
        #define T23_PS_1_32                     (5 << _T2CON_TCKPS_POSITION)    /*           1:32 */
        #define T23_PS_1_16                     (4 << _T2CON_TCKPS_POSITION)    /*           1:16 */
        #define T23_PS_1_8                      (3 << _T2CON_TCKPS_POSITION)    /*           1:8 */
        #define T23_PS_1_4                      (2 << _T2CON_TCKPS_POSITION)    /*           1:4 */
        #define T23_PS_1_2                      (1 << _T2CON_TCKPS_POSITION)    /*           1:2 */
        #define T23_PS_1_1                      (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T23_32BIT_MODE_ON               (1 << _T2CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T23_32BIT_MODE_OFF              (0)

        // Sync external clock option - values are mutually exclusive
        #define T23_SOURCE_EXT                  (1 << _T2CON_TCS_POSITION)      /* External clock source */
        #define T23_SOURCE_INT                  (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/

/******************************************************************************
 * Function:        CloseTimer23()
 *
 * Description:     Switches off the 32-bit Timer23
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer23();
 *
 *****************************************************************************/
#define CloseTimer23()  (CloseTimer2(), CloseTimer3())


/******************************************************************************
 * Function:        void ConfigIntTimer23(unsigned int config)
 *
 * Description:     Configures the 32-bit Timer23 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T23_INT_XXX, T23_INT_PRIOR_XXX
 *                            and T23_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer23(T23_INT_ON | T23_INT_PRIOR_3 | T23_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer23(config)    ConfigIntTimer3((config))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T23_INT_ON                      (1<<15)     /* Interrupt Enable */
        #define T23_INT_OFF                     (0)

        // Interrupt priority - values are mutually exclusive
        #define T23_INT_PRIOR_7                  (7)
        #define T23_INT_PRIOR_6                  (6)
        #define T23_INT_PRIOR_5                  (5)
        #define T23_INT_PRIOR_4                  (4)
        #define T23_INT_PRIOR_3                  (3)
        #define T23_INT_PRIOR_2                  (2)
        #define T23_INT_PRIOR_1                  (1)
        #define T23_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T23_INT_SUB_PRIOR_3              (3 << 4)
        #define T23_INT_SUB_PRIOR_2              (2 << 4)
        #define T23_INT_SUB_PRIOR_1              (1 << 4)
        #define T23_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT23()
 *
 * Description:     Enables the 32-bit Timer23 interrupt(Timer3 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT23;
 *****************************************************************************/
#define EnableIntT23                EnableIntT3


/******************************************************************************
 * Function:        DisableIntT23
 *
 * Description:     Disables 32-bit Timer23 interrupt(Timer3 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT23;
 *****************************************************************************/
#define DisableIntT23               DisableIntT3


/******************************************************************************
 * Function:        void SetPriorityIntT23(unsigned int priority)
 *
 * Description:     Sets the priority for 32-bit Timer 23 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *                  Interrupts are Timer3.
 *

 * PreCondition:    None
 *
 * Inputs:          priority : A value of T2_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT23(T2_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT23(priority) SetPriorityIntT3((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer23(void)
 *
 * Description:     Returns the current 32-bit Timer23 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          The current 32-bit timer value.
 *
 * Example:         ReadTimer23();
 *
 *****************************************************************************/
#define ReadTimer23()   ReadTimer2()


/******************************************************************************
 * Function:        void WriteTimer23(unsigned int value)
 *
 * Description:     Loads given value into 32-bit Timer23 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer23(1234);
 *
 *****************************************************************************/
#define WriteTimer23(value) WriteTimer2((value))


/******************************************************************************
 * Function:        unsigned int ReadPeriod23(void)
 *
 * Description:     Returns the current Period23 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR2 value.
 *
 * Example:         ReadPeriod23();
 *
 *****************************************************************************/
#define ReadPeriod23()  (PR2)


/******************************************************************************
 * Function:        void WritePeriod23(unsigned int value)
 *
 * Description:     Loads given value into Period23 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod23(1234);
 *
 *****************************************************************************/
#define WritePeriod23(value)    PR2 = (value)



#endif // _TMR3


#if defined _TMR4

/******************************************************************************
 * Function:        void OpenTimer4(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 4
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T4_ON/OFF, T4_IDLE_XXX,
 *                          T4_GATE_XXX, T4_PS_XXX, T4_32BIT_MODE_ON, and
 *                          T4_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer4(T4_ON | T4_IDLE_ON | T4_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer4(config, period)  (T4CON = ((config)&~(T4_ON)), TMR4 = 0, PR4 = (period), T4CONSET=((config)&(T4_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T4_ON                           (1 << _T4CON_ON_POSITION)       /* Timer4 ON */
        #define T4_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T4_IDLE_STOP                    (1 << _T4CON_SIDL_POSITION)     /* stop during idle */
        #define T4_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T4_GATE_ON                      (1 << _T4CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T4_GATE_OFF                     (0)

        // Timer prescaler control - values are mutually exclusive
        #define T4_PS_1_256                     (7 << _T4CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T4_PS_1_64                      (6 << _T4CON_TCKPS_POSITION)    /*           1:64 */
        #define T4_PS_1_32                      (5 << _T4CON_TCKPS_POSITION)    /*           1:32 */
        #define T4_PS_1_16                      (4 << _T4CON_TCKPS_POSITION)    /*           1:16 */
        #define T4_PS_1_8                       (3 << _T4CON_TCKPS_POSITION)    /*           1:8 */
        #define T4_PS_1_4                       (2 << _T4CON_TCKPS_POSITION)    /*           1:4 */
        #define T4_PS_1_2                       (1 << _T4CON_TCKPS_POSITION)    /*           1:2 */
        #define T4_PS_1_1                       (0)                             /*           1:1 */

        // 32-bit or 16-bit option - values are mutually exclusive
        #define T4_32BIT_MODE_ON                (1 << _T4CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T4_32BIT_MODE_OFF               (0)

        // Source selection - values are mutually exclusive
        #define T4_SOURCE_EXT                   (1 << _T4CON_TCS_POSITION)      /* External clock source */
        #define T4_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        void CloseTimer4(void)
 *
 * Description:     Switches off the Timer4
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer4();
 *
 *****************************************************************************/
#define CloseTimer4()   (mT4IntEnable(0), T4CON = 0x0)



/******************************************************************************
 * Function:        void ConfigIntTimer4(unsigned int config)
 *
 * Description:     Configures Timer 4 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T4_INT_XXX, T4_INT_PRIOR_XXX
 *                            and T4_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer4(T4_INT_ON | T4_INT_PRIOR_3 | T4_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer4(config) (mT4ClearIntFlag(), mT4SetIntPriority((config) & 7), \
        mT4SetIntSubPriority(((config) >> 4) & 3),  mT4IntEnable((config) >> 15))


    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T4_INT_ON                       (1<<15)     /* Interrupt Enable */
        #define T4_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T4_INT_PRIOR_7                  (7)
        #define T4_INT_PRIOR_6                  (6)
        #define T4_INT_PRIOR_5                  (5)
        #define T4_INT_PRIOR_4                  (4)
        #define T4_INT_PRIOR_3                  (3)
        #define T4_INT_PRIOR_2                  (2)
        #define T4_INT_PRIOR_1                  (1)
        #define T4_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T4_INT_SUB_PRIOR_3              (3 << 4)
        #define T4_INT_SUB_PRIOR_2              (2 << 4)
        #define T4_INT_SUB_PRIOR_1              (1 << 4)
        #define T4_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT4()
 *
 * Description:     Enables Timer4 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT4;
 *****************************************************************************/
#define EnableIntT4                 mT4IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT4
 *
 * Description:     Disables Timer4 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT4;
 *****************************************************************************/
#define DisableIntT4                mT4IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT4(unsigned int priority)
 *
 * Description:     Sets the priority for Timer 4 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T4_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT4(T4_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT4(priority)  mT4SetIntPriority(priority)


/******************************************************************************
 * Function:        unsigned int ReadTimer4(void)
 *
 * Description:     Returns the current Timer4 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR4 value.
 *
 * Example:         ReadTimer4();
 *
 *****************************************************************************/
#define ReadTimer4()    (TMR4)


/******************************************************************************
 * Function:        void WriteTimer4(unsigned int value)
 *
 * Description:     Loads given value into Timer4 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer4(1234);
 *
 *****************************************************************************/
#define WriteTimer4(value)  TMR4 = value


/******************************************************************************
 * Function:        unsigned int ReadPeriod4(void)
 *
 * Description:     Returns the current Period4 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR4 value.
 *
 * Example:         ReadPeriod4();
 *
 *****************************************************************************/
#define ReadPeriod4()   (PR4)


/******************************************************************************
 * Function:        void WritePeriod4(unsigned int value)
 *
 * Description:     Loads given value into Period4 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod4(1234);
 *
 *****************************************************************************/
#define WritePeriod4(value) PR4 = (value)

#endif  // _TMR4


#if defined _TMR5

/******************************************************************************
 * Function:        void OpenTimer5(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 5
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T5_ON/OFF, T5_IDLE_XXX,
 *                          T5_GATE_XXX, T5_PS_XXX, T5_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer5(T5_ON | T5_IDLE_ON | T5_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer5(config, period)  (T5CON = ((config)&~(T5_ON)), TMR5 = 0, PR5 = (period), T5CONSET=((config)&(T5_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T5_ON                           (1 << _T5CON_ON_POSITION)       /* Timer5 ON */
        #define T5_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T5_IDLE_STOP                    (1 << _T5CON_SIDL_POSITION)     /* stop during idle */
        #define T5_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T5_GATE_ON                      (1 << _T5CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T5_GATE_OFF                     (0)

        // Prescale values - values are mutually exclusive
        #define T5_PS_1_256                     (7 << _T5CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T5_PS_1_64                      (6 << _T5CON_TCKPS_POSITION)    /*           1:64 */
        #define T5_PS_1_32                      (5 << _T5CON_TCKPS_POSITION)    /*           1:32 */
        #define T5_PS_1_16                      (4 << _T5CON_TCKPS_POSITION)    /*           1:16 */
        #define T5_PS_1_8                       (3 << _T5CON_TCKPS_POSITION)    /*           1:8 */
        #define T5_PS_1_4                       (2 << _T5CON_TCKPS_POSITION)    /*           1:4 */
        #define T5_PS_1_2                       (1 << _T5CON_TCKPS_POSITION)    /*           1:2 */
        #define T5_PS_1_1                       (0)                             /*           1:1 */

        // Sync external clock option - values are mutually exclusive
        #define T5_SOURCE_EXT                   (1 << _T5CON_TCS_POSITION)      /* External clock source */
        #define T5_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/

/******************************************************************************
 * Function:        void CloseTimer5(void)
 *
 * Description:     Switches off the Timer5
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer5();
 *
 *****************************************************************************/
#define CloseTimer5()   (mT5IntEnable(0), T5CON = 0x0)



/******************************************************************************
 * Function:        void ConfigIntTimer5(unsigned int config)
 *
 * Description:     Configures Timer 5 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T5_INT_XXX, T5_INT_PRIOR_XXX
 *                            and T5_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer5(T5_INT_ON | T5_INT_PRIOR_3 | T5_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer5(config) (mT5ClearIntFlag(), mT5SetIntPriority((config) & 7), \
        mT5SetIntSubPriority(((config) >> 4) & 3), mT5IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T5_INT_ON                       (1<<15)     /* Interrupt Enable */
        #define T5_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T5_INT_PRIOR_7                  (7)
        #define T5_INT_PRIOR_6                  (6)
        #define T5_INT_PRIOR_5                  (5)
        #define T5_INT_PRIOR_4                  (4)
        #define T5_INT_PRIOR_3                  (3)
        #define T5_INT_PRIOR_2                  (2)
        #define T5_INT_PRIOR_1                  (1)
        #define T5_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T5_INT_SUB_PRIOR_3              (3 << 4)
        #define T5_INT_SUB_PRIOR_2              (2 << 4)
        #define T5_INT_SUB_PRIOR_1              (1 << 4)
        #define T5_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT5()
 *
 * Description:     Enables Timer5 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT5;
 *****************************************************************************/
#define EnableIntT5                 mT5IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT5
 *
 * Description:     Disables Timer5 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT5;
 *****************************************************************************/
#define DisableIntT5                mT5IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT5(unsigned int priority)
 *
 * Description:     Sets the priority for Timer 5 interrupt
  *                 The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
*
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T5_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT5(T5_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT5(priority)  mT5SetIntPriority(priority)


/******************************************************************************
 * Function:        unsigned int ReadTimer5(void)
 *
 * Description:     Returns the current Timer5 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR5 value.
 *
 * Example:         ReadTimer5();
 *
 *****************************************************************************/
#define ReadTimer5()    (TMR5)


/******************************************************************************
 * Function:        void WriteTimer5(unsigned int value)
 *
 * Description:     Loads given value into Timer5 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer5(1234);
 *
 *****************************************************************************/
#define WriteTimer5(value)  TMR5 = value


/******************************************************************************
 * Function:        unsigned int ReadPeriod5(void)
 *
 * Description:     Returns the current Period5 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR5 value.
 *
 * Example:         ReadPeriod5();
 *
 *****************************************************************************/
#define ReadPeriod5()   (PR5)


/******************************************************************************
 * Function:        void WritePeriod5(unsigned int value)
 *
 * Description:     Loads given value into Period5 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod5(1234);
 *
 *****************************************************************************/
#define WritePeriod5(value) PR5 = (value)



/******************************************************************************
 * Function:        void OpenTimer45(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 45 - A 32-bit time by pairing
 *                  Timer 4 & 5.
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T4_ON/OFF, T4_IDLE_XXX,
 *                          T4_GATE_XXX, T4_PS_XXX, T4_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffffffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer45(T4_ON | T4_IDLE_ON | T4_PS_1_4, 123);
 *****************************************************************************/
#define OpenTimer45(config, period) \
( OpenTimer4((config) | T4_32BIT_MODE_ON, (period)))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T45_ON                          (1 << _T4CON_ON_POSITION)       /* Timer4 ON */
        #define T45_OFF                         (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T45_IDLE_STOP                   (1 << _T4CON_SIDL_POSITION)     /* stop during idle */
        #define T45_IDLE_CON                    (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T45_GATE_ON                     (1 << _T4CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T45_GATE_OFF                    (0)

        // Timer prescaler control - values are mutually exclusive
        #define T45_PS_1_256                    (7 << _T4CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T45_PS_1_64                     (6 << _T4CON_TCKPS_POSITION)    /*           1:64 */
        #define T45_PS_1_32                     (5 << _T4CON_TCKPS_POSITION)    /*           1:32 */
        #define T45_PS_1_16                     (4 << _T4CON_TCKPS_POSITION)    /*           1:16 */
        #define T45_PS_1_8                      (3 << _T4CON_TCKPS_POSITION)    /*           1:8 */
        #define T45_PS_1_4                      (2 << _T4CON_TCKPS_POSITION)    /*           1:4 */
        #define T45_PS_1_2                      (1 << _T4CON_TCKPS_POSITION)    /*           1:2 */
        #define T45_PS_1_1                      (0)                             /*           1:1 */

        // 32-bit or 16-bit option - values are mutually exclusive
        #define T45_32BIT_MODE_ON               (1 << _T4CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T45_32BIT_MODE_OFF              (0)

        // Source selection - values are mutually exclusive
        #define T45_SOURCE_EXT                  (1 << _T4CON_TCS_POSITION)      /* External clock source */
        #define T45_SOURCE_INT                  (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/

/******************************************************************************
 * Function:        CloseTimer45()
 *
 * Description:     Switches off the 32-bit Timer45
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer45();
 *
 *****************************************************************************/
#define CloseTimer45()  (CloseTimer4(), CloseTimer5())


/******************************************************************************
 * Function:        void ConfigIntTimer45(unsigned int config)
 *
 * Description:     Configures the 32-bit Timer45 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T4_INT_XXX, T4_INT_PRIOR_XXX
 *                            and T4_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer45(T4_INT_ON | T4_INT_PRIOR_3 | T4_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer45(config)    ConfigIntTimer5(config)

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T45_INT_ON                      (1<<15)     /* Interrupt Enable */
        #define T45_INT_OFF                     (0)

        // Interrupt priority - values are mutually exclusive
        #define T45_INT_PRIOR_7                  (7)
        #define T45_INT_PRIOR_6                  (6)
        #define T45_INT_PRIOR_5                  (5)
        #define T45_INT_PRIOR_4                  (4)
        #define T45_INT_PRIOR_3                  (3)
        #define T45_INT_PRIOR_2                  (2)
        #define T45_INT_PRIOR_1                  (1)
        #define T45_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T45_INT_SUB_PRIOR_3              (3 << 4)
        #define T45_INT_SUB_PRIOR_2              (2 << 4)
        #define T45_INT_SUB_PRIOR_1              (1 << 4)
        #define T45_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT45
 *
 * Description:     Enables the 32-bit Timer45 interrupt(Timer5 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT45;
 *****************************************************************************/
#define EnableIntT45                EnableIntT5


/******************************************************************************
 * Function:        DisableIntT45
 *
 * Description:     Disables 32-bit Timer45 interrupt(Timer5 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT45;
 *****************************************************************************/
#define DisableIntT45               DisableIntT5


/******************************************************************************
 * Function:        void SetPriorityIntT45(int priority)
 *
 * Description:     Sets the priority for 32-bit Timer 45 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *                  Timer5 interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T4_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT45(T4_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT45(priority) SetPriorityIntT5(priority)


/******************************************************************************
 * Function:        unsigned int ReadTimer45(void)
 *
 * Description:     Returns the current 32-bit Timer45 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          The current 32-bit timer value.
 *
 * Example:         ReadTimer45();
 *
 *****************************************************************************/
#define ReadTimer45()   ReadTimer4()


/******************************************************************************
 * Function:        void WriteTimer45(unsigned int value)
 *
 * Description:     Loads given value into 32-bit Timer45 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer45(1234);
 *
 *****************************************************************************/
#define WriteTimer45(value) WriteTimer4(value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod45(void)
 *
 * Description:     Returns the current Period45 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR4 value.
 *
 * Example:         ReadPeriod45();
 *
 *****************************************************************************/
#define ReadPeriod45()  PR4


/******************************************************************************
 * Function:        void WritePeriod45(unsigned int value)
 *
 * Description:     Loads given value into Period45 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod45(1234);
 *
 *****************************************************************************/
#define WritePeriod45(value)    PR4 = (value)

#endif      // _TMR5

#if defined _TMR6

/******************************************************************************
 * Function:        void OpenTimer6(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 6
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T6_ON/OFF, T6_IDLE_XXX,
 *                          T6_GATE_XXX, T6_PS_XXX, T6_32BIT_MODE_ON, and
 *                          T6_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer6(T6_ON | T6_IDLE_ON | T6_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer6(config, period)  (T6CON = ((config)&~(T6_ON)), TMR6 = 0, PR6 = (period), T6CONSET=((config)&(T6_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T6_ON                           (1 << _T6CON_ON_POSITION)       /* Timer6 ON */
        #define T6_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T6_IDLE_STOP                    (1 << _T6CON_SIDL_POSITION)     /* stop during idle */
        #define T6_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T6_GATE_ON                      (1 << _T6CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T6_GATE_OFF                     (0)

        // Prescale values - values are mutually exclusive
        #define T6_PS_1_256                     (7 << _T6CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T6_PS_1_64                      (6 << _T6CON_TCKPS_POSITION)    /*           1:64 */
        #define T6_PS_1_32                      (5 << _T6CON_TCKPS_POSITION)    /*           1:32 */
        #define T6_PS_1_16                      (4 << _T6CON_TCKPS_POSITION)    /*           1:16 */
        #define T6_PS_1_8                       (3 << _T6CON_TCKPS_POSITION)    /*           1:8 */
        #define T6_PS_1_4                       (2 << _T6CON_TCKPS_POSITION)    /*           1:4 */
        #define T6_PS_1_2                       (1 << _T6CON_TCKPS_POSITION)    /*           1:2 */
        #define T6_PS_1_1                       (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T6_32BIT_MODE_ON                (1 << _T6CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T6_32BIT_MODE_OFF               (0)

        // Sync external clock option - values are mutually exclusive
        #define T6_SOURCE_EXT                   (1 << _T6CON_TCS_POSITION)      /* External clock source */
        #define T6_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        CloseTimer6()
 *
 * Description:     Switches off the Timer6
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer6();
 *
 *****************************************************************************/
#define CloseTimer6()   (mT6IntEnable(0), T6CON = 0)


/******************************************************************************
 * Function:        void ConfigIntTimer6(unsigned int config)
 *
 * Description:     Configures Timer 6 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T6_INT_XXX, T6_INT_PRIOR_XXX
 *                            and T6_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer6(T6_INT_ON | T6_INT_PRIOR_3 | T6_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer6(config) (mT6ClearIntFlag(), mT6SetIntPriority(((config) & 7)),\
        mT6SetIntSubPriority(((config) >> 4) & 3), mT6IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T6_INT_ON                       (1 << 15)       /* T6 Interrupt Enable */
        #define T6_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T6_INT_PRIOR_7                  (7)
        #define T6_INT_PRIOR_6                  (6)
        #define T6_INT_PRIOR_5                  (5)
        #define T6_INT_PRIOR_4                  (4)
        #define T6_INT_PRIOR_3                  (3)
        #define T6_INT_PRIOR_2                  (2)
        #define T6_INT_PRIOR_1                  (1)
        #define T6_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T6_INT_SUB_PRIOR_3              (3 << 4)
        #define T6_INT_SUB_PRIOR_2              (2 << 4)
        #define T6_INT_SUB_PRIOR_1              (1 << 4)
        #define T6_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT6
 *
 * Description:     Enables Timer6 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT6;
 *****************************************************************************/
#define EnableIntT6                 mT6IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT6
 *
 * Description:     Disables Timer6 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT6;
 *****************************************************************************/
#define DisableIntT6                mT6IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT6(int priority)
 *
 * Description:     Sets the priority for Timer 6 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T6_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT6(T6_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT6(priority)  mT6SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer6(void)
 *
 * Description:     Returns the current Timer6 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR6 value.
 *
 * Example:         ReadTimer6();
 *
 *****************************************************************************/
#define ReadTimer6()    (TMR6)


/******************************************************************************
 * Function:        void WriteTimer6(unsigned int value)
 *
 * Description:     Loads given value into Timer6 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer6(1234);
 *
 *****************************************************************************/
#define WriteTimer6(value)  TMR6 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod6(void)
 *
 * Description:     Returns the current Period6 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR6 value.
 *
 * Example:         ReadPeriod6();
 *
 *****************************************************************************/
#define ReadPeriod6()   (PR6)


/******************************************************************************
 * Function:        void WritePeriod6(unsigned int value)
 *
 * Description:     Loads given value into Period6 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod6(1234);
 *
 *****************************************************************************/
#define WritePeriod6(value) PR6 = ((value))



#endif  // _TMR6


#if defined _TMR7

/******************************************************************************
 * Function:        void OpenTimer7(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 7
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T7_ON/OFF, T7_IDLE_XXX,
 *                          T7_GATE_XXX, T7_PS_XXX, T7_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer7(T7_ON | T7_IDLE_ON | T7_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer7(config, period)  (T7CON = ((config)&~(T7_ON)), TMR7 = 0, PR7 = (period), T7CONSET=((config)&(T7_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T7_ON                           (1 << _T7CON_ON_POSITION)       /* Timer7 ON */
        #define T7_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T7_IDLE_STOP                    (1 << _T7CON_SIDL_POSITION)     /* stop during idle */
        #define T7_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T7_GATE_ON                      (1 << _T7CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T7_GATE_OFF                     (0)

        // Timer prescaler control - values are mutually exclusive
        #define T7_PS_1_256                     (7 << _T7CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T7_PS_1_64                      (6 << _T7CON_TCKPS_POSITION)    /*           1:64 */
        #define T7_PS_1_32                      (5 << _T7CON_TCKPS_POSITION)    /*           1:32 */
        #define T7_PS_1_16                      (4 << _T7CON_TCKPS_POSITION)    /*           1:16 */
        #define T7_PS_1_8                       (3 << _T7CON_TCKPS_POSITION)    /*           1:8 */
        #define T7_PS_1_4                       (2 << _T7CON_TCKPS_POSITION)    /*           1:4 */
        #define T7_PS_1_2                       (1 << _T7CON_TCKPS_POSITION)    /*           1:2 */
        #define T7_PS_1_1                       (0)                             /*           1:1 */

        // Source selection - values are mutually exclusive
        #define T7_SOURCE_EXT                   (1 << _T7CON_TCS_POSITION)      /* External clock source */
        #define T7_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        CloseTimer7()
 *
 * Description:     Switches off the Timer7
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer7();
 *
 *****************************************************************************/
#define CloseTimer7()   (mT7IntEnable(0), T7CON = 0)



/******************************************************************************
 * Function:        void ConfigIntTimer7(unsigned int config)
 *
 * Description:     Configures Timer 7 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T7_INT_XXX, T7_INT_PRIOR_XXX
 *                            and T7_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer7(T7_INT_ON | T7_INT_PRIOR_3 | T7_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer7(config) (mT7ClearIntFlag(), mT7SetIntPriority(((config) & 7)),\
        mT7SetIntSubPriority(((config) >> 4) & 3), mT7IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T7_INT_ON                       (1<<15)     /* Interrupt Enable */
        #define T7_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T7_INT_PRIOR_7                  (7)
        #define T7_INT_PRIOR_6                  (6)
        #define T7_INT_PRIOR_5                  (5)
        #define T7_INT_PRIOR_4                  (4)
        #define T7_INT_PRIOR_3                  (3)
        #define T7_INT_PRIOR_2                  (2)
        #define T7_INT_PRIOR_1                  (1)
        #define T7_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T7_INT_SUB_PRIOR_3              (3 << 4)
        #define T7_INT_SUB_PRIOR_2              (2 << 4)
        #define T7_INT_SUB_PRIOR_1              (1 << 4)
        #define T7_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT7()
 *
 * Description:     Enables Timer7 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT7;
 *****************************************************************************/
#define EnableIntT7                 mT7IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT7
 *
 * Description:     Disables Timer7 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT7;
 *****************************************************************************/
#define DisableIntT7                mT7IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT7(unsigned int priority)
 *
 * Description:     Sets the priority for Timer 7 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T7_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT7(T7_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT7(priority)  mT7SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer7(void)
 *
 * Description:     Returns the current Timer7 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR7 value.
 *
 * Example:         ReadTimer7();
 *
 *****************************************************************************/
#define ReadTimer7()    (TMR7)


/******************************************************************************
 * Function:        void WriteTimer7(unsigned int value)
 *
 * Description:     Loads given value into Timer7 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer7(1234);
 *
 *****************************************************************************/
#define WriteTimer7(value)  TMR7 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod7(void)
 *
 * Description:     Returns the current Period7 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR7 value.
 *
 * Example:         ReadPeriod7();
 *
 *****************************************************************************/
#define ReadPeriod7()   (PR7)


/******************************************************************************
 * Function:        void WritePeriod7(unsigned int value)
 *
 * Description:     Loads given value into Period7 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod7(1234);
 *
 *****************************************************************************/
#define WritePeriod7(value) PR7 = ((value))



/******************************************************************************
 * Function:        void OpenTimer67(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 67 - A 32-bit time by pairing
 *                  Timer 6 & 7.
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T67_ON/OFF, T67_IDLE_XXX,
 *                          T67_GATE_XXX, T67_PS_XXX, T67_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffffffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer67(T67_ON | T67_IDLE_ON | T67_PS_1_4, 123);
 *****************************************************************************/
#define OpenTimer67(config, period) \
( OpenTimer6((config) | T6_32BIT_MODE_ON, (period)))

/******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T67_ON                          (1 << _T6CON_ON_POSITION)       /* Timer67 ON */
        #define T67_OFF                         (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T67_IDLE_STOP                   (1 << _T6CON_SIDL_POSITION)     /* stop during idle */
        #define T67_IDLE_CON                    (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T67_GATE_ON                     (1 << _T6CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T67_GATE_OFF                    (0)

        // Prescale values - values are mutually exclusive
        #define T67_PS_1_256                    (7 << _T6CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T67_PS_1_64                     (6 << _T6CON_TCKPS_POSITION)    /*           1:64 */
        #define T67_PS_1_32                     (5 << _T6CON_TCKPS_POSITION)    /*           1:32 */
        #define T67_PS_1_16                     (4 << _T6CON_TCKPS_POSITION)    /*           1:16 */
        #define T67_PS_1_8                      (3 << _T6CON_TCKPS_POSITION)    /*           1:8 */
        #define T67_PS_1_4                      (2 << _T6CON_TCKPS_POSITION)    /*           1:4 */
        #define T67_PS_1_2                      (1 << _T6CON_TCKPS_POSITION)    /*           1:2 */
        #define T67_PS_1_1                      (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T67_32BIT_MODE_ON               (1 << _T6CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T67_32BIT_MODE_OFF              (0)

        // Sync external clock option - values are mutually exclusive
        #define T67_SOURCE_EXT                  (1 << _T6CON_TCS_POSITION)      /* External clock source */
        #define T67_SOURCE_INT                  (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/

/******************************************************************************
 * Function:        CloseTimer67()
 *
 * Description:     Switches off the 32-bit Timer67
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer67();
 *
 *****************************************************************************/
#define CloseTimer67()  (CloseTimer6(), CloseTimer7())


/******************************************************************************
 * Function:        void ConfigIntTimer67(unsigned int config)
 *
 * Description:     Configures the 32-bit Timer67 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T67_INT_XXX, T67_INT_PRIOR_XXX
 *                            and T67_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer67(T23_INT_ON | T67_INT_PRIOR_3 | T67_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer67(config)    ConfigIntTimer7((config))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T67_INT_ON                      (1<<15)     /* Interrupt Enable */
        #define T67_INT_OFF                     (0)

        // Interrupt priority - values are mutually exclusive
        #define T67_INT_PRIOR_7                  (7)
        #define T67_INT_PRIOR_6                  (6)
        #define T67_INT_PRIOR_5                  (5)
        #define T67_INT_PRIOR_4                  (4)
        #define T67_INT_PRIOR_3                  (3)
        #define T67_INT_PRIOR_2                  (2)
        #define T67_INT_PRIOR_1                  (1)
        #define T67_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T67_INT_SUB_PRIOR_3              (3 << 4)
        #define T67_INT_SUB_PRIOR_2              (2 << 4)
        #define T67_INT_SUB_PRIOR_1              (1 << 4)
        #define T67_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT67()
 *
 * Description:     Enables the 32-bit Timer67 interrupt(Timer7 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT67;
 *****************************************************************************/
#define EnableIntT67                EnableIntT7


/******************************************************************************
 * Function:        DisableIntT67
 *
 * Description:     Disables 32-bit Timer67 interrupt(Timer7 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT67;
 *****************************************************************************/
#define DisableIntT67               DisableIntT7


/******************************************************************************
 * Function:        void SetPriorityIntT67(unsigned int priority)
 *
 * Description:     Sets the priority for 32-bit Timer 67 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *                  Interrupts are Timer3.
 *

 * PreCondition:    None
 *
 * Inputs:          priority : A value of T6_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT67(T6_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT67(priority) SetPriorityIntT7((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer67(void)
 *
 * Description:     Returns the current 32-bit Timer67 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          The current 32-bit timer value.
 *
 * Example:         ReadTimer67();
 *
 *****************************************************************************/
#define ReadTimer67()   ReadTimer6()


/******************************************************************************
 * Function:        void WriteTimer67(unsigned int value)
 *
 * Description:     Loads given value into 32-bit Timer67 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer67(1234);
 *
 *****************************************************************************/
#define WriteTimer67(value) WriteTimer6((value))


/******************************************************************************
 * Function:        unsigned int ReadPeriod67(void)
 *
 * Description:     Returns the current Period67 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR6 value.
 *
 * Example:         ReadPeriod67();
 *
 *****************************************************************************/
#define ReadPeriod67()  (PR6)


/******************************************************************************
 * Function:        void WritePeriod67(unsigned int value)
 *
 * Description:     Loads given value into Period67 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod67(1234);
 *
 *****************************************************************************/
#define WritePeriod67(value)    PR6 = (value)

#endif // _TMR7

#if defined _TMR8

/******************************************************************************
 * Function:        void OpenTimer8(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 8
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T8_ON/OFF, T8_IDLE_XXX,
 *                          T8_GATE_XXX, T8_PS_XXX, T8_32BIT_MODE_ON, and
 *                          T8_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer8(T8_ON | T8_IDLE_ON | T8_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer8(config, period)  (T8CON = ((config)&~(T8_ON)), TMR8 = 0, PR8 = (period), T8CONSET=((config)&(T8_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T8_ON                           (1 << _T8CON_ON_POSITION)       /* Timer8 ON */
        #define T8_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T8_IDLE_STOP                    (1 << _T8CON_SIDL_POSITION)     /* stop during idle */
        #define T8_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T8_GATE_ON                      (1 << _T8CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T8_GATE_OFF                     (0)

        // Prescale values - values are mutually exclusive
        #define T8_PS_1_256                     (7 << _T8CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T8_PS_1_64                      (6 << _T8CON_TCKPS_POSITION)    /*           1:64 */
        #define T8_PS_1_32                      (5 << _T8CON_TCKPS_POSITION)    /*           1:32 */
        #define T8_PS_1_16                      (4 << _T8CON_TCKPS_POSITION)    /*           1:16 */
        #define T8_PS_1_8                       (3 << _T8CON_TCKPS_POSITION)    /*           1:8 */
        #define T8_PS_1_4                       (2 << _T8CON_TCKPS_POSITION)    /*           1:4 */
        #define T8_PS_1_2                       (1 << _T8CON_TCKPS_POSITION)    /*           1:2 */
        #define T8_PS_1_1                       (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T8_32BIT_MODE_ON                (1 << _T8CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T8_32BIT_MODE_OFF               (0)

        // Sync external clock option - values are mutually exclusive
        #define T8_SOURCE_EXT                   (1 << _T8CON_TCS_POSITION)      /* External clock source */
        #define T8_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        CloseTimer8()
 *
 * Description:     Switches off the Timer8
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer8();
 *
 *****************************************************************************/
#define CloseTimer8()   (mT8IntEnable(0), T8CON = 0)


/******************************************************************************
 * Function:        void ConfigIntTimer8(unsigned int config)
 *
 * Description:     Configures Timer 8 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T8_INT_XXX, T8_INT_PRIOR_XXX
 *                            and T8_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer8(T8_INT_ON | T8_INT_PRIOR_3 | T8_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer8(config) (mT8ClearIntFlag(), mT8SetIntPriority(((config) & 7)),\
        mT8SetIntSubPriority(((config) >> 4) & 3), mT8IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T8_INT_ON                       (1 << 15)       /* T8 Interrupt Enable */
        #define T8_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T8_INT_PRIOR_7                  (7)
        #define T8_INT_PRIOR_6                  (6)
        #define T8_INT_PRIOR_5                  (5)
        #define T8_INT_PRIOR_4                  (4)
        #define T8_INT_PRIOR_3                  (3)
        #define T8_INT_PRIOR_2                  (2)
        #define T8_INT_PRIOR_1                  (1)
        #define T8_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T8_INT_SUB_PRIOR_3              (3 << 4)
        #define T8_INT_SUB_PRIOR_2              (2 << 4)
        #define T8_INT_SUB_PRIOR_1              (1 << 4)
        #define T8_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT8
 *
 * Description:     Enables Timer8 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT8;
 *****************************************************************************/
#define EnableIntT8                 mT8IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT8
 *
 * Description:     Disables Timer8 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT2;
 *****************************************************************************/
#define DisableIntT8                mT8IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT8(int priority)
 *
 * Description:     Sets the priority for Timer 8 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T8_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT8(T8_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT8(priority)  mT8SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer8(void)
 *
 * Description:     Returns the current Timer8 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR8 value.
 *
 * Example:         ReadTimer8();
 *
 *****************************************************************************/
#define ReadTimer8()    (TMR8)


/******************************************************************************
 * Function:        void WriteTimer8(unsigned int value)
 *
 * Description:     Loads given value into Timer8 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer8(1234);
 *
 *****************************************************************************/
#define WriteTimer8(value)  TMR8 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod8(void)
 *
 * Description:     Returns the current Period8 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR8 value.
 *
 * Example:         ReadPeriod8();
 *
 *****************************************************************************/
#define ReadPeriod8()   (PR8)


/******************************************************************************
 * Function:        void WritePeriod8(unsigned int value)
 *
 * Description:     Loads given value into Period8 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod8(1234);
 *
 *****************************************************************************/
#define WritePeriod8(value) PR8 = ((value))



#endif  // _TMR8


#if defined _TMR9

/******************************************************************************
 * Function:        void OpenTimer9(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 9
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T9_ON/OFF, T9_IDLE_XXX,
 *                          T9_GATE_XXX, T9_PS_XXX, T9_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer9(T9_ON | T9_IDLE_ON | T9_PS_1_4, 123);
 *
 *****************************************************************************/
#define OpenTimer9(config, period)  (T9CON = ((config)&~(T9_ON)), TMR9 = 0, PR9 = (period), T9CONSET=((config)&(T9_ON)) )

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T9_ON                           (1 << _T9CON_ON_POSITION)       /* Timer9 ON */
        #define T9_OFF                          (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T9_IDLE_STOP                    (1 << _T9CON_SIDL_POSITION)     /* stop during idle */
        #define T9_IDLE_CON                     (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T9_GATE_ON                      (1 << _T9CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T9_GATE_OFF                     (0)

        // Timer prescaler control - values are mutually exclusive
        #define T9_PS_1_256                     (7 << _T9CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T9_PS_1_64                      (6 << _T9CON_TCKPS_POSITION)    /*           1:64 */
        #define T9_PS_1_32                      (5 << _T9CON_TCKPS_POSITION)    /*           1:32 */
        #define T9_PS_1_16                      (4 << _T9CON_TCKPS_POSITION)    /*           1:16 */
        #define T9_PS_1_8                       (3 << _T9CON_TCKPS_POSITION)    /*           1:8 */
        #define T9_PS_1_4                       (2 << _T9CON_TCKPS_POSITION)    /*           1:4 */
        #define T9_PS_1_2                       (1 << _T9CON_TCKPS_POSITION)    /*           1:2 */
        #define T9_PS_1_1                       (0)                             /*           1:1 */

        // Source selection - values are mutually exclusive
        #define T9_SOURCE_EXT                   (1 << _T9CON_TCS_POSITION)      /* External clock source */
        #define T9_SOURCE_INT                   (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        CloseTimer9()
 *
 * Description:     Switches off the Timer9
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer9();
 *
 *****************************************************************************/
#define CloseTimer9()   (mT9IntEnable(0), T9CON = 0)



/******************************************************************************
 * Function:        void ConfigIntTimer9(unsigned int config)
 *
 * Description:     Configures Timer 9 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T9_INT_XXX, T9_INT_PRIOR_XXX
 *                            and T9_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer9(T9_INT_ON | T9_INT_PRIOR_3 | T9_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer9(config) (mT9ClearIntFlag(), mT9SetIntPriority(((config) & 7)),\
        mT9SetIntSubPriority(((config) >> 4) & 3), mT9IntEnable((config) >> 15))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T9_INT_ON                       (1<<15)     /* Interrupt Enable */
        #define T9_INT_OFF                      (0)

        // Interrupt priority - values are mutually exclusive
        #define T9_INT_PRIOR_7                  (7)
        #define T9_INT_PRIOR_6                  (6)
        #define T9_INT_PRIOR_5                  (5)
        #define T9_INT_PRIOR_4                  (4)
        #define T9_INT_PRIOR_3                  (3)
        #define T9_INT_PRIOR_2                  (2)
        #define T9_INT_PRIOR_1                  (1)
        #define T9_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T9_INT_SUB_PRIOR_3              (3 << 4)
        #define T9_INT_SUB_PRIOR_2              (2 << 4)
        #define T9_INT_SUB_PRIOR_1              (1 << 4)
        #define T9_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/


/******************************************************************************
 * Function:        EnableIntT9()
 *
 * Description:     Enables Timer9 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT9;
 *****************************************************************************/
#define EnableIntT9                 mT9IntEnable(1)


/******************************************************************************
 * Function:        DisableIntT9
 *
 * Description:     Disables Timer9 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT9;
 *****************************************************************************/
#define DisableIntT9                mT9IntEnable(0)


/******************************************************************************
 * Function:        void SetPriorityIntT9(unsigned int priority)
 *
 * Description:     Sets the priority for Timer 9 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *
 * PreCondition:    None
 *
 * Inputs:          priority : A value of T9_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT9(T9_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT9(priority)  mT9SetIntPriority((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer9(void)
 *
 * Description:     Returns the current Timer9 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          TMR9 value.
 *
 * Example:         ReadTimer9();
 *
 *****************************************************************************/
#define ReadTimer9()    (TMR9)


/******************************************************************************
 * Function:        void WriteTimer9(unsigned int value)
 *
 * Description:     Loads given value into Timer9 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer9(1234);
 *
 *****************************************************************************/
#define WriteTimer9(value)  TMR9 = (value)


/******************************************************************************
 * Function:        unsigned int ReadPeriod9(void)
 *
 * Description:     Returns the current Period9 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR9 value.
 *
 * Example:         ReadPeriod9();
 *
 *****************************************************************************/
#define ReadPeriod9()   (PR9)


/******************************************************************************
 * Function:        void WritePeriod9(unsigned int value)
 *
 * Description:     Loads given value into Period9 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod9(1234);
 *
 *****************************************************************************/
#define WritePeriod9(value) PR9 = ((value))



/******************************************************************************
 * Function:        void OpenTimer89(unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer 89 - A 32-bit time by pairing
 *                  Timer 8 & 9.
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T89_ON/OFF, T89_IDLE_XXX,
 *                          T89_GATE_XXX, T89_PS_XXX, T89_SOURCE_XXX.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffffffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer89(T89_ON | T89_IDLE_ON | T89_PS_1_4, 123);
 *****************************************************************************/
#define OpenTimer89(config, period) \
( OpenTimer8((config) | T8_32BIT_MODE_ON, (period)))

/******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T89_ON                          (1 << _T8CON_ON_POSITION)       /* Timer89 ON */
        #define T89_OFF                         (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T89_IDLE_STOP                   (1 << _T8CON_SIDL_POSITION)     /* stop during idle */
        #define T89_IDLE_CON                    (0)                             /* operate during idle */

        // Timer gate control - values are mutually exclusive
        #define T89_GATE_ON                     (1 << _T8CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T89_GATE_OFF                    (0)

        // Prescale values - values are mutually exclusive
        #define T89_PS_1_256                    (7 << _T8CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T89_PS_1_64                     (6 << _T8CON_TCKPS_POSITION)    /*           1:64 */
        #define T89_PS_1_32                     (5 << _T8CON_TCKPS_POSITION)    /*           1:32 */
        #define T89_PS_1_16                     (4 << _T8CON_TCKPS_POSITION)    /*           1:16 */
        #define T89_PS_1_8                      (3 << _T8CON_TCKPS_POSITION)    /*           1:8 */
        #define T89_PS_1_4                      (2 << _T8CON_TCKPS_POSITION)    /*           1:4 */
        #define T89_PS_1_2                      (1 << _T8CON_TCKPS_POSITION)    /*           1:2 */
        #define T89_PS_1_1                      (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T89_32BIT_MODE_ON               (1 << _T8CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T89_32BIT_MODE_OFF              (0)

        // Sync external clock option - values are mutually exclusive
        #define T89_SOURCE_EXT                  (1 << _T8CON_TCS_POSITION)      /* External clock source */
        #define T89_SOURCE_INT                  (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/

/******************************************************************************
 * Function:        CloseTimer89()
 *
 * Description:     Switches off the 32-bit Timer89
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer89();
 *
 *****************************************************************************/
#define CloseTimer89()  (CloseTimer8(), CloseTimer9())


/******************************************************************************
 * Function:        void ConfigIntTimer89(unsigned int config)
 *
 * Description:     Configures the 32-bit Timer89 interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T89_INT_XXX, T89_INT_PRIOR_XXX
 *                            and T89_INT_SUB_PRIOR_X
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer89(T89_INT_ON | T89_INT_PRIOR_3 | T89_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
#define ConfigIntTimer89(config)    ConfigIntTimer9((config))

    /******************************************************************************
     * Available options for config parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T89_INT_ON                      (1<<15)     /* Interrupt Enable */
        #define T89_INT_OFF                     (0)

        // Interrupt priority - values are mutually exclusive
        #define T89_INT_PRIOR_7                  (7)
        #define T89_INT_PRIOR_6                  (6)
        #define T89_INT_PRIOR_5                  (5)
        #define T89_INT_PRIOR_4                  (4)
        #define T89_INT_PRIOR_3                  (3)
        #define T89_INT_PRIOR_2                  (2)
        #define T89_INT_PRIOR_1                  (1)
        #define T89_INT_PRIOR_0                  (0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T89_INT_SUB_PRIOR_3              (3 << 4)
        #define T89_INT_SUB_PRIOR_2              (2 << 4)
        #define T89_INT_SUB_PRIOR_1              (1 << 4)
        #define T89_INT_SUB_PRIOR_0              (0 << 4)
    /***********************************
     * End config parameter values
     ************************************/



/******************************************************************************
 * Function:        EnableIntT89()
 *
 * Description:     Enables the 32-bit Timer89 interrupt(Timer9 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableIntT89;
 *****************************************************************************/
#define EnableIntT89                EnableIntT9


/******************************************************************************
 * Function:        DisableIntT89
 *
 * Description:     Disables 32-bit Timer89 interrupt(Timer9 interrupt)
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableIntT89;
 *****************************************************************************/
#define DisableIntT89               DisableIntT9


/******************************************************************************
 * Function:        void SetPriorityIntT89(unsigned int priority)
 *
 * Description:     Sets the priority for 32-bit Timer 89 interrupt
 *                  The OpenTimerx() sets the priority. Use this
 *                  macro to change the previously set priority
 *                  without any need to respecify other parameters.
 *                  Interrupts are Timer9.
 *

 * PreCondition:    None
 *
 * Inputs:          priority : A value of T89_INT_PRIOR_XXX
 *
 * Output:          None
 *
 * Example:         SetPriorityIntT89(T89_INT_PRIORITY_3);
 *****************************************************************************/
#define SetPriorityIntT89(priority) SetPriorityIntT9((priority))


/******************************************************************************
 * Function:        unsigned int ReadTimer89(void)
 *
 * Description:     Returns the current 32-bit Timer89 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          The current 32-bit timer value.
 *
 * Example:         ReadTimer89();
 *
 *****************************************************************************/
#define ReadTimer89()   ReadTimer8()


/******************************************************************************
 * Function:        void WriteTimer89(unsigned int value)
 *
 * Description:     Loads given value into 32-bit Timer89 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WriteTimer89(1234);
 *
 *****************************************************************************/
#define WriteTimer89(value) WriteTimer8((value))


/******************************************************************************
 * Function:        unsigned int ReadPeriod89(void)
 *
 * Description:     Returns the current Period89 value.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          PR8 value.
 *
 * Example:         ReadPeriod89();
 *
 *****************************************************************************/
#define ReadPeriod89()  (PR8)


/******************************************************************************
 * Function:        void WritePeriod89(unsigned int value)
 *
 * Description:     Loads given value into Period89 register.
 *
 * PreCondition:    None
 *
 * Inputs:          value: The value to be loaded.
 *
 * Output:          None
 *
 * Example:         WritePeriod89(1234);
 *
 *****************************************************************************/
#define WritePeriod89(value)    PR8 = (value)

#endif // _TMR9


/******************************************************************************
     * Available options for config Timer parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define T_ON                          (1 << _T2CON_ON_POSITION)       /* Timer89 ON */
        #define T_OFF                         (0)

        // Stop-in-idle control - values are mutually exclusive
        #define T_IDLE_STOP                   (1 << _T2CON_SIDL_POSITION)     /* stop during idle */
        #define T_IDLE_CON                    (0)                             /* operate during idle */

        // Asynchronous write control - values are mutually exclusive
        #define T_TMWDIS_ON                    (1 << _T1CON_TWDIS_POSITION)    /* Asynchronous Write Disable */
        #define T_TMWDIS_OFF                   (0)				
				
        // Timer gate control - values are mutually exclusive
        #define T_GATE_ON                     (1 << _T2CON_TGATE_POSITION)    /* Timer Gate accumulation mode ON */
        #define T_GATE_OFF                    (0)

        // Prescale values - values are mutually exclusive
        #define T_PS_1_256                    (7 << _T2CON_TCKPS_POSITION)    /* Prescaler 1:256 */
        #define T_PS_1_64                     (6 << _T2CON_TCKPS_POSITION)    /*           1:64 */
        #define T_PS_1_32                     (5 << _T2CON_TCKPS_POSITION)    /*           1:32 */
        #define T_PS_1_16                     (4 << _T2CON_TCKPS_POSITION)    /*           1:16 */
        #define T_PS_1_8                      (3 << _T2CON_TCKPS_POSITION)    /*           1:8 */
        #define T_PS_1_4                      (2 << _T2CON_TCKPS_POSITION)    /*           1:4 */
        #define T_PS_1_2                      (1 << _T2CON_TCKPS_POSITION)    /*           1:2 */
        #define T_PS_1_1                      (0)                             /*           1:1 */

        // 32-bit or 16-bit - values are mutually exclusive
        #define T_32BIT_MODE_ON               (1 << _T2CON_T32_POSITION)      /* Enable 32-bit mode */
        #define T_32BIT_MODE_OFF              (0)

        // Sync option - values are mutually exclusive
        #define T_SYNC_EXT_ON                  (1 << _T1CON_TSYNC_POSITION)    /* Synch external clk input */
        #define T_SYNC_EXT_OFF                 (0)	 				
				
        // Sync external clock option - values are mutually exclusive
        #define T_SOURCE_EXT                  (1 << _T2CON_TCS_POSITION)      /* External clock source */
        #define T_SOURCE_INT                  (0)                             /* Internal clock source */
    /***********************************
     * End config parameter values
     ************************************/
		 
    /******************************************************************************
     * Available options for config INT Timer parameter
     *****************************************************************************/
        // Interrupt on/off - values are mutually exclusive
        #define T_INT_ON												(1 << 15)       /* TIMx Interrupt Enable */
        #define T_INT_OFF                      	(0)

        // Interrupt priority - values are mutually exclusive
        #define T_INT_PRIOR_7                  	(7)
        #define T_INT_PRIOR_6                  	(6)
        #define T_INT_PRIOR_5                  	(5)
        #define T_INT_PRIOR_4                  	(4)
        #define T_INT_PRIOR_3                  	(3)
        #define T_INT_PRIOR_2                  	(2)
        #define T_INT_PRIOR_1                  	(1)
        #define T_INT_PRIOR_0                  	(0)

        // Interrupt sub-priority - values are mutually exclusive
        #define T_INT_SUB_PRIOR_3              	(3 << 4)
        #define T_INT_SUB_PRIOR_2              	(2 << 4)
        #define T_INT_SUB_PRIOR_1              	(1 << 4)
        #define T_INT_SUB_PRIOR_0              	(0 << 4)
    /***********************************
     * End config parameter values
     ************************************/

/*********************************************************************
 * Timer X Interrupt Control Functions
 ********************************************************************/
extern inline void __attribute__((always_inline)) 
mTClearIntFlag( TIMER_MODULE id ) 
{
	volatile unsigned int	*ifsx_clr;
    unsigned int            mask;
    
	if( TIMER_NUMBER_OF_MODULES < id ) return;  
    
    if( TIMER7 > id)
    {
        ifsx_clr 	= (volatile UINT *)(0xBF810044);                            //IFS0CLR
        if( TIMER6 > id)
        {
            mask 	= 1<<(4+(5*id));
        }
        else
        {
            mask 	= _IFS0_T6IF_MASK;
        }
    }
    else
    {
        ifsx_clr 	= (volatile UINT *)(0xBF810054);                            //IFS1CLR
        mask 	= 1<<(4*(id-6));
    }
    *ifsx_clr = mask;
}

extern inline unsigned int __attribute__((always_inline)) 
mTGetIntFlag( TIMER_MODULE id ) 
{
	volatile unsigned int	*ifsx;
    unsigned int            mask;
    
	if( TIMER_NUMBER_OF_MODULES < id ) return 0;    
    
    if( TIMER7 > id)
    {
        ifsx 	= (volatile UINT *)(0xBF810040);                                //IFS0
        if( TIMER6 > id)
        {
            mask 	= 1<<(4+(5*id));
        }
        else
        {
            mask 	= _IFS0_T6IF_MASK;
        }
    }
    else
    {
        ifsx 	= (volatile UINT *)(0xBF810050);                                //IFS1
        mask 	= 1<<(4*(id-6));
    }    
    return (*ifsx & mask);
}

extern inline unsigned int __attribute__((always_inline)) 
mTGetIntEnable( TIMER_MODULE id )
{
	volatile unsigned int	*iecx;
    unsigned int            mask;
    
	if( TIMER_NUMBER_OF_MODULES < id ) return 0;    
    
    if( TIMER7 > id)
    {
        iecx 	= (volatile UINT *)(0xBF8100C0);                                //IEC0
        if( TIMER6 > id)
        {
            mask 	= 1<<(4+(5*id));
        }
        else
        {
            mask 	= _IEC0_T6IE_MASK;
        }
    }
    else
    {
        iecx 	= (volatile UINT *)(0xBF8100D0);                                //IEC1
        mask 	= 1<<(4*(id-6));
    }    
    return (*iecx & mask);
}

extern inline void __attribute__((always_inline)) 
mTIntEnable( TIMER_MODULE id, BOOL enable)
{
	volatile unsigned int	*iecx;
    unsigned int            mask;
    
	if( TIMER_NUMBER_OF_MODULES < id ) return;    
    
    if( TIMER7 > id)
    {
        iecx 	= (volatile UINT *)(0xBF8100C4);                                //IEC0CLR
        if( TIMER6 > id)
        {
            mask 	= 1<<(4+(5*id));
        }
        else
        {
            mask 	= _IEC0_T6IE_MASK;
        }
    }
    else
    {
        iecx 	= (volatile UINT *)(0xBF8100D4);                                //IEC1CLR
        mask 	= 1<<(4*(id-6));
    }        
    *iecx = mask;
    
    if( enable )
    {
        iecx    += 1;                                                           //IECxSET
        *iecx   = mask;
    }
}

extern inline void __attribute__((always_inline)) 
mTSetIntPriority( TIMER_MODULE id, unsigned int priority)         
{
    
    if( TIMER_NUMBER_OF_MODULES <= id ) return;     
    
    switch( id )
    {
        case TIMER1:
            IPC1CLR = _IPC1_T1IP_MASK;
            IPC1SET = ((priority) << _IPC1_T1IP_POSITION);
            break;
        case TIMER2:            
            IPC2CLR = _IPC2_T2IP_MASK;
            IPC2SET = ((priority) << _IPC2_T2IP_POSITION);
            break;
        case TIMER3:
            IPC3CLR = _IPC3_T3IP_MASK;
            IPC3SET = ((priority) << _IPC3_T3IP_POSITION);
            break;
        case TIMER4:   
            IPC4CLR = _IPC4_T4IP_MASK;
            IPC4SET = ((priority) << _IPC4_T4IP_POSITION);
            break;
        case TIMER5:   
            IPC6CLR = _IPC6_T5IP_MASK;
            IPC6SET = ((priority) << _IPC6_T5IP_POSITION);
            break;
        case TIMER6:   
            IPC7CLR = _IPC7_T6IP_MASK;
            IPC7SET = ((priority) << _IPC7_T6IP_POSITION);
            break;
        case TIMER7:   
            IPC8CLR = _IPC8_T7IP_MASK;
            IPC8SET = ((priority) << _IPC8_T7IP_POSITION);
            break;
        case TIMER8:   
            IPC9CLR = _IPC9_T8IP_MASK;
            IPC9SET = ((priority) << _IPC9_T8IP_POSITION);
            break;
        case TIMER9:   
            IPC10CLR = _IPC10_T9IP_MASK;
            IPC10SET = ((priority) << _IPC10_T9IP_POSITION);
            break;
        default:
            break;
    }
}

extern inline unsigned int __attribute__((always_inline)) 
mTGetIntPriority( TIMER_MODULE id )
{
unsigned int ret = 0;

    if( TIMER_NUMBER_OF_MODULES <= id ) return 0;     
    
    switch( id )
    {
        case TIMER1:
            ret = IPC1bits.T1IP;
            break;
        case TIMER2:            
            ret = IPC2bits.T2IP;
            break;
        case TIMER3:
            ret = IPC3bits.T3IP;
            break;
        case TIMER4:   
            ret = IPC4bits.T4IP;
            break;
        case TIMER5:   
            ret = IPC6bits.T5IP;
            break;
        case TIMER6:   
            ret = IPC7bits.T6IP;
            break;
        case TIMER7:   
            ret = IPC8bits.T7IP;
            break;
        case TIMER8:   
            ret = IPC9bits.T8IP;
            break;
        case TIMER9:   
            ret = IPC10bits.T9IP;
            break;
        default:
            break; 
    }    
    return ret;
}    
    
extern inline void __attribute__((always_inline)) 
mTSetIntSubPriority( TIMER_MODULE id, unsigned int subPriority)
{
    
    if( TIMER_NUMBER_OF_MODULES <= id ) return;     
    
    switch( id )
    {
        case TIMER1:
            IPC1CLR = _IPC1_T1IS_MASK;
            IPC1SET = ((subPriority) << _IPC1_T1IS_POSITION);
            break;
        case TIMER2:            
            IPC2CLR = _IPC2_T2IS_MASK;
            IPC2SET = ((subPriority) << _IPC2_T2IS_POSITION);
            break;
        case TIMER3:
            IPC3CLR = _IPC3_T3IS_MASK;
            IPC3SET = ((subPriority) << _IPC3_T3IS_POSITION);
            break;
        case TIMER4:   
            IPC4CLR = _IPC4_T4IS_MASK;
            IPC4SET = ((subPriority) << _IPC4_T4IS_POSITION);
            break;
        case TIMER5:   
            IPC6CLR = _IPC6_T5IS_MASK;
            IPC6SET = ((subPriority) << _IPC6_T5IS_POSITION);
            break;
        case TIMER6:   
            IPC7CLR = _IPC7_T6IS_MASK;
            IPC7SET = ((subPriority) << _IPC7_T6IS_POSITION);
            break;
        case TIMER7:   
            IPC8CLR = _IPC8_T7IS_MASK;
            IPC8SET = ((subPriority) << _IPC8_T7IS_POSITION);
            break;
        case TIMER8:   
            IPC9CLR = _IPC9_T8IS_MASK;
            IPC9SET = ((subPriority) << _IPC9_T8IS_POSITION);
            break;
        case TIMER9:   
            IPC10CLR = _IPC10_T9IS_MASK;
            IPC10SET = ((subPriority) << _IPC10_T9IS_POSITION);
            break;
        default:
            break;
    }    
}            

extern inline unsigned int __attribute__((always_inline)) 
mTGetIntSubPriority( TIMER_MODULE id ) 
{
unsigned int ret = 0;

    if( TIMER_NUMBER_OF_MODULES <= id ) return 0;     
    
    switch( id )
    {
        case TIMER1:
            ret = IPC1bits.T1IS;
            break;
        case TIMER2:            
            ret = IPC2bits.T2IS;
            break;
        case TIMER3:
            ret = IPC3bits.T3IS;
            break;
        case TIMER4:   
            ret = IPC4bits.T4IS;
            break;
        case TIMER5:   
            ret = IPC6bits.T5IS;
            break;
        case TIMER6:   
            ret = IPC7bits.T6IS;
            break;
        case TIMER7:   
            ret = IPC8bits.T7IS;
            break;
        case TIMER8:   
            ret = IPC9bits.T8IS;
            break;
        case TIMER9:   
            ret = IPC10bits.T9IS;
            break;
        default:
            break;
    }
    return ret;    
}

/******************************************************************************
 * Function:        void OpenTimer(TMR_MODULE id, unsigned int config, unsigned int period)
 *
 * Description:     Configures Timer X
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise OR value of T_ON/OFF, T_IDLE_XXX,
 *                          T_GATE_XXX, T_PS_XXX, T_32BIT_MODE_ON,
 *                          T_SOURCE_XXX...
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 *                  period: A value between 0 - 0xffff inclusive
 *
 * Output:          None
 *
 * Example:         OpenTimer(TIMER2, T_ON | T_IDLE_ON | T_PS_1_4, 123);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
OpenTimer( TIMER_MODULE id, unsigned int config,  unsigned int period )
{
	volatile unsigned int	*tmr_txcon;
	volatile unsigned int	*tmr_tmrx;
	volatile unsigned int	*tmr_prx;	
	
	if( TIMER_NUMBER_OF_MODULES < id ) return;

	tmr_txcon 	= (volatile UINT *)(0xBF840000 + (0x200*((UINT)id)));           //TMR1TxCON
	tmr_tmrx    = (volatile UINT *)(0xBF840010 + (0x200*((UINT)id)));           //TMR1TMRx
	tmr_prx     = (volatile UINT *)(0xBF840020 + (0x200*((UINT)id)));           //TMR1PRx
	
	*tmr_txcon 	= (config)&~(T_ON);
	*tmr_tmrx	= 0;
	*tmr_prx	= period;
	tmr_txcon 	+= 2;                                                           //TMRxTxCONSET
	*tmr_txcon	= (config)&(T_ON);
}


/******************************************************************************
 * Function:        CloseTimer()
 *
 * Description:     Switches off the TimerX
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseTimer(TIMER2);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline))  
CloseTimer( TIMER_MODULE id )
{
	volatile unsigned int	*tmr_txcon;
	
	if( TIMER_NUMBER_OF_MODULES < id ) return;
	
	tmr_txcon 	= (volatile UINT *)(0xBF840000 + (0x200*((UINT)id)));           //TMR1TxCON	
	
    mTIntEnable(id, FALSE), 
	*tmr_txcon = 0;
}


/******************************************************************************
 * Function:        void ConfigIntTimer(TMR_MODULE id, unsigned int config)
 *
 * Description:     Configures Timer X interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: Bit-wise OR value of T_INT_XXX, T_INT_PRIOR_XXX
 *                            and T_INT_SUB_PRIOR_X.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigIntTimer(TIMER2, T_INT_ON | T_INT_PRIOR_3 | T_INT_SUB_PRIOR1);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
ConfigIntTimer( TIMER_MODULE id, unsigned int config )
{
    
	if( TIMER_NUMBER_OF_MODULES < id ) return;
    
    mTClearIntFlag(id); 
    mTSetIntPriority(id, ((config) & 7));
    mTSetIntSubPriority(id, ((config) >> 4) & 3);
    mTIntEnable(id, (config) >> 15);
}


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_H */

