/*
		FileName: int.h
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

#ifndef INT_H
#define	INT_H

#include <xc.h>
#include <GenericTypeDefs.h>
#include <stdint.h>
#include <sys/attribs.h>

#ifdef	__cplusplus
extern "C" {
#endif


/****************************************************************************************************
 * <combinewith mCTGetIntFlag, mCTIntEnable, mCTGetIntEnable, mCTSetIntPriority, mCTGetIntPriority,
 * mCTSetIntSubPriority, mCTGetIntSubPriority>
 *
 * Core Timer Control Interrupt Functions
 * Prototype:
 *     void mCTClearIntFlag(void) int mCTGetIntFlag(void) void
 *     mCTSetIntEnable(void) int mCTGetIntEnable(void) void
 *     mCTClearIntEnable(void) void mCTSetIntPriority(int priority)
 *     int mCTGetIntPriority(void) void
 *     mCTSetIntSubPriority(subPriority) int
 *     mCTGetIntSubPriority(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 *****************************************************************************************************
 */
#define mCTClearIntFlag()                   (IFS0CLR = _IFS0_CTIF_MASK)
#define mCTGetIntFlag()                     (IFS0bits.CTIF)
#define mCTIntEnable(enable)                (IEC0CLR = _IEC0_CTIE_MASK, IEC0SET = ((enable) << _IEC0_CTIE_POSITION))
#define mCTGetIntEnable()                   (IEC0bits.CTIE)
#define mCTSetIntPriority(priority)         (IPC0CLR = _IPC0_CTIP_MASK, IPC0SET = ((priority) << _IPC0_CTIP_POSITION))
#define mCTGetIntPriority()                 (IPC0bits.CTIP)
#define mCTSetIntSubPriority(subPriority)   (IPC0CLR = _IPC0_CTIS_MASK, IPC0SET = ((subPriority) << _IPC0_CTIS_POSITION))
#define mCTGetIntSubPriority()              (IPC0bits.CTIS)

    
/*********************************************************************************************************
 * <combinewith mCS0GetIntFlag, mCS0IntEnable, mCS0GetIntEnable, mCS0SetIntPriority, mCS0GetIntPriority,
 * mCS0SetIntSubPriority, mCS0GetIntSubPriority>
 *
 * Core Software Interrupt 0 Control Functions
 * Prototype:
 *     void mCS0ClearIntFlag(void) int mCS0GetIntFlag(void) void
 *     mCS0SetIntEnable(void) int mCS0GetIntEnable(void) void
 *     mCS0ClearIntEnable(void) void mCS0SetIntPriority(int
 *     priority) int mCS0GetIntPriority(void) void
 *     mCS0SetIntSubPriority(subPriority) int
 *     mCS0GetIntSubPriority(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 **************************************************************************************************************
 */
#define mCS0ClearIntFlag()                  (IFS0CLR = _IFS0_CS0IF_MASK)
#define mCS0GetIntFlag()                    (IFS0bits.CS0IF)
#define mCS0IntEnable(enable)               (IEC0CLR = _IEC0_CS0IE_MASK, IEC0SET = ((enable) << _IEC0_CS0IE_POSITION))
#define mCS0GetIntEnable()                  (IEC0bits.CS0IE)
#define mCS0SetIntPriority(priority)        (IPC0CLR = _IPC0_CS0IP_MASK, IPC0SET = ((priority) << _IPC0_CS0IP_POSITION))
#define mCS0GetIntPriority()                (IPC0bits.CS0IP)
#define mCS0SetIntSubPriority(subPriority)  (IPC0CLR = _IPC0_CS0IS_MASK, IPC0SET = ((subPriority) << _IPC0_CS0IS_POSITION))
#define mCS0GetIntSubPriority()             (IPC0bits.CS0IS)

/**************************************************************************************
 * <combinewith mCS1GetIntEnable, mCS1GetIntFlag, mCS1GetIntPriority,
 * mCS1GetIntSubPriority, mCS1IntEnable, mCS1SetIntPriority, mCS1SetIntSubPriority>
 *
 * Core Software Interrupt 1 Control Functions
 * Prototype:
 *     void mCS1ClearIntFlag(void) int mCS1GetIntFlag(void) void
 *     mCS1SetIntEnable(void) int mCS1GetIntEnable(void) void
 *     mCS1ClearIntEnable(void) void mCS1SetIntPriority(int
 *     priority) int mCS1GetIntPriority(void) void
 *     mCS1SetIntSubPriority(subPriority) int
 *     mCS1GetIntSubPriority(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 *     edgeMode :     1 = Rising, 0 = Falling
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 ************************************************************************************
 */
#define mCS1ClearIntFlag()                  (IFS0CLR = _IFS0_CS1IF_MASK)
#define mCS1GetIntFlag()                    (IFS0bits.CS1IF)
#define mCS1GetIntEnable()                  (IEC0bits.CS1IE)
#define mCS1IntEnable(enable)               (IEC0CLR = _IEC0_CS1IE_MASK, IEC0SET = ((enable) << _IEC0_CS1IE_POSITION))
#define mCS1SetIntPriority(priority)        (IPC0CLR = _IPC0_CS1IP_MASK, IPC0SET = ((priority) << _IPC0_CS1IP_POSITION))
#define mCS1GetIntPriority()                (IPC0bits.CS1IP)
#define mCS1SetIntSubPriority(subPriority)  (IPC0CLR = _IPC0_CS1IS_MASK, IPC0SET = ((subPriority) << _IPC0_CS1IS_POSITION))
#define mCS1GetIntSubPriority()             (IPC0bits.CS1IS)


/************************************************************************************************************************************************************************************************************
 * <combinewith mINT0GetIntFlag, mINT0GetIntEnable, mINT0IntEnable, mINT0SetIntPriority, mINT0GetIntPriority, mINT0SetIntSubPriority, mINT0GetIntSubPriority, mINT0SetEdgeMode, mINT0GetEdgeMode,
 * mINT1ClearIntFlag, mINT1GetIntFlag, mINT1GetIntEnable, mINT1IntEnable, mINT1SetIntPriority, mINT1GetIntPriority, mINT1SetIntSubPriority, mINT1GetIntSubPriority, mINT1SetEdgeMode, mINT1GetEdgeMode,
 * mINT2ClearIntFlag, mINT2GetIntFlag, mINT2GetIntEnable, mINT2IntEnable, mINT2SetIntPriority, mINT2GetIntPriority, mINT2SetIntSubPriority, mINT2GetIntSubPriority, mINT2SetEdgeMode, mINT2GetEdgeMode,
 * mINT3ClearIntFlag, mINT3GetIntFlag, mINT3GetIntEnable, mINT3IntEnable, mINT3SetIntPriority, mINT3GetIntPriority, mINT3SetIntSubPriority, mINT3GetIntSubPriority, mINT3SetEdgeMode, mINT3GetEdgeMode,
 * mINT4ClearIntFlag, mINT4GetIntFlag, mINT4GetIntEnable, mINT4IntEnable, mINT4SetIntPriority, mINT4GetIntPriority, mINT4SetIntSubPriority, mINT4GetIntSubPriority, mINT4SetEdgeMode, mINT4GetEdgeMode>
 *
 * External INTx Control Functions
 * Prototype:
 *     void mINTxClearIntFlag(void) int mINTxGetIntFlag(void) void
 *     mINTxSetIntEnable(void) int mINTxGetIntEnable(void) void
 *     mINTxClearIntEnable(void) void mINTxSetIntPriority(int
 *     priority) int mINTxGetIntPriority(void) void
 *     mINTxSetIntSubPriority(subPriority) int
 *     mINTxGetIntSubPriority(void) void mINTxSetEdgeRising(void)
 *     void mINTxGetEdgeFalling(void) int mINTxGetEdgeMode(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 ******************************************************************************************************************************************************************/
/*********************************************************************
 * External INT0 Control Functions
 ********************************************************************/
#define mINT0ClearIntFlag()         (IFS0CLR = _IFS0_INT0IF_MASK)
#define mINT0GetIntFlag()           (IFS0bits.INT0IF)
#define mINT0GetIntEnable()                     (IEC0bits.INT0IE)
#define mINT0IntEnable(enable)                  (IEC0CLR = _IEC0_INT0IE_MASK, IEC0SET = ((enable) << _IEC0_INT0IE_POSITION))
#define mINT0SetIntPriority(priority)       (IPC0CLR = _IPC0_INT0IP_MASK, IPC0SET = ((priority) << _IPC0_INT0IP_POSITION))
#define mINT0GetIntPriority()           (IPC0bits.INT0IP)
#define mINT0SetIntSubPriority(subPriority)     (IPC0CLR = _IPC0_INT0IS_MASK, IPC0SET = ((subPriority) << _IPC0_INT0IS_POSITION))
#define mINT0GetIntSubPriority()        (IPC0bits.INT0IS)
#define mINT0SetEdgeMode(mode)              (INTCONCLR = (1 << _INTCON_INT0EP_POSITION), INTCONSET = ((mode) << _INTCON_INT0EP_POSITION))
#define mINT0GetEdgeMode()          (INTCONbits.INT0EP)
/*********************************************************************
 * External INT1 Control Functions
 ********************************************************************/
#define mINT1ClearIntFlag()         (IFS0CLR = _IFS0_INT1IF_MASK)
#define mINT1GetIntFlag()           (IFS0bits.INT1IF)
#define mINT1GetIntEnable()                     (IEC0bits.INT1IE)
#define mINT1IntEnable(enable)                  (IEC0CLR = _IEC0_INT1IE_MASK, IEC0SET = ((enable) << _IEC0_INT1IE_POSITION))
#define mINT1SetIntPriority(priority)       (IPC2CLR = _IPC2_INT1IP_MASK, IPC2SET = ((priority) << _IPC2_INT1IP_POSITION))
#define mINT1GetIntPriority()           (IPC2bits.INT1IP)
#define mINT1SetIntSubPriority(subPriority)     (IPC2CLR = _IPC2_INT1IS_MASK, IPC2SET = ((subPriority) << _IPC2_INT1IS_POSITION))
#define mINT1GetIntSubPriority()        (IPC2bits.INT1IS)
#define mINT1SetEdgeMode(mode)              (INTCONCLR = (1 << _INTCON_INT1EP_POSITION), INTCONSET = ((mode) << _INTCON_INT1EP_POSITION))
#define mINT1GetEdgeMode()          (INTCONbits.INT1EP)
/*********************************************************************
 * External INT2 Control Functions
 ********************************************************************/
#define mINT2ClearIntFlag()         (IFS0CLR = _IFS0_INT2IF_MASK)
#define mINT2GetIntFlag()           (IFS0bits.INT2IF)
#define mINT2GetIntEnable()                     (IEC0bits.INT2IE)
#define mINT2IntEnable(enable)                  (IEC0CLR = _IEC0_INT2IE_MASK, IEC0SET = ((enable) << _IEC0_INT2IE_POSITION))
#define mINT2SetIntPriority(priority)       (IPC3CLR = _IPC3_INT2IP_MASK, IPC3SET = ((priority) << _IPC3_INT2IP_POSITION))
#define mINT2GetIntPriority()           (IPC3bits.INT2IP)
#define mINT2SetIntSubPriority(subPriority)     (IPC3CLR = _IPC3_INT2IS_MASK, IPC3SET = ((subPriority) << _IPC3_INT2IS_POSITION))
#define mINT2GetIntSubPriority()        (IPC3bits.INT2IS)
#define mINT2SetEdgeMode(mode)              (INTCONCLR = (1 << _INTCON_INT2EP_POSITION), INTCONSET = ((mode) << _INTCON_INT2EP_POSITION))
#define mINT2GetEdgeMode()          (INTCONbits.INT2EP)
/*********************************************************************
 * External INT3 Control Functions
 ********************************************************************/
#define mINT3ClearIntFlag()         (IFS0CLR = _IFS0_INT3IF_MASK)
#define mINT3GetIntFlag()           (IFS0bits.INT3IF)
#define mINT3GetIntEnable()                     (IEC0bits.INT3IE)
#define mINT3IntEnable(enable)                  (IEC0CLR = _IEC0_INT3IE_MASK, IEC0SET = ((enable) << _IEC0_INT3IE_POSITION))
#define mINT3SetIntPriority(priority)       (IPC4CLR = _IPC4_INT3IP_MASK, IPC4SET = ((priority) << _IPC4_INT3IP_POSITION))
#define mINT3GetIntPriority()           (IPC4bits.INT3IP)
#define mINT3SetIntSubPriority(subPriority)     (IPC4CLR = _IPC4_INT3IS_MASK, IPC4SET = ((subPriority) << _IPC4_INT3IS_POSITION))
#define mINT3GetIntSubPriority()        (IPC4bits.INT3IS)
#define mINT3SetEdgeMode(mode)              (INTCONCLR = (1 << _INTCON_INT3EP_POSITION), INTCONSET = ((mode) << _INTCON_INT3EP_POSITION))
#define mINT3GetEdgeMode()          (INTCONbits.INT3EP)
/*********************************************************************
 * External INT4 Control Functions
 ********************************************************************/
#define mINT4ClearIntFlag()         (IFS0CLR = _IFS0_INT4IF_MASK)
#define mINT4GetIntFlag()           (IFS0bits.INT4IF)
#define mINT4GetIntEnable()                     (IEC0bits.INT4IE)
#define mINT4IntEnable(enable)                  (IEC0CLR = _IEC0_INT4IE_MASK, IEC0SET = ((enable) << _IEC0_INT4IE_POSITION))
#define mINT4SetIntPriority(priority)       (IPC5CLR = _IPC5_INT4IP_MASK, IPC5SET = ((priority) << _IPC5_INT4IP_POSITION))
#define mINT4GetIntPriority()           (IPC5bits.INT4IP)
#define mINT4SetIntSubPriority(subPriority)     (IPC5CLR = _IPC5_INT4IS_MASK, IPC5SET = ((subPriority) << _IPC5_INT4IS_POSITION))
#define mINT4GetIntSubPriority()        (IPC5bits.INT4IS)
#define mINT4SetEdgeMode(mode)              (INTCONCLR = (1 << _INTCON_INT4EP_POSITION), INTCONSET = ((mode) << _INTCON_INT4EP_POSITION))
#define mINT4GetEdgeMode()          (INTCONbits.INT4EP)    


/******************************************************************************************************************************************
 * <combinewith mT1GetIntFlag, mT1GetIntEnable, mT1IntEnable, mT1SetIntPriority, mT1GetIntPriority, mT1SetIntSubPriority, mT1GetIntSubPriority,
 * mT2ClearIntFlag, mT2GetIntFlag, mT2GetIntEnable, mT2IntEnable, mT2SetIntPriority, mT2GetIntPriority, mT2SetIntSubPriority, mT2GetIntSubPriority,
 * mT3ClearIntFlag, mT3GetIntFlag, mT3GetIntEnable, mT3IntEnable, mT3SetIntPriority, mT3GetIntPriority, mT3SetIntSubPriority, mT3GetIntSubPriority,
 * mT23ClearIntFlag, mT23GetIntFlag, mT23GetIntEnable, mT23IntEnable, mT23SetIntPriority, mT23GetIntPriority, mT23SetIntSubPriority, mT23GetIntSubPriority,
 * mT4ClearIntFlag, mT4GetIntFlag, mT4GetIntEnable, mT4IntEnable, mT4SetIntPriority, mT4GetIntPriority, mT4SetIntSubPriority, mT4GetIntSubPriority,
 * mT5ClearIntFlag, mT5GetIntFlag, mT5GetIntEnable, mT5IntEnable, mT5SetIntPriority, mT5GetIntPriority, mT5SetIntSubPriority, mT5GetIntSubPriority,
 * mT45ClearIntFlag, mT45GetIntFlag, mT45GetIntEnable, mT45IntEnable, mT45SetIntPriority, mT45GetIntPriority, mT45SetIntSubPriority, mT45GetIntSubPriority>
 *
 * Timer x Interrupt Control Functions
 *
 * Function:        void    mTxClearIntFlag(void)
 *                  int     mTxGetIntFlag(void)
 *                  void    mTxSetIntEnable(void)
 *                  int     mTxGetIntEnable(void)
 *                  void    mTxClearIntEnable(void)
 *                  void    mTxSetIntPriority(int priority)
 *                  int     mTxGetIntPriority(void)
 *                  void    mTxSetIntSubPriority(subPriority)
 *                  int     mTxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *****************************************************************************************************************************************/
/*********************************************************************
 * Timer 1 Interrupt Control Functions
 ********************************************************************/
#ifdef _TMR1
#define mT1ClearIntFlag()                   (IFS0CLR = _IFS0_T1IF_MASK)
#define mT1GetIntFlag()                     (IFS0bits.T1IF)
#define mT1GetIntEnable()                   (IEC0bits.T1IE)
#define mT1IntEnable(enable)                (IEC0CLR = _IEC0_T1IE_MASK, IEC0SET = ((enable) << _IEC0_T1IE_POSITION))
#define mT1SetIntPriority(priority)         (IPC1CLR = _IPC1_T1IP_MASK, IPC1SET = ((priority) << _IPC1_T1IP_POSITION))
#define mT1GetIntPriority()                 (IPC1bits.T1IP)
#define mT1SetIntSubPriority(subPriority)   (IPC1CLR = _IPC1_T1IS_MASK, IPC1SET = ((subPriority) << _IPC1_T1IS_POSITION))
#define mT1GetIntSubPriority()              (IPC1bits.T1IS)
#endif
#ifdef _TMR2
/*********************************************************************
 * Timer 2 Interrupt Control Functions
 ********************************************************************/
#define mT2ClearIntFlag()                   (IFS0CLR = _IFS0_T2IF_MASK)
#define mT2GetIntFlag()                     (IFS0bits.T2IF)
#define mT2GetIntEnable()                   (IEC0bits.T2IE)
#define mT2IntEnable(enable)                (IEC0CLR = _IEC0_T2IE_MASK, IEC0SET = ((enable) << _IEC0_T2IE_POSITION))
#define mT2SetIntPriority(priority)         (IPC2CLR = _IPC2_T2IP_MASK, IPC2SET = ((priority) << _IPC2_T2IP_POSITION))
#define mT2GetIntPriority()                 (IPC2bits.T2IP)
#define mT2SetIntSubPriority(subPriority)   (IPC2CLR = _IPC2_T2IS_MASK, IPC2SET = ((subPriority) << _IPC2_T2IS_POSITION))
#define mT2GetIntSubPriority()              (IPC2bits.T2IS)
#endif
#ifdef _TMR3
/*********************************************************************
 * Timer 3 Interrupt Control Functions
 ********************************************************************/
#define mT3ClearIntFlag()                   (IFS0CLR = _IFS0_T3IF_MASK)
#define mT3GetIntFlag()                     (IFS0bits.T3IF)
#define mT3GetIntEnable()                   (IEC0bits.T3IE)
#define mT3IntEnable(enable)                (IEC0CLR = _IEC0_T3IE_MASK, IEC0SET = ((enable) << _IEC0_T3IE_POSITION))
#define mT3SetIntPriority(priority)         (IPC3CLR = _IPC3_T3IP_MASK, IPC3SET = ((priority) << _IPC3_T3IP_POSITION))
#define mT3GetIntPriority()                 (IPC3bits.T3IP)
#define mT3SetIntSubPriority(subPriority)   (IPC3CLR = _IPC3_T3IS_MASK, IPC3SET = ((subPriority) << _IPC3_T3IS_POSITION))
#define mT3GetIntSubPriority()              (IPC3bits.T3IS)
/*********************************************************************
 * Timer 23 Interrupt Control Functions
 ********************************************************************/
#define mT23ClearIntFlag()                   (IFS0CLR = _IFS0_T3IF_MASK)
#define mT23GetIntFlag()                     (IFS0bits.T3IF)
#define mT23GetIntEnable()                   (IEC0bits.T3IE)
#define mT23IntEnable(enable)                (IEC0CLR = _IEC0_T3IE_MASK, IEC0SET = ((enable) << _IEC0_T3IE_POSITION))
#define mT23SetIntPriority(priority)         (IPC3CLR = _IPC3_T3IP_MASK, IPC3SET = ((priority) << _IPC3_T3IP_POSITION))
#define mT23GetIntPriority()                 (IPC3bits.T3IP)
#define mT23SetIntSubPriority(subPriority)   (IPC3CLR = _IPC3_T3IS_MASK, IPC3SET = ((subPriority) << _IPC3_T3IS_POSITION))
#define mT23GetIntSubPriority()              (IPC3bits.T3IS)
#endif
#ifdef _TMR4
/*********************************************************************
 * Timer 4 Interrupt Control Functions
 ********************************************************************/
#define mT4ClearIntFlag()                   (IFS0CLR = _IFS0_T4IF_MASK)
#define mT4GetIntFlag()                     (IFS0bits.T4IF)
#define mT4GetIntEnable()                   (IEC0bits.T4IE)
#define mT4IntEnable(enable)                (IEC0CLR = _IEC0_T4IE_MASK, IEC0SET = ((enable) << _IEC0_T4IE_POSITION))
#define mT4SetIntPriority(priority)         (IPC4CLR = _IPC4_T4IP_MASK, IPC4SET = ((priority) << _IPC4_T4IP_POSITION))
#define mT4GetIntPriority()                 (IPC4bits.T4IP)
#define mT4SetIntSubPriority(subPriority)   (IPC4CLR = _IPC4_T4IS_MASK, IPC4SET = ((subPriority) << _IPC4_T4IS_POSITION))
#define mT4GetIntSubPriority()              (IPC4bits.T4IS)
#endif
#ifdef _TMR5
/*********************************************************************
 * Timer 5 Interrupt Control Functions
 ********************************************************************/
#define mT5ClearIntFlag()                   (IFS0CLR = _IFS0_T5IF_MASK)
#define mT5GetIntFlag()                     (IFS0bits.T5IF)
#define mT5GetIntEnable()                   (IEC0bits.T5IE)
#define mT5IntEnable(enable)                (IEC0CLR = _IEC0_T5IE_MASK, IEC0SET = ((enable) << _IEC0_T5IE_POSITION))
#define mT5SetIntPriority(priority)         (IPC6CLR = _IPC6_T5IP_MASK, IPC6SET = ((priority) << _IPC6_T5IP_POSITION))
#define mT5GetIntPriority()                 (IPC6bits.T5IP)
#define mT5SetIntSubPriority(subPriority)   (IPC6CLR = _IPC6_T5IS_MASK, IPC6SET = ((subPriority) << _IPC6_T5IS_POSITION))
#define mT5GetIntSubPriority()              (IPC6bits.T5IS)
/*********************************************************************
 * Timer 45 Interrupt Control Functions
 ********************************************************************/
#define mT45ClearIntFlag()                   (IFS0CLR = _IFS0_T5IF_MASK)
#define mT45GetIntFlag()                     (IFS0bits.T5IF)
#define mT45GetIntEnable()                   (IEC0bits.T5IE)
#define mT45IntEnable(enable)                (IEC0CLR = _IEC0_T5IE_MASK, IEC0SET = ((enable) << _IEC0_T5IE_POSITION))
#define mT45SetIntPriority(priority)         (IPC6CLR = _IPC6_T5IP_MASK, IPC6SET = ((priority) << _IPC6_T5IP_POSITION))
#define mT45GetIntPriority()                 (IPC6bits.T5IP)
#define mT45SetIntSubPriority(subPriority)   (IPC6CLR = _IPC6_T5IS_MASK, IPC6SET = ((subPriority) << _IPC6_T5IS_POSITION))
#define mT45GetIntSubPriority()              (IPC6bits.T5IS)
#endif    
#ifdef _TMR6
/*********************************************************************
 * Timer 6 Interrupt Control Functions
 ********************************************************************/
#define mT6ClearIntFlag()                   (IFS0CLR = _IFS0_T6IF_MASK)
#define mT6GetIntFlag()                     (IFS0bits.T6IF)
#define mT6GetIntEnable()                   (IEC0bits.T6IE)
#define mT6IntEnable(enable)                (IEC0CLR = _IEC0_T6IE_MASK, IEC0SET = ((enable) << _IEC0_T6IE_POSITION))
#define mT6SetIntPriority(priority)         (IPC7CLR = _IPC7_T6IP_MASK, IPC7SET = ((priority) << _IPC7_T6IP_POSITION))
#define mT6GetIntPriority()                 (IPC7bits.T6IP)
#define mT6SetIntSubPriority(subPriority)   (IPC7CLR = _IPC7_T6IS_MASK, IPC7SET = ((subPriority) << _IPC7_T6IS_POSITION))
#define mT6GetIntSubPriority()              (IPC7bits.T6IS)
#endif
#ifdef _TMR7
/*********************************************************************
 * Timer 7 Interrupt Control Functions
 ********************************************************************/
#define mT7ClearIntFlag()                   (IFS1CLR = _IFS1_T7IF_MASK)
#define mT7GetIntFlag()                     (IFS1bits.T7IF)
#define mT7GetIntEnable()                   (IEC1bits.T7IE)
#define mT7IntEnable(enable)                (IEC1CLR = _IEC1_T7IE_MASK, IEC1SET = ((enable) << _IEC1_T7IE_POSITION))
#define mT7SetIntPriority(priority)         (IPC8CLR = _IPC8_T7IP_MASK, IPC8SET = ((priority) << _IPC8_T7IP_POSITION))
#define mT7GetIntPriority()                 (IPC8bits.T7IP)
#define mT7SetIntSubPriority(subPriority)   (IPC8CLR = _IPC8_T7IS_MASK, IPC8SET = ((subPriority) << _IPC8_T7IS_POSITION))
#define mT7GetIntSubPriority()              (IPC8bits.T7IS)
/*********************************************************************
 * Timer 67 Interrupt Control Functions
 ********************************************************************/
#define mT67ClearIntFlag()                   (IFS1CLR = _IFS1_T7IF_MASK)
#define mT67GetIntFlag()                     (IFS1bits.T7IF)
#define mT67GetIntEnable()                   (IEC1bits.T7IE)
#define mT67IntEnable(enable)                (IEC1CLR = _IEC1_T7IE_MASK, IEC1SET = ((enable) << _IEC1_T7IE_POSITION))
#define mT67SetIntPriority(priority)         (IPC8CLR = _IPC8_T7IP_MASK, IPC8SET = ((priority) << _IPC8_T7IP_POSITION))
#define mT67GetIntPriority()                 (IPC8bits.T7IP)
#define mT67SetIntSubPriority(subPriority)   (IPC8CLR = _IPC8_T7IS_MASK, IPC8SET = ((subPriority) << _IPC8_T7IS_POSITION))
#define mT67GetIntSubPriority()              (IPC8bits.T7IS)
#endif   
#ifdef _TMR8
/*********************************************************************
 * Timer 8 Interrupt Control Functions
 ********************************************************************/
#define mT8ClearIntFlag()                   (IFS1CLR = _IFS1_T8IF_MASK)
#define mT8GetIntFlag()                     (IFS1bits.T8IF)
#define mT8GetIntEnable()                   (IEC1bits.T8IE)
#define mT8IntEnable(enable)                (IEC1CLR = _IEC1_T8IE_MASK, IEC1SET = ((enable) << _IEC1_T8IE_POSITION))
#define mT8SetIntPriority(priority)         (IPC9CLR = _IPC9_T8IP_MASK, IPC9SET = ((priority) << _IPC9_T8IP_POSITION))
#define mT8GetIntPriority()                 (IPC9bits.T8IP)
#define mT8SetIntSubPriority(subPriority)   (IPC9CLR = _IPC9_T8IS_MASK, IPC9SET = ((subPriority) << _IPC9_T8IS_POSITION))
#define mT8GetIntSubPriority()              (IPC9bits.T8IS)
#endif
#ifdef _TMR9
/*********************************************************************
 * Timer 9 Interrupt Control Functions
 ********************************************************************/
#define mT9ClearIntFlag()                   (IFS1CLR = _IFS1_T9IF_MASK)
#define mT9GetIntFlag()                     (IFS1bits.T9IF)
#define mT9GetIntEnable()                   (IEC1bits.T9IE)
#define mT9IntEnable(enable)                (IEC1CLR = _IEC1_T9IE_MASK, IEC1SET = ((enable) << _IEC1_T9IE_POSITION))
#define mT9SetIntPriority(priority)         (IPC10CLR = _IPC10_T9IP_MASK, IPC10SET = ((priority) << _IPC10_T9IP_POSITION))
#define mT9GetIntPriority()                 (IPC10bits.T9IP)
#define mT9SetIntSubPriority(subPriority)   (IPC10CLR = _IPC10_T9IS_MASK, IPC10SET = ((subPriority) << _IPC10_T9IS_POSITION))
#define mT9GetIntSubPriority()              (IPC10bits.T9IS)
/*********************************************************************
 * Timer 89 Interrupt Control Functions
 ********************************************************************/
