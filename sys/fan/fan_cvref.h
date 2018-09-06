/*
		FileName: cvref.h
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

#ifndef CVREF_H
#define	CVREF_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

/*********************************************************************
 * Function:      CVREFOpen(config)
 *
 * Description:   Configures CVREF
 *
 * PreCondition:  None
 *
 * Inputs:      Desired configuration - see below
 *
 * Output:        None
 *
 * Example:   CVREFOpen( CVREF_ENABLE | CVREF_OUTPUT_ENABLE | CVREF_RANGE_HIGH | CVREF_SOURCE_AVDD | CVREF_STEP_15 )
 *
 ********************************************************************/
#define CVREFOpen(config) (CVRCON = (config))

    /****************************************
     * Available options for config parameter
     ****************************************/
        // CVRef mode select - values are mutually exclusive
        #define CVREF_ENABLE            (1 << _CVRCON_ON_POSITION)
        #define CVREF_DISABLE           (0)

        // CVRef output control - values are mutually exclusive
        #define CVREF_OUTPUT_ENABLE     (1 << _CVRCON_CVROE_POSITION)
        #define CVREF_OUTPUT_DISABLE    (0)

        // CVRef range control - values are mutually exclusive
        #define CVREF_RANGE_HIGH        (0)
        #define CVREF_RANGE_LOW         (1 << _CVRCON_CVRR_POSITION)

        // CVRef Reference source select - values are mutually exclusive
        #define CVREF_SOURCE_AVDD       (0)
        #define CVREF_SOURCE_VREF       (1 << _CVRCON_CVRSS_POSITION)

        // CVRef Output Voltage Select - values are mutually exclusive
        #define CVREF_STEP_0            (0)
        #define CVREF_STEP_1            (1 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_2            (2 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_3            (3 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_4            (4 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_5            (5 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_6            (6 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_7            (7 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_8            (8 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_9            (9 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_10           (10 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_11           (11 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_12           (12 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_13           (13 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_14           (14 << _CVRCON_CVR_POSITION)
        #define CVREF_STEP_15           (15 << _CVRCON_CVR_POSITION)
    /****************************************
     * End config1 parameter values
     ****************************************/



/*********************************************************************
 * Function:      CVREFClose()
 *
 * Description:   Disables CVREF
 *
 * PreCondition:  None
 *
 * Inputs:        None
 *
 * Output:        None
 *
 * Example:       CVREFClose()
 *
 ********************************************************************/
#define CVREFClose()    (CVRCONCLR = _CVRCON_ON_MASK)


#ifdef	__cplusplus
}
#endif

#endif	/* CVREF_H */

