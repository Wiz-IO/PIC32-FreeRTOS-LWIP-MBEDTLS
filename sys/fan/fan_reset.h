/*
		FileName: reset.h
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

#ifndef RESET_H
#define	RESET_H

#include <xc.h>
#include "fan_lock.h"

#ifdef	__cplusplus
extern "C" {
#endif

/******************************************************************************************************************************
  * <combinewith mGetBORFlag, mGetMCLRFlag, mGetSWRFlag, mGetWDTOFlag, mGetCMRFlag, mGetIDLEFlag, mGetSLEEPFlag, mGetVREGSFlag>
  *
  * Prototype:
  *     mGetPORFlag(void) mGetBORFlag(void) mGetMCLRFlag(void)
  *     mGetWDTOFlag(void) mGetCMRFlag(void) mGetSWRFlag(void)
  *     mGetSLEEPFlag(void) mGetIDLEFlag(void) mGetVREGSFlag(void)
  * Description:
  *     RESET Status bit Macros
  *
  *     These macros get/set their corresponding status bit
  * Preconditions:
  *     None
  * Return:
  *     The values returned are either '0' or a '1' in the respective
  *     status bit position.
  *
  * Example:
  *     mGetPORFlag(); - This macro returns '0' or '1' (0x0001)
  *     mGetBORFlag(); - This macro returns '0' or '2' (0x0002)
  *     mGetWDTOFlag(); - This macro returns '0' or '8' (0x0008) ...
  *     mGetMCLRFlag(); - This macro returns '0' or '128' (0x0080)
  *****************************************************************************************************************************
*/
#define mGetPORFlag()                   (RCONbits.POR)
#define mGetBORFlag()                   (RCONbits.BOR)
#define mGetMCLRFlag()                  (RCONbits.EXTR)
#define mGetSWRFlag()                   (RCONbits.SWR)
#define mGetWDTOFlag()                  (RCONbits.WDTO)
#define mGetDMTOFlag()                  (RCONbits.DMTO)    
#define mGetCMRFlag()                   (RCONbits.CMR)
#define mGetSLEEPFlag()                 (RCONbits.SLEEP)
#define mGetIDLEFlag()                  (RCONbits.IDLE)
#define mGetVREGSFlag()                 (PWRCONbits.VREGS)


/*************************************************************************************************************************************************************
  * <combinewith mClearBORFlag, mClearCMRFlag, mClearIDLEFlag, mClearMCLRFlag, mClearSLEEPFlag, mClearSWRFlag, mClearVREGSFlag, mClearWDTOFlag, mSetVREGSFlag>
  *
  * Prototype:
  *     mClearPORFlag() mClearBORFlag() mClearMCLRFlag()
  *     mClearSWRFlag() mClearWDTOFlag() mClearCMRFlag()
  *     mClearSLEEPFlag() mClearIDLEFlag() mClearVREGSFlag()
  *     mSetVREGSFlag()
  * Description:
  *     RESET Clear/Set Status Macros
  *
  *     These macros clear/set their corresponding status bit
  * Preconditions:
  *     None
  * Return:
  *     None
  *
  * Example:
  *     mClearMCLRFlag(); - This macro clears MCLR bit in RCON
  *     register
  ************************************************************************************************************************************************************
*/
#define mClearPORFlag()                 (RCONCLR = _RCON_POR_MASK)
#define mClearBORFlag()                 (RCONCLR = _RCON_BOR_MASK)
#define mClearMCLRFlag()                (RCONCLR = _RCON_EXTR_MASK)
#define mClearSWRFlag()                 (RCONCLR = _RCON_SWR_MASK)
#define mClearWDTOFlag()                (RCONCLR = _RCON_WDTO_MASK)
#define mClearDMTOFlag()                (RCONCLR = _RCON_DMTO_MASK)   
#define mClearCMRFlag()                 (RCONCLR = _RCON_CMR_MASK)
#define mClearSLEEPFlag()               (RCONCLR = _RCON_SLEEP_MASK)
#define mClearIDLEFlag()                (RCONCLR = _RCON_IDLE_MASK)
#define mClearVREGSFlag()               (PWRCONCLR = _PWRCON_VREGS_MASK)
#define mSetVREGSFlag()                 (PWRCONSET = _PWRCON_VREGS_MASK)

/******************************************************************************
 * Function:            void SoftReset(void)
 *
 * Description:         software device reset
 *
 * PreCondition:        None
 *
 * Inputs:              None
 *
 * Output:              None
 *
 * Example:             SoftReset();
 *
 * How it works:        The following steps are performed by this function:
 *                      Step 1 - Execute "unlock" sequence to access the RSWRST register.
 *                      Step 2 - Write a '1' to RSWRST.SWRST bit to arm the software reset.
 *                      Step 3 - A Read of the RSWRST register must follow the write.  This
 *                      action triggers the software reset, which should occur on the next
 *                      clock cycle.
 * Note:                The read instruction must be following with either 4 nop
 *                      instructions (fills the instruction pipe) or a while(1)loop to
 *                      ensure no instructions can access the bus before reset occurs.
 *****************************************************************************/