#define mT89ClearIntFlag()                   (IFS1CLR = _IFS1_T9IF_MASK)
#define mT89GetIntFlag()                     (IFS1bits.T9IF)
#define mT89GetIntEnable()                   (IEC1bits.T9IE)
#define mT89IntEnable(enable)                (IEC1CLR = _IEC1_T9IE_MASK, IEC1SET = ((enable) << _IEC1_T9IE_POSITION))
#define mT89SetIntPriority(priority)         (IPC10CLR = _IPC10_T9IP_MASK, IPC10SET = ((priority) << _IPC10_T9IP_POSITION))
#define mT89GetIntPriority()                 (IPC10bits.T9IP)
#define mT89SetIntSubPriority(subPriority)   (IPC10CLR = _IPC10_T9IS_MASK, IPC10SET = ((subPriority) << _IPC10_T9IS_POSITION))
#define mT89GetIntSubPriority()              (IPC10bits.T9IS)
#endif      

    
/******************************************************************************************************************************************
 * <combinewith mIC1GetIntFlag, mIC1GetIntEnable, mIC1IntEnable, mIC1SetIntPriority, mIC1GetIntPriority, mIC1SetIntSubPriority, mIC1GetIntSubPriority,
 * mIC2ClearIntFlag, mIC2GetIntFlag, mIC2GetIntEnable, mIC2IntEnable, mIC2SetIntPriority, mIC2GetIntPriority, mIC2SetIntSubPriority, mIC2GetIntSubPriority,
 * mIC3ClearIntFlag, mIC3GetIntFlag, mIC3GetIntEnable, mIC3IntEnable, mIC3SetIntPriority, mIC3GetIntPriority, mIC3SetIntSubPriority, mIC3GetIntSubPriority,
 * mIC4ClearIntFlag, mIC4GetIntFlag, mIC4GetIntEnable, mIC4IntEnable, mIC4SetIntPriority, mIC4GetIntPriority, mIC4SetIntSubPriority, mIC4GetIntSubPriority,
 * mIC5ClearIntFlag, mIC5GetIntFlag, mIC5GetIntEnable, mIC5IntEnable, mIC5SetIntPriority, mIC5GetIntPriority, mIC5SetIntSubPriority, mIC5GetIntSubPriority>
 *
 * Input Capture x Interrupt Control Functions
 *
 * Function:        void    mICxClearIntFlag(void)
 *                  int     mICxGetIntFlag(void)
 *                  void    mICxSetIntEnable(void)
 *                  int     mICxGetIntEnable(void)
 *                  void    mICxClearIntEnable(void)
 *                  void    mICxSetIntPriority(int priority)
 *                  int     mICxGetIntPriority(void)
 *                  void    mICxSetIntSubPriority(subPriority)
 *                  int     mICxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *****************************************************************************************************************************************/
#ifdef _ICAP1
/*********************************************************************
 * Input Capture 1 Interrupt Control Functions
 ********************************************************************/
#define mIC1ClearIntFlag()                  (IFS0CLR = _IFS0_IC1IF_MASK)
#define mIC1GetIntFlag()                    (IFS0bits.IC1IF)
#define mIC1GetIntEnable()                  (IEC0bits.IC1IE)
#define mIC1IntEnable(enable)               (IEC0CLR = _IEC0_IC1IE_MASK, IEC0SET = ((enable) << _IEC0_IC1IE_POSITION))
#define mIC1SetIntPriority(priority)        (IPC1CLR = _IPC1_IC1IP_MASK, IPC1SET = ((priority) << _IPC1_IC1IP_POSITION))
#define mIC1GetIntPriority()                (IPC1bits.IC1IP)
#define mIC1SetIntSubPriority(subPriority)  (IPC1CLR = _IPC1_IC1IS_MASK, IPC1SET = ((subPriority) << _IPC1_IC1IS_POSITION))
#define mIC1GetIntSubPriority()             (IPC1bits.IC1IS)
#endif
#ifdef _ICAP2
/*********************************************************************
 * Input Capture 2 Interrupt Control Functions
 ********************************************************************/
#define mIC2ClearIntFlag()                  (IFS0CLR = _IFS0_IC2IF_MASK)
#define mIC2GetIntFlag()                    (IFS0bits.IC2IF)
#define mIC2GetIntEnable()                  (IEC0bits.IC2IE)
#define mIC2IntEnable(enable)               (IEC0CLR = _IEC0_IC2IE_MASK, IEC0SET = ((enable) << _IEC0_IC2IE_POSITION))
#define mIC2SetIntPriority(priority)        (IPC2CLR = _IPC2_IC2IS_MASK, IPC2SET = ((priority) << _IPC2_IC2IP_POSITION))
#define mIC2GetIntPriority()                (IPC2bits.IC2IP)
#define mIC2SetIntSubPriority(subPriority)  (IPC2CLR = _IPC2_IC2IS_MASK, IPC2SET = ((subPriority) << _IPC2_IC2IS_POSITION))
#define mIC2GetIntSubPriority()             (IPC2bits.IC2IS)
#endif
#ifdef _ICAP3
/*********************************************************************
 * Input Capture 3 Interrupt Control Functions
 ********************************************************************/
#define mIC3ClearIntFlag()                  (IFS0CLR = _IFS0_IC3IF_MASK)
#define mIC3GetIntFlag()                    (IFS0bits.IC3IF)
#define mIC3GetIntEnable()                  (IEC0bits.IC3IE)
#define mIC3IntEnable(enable)               (IEC0CLR = _IEC0_IC3IE_MASK, IEC0SET = ((enable) << _IEC0_IC3IE_POSITION))
#define mIC3SetIntPriority(priority)        (IPC4CLR = _IPC4_IC3IS_MASK, IPC4SET = ((priority) << _IPC4_IC3IP_POSITION))
#define mIC3GetIntPriority()                (IPC4bits.IC3IP)
#define mIC3SetIntSubPriority(subPriority)  (IPC4CLR = _IPC4_IC3IS_MASK, IPC4SET = ((subPriority) << _IPC4_IC3IS_POSITION))
#define mIC3GetIntSubPriority()             (IPC4bits.IC3IS)
#endif
#ifdef _ICAP4
/*********************************************************************
 * Input Capture 4 Interrupt Control Functions
 ********************************************************************/
#define mIC4ClearIntFlag()                  (IFS0CLR = _IFS0_IC4IF_MASK)
#define mIC4GetIntFlag()                    (IFS0bits.IC4IF)
#define mIC4GetIntEnable()                  (IEC0bits.IC4IE)
#define mIC4IntEnable(enable)               (IEC0CLR = _IEC0_IC4IE_MASK, IEC0SET = ((enable) << _IEC0_IC4IE_POSITION))
#define mIC4SetIntPriority(priority)        (IPC5CLR = _IPC5_IC4IP_MASK, IPC5SET = ((priority) << _IPC5_IC4IP_POSITION))
#define mIC4GetIntPriority()                (IPC5bits.IC4IP)
#define mIC4SetIntSubPriority(subPriority)  (IPC5CLR = _IPC5_IC4IS_MASK, IPC5SET = ((subPriority) << _IPC5_IC4IS_POSITION))
#define mIC4GetIntSubPriority()             (IPC5bits.IC4IS)
#endif
#ifdef _ICAP5
/*********************************************************************
 * Input Capture 5 Interrupt Control Functions
 ********************************************************************/
#define mIC5ClearIntFlag()                  (IFS0CLR = _IFS0_IC5IF_MASK)
#define mIC5GetIntFlag()                    (IFS0bits.IC5IF)
#define mIC5GetIntEnable()                  (IEC0bits.IC5IE)
#define mIC5IntEnable(enable)               (IEC0CLR = _IEC0_IC5IE_MASK, IEC0SET = ((enable) << _IEC0_IC5IE_POSITION))
#define mIC5SetIntPriority(priority)        (IPC6CLR = _IPC6_IC5IP_MASK, IPC6SET = ((priority) << _IPC6_IC5IP_POSITION))
#define mIC5GetIntPriority()                (IPC6bits.IC5IP)
#define mIC5SetIntSubPriority(subPriority)  (IPC6CLR = _IPC6_IC5IS_MASK, IPC6SET = ((subPriority) << _IPC6_IC5IS_POSITION))
#define mIC5GetIntSubPriority()             (IPC6bits.IC5IS)
#endif
#ifdef _ICAP6
/*********************************************************************
 * Input Capture 6 Interrupt Control Functions
 ********************************************************************/
#define mIC6ClearIntFlag()                  (IFS0CLR = _IFS0_IC6IF_MASK)
#define mIC6GetIntFlag()                    (IFS0bits.IC6IF)
#define mIC6GetIntEnable()                  (IEC0bits.IC6IE)
#define mIC6IntEnable(enable)               (IEC0CLR = _IEC0_IC6IE_MASK, IEC0SET = ((enable) << _IEC0_IC6IE_POSITION))
#define mIC6SetIntPriority(priority)        (IPC7CLR = _IPC7_IC6IP_MASK, IPC7SET = ((priority) << _IPC7_IC6IP_POSITION))
#define mIC6GetIntPriority()                (IPC7bits.IC6IP)
#define mIC6SetIntSubPriority(subPriority)  (IPC7CLR = _IPC7_IC6IS_MASK, IPC7SET = ((subPriority) << _IPC7_IC6IS_POSITION))
#define mIC6GetIntSubPriority()             (IPC7bits.IC6IS)
#endif
#ifdef _ICAP7
/*********************************************************************
 * Input Capture 7 Interrupt Control Functions
 ********************************************************************/
#define mIC7ClearIntFlag()                  (IFS1CLR = _IFS1_IC7IF_MASK)
#define mIC7GetIntFlag()                    (IFS1bits.IC7IF)
#define mIC7GetIntEnable()                  (IEC1bits.IC7IE)
#define mIC7IntEnable(enable)               (IEC1CLR = _IEC1_IC7IE_MASK, IEC1SET = ((enable) << _IEC1_IC7IE_POSITION))
#define mIC7SetIntPriority(priority)        (IPC8CLR = _IPC8_IC7IP_MASK, IPC8SET = ((priority) << _IPC8_IC7IP_POSITION))
#define mIC7GetIntPriority()                (IPC8bits.IC7IP)
#define mIC7SetIntSubPriority(subPriority)  (IPC8CLR = _IPC8_IC7IS_MASK, IPC8SET = ((subPriority) << _IPC8_IC7IS_POSITION))
#define mIC7GetIntSubPriority()             (IPC8bits.IC7IS)
#endif
#ifdef _ICAP8
/*********************************************************************
 * Input Capture 8 Interrupt Control Functions
 ********************************************************************/
#define mIC8ClearIntFlag()                  (IFS1CLR = _IFS1_IC8IF_MASK)
#define mIC8GetIntFlag()                    (IFS1bits.IC8IF)
#define mIC8GetIntEnable()                  (IEC1bits.IC8IE)
#define mIC8IntEnable(enable)               (IEC1CLR = _IEC1_IC8IE_MASK, IEC1SET = ((enable) << _IEC1_IC8IE_POSITION))
#define mIC8SetIntPriority(priority)        (IPC9CLR = _IPC9_IC8IP_MASK, IPC9SET = ((priority) << _IPC9_IC8IP_POSITION))
#define mIC8GetIntPriority()                (IPC9bits.IC8IP)
#define mIC8SetIntSubPriority(subPriority)  (IPC9CLR = _IPC9_IC8IS_MASK, IPC9SET = ((subPriority) << _IPC9_IC8IS_POSITION))
#define mIC8GetIntSubPriority()             (IPC9bits.IC8IS)
#endif
#ifdef _ICAP9
/*********************************************************************
 * Input Capture 8 Interrupt Control Functions
 ********************************************************************/
#define mIC9ClearIntFlag()                  (IFS1CLR = _IFS1_IC9IF_MASK)
#define mIC9GetIntFlag()                    (IFS1bits.IC9IF)
#define mIC9GetIntEnable()                  (IEC1bits.IC9IE)
#define mIC9IntEnable(enable)               (IEC1CLR = _IEC1_IC9IE_MASK, IEC1SET = ((enable) << _IEC1_IC9IE_POSITION))
#define mIC9SetIntPriority(priority)        (IPC10CLR = _IPC10_IC9IP_MASK, IPC10SET = ((priority) << _IPC10_IC9IP_POSITION))
#define mIC9GetIntPriority()                (IPC10bits.IC9IP)
#define mIC9SetIntSubPriority(subPriority)  (IPC10CLR = _IPC10_IC9IS_MASK, IPC10SET = ((subPriority) << _IPC10_IC9IS_POSITION))
#define mIC9GetIntSubPriority()             (IPC10bits.IC9IS)
#endif


/******************************************************************************************************************************************
 * <combinewith mOC1GetIntFlag, mOC1GetIntEnable, mOC1IntEnable, mOC1SetIntPriority, mOC1GetIntPriority, mOC1SetIntSubPriority, mOC1GetIntSubPriority,
 * mOC2ClearIntFlag, mOC2GetIntFlag, mOC2GetIntEnable, mOC2IntEnable, mOC2SetIntPriority, mOC2GetIntPriority, mOC2SetIntSubPriority, mOC2GetIntSubPriority,
 * mOC3ClearIntFlag, mOC3GetIntFlag, mOC3GetIntEnable, mOC3IntEnable, mOC3SetIntPriority, mOC3GetIntPriority, mOC3SetIntSubPriority, mOC3GetIntSubPriority,
 * mOC4ClearIntFlag, mOC4GetIntFlag, mOC4GetIntEnable, mOC4IntEnable, mOC4SetIntPriority, mOC4GetIntPriority, mOC4SetIntSubPriority, mOC4GetIntSubPriority,
 * mOC5ClearIntFlag, mOC5GetIntFlag, mOC5GetIntEnable, mOC5IntEnable, mOC5SetIntPriority, mOC5GetIntPriority, mOC5SetIntSubPriority, mOC5GetIntSubPriority>
 *
 * Output Compare x Interrupt Control Functions
 *
 * Function:        void    mOCxClearIntFlag(void)
 *                  int     mOCxGetIntFlag(void)
 *                  void    mOCxSetIntEnable(void)
 *                  int     mOCxGetIntEnable(void)
 *                  void    mOCxClearIntEnable(void)
 *                  void    mOCxSetIntPriority(int priority)
 *                  int     mOCxGetIntPriority(void)
 *                  void    mOCxSetIntSubPriority(subPriority)
 *                  int     mOCxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *****************************************************************************************************************************************/
#ifdef _OCMP1
/*********************************************************************
 * Output Compare 1 Interrupt Control Functions
 ********************************************************************/
#define mOC1ClearIntFlag()                  (IFS0CLR = _IFS0_OC1IF_MASK)
#define mOC1GetIntFlag()                    (IFS0bits.OC1IF)
#define mOC1GetIntEnable()                  (IEC0bits.OC1IE)
#define mOC1IntEnable(enable)               (IEC0CLR = _IEC0_OC1IE_MASK, IEC0SET = ((enable) << _IEC0_OC1IE_POSITION))
#define mOC1SetIntPriority(priority)        (IPC1CLR = _IPC1_IC1IP_MASK, IPC1SET = ((priority) << _IPC1_OC1IP_POSITION))
#define mOC1GetIntPriority()                (IPC1bits.OC1IP)
#define mOC1SetIntSubPriority(subPriority)  (IPC1CLR = _IPC1_OC1IS_MASK, IPC1SET = ((subPriority) << _IPC1_OC1IS_POSITION))
#define mOC1GetIntSubPriority()             (IPC1bits.OC1IS)
#endif
#ifdef _OCMP2
/*********************************************************************
 * Output Compare 2 Interrupt Control Functions
 ********************************************************************/
#define mOC2ClearIntFlag()                  (IFS0CLR = _IFS0_OC2IF_MASK)
#define mOC2GetIntFlag()                    (IFS0bits.OC2IF)
#define mOC2GetIntEnable()                  (IEC0bits.OC2IE)
#define mOC2IntEnable(enable)               (IEC0CLR = _IEC0_OC2IE_MASK, IEC0SET = ((enable) << _IEC0_OC2IE_POSITION))
#define mOC2SetIntPriority(priority)        (IPC3CLR = _IPC3_OC2IP_MASK, IPC3SET = ((priority) << _IPC3_OC2IP_POSITION))
#define mOC2GetIntPriority()                (IPC3bits.OC2IP)
#define mOC2SetIntSubPriority(subPriority)  (IPC3CLR = _IPC3_OC2IS_MASK, IPC3SET = ((subPriority) << _IPC3_OC2IS_POSITION))
#define mOC2GetIntSubPriority()             (IPC3bits.OC2IS)
#endif
#ifdef _OCMP3
/*********************************************************************
 * Output Compare 3 Interrupt Control Functions
 ********************************************************************/
#define mOC3ClearIntFlag()                  (IFS0CLR = _IFS0_OC3IF_MASK)
#define mOC3GetIntFlag()                    (IFS0bits.OC3IF)
#define mOC3GetIntEnable()                  (IEC0bits.OC3IE)
#define mOC3IntEnable(enable)               (IEC0CLR = _IEC0_OC3IE_MASK, IEC0SET = ((enable) << _IEC0_OC3IE_POSITION))
#define mOC3SetIntPriority(priority)        (IPC4CLR = _IPC4_OC3IP_MASK, IPC4SET = ((priority) << _IPC4_OC3IP_POSITION))
#define mOC3GetIntPriority()                (IPC4bits.OC3IP)
#define mOC3SetIntSubPriority(subPriority)  (IPC4CLR = _IPC4_OC3IS_MASK, IPC4SET = ((subPriority) << _IPC4_OC3IS_POSITION))
#define mOC3GetIntSubPriority()             (IPC4bits.OC3IS)
#endif
#ifdef _OCMP4
/*********************************************************************
 * Output Compare 4 Interrupt Control Functions
 ********************************************************************/
#define mOC4ClearIntFlag()                  (IFS0CLR = _IFS0_OC4IF_MASK)
#define mOC4GetIntFlag()                    (IFS0bits.OC4IF)
#define mOC4GetIntEnable()                  (IEC0bits.OC4IE)
#define mOC4IntEnable(enable)               (IEC0CLR = _IEC0_OC4IE_MASK, IEC0SET = ((enable) << _IEC0_OC4IE_POSITION))
#define mOC4SetIntPriority(priority)        (IPC5CLR = _IPC5_OC4IP_MASK, IPC5SET = ((priority) << _IPC5_OC4IP_POSITION))
#define mOC4GetIntPriority()                (IPC5bits.OC4IP)
#define mOC4SetIntSubPriority(subPriority)  (IPC5CLR = _IPC5_OC4IS_MASK, IPC5SET = ((subPriority) << _IPC5_OC4IS_POSITION))
#define mOC4GetIntSubPriority()             (IPC5bits.OC4IS)
#endif
#ifdef _OCMP5
/*********************************************************************
 * Output Compare 5 Interrupt Control Functions
 ********************************************************************/
#define mOC5ClearIntFlag()                  (IFS0CLR = _IFS0_OC5IF_MASK)
#define mOC5GetIntFlag()                    (IFS0bits.OC5IF)
#define mOC5GetIntEnable()                  (IEC0bits.OC5IE)
#define mOC5IntEnable(enable)               (IEC0CLR = _IEC0_OC5IE_MASK, IEC0SET = ((enable) << _IEC0_OC5IE_POSITION))
#define mOC5SetIntPriority(priority)        (IPC6CLR = _IPC6_OC5IP_MASK, IPC6SET = ((priority) << _IPC6_OC5IP_POSITION))
#define mOC5GetIntPriority()                (IPC6bits.OC5IP)
#define mOC5SetIntSubPriority(subPriority)  (IPC6CLR = _IPC6_OC5IS_MASK, IPC6SET = ((subPriority) << _IPC6_OC5IS_POSITION))
#define mOC5GetIntSubPriority()             (IPC6bits.OC5IS)
#endif
#ifdef _OCMP6
/*********************************************************************
 * Output Compare 6 Interrupt Control Functions
 ********************************************************************/
#define mOC6ClearIntFlag()                  (IFS0CLR = _IFS0_OC6IF_MASK)
#define mOC6GetIntFlag()                    (IFS0bits.OC6IF)
#define mOC6GetIntEnable()                  (IEC0bits.OC6IE)
#define mOC6IntEnable(enable)               (IEC0CLR = _IEC0_OC6IE_MASK, IEC0SET = ((enable) << _IEC0_OC6IE_POSITION))
#define mOC6SetIntPriority(priority)        (IPC7CLR = _IPC7_OC6IP_MASK, IPC7SET = ((priority) << _IPC7_OC6IP_POSITION))
#define mOC6GetIntPriority()                (IPC7bits.OC6IP)
#define mOC6SetIntSubPriority(subPriority)  (IPC7CLR = _IPC7_OC6IS_MASK, IPC7SET = ((subPriority) << _IPC7_OC6IS_POSITION))
#define mOC6GetIntSubPriority()             (IPC7bits.OC6IS)
#endif
#ifdef _OCMP7
/*********************************************************************
 * Output Compare 7 Interrupt Control Functions
 ********************************************************************/
#define mOC7ClearIntFlag()                  (IFS1CLR = _IFS1_OC7IF_MASK)
#define mOC7GetIntFlag()                    (IFS1bits.OC7IF)
#define mOC7GetIntEnable()                  (IEC1bits.OC7IE)
#define mOC7IntEnable(enable)               (IEC1CLR = _IEC1_OC7IE_MASK, IEC1SET = ((enable) << _IEC1_OC7IE_POSITION))
#define mOC7SetIntPriority(priority)        (IPC8CLR = _IPC8_OC7IP_MASK, IPC8SET = ((priority) << _IPC8_OC7IP_POSITION))
#define mOC7GetIntPriority()                (IPC8bits.OC7IP)
#define mOC7SetIntSubPriority(subPriority)  (IPC8CLR = _IPC8_OC7IS_MASK, IPC8SET = ((subPriority) << _IPC8_OC7IS_POSITION))
#define mOC7GetIntSubPriority()             (IPC8bits.OC7IS)
#endif
#ifdef _OCMP8
/*********************************************************************
 * Output Compare 8 Interrupt Control Functions
 ********************************************************************/
#define mOC8ClearIntFlag()                  (IFS1CLR = _IFS1_OC8IF_MASK)
#define mOC8GetIntFlag()                    (IFS1bits.OC8IF)
#define mOC8GetIntEnable()                  (IEC1bits.OC8IE)
#define mOC8IntEnable(enable)               (IEC1CLR = _IEC1_OC8IE_MASK, IEC1SET = ((enable) << _IEC1_OC8IE_POSITION))
#define mOC8SetIntPriority(priority)        (IPC9CLR = _IPC9_OC8IP_MASK, IPC9SET = ((priority) << _IPC9_OC8IP_POSITION))
#define mOC8GetIntPriority()                (IPC9bits.OC8IP)
#define mOC8SetIntSubPriority(subPriority)  (IPC9CLR = _IPC9_OC8IS_MASK, IPC9SET = ((subPriority) << _IPC9_OC8IS_POSITION))
#define mOC8GetIntSubPriority()             (IPC9bits.OC8IS)
#endif
#ifdef _OCMP9
/*********************************************************************
 * Output Compare 9 Interrupt Control Functions
 ********************************************************************/
#define mOC9ClearIntFlag()                  (IFS1CLR = _IFS1_OC9IF_MASK)
#define mOC9GetIntFlag()                    (IFS1bits.OC9IF)
#define mOC9GetIntEnable()                  (IEC1bits.OC9IE)
#define mOC9IntEnable(enable)               (IEC1CLR = _IEC1_OC9IE_MASK, IEC1SET = ((enable) << _IEC1_OC9IE_POSITION))
#define mOC9SetIntPriority(priority)        (IPC10CLR = _IPC10_OC9IP_MASK, IPC10SET = ((priority) << _IPC10_OC9IP_POSITION))
#define mOC9GetIntPriority()                (IPC10bits.OC9IP)
#define mOC9SetIntSubPriority(subPriority)  (IPC10CLR = _IPC10_OC9IS_MASK, IPC10SET = ((subPriority) << _IPC10_OC9IS_POSITION))
#define mOC9GetIntSubPriority()             (IPC10bits.OC9IS)
#endif

   
/*****************************************************************************************
 * <combinewith mCNGetIntEnable, mCNGetIntFlag, mCNGetIntPriority, mCNGetIntSubPriority,
 * mCNIntEnable, mCNSetIntPriority, mCNSetIntSubPriority, mCNGetIntSubPriority>
 *
 * Change Notice Interrupt Control Functions
 * Prototype:
 *     void mCNClearIntFlag(void) int mCNGetIntFlag(void) void
 *     mCNSetIntEnable(void) int mCNGetIntEnable(void) void
 *     mCNClearIntEnable(void) void mCNSetIntPriority(int priority)
 *     int mCNGetIntPriority(void) void
 *     mCNSetIntSubPriority(subPriority) int
 *     mCNGetIntSubPriority(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 ***************************************************************************************
 */

#define mCNAClearIntFlag()                   (IFS3CLR = _IFS3_CNAIF_MASK)
#define mCNAGetIntFlag()                     (IFS3bits.CNAIF)
#define mCNAGetIntEnable()                   (IEC3bits.CNAIE)
#define mCNAIntEnable(enable)                (IEC3CLR = _IEC3_CNAIE_MASK, IEC3SET = ((enable) << _IEC3_CNAIE_POSITION))

#define mCNBClearIntFlag()                   (IFS3CLR = _IFS3_CNBIF_MASK)
#define mCNBGetIntFlag()                     (IFS3bits.CNBIF)
#define mCNBGetIntEnable()                   (IEC3bits.CNBIE)
#define mCNBIntEnable(enable)                (IEC3CLR = _IEC3_CNBIE_MASK, IEC3SET = ((enable) << _IEC3_CNBIE_POSITION))

#define mCNCClearIntFlag()                   (IFS3CLR = _IFS3_CNCIF_MASK)
#define mCNCGetIntFlag()                     (IFS3bits.CNCIF)
#define mCNCGetIntEnable()                   (IEC3bits.CNCIE)
#define mCNCIntEnable(enable)                (IEC3CLR = _IEC3_CNCIE_MASK, IEC3SET = ((enable) << _IEC3_CNCIE_POSITION))

#define mCNDClearIntFlag()                   (IFS3CLR = _IFS3_CNDIF_MASK)
#define mCNDGetIntFlag()                     (IFS3bits.CNDIF)
#define mCNDGetIntEnable()                   (IEC3bits.CNDIE)
#define mCNDIntEnable(enable)                (IEC3CLR = _IEC3_CNDIE_MASK, IEC3SET = ((enable) << _IEC3_CNDIE_POSITION))

#define mCNEClearIntFlag()                   (IFS3CLR = _IFS3_CNEIF_MASK)
#define mCNEGetIntFlag()                     (IFS3bits.CNEIF)
#define mCNEGetIntEnable()                   (IEC3bits.CNEIE)
#define mCNEIntEnable(enable)                (IEC3CLR = _IEC3_CNEIE_MASK, IEC3SET = ((enable) << _IEC3_CNEIE_POSITION))

#define mCNFClearIntFlag()                   (IFS3CLR = _IFS3_CNFIF_MASK)
#define mCNFGetIntFlag()                     (IFS3bits.CNFIF)
#define mCNFGetIntEnable()                   (IEC3bits.CNFIE)
#define mCNFIntEnable(enable)                (IEC3CLR = _IEC3_CNFIE_MASK, IEC3SET = ((enable) << _IEC3_CNFIE_POSITION))

#define mCNGClearIntFlag()                   (IFS3CLR = _IFS3_CNGIF_MASK)
#define mCNGGetIntFlag()                     (IFS3bits.CNGIF)
#define mCNGGetIntEnable()                   (IEC3bits.CNGIE)
#define mCNGIntEnable(enable)                (IEC3CLR = _IEC3_CNGIE_MASK, IEC3SET = ((enable) << _IEC3_CNGIE_POSITION))
 
#define mCNHClearIntFlag()                   (IFS3CLR = _IFS3_CNHIF_MASK)
#define mCNHGetIntFlag()                     (IFS3bits.CNHIF)
#define mCNHGetIntEnable()                   (IEC3bits.CNHIE)
#define mCNHIntEnable(enable)                (IEC3CLR = _IEC3_CNHIE_MASK, IEC3SET = ((enable) << _IEC3_CNHIE_POSITION))

#define mCNJClearIntFlag()                   (IFS3CLR = _IFS3_CNJIF_MASK)
#define mCNJGetIntFlag()                     (IFS3bits.CNJIF)
#define mCNJGetIntEnable()                   (IEC3bits.CNJIE)
#define mCNJIntEnable(enable)                (IEC3CLR = _IEC3_CNJIE_MASK, IEC3SET = ((enable) << _IEC3_CNJIE_POSITION)) 

#define mCNKClearIntFlag()                   (IFS3CLR = _IFS3_CNKIF_MASK)
#define mCNKGetIntFlag()                     (IFS3bits.CNKIF)
#define mCNKGetIntEnable()                   (IEC3bits.CNKIE)
#define mCNKIntEnable(enable)                (IEC3CLR = _IEC3_CNKIE_MASK, IEC3SET = ((enable) << _IEC3_CNKIE_POSITION))    
        
