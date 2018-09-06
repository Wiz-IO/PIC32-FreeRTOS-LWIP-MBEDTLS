/*
		FileName: wdt.h
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

#ifndef WDT_H
#define	WDT_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*********************************************************************
 * Function:        EnableWDT()
 *
 * Description:     Enables the WDT
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableWDT()
 *
 ********************************************************************/
#define EnableWDT() (WDTCONSET = _WDTCON_ON_MASK)


/*********************************************************************
 * Function:        DisableWDT()
 *
 * Description:     Disables the WDT
 *
 * PreCondition:    WDT must not be enabled by the device configuration
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableWDT()
 *
 ********************************************************************/
#define DisableWDT() (WDTCONCLR = _WDTCON_ON_MASK)


/*********************************************************************
 * Function:        ClearWDT()
 *
 * Description:     Resets the WDT
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         ClearWDT()
 *
 ********************************************************************/
extern inline void __attribute__ ((always_inline)) __attribute__((optimize("-O0"))) 
ClearWDT( void )
{
    volatile uint16_t * wdt_clrkey;

    /* get address of upper 16-bit word of the WDTCON SFR */
    wdt_clrkey = ( (volatile uint16_t *)&WDTCON ) + 1;
    *wdt_clrkey = 0x5743;
}


/*********************************************************************
 * Function:        ClearEventWDT()
 *
 * Description:     Clears the WDT event bit
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         ClearEventWDT()
 *
 ********************************************************************/
#define ClearEventWDT() ( RCONCLR = _RCON_WDTO_MASK)


/*********************************************************************
 * Function:        ReadEventWDT()
 *
 * Description:     Returns the state of the WDT event bit
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          State of the WDT event bit
 *
 * Example:         ReadEventWDT()
 *
 ********************************************************************/
#define ReadEventWDT() (RCONbits.WDTO)


/*********************************************************************
 * Function:        ReadPostscalerWDT()
 *
 * Description:     Returns the WDT prescaler value
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          The WDT Postscaler value
 *
 * Example:         ReadPostscalerWDT()
 *
 ********************************************************************/
#define ReadPostscalerWDT()  (WDTCONbits.RUNDIV)


#ifdef	__cplusplus
}
#endif

#endif	/* WDT_H */

