/*
		FileName: lock.h
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

#ifndef LOCK_H
#define	LOCK_H

#include <xc.h>
#include "fan_int.h"
#ifdef	__cplusplus
extern "C" {
#endif

    
    
/*********************************************************************
  Function:        void mSYSTEMUnlock(intStat, dmaSusp)

  PreCondition:    None

  Input:           None

  Output:          None

  Side Effects:    The system will be unlocked, the interrupts disabled and the DMA
            operation suspended.
            The previous interrupt and DMA status is saved in the passed parameters,
            supposed to be integers.

  Example:
    <code>
    unsigned int status1, status2;
    mSYSTEMUnlock(status1, status2);
    //change some system settings
    mSYSTEMLock(status1, status2);
    </code>
  Note:            The first write is "garbage" to ensure that the
                   unlocking is correctly preformed
 ********************************************************************/
#define mSYSTEMUnlock(intStat, dmaSusp) do{intStat=INTDisableInterrupts(); \
                    SYSKEY = 0, SYSKEY = 0xAA996655, SYSKEY = 0x556699AA;}while(0)

// *****************************************************************************
/* Function:
    void SystemUnlock( void )

  Summary:
    Performs a system unlock sequence by writing to the SYSKEY register.

  Description:
    Performs a system unlock sequence by writing to the SYSKEY register. A 
    system unlock sequence is required before performing certain actions such
    as changing a clock frequency or IO unlocking.

  Remarks:
    None.
*/

void extern inline __attribute__((nomips16,nomicromips,always_inline))  SystemUnlock( void )
{
    unsigned int status;

    status = INTDisableInterrupts();
    SYSKEY = 0x00000000;
	SYSKEY = 0xAA996655;
	SYSKEY = 0x556699AA;
    INTRestoreInterrupts(status);
} 
    
    
/*********************************************************************
  Function:        void mSYSTEMLock(intStat, dmaSusp)

  PreCondition:    None

  Input:           None

  Output:          None

   Example:
    <code>
    unsigned int status1, status2;
    mSYSTEMUnlock(status1, status2);
    //change some system settings
    mSYSTEMLock(status1, status2);
    </code>

  Side Effects:    The system will be locked and the status of the interrupts and the DMA restored
            from the integer parameters passed.
 ********************************************************************/
#define mSYSTEMLock(intStat, dmaSusp)   do{SYSKEY = 0x33333333; INTRestoreInterrupts(intStat);}while(0)

// *****************************************************************************
/* Function:
    void SystemLock( void )

  Summary:
    Performs a system lock sequence by writing to the SYSKEY register.

  Description:
    Performs a system lock sequence by writing to the SYSKEY register. A 
    system lock sequence is required after performing the action that required
    a system lock sequence.

  Remarks:
    None.
*/

void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
SystemLock( void )
{
    unsigned int status;

    status = INTDisableInterrupts();
    SYSKEY = 0x33333333;
    INTRestoreInterrupts(status);
}


/*********************************************************************
  Function:        void mSysUnlockOpLock(op)

  PreCondition:    None

  Input:           Operator to be performed between unlocking and locking the system.

  Output:          None


  Side Effects:    The system will be unlocked, the operation(s) passed as parameter will be executed
            and the system will be locked again.

  Note:            None
 ********************************************************************/
#define mSysUnlockOpLock(op)    do{int intStat; intStat=INTDisableInterrupts(); \
            SYSKEY = 0; SYSKEY = 0xAA996655; SYSKEY = 0x556699AA; \
            (op); \
            SYSKEY = 0x33333333; \
            INTRestoreInterrupts(intStat);}while(0)



#ifdef	__cplusplus
}
#endif

#endif	/* LOCK_H */