#define mCNASetIntPriority(priority)         (IPC29CLR = _IPC29_CNAIP_MASK, IPC29SET = ((priority) << _IPC29_CNAIP_POSITION))
#define mCNAGetIntPriority()                 (IPC29bits.CNAIP)
#define mCNASetIntSubPriority(subPriority)   (IPC29CLR = _IPC29_CNAIS_MASK, IPC29SET = ((subPriority) << _IPC29_CNAIS_POSITION))
#define mCNAGetIntSubPriority()              (IPC29bits.CNAIS)    
    
#define mCNBSetIntPriority(priority)         (IPC29CLR = _IPC29_CNBIP_MASK, IPC29SET = ((priority) << _IPC29_CNBIP_POSITION))
#define mCNBGetIntPriority()                 (IPC29bits.CNBIP)
#define mCNBSetIntSubPriority(subPriority)   (IPC29CLR = _IPC29_CNBIS_MASK, IPC29SET = ((subPriority) << _IPC29_CNBIS_POSITION))
#define mCNBGetIntSubPriority()              (IPC29bits.CNBIS)  
    
#define mCNCSetIntPriority(priority)         (IPC30CLR = _IPC30_CNCIP_MASK, IPC30SET = ((priority) << _IPC30_CNCIP_POSITION))
#define mCNCGetIntPriority()                 (IPC30bits.CNCIP)
#define mCNCSetIntSubPriority(subPriority)   (IPC30CLR = _IPC30_CNCIS_MASK, IPC30SET = ((subPriority) << _IPC30_CNCIS_POSITION))
#define mCNCGetIntSubPriority()              (IPC30bits.CNCIS)      
    
#define mCNDSetIntPriority(priority)         (IPC30CLR = _IPC30_CNDIP_MASK, IPC30SET = ((priority) << _IPC30_CNDIP_POSITION))
#define mCNDGetIntPriority()                 (IPC30bits.CNDIP)
#define mCNDSetIntSubPriority(subPriority)   (IPC30CLR = _IPC30_CNDIS_MASK, IPC30SET = ((subPriority) << _IPC30_CNDIS_POSITION))
#define mCNDGetIntSubPriority()              (IPC30bits.CNDIS)
    
#define mCNESetIntPriority(priority)         (IPC30CLR = _IPC30_CNEIP_MASK, IPC30SET = ((priority) << _IPC30_CNEIP_POSITION))
#define mCNEGetIntPriority()                 (IPC30bits.CNEIP)
#define mCNESetIntSubPriority(subPriority)   (IPC30CLR = _IPC30_CNEIS_MASK, IPC30SET = ((subPriority) << _IPC30_CNEIS_POSITION))
#define mCNEGetIntSubPriority()              (IPC30bits.CNEIS)
    
#define mCNFSetIntPriority(priority)         (IPC30CLR = _IPC30_CNFIP_MASK, IPC30SET = ((priority) << _IPC30_CNFIP_POSITION))
#define mCNFGetIntPriority()                 (IPC30bits.CNFIP)
#define mCNFSetIntSubPriority(subPriority)   (IPC30CLR = _IPC30_CNFIS_MASK, IPC30SET = ((subPriority) << _IPC30_CNFIS_POSITION))
#define mCNFGetIntSubPriority()              (IPC30bits.CNFIS)
    
#define mCNGSetIntPriority(priority)         (IPC31CLR = _IPC31_CNGIP_MASK, IPC31SET = ((priority) << _IPC31_CNGIP_POSITION))
#define mCNGGetIntPriority()                 (IPC31bits.CNGIP)
#define mCNGSetIntSubPriority(subPriority)   (IPC31CLR = _IPC31_CNGIS_MASK, IPC31SET = ((subPriority) << _IPC31_CNGIS_POSITION))
#define mCNGGetIntSubPriority()              (IPC31bits.CNGIS) 
    
#define mCNHSetIntPriority(priority)         (IPC31CLR = _IPC31_CNHIP_MASK, IPC31SET = ((priority) << _IPC31_CNHIP_POSITION))
#define mCNHGetIntPriority()                 (IPC31bits.CNHIP)
#define mCNHSetIntSubPriority(subPriority)   (IPC31CLR = _IPC31_CNHIS_MASK, IPC31SET = ((subPriority) << _IPC31_CNHIS_POSITION))
#define mCNHGetIntSubPriority()              (IPC31bits.CNHIS)
    
#define mCNJSetIntPriority(priority)         (IPC31CLR = _IPC31_CNJIP_MASK, IPC31SET = ((priority) << _IPC31_CNJIP_POSITION))
#define mCNJGetIntPriority()                 (IPC31bits.CNJIP)
#define mCNJSetIntSubPriority(subPriority)   (IPC31CLR = _IPC31_CNJIS_MASK, IPC31SET = ((subPriority) << _IPC31_CNJIS_POSITION))
#define mCNJGetIntSubPriority()              (IPC31bits.CNJIS)   
    
#define mCNKSetIntPriority(priority)         (IPC31CLR = _IPC31_CNKIP_MASK, IPC31SET = ((priority) << _IPC31_CNKIP_POSITION))
#define mCNKGetIntPriority()                 (IPC31bits.CNKIP)
#define mCNKSetIntSubPriority(subPriority)   (IPC31CLR = _IPC31_CNKIS_MASK, IPC31SET = ((subPriority) << _IPC31_CNKIS_POSITION))
#define mCNKGetIntSubPriority()              (IPC31bits.CNKIS)     
   

/******************************************************************************************************************************************
 * <combinewith mSPI1EGetIntFlag, mSPI1EGetIntEnable, mSPI1EIntEnable, mSPI1TXClearIntFlag, mSPI1TXGetIntFlag, mSPI1TXGetIntEnable, mSPI1TXIntEnable,
 * mSPI1RXClearIntFlag, mSPI1RXGetIntFlag, mSPI1RXGetIntEnable, mSPI1RXIntEnable, mSPI1ClearAllIntFlags, mSPI1IntDisable, mSPI1SetIntEnable,
 * mSPI1SetIntPriority, mSPI1GetIntPriority, mSPI1SetIntSubPriority, mSPI1GetIntSubPriority,
 * mSPI2EClearIntFlag, mSPI2EGetIntFlag, mSPI2EGetIntEnable, mSPI2EIntEnable, mSPI2TXClearIntFlag, mSPI2TXGetIntFlag, mSPI2TXGetIntEnable, mSPI2TXIntEnable,
 * mSPI2RXClearIntFlag, mSPI2RXGetIntFlag, mSPI2RXGetIntEnable, mSPI2RXIntEnable, mSPI2ClearAllIntFlags, mSPI2IntDisable, mSPI2SetIntEnable,
 * mSPI2SetIntPriority, mSPI2GetIntPriority, mSPI2SetIntSubPriority, mSPI2GetIntSubPriority>
 *
 * SPI x Interrupt Control Functions
 *
 * Function:        void    mSPIxEClearIntFlag(void)
 *                  int     mSPIxEGetIntFlag(void)
 *                  void    mSPIxESetIntEnable(void)
 *                  int     mSPIxEGetIntEnable(void)
 *                  void    mSPIxEClearIntEnable(void)
 *                  void    mSPIxTXClearIntFlag(void)
 *                  int     mSPIxTXGetIntFlag(void)
 *                  void    mSPIxTXSetIntEnable(void)
 *                  int     mSPIxTXGetIntEnable(void)
 *                  void    mSPIxTXClearIntEnable(void)
 *                  void    mSPIxRXClearIntFlag(void)
 *                  int     mSPIxRXGetIntFlag(void)
 *                  void    mSPIxRXSetIntEnable(void)
 *                  int     mSPIxRXGetIntEnable(void)
 *                  void    mSPIxRXClearIntEnable(void)
 *                  void    mSSPIxetPriority(int priority)
 *                  int     mSPIxGetIntPriority(void)
 *                  void    mSPIxSetIntSubPriority(subPriority)
 *                  int     mSPIxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *****************************************************************************************************************************************/    
    
#ifdef _SPI1
/*********************************************************************
 * SPI 1 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_1_VECTOR                               _SPI1_FAULT_VECTOR
/*********************************************************************
 * SPI 1 Fault
 ********************************************************************/
#define mSPI1EClearIntFlag()                        (IFS3CLR = _IFS3_SPI1EIF_MASK)
#define mSPI1EGetIntFlag()                          (IFS3bits.SPI1EIF)
#define mSPI1EGetIntEnable()                        (IEC3bits.SPI1EIE)
#define mSPI1EIntEnable(enable)                     (IEC3CLR = _IEC3_SPI1EIE_MASK, IEC3SET = ((enable) << _IEC3_SPI1EIE_POSITION))
#define mSPI1ESetIntPriority(priority)              (IPC27CLR = _IPC27_SPI1EIP_MASK, IPC27SET = ((priority) << _IPC27_SPI1EIP_POSITION))
#define mSPI1EGetIntPriority()                      (IPC27bits.SPI1EIP)
#define mSPI1ESetIntSubPriority(subPriority)        (IPC27CLR = _IPC27_SPI1EIS_MASK, IPC27SET = ((subPriority) << _IPC27_SPI1EIS_POSITION))
#define mSPI1EGetIntSubPriority()                   (IPC27bits.SPI1EIS)
/*********************************************************************
 * SPI 1 Receive
 ********************************************************************/
#define mSPI1RXClearIntFlag()                       (IFS3CLR = _IFS3_SPI1RXIF_MASK)
#define mSPI1RXGetIntFlag()                         (IFS3bits.SPI1RXIF)
#define mSPI1RXGetIntEnable()                       (IEC3bits.SPI1RXIE)
#define mSPI1RXIntEnable(enable)                    (IEC3CLR = _IEC3_SPI1RXIE_MASK, IEC3SET = ((enable) << _IEC3_SPI1RXIE_POSITION))
#define mSPI1RXSetIntPriority(priority)             (IPC27CLR = _IPC27_SPI1RXIP_MASK, IPC27SET = ((priority) << _IPC27_SPI1RXIP_POSITION))
#define mSPI1RXGetIntPriority()                     (IPC27bits.SPI1RXIP)
#define mSPI1RXSetIntSubPriority(subPriority)       (IPC27CLR = _IPC27_SPI1RXIS_MASK, IPC27SET = ((subPriority) << _IPC27_SPI1RXIS_POSITION))
#define mSPI1RXGetIntSubPriority()                  (IPC27bits.SPI1RXIS)
/*********************************************************************
 * SPI 1 Transfer
 ********************************************************************/
#define mSPI1TXClearIntFlag()                       (IFS3CLR = _IFS3_SPI1TXIF_MASK)
#define mSPI1TXGetIntFlag()                         (IFS3bits.SPI1TXIF)
#define mSPI1TXGetIntEnable()                       (IEC3bits.SPI1TXIE)
#define mSPI1TXIntEnable(enable)                    (IEC3CLR = _IEC3_SPI1TXIE_MASK, IEC3SET = ((enable) << _IEC3_SPI1TXIE_POSITION))
#define mSPI1TXSetIntPriority(priority)             (IPC27CLR = _IPC27_SPI1TXIP_MASK, IPC27SET = ((priority) << _IPC27_SPI1TXIP_POSITION))
#define mSPI1TXGetIntPriority()                     (IPC27bits.SPI1TXIP)
#define mSPI1TXSetIntSubPriority(subPriority)       (IPC27CLR = _IPC27_SPI1TXIS_MASK, IPC27SET = ((subPriority) << _IPC27_SPI1TXIS_POSITION))
#define mSPI1TXGetIntSubPriority()                  (IPC27bits.SPI1TXIS)
/*********************************************************************
 * SPI 1 All
 ********************************************************************/
#define mSPI1ClearAllIntFlags()                     (IFS3CLR = (_IFS3_SPI1EIF_MASK | _IFS3_SPI1TXIF_MASK | _IFS3_SPI1RXIF_MASK))
#define mSPI1IntDisable()                           (IEC3CLR = (_IEC3_SPI1EIE_MASK | _IEC3_SPI1TXIE_MASK | _IEC3_SPI1RXIE_MASK))
#define mSPI1SetIntEnable(flags)                    (IEC3SET = (((flags) & 0x7) << _IEC3_SPI1EIE_POSITION))
#define mSPI1UnifiedIntVector()                     (OFF111bits.VOFF = OFF110bits.VOFF = OFF109bits.VOFF)
#endif
#ifdef _SPI2
/*********************************************************************
 * SPI 2 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_2_VECTOR                               _SPI2_FAULT_VECTOR
/*********************************************************************
 * SPI 2 Fault
 ********************************************************************/
#define mSPI2EClearIntFlag()                        (IFS4CLR = _IFS4_SPI2EIF_MASK)
#define mSPI2EGetIntFlag()                          (IFS4bits.SPI2EIF)
#define mSPI2EGetIntEnable()                        (IEC4bits.SPI2EIE)
#define mSPI2EIntEnable(enable)                     (IEC4CLR = _IEC4_SPI2EIE_MASK, IEC4SET = ((enable) << _IEC4_SPI2EIE_POSITION))
#define mSPI2ESetIntPriority(priority)              (IPC35CLR = _IPC35_SPI2EIP_MASK, IPC35SET = ((priority) << _IPC35_SPI2EIP_POSITION))
#define mSPI2EGetIntPriority()                      (IPC35bits.SPI2EIP)
#define mSPI2ESetIntSubPriority(subPriority)        (IPC35CLR = _IPC35_SPI2EIS_MASK, IPC35SET = ((subPriority) << _IPC35_SPI2EIS_POSITION))
#define mSPI2EGetIntSubPriority()                   (IPC35bits.SPI2EIS)
/*********************************************************************
 * SPI 2 Receive
 ********************************************************************/
#define mSPI2RXClearIntFlag()                       (IFS4CLR = _IFS4_SPI2RXIF_MASK)
#define mSPI2RXGetIntFlag()                         (IFS4bits.SPI2RXIF)
#define mSPI2RXGetIntEnable()                       (IEC4bits.SPI2RXIE)
#define mSPI2RXIntEnable(enable)                    (IEC4CLR = _IEC4_SPI2RXIE_MASK, IEC4SET = ((enable) << _IEC4_SPI2RXIE_POSITION))
#define mSPI2RXSetIntPriority(priority)             (IPC35CLR = _IPC35_SPI2RXIP_MASK, IPC35SET = ((priority) << _IPC35_SPI2RXIP_POSITION))
#define mSPI2RXGetIntPriority()                     (IPC35bits.SPI2RXIP)
#define mSPI2RXSetIntSubPriority(subPriority)       (IPC35CLR = _IPC35_SPI2RXIS_MASK, IPC35SET = ((subPriority) << _IPC35_SPI2RXIS_POSITION))
#define mSPI2RXGetIntSubPriority()                  (IPC35bits.SPI2RXIS)
/*********************************************************************
 * SPI 2 Transfer
 ********************************************************************/
#define mSPI2TXClearIntFlag()                       (IFS4CLR = _IFS4_SPI2TXIF_MASK)
#define mSPI2TXGetIntFlag()                         (IFS4bits.SPI2TXIF)
#define mSPI2TXGetIntEnable()                       (IEC4bits.SPI2TXIE)
#define mSPI2TXIntEnable(enable)                    (IEC4CLR = _IEC4_SPI2TXIE_MASK, IEC4SET = ((enable) << _IEC4_SPI2TXIE_POSITION))
#define mSPI2TXSetIntPriority(priority)             (IPC36CLR = _IPC36_SPI2TXIP_MASK, IPC36SET = ((priority) << _IPC36_SPI2TXIP_POSITION))
#define mSPI2TXGetIntPriority()                     (IPC36bits.SPI2TXIP)
#define mSPI2TXSetIntSubPriority(subPriority)       (IPC36CLR = _IPC36_SPI2TXIS_MASK, IPC36SET = ((subPriority) << _IPC36_SPI2TXIS_POSITION))
#define mSPI2TXGetIntSubPriority()                  (IPC36bits.SPI2TXIS)
/*********************************************************************
 * SPI 2 All
 ********************************************************************/
#define mSPI2ClearAllIntFlags()                     (IFS4CLR = (_IFS4_SPI2EIF_MASK | _IFS4_SPI2TXIF_MASK | _IFS4_SPI2RXIF_MASK))
#define mSPI2IntDisable()                           (IEC4CLR = (_IEC4_SPI2EIE_MASK | _IEC4_SPI2TXIE_MASK | _IEC4_SPI2RXIE_MASK))
#define mSPI2SetIntEnable(flags)                    (IEC4SET = (((flags) & 0x7) << _IEC4_SPI2EIE_POSITION))
#define mSPI2UnifiedIntVector()                     (OFF144bits.VOFF = OFF143bits.VOFF = OFF142bits.VOFF)
#endif     
#ifdef _SPI3
/*********************************************************************
 * SPI 3 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_3_VECTOR                               _SPI3_FAULT_VECTOR
/*********************************************************************
 * SPI 3 Fault
 ********************************************************************/
#define mSPI3EClearIntFlag()                        (IFS4CLR = _IFS4_SPI3EIF_MASK)
#define mSPI3EGetIntFlag()                          (IFS4bits.SPI3EIF)
#define mSPI3EGetIntEnable()                        (IEC4bits.SPI3EIE)
#define mSPI3EIntEnable(enable)                     (IEC4CLR = _IEC4_SPI3EIE_MASK, IEC4SET = ((enable) << _IEC4_SPI3EIE_POSITION))
#define mSPI3ESetIntPriority(priority)              (IPC38CLR = _IPC38_SPI3EIP_MASK, IPC38SET = ((priority) << _IPC38_SPI3EIP_POSITION))
#define mSPI3EGetIntPriority()                      (IPC38bits.SPI3EIP)
#define mSPI3ESetIntSubPriority(subPriority)        (IPC38CLR = _IPC38_SPI3EIS_MASK, IPC38SET = ((subPriority) << _IPC38_SPI3EIS_POSITION))
#define mSPI3EGetIntSubPriority()                   (IPC38bits.SPI3EIS)
/*********************************************************************
 * SPI 3 Receive
 ********************************************************************/
#define mSPI3RXClearIntFlag()                       (IFS4CLR = _IFS4_SPI3RXIF_MASK)
#define mSPI3RXGetIntFlag()                         (IFS4bits.SPI3RXIF)
#define mSPI3RXGetIntEnable()                       (IEC4bits.SPI3RXIE)
#define mSPI3RXIntEnable(enable)                    (IEC4CLR = _IEC4_SPI3RXIE_MASK, IEC4SET = ((enable) << _IEC4_SPI3RXIE_POSITION))
#define mSPI3RXSetIntPriority(priority)             (IPC38CLR = _IPC38_SPI3RXIP_MASK, IPC38SET = ((priority) << _IPC38_SPI3RXIP_POSITION))
#define mSPI3RXGetIntPriority()                     (IPC38bits.SPI3RXIP)
#define mSPI3RXSetIntSubPriority(subPriority)       (IPC38CLR = _IPC38_SPI3RXIS_MASK, IPC38SET = ((subPriority) << _IPC38_SPI3RXIS_POSITION))
#define mSPI3RXGetIntSubPriority()                  (IPC38bits.SPI3RXIS)
/*********************************************************************
 * SPI 3 Transfer
 ********************************************************************/
#define mSPI3TXClearIntFlag()                       (IFS4CLR = _IFS4_SPI3TXIF_MASK)
#define mSPI3TXGetIntFlag()                         (IFS4bits.SPI3TXIF)
#define mSPI3TXGetIntEnable()                       (IEC4bits.SPI3TXIE)
#define mSPI3TXIntEnable(enable)                    (IEC4CLR = _IEC4_SPI3TXIE_MASK, IEC4SET = ((enable) << _IEC4_SPI3TXIE_POSITION))
#define mSPI3TXSetIntPriority(priority)             (IPC39CLR = _IPC39_SPI3TXIP_MASK, IPC39SET = ((priority) << _IPC39_SPI3TXIP_POSITION))
#define mSPI3TXGetIntPriority()                     (IPC39bits.SPI3TXIP)
#define mSPI3TXSetIntSubPriority(subPriority)       (IPC39CLR = _IPC39_SPI3TXIS_MASK, IPC39SET = ((subPriority) << _IPC39_SPI3TXIS_POSITION))
#define mSPI3TXGetIntSubPriority()                  (IPC39bits.SPI3TXIS)
/*********************************************************************
 * SPI 3 All
 ********************************************************************/
#define mSPI3ClearAllIntFlags()                     (IFS4CLR = (_IFS4_SPI3EIF_MASK | _IFS4_SPI3TXIF_MASK | _IFS4_SPI3RXIF_MASK))
#define mSPI3IntDisable()                           (IEC4CLR = (_IEC4_SPI3EIE_MASK | _IEC4_SPI3TXIE_MASK | _IEC4_SPI3RXIE_MASK))
#define mSPI3SetIntEnable(flags)                    (IEC4SET = (((flags) & 0x7) << _IEC4_SPI3EIE_POSITION))
#define mSPI3UnifiedIntVector()                     (OFF156bits.VOFF = OFF155bits.VOFF = OFF154bits.VOFF)
#endif     
#ifdef _SPI4
/*********************************************************************
 * SPI 4 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_4_VECTOR                               _SPI4_FAULT_VECTOR
/*********************************************************************
 * SPI 4 Fault
 ********************************************************************/
#define mSPI4EClearIntFlag()                        (IFS5CLR = _IFS5_SPI4EIF_MASK)
#define mSPI4EGetIntFlag()                          (IFS5bits.SPI4EIF)
#define mSPI4EGetIntEnable()                        (IEC5bits.SPI4EIE)
#define mSPI4EIntEnable(enable)                     (IEC5CLR = _IEC5_SPI4EIE_MASK, IEC5SET = ((enable) << _IEC5_SPI4EIE_POSITION))
#define mSPI4ESetIntPriority(priority)              (IPC40CLR = _IPC40_SPI4EIP_MASK, IPC40SET = ((priority) << _IPC40_SPI4EIP_POSITION))
#define mSPI4EGetIntPriority()                      (IPC40bits.SPI4EIP)
#define mSPI4ESetIntSubPriority(subPriority)        (IPC40CLR = _IPC40_SPI4EIS_MASK, IPC40SET = ((subPriority) << _IPC40_SPI4EIS_POSITION))
#define mSPI4EGetIntSubPriority()                   (IPC40bits.SPI4EIS)
/*********************************************************************
 * SPI 4 Receive
 ********************************************************************/
#define mSPI4RXClearIntFlag()                       (IFS5CLR = _IFS5_SPI4RXIF_MASK)
#define mSPI4RXGetIntFlag()                         (IFS5bits.SPI4RXIF)
#define mSPI4RXGetIntEnable()                       (IEC5bits.SPI4RXIE)
#define mSPI4RXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI4RXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI4RXIE_POSITION))
#define mSPI4RXSetIntPriority(priority)             (IPC41CLR = _IPC41_SPI4RXIP_MASK, IPC41SET = ((priority) << _IPC41_SPI4RXIP_POSITION))
#define mSPI4RXGetIntPriority()                     (IPC41bits.SPI4RXIP)
#define mSPI4RXSetIntSubPriority(subPriority)       (IPC41CLR = _IPC41_SPI4RXIS_MASK, IPC41SET = ((subPriority) << _IPC41_SPI4RXIS_POSITION))
#define mSPI4RXGetIntSubPriority()                  (IPC41bits.SPI4RXIS)
/*********************************************************************
 * SPI 4 Transfer
 ********************************************************************/
#define mSPI4TXClearIntFlag()                       (IFS5CLR = _IFS5_SPI4TXIF_MASK)
#define mSPI4TXGetIntFlag()                         (IFS5bits.SPI4TXIF)
#define mSPI4TXGetIntEnable()                       (IEC5bits.SPI4TXIE)
#define mSPI4TXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI4TXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI4TXIE_POSITION))
#define mSPI4TXSetIntPriority(priority)             (IPC41CLR = _IPC41_SPI4TXIP_MASK, IPC41SET = ((priority) << _IPC41_SPI4TXIP_POSITION))
#define mSPI4TXGetIntPriority()                     (IPC41bits.SPI4TXIP)
#define mSPI4TXSetIntSubPriority(subPriority)       (IPC41CLR = _IPC41_SPI4TXIS_MASK, IPC41SET = ((subPriority) << _IPC41_SPI4TXIS_POSITION))
#define mSPI4TXGetIntSubPriority()                  (IPC41bits.SPI4TXIS)
/*********************************************************************
 * SPI 4 All
 ********************************************************************/
#define mSPI4ClearAllIntFlags()                     (IFS5CLR = (_IFS5_SPI4EIF_MASK | _IFS5_SPI4TXIF_MASK | _IFS5_SPI4RXIF_MASK))
#define mSPI4IntDisable()                           (IEC5CLR = (_IEC5_SPI4EIE_MASK | _IEC5_SPI4TXIE_MASK | _IEC5_SPI4RXIE_MASK))
#define mSPI4SetIntEnable(flags)                    (IEC5SET = (((flags) & 0x7) << _IEC5_SPI4EIE_POSITION))
#define mSPI4UnifiedIntVector()                     (OFF165bits.VOFF = OFF164bits.VOFF = OFF163bits.VOFF)
#endif         
#ifdef _SPI5
/*********************************************************************
 * SPI 5 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_5_VECTOR                               _SPI5_FAULT_VECTOR
/*********************************************************************
 * SPI 5 Fault
 ********************************************************************/
#define mSPI5EClearIntFlag()                        (IFS5CLR = _IFS5_SPI5EIF_MASK)
#define mSPI5EGetIntFlag()                          (IFS5bits.SPI5EIF)
#define mSPI5EGetIntEnable()                        (IEC5bits.SPI5EIE)
#define mSPI5EIntEnable(enable)                     (IEC5CLR = _IEC5_SPI5EIE_MASK, IEC5SET = ((enable) << _IEC5_SPI5EIE_POSITION))
#define mSPI5ESetIntPriority(priority)              (IPC44CLR = _IPC44_SPI5EIP_MASK, IPC44SET = ((priority) << _IPC44_SPI5EIP_POSITION))
#define mSPI5EGetIntPriority()                      (IPC44bits.SPI5EIP)
#define mSPI5ESetIntSubPriority(subPriority)        (IPC44CLR = _IPC44_SPI5EIS_MASK, IPC44SET = ((subPriority) << _IPC44_SPI5EIS_POSITION))
#define mSPI5EGetIntSubPriority()                   (IPC44bits.SPI5EIS)
/*********************************************************************
 * SPI 5 Receive
 ********************************************************************/
#define mSPI5RXClearIntFlag()                       (IFS5CLR = _IFS5_SPI5RXIF_MASK)
#define mSPI5RXGetIntFlag()                         (IFS5bits.SPI5RXIF)
#define mSPI5RXGetIntEnable()                       (IEC5bits.SPI5RXIE)
#define mSPI5RXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI5RXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI5RXIE_POSITION))
#define mSPI5RXSetIntPriority(priority)             (IPC44CLR = _IPC44_SPI5RXIP_MASK, IPC44SET = ((priority) << _IPC44_SPI5RXIP_POSITION))
#define mSPI5RXGetIntPriority()                     (IPC44bits.SPI5RXIP)
#define mSPI5RXSetIntSubPriority(subPriority)       (IPC44CLR = _IPC44_SPI5RXIS_MASK, IPC44SET = ((subPriority) << _IPC44_SPI5RXIS_POSITION))
#define mSPI5RXGetIntSubPriority()                  (IPC44bits.SPI5RXIS)
/*********************************************************************
 * SPI 5 Transfer
 ********************************************************************/
#define mSPI5TXClearIntFlag()                       (IFS5CLR = _IFS5_SPI5TXIF_MASK)
#define mSPI5TXGetIntFlag()                         (IFS5bits.SPI5TXIF)
#define mSPI5TXGetIntEnable()                       (IEC5bits.SPI5TXIE)
#define mSPI5TXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI5TXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI5TXIE_POSITION))
#define mSPI5TXSetIntPriority(priority)             (IPC44CLR = _IPC44_SPI5TXIP_MASK, IPC44SET = ((priority) << _IPC44_SPI5TXIP_POSITION))
#define mSPI5TXGetIntPriority()                     (IPC44bits.SPI5TXIP)
#define mSPI5TXSetIntSubPriority(subPriority)       (IPC44CLR = _IPC44_SPI5TXIS_MASK, IPC44SET = ((subPriority) << _IPC44_SPI5TXIS_POSITION))
#define mSPI5TXGetIntSubPriority()                  (IPC44bits.SPI5TXIS)
/*********************************************************************
 * SPI 5 All
 ********************************************************************/
#define mSPI5ClearAllIntFlags()                     (IFS5CLR = (_IFS5_SPI5EIF_MASK | _IFS5_SPI5TXIF_MASK | _IFS5_SPI5RXIF_MASK))
#define mSPI5IntDisable()                           (IEC5CLR = (_IEC5_SPI5EIE_MASK | _IEC5_SPI5TXIE_MASK | _IEC5_SPI5RXIE_MASK))
#define mSPI5SetIntEnable(flags)                    (IEC5SET = (((flags) & 0x7) << _IEC5_SPI5EIE_POSITION))
#define mSPI5UnifiedIntVector()                     (OFF178bits.VOFF = OFF177bits.VOFF = OFF176bits.VOFF)
#endif      
#ifdef _SPI6
#if defined(_IFS5_SPI6IF_POSITION)  
    #define _IFS5_SPI6EIF_POSITION                      _IFS5_SPI6IF_POSITION
    #define SPI6EIF                                     SPI6IF  
    #define SPI6EIE                                     SPI6IE 
