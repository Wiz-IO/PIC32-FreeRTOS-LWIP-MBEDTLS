/*
		FileName: power.h
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

#ifndef POWER_H
#define	POWER_H

#include <xc.h>
#include "fan_lock.h"

#ifdef	__cplusplus
extern "C" {
#endif


/*********************************************************************
 * Function:        PowerSaveSleep()
 *
 * Description:     Sets Powersave mode to Sleep and enters Sleep mode
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         PowerSaveSleep()
 *
 ********************************************************************/
void  extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PowerSaveSleep(void)
{
 	mSysUnlockOpLock((OSCCONSET = (1 << _OSCCON_SLPEN_POSITION)));
    asm volatile("WAIT");
}



/*********************************************************************
 * Function:        PowerSaveIdle()
 *
 * Description:     Sets Powersave mode to Idle and enters Idle mode
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         PowerSaveIdle()
 *
 ********************************************************************/
void  extern inline __attribute__((nomips16,nomicromips,always_inline))  
PowerSaveIdle(void)
{
 	mSysUnlockOpLock((OSCCONCLR = (1 << _OSCCON_SLPEN_POSITION)));
    asm volatile("WAIT");
}


#ifdef	__cplusplus
}
#endif

#endif	/* POWER_H */