extern __inline__ void __attribute__((always_inline, noreturn)) 
SoftReset(void)
{
	int	intStat;
	int	dmaSusp;
	volatile int* p = &RSWRST;

	mSYSTEMUnlock(intStat, dmaSusp);
	RSWRSTSET = _RSWRST_SWRST_MASK;
	*p;

	while(1);
}


/******************************************************************************
 * Check status of wakeup event
 *
 * Function:        isWU()
 *
 * Description:     Checks if wakeup from sleep was caused by MCLR, POR or BOR
 *                  or interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          Return codes:   0= no wake from sleep
 *                                  1 = wake from sleep due to interrupt
 *                                  2 = wake from sleep due to MCLR
 *                                  4 = wake from sleep due to BOR
 *
 * Example:         isWU();
 *
 *****************************************************************************/
extern __inline__ char __attribute__((always_inline)) 
isWU(void)
{
   if( RCONbits.SLEEP )
   {
       if(RCONbits.EXTR)
       {
           return 2;        /* wakeup is due to MCLR */
       }

       if(RCONbits.BOR)
       {
           return 4;        /* wakeup is due to BOR */
       }
       else
           return 1;        /* else, wakeup is due to interrupt. */
   }
  return 0;
}

/******************************************************************************
 * Reset POR event
 *
 * Function:        PORStatReset
 *
 * Description:     Clears POR event flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          None
 *
 * Example:         PORStatReset;
 *
 *****************************************************************************/
#define PORStatReset                    mClearPORFlag()


/******************************************************************************
 * Reset BOR event
 *
 * Function:        BORStatReset
 *
 * Description:     Clears BOR event flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          None
 *
 * Example:         BORStatReset;
 *
 *****************************************************************************/
#define BORStatReset                    mClearBORFlag()

/******************************************************************************
 * Checks to see if this was MCLR reset
 *
 * Function:        int isMCLR(void)
 *
 * Description:     Returns MCLR event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if MCLR ocurred,
 *                  '0' otherwise
 *
 * Example:         isMCLR();
 *
 *****************************************************************************/
#define isMCLR()                        mGetMCLRFlag()

/******************************************************************************
 * Checks to see if this was POR reset
 *
 * Function:        int isPOR(void)
 *
 * Description:     Returns POR event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if POR ocurred,
 *                  '0' otherwise
 *
 * Example:         isPOR();
 *
 *****************************************************************************/
#define isPOR()                         mGetMCLRFlag()


/******************************************************************************
 * Checks to see if this was BOR reset
 *
 * Function:        int isBOR(void)
 *
 * Description:     Returns BOR event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if BOR ocurred,
 *                  '0' otherwise
 *
 * Example:         isBOR();
 *
 *****************************************************************************/
#define isBOR()                         mGetBORFlag()


/******************************************************************************
 * Checks to see if this was LVD event
 *
 * Function:        int isLVD(void)
 *
 * Description:     Returns LVD event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if LVD ocurred,
 *                  '0' otherwise
 *
 * Example:         isLVD();
 *
 *****************************************************************************/
#define isLVD()                         0

/******************************************************************************
 * Checks to see if this was WDTO reset
 *
 * Function:        int isWDTO(void)
 *
 * Description:     Returns WDTO event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if WDTO ocurred,
 *                  '0' otherwise
 *
 * Example:         isPOR();
 *
 *****************************************************************************/
#define isWDTTO()                       (RCONbits.WDTO)


/******************************************************************************
 * Checks to see if this was WDT wakeup reset
 *
 * Function:        int isWDTWU(void)
 *
 * Description:     Returns WDT wakeup event occurred flag
 *
 * PreCondition:    None
 *
 * Inputs:          none
 *
 * Output:          '1' if WDT wakeup ocurred,
 *                  '0' otherwise
 *
 * Example:         isPOR();
 *
 *****************************************************************************/
#define isWDTWU()                       ((RCONbits.WDTO ) && (RCONbits.SLEEP))


//******************************************************************************
/* Function :  resetNmiGet

  Summary:
    Implements Default variant of resetNmiGet 

  Description:
    This template implements the Default variant of the resetNmiGet function.
*/
extern __inline__ unsigned int __attribute__((always_inline)) 
resetNmiGet( void )
{
    return (RNMICON & (~_RNMICON_NMICNT_MASK));
}


//******************************************************************************
/* Function :  resetNmiEventSet

  Summary:
    Implements Default variant of resetNmiEventSet 

  Description:
    This template implements the Default variant of the resetNmiEventSet function.
*/
extern __inline__ void __attribute__((always_inline)) 
resetNmiEventSet( unsigned int nmi_set )
{
    mSysUnlockOpLock((RNMICONSET = nmi_set));
}


//******************************************************************************
/* Function :  resetNmiEventClear

  Summary:
    Implements Default variant of resetNmiEventClear 

  Description:
    This template implements the Default variant of the resetNmiEventClear function.
*/
extern __inline__ void __attribute__((always_inline)) 
resetNmiEventClear( unsigned int nmi_reason )
{
    mSysUnlockOpLock((RNMICONCLR = nmi_reason));
}




#ifdef	__cplusplus
}
#endif

#endif	/* RESET_H */