#endif
#if defined(_IFS5_SPI6IF_MASK)
    #define _IFS5_SPI6EIF_MASK                          _IFS5_SPI6IF_MASK
#endif
#if defined(_IFS5_SPI6IF_LENGTH)
    #define _IFS5_SPI6EIF_LENGTH                        _IFS5_SPI6IF_LENGTH  
#endif  
    
#if defined(_IFS5_SPI6TX_POSITION)    
    #define _IFS5_SPI6TXIF_POSITION                     _IFS5_SPI6TX_POSITION
    #define SPI6TXIF                                    SPI6TX
#endif 
#if defined(_IFS5_SPI6TX_MASK)     
    #define _IFS5_SPI6TXIF_MASK                         _IFS5_SPI6TX_MASK
#endif
#if defined(_IFS5_SPI6TX_LENGTH)    
    #define _IFS5_SPI6TXIF_LENGTH                       _IFS5_SPI6TX_LENGTH   
#endif    
#if defined(_IEC5_SPI6IE_POSITION)     
    #define _IEC5_SPI6EIE_POSITION                      _IEC5_SPI6IE_POSITION
#endif
#if defined(_IEC5_SPI6IE_MASK) 
    #define _IEC5_SPI6EIE_MASK                          _IEC5_SPI6IE_MASK
#endif
#if defined(_IEC5_SPI6IE_LENGTH) 
    #define _IEC5_SPI6EIE_LENGTH                        _IEC5_SPI6IE_LENGTH   
#endif    
/*********************************************************************
 * SPI 6 legacy int vector define (unified)
 ********************************************************************/  
#define _SPI_6_VECTOR                               _SPI6_FAULT_VECTOR    
/*********************************************************************
 * SPI 6 Fault
 ********************************************************************/
#define mSPI6EClearIntFlag()                        (IFS5CLR = _IFS5_SPI6EIF_MASK)
#define mSPI6EGetIntFlag()                          (IFS5bits.SPI6EIF)
#define mSPI6EGetIntEnable()                        (IEC5bits.SPI6EIE)
#define mSPI6EIntEnable(enable)                     (IEC5CLR = _IEC5_SPI6EIE_MASK, IEC5SET = ((enable) << _IEC5_SPI6EIE_POSITION))
#define mSPI6ESetIntPriority(priority)              (IPC46CLR = _IPC46_SPI6EIP_MASK, IPC46SET = ((priority) << _IPC46_SPI6EIP_POSITION))
#define mSPI6EGetIntPriority()                      (IPC46bits.SPI6EIP)
#define mSPI6ESetIntSubPriority(subPriority)        (IPC46CLR = _IPC46_SPI6EIS_MASK, IPC46SET = ((subPriority) << _IPC46_SPI6EIS_POSITION))
#define mSPI6EGetIntSubPriority()                   (IPC46bits.SPI6EIS)
/*********************************************************************
 * SPI 6 Receive
 ********************************************************************/
#define mSPI6RXClearIntFlag()                       (IFS5CLR = _IFS5_SPI6RXIF_MASK)
#define mSPI6RXGetIntFlag()                         (IFS5bits.SPI6RXIF)
#define mSPI6RXGetIntEnable()                       (IEC5bits.SPI6RXIE)
#define mSPI6RXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI6RXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI6RXIE_POSITION))
#define mSPI6RXSetIntPriority(priority)             (IPC46CLR = _IPC46_SPI6RXIP_MASK, IPC46SET = ((priority) << _IPC46_SPI6RXIP_POSITION))
#define mSPI6RXGetIntPriority()                     (IPC46bits.SPI6RXIP)
#define mSPI6RXSetIntSubPriority(subPriority)       (IPC46CLR = _IPC46_SPI6RXIS_MASK, IPC46SET = ((subPriority) << _IPC46_SPI6RXIS_POSITION))
#define mSPI6RXGetIntSubPriority()                  (IPC46bits.SPI6RXIS)
/*********************************************************************
 * SPI 6 Transfer
 ********************************************************************/
#define mSPI6TXClearIntFlag()                       (IFS5CLR = _IFS5_SPI6TXIF_MASK)
#define mSPI6TXGetIntFlag()                         (IFS5bits.SPI6TXIF)
#define mSPI6TXGetIntEnable()                       (IEC5bits.SPI6TXIE)
#define mSPI6TXIntEnable(enable)                    (IEC5CLR = _IEC5_SPI6TXIE_MASK, IEC5SET = ((enable) << _IEC5_SPI6TXIE_POSITION))
#define mSPI6TXSetIntPriority(priority)             (IPC46CLR = _IPC46_SPI6TXIP_MASK, IPC46SET = ((priority) << _IPC46_SPI6TXIP_POSITION))
#define mSPI6TXGetIntPriority()                     (IPC46bits.SPI6TXIP)
#define mSPI6TXSetIntSubPriority(subPriority)       (IPC46CLR = _IPC46_SPI6TXIS_MASK, IPC46SET = ((subPriority) << _IPC46_SPI6TXIS_POSITION))
#define mSPI6TXGetIntSubPriority()                  (IPC46bits.SPI6TXIS)
/*********************************************************************
 * SPI 6 All
 ********************************************************************/
#define mSPI6ClearAllIntFlags()                     (IFS5CLR = (_IFS5_SPI6EIF_MASK | _IFS5_SPI6TXIF_MASK | _IFS5_SPI6RXIF_MASK))
#define mSPI6IntDisable()                           (IEC5CLR = (_IEC5_SPI6EIE_MASK | _IEC5_SPI6TXIE_MASK | _IEC5_SPI6RXIE_MASK))
#define mSPI6SetIntEnable(flags)                    (IEC5SET = (((flags) & 0x7) << _IEC5_SPI6EIE_POSITION))
#define mSPI6UnifiedIntVector()                     (OFF187bits.VOFF = OFF186bits.VOFF = OFF185bits.VOFF)
#endif    
      
/*********************************************************************
 * <combinewith mI2C1BGetIntFlag, mI2C1BGetIntEnable, mI2C1BIntEnable,
 * mI2C1SClearIntFlag, mI2C1SGetIntFlag, mI2C1SGetIntEnable, mI2C1SIntEnable, mI2C1MClearIntFlag,
 * mI2C1MGetIntFlag, mI2C1MGetIntEnable, mI2C1MIntEnable, mI2C1ClearAllIntFlags, mI2C1IntDisable,
 * mI2C1SetIntPriority, mI2C1GetIntPriority, mI2C1SetIntSubPriority, mI2C1GetIntSubPriority,
 * mI2C2BClearIntFlag, mI2C2BGetIntFlag, mI2C2BGetIntEnable, mI2C2BIntEnable,
 * mI2C2SClearIntFlag, mI2C2SGetIntFlag, mI2C2SGetIntEnable, mI2C2SIntEnable, mI2C2MClearIntFlag,
 * mI2C2MGetIntFlag, mI2C2MGetIntEnable, mI2C2MIntEnable, mI2C2ClearAllIntFlags, mI2C2IntDisable,
 * mI2C2SetIntPriority, mI2C2GetIntPriority, mI2C2SetIntSubPriority, mI2C2GetIntSubPriority>
 *
 * I2C x Interrupt Control Functions
 *
 * Function:        void    mI2CxBClearIntFlag(void)
 *                  int     mI2CxBGetIntFlag(void)
 *                  void    mI2CxBSetIntEnable(void)
 *                  int     mI2CxBGetIntEnable(void)
 *                  void    mI2CxBClearIntEnable(void)
 *                  void    mI2CxSClearIntFlag(void)
 *                  int     mI2CxSGetIntFlag(void)
 *                  void    mI2CxSSetIntEnable(void)
 *                  int     mI2CxSGetIntEnable(void)
 *                  void    mI2CxSClearIntEnable(void)
 *                  void    mI2CxMClearIntFlag(void)
 *                  int     mI2CxMGetIntFlag(void)
 *                  void    mI2CxMSetIntEnable(void)
 *                  int     mI2CxMGetIntEnable(void)
 *                  void    mI2CxMClearIntEnable(void)
 *                  void    mI2CxSetIntPriority(int priority)
 *                  int     mI2CxGetIntPriority(void)
 *                  void    mI2CxSetIntSubPriority(subPriority)
 *                  int     mI2CxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
#ifdef _I2C1
/*********************************************************************
 * I2C 1 legacy int vector define (unified)
 ********************************************************************/  
#define _I2C_1_VECTOR                           _I2C1_BUS_VECTOR
/*********************************************************************
 * I2C 1 Bus Collision
 ********************************************************************/
#define mI2C1BClearIntFlag()                    (IFS3CLR = _IFS3_I2C1BIF_MASK)
#define mI2C1BSetIntFlag()                      (IFS3SET = _IFS3_I2C1BIF_MASK)
#define mI2C1BGetIntFlag()                      (IFS3bits.I2C1BIF)
#define mI2C1BGetIntEnable()                    (IEC3bits.I2C1BIE)
#define mI2C1BIntEnable(enable)                 (IEC3CLR = _IEC3_I2C1BIE_MASK, IEC3SET = ((enable) << _IEC3_I2C1BIE_POSITION))
#define mI2C1BSetIntPriority(priority)          (IPC28CLR = _IPC28_I2C1BIP_MASK, IPC28SET = ((priority) << _IPC28_I2C1BIP_POSITION))
#define mI2C1BGetIntPriority()                  (IPC28bits.I2C1BIS)
#define mI2C1BSetIntSubPriority(subPriority)    (IPC28CLR = _IPC28_I2C1BIS_MASK, IPC28SET = ((subPriority) << _IPC28_I2C1BIS_POSITION))
#define mI2C1BGetIntSubPriority()               (IPC28bits.I2C1BIS)
/*********************************************************************
 * I2C 1 Slave
 ********************************************************************/
#define mI2C1SClearIntFlag()                    (IFS3CLR = _IFS3_I2C1SIF_MASK)
#define mI2C1SSetIntFlag()                      (IFS3SET = _IFS3_I2C1SIF_MASK)
#define mI2C1SGetIntFlag()                      (IFS3bits.I2C1SIF)
#define mI2C1SGetIntEnable()                    (IEC3bits.I2C1SIE)
#define mI2C1SIntEnable(enable)                 (IEC3CLR = _IEC3_I2C1SIE_MASK, IEC3SET = ((enable) << _IEC3_I2C1SIE_POSITION))
#define mI2C1SSetIntPriority(priority)          (IPC29CLR = _IPC29_I2C1SIP_MASK, IPC29SET = ((priority) << _IPC29_I2C1SIP_POSITION))
#define mI2C1SGetIntPriority()                  (IPC29bits.I2C1SIS)
#define mI2C1SSetIntSubPriority(subPriority)    (IPC29CLR = _IPC29_I2C1SIS_MASK, IPC29SET = ((subPriority) << _IPC29_I2C1SIS_POSITION))
#define mI2C1SGetIntSubPriority()               (IPC29bits.I2C1SIS)    
/*********************************************************************
 * I2C 1 Master
 ********************************************************************/
#define mI2C1MClearIntFlag()                    (IFS3CLR = _IFS3_I2C1MIF_MASK)
#define mI2C1MSetIntFlag()                      (IFS3SET = _IFS3_I2C1MIF_MASK)
#define mI2C1MGetIntFlag()                      (IFS3bits.I2C1MIF)
#define mI2C1MGetIntEnable()                    (IEC3bits.I2C1MIE)
#define mI2C1MIntEnable(enable)                 (IEC3CLR = _IEC3_I2C1MIE_MASK, IEC3SET = ((enable) << _IEC3_I2C1MIE_POSITION))
#define mI2C1MSetIntPriority(priority)          (IPC29CLR = _IPC29_I2C1MIP_MASK, IPC29SET = ((priority) << _IPC29_I2C1MIP_POSITION))
#define mI2C1MGetIntPriority()                  (IPC29bits.I2C1MIS)
#define mI2C1MSetIntSubPriority(subPriority)    (IPC29CLR = _IPC29_I2C1MIS_MASK, IPC29SET = ((subPriority) << _IPC29_I2C1MIS_POSITION))
#define mI2C1MGetIntSubPriority()               (IPC29bits.I2C1MIS)    
/*********************************************************************
 * I2C 1 All
 ********************************************************************/
#define mI2C1ClearAllIntFlags()                 (IFS3CLR = (_IFS3_I2C1BIF_MASK | _IFS3_I2C1SIF_MASK | _IFS3_I2C1MIF_MASK))
#define mI2C1IntDisable()                       (IEC3CLR = (_IEC3_I2C1BIE_MASK | _IEC3_I2C1SIE_MASK | _IEC3_I2C1MIE_MASK))
#define mI2C1SetIntEnable(flags)                (IEC3SET = (((flags) & 0x7) << _IEC3_I2C1BIE_POSITION))
#define mI2C1SetIntPriority(priority)           (IPC28CLR = _IPC28_I2C1BIP_MASK, IPC29CLR = _IPC29_I2C1SIP_MASK, IPC29CLR = _IPC29_I2C1MIP_MASK,\
                                                IPC28SET = ((priority) << _IPC28_I2C1BIP_POSITION),\
                                                IPC29SET = ((priority) << _IPC29_I2C1SIP_POSITION),\
                                                IPC29SET = ((priority) << _IPC29_I2C1MIP_POSITION))
#define mI2C1GetIntPriority()                   (IPC28bits.I2C1BIS)
#define mI2C1SetIntSubPriority(subPriority)     (IPC28CLR = _IPC28_I2C1BIS_MASK, IPC29CLR = _IPC29_I2C1SIS_MASK, IPC29CLR = _IPC29_I2C1MIS_MASK,\
                                                IPC28SET = ((subPriority) << _IPC28_I2C1BIS_POSITION),\
                                                IPC29SET = ((subPriority) << _IPC29_I2C1SIS_POSITION),\
                                                IPC29SET = ((subPriority) << _IPC29_I2C1MIS_POSITION))
#define mI2C1GetIntSubPriority()                (IPC28bits.I2C1BIS)
#define mI2C1UnifiedIntVector()                 (OFF117bits.VOFF = OFF116bits.VOFF = OFF115bits.VOFF)
#endif
#ifdef _I2C2
/*********************************************************************
 * I2C 2 legacy int vector define (unified)
 ********************************************************************/  
#define _I2C_2_VECTOR                           _I2C2_BUS_VECTOR
/*********************************************************************
 * I2C 2 Bus Collision
 ********************************************************************/
#define mI2C2BClearIntFlag()                    (IFS4CLR = _IFS4_I2C2BIF_MASK)
#define mI2C2BGetIntFlag()                      (IFS4bits.I2C2BIF)
#define mI2C2BGetIntEnable()                    (IEC4bits.I2C2BIE)
#define mI2C2BIntEnable(enable)                 (IEC4CLR = _IEC4_I2C2BIE_MASK, IEC4SET = ((enable) << _IEC4_I2C2BIE_POSITION))
#define mI2C2BSetIntPriority(priority)          (IPC37CLR = _IPC37_I2C2BIP_MASK, IPC37SET = ((priority) << _IPC37_I2C2BIP_POSITION))
#define mI2C2BGetIntPriority()                  (IPC37bits.I2C2BIS)
#define mI2C2BSetIntSubPriority(subPriority)    (IPC37CLR = _IPC37_I2C2BIS_MASK, IPC37SET = ((subPriority) << _IPC37_I2C2BIS_POSITION))
#define mI2C2BGetIntSubPriority()               (IPC37bits.I2C2BIS)
/*********************************************************************
 * I2C 2 Slave
 ********************************************************************/
#define mI2C2SClearIntFlag()                    (IFS4CLR = _IFS4_I2C2SIF_MASK)
#define mI2C2SGetIntFlag()                      (IFS4bits.I2C2SIF)
#define mI2C2SGetIntEnable()                    (IEC4bits.I2C2SIE)
#define mI2C2SIntEnable(enable)                 (IEC4CLR = _IEC4_I2C2SIE_MASK, IEC4SET = ((enable) << _IEC4_I2C2SIE_POSITION))
#define mI2C2SSetIntPriority(priority)          (IPC37CLR = _IPC37_I2C2SIP_MASK, IPC37SET = ((priority) << _IPC37_I2C2SIP_POSITION))
#define mI2C2SGetIntPriority()                  (IPC37bits.I2C2SIS)
#define mI2C2SSetIntSubPriority(subPriority)    (IPC37CLR = _IPC37_I2C2SIS_MASK, IPC37SET = ((subPriority) << _IPC37_I2C2SIS_POSITION))
#define mI2C2SGetIntSubPriority()               (IPC37bits.I2C2SIS)    
/*********************************************************************
 * I2C 2 Master
 ********************************************************************/
#define mI2C2MClearIntFlag()                    (IFS4CLR = _IFS4_I2C2MIF_MASK)
#define mI2C2MGetIntFlag()                      (IFS4bits.I2C2MIF)
#define mI2C2MGetIntEnable()                    (IEC4bits.I2C2MIE)
#define mI2C2MIntEnable(enable)                 (IEC4CLR = _IEC4_I2C2MIE_MASK, IEC4SET = ((enable) << _IEC4_I2C2MIE_POSITION))
#define mI2C2MSetIntPriority(priority)          (IPC37CLR = _IPC37_I2C2MIP_MASK, IPC37SET = ((priority) << _IPC37_I2C2MIP_POSITION))
#define mI2C2MGetIntPriority()                  (IPC37bits.I2C2MIS)
#define mI2C2MSetIntSubPriority(subPriority)    (IPC37CLR = _IPC37_I2C2MIS_MASK, IPC37SET = ((subPriority) << _IPC37_I2C2MIS_POSITION))
#define mI2C2MGetIntSubPriority()               (IPC37bits.I2C2MIS)    
/*********************************************************************
 * I2C 2 All
 ********************************************************************/
#define mI2C2ClearAllIntFlags()                 (IFS4CLR = (_IFS4_I2C2BIF_MASK | _IFS4_I2C2SIF_MASK | _IFS4_I2C2MIF_MASK))
#define mI2C2IntDisable()                       (IEC4CLR = (_IEC4_I2C2BIE_MASK | _IEC4_I2C2SIE_MASK | _IEC4_I2C2MIE_MASK))
#define mI2C2SetIntEnable(flags)                (IEC4SET = (((flags) & 0x7) << _IEC4_I2C2BIE_POSITION))
#define mI2C2SetIntPriority(priority)           (IPC37CLR = _IPC37_I2C2BIP_MASK, IPC37CLR = _IPC37_I2C2SIP_MASK, IPC37CLR = _IPC37_I2C2MIP_MASK,\
                                                IPC37SET = ((priority) << _IPC37_I2C2BIP_POSITION),\
                                                IPC37SET = ((priority) << _IPC37_I2C2SIP_POSITION),\
                                                IPC37SET = ((priority) << _IPC37_I2C2MIP_POSITION))
#define mI2C2GetIntPriority()                   (IPC37bits.I2C2BIS)
#define mI2C2SetIntSubPriority(subPriority)     (IPC37CLR = _IPC37_I2C2BIS_MASK, IPC37CLR = _IPC37_I2C2SIS_MASK, IPC37CLR = _IPC37_I2C2MIS_MASK,\
                                                IPC37SET = ((subPriority) << _IPC37_I2C2BIS_POSITION),\
                                                IPC37SET = ((subPriority) << _IPC37_I2C2SIS_POSITION),\
                                                IPC37SET = ((subPriority) << _IPC37_I2C2MIS_POSITION))
#define mI2C2GetIntSubPriority()                (IPC37bits.I2C2BIS)
#define mI2C2UnifiedIntVector()                 (OFF150bits.VOFF = OFF149bits.VOFF = OFF148bits.VOFF)
#endif    
#ifdef _I2C3
/*********************************************************************
 * I2C 3 legacy int vector define (unified)
 ********************************************************************/  
#define _I2C_3_VECTOR                           _I2C3_BUS_VECTOR
/*********************************************************************
 * I2C 3 Bus Collision
 ********************************************************************/
#define mI2C3BClearIntFlag()                    (IFS5CLR = _IFS5_I2C3BIF_MASK)
#define mI2C3BGetIntFlag()                      (IFS5bits.I2C3BIF)
#define mI2C3BGetIntEnable()                    (IEC5bits.I2C3BIE)
#define mI2C3BIntEnable(enable)                 (IEC5CLR = _IEC5_I2C3BIE_MASK, IEC5SET = ((enable) << _IEC5_I2C3BIE_POSITION))
#define mI2C3BSetIntPriority(priority)          (IPC40CLR = _IPC40_I2C3BIP_MASK, IPC40SET = ((priority) << _IPC40_I2C3BIP_POSITION))
#define mI2C3BGetIntPriority()                  (IPC40bits.I2C3BIS)
#define mI2C3BSetIntSubPriority(subPriority)    (IPC40CLR = _IPC40_I2C3BIS_MASK, IPC40SET = ((subPriority) << _IPC40_I2C3BIS_POSITION))
#define mI2C3BGetIntSubPriority()               (IPC40bits.I2C3BIS)
/*********************************************************************
 * I2C 3 Slave
 ********************************************************************/
#define mI2C3SClearIntFlag()                    (IFS5CLR = _IFS5_I2C3SIF_MASK)
#define mI2C3SGetIntFlag()                      (IFS5bits.I2C3SIF)
#define mI2C3SGetIntEnable()                    (IEC5bits.I2C3SIE)
#define mI2C3SIntEnable(enable)                 (IEC5CLR = _IEC5_I2C3SIE_MASK, IEC5SET = ((enable) << _IEC5_I2C3SIE_POSITION))
#define mI2C3SSetIntPriority(priority)          (IPC40CLR = _IPC40_I2C3SIP_MASK, IPC40SET = ((priority) << _IPC40_I2C3SIP_POSITION))
#define mI2C3SGetIntPriority()                  (IPC40bits.I2C3SIS)
#define mI2C3SSetIntSubPriority(subPriority)    (IPC40CLR = _IPC40_I2C3SIS_MASK, IPC40SET = ((subPriority) << _IPC40_I2C3SIS_POSITION))
#define mI2C3SGetIntSubPriority()               (IPC40bits.I2C3SIS)
/*********************************************************************
 * I2C 3 Master
 ********************************************************************/
#define mI2C3MClearIntFlag()                    (IFS5CLR = _IFS5_I2C3MIF_MASK)
#define mI2C3MGetIntFlag()                      (IFS5bits.I2C3MIF)
#define mI2C3MGetIntEnable()                    (IEC5bits.I2C3MIE)
#define mI2C3MIntEnable(enable)                 (IEC5CLR = _IEC5_I2C3MIE_MASK, IEC5SET = ((enable) << _IEC5_I2C3MIE_POSITION))
#define mI2C3MSetIntPriority(priority)          (IPC40CLR = _IPC40_I2C3MIP_MASK, IPC40SET = ((priority) << _IPC40_I2C3MIP_POSITION))
#define mI2C3MGetIntPriority()                  (IPC40bits.I2C3MIS)
#define mI2C3MSetIntSubPriority(subPriority)    (IPC40CLR = _IPC40_I2C3MIS_MASK, IPC40SET = ((subPriority) << _IPC40_I2C3MIS_POSITION))
#define mI2C3MGetIntSubPriority()               (IPC40bits.I2C3MIS)  
/*********************************************************************
 * I2C 3 All
 ********************************************************************/
#define mI2C3ClearAllIntFlags()                 (IFS5CLR = (_IFS5_I2C3BIF_MASK | _IFS5_I2C3SIF_MASK | _IFS5_I2C3MIF_MASK))
#define mI2C3IntDisable()                       (IEC5CLR = (_IEC5_I2C3BIE_MASK | _IEC5_I2C3SIE_MASK | _IEC5_I2C3MIE_MASK))
#define mI2C3SetIntEnable(flags)                (IEC5SET = (((flags) & 0x7) << _IEC5_I2C3BIE_POSITION))
#define mI2C3SetIntPriority(priority)           (IPC40CLR = _IPC40_I2C3BIP_MASK, IPC40CLR = _IPC40_I2C3SIP_MASK, IPC40CLR = _IPC40_I2C3MIP_MASK,\
                                                IPC40SET = ((priority) << _IPC40_I2C3BIP_POSITION),\
                                                IPC40SET = ((priority) << _IPC40_I2C3SIP_POSITION),\
                                                IPC40SET = ((priority) << _IPC40_I2C3MIP_POSITION))
#define mI2C3GetIntPriority()                   (IPC40bits.I2C3BIS)
#define mI2C3SetIntSubPriority(subPriority)     (IPC40CLR = _IPC40_I2C3BIS_MASK, IPC40CLR = _IPC40_I2C3SIS_MASK, IPC40CLR = _IPC40_I2C3MIS_MASK,\
                                                IPC40SET = ((subPriority) << _IPC40_I2C3BIS_POSITION),\
                                                IPC40SET = ((subPriority) << _IPC40_I2C3SIS_POSITION),\
                                                IPC40SET = ((subPriority) << _IPC40_I2C3MIS_POSITION))
#define mI2C3GetIntSubPriority()                (IPC40bits.I2C3BIS)
#define mI2C3UnifiedIntVector()                 (OFF162bits.VOFF = OFF161bits.VOFF = OFF160bits.VOFF)
#endif
#ifdef _I2C4
/*********************************************************************
 * I2C 4 legacy int vector define (unified)
 ********************************************************************/  
#define _I2C_4_VECTOR                           _I2C4_BUS_VECTOR
/*********************************************************************
 * I2C 4 Bus Collision
 ********************************************************************/
#define mI2C4BClearIntFlag()                    (IFS5CLR = _IFS5_I2C4BIF_MASK)
#define mI2C4BGetIntFlag()                      (IFS5bits.I2C4BIF)
#define mI2C4BGetIntEnable()                    (IEC5bits.I2C4BIE)
#define mI2C4BIntEnable(enable)                 (IEC5CLR = _IEC5_I2C4BIE_MASK, IEC5SET = ((enable) << _IEC5_I2C4BIE_POSITION))
#define mI2C4BSetIntPriority(priority)          (IPC43CLR = _IPC43_I2C4BIP_MASK, IPC43SET = ((priority) << _IPC43_I2C4BIP_POSITION))
#define mI2C4BGetIntPriority()                  (IPC43bits.I2C4BIS)
#define mI2C4BSetIntSubPriority(subPriority)    (IPC43CLR = _IPC43_I2C4BIS_MASK, IPC43SET = ((subPriority) << _IPC43_I2C4BIS_POSITION))
#define mI2C4BGetIntSubPriority()               (IPC43bits.I2C4BIS)
/*********************************************************************
 * I2C 4 Slave
 ********************************************************************/
#define mI2C4SClearIntFlag()                    (IFS5CLR = _IFS5_I2C4SIF_MASK)
#define mI2C4SGetIntFlag()                      (IFS5bits.I2C4SIF)
#define mI2C4SGetIntEnable()                    (IEC5bits.I2C4SIE)
#define mI2C4SIntEnable(enable)                 (IEC5CLR = _IEC5_I2C4SIE_MASK, IEC5SET = ((enable) << _IEC5_I2C4SIE_POSITION))
#define mI2C4SSetIntPriority(priority)          (IPC43CLR = _IPC43_I2C4SIP_MASK, IPC43SET = ((priority) << _IPC43_I2C4SIP_POSITION))
#define mI2C4SGetIntPriority()                  (IPC43bits.I2C4SIS)
#define mI2C4SSetIntSubPriority(subPriority)    (IPC43CLR = _IPC43_I2C4SIS_MASK, IPC43SET = ((subPriority) << _IPC43_I2C4SIS_POSITION))
#define mI2C4SGetIntSubPriority()               (IPC43bits.I2C4SIS)
/*********************************************************************
 * I2C 4 Master
 ********************************************************************/
#define mI2C4MClearIntFlag()                    (IFS5CLR = _IFS5_I2C4MIF_MASK)
#define mI2C4MGetIntFlag()                      (IFS5bits.I2C4MIF)
#define mI2C4MGetIntEnable()                    (IEC5bits.I2C4MIE)
#define mI2C4MIntEnable(enable)                 (IEC5CLR = _IEC5_I2C4MIE_MASK, IEC5SET = ((enable) << _IEC5_I2C4MIE_POSITION))
#define mI2C4MSetIntPriority(priority)          (IPC43CLR = _IPC43_I2C4MIP_MASK, IPC43SET = ((priority) << _IPC43_I2C4MIP_POSITION))
#define mI2C4MGetIntPriority()                  (IPC43bits.I2C4MIS)
#define mI2C4MSetIntSubPriority(subPriority)    (IPC43CLR = _IPC43_I2C4MIS_MASK, IPC43SET = ((subPriority) << _IPC43_I2C4MIS_POSITION))
#define mI2C4MGetIntSubPriority()               (IPC43bits.I2C4MIS)  
/*********************************************************************
 * I2C 4 All
 ********************************************************************/
#define mI2C4ClearAllIntFlags()                 (IFS5CLR = (_IFS5_I2C4BIF_MASK | _IFS5_I2C4SIF_MASK | _IFS5_I2C4MIF_MASK))
#define mI2C4IntDisable()                       (IEC5CLR = (_IEC5_I2C4BIE_MASK | _IEC5_I2C4SIE_MASK | _IEC5_I2C4MIE_MASK))
#define mI2C4SetIntEnable(flags)                (IEC5SET = (((flags) & 0x7) << _IEC5_I2C4BIE_POSITION))
#define mI2C4SetIntPriority(priority)           (IPC43CLR = _IPC43_I2C4BIP_MASK, IPC43CLR = _IPC43_I2C4SIP_MASK, IPC43CLR = _IPC43_I2C4MIP_MASK,\
                                                IPC43SET = ((priority) << _IPC43_I2C4BIP_POSITION),\
                                                IPC43SET = ((priority) << _IPC43_I2C4SIP_POSITION),\
                                                IPC43SET = ((priority) << _IPC43_I2C4MIP_POSITION))
#define mI2C4GetIntPriority()                   (IPC43bits.I2C4BIS)
#define mI2C4SetIntSubPriority(subPriority)     (IPC43CLR = _IPC43_I2C4BIS_MASK, IPC43CLR = _IPC43_I2C4SIS_MASK, IPC43CLR = _IPC43_I2C4MIS_MASK,\
                                                IPC43SET = ((subPriority) << _IPC43_I2C4BIS_POSITION),\
                                                IPC43SET = ((subPriority) << _IPC43_I2C4SIS_POSITION),\
                                                IPC43SET = ((subPriority) << _IPC43_I2C4MIS_POSITION))
#define mI2C4GetIntSubPriority()                (IPC43bits.I2C4BIS)
#define mI2C4UnifiedIntVector()                 (OFF175bits.VOFF = OFF174bits.VOFF = OFF173bits.VOFF)
#endif
#ifdef _I2C5
/*********************************************************************
 * I2C 5 legacy int vector define (unified)
 ********************************************************************/  
#define _I2C_5_VECTOR                           _I2C5_BUS_VECTOR
/*********************************************************************
 * I2C 5 Bus Collision
 ********************************************************************/
#define mI2C5BClearIntFlag()                    (IFS5CLR = _IFS5_I2C5BIF_MASK)
#define mI2C5BGetIntFlag()                      (IFS5bits.I2C5BIF)
#define mI2C5BGetIntEnable()                    (IEC5bits.I2C5BIE)
#define mI2C5BIntEnable(enable)                 (IEC5CLR = _IEC5_I2C5BIE_MASK, IEC5SET = ((enable) << _IEC5_I2C5BIE_POSITION))
#define mI2C5BSetIntPriority(priority)          (IPC45CLR = _IPC45_I2C5BIP_MASK, IPC45SET = ((priority) << _IPC45_I2C5BIP_POSITION))
#define mI2C5BGetIntPriority()                  (IPC45bits.I2C5BIS)
#define mI2C5BSetIntSubPriority(subPriority)    (IPC45CLR = _IPC45_I2C5BIS_MASK, IPC45SET = ((subPriority) << _IPC45_I2C5BIS_POSITION))
#define mI2C5BGetIntSubPriority()               (IPC45bits.I2C5BIS)
/*********************************************************************
 * I2C 5 Slave
 ********************************************************************/
#define mI2C5SClearIntFlag()                    (IFS5CLR = _IFS5_I2C5SIF_MASK)
#define mI2C5SGetIntFlag()                      (IFS5bits.I2C5SIF)
#define mI2C5SGetIntEnable()                    (IEC5bits.I2C5SIE)
#define mI2C5SIntEnable(enable)                 (IEC5CLR = _IEC5_I2C5SIE_MASK, IEC5SET = ((enable) << _IEC5_I2C5SIE_POSITION))
#define mI2C5SSetIntPriority(priority)          (IPC45CLR = _IPC45_I2C5SIP_MASK, IPC45SET = ((priority) << _IPC45_I2C5SIP_POSITION))
#define mI2C5SGetIntPriority()                  (IPC45bits.I2C5SIS)
#define mI2C5SSetIntSubPriority(subPriority)    (IPC45CLR = _IPC45_I2C5SIS_MASK, IPC45SET = ((subPriority) << _IPC45_I2C5SIS_POSITION))
#define mI2C5SGetIntSubPriority()               (IPC45bits.I2C5SIS)
/*********************************************************************
 * I2C 5 Master
 ********************************************************************/
#define mI2C5MClearIntFlag()                    (IFS5CLR = _IFS5_I2C5MIF_MASK)
#define mI2C5MGetIntFlag()                      (IFS5bits.I2C5MIF)
#define mI2C5MGetIntEnable()                    (IEC5bits.I2C5MIE)
#define mI2C5MIntEnable(enable)                 (IEC5CLR = _IEC5_I2C5MIE_MASK, IEC5SET = ((enable) << _IEC5_I2C5MIE_POSITION))
#define mI2C5MSetIntPriority(priority)          (IPC46CLR = _IPC46_I2C5MIP_MASK, IPC46SET = ((priority) << _IPC46_I2C5MIP_POSITION))
#define mI2C5MGetIntPriority()                  (IPC46bits.I2C5MIS)
#define mI2C5MSetIntSubPriority(subPriority)    (IPC465CLR = _IPC46_I2C5MIS_MASK, IPC46SET = ((subPriority) << _IPC46_I2C5MIS_POSITION))
#define mI2C5MGetIntSubPriority()               (IPC46bits.I2C5MIS)  
/*********************************************************************
 * I2C 5 All
 ********************************************************************/
#define mI2C5ClearAllIntFlags()                 (IFS5CLR = (_IFS5_I2C5BIF_MASK | _IFS5_I2C5SIF_MASK | _IFS5_I2C5MIF_MASK))
#define mI2C5IntDisable()                       (IEC5CLR = (_IEC5_I2C5BIE_MASK | _IEC5_I2C5SIE_MASK | _IEC5_I2C5MIE_MASK))
#define mI2C5SetIntEnable(flags)                (IEC5SET = (((flags) & 0x7) << _IEC5_I2C5BIE_POSITION))
#define mI2C5SetIntPriority(priority)           (IPC45CLR = _IPC45_I2C5BIP_MASK, IPC45CLR = _IPC45_I2C5SIP_MASK, IPC46CLR = _IPC46_I2C5MIP_MASK,\
                                                IPC45SET = ((priority) << _IPC45_I2C5BIP_POSITION),\
                                                IPC45SET = ((priority) << _IPC45_I2C5SIP_POSITION),\
                                                IPC46SET = ((priority) << _IPC46_I2C5MIP_POSITION))
#define mI2C5GetIntPriority()                   (IPC45bits.I2C5BIS)
#define mI2C5SetIntSubPriority(subPriority)     (IPC45CLR = _IPC45_I2C5BIS_MASK, IPC45CLR = _IPC45_I2C5SIS_MASK, IPC46CLR = _IPC46_I2C5MIS_MASK,\
                                                IPC45SET = ((subPriority) << _IPC45_I2C5BIS_POSITION),\
                                                IPC45SET = ((subPriority) << _IPC45_I2C5SIS_POSITION),\
                                                IPC46SET = ((subPriority) << _IPC46_I2C5MIS_POSITION))
#define mI2C5GetIntSubPriority()                (IPC45bits.I2C5BIS)
#define mI2C5UnifiedIntVector()                 (OFF184bits.VOFF = OFF183bits.VOFF = OFF182bits.VOFF)
#endif  
    

/******************************************************************************************************************************************************
 * <combinewith mAD1GetIntFlag, mAD1GetIntEnable, mAD1IntEnable, mAD1SetIntPriority,
 * mAD1GetIntPriority, mAD1SetIntSubPriority, mAD1GetIntSubPriority>
 *
 * Analog to Digital 1 Interrupt Control Functions
 * Prototype:
 *     void mAD1ClearIntFlag(void) int mAD1GetIntFlag(void) void
 *     mAD1SetIntEnable(void) int mAD1GetIntEnable(void) void
 *     mAD1ClearIntEnable(void) void mAD1SetIntPriority(int
 *     priority) int mAD1GetIntPriority(void) void
 *     mAD1SetIntSubPriority(subPriority) int
 *     mGAD1etSubPriority(void)
 * Preconditions:
 *     EBASE and IntCtl.VS set up
 * Input:
 *     priority :     A value between 0 \- 7 inclusive.
 *     subPriority :  A value between 0 \- 3 inclusive
 * Return:
 *     For 'Get' functions, the returned values are of
 *     same type as 'Set' functions.
 *
 * Side Effects:
 *     None
 * Remarks:
 *     None
 *****************************************************************************************************************************************************
 */    
#ifdef _ADCHS
//#define mAD1ClearIntFlag()                  (IFS0CLR = _IFS0_AD1IF_MASK )
//#define mAD1GetIntFlag()                    (IFS0bits.AD1IF)
//#define mAD1GetIntEnable()                  (IEC1bits.AD1IE)
//#define mAD1IntEnable(enable)               (IEC0CLR = _IEC0_AD1IE_MASK, IEC0SET = ((enable) << _IEC0_AD1IE_POSITION))
//#define mAD1SetIntPriority(priority)        (IPC5CLR = _IPC5_AD1IP_MASK, IPC5SET = ((priority) << _IPC5_AD1IP_POSITION))
//#define mAD1GetIntPriority()                (IPC5bits.AD1IP)
//#define mAD1SetIntSubPriority(subPriority)  (IPC5CLR = _IPC5_AD1IS_MASK, IPC5SET = ((subPriority) << _IPC5_AD1IS_POSITION))
//#define mAD1GetIntSubPriority()             (IPC5bits.AD1IS)
#endif   
    
    
/******************************************************************************************************************************************
 * <combinewith mU1EGetIntFlag, mU1EGetIntEnable, mU1EIntEnable, mU1TXClearIntFlag, mU1TXGetIntFlag, mU1TXGetIntEnable, mU1TXIntEnable,
 * mU1RXClearIntFlag, mU1RXGetIntFlag, mU1RXGetIntEnable, mU1RXIntEnable, mU1ClearAllIntFlags, mU1IntDisable, mU1SetIntEnable,
 * mU1SetIntPriority, mU1GetIntPriority, mU1SetIntSubPriority, mU1GetIntSubPriority,
 * mU2EClearIntFlag, mU2EGetIntFlag, mU2EGetIntEnable, mU2EIntEnable, mU2TXClearIntFlag, mU2TXGetIntFlag, mU2TXGetIntEnable, mU2TXIntEnable,
 * mU2RXClearIntFlag, mU2RXGetIntFlag, mU2RXGetIntEnable, mU2RXIntEnable, mU2ClearAllIntFlags, mU2IntDisable, mU2SetIntEnable,
 * mU2SetIntPriority, mU2GetIntPriority, mU2SetIntSubPriority, mU2GetIntSubPriority>
 *
 * UART x Interrupt Control Functions
 *
 * Function:        void    mUxEClearIntFlag(void)
 *                  int     mUxEGetIntFlag(void)
 *                  void    mUxESetIntEnable(void)
 *                  int     mUxEGetIntEnable(void)
 *                  void    mUxEClearIntEnable(void)
 *                  void    mUxTXClearIntFlag(void)
 *                  int     mUxTXGetIntFlag(void)
 *                  void    mUxTXSetIntEnable(void)
 *                  int     mUxTXGetIntEnable(void)
 *                  void    mUxTXClearIntEnable(void)
 *                  void    mUxRXClearIntFlag(void)
 *                  int     mUxRXGetIntFlag(void)
 *                  void    mUxRXSetIntEnable(void)
 *                  int     mUxRXGetIntEnable(void)
 *                  void    mUxRXClearIntEnable(void)
 *                  void    mUxSetIntPriority(int priority)
 *                  int     mUxGetIntPriority(void)
 *                  void    mUxSetIntSubPriority(subPriority)
 *                  int     mUxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 *****************************************************************************************************************************************/
#ifdef _UART1
/*********************************************************************
 * UART 1 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_1_VECTOR                          _UART1_FAULT_VECTOR
/*********************************************************************
 * UART 1 Fault
 ********************************************************************/
#define mU1EClearIntFlag()                      (IFS3CLR = _IFS3_U1EIF_MASK)
#define mU1EGetIntFlag()                        (IFS3bits.U1EIF)
#define mU1EGetIntEnable()                      (IEC3bits.U1EIE)
#define mU1EIntEnable(enable)                   (IEC3CLR = _IEC3_U1EIE_MASK, IEC3SET = ((enable) << _IEC3_U1EIE_POSITION))
#define mU1ESetIntPriority(priority)            (IPC28CLR = _IPC28_U1EIP_MASK, IPC28SET = ((priority) << _IPC28_U1EIP_POSITION))
#define mU1EGetIntPriority()                    (IPC28bits.U1EIP)
#define mU1ESetIntSubPriority(subPriority)      (IPC28CLR = _IPC28_U1EIS_MASK, IPC28SET = ((subPriority) << _IPC28_U1EIS_POSITION))
#define mU1EGetIntSubPriority()                 (IPC28bits.U1EIS)    
/*********************************************************************
 * UART 1 Receive
 ********************************************************************/
#define mU1RXClearIntFlag()                     (IFS3CLR = _IFS3_U1RXIF_MASK)
#define mU1RXGetIntFlag()                       (IFS3bits.U1RXIF)
#define mU1RXGetIntEnable()                     (IEC3bits.U1RXIE)
#define mU1RXIntEnable(enable)                  (IEC3CLR = _IEC3_U1RXIE_MASK, IEC3SET = ((enable) << _IEC3_U1RXIE_POSITION))
#define mU1RXSetIntPriority(priority)           (IPC28CLR = _IPC28_U1RXIP_MASK, IPC28SET = ((priority) << _IPC28_U1RXIP_POSITION))
#define mU1RXGetIntPriority()                   (IPC28bits.U1RXIP)
#define mU1RXSetIntSubPriority(subPriority)     (IPC28CLR = _IPC28_U1RXIS_MASK, IPC28SET = ((subPriority) << _IPC28_U1RXIS_POSITION))
#define mU1RXGetIntSubPriority()                (IPC28bits.U1RXIS)      
/*********************************************************************
 * UART 1 Transfer
 ********************************************************************/
#define mU1TXClearIntFlag()                     (IFS3CLR = _IFS3_U1TXIF_MASK)
#define mU1TXGetIntFlag()                       (IFS3bits.U1TXIF)
#define mU1TXGetIntEnable()                     (IEC3bits.U1TXIE)
#define mU1TXIntEnable(enable)                  (IEC3CLR = _IEC3_U1TXIE_MASK, IEC3SET = ((enable) << _IEC3_U1TXIE_POSITION))
#define mU1TXSetIntPriority(priority)           (IPC28CLR = _IPC28_U1TXIP_MASK, IPC28SET = ((priority) << _IPC28_U1TXIP_POSITION))
#define mU1TXGetIntPriority()                   (IPC28bits.U1TXIP)
#define mU1TXSetIntSubPriority(subPriority)     (IPC28CLR = _IPC28_U1TXIS_MASK, IPC28SET = ((subPriority) << _IPC28_U1TXIS_POSITION))
#define mU1TXGetIntSubPriority()                (IPC28bits.U1TXIS) 
/*********************************************************************
 * UART 1 All
 ********************************************************************/
#define mU1ClearAllIntFlags()                   (IFS3CLR = (_IFS3_U1EIF_MASK | _IFS3_U1RXIF_MASK | _IFS3_U1TXIF_MASK ))
#define mU1IntDisable()                         (IEC3CLR = (_IEC3_U1EIE_MASK | _IEC3_U1RXIE_MASK | _IEC3_U1TXIE_MASK ))
#define mU1IntSetIntEnable(flags)               (IEC3SET = (((flags) & 0x7) << _IEC3_U1EIE_POSITION)) 
#define mU1UnifiedIntVector()                   (OFF114bits.VOFF = OFF113bits.VOFF = OFF112bits.VOFF) 
#endif
#ifdef _UART2
/*********************************************************************
 * UART 2 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_2_VECTOR                          _UART2_FAULT_VECTOR
/*********************************************************************
 * UART 2 Fault
 ********************************************************************/
#define mU2EClearIntFlag()                      (IFS4CLR = _IFS4_U2EIF_MASK)
#define mU2EGetIntFlag()                        (IFS4bits.U2EIF)
#define mU2EGetIntEnable()                      (IEC4bits.U2EIE)
#define mU2EIntEnable(enable)                   (IEC4CLR = _IEC4_U2EIE_MASK, IEC4SET = ((enable) << _IEC4_U2EIE_POSITION))
#define mU2ESetIntPriority(priority)            (IPC36CLR = _IPC36_U2EIP_MASK, IPC36SET = ((priority) << _IPC36_U2EIP_POSITION))
#define mU2EGetIntPriority()                    (IPC36bits.U2EIP)
#define mU2ESetIntSubPriority(subPriority)      (IPC36CLR = _IPC36_U2EIS_MASK, IPC36SET = ((subPriority) << _IPC36_U2EIS_POSITION))
#define mU2EGetIntSubPriority()                 (IPC36bits.U2EIS)
/*********************************************************************
 * UART 2 Receive
 ********************************************************************/
#define mU2RXClearIntFlag()                     (IFS4CLR = _IFS4_U2RXIF_MASK)
#define mU2RXGetIntFlag()                       (IFS4bits.U2RXIF)
#define mU2RXGetIntEnable()                     (IEC4bits.U2RXIE)
#define mU2RXIntEnable(enable)                  (IEC4CLR = _IEC4_U2RXIE_MASK, IEC4SET = ((enable) << _IEC4_U2RXIE_POSITION))
#define mU2RXSetIntPriority(priority)           (IPC36CLR = _IPC36_U2RXIP_MASK, IPC36SET = ((priority) << _IPC36_U2RXIP_POSITION))
#define mU2RXGetIntPriority()                   (IPC36bits.U2RXIP)
#define mU2RXSetIntSubPriority(subPriority)     (IPC36CLR = _IPC36_U2RXIS_MASK, IPC36SET = ((subPriority) << _IPC36_U2RXIS_POSITION))
#define mU2RXGetIntSubPriority()                (IPC36bits.U2RXIS)
/*********************************************************************
 * UART 2 Transfer
 ********************************************************************/
#define mU2TXClearIntFlag()                     (IFS4CLR = _IFS4_U2TXIF_MASK)
#define mU2TXGetIntFlag()                       (IFS4bits.U2TXIF)
#define mU2TXGetIntEnable()                     (IEC4bits.U2TXIE)
#define mU2TXIntEnable(enable)                  (IEC4CLR = _IEC4_U2TXIE_MASK, IEC4SET = ((enable) << _IEC4_U2TXIE_POSITION))
#define mU2TXSetIntPriority(priority)           (IPC36CLR = _IPC36_U2TXIP_MASK, IPC36SET = ((priority) << _IPC36_U2TXIP_POSITION))
#define mU2TXGetIntPriority()                   (IPC36bits.U2TXIP)
#define mU2TXSetIntSubPriority(subPriority)     (IPC36CLR = _IPC36_U2TXIS_MASK, IPC36SET = ((subPriority) << _IPC36_U2TXIS_POSITION))
#define mU2TXGetIntSubPriority()                (IPC36bits.U2TXIS) 
/*********************************************************************
 * UART 2 All
 ********************************************************************/
#define mU2ClearAllIntFlags()                   (IFS4CLR = (_IFS4_U2EIF_MASK | _IFS4_U2RXIF_MASK | _IFS4_U2TXIF_MASK ))
#define mU2IntDisable()                         (IEC4CLR = (_IEC4_U2EIE_MASK | _IEC4_U2RXIE_MASK | _IEC4_U2TXIE_MASK ))
#define mU2IntSetIntEnable(flags)               (IEC4SET = (((flags) & 0x7) << _IEC4_U3EIE_POSITION))
#define mU2UnifiedIntVector()                   (OFF147bits.VOFF = OFF146bits.VOFF = OFF145bits.VOFF) 
#endif
#ifdef _UART3
/*********************************************************************
 * UART 3 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_3_VECTOR                          _UART3_FAULT_VECTOR
/*********************************************************************
 * UART 3 Fault
 ********************************************************************/
#define mU3EClearIntFlag()                      (IFS4CLR = _IFS4_U3EIF_MASK)
#define mU3EGetIntFlag()                        (IFS4bits.U3EIF)
#define mU3EGetIntEnable()                      (IEC4bits.U3EIE)
#define mU3EIntEnable(enable)                   (IEC4CLR = _IEC4_U3EIE_MASK, IEC4SET = ((enable) << _IEC4_U3EIE_POSITION))
#define mU3ESetIntPriority(priority)            (IPC39CLR = _IPC39_U3EIP_MASK, IPC39SET = ((priority) << _IPC39_U3EIP_POSITION))
#define mU3EGetIntPriority()                    (IPC39bits.U3EIP)
#define mU3ESetIntSubPriority(subPriority)      (IPC39CLR = _IPC39_U3EIS_MASK, IPC39SET = ((subPriority) << _IPC39_U3EIS_POSITION))
#define mU3EGetIntSubPriority()                 (IPC39bits.U3EIS)
/*********************************************************************
 * UART 3 Receive
 ********************************************************************/
#define mU3RXClearIntFlag()                     (IFS4CLR = _IFS4_U3RXIF_MASK)
#define mU3RXGetIntFlag()                       (IFS4bits.U3RXIF)
#define mU3RXGetIntEnable()                     (IEC4bits.U3RXIE)
#define mU3RXIntEnable(enable)                  (IEC4CLR = _IEC4_U3RXIE_MASK, IEC4SET = ((enable) << _IEC4_U3RXIE_POSITION))
#define mU3RXSetIntPriority(priority)           (IPC39CLR = _IPC39_U3RXIP_MASK, IPC39SET = ((priority) << _IPC39_U3RXIP_POSITION))
#define mU3RXGetIntPriority()                   (IPC39bits.U3RXIP)
#define mU3RXSetIntSubPriority(subPriority)     (IPC39CLR = _IPC39_U3RXIS_MASK, IPC39SET = ((subPriority) << _IPC39_U3RXIS_POSITION))
#define mU3RXGetIntSubPriority()                (IPC39bits.U3RXIS)
/*********************************************************************
 * UART 3 Transfer
 ********************************************************************/
#define mU3TXClearIntFlag()                     (IFS4CLR = _IFS4_U3TXIF_MASK)
#define mU3TXGetIntFlag()                       (IFS4bits.U3TXIF)
#define mU3TXGetIntEnable()                     (IEC4bits.U3TXIE)
#define mU3TXIntEnable(enable)                  (IEC4CLR = _IEC4_U3TXIE_MASK, IEC4SET = ((enable) << _IEC4_U3TXIE_POSITION))
#define mU3TXSetIntPriority(priority)           (IPC39CLR = _IPC39_U3TXIP_MASK, IPC39SET = ((priority) << _IPC39_U3TXIP_POSITION))
#define mU3TXGetIntPriority()                   (IPC39bits.U3TXIP)
#define mU3TXSetIntSubPriority(subPriority)     (IPC39CLR = _IPC39_U3TXIS_MASK, IPC39SET = ((subPriority) << _IPC39_U3TXIS_POSITION))
#define mU3TXGetIntSubPriority()                (IPC39bits.U3TXIS) 
/*********************************************************************
 * UART 3 All
 ********************************************************************/
#define mU3ClearAllIntFlags()                   (IFS4CLR = (_IFS4_U3EIF_MASK | _IFS4_U3RXIF_MASK | _IFS4_U3TXIF_MASK ))
#define mU3IntDisable()                         (IEC4CLR = (_IEC4_U3EIE_MASK | _IEC4_U3RXIE_MASK | _IEC4_U3TXIE_MASK ))
#define mU3IntSetIntEnable(flags)               (IEC4SET = (((flags) & 0x7) << _IEC4_U3EIE_POSITION)) 
#define mU3UnifiedIntVector()                   (OFF159bits.VOFF = OFF158bits.VOFF = OFF157bits.VOFF)
#endif      
#ifdef _UART4
/*********************************************************************
 * UART 4 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_4_VECTOR                          _UART4_FAULT_VECTOR
/*********************************************************************
 * UART 4 Fault
 ********************************************************************/
#define mU4EClearIntFlag()                      (IFS5CLR = _IFS5_U4EIF_MASK)
#define mU4EGetIntFlag()                        (IFS5bits.U4EIF)
#define mU4EGetIntEnable()                      (IEC5bits.U4EIE)
#define mU4EIntEnable(enable)                   (IEC5CLR = _IEC5_U4EIE_MASK, IEC5SET = ((enable) << _IEC5_U4EIE_POSITION))
#define mU4ESetIntPriority(priority)            (IPC42CLR = _IPC42_U4EIP_MASK, IPC42SET = ((priority) << _IPC42_U4EIP_POSITION))
#define mU4EGetIntPriority()                    (IPC42bits.U4EIP)
#define mU4ESetIntSubPriority(subPriority)      (IPC42CLR = _IPC42_U4EIS_MASK, IPC42SET = ((subPriority) << _IPC42_U4EIS_POSITION))
#define mU4EGetIntSubPriority()                 (IPC42bits.U4EIS)
/*********************************************************************
 * UART 4 Receive
 ********************************************************************/
#define mU4RXClearIntFlag()                     (IFS5CLR = _IFS5_U4RXIF_MASK)
#define mU4RXGetIntFlag()                       (IFS5bits.U4RXIF)
#define mU4RXGetIntEnable()                     (IEC5bits.U4RXIE)
#define mU4RXIntEnable(enable)                  (IEC5CLR = _IEC5_U4RXIE_MASK, IEC5SET = ((enable) << _IEC5_U4RXIE_POSITION))
#define mU4RXSetIntPriority(priority)           (IPC42CLR = _IPC42_U4RXIP_MASK, IPC42SET = ((priority) << _IPC42_U4RXIP_POSITION))
#define mU4RXGetIntPriority()                   (IPC42bits.U4RXIP)
#define mU4RXSetIntSubPriority(subPriority)     (IPC42CLR = _IPC42_U4RXIS_MASK, IPC42SET = ((subPriority) << _IPC42_U4RXIS_POSITION))
#define mU4RXGetIntSubPriority()                (IPC42bits.U4RXIS)
/*********************************************************************
 * UART 4 Transfer
 ********************************************************************/
#define mU4TXClearIntFlag()                     (IFS5CLR = _IFS5_U4TXIF_MASK)
#define mU4TXGetIntFlag()                       (IFS5bits.U4TXIF)
#define mU4TXGetIntEnable()                     (IEC5bits.U4TXIE)
#define mU4TXIntEnable(enable)                  (IEC5CLR = _IEC5_U4TXIE_MASK, IEC5SET = ((enable) << _IEC5_U4TXIE_POSITION))
#define mU4TXSetIntPriority(priority)           (IPC43CLR = _IPC43_U4TXIP_MASK, IPC43SET = ((priority) << _IPC43_U4TXIP_POSITION))
#define mU4TXGetIntPriority()                   (IPC43bits.U4TXIP)
#define mU4TXSetIntSubPriority(subPriority)     (IPC43CLR = _IPC43_U4TXIS_MASK, IPC43SET = ((subPriority) << _IPC43_U4TXIS_POSITION))
#define mU4TXGetIntSubPriority()                (IPC43bits.U4TXIS) 
/*********************************************************************
 * UART 4 All
 ********************************************************************/
#define mU4ClearAllIntFlags()                   (IFS5CLR = (_IFS5_U4EIF_MASK | _IFS5_U4RXIF_MASK | _IFS5_U4TXIF_MASK ))
#define mU4IntDisable()                         (IEC5CLR = (_IEC5_U4EIE_MASK | _IEC5_U4RXIE_MASK | _IEC5_U4TXIE_MASK ))
#define mU4IntSetIntEnable(flags)               (IEC5SET = (((flags) & 0x7) << _IEC5_U4EIE_POSITION)) 
#define mU4UnifiedIntVector()                   (OFF172bits.VOFF = OFF171bits.VOFF = OFF170bits.VOFF)
#endif 
#ifdef _UART5
/*********************************************************************
 * UART 5 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_5_VECTOR                          _UART5_FAULT_VECTOR
/*********************************************************************
 * UART 5 Fault
 ********************************************************************/
#define mU5EClearIntFlag()                      (IFS5CLR = _IFS5_U5EIF_MASK)
#define mU5EGetIntFlag()                        (IFS5bits.U5EIF)
#define mU5EGetIntEnable()                      (IEC5bits.U5EIE)
#define mU5EIntEnable(enable)                   (IEC5CLR = _IEC5_U5EIE_MASK, IEC5SET = ((enable) << _IEC5_U5EIE_POSITION))
#define mU5ESetIntPriority(priority)            (IPC44CLR = _IPC44_U5EIP_MASK, IPC44SET = ((priority) << _IPC44_U5EIP_POSITION))
#define mU5EGetIntPriority()                    (IPC44bits.U5EIP)
#define mU5ESetIntSubPriority(subPriority)      (IPC44CLR = _IPC44_U5EIS_MASK, IPC44SET = ((subPriority) << _IPC44_U5EIS_POSITION))
#define mU5EGetIntSubPriority()                 (IPC44bits.U5EIS)
/*********************************************************************
 * UART 5 Receive
 ********************************************************************/
#define mU5RXClearIntFlag()                     (IFS5CLR = _IFS5_U5RXIF_MASK)
#define mU5RXGetIntFlag()                       (IFS5bits.U5RXIF)
#define mU5RXGetIntEnable()                     (IEC5bits.U5RXIE)
#define mU5RXIntEnable(enable)                  (IEC5CLR = _IEC5_U5RXIE_MASK, IEC5SET = ((enable) << _IEC5_U5RXIE_POSITION))
#define mU5RXSetIntPriority(priority)           (IPC45CLR = _IPC45_U5RXIP_MASK, IPC45SET = ((priority) << _IPC45_U5RXIP_POSITION))
#define mU5RXGetIntPriority()                   (IPC45bits.U5RXIP)
#define mU5RXSetIntSubPriority(subPriority)     (IPC45CLR = _IPC45_U5RXIS_MASK, IPC45SET = ((subPriority) << _IPC45_U5RXIS_POSITION))
#define mU5RXGetIntSubPriority()                (IPC45bits.U5RXIS)
/*********************************************************************
 * UART 5 Transfer
 ********************************************************************/
#define mU5TXClearIntFlag()                     (IFS5CLR = _IFS5_U5TXIF_MASK)
#define mU5TXGetIntFlag()                       (IFS5bits.U5TXIF)
#define mU5TXGetIntEnable()                     (IEC5bits.U5TXIE)
#define mU5TXIntEnable(enable)                  (IEC5CLR = _IEC5_U5TXIE_MASK, IEC5SET = ((enable) << _IEC5_U5TXIE_POSITION))
#define mU5TXSetIntPriority(priority)           (IPC45CLR = _IPC45_U5TXIP_MASK, IPC45SET = ((priority) << _IPC45_U5TXIP_POSITION))
#define mU5TXGetIntPriority()                   (IPC45bits.U5TXIP)
#define mU5TXSetIntSubPriority(subPriority)     (IPC45CLR = _IPC45_U5TXIS_MASK, IPC45SET = ((subPriority) << _IPC45_U5TXIS_POSITION))
#define mU5TXGetIntSubPriority()                (IPC45bits.U5TXIS) 
/*********************************************************************
 * UART 5 All
 ********************************************************************/
#define mU5ClearAllIntFlags()                   (IFS5CLR = (_IFS5_U5EIF_MASK | _IFS5_U5RXIF_MASK | _IFS5_U5TXIF_MASK ))
#define mU5IntDisable()                         (IEC5CLR = (_IEC5_U5EIE_MASK | _IEC5_U5RXIE_MASK | _IEC5_U5TXIE_MASK ))
#define mU5IntSetIntEnable(flags)               (IEC5SET = (((flags) & 0x7) << _IEC5_U5EIE_POSITION))
#define mU5UnifiedIntVector()                   (OFF181bits.VOFF = OFF180bits.VOFF = OFF179bits.VOFF)
#endif 
#ifdef _UART6
/*********************************************************************
 * UART 6 legacy int vector define (unified)
 ********************************************************************/  
#define _UART_6_VECTOR                          _UART6_FAULT_VECTOR
/*********************************************************************
 * UART 6 Fault
 ********************************************************************/
#define mU6EClearIntFlag()                      (IFS5CLR = _IFS5_U6EIF_MASK)
#define mU6EGetIntFlag()                        (IFS5bits.U6EIF)
#define mU6EGetIntEnable()                      (IEC5bits.U6EIE)
#define mU6EIntEnable(enable)                   (IEC5CLR = _IEC5_U6EIE_MASK, IEC5SET = ((enable) << _IEC5_U6EIE_POSITION))
#define mU6ESetIntPriority(priority)            (IPC47CLR = _IPC47_U6EIP_MASK, IPC47SET = ((priority) << _IPC47_U6EIP_POSITION))
#define mU6EGetIntPriority()                    (IPC47bits.U6EIP)
#define mU6ESetIntSubPriority(subPriority)      (IPC47CLR = _IPC47_U6EIS_MASK, IPC47SET = ((subPriority) << _IPC47_U6EIS_POSITION))
#define mU6EGetIntSubPriority()                 (IPC47bits.U6EIS)
/*********************************************************************
 * UART 6 Receive
 ********************************************************************/
#define mU6RXClearIntFlag()                     (IFS5CLR = _IFS5_U6RXIF_MASK)
#define mU6RXGetIntFlag()                       (IFS5bits.U6RXIF)
#define mU6RXGetIntEnable()                     (IEC5bits.U6RXIE)
#define mU6RXIntEnable(enable)                  (IEC5CLR = _IEC5_U6RXIE_MASK, IEC5SET = ((enable) << _IEC5_U6RXIE_POSITION))
#define mU6RXSetIntPriority(priority)           (IPC47CLR = _IPC47_U6RXIP_MASK, IPC47SET = ((priority) << _IPC47_U6RXIP_POSITION))
#define mU6RXGetIntPriority()                   (IPC47bits.U6RXIP)
#define mU6RXSetIntSubPriority(subPriority)     (IPC47CLR = _IPC47_U6RXIS_MASK, IPC47SET = ((subPriority) << _IPC47_U6RXIS_POSITION))
#define mU6RXGetIntSubPriority()                (IPC47bits.U6RXIS)
/*********************************************************************
 * UART 6 Transfer
 ********************************************************************/
#define mU6TXClearIntFlag()                     (IFS5CLR = _IFS5_U6TXIF_MASK)
#define mU6TXGetIntFlag()                       (IFS5bits.U6TXIF)
#define mU6TXGetIntEnable()                     (IEC5bits.U6TXIE)
#define mU6TXIntEnable(enable)                  (IEC5CLR = _IEC5_U6TXIE_MASK, IEC5SET = ((enable) << _IEC5_U6TXIE_POSITION))
#define mU6TXSetIntPriority(priority)           (IPC47CLR = _IPC47_U6TXIP_MASK, IPC47SET = ((priority) << _IPC47_U6TXIP_POSITION))
#define mU6TXGetIntPriority()                   (IPC47bits.U6TXIP)
#define mU6TXSetIntSubPriority(subPriority)     (IPC47CLR = _IPC47_U6TXIS_MASK, IPC47SET = ((subPriority) << _IPC47_U6TXIS_POSITION))
#define mU6TXGetIntSubPriority()                (IPC47bits.U6TXIS) 
/*********************************************************************
 * UART 6 All
 ********************************************************************/
#define mU6ClearAllIntFlags()                   (IFS5CLR = (_IFS5_U6EIF_MASK | _IFS5_U6RXIF_MASK | _IFS5_U6TXIF_MASK ))
#define mU6IntDisable()                         (IEC5CLR = (_IEC5_U6EIE_MASK | _IEC5_U6RXIE_MASK | _IEC5_U6TXIE_MASK ))
#define mU6IntSetIntEnable(flags)               (IEC5SET = (((flags) & 0x7) << _IEC5_U6EIE_POSITION)) 
#define mU6UnifiedIntVector()                   (OFF190bits.VOFF = OFF189bits.VOFF = OFF188bits.VOFF)
#endif      
 

/*********************************************************************
 * <combinewith mCMP1GetIntFlag, mCMP1GetIntEnable, mCMP1IntEnable, mCMP1SetIntPriority,
 * mCMP1GetIntPriority, mCMP1SetIntSubPriority, mCMP1GetIntSubPriority,
 * mCMP2ClearIntFlag, mCMP2GetIntEnable, mCMP2GetIntFlag, mCMP2GetIntPriority, mCMP2GetIntSubPriority,
 * mCMP2IntEnable, mCMP2SetIntPriority, mCMP2SetIntSubPriority>
 *
 * Comparator x Interrupt Control Functions
 *
 * Function:        void    mCMPxClearIntFlag(void)
 *                  int     mCMPxGetIntFlag(void)
 *                  void    mCMPxSetIntEnable(void)
 *                  int     mCMPxGetIntEnable(void)
 *                  void    mCMPxClearIntEnable(void)
 *                  void    mCMPxxSetIntPriority(int priority)
 *                  int     mCMPxxGetIntPriority(void)
 *                  void    mCMPxxSetIntSubPriority(subPriority)
 *                  int     mCMPxxGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/    
#ifdef _CMP
/**********************************************
 * Comparator 1 Interrupt Control Functions
 **********************************************/
#define mCMP1ClearIntFlag()                     (IFS4CLR = _IFS4_CMP1IF_MASK)
#define mCMP1GetIntFlag()                       (IFS4bits.CMP1IF)
#define mCMP1GetIntEnable()                     (IEC4bits.CMP1IE)
#define mCMP1IntEnable(enable)                  (IEC4CLR = _IEC4_CMP1IE_MASK, IEC4SET = ((enable) << _IEC4_CMP1IE_POSITION))
#define mCMP1SetIntPriority(priority)           (IPC32CLR = _IPC32_CMP1IP_MASK, IPC32SET = ((priority) << _IPC32_CMP1IP_POSITION))
#define mCMP1GetIntPriority()                   (IPC32bits.CMP1IP)
#define mCMP1SetIntSubPriority(subPriority)     (IPC32CLR = _IPC32_CMP1IS_MASK, IPC32SET = ((subPriority) << _IPC32_CMP1IS_POSITION))
#define mCMP1GetIntSubPriority()                (IPC32bits.CMP1IS)
/**********************************************
 * Comparator 2 Interrupt Control Functions
 **********************************************/
#define mCMP2ClearIntFlag()                     (IFS4CLR = _IFS4_CMP2IF_MASK)
#define mCMP2GetIntFlag()                       (IFS4bits.CMP2IF)
#define mCMP2GetIntEnable()                     (IEC4bits.CMP2IE)
#define mCMP2IntEnable(enable)                  (IEC4CLR = _IEC4_CMP2IE_MASK, IEC4SET = ((enable) << _IEC4_CMP2IE_POSITION))
#define mCMP2SetIntPriority(priority)           (IPC32CLR = _IPC32_CMP2IP_MASK, IPC32SET = ((priority) << _IPC32_CMP2IP_POSITION))
#define mCMP2GetIntPriority()                   (IPC32bits.CMP2IP)
#define mCMP2SetIntSubPriority(subPriority)     (IPC32CLR = _IPC32_CMP2IS_MASK, IPC32SET = ((subPriority) << _IPC32_CMP2IS_POSITION))
#define mCMP2GetIntSubPriority()                (IPC32bits.CMP2IS)
#endif
    
    
/*********************************************************************
 * <combinewith mFCEGetIntEnable, mFCEGetIntFlag, mFCEGetIntPriority, mFCEGetIntSubPriority,
 * mFCEIntEnable, mFCESetIntPriority, mFCESetIntSubPriority>
 *
 * Flash Control Event Interrupt Control Functions
 *
 * Function:        void    mFCEClearIntFlag(void)
 *                  int     mFCEGetIntFlag(void)
 *                  void    mFCESetIntEnable(void)
 *                  int     mFCEGetIntEnable(void)
 *                  void    mFCEClearIntEnable(void)
 *                  void    mFCESetIntPriority(int priority)
 *                  int     mFCEGetIntPriority(void)
 *                  void    mFCESetIntSubPriority(subPriority)
 *                  int     mFCEGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
#define mFCEClearIntFlag()                 (IFS5CLR = _IFS5_FCEIF_MASK)
#define mFCEGetIntFlag()                   (IFS5bits.FCEIF)
#define mFCEGetIntEnable()                 (IEC5bits.FCEIE)
#define mFCEIntEnable(enable)              (IEC5CLR = _IEC5_FCEIE_MASK, IEC5SET = ((enable) << _IEC5_FCEIE_POSITION))
#define mFCESetIntPriority(priority)       (IPC41CLR = _IPC41_FCEIP_MASK, IPC41SET = ((priority) << _IPC41_FCEIP_POSITION))
#define mFCEGetIntPriority()               (IPC41bits.FCEIP)
#define mFCESetIntSubPriority(subPriority) (IPC41CLR = _IPC41_FCEIS_MASK, IPC41SET = ((subPriority) << _IPC41_FCEIS_POSITION))
#define mFCEGetIntSubPriority()            (IPC41bits.FCEIS)    
    
    
/*********************************************************************
 * <combinewith mPMPGetIntEnable, mPMPGetIntFlag, mPMPGetIntPriority, mPMPGetIntSubPriority,
 * mPMPIntEnable, mPMPSetIntPriority, mPMPSetIntSubPriority>
 *
 * Parallel master Port Interrupt Control Functions
 *
 * Function:        void    mPMPClearIntFlag(void)
 *                  int     mPMPGetIntFlag(void)
 *                  void    mPMPSetIntEnable(void)
 *                  int     mPMPGetIntEnable(void)
 *                  void    mPMPClearIntEnable(void)
 *                  void    mPMPSetIntPriority(int priority)
 *                  int     mPMPGetIntPriority(void)
 *                  void    mPMPSetIntSubPriority(subPriority)
 *                  int     mPMPGetIntSubPriority(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Inputs:          priority:       A value between 0 - 7 inclusive.
 *                  subPriority:    A value between 0 - 3 inclusive
 *
 * Output:          For 'Get' functions, the returned values are of
 *                  same type as 'Set' functions.
 *
 * Side Effects:    None
 *
 * Overview:        None
 ********************************************************************/
#define mPMPClearIntFlag()                  (IFS4CLR = _IFS4_PMPIF_MASK)
#define mPMPGetIntFlag()                    (IFS4bits.PMPIF)
#define mPMPGetIntEnable()                  (IEC4bits.PMPIE)
#define mPMPIntEnable(enable)               (IEC4CLR = _IEC4_PMPIE_MASK, IEC4SET = ((enable) << _IEC4_PMPIE_POSITION))
#define mPMPEClearIntFlag()                 (IFS4CLR = _IFS4_PMPEIF_MASK)
#define mPMPEGetIntFlag()                   (IFS4bits.PMPEIF)
#define mPMPEGetIntEnable()                 (IEC4bits.PMPEIE)
#define mPMPEIntEnable(enable)              (IEC4CLR = _IEC4_PMPEIE_MASK, IEC4SET = ((enable) << _IEC4_PMPEIE_POSITION))
#define mPMPSetIntPriority(priority)        (IPC32CLR = _IPC32_PMPIP_MASK, IPC32SET = ((priority) << _IPC32_PMPIP_POSITION))
#define mPMPGetIntPriority()                (IPC32bits.PMPIP)
#define mPMPSetIntSubPriority(subPriority)  (IPC32CLR = _IPC32_PMPIS_MASK, IPC32SET = ((subPriority) << _IPC32_PMPIS_POSITION))
#define mPMPGetIntSubPriority()             (IPC32bits.PMPIS)
    

/**************************************************************************************************************************
  * <combinewith mDMA0GetIntFlag, mDMA0GetIntEnable, mDMA0IntEnable, mDMA0SetIntPriority, mDMA0GetIntPriority,
  * mDMA0SetIntSubPriority, mDMA0GetIntSubPriority, mDMA1ClearIntFlag, mDMA1GetIntFlag, mDMA1GetIntEnable,
  * mDMA1IntEnable, mDMA1SetIntPriority, mDMA1GetIntPriority, mDMA1SetIntSubPriority, mDMA1GetIntSubPriority,
  * mDMA2ClearIntFlag, mDMA2GetIntFlag, mDMA2GetIntEnable, mDMA2IntEnable, mDMA2SetIntPriority, mDMA2GetIntPriority,
  * mDMA2SetIntSubPriority, mDMA2GetIntSubPriority, mDMA3ClearIntFlag, mDMA3GetIntFlag, mDMA3GetIntEnable, mDMA3IntEnable,
  * mDMA3SetIntPriority, mDMA3GetIntPriority, mDMA3SetIntSubPriority, mDMA3GetIntSubPriority, mDMA4GetIntFlag,
  * mDMA4GetIntEnable, mDMA4IntEnable, mDMA4SetIntPriority, mDMA4GetIntPriority,
  * mDMA4SetIntSubPriority, mDMA4GetIntSubPriority, mDMA5ClearIntFlag, mDMA5GetIntFlag, mDMA5GetIntEnable,
  * mDMA5IntEnable, mDMA5SetIntPriority, mDMA5GetIntPriority, mDMA5SetIntSubPriority, mDMA5GetIntSubPriority,
  * mDMA6ClearIntFlag, mDMA6GetIntFlag, mDMA6GetIntEnable, mDMA6IntEnable, mDMA6SetIntPriority, mDMA6GetIntPriority,
  * mDMA6SetIntSubPriority, mDMA6GetIntSubPriority, mDMA7ClearIntFlag, mDMA7GetIntFlag, mDMA7GetIntEnable, mDMA7IntEnable,
  * mDMA7SetIntPriority, mDMA7GetIntPriority, mDMA7SetIntSubPriority, mDMA7GetIntSubPriority>
  *
  * DMA x Channel Interrupt Control Functions
  * Prototype:
  *     void mDMAxClearIntFlag(void) int mDMAxGetIntFlag(void) void
  *     mDMAxSetIntEnable(void) int mDMAxGetIntEnable(void) void
  *     mDMAxClearIntEnable(void) void mDMAxSetIntPriority(int
  *     priority) int mDMAxGetIntPriority(void) void
  *     mDMAxSetIntSubPriority(subPriority) int
  *     mDMAxGetIntSubPriority(void)
  * Preconditions:
  *     EBASE and IntCtl.VS set up
  * Input:
  *     priority :     A value between 0 \- 7 inclusive.
  *     subPriority :  A value between 0 \- 3 inclusive
  * Return:
  *     For 'Get' functions, the returned values are of
  *     same type as 'Set' functions.
  *
  * Side Effects:
  *     None
  * Remarks:
  *     None
  *************************************************************************************************************************
*/
#ifdef _DMAC
#define mDMA0ClearIntFlag()                     (IFS4CLR = _IFS4_DMA0IF_MASK)
#define mDMA0GetIntFlag()                       (IFS4bits.DMA0IF)
#define mDMA0GetIntEnable()                     (IEC4bits.DMA0IE)
#define mDMA0IntEnable(enable)                  (IEC4CLR = _IEC4_DMA0IE_MASK, IEC4SET = ((enable) << _IEC4_DMA0IE_POSITION))
#define mDMA0SetIntPriority(priority)           (IPC33CLR = _IPC33_DMA0IP_MASK, IPC33SET = ((priority) << _IPC33_DMA0IP_POSITION))
#define mDMA0GetIntPriority()                   (IPC33bits.DMA0IP)
#define mDMA0SetIntSubPriority(subPriority)     (IPC33CLR = _IPC33_DMA0IS_MASK, IPC33SET = ((subPriority) << _IPC33_DMA0IS_POSITION))
#define mDMA0GetIntSubPriority()                (IPC33bits.DMA0IS)

#define mDMA1ClearIntFlag()                     (IFS4CLR = _IFS4_DMA1IF_MASK)
#define mDMA1GetIntFlag()                       (IFS4bits.DMA1IF)
#define mDMA1GetIntEnable()                     (IEC4bits.DMA1IE)
#define mDMA1IntEnable(enable)                  (IEC4CLR = _IEC4_DMA1IE_MASK, IEC4SET = ((enable) << _IEC4_DMA1IE_POSITION))
#define mDMA1SetIntPriority(priority)           (IPC33CLR = _IPC33_DMA1IP_MASK, IPC33SET = ((priority) << _IPC33_DMA1IP_POSITION))
#define mDMA1GetIntPriority()                   (IPC33bits.DMA1IP)
#define mDMA1SetIntSubPriority(subPriority)     (IPC33CLR = _IPC33_DMA1IS_MASK, IPC33SET = ((subPriority) << _IPC33_DMA1IS_POSITION))
#define mDMA1GetIntSubPriority()                (IPC33bits.DMA1IS)

#define mDMA2ClearIntFlag()                     (IFS4CLR = _IFS4_DMA2IF_MASK)
#define mDMA2GetIntFlag()                       (IFS4bits.DMA2IF)
#define mDMA2GetIntEnable()                     (IEC4bits.DMA2IE)
#define mDMA2IntEnable(enable)                  (IEC4CLR = _IEC4_DMA2IE_MASK, IEC4SET = ((enable) << _IEC4_DMA2IE_POSITION))
#define mDMA2SetIntPriority(priority)           (IPC34CLR = _IPC34_DMA2IP_MASK, IPC34SET = ((priority) << _IPC34_DMA2IP_POSITION))
#define mDMA2GetIntPriority()                   (IPC34bits.DMA2IP)
#define mDMA2SetIntSubPriority(subPriority)     (IPC34CLR = _IPC34_DMA2IS_MASK, IPC34SET = ((subPriority) << _IPC34_DMA2IS_POSITION))
#define mDMA2GetIntSubPriority()                (IPC34bits.DMA2IS)

#define mDMA3ClearIntFlag()                     (IFS4CLR = _IFS4_DMA3IF_MASK)
#define mDMA3GetIntFlag()                       (IFS4bits.DMA3IF)
#define mDMA3GetIntEnable()                     (IEC4bits.DMA3IE)
#define mDMA3IntEnable(enable)                  (IEC4CLR = _IEC4_DMA3IE_MASK, IEC4SET = ((enable) << _IEC4_DMA3IE_POSITION))
#define mDMA3SetIntPriority(priority)           (IPC34CLR = _IPC34_DMA3IP_MASK, IPC34SET = ((priority) << _IPC34_DMA3IP_POSITION))
#define mDMA3GetIntPriority()                   (IPC34bits.DMA3IP)
#define mDMA3SetIntSubPriority(subPriority)     (IPC34CLR = _IPC34_DMA3IS_MASK, IPC34SET = ((subPriority) << _IPC34_DMA3IS_POSITION))
#define mDMA3GetIntSubPriority()                (IPC34bits.DMA3IS)

#define mDMA4ClearIntFlag()                     (IFS4CLR = _IFS4_DMA4IF_MASK)
#define mDMA4GetIntFlag()                       (IFS4bits.DMA4IF)
#define mDMA4GetIntEnable()                     (IEC4bits.DMA4IE)
#define mDMA4IntEnable(enable)                  (IEC4CLR = _IEC4_DMA4IE_MASK, IEC4SET = ((enable) << _IEC4_DMA4IE_POSITION))
#define mDMA4SetIntPriority(priority)           (IPC34CLR = _IPC34_DMA4IP_MASK, IPC34SET = ((priority) << _IPC34_DMA4IP_POSITION))
#define mDMA4GetIntPriority()                   (IPC34bits.DMA4IP)
#define mDMA4SetIntSubPriority(subPriority)     (IPC34CLR = _IPC34_DMA4IS_MASK, IPC34SET = ((subPriority) << _IPC34_DMA4IS_POSITION))
#define mDMA4GetIntSubPriority()                (IPC34bits.DMA4IS)

#define mDMA5ClearIntFlag()                     (IFS4CLR = _IFS4_DMA5IF_MASK)
#define mDMA5GetIntFlag()                       (IFS4bits.DMA5IF)
#define mDMA5GetIntEnable()                     (IEC4bits.DMA5IE)
#define mDMA5IntEnable(enable)                  (IEC4CLR = _IEC4_DMA5IE_MASK, IEC4SET = ((enable) << _IEC4_DMA5IE_POSITION))
#define mDMA5SetIntPriority(priority)           (IPC34CLR = _IPC34_DMA5IP_MASK, IPC34SET = ((priority) << _IPC34_DMA5IP_POSITION))
#define mDMA5GetIntPriority()                   (IPC34bits.DMA5IP)
#define mDMA5SetIntSubPriority(subPriority)     (IPC34CLR = _IPC34_DMA5IS_MASK, IPC34SET = ((subPriority) << _IPC34_DMA5IS_POSITION))
#define mDMA5GetIntSubPriority()                (IPC34bits.DMA5IS)

#define mDMA6ClearIntFlag()                     (IFS4CLR = _IFS4_DMA6IF_MASK)
#define mDMA6GetIntFlag()                       (IFS4bits.DMA6IF)
#define mDMA6GetIntEnable()                     (IEC4bits.DMA6IE)
#define mDMA6IntEnable(enable)                  (IEC4CLR = _IEC4_DMA6IE_MASK, IEC4SET = ((enable) << _IEC4_DMA6IE_POSITION))
#define mDMA6SetIntPriority(priority)           (IPC35CLR = _IPC35_DMA6IP_MASK, IPC35SET = ((priority) << _IPC35_DMA6IP_POSITION))
#define mDMA6GetIntPriority()                   (IPC35bits.DMA6IP)
#define mDMA6SetIntSubPriority(subPriority)     (IPC35CLR = _IPC35_DMA6IS_MASK, IPC35SET = ((subPriority) << _IPC35_DMA6IS_POSITION))
#define mDMA6GetIntSubPriority()                (IPC35bits.DMA6IS)

#define mDMA7ClearIntFlag()                     (IFS4CLR = _IFS4_DMA7IF_MASK)
#define mDMA7GetIntFlag()                       (IFS4bits.DMA7IF)
#define mDMA7GetIntEnable()                     (IEC4bits.DMA7IE)
#define mDMA7IntEnable(enable)                  (IEC4CLR = _IEC4_DMA7IE_MASK, IEC4SET = ((enable) << _IEC4_DMA7IE_POSITION))
#define mDMA7SetIntPriority(priority)           (IPC35CLR = _IPC35_DMA7IP_MASK, IPC35SET = ((priority) << _IPC35_DMA7IP_POSITION))
#define mDMA7GetIntPriority()                   (IPC35bits.DMA7IP)
#define mDMA7SetIntSubPriority(subPriority)     (IPC35CLR = _IPC35_DMA7IS_MASK, IPC35SET = ((subPriority) << _IPC35_DMA7IS_POSITION))
#define mDMA7GetIntSubPriority()                (IPC35bits.DMA7IS)
#endif    
    
    
    
// *****************************************************************************
// *****************************************************************************
// Section: Constants & Data Types
// *****************************************************************************
// *****************************************************************************

typedef enum {

    INT_ID_0 = 0,
    INT_NUMBER_OF_MODULES = 1

} INT_MODULE_ID;

typedef enum {

    INT_EXTERNAL_INT_SOURCE0 = 0x01,
    INT_EXTERNAL_INT_SOURCE1 = 0x02,
    INT_EXTERNAL_INT_SOURCE2 = 0x04,
    INT_EXTERNAL_INT_SOURCE3 = 0x08,
    INT_EXTERNAL_INT_SOURCE4 = 0x10

} INT_EXTERNAL_SOURCES;

typedef enum {

    INT_DISABLE_INTERRUPT = 0,
    INT_PRIORITY_LEVEL1 = 1,
    INT_PRIORITY_LEVEL2 = 2,
    INT_PRIORITY_LEVEL3 = 3,
    INT_PRIORITY_LEVEL4 = 4,
    INT_PRIORITY_LEVEL5 = 5,
    INT_PRIORITY_LEVEL6 = 6,
    INT_PRIORITY_LEVEL7 = 7

} INT_PRIORITY_LEVEL;

typedef enum {

    INT_SUBPRIORITY_LEVEL0 = 0x00,
    INT_SUBPRIORITY_LEVEL1 = 0x01,
    INT_SUBPRIORITY_LEVEL2 = 0x02,
    INT_SUBPRIORITY_LEVEL3 = 0x03

} INT_SUBPRIORITY_LEVEL;

typedef enum {

    INT_SOURCE_TIMER_CORE = 0,
    INT_SOURCE_SOFTWARE_0 = 1,
    INT_SOURCE_SOFTWARE_1 = 2,
    INT_SOURCE_EXTERNAL_0 = 3,
    INT_SOURCE_TIMER_1 = 4,
    INT_SOURCE_INPUT_CAPTURE_1_ERROR = 5,
    INT_SOURCE_INPUT_CAPTURE_1 = 6,
    INT_SOURCE_OUTPUT_COMPARE_1 = 7,
    INT_SOURCE_EXTERNAL_1 = 8,
    INT_SOURCE_TIMER_2 = 9,
    INT_SOURCE_INPUT_CAPTURE_2_ERROR = 10,
    INT_SOURCE_INPUT_CAPTURE_2 = 11,
    INT_SOURCE_OUTPUT_COMPARE_2 = 12,
    INT_SOURCE_EXTERNAL_2 = 13,
    INT_SOURCE_TIMER_3 = 14,
    INT_SOURCE_INPUT_CAPTURE_3_ERROR = 15,
    INT_SOURCE_INPUT_CAPTURE_3 = 16,
    INT_SOURCE_OUTPUT_COMPARE_3 = 17,
    INT_SOURCE_EXTERNAL_3 = 18,
    INT_SOURCE_TIMER_4 = 19,
    INT_SOURCE_INPUT_CAPTURE_4_ERROR = 20,
    INT_SOURCE_INPUT_CAPTURE_4 = 21,
    INT_SOURCE_OUTPUT_COMPARE_4 = 22,
    INT_SOURCE_EXTERNAL_4 = 23,
    INT_SOURCE_TIMER_5 = 24,
    INT_SOURCE_INPUT_CAPTURE_5_ERROR = 25,
    INT_SOURCE_INPUT_CAPTURE_5 = 26,
    INT_SOURCE_OUTPUT_COMPARE_5 = 27,
    INT_SOURCE_TIMER_6 = 28,
    INT_SOURCE_INPUT_CAPTURE_6_ERROR = 29,
    INT_SOURCE_INPUT_CAPTURE_6 = 30,
    INT_SOURCE_OUTPUT_COMPARE_6 = 31,
    INT_SOURCE_TIMER_7 = 32,
    INT_SOURCE_INPUT_CAPTURE_7_ERROR = 33,
    INT_SOURCE_INPUT_CAPTURE_7 = 34,
    INT_SOURCE_OUTPUT_COMPARE_7 = 35,
    INT_SOURCE_TIMER_8 = 36,
    INT_SOURCE_INPUT_CAPTURE_8_ERROR = 37,
    INT_SOURCE_INPUT_CAPTURE_8 = 38,
    INT_SOURCE_OUTPUT_COMPARE_8 = 39,
    INT_SOURCE_TIMER_9 = 40,
    INT_SOURCE_INPUT_CAPTURE_9_ERROR = 41,
    INT_SOURCE_INPUT_CAPTURE_9 = 42,
    INT_SOURCE_OUTPUT_COMPARE_9 = 43,
    INT_SOURCE_ADC_1 = 44,
    INT_SOURCE_ADC_FIFO = 45,
    INT_SOURCE_ADC_1_DC1 = 46,
    INT_SOURCE_ADC_1_DC2 = 47,
    INT_SOURCE_ADC_1_DC3 = 48,
    INT_SOURCE_ADC_1_DC4 = 49,
    INT_SOURCE_ADC_1_DC5 = 50,
    INT_SOURCE_ADC_1_DC6 = 51,
    INT_SOURCE_ADC_1_DF1 = 52,
    INT_SOURCE_ADC_1_DF2 = 53,
    INT_SOURCE_ADC_1_DF3 = 54,
    INT_SOURCE_ADC_1_DF4 = 55,
    INT_SOURCE_ADC_1_DF5 = 56,
    INT_SOURCE_ADC_1_DF6 = 57,
    INT_SOURCE_ADC_FAULT = 58,
    INT_SOURCE_ADC_1_DATA0 = 59,
    INT_SOURCE_ADC_1_DATA1 = 60,
    INT_SOURCE_ADC_1_DATA2 = 61,
    INT_SOURCE_ADC_1_DATA3 = 62,
    INT_SOURCE_ADC_1_DATA4 = 63,
    INT_SOURCE_ADC_1_DATA5 = 64,
    INT_SOURCE_ADC_1_DATA6 = 65,
    INT_SOURCE_ADC_1_DATA7 = 66,
    INT_SOURCE_ADC_1_DATA8 = 67,
    INT_SOURCE_ADC_1_DATA9 = 68,
    INT_SOURCE_ADC_1_DATA10 = 69,
    INT_SOURCE_ADC_1_DATA11 = 70,
    INT_SOURCE_ADC_1_DATA12 = 71,
    INT_SOURCE_ADC_1_DATA13 = 72,
    INT_SOURCE_ADC_1_DATA14 = 73,
    INT_SOURCE_ADC_1_DATA15 = 74,
    INT_SOURCE_ADC_1_DATA16 = 75,
    INT_SOURCE_ADC_1_DATA17 = 76,
    INT_SOURCE_ADC_1_DATA18 = 77,
    INT_SOURCE_ADC_1_DATA19 = 78,
    INT_SOURCE_ADC_1_DATA20 = 79,
    INT_SOURCE_ADC_1_DATA21 = 80,
    INT_SOURCE_ADC_1_DATA22 = 81,
    INT_SOURCE_ADC_1_DATA23 = 82,
    INT_SOURCE_ADC_1_DATA24 = 83,
    INT_SOURCE_ADC_1_DATA25 = 84,
    INT_SOURCE_ADC_1_DATA26 = 85,
    INT_SOURCE_ADC_1_DATA27 = 86,
    INT_SOURCE_ADC_1_DATA28 = 87,
    INT_SOURCE_ADC_1_DATA29 = 88,
    INT_SOURCE_ADC_1_DATA30 = 89,
    INT_SOURCE_ADC_1_DATA31 = 90,
    INT_SOURCE_ADC_1_DATA32 = 91,
    INT_SOURCE_ADC_1_DATA33 = 92,
    INT_SOURCE_ADC_1_DATA34 = 93,
    INT_SOURCE_ADC_1_DATA35 = 94,
    INT_SOURCE_ADC_1_DATA36 = 95,
    INT_SOURCE_ADC_1_DATA37 = 96,
    INT_SOURCE_ADC_1_DATA38 = 97,
    INT_SOURCE_ADC_1_DATA39 = 98,
    INT_SOURCE_ADC_1_DATA40 = 99,
    INT_SOURCE_ADC_1_DATA41 = 100,
    INT_SOURCE_ADC_1_DATA42 = 101,
    INT_SOURCE_ADC_1_DATA43 = 102,
    INT_SOURCE_ADC_1_DATA44 = 103,
    INT_SOURCE_CORE_PERF_COUNT = 104,
    INT_SOURCE_FAST_DEBUG = 105,
    INT_SOURCE_SYSTEM_BUS_PROTECTION = 106,
    INT_SOURCE_CRYPTO = 107,          
    INT_SOURCE_RESERVED_108,           
    INT_SOURCE_SPI_1_ERROR = 109,
    INT_SOURCE_SPI_1_RECEIVE = 110,
    INT_SOURCE_SPI_1_TRANSMIT = 111,
    INT_SOURCE_USART_1_ERROR = 112,
    INT_SOURCE_USART_1_RECEIVE = 113,
    INT_SOURCE_USART_1_TRANSMIT = 114,
    INT_SOURCE_I2C_1_BUS = 115,
    INT_SOURCE_I2C_1_SLAVE = 116,
    INT_SOURCE_I2C_1_MASTER = 117,
    INT_SOURCE_CHANGE_NOTICE_A = 118,
    INT_SOURCE_CHANGE_NOTICE_B = 119,
    INT_SOURCE_CHANGE_NOTICE_C = 120,
    INT_SOURCE_CHANGE_NOTICE_D = 121,
    INT_SOURCE_CHANGE_NOTICE_E = 122,
    INT_SOURCE_CHANGE_NOTICE_F = 123,
    INT_SOURCE_CHANGE_NOTICE_G = 124,
    INT_SOURCE_CHANGE_NOTICE_H = 125,
    INT_SOURCE_CHANGE_NOTICE_J = 126,
    INT_SOURCE_CHANGE_NOTICE_K = 127,
    INT_SOURCE_PARALLEL_PORT = 128,
    INT_SOURCE_PARALLEL_PORT_ERROR = 129,
    INT_SOURCE_COMPARATOR_1 = 130,
    INT_SOURCE_COMPARATOR_2 = 131,
    INT_SOURCE_USB_1 = 132,
    INT_SOURCE_USB_1_DMA = 133,
    INT_SOURCE_DMA_0 = 134,
    INT_SOURCE_DMA_1 = 135,
    INT_SOURCE_DMA_2 = 136,
    INT_SOURCE_DMA_3 = 137,
    INT_SOURCE_DMA_4 = 138,
    INT_SOURCE_DMA_5 = 139,
    INT_SOURCE_DMA_6 = 140,
    INT_SOURCE_DMA_7 = 141,
    INT_SOURCE_SPI_2_ERROR = 142,
    INT_SOURCE_SPI_2_RECEIVE = 143,
    INT_SOURCE_SPI_2_TRANSMIT = 144,
    INT_SOURCE_USART_2_ERROR = 145,
    INT_SOURCE_USART_2_RECEIVE = 146,
    INT_SOURCE_USART_2_TRANSMIT = 147,
    INT_SOURCE_I2C_2_BUS = 148,
    INT_SOURCE_I2C_2_SLAVE = 149,
    INT_SOURCE_I2C_2_MASTER = 150,
    INT_SOURCE_CAN_1 = 151,
    INT_SOURCE_CAN_2 = 152,
    INT_SOURCE_ETH_1 = 153,
    INT_SOURCE_SPI_3_ERROR = 154,
    INT_SOURCE_SPI_3_RECEIVE = 155,
    INT_SOURCE_SPI_3_TRANSMIT = 156,
    INT_SOURCE_USART_3_ERROR = 157,
    INT_SOURCE_USART_3_RECEIVE = 158,
    INT_SOURCE_USART_3_TRANSMIT = 159,
    INT_SOURCE_I2C_3_BUS = 160,
    INT_SOURCE_I2C_3_SLAVE = 161,
    INT_SOURCE_I2C_3_MASTER = 162,
    INT_SOURCE_SPI_4_ERROR = 163,
    INT_SOURCE_SPI_4_RECEIVE = 164,
    INT_SOURCE_SPI_4_TRANSMIT = 165,         
    INT_SOURCE_RTCC = 166,
    INT_SOURCE_FLASH_CONTROL = 167,
    INT_SOURCE_PREFETCH = 168,
    INT_SOURCE_SQI1 = 169,                    
    INT_SOURCE_USART_4_ERROR = 170,
    INT_SOURCE_USART_4_RECEIVE = 171,
    INT_SOURCE_USART_4_TRANSMIT = 172,
    INT_SOURCE_I2C_4_BUS = 173,
    INT_SOURCE_I2C_4_SLAVE = 174,         
    INT_SOURCE_I2C_4_MASTER = 175,         
    INT_SOURCE_SPI_5_ERROR = 176,
    INT_SOURCE_SPI_5_RECEIVE = 177,
    INT_SOURCE_SPI_5_TRANSMIT = 178,
    INT_SOURCE_USART_5_ERROR = 179,
    INT_SOURCE_USART_5_RECEIVE = 180,
    INT_SOURCE_USART_5_TRANSMIT = 181,
    INT_SOURCE_I2C_5_BUS = 182,
    INT_SOURCE_I2C_5_SLAVE = 183,        
    INT_SOURCE_I2C_5_MASTER = 184,                   
    INT_SOURCE_SPI_6_ERROR = 185,
    INT_SOURCE_SPI_6_RECEIVE = 186,
    INT_SOURCE_SPI_6_TRANSMIT = 187,
    INT_SOURCE_USART_6_ERROR = 188,
    INT_SOURCE_USART_6_RECEIVE = 189,
    INT_SOURCE_USART_6_TRANSMIT = 190,        
    INT_SOURCE_RESERVED_191,           
    INT_SOURCE_ADC_END_OF_SCAN = 192,
    INT_SOURCE_ADC_ANALOG_CIRCUIT_READY = 193,
    INT_SOURCE_ADC_UPDATE_READY = 194,          
    INT_SOURCE_RESERVED_195,                    
    INT_SOURCE_ADC_GROUP = 196,        
    INT_SOURCE_RESERVED_197,             
    INT_SOURCE_ADC_0_EARLY = 198,
    INT_SOURCE_ADC_1_EARLY = 199,
    INT_SOURCE_ADC_2_EARLY = 200,
    INT_SOURCE_ADC_3_EARLY = 201,
    INT_SOURCE_ADC_4_EARLY = 202,       
    INT_SOURCE_RESERVED_203,
    INT_SOURCE_RESERVED_204,     
    INT_SOURCE_ADC_7_EARLY = 205,
    INT_SOURCE_ADC_0_WARM = 206,
    INT_SOURCE_ADC_1_WARM = 207,
    INT_SOURCE_ADC_2_WARM = 208,
    INT_SOURCE_ADC_3_WARM = 209,
    INT_SOURCE_ADC_4_WARM = 210,
    INT_SOURCE_RESERVED_211,    
    INT_SOURCE_RESERVED_212,            
    INT_SOURCE_ADC_7_WARM   = 213,
    INT_SOURCE_NOSRC        = 214        
} INT_SOURCE;

typedef enum {

    INT_VECTOR_CT = 0,
    INT_VECTOR_CS0,
    INT_VECTOR_CS1,
    INT_VECTOR_INT0,
    INT_VECTOR_T1,
    INT_VECTOR_IC1_ERROR,
    INT_VECTOR_IC1,
    INT_VECTOR_OC1,
    INT_VECTOR_INT1,
    INT_VECTOR_T2,
    INT_VECTOR_IC2_ERROR,
    INT_VECTOR_IC2,
    INT_VECTOR_OC2,
    INT_VECTOR_INT2,
    INT_VECTOR_T3,
    INT_VECTOR_IC3_ERROR,
    INT_VECTOR_IC3,   
    INT_VECTOR_OC3,
    INT_VECTOR_INT3,
    INT_VECTOR_T4,
    INT_VECTOR_IC4_ERROR,
    INT_VECTOR_IC4,
    INT_VECTOR_OC4,
    INT_VECTOR_INT4,
    INT_VECTOR_T5,
    INT_VECTOR_IC5_ERROR,
    INT_VECTOR_IC5,
    INT_VECTOR_OC5,
    INT_VECTOR_T6,
    INT_VECTOR_IC6_ERROR,
    INT_VECTOR_IC6,
    INT_VECTOR_OC6,
    INT_VECTOR_T7,
    INT_VECTOR_IC7_ERROR,
    INT_VECTOR_IC7,
    INT_VECTOR_OC7,
    INT_VECTOR_T8,
    INT_VECTOR_IC8_ERROR,
    INT_VECTOR_IC8,
    INT_VECTOR_OC8,
    INT_VECTOR_T9,
    INT_VECTOR_IC9_ERROR,
    INT_VECTOR_IC9,
    INT_VECTOR_OC9,
    INT_VECTOR_ADC1,
    INT_VECTOR_ADC_FIFO,
    INT_VECTOR_ADC_DC1,
    INT_VECTOR_ADC_DC2,
    INT_VECTOR_ADC_DC3,
    INT_VECTOR_ADC_DC4,
    INT_VECTOR_ADC_DC5,
    INT_VECTOR_ADC_DC6,
    INT_VECTOR_ADC_DF1,
    INT_VECTOR_ADC_DF2,
    INT_VECTOR_ADC_DF3,
    INT_VECTOR_ADC_DF4,
    INT_VECTOR_ADC_DF5,
    INT_VECTOR_ADC_DF6,
    INT_VECTOR_ADC_FAULT,
    INT_VECTOR_ADC_DATA0,
    INT_VECTOR_ADC_DATA1,
    INT_VECTOR_ADC_DATA2,
    INT_VECTOR_ADC_DATA3,
    INT_VECTOR_ADC_DATA4,
    INT_VECTOR_ADC_DATA5,
    INT_VECTOR_ADC_DATA6,
    INT_VECTOR_ADC_DATA7,
    INT_VECTOR_ADC_DATA8,
    INT_VECTOR_ADC_DATA9,
    INT_VECTOR_ADC_DATA10,
    INT_VECTOR_ADC_DATA11,
    INT_VECTOR_ADC_DATA12,
    INT_VECTOR_ADC_DATA13,
    INT_VECTOR_ADC_DATA14,
    INT_VECTOR_ADC_DATA15,
    INT_VECTOR_ADC_DATA16,
    INT_VECTOR_ADC_DATA17,
    INT_VECTOR_ADC_DATA18,
    INT_VECTOR_ADC_DATA19,
    INT_VECTOR_ADC_DATA20,
    INT_VECTOR_ADC_DATA21,
    INT_VECTOR_ADC_DATA22,
    INT_VECTOR_ADC_DATA23,
    INT_VECTOR_ADC_DATA24,
    INT_VECTOR_ADC_DATA25,
    INT_VECTOR_ADC_DATA26,
    INT_VECTOR_ADC_DATA27,
    INT_VECTOR_ADC_DATA28,
    INT_VECTOR_ADC_DATA29,
    INT_VECTOR_ADC_DATA30,
    INT_VECTOR_ADC_DATA31,
    INT_VECTOR_ADC_DATA32,
    INT_VECTOR_ADC_DATA33,
    INT_VECTOR_ADC_DATA34,
    INT_VECTOR_ADC_DATA35,
    INT_VECTOR_ADC_DATA36,
    INT_VECTOR_ADC_DATA37,
    INT_VECTOR_ADC_DATA38,
    INT_VECTOR_ADC_DATA39,
    INT_VECTOR_ADC_DATA40,
    INT_VECTOR_ADC_DATA41,
    INT_VECTOR_ADC_DATA42,
    INT_VECTOR_ADC_DATA43,
    INT_VECTOR_ADC_DATA44,
    INT_VECTOR_CORE_PERF_COUNT,
    INT_VECTOR_CORE_FAST_DEBUG_CHANNEL,
    INT_VECTOR_CORE_SYSTEM_BUS_PROTECTION,
    INT_VECTOR_CRYPTO,
    INT_VECTOR_RESERVED_108,  
    INT_VECTOR_SPI1_FAULT,
    INT_VECTOR_SPI1_RX,
    INT_VECTOR_SPI1_TX,
    INT_VECTOR_UART1_FAULT,
    INT_VECTOR_UART1_RX,
    INT_VECTOR_UART1_TX,
    INT_VECTOR_I2C1_BUS,
    INT_VECTOR_I2C1_SLAVE,
    INT_VECTOR_I2C1_MASTER,
    INT_VECTOR_CHANGE_NOTICE_A,
    INT_VECTOR_CHANGE_NOTICE_B,
    INT_VECTOR_CHANGE_NOTICE_C,
    INT_VECTOR_CHANGE_NOTICE_D,
    INT_VECTOR_CHANGE_NOTICE_E,
    INT_VECTOR_CHANGE_NOTICE_F,
    INT_VECTOR_CHANGE_NOTICE_G,
    INT_VECTOR_CHANGE_NOTICE_H,
    INT_VECTOR_CHANGE_NOTICE_J,
    INT_VECTOR_CHANGE_NOTICE_K,
    INT_VECTOR_PMP,
    INT_VECTOR_PMP_ERROR,	
    INT_VECTOR_CMP1,
    INT_VECTOR_CMP2,
    INT_VECTOR_USB1,
    INT_VECTOR_USB1_DMA,
    INT_VECTOR_DMA0,
    INT_VECTOR_DMA1,
    INT_VECTOR_DMA2,
    INT_VECTOR_DMA3,
    INT_VECTOR_DMA4,
    INT_VECTOR_DMA5,
    INT_VECTOR_DMA6,
    INT_VECTOR_DMA7,		
    INT_VECTOR_SPI2_FAULT,
    INT_VECTOR_SPI2_RX,
    INT_VECTOR_SPI2_TX,
    INT_VECTOR_UART2_FAULT,
    INT_VECTOR_UART2_RX,
    INT_VECTOR_UART2_TX,
    INT_VECTOR_I2C2_BUS,
    INT_VECTOR_I2C2_SLAVE,
    INT_VECTOR_I2C2_MASTER,
    INT_VECTOR_CAN1,
    INT_VECTOR_CAN2,		
    INT_VECTOR_ETH,		
    INT_VECTOR_SPI3_FAULT,
    INT_VECTOR_SPI3_RX,
    INT_VECTOR_SPI3_TX,
    INT_VECTOR_UART3_FAULT,
    INT_VECTOR_UART3_RX,
    INT_VECTOR_UART3_TX,
    INT_VECTOR_I2C3_BUS,
    INT_VECTOR_I2C3_SLAVE,
    INT_VECTOR_I2C3_MASTER,
    INT_VECTOR_SPI4_FAULT,
    INT_VECTOR_SPI4_RX,
    INT_VECTOR_SPI4_TX,
    INT_VECTOR_RTCC,
    INT_VECTOR_FLASH,		
    INT_VECTOR_PREFETCH,		
    INT_VECTOR_SQI1,		
    INT_VECTOR_UART4_FAULT,
    INT_VECTOR_UART4_RX,
    INT_VECTOR_UART4_TX,
    INT_VECTOR_I2C4_BUS,
    INT_VECTOR_I2C4_SLAVE,
    INT_VECTOR_I2C4_MASTER,				
    INT_VECTOR_SPI5_FAULT,
    INT_VECTOR_SPI5_RX,
    INT_VECTOR_SPI5_TX,
    INT_VECTOR_UART5_FAULT,
    INT_VECTOR_UART5_RX,
    INT_VECTOR_UART5_TX,
    INT_VECTOR_I2C5_BUS,
    INT_VECTOR_I2C5_SLAVE,
    INT_VECTOR_I2C5_MASTER,
    INT_VECTOR_SPI6_FAULT,
    INT_VECTOR_SPI6_RX,
    INT_VECTOR_SPI6_TX,
    INT_VECTOR_UART6_FAULT,
    INT_VECTOR_UART6_RX,
    INT_VECTOR_UART6_TX,
    INT_VECTOR_RESERVED_191,
    INT_VECTOR_ADC_END_OF_SCANR,
    INT_VECTOR_ADC_ANALOG_CIRCUIT_READY,
    INT_VECTOR_ADC_UPDATE_READY,
    INT_VECTOR_RESERVED_195,
    INT_VECTOR_ADC_GROUP,
    INT_VECTOR_RESERVED_197,
    INT_VECTOR_ADC_0_EARLY,
    INT_VECTOR_ADC_1_EARLY,
    INT_VECTOR_ADC_2_EARLY,
    INT_VECTOR_ADC_3_EARLY,
    INT_VECTOR_ADC_4_EARLY,
    INT_VECTOR_RESERVED_203,
    INT_VECTOR_RESERVED_204,
    INT_VECTOR_ADC_7_EARLY,
    INT_VECTOR_ADC_0_WARM,
    INT_VECTOR_ADC_1_WARM,
    INT_VECTOR_ADC_2_WARM,
    INT_VECTOR_ADC_3_WARM,
    INT_VECTOR_ADC_4_WARM,
    INT_VECTOR_RESERVED_211,		
    INT_VECTOR_RESERVED_212,
    INT_VECTOR_ADC_7_WARM,
    INT_VECTOR_NOVECT
} INT_VECTOR;

typedef enum {

    INT_VECTOR_SPACING_0 = 0x00,
    INT_VECTOR_SPACING_8 = 0x01,
    INT_VECTOR_SPACING_16 = 0x02,
    INT_VECTOR_SPACING_32 = 0x04,
    INT_VECTOR_SPACING_64 = 0x08,
    INT_VECTOR_SPACING_128 = 0x10,
    INT_VECTOR_SPACING_256 = 0x20,
    INT_VECTOR_SPACING_512 = 0x40

} INT_VECTOR_SPACING;

typedef enum {

    INT_SHADOW_REGISTER_0 = 0x00,
    INT_SHADOW_REGISTER_1 = 0x01,
    INT_SHADOW_REGISTER_2 = 0x02,
    INT_SHADOW_REGISTER_3 = 0x03,
    INT_SHADOW_REGISTER_4 = 0x04,
    INT_SHADOW_REGISTER_5 = 0x05,
    INT_SHADOW_REGISTER_6 = 0x06,
    INT_SHADOW_REGISTER_7 = 0x07

} INT_SHADOW_REGISTER;
    
// *****************************************************************************
/* Interrupt Single Vector Shadow Set

  Summary:
    Single vector shadow set selector.

  Description:
    These definitions can be used enable the use of the shadow set when
    in single vector mode.
*/ 
typedef enum
{
    // Use the the CPU's register set when entering the handler.
    INT_REGISTOR_SET_SELECT_NONE /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,
    // Use the shadow set when entering the handler
    INT_REGISTOR_SET_SELECT_SS0  /*DOM-IGNORE-BEGIN*/ = (_PRISS_SS0_MASK) /*DOM-IGNORE-END*/

}INT_SV_SS;

// *****************************************************************************
/* Interrupt Vector Priority

  Summary:
    Interrupt vector priority definitions.

  Description:
    These definitions can be used to set the priority of an interrupt
    vector.
*/
typedef enum
{
    // Interrupt vector priority level of 0, interrupt is disabled.
    INT_PRIORITY_DISABLED /*DOM-IGNORE-BEGIN*/=      0 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 1.
    INT_PRIORITY_LEVEL_1  /*DOM-IGNORE-BEGIN*/=      1 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 2.
    INT_PRIORITY_LEVEL_2  /*DOM-IGNORE-BEGIN*/=      2 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 3.
    INT_PRIORITY_LEVEL_3  /*DOM-IGNORE-BEGIN*/=      3 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 4.
    INT_PRIORITY_LEVEL_4  /*DOM-IGNORE-BEGIN*/=      4 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 5.
    INT_PRIORITY_LEVEL_5  /*DOM-IGNORE-BEGIN*/=      5 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 6.
    INT_PRIORITY_LEVEL_6  /*DOM-IGNORE-BEGIN*/=      6 /*DOM-IGNORE-END*/,
    // Interrupt vector priority level of 7.
    INT_PRIORITY_LEVEL_7  /*DOM-IGNORE-BEGIN*/=      7  /*DOM-IGNORE-END*/
}INT_PRIORITY;

// *****************************************************************************
/* Interrupt Vector Sub-priority

  Summary:
    Interrupt vector sub-priority definitions.

  Description:
    These definitions can be used to set the sub-priority of an interrupt
    vector.
*/
typedef enum
{
    // Interrupt vector sub-priority level of 0.
    INT_SUB_PRIORITY_LEVEL_0 /*DOM-IGNORE-BEGIN*/=   0 /*DOM-IGNORE-END*/,
    // Interrupt vector sub-priority level of 1.
    INT_SUB_PRIORITY_LEVEL_1 /*DOM-IGNORE-BEGIN*/=   1 /*DOM-IGNORE-END*/,
    // Interrupt vector sub-priority level of 2.
    INT_SUB_PRIORITY_LEVEL_2 /*DOM-IGNORE-BEGIN*/=   2 /*DOM-IGNORE-END*/,
    // Interrupt vector sub-priority level of 3.
    INT_SUB_PRIORITY_LEVEL_3 /*DOM-IGNORE-BEGIN*/=   3 /*DOM-IGNORE-END*/
}INT_SUB_PRIORITY;

// *****************************************************************************
/* Interrupt Enable/Disable

  Summary:
    Interrupt enable/disable definitions.

  Description:
    These definitions can be used to enable or disable an interrupt.
*/
typedef enum
{
    // Disables the interrupt.
    INT_DISABLED /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/,
    // Enables the interrupt.
    INT_ENABLED /*DOM-IGNORE-BEGIN*/  = 1 /*DOM-IGNORE-END*/
}INT_EN_DIS;
// *****************************************************************************
/* Interrupt Temporal Proximity Control

  Summary:
    Interrupt Temporal Proximity Control definitions.

  Description:
    These definitions can be used to set the interrupt priority of the Interrupt Temporal Proximity Timer.
*/
typedef enum
{
    // Temporal Proximity Timer disabled.
    INT_TPC_DISABLE            /*DOM-IGNORE-BEGIN*/=      0x00000700 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 1.
    INT_TPC_GROUP_PRI_LEVEL_1  /*DOM-IGNORE-BEGIN*/=      1 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 2 and below.
    INT_TPC_GROUP_PRI_LEVEL_2  /*DOM-IGNORE-BEGIN*/=      2 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 3 and below.
    INT_TPC_GROUP_PRI_LEVEL_3  /*DOM-IGNORE-BEGIN*/=      3 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 4 and below.
    INT_TPC_GROUP_PRI_LEVEL_4  /*DOM-IGNORE-BEGIN*/=      4 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 5 and below.
    INT_TPC_GROUP_PRI_LEVEL_5  /*DOM-IGNORE-BEGIN*/=      5 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 6 and below.
    INT_TPC_GROUP_PRI_LEVEL_6  /*DOM-IGNORE-BEGIN*/=      6 /*DOM-IGNORE-END*/,
    // Temporal Proximity Timer enable for interupt priority level 7 and below.
    INT_TPC_GROUP_PRI_LEVEL_7  /*DOM-IGNORE-BEGIN*/=      7 /*DOM-IGNORE-END*/
}INT_TPC_GROUP;

// *****************************************************************************
/* Interrupt Vector Spacing

  Summary:
    Interrupt vector spacing definitions.

  Description:
    These definitions can be used to set the core's EBASE vector spacing.
*/
typedef enum
{
    // Vector spacing of 32 bytes.
    INT_VS_32  /*DOM-IGNORE-BEGIN*/= 32 /*DOM-IGNORE-END*/,
    // Vector spacing of 64 bytes.
    INT_VS_64  /*DOM-IGNORE-BEGIN*/= 64 /*DOM-IGNORE-END*/,
    // Vector spacing of 128 bytes.
    INT_VS_128  /*DOM-IGNORE-BEGIN*/= 128 /*DOM-IGNORE-END*/,
    // Vector spacing of 256 bytes.
    INT_VS_256  /*DOM-IGNORE-BEGIN*/= 256 /*DOM-IGNORE-END*/,
    // Vector spacing of 512 bytes.
    INT_VS_512  /*DOM-IGNORE-BEGIN*/= 512 /*DOM-IGNORE-END*/
}INT_VS;

// *****************************************************************************
/* Interrupt Configuration

  Summary:
    Interrupt configuration parameters.

  Description:
    These definitions can be used to configure the system interrupt controller.
*/
typedef enum
{
    // Configure the interrupt module for Mult-vector mode.
    INT_SYSTEM_CONFIG_MULT_VECTOR,
    // Configure the interrupt module for Single Vectored mode.
    INT_SYSTEM_CONFIG_SINGLE_VECTOR
}INT_SYSTEM_CONFIG;

// *****************************************************************************
// *****************************************************************************
// Section: Interrupt Peripheral Library Interface Routines and Macors
// *****************************************************************************
// *****************************************************************************    
    
//******************************************************************************
/* Function :  INT_Enable

  Summary:
    Implements PIC32 variant of INT_Enable 

  Description:
    This template implements the PIC32 variant of the INT_Enable function.
*/
void extern inline __attribute__((nomips16,nomicromips,always_inline))  
INT_Enable(void)
{
    __builtin_mtc0(12, 0,(__builtin_mfc0(12, 0) | 0x0001));
}

//******************************************************************************
/* Function :  INT_Disable

  Summary:
    Implements PIC32 variant of INT_Disable 

  Description:
    This template implements the PIC32 variant of the INT_Disable function.
*/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
INT_Disable(void)
{
    __builtin_disable_interrupts();
}

/*******************************************************************************
  Function:
    unsigned int __attribute__((nomips16)) INTDisableInterrupts(void)

  Summary:
    Disables the PIC32MX from handling interrupts.

  Description:
    This routine disables the core from handling any pending interrupt requests.

  Precondition:
    None

  Parameters:
    None

  Returns:
    The previous state of the CP0 register Status.IE bit.  The INTRestoreInterrupts
    function can be used in other routines to restore the system interrupt state.

  Example:
    <code>
    unsigned int intStatus;

    intStatus = INTDisableInterrupts();
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
unsigned int extern inline __attribute__((nomips16,nomicromips,always_inline)) __attribute__((optimize("-O0")))
INTDisableInterrupts(void)
{
    
    return (unsigned int)__builtin_disable_interrupts();
}

/*******************************************************************************
  Function:
    unsigned int __attribute__((nomips16))  INTEnableInterrupts(void)

  Summary:
    Enables the PIC32MZ to handle interrupts.

  Description:
    This routine enables the core to handle any pending interrupt requests.

  Precondition:
    Need to configure system using INTConfigureSystem

  Parameters:
    None

  Returns:
    The previous state of the CP0 register Status.IE bit.  The INTRestoreInterrupts
    function can be used in other routines to restore the system interrupt state.

  Example:
    <code>
    unsigned int intStatus;

    intStatus = INTEnableInterrupts();
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
unsigned int extern inline __attribute__((nomips16,nomicromips,always_inline))  
INTEnableInterrupts(void)
{
    unsigned int status = 0;

    asm volatile("ei    %0" : "=r"(status));

    return (status & 0x00000001);
}
    
/*******************************************************************************
  Function:
    void __attribute__((nomips16))  INTRestoreInterrupts(unsigned int status)

  Summary:
    Restores the PIC32MX interrupt state.

  Description:
    This routine restores the core to the previous interrupt handling state.

  Precondition:
    None

  Parameters:
    status      - the state of the CP0 register Status.IE

  Returns:
    None

  Example:
    <code>
    unsigned int intStatus;

    intStatus = INTDisableInterrupts();

    // ... application code

    INTRestoreInterrupts(intStatus);
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) __attribute__((optimize("-O0"))) 
INTRestoreInterrupts(unsigned int status)
{

    __builtin_mtc0(12, 0, status);
}

/*******************************************************************************
  Function :  void INTMultiVectorSelect(void)

  Summary:
    Implements Default variant of INTMultiVectorSelect 

  Description:
    This template implements the Default variant of the INTMultiVectorSelect function.
*******************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
INTMultiVectorSelect( void )
{
    
    INTCONSET = _INTCON_MVEC_MASK;
}

/*********************************************************************
 * Function:        void INTEnableSystemMultiVectoredInt(void)
 *
 * PreCondition:    EBASE and IntCtl.VS set up
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    System interrupts are turned on
 *
 * Overview:        Enables system wide multi-vectored interrupts
 ********************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))  
INTEnableSystemMultiVectoredInt( void )
{
    unsigned int val;

    // set the CP0 cause IV bit high
    asm volatile("mfc0   %0,$13" : "=r"(val));
    val |= 0x00800000;
    asm volatile("mtc0   %0,$13" : "+r"(val));

    INTCONSET = _INTCON_MVEC_MASK;

    // set the CP0 status IE bit high to turn on interrupts
    INTEnableInterrupts();
}

/*********************************************************************
 * Function:       void INTEnableSystemSingleVectoredInt(void)
 *
 * PreCondition:    EBASE and IntCtrl.VS set up (VS = 0)
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    Single vectored interrupts are turned on
 *
 * Overview:        Enables system wide single vectored interrupts
 ********************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))  
INTEnableSystemSingleVectoredInt( void )
{
    unsigned int val;

    // set the CP0 cause IV bit high
    asm volatile("mfc0   %0,$13" : "=r"(val));
    val |= 0x00800000;
    asm volatile("mtc0   %0,$13" : "+r"(val));

    INTCONCLR = _INTCON_MVEC_MASK;

    // set the CP0 status IE bit high to turn on interrupts
    INTEnableInterrupts();
}

/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) INTConfigureSystem(INT_SYSTEM_CONFIG config);

  Summary:
    Configures the system for  multi-vector or single vectored interrupts.

  Description:
    This routine configures the core to receive interrupt requests and configures the
    Interrupt module for Multi-vectored or Single Vectored mode.

  Precondition:
    None

  Parameters:
    config      - The interrupt configuration to set.

  Returns:
    None

  Example:
    Configure for Multi-vectored mode
    <code>

    // configure for multi-vectored mode
    INTConfigureSystem(INT_SYSTEM_CONFIG_MULT_VECTOR);

    // enable interrupts
    INTEnableInterrupts();

    // ...
    </code>

    Configure for Single Vectored mode
    <code>

    // configure for single vectored mode
    INTConfigureSystem(INT_SYSTEM_CONFIG_SINGLE_VECTOR);

    // enable interrupts
    INTEnableInterrupts();

    // ...
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))
INTConfigureSystem(INT_SYSTEM_CONFIG config)
{
    unsigned int val;

    // set the CP0 cause IV bit high
    asm volatile("mfc0   %0,$13" : "=r"(val));
    val |= 0x00800000;
    asm volatile("mtc0   %0,$13" : "+r"(val));

    if(config == INT_SYSTEM_CONFIG_MULT_VECTOR)
        INTCONSET = _INTCON_MVEC_MASK;
    else
        INTCONCLR = _INTCON_MVEC_MASK;
}

/*******************************************************************************
  Function:
    void __attribute__((nomips16)) INTSetEBASE(unsigned int ebase_address)

  Summary:
    Sets the PIC32MX exception base.

  Description:
    This routine sets the exception base of the core.

  Precondition:
    None

  Parameters:
    ebase_address   - The address of the EBASE.
                    * must be be located in KSEG0 or KSEG1
                    * must be 4KB aligned

  Returns:
    None

  Example:
    <code>

    INTSetEBASE(0xBFC01000);
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))
INTSetEBASE( unsigned int ebase_address )
{
    unsigned int temp;
    unsigned int status;

    status = INTDisableInterrupts();

    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp |= _CP0_STATUS_BEV_MASK;                           // set the BEV bit

    _CP0_SET_STATUS(temp);                                  // Update the Status register

    _CP0_SET_EBASE(ebase_address);                          // Set the EBASE Value (Kseg0 or Kseg1)

    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp &= ~(_CP0_STATUS_BEV_MASK);                        // Clear EXL and BEV bits

    _CP0_SET_STATUS(temp);                                  // Update the Status register

    INTRestoreInterrupts(status);
}

/*******************************************************************************
  Function:
    void __attribute__((nomips16)) INTSetVectorSpacing(INT_VS vector_spacing)

  Summary:
    Sets the PIC32MX exception vector spacing.

  Description:
    This routine sets the exception vector spacing of the core.

  Precondition:
    None

  Parameters:
    vector_spacing  - The desired vector spacing.

  Returns:
    None

  Example:
    <code>

    INTSetVectorSpacing(INT_VS_32);
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))
INTSetVectorSpacing(INT_VS vector_spacing)
{
    unsigned int temp;
    unsigned int status;

    status = INTDisableInterrupts();

    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp |= _CP0_STATUS_BEV_MASK;                           // set the BEV bit

    _CP0_SET_STATUS(temp);                                  // Update the Status register

    _CP0_SET_INTCTL(vector_spacing);                      // set the vector spacing

    temp = _CP0_GET_STATUS();                               // get the CP0 Status register

    temp &= ~(_CP0_STATUS_BEV_MASK);                        // Clear EXL and BEV bits

    _CP0_SET_STATUS(temp);                                  // Update the Status register

    INTRestoreInterrupts(status);
}

/*******************************************************************************
  Function:
    extern inline void __attribute__ ((always_inline)) INTSingleVectorRegisterSet(INT_SV_SS reg_set)

  Summary:
    Sets the single vectored interrupt handler's general purpose register set.

  Description:
    This routine sets the single vectored interrupt handler's general purpose register set.

  Precondition:
    The interrupt controller must be set in Single Vectored mode.

  Parameters:
    reg_set         - Register set for the single vectored handler.

  Returns:
    None

  Example:
    <code>

    INTSingleVectorRegisterSet(INT_REGISTOR_SET_SELECT_NONE);
    </code>

  Remarks:
    None.
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSingleVectorRegisterSet(INT_SV_SS reg_set)
{
    PRISSCLR   = reg_set;
    PRISSSET   = reg_set;
}

/*******************************************************************************
  Function:
    extern inline unsigned int __attribute__ ((always_inline)) INTGetInterruptVectorNumber(void)

  Summary:
    Gets the pending interrupt vector.

  Description:
    This routine gets the pending interrupt vector number.

  Precondition:
    None

  Parameters:
    None

  Returns:
    The pending interrupt vector number.

  Example:
    <code>
    unsigned int vector_num;

    vector_num = INTGetInterruptVectorNumber();

    if(vector_num == _CORE_TIMER_VECTOR)
    {
        // ...
    }
    </code>

  Remarks:
    The user can refer to the device file to get the vector number defines.
  *****************************************************************************/
extern inline unsigned int __attribute__ ((always_inline)) 
INTGetInterruptVectorNumber(void)
{
    return (unsigned int)(INTSTATbits.SIRQ);
}

/*******************************************************************************
  Function:
    extern inline INT_PRIORITY __attribute__ ((always_inline)) INTGetInterruptVectorPriority(void)

  Summary:
    Gets the pending interrupt vector's priority.

  Description:
    This routine gets the pending interrupt vector's priority.

  Precondition:
    None

  Parameters:
    None

  Returns:
    The pending interrupt vector's priority.

  Example:
    <code>
    INT_PRIORITY vector_pri;

    vector_pri = INTGetInterruptVectorPriority();
    </code>

  Remarks:
    None.
  *****************************************************************************/
extern inline INT_PRIORITY __attribute__ ((always_inline)) 
INTGetInterruptVectorPriority(void)
{
    return (INT_PRIORITY)(INTSTATbits.SRIPL);
}

/*******************************************************************************
  Function:
    extern inline void __attribute__ ((always_inline)) INTGetInterruptVectorNumberAndPriority(unsigned int *number, INT_PRIORITY *priority)

  Summary:
    Gets the pending interrupt vector number and priority.

  Description:
    This routine gets the pending interrupt vector number and priority.

  Precondition:
    *number - pointer to the vector number

    *priority - pointer to the interrupt priority

  Parameters:
    None

  Returns:
    The pending interrupt vector's priority.

  Example:
    <code>
    INT_PRIORITY vector_pri;
    unsigned int vector_num;

    INTGetInterruptVectorNumberAndPriority(&vector_num, &vector_pri);

    if(vector_num == _CORE_TIMER_VECTOR)
    {
        // ...
    }
    </code>

  Remarks:
    None.
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTGetInterruptVectorNumberAndPriority(unsigned int *number, INT_PRIORITY *priority)
{
    *number     = INTSTAT;
    *priority   = (INT_PRIORITY)((*number >> 8) & 7);
    *number     &= 0x3F;
}

/*******************************************************************************
  Function:
    void INTClearFlag(INT_SOURCE source)

  Summary:
    Clears an interrupt request flag.

  Description:
    This routine clears an interrupt request flag.

  Precondition:
    None

  Parameters:
    source  - Interrupt source.

  Returns:
    None

  Example:
    <code>
    INTClearFlag(INT_CT);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline))
INTClearFlag( INT_SOURCE source )
{
    volatile UINT *ifs_clr  =   (volatile UINT *)(0xBF810044 + ((UINT)0x10*((UINT)source/(UINT)32)));     //IFSxCLR
    UINT bit_offset = (UINT)source & (UINT)0x1F;
    
    *ifs_clr = (1 << bit_offset);
}

/*******************************************************************************
  Function:
    void INTSetFlag(INT_SOURCE source)

  Summary:
    Sets an interrupt request flag.

  Description:
    This routine sets an interrupt request flag.

  Precondition:
    None

  Parameters:
    source  - Interrupt source.

  Returns:
    None

  Example:
    <code>
    INTSetFlag(INT_CT);
    </code>

  Remarks:
    If the corresponding interrupt enable is set, this routine will cause the
    application to vector to the interrupt's handler.
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSetFlag( INT_SOURCE source )
{
    volatile UINT *ifs_set  =   (volatile UINT *)(0xBF810048 + ((UINT)0x10*((UINT)source/(UINT)32)));     //IFSxSET
    UINT bit_offset = (UINT)source & (UINT)0x1F;
    
    *ifs_set = (1 << bit_offset);    
}

/*******************************************************************************
  Function:
    unsigned int INTGetFlag(INT_SOURCE source)

  Summary:
    Gets the interrupt request flag.

  Description:
    This routine gets an interrupt request flag.

  Precondition:
    None

  Parameters:
    source  - Interrupt source.

  Returns:
    * 0 if the interrupt request flag is clear
    * else request flag is set
  Example:
    <code>
    if(INTGetFlag(INT_CT))
    {
        // ... do something
    }
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline unsigned int __attribute__ ((always_inline)) 
INTGetFlag( INT_SOURCE source )
{ 
    volatile UINT *ifs  =   (volatile UINT *)(0xBF810040 + ((UINT)0x10*((UINT)source/(UINT)32)));     //IFSx
    UINT bit_offset = (UINT)source & (UINT)0x1F;    
    
    return ((*ifs) & (1 << bit_offset));
}

/*******************************************************************************
  Function:
    void INTEnable(INT_SOURCE source, INT_EN_DIS enable)

  Summary:
    Enables or disables the interrupt.

  Description:
    This routine enables or disables the interrupt source.

  Precondition:
    None

  Parameters:
    source  - Interrupt source.
    enable  - Enable state to set.

  Returns:
    None

  Example:
    <code>
    INTEnable(INT_CT, INT_ENABLED);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTEnable( INT_SOURCE source, INT_EN_DIS enable )
{
    if( source >= INT_SOURCE_NOSRC ) return;
    
    volatile UINT *iec_clr  =   (volatile UINT *)(0xBF8100C4 + ((UINT)0x10*((UINT)source/(UINT)32)));     //IECxCLR
    UINT bit_mask = (1 << ((UINT)source & (UINT)0x1F));
    
    if(enable)
    {
        iec_clr++;
        *iec_clr   = bit_mask;
    }
    else
    {
        *iec_clr   = bit_mask;    
    }
}

/*******************************************************************************
  Function:
    unsigned int INTGetEnable(INT_SOURCE source)

  Summary:
    Gets the interrupt enable.

  Description:
    This routine gets an interrupt enable.

  Precondition:
    None

  Parameters:
    source  - Interrupt source.

  Returns:
    * 0 if interrupt is disabled
    * else interrupt is enabled

  Example:
    <code>
    if(INTGetEnable(INT_CT))
    {
        // ... do something
    }
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline unsigned int __attribute__ ((always_inline)) 
INTGetEnable( INT_SOURCE source )
{  
    volatile UINT *iec  =   (volatile UINT *)(0xBF8100C0 + ((UINT)0x10*((UINT)source/(UINT)32)));     //IECx
    UINT bit_offset = (UINT)source & (UINT)0x1F;    
    
    return ((*iec) & (1 << bit_offset));     
}

/*******************************************************************************
  Function:
    void INTSetVectorPriority(INT_VECTOR vector, INT_PRIORITY priority)

  Summary:
    Sets the interrupt vector's priority.

  Description:
    This routine sets the interrupt vector's priority.

  Precondition:
    None

  Parameters:
    vector    - Interrupt vector.
    priority  - Interrupt vector's priority.

  Returns:
    None

  Example:
    <code>
    INTSetVectorPriority(INT_CORE_TIMER_VECTOR, INT_PRIORITY_LEVEL_4);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSetVectorPriority( INT_VECTOR vector, INT_PRIORITY priority )
{
	volatile uint32_t *IPCx = (volatile uint32_t *)(&IPC0 + ((0x10 * (vector >> 2)) >> 2));
	uint32_t mask = 0x07 << ((vector & 0x03) * 8 + 2);
	uint32_t position = (vector & 0x03) * 8 + 2;

	/* read-modify-write */
	*IPCx &= ~mask;
	*IPCx |= (priority << position) & mask;	
}

/*******************************************************************************
  Function:
    INT_PRIORITY INTGetVectorPriority(INT_VECTOR vector)

  Summary:
    Gets the interrupt vector's priority.

  Description:
    This routine gets the interrupt vector's priority.

  Precondition:
    None

  Parameters:
    vector    - Interrupt vector.

  Returns:
    interrupt vector's priority

  Example:
    <code>
    INT_PRIORITY intPriority;

    intPriority = INTGetVectorPriority(INT_CORE_TIMER_VECTOR);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline INT_PRIORITY __attribute__ ((always_inline)) 
INTGetVectorPriority( INT_VECTOR vector )
{ 
    volatile uint32_t *IPCx = (volatile uint32_t *)(&IPC0 + ((0x10 * (vector >> 2)) >> 2));
    uint32_t mask = 0x07 << (((vector & 0x03) * 8) + 2);
    uint32_t position = (((vector & 0x03) * 8) + 2);

    return (INT_PRIORITY)((*IPCx & mask) >> position);
}

/*******************************************************************************
  Function:
    void INTSetVectorSubPriority(INT_VECTOR vector, INT_SUB_PRIORITY subPriority)

  Summary:
    Sets the interrupt vector's sub-priority.

  Description:
    This routine sets the interrupt vector's sub-priority.

  Precondition:
    None

  Parameters:
    vector          - Interrupt vector.
    subPriority     - Interrupt vector's sub-priority.

  Returns:
    None

  Example:
    <code>
    INTSetVectorSubPriority(INT_CORE_TIMER_VECTOR, INT_SUB_PRIORITY_LEVEL_1);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSetVectorSubPriority( INT_VECTOR vector, INT_SUB_PRIORITY subPriority ) 
{  
	volatile uint32_t *IPCx = (volatile uint32_t *)(&IPC0 + ((0x10 * (vector >> 2)) >> 2));
	uint32_t mask = 0x03 << ((vector & 0x03) * 8);
	uint32_t position = (vector & 0x03) * 8;

	/* read-modify-write */
	*IPCx &= ~mask; /* zeroed mask */
	*IPCx |= (subPriority << position) & mask; /* set value */
}

/*******************************************************************************
  Function:
    INT_SUB_PRIORITY INTGetVectorSubPriority(INT_VECTOR vector)

  Summary:
    Gets the interrupt vector's priority.

  Description:
    This routine gets the interrupt vector's priority.

  Precondition:
    None

  Parameters:
    vector    - Interrupt vector.

  Returns:
    interrupt vector's sub-priority

  Example:
    <code>
    INT_SUB_PRIORITY intSubPriority;

    intSubPriority = INTGetVectorSubPriority(INT_CORE_TIMER_VECTOR);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline INT_SUB_PRIORITY __attribute__ ((always_inline)) 
INTGetVectorSubPriority( INT_VECTOR vector )
{ 
    volatile uint32_t *IPCx = (volatile uint32_t *)(&IPC0 + ((0x10 * (vector >> 2)) >> 2));
    uint32_t mask = 0x03 << ((vector & 0x03) * 8);
    uint32_t position = (vector & 0x03) * 8;

    return (INT_SUB_PRIORITY)((*IPCx & mask) >> position);
}

/* Function :  ExistsShadowRegisterAssign

  Summary:
    Implements Default variant of INTExistsShadowRegisterAssign

  Description:
    This template implements the Default variant of the INT_ExistsShadowRegisterAssign function.
*/
extern inline BOOL __attribute__ ((always_inline)) 
INTExistsShadowRegisterAssign( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  INTShadowRegisterAssign

  Summary:
    Implements Default variant of INTShadowRegisterAssign

  Description:
    This template implements the Default variant of the INTShadowRegisterAssign function.
*/
extern inline void __attribute__ ((always_inline)) 
INTShadowRegisterAssign( INT_PRIORITY_LEVEL priority , INT_SHADOW_REGISTER shadowRegister )
{
    volatile uint32_t *PRISSx = (volatile uint32_t *)&PRISS;

    *PRISSx &= ~(0x0f << (priority * 4));
    *PRISSx |= shadowRegister << (priority * 4);
}

//******************************************************************************
/* Function :  INTShadowRegisterGet

  Summary:
    Implements Default variant of INTShadowRegisterGet

  Description:
    This template implements the Default variant of the INTShadowRegisterGet function.
*/
extern inline INT_SHADOW_REGISTER __attribute__ ((always_inline))
INTShadowRegisterGet( INT_PRIORITY_LEVEL priority )
{
    return (INT_SHADOW_REGISTER) ((PRISS >> (priority * 4)) & 0x0f);
}

//******************************************************************************
/* Function :  INTExistsVariableOffset

  Summary:
    Implements Default variant of INTExistsVariableOffset

  Description:
    This template implements the Default variant of the INTExistsVariableOffset function.
*/
extern inline BOOL __attribute__ ((always_inline)) 
INTExistsVariableOffset( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  INTVariableVectorOffsetSet

  Summary:
    Implements Default variant of INTVariableVectorOffsetSet

  Description:
    This template implements the Default variant of the INTVariableVectorOffsetSet function.
*/
extern inline void __attribute__ ((always_inline)) 
INTVariableVectorOffsetSet( INT_VECTOR vector , uint32_t offset )
{
    volatile uint32_t *OFFx = (volatile uint32_t *)(&OFF000 + (vector));

    *OFFx = offset; /* backward compatibility */
}

//******************************************************************************
/* Function :  INTVariableVectorOffsetGet

  Summary:
    Implements Default variant of INTVariableVectorOffsetGet

  Description:
    This template implements the Default variant of the INTVariableVectorOffsetGet function.
*/
extern inline uint32_t __attribute__ ((always_inline)) 
INTVariableVectorOffsetGet( INT_VECTOR vector )
{
    volatile uint32_t *OFFx = (volatile uint32_t *)(&OFF000 + (vector));

    return (uint32_t)*OFFx; /* backward compatibility */
}

//******************************************************************************
/* Function :  INTExistsSoftwareNMI

  Summary:
    Implements Default variant of INT_ExistsSoftwareNMI

  Description:
    This template implements the Default variant of the INTExistsSoftwareNMI function.
*/
extern inline BOOL __attribute__ ((always_inline)) 
INTExistsSoftwareNMI( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  INTSoftwareNMITrigger

  Summary:
    Implements Default variant of INTSoftwareNMITrigger 

  Description:
    This template implements the Default variant of the INTSoftwareNMITrigger function.
*/
extern inline BOOL __attribute__ ((always_inline)) 
INTSoftwareNMITrigger( void )
{
    INTCONbits.NMIKEY = 0x4e;
}

/*******************************************************************************
  Function:
    extern inline void __attribute__ ((always_inline)) INTSetIntProximityTimerReload(unsigned int time)

  Summary:
    Sets or reloads the interrupt proximity timer.

  Description:
    This routine sets or reloads the interrupt proximity timer.

  Precondition:
    None

  Parameters:
    time            - 32-bit timer value.

  Returns:
    None

  Example:
    <code>
    INTSetIntProximityTimerReload(56000);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSetIntProximityTimerReload(unsigned int time)
{
    IPTMR = time;
}

/*******************************************************************************
  Function:
    extern inline unsigned int __attribute__ ((always_inline)) INTGetIntProximityTimer(void)

  Summary:
    Gets the interrupt proximity timer.

  Description:
    This routine gets the interrupt proximity timer.

  Precondition:
    None

  Parameters:
    None

  Returns:
    The current tick count of the timer.

  Example:
    <code>
    unsigned int time

    time = INTGetIntProximityTimer();
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline unsigned int __attribute__ ((always_inline)) 
INTGetIntProximityTimer(void)
{
    return IPTMR;
}

/*******************************************************************************
  Function:
    extern inline void __attribute__ ((always_inline)) INTSetTemporalProximityControl(INT_TPC_GROUP level)

  Summary:
    Sets the Temporal Proximity Control level.

  Description:
    This routine sets the temporal Proximity Control level.

  Precondition:
    None

  Parameters:
    level   - Level of the temporal proximity control.

  Returns:
    None

  Example:
    <code>
    INTSetTemporalProximityControl(INT_TPC_GROUP_PRI_LEVEL_3);
    </code>

  Remarks:
    None
  *****************************************************************************/
extern inline void __attribute__ ((always_inline)) 
INTSetTemporalProximityControl( INT_TPC_GROUP level )
{
    INTCONCLR = INT_TPC_DISABLE;

    if(level != INT_TPC_DISABLE)
        INTCONSET = (level << _INTCON_TPC_POSITION);
}


/*******************************************************************************
//DOM-IGNORE-BEGIN
  *****************************************************************************/
#define CORE_SW_0           0x00000100
#define CORE_SW_1           0x00000200
/*******************************************************************************
//DOM-IGNORE-END
  *****************************************************************************/


/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) CoreSetSoftwareInterrupt0(void)

  Summary:
    Set the Core Software Interrupt 0.

  Description:
    This routine sets the core software interrupt 0.  This will produce an interrupt
    service request.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Example:
    <code>

    CoreSetSoftwareInterrupt0();
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))
CoreSetSoftwareInterrupt0( void )
{
   unsigned int val;
   asm volatile("mfc0 %0,$13" : "=r" (val));
   val |= CORE_SW_0;
   asm volatile("mtc0 %0,$13" : "+r" (val));
}

/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) CoreSetSoftwareInterrupt1(void)

  Summary:
    Set the Core Software Interrupt 1.

  Description:
    This routine sets the core software interrupt 1.  This will produce an interrupt
    service request.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Example:
    <code>

    CoreSetSoftwareInterrupt1();
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
CoreSetSoftwareInterrupt1( void )
{
   unsigned int val;
   asm volatile("mfc0 %0,$13" : "=r" (val));
   val |= CORE_SW_1;
   asm volatile("mtc0 %0,$13" : "+r" (val));
}

/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) CoreClearSoftwareInterrupt0(void)

  Summary:
    Clears the Core Software Interrupt 0.

  Description:
    This routine clears the core software interrupt 0.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Example:
    <code>

    CoreClearSoftwareInterrupt0();

    INTClearFlag(INT_CS0);
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.

    You must call this routine before clearing the interrupt request flag.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))
CoreClearSoftwareInterrupt0(void)
{
   unsigned int val;
   asm volatile("mfc0 %0,$13" : "=r" (val));
   val &= ~(CORE_SW_0);
   asm volatile("mtc0 %0,$13" : "+r" (val));
}

/*******************************************************************************
  Function:
    void __attribute__ ((nomips16)) CoreClearSoftwareInterrupt1(void)

  Summary:
    Clears the Core Software Interrupt 1.

  Description:
    This routine clears the core software interrupt 1.

  Precondition:
    None

  Parameters:
    None

  Returns:
    None

  Example:
    <code>

    CoreClearSoftwareInterrupt1();

    INTClearFlag(INT_CS1);
    </code>

  Remarks:
    This function cannot be compiled using the MIPS16 instruction set.

    You must call this routine before clearing the interrupt request flag.
  *****************************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline))  
CoreClearSoftwareInterrupt1(void)
{
   unsigned int val;
   asm volatile("mfc0 %0,$13" : "=r" (val));
   val &= ~(CORE_SW_1);
   asm volatile("mtc0 %0,$13" : "+r" (val));
}


#ifdef	__cplusplus
}
#endif

#endif	/* INT_H */

