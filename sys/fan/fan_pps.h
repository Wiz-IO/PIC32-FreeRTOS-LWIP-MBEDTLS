/*
		FileName: pps.h
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

#ifndef PPS_H
#define	PPS_H

#include <xc.h>

/*
Example Code:

   // Assign UART 2 signals onto pins using PPS
    PPSInput(2,U2RX, RPA9);  //Assign U2RX to pin RPA09
    PPSInput(3,U2CTS,RPC3);  //Assign U2CTS to pin RPC3
    PPSOutput(4,RPC4,U2TX);   //Assign U2TX to pin RPC4
    PPSOutput(1,RPB15,U2RTS); //Assign U2RTS to pin RPB15

 */

#ifdef	__cplusplus
extern "C" {
#endif

/* Input Pins Group 1 */
#define IN_FN_PPS1_INT3          INT3Rbits.INT3R
#define IN_FN_PPS1_T2CK          T2CKRbits.T2CKR
#define IN_FN_PPS1_T6CK          T6CKRbits.T6CKR
#define IN_FN_PPS1_IC3           IC3Rbits.IC3R
#define IN_FN_PPS1_IC7           IC7Rbits.IC7R
#define IN_FN_PPS1_U1RX          U1RXRbits.U1RXR
#define IN_FN_PPS1_U2CTS         U2CTSRbits.U2CTSR
#define IN_FN_PPS1_U5RX          U5RXRbits.U5RXR
#define IN_FN_PPS1_U6CTS         U6CTSRbits.U6CTSR
#define IN_FN_PPS1_SDI1          SDI1Rbits.SDI1R
#define IN_FN_PPS1_SDI3          SDI3Rbits.SDI3R
#define IN_FN_PPS1_SDI5          SDI5Rbits.SDI5R
#define IN_FN_PPS1_SS6           SS6Rbits.SS6R
#define IN_FN_PPS1_REFCLKI1      REFCLKI1Rbits.REFCLKI1R

#define IN_PIN_PPS1_RPD2         0   /* Assign RPD2  as Input Pin */
#define IN_PIN_PPS1_RPG8         1   /* Assign RPG8  as Input Pin */
#define IN_PIN_PPS1_RPF4         2   /* Assign RPF4  as Input Pin */
#define IN_PIN_PPS1_RPD10        3   /* Assign RPD10 as Input Pin */
#define IN_PIN_PPS1_RPF1         4   /* Assign RPF1  as Input Pin */
#define IN_PIN_PPS1_RPB9         5   /* Assign RPB9  as Input Pin */
#define IN_PIN_PPS1_RPB10        6   /* Assign RPB10 as Input Pin */
#define IN_PIN_PPS1_RPC14        7   /* Assign RPC14 as Input Pin */
#define IN_PIN_PPS1_RPB5         8   /* Assign RPB5  as Input Pin */
//                               9   - RESERVED
#define IN_PIN_PPS1_RPC1         10  /* Assign RPC1  as Input Pin */
#define IN_PIN_PPS1_RPD14        11  /* Assign RPD14 as Input Pin */
#define IN_PIN_PPS1_RPG1         12  /* Assign RPG1  as Input Pin */
#define IN_PIN_PPS1_RPA14        13  /* Assign RPA14 as Input Pin */
#define IN_PIN_PPS1_RPD6         14  /* Assign RPD6  as Input Pin */
//                               15  - RESERVED

/* Input Pins Group 2 */
#define IN_FN_PPS2_INT4          INT4Rbits.INT4R
#define IN_FN_PPS2_T5CK          T5CKRbits.T5CKR
#define IN_FN_PPS2_T7CK          T7CKRbits.T7CKR
#define IN_FN_PPS2_IC4           IC4Rbits.IC4R
#define IN_FN_PPS2_IC8           IC8Rbits.IC8R
#define IN_FN_PPS2_U3RX          U3RXRbits.U3RXR
#define IN_FN_PPS2_U4CTS         U4CTSRbits.U4CTSR
#define IN_FN_PPS2_SDI2          SDI2Rbits.SDI2R
#define IN_FN_PPS2_SDI4          SDI4Rbits.SDI4R
#define IN_FN_PPS2_C1RX          C1RXRbits.C1RXR
#define IN_FN_PPS2_REFCLKI4      REFCLKI4Rbits.REFCLKI4R
    
#define IN_PIN_PPS2_RPD3         0   /* Assign RPD3  as Input Pin */
#define IN_PIN_PPS2_RPG7         1   /* Assign RPG7  as Input Pin */
#define IN_PIN_PPS2_RPF5         2   /* Assign RPF5  as Input Pin */
#define IN_PIN_PPS2_RPD11        3   /* Assign RPD11 as Input Pin */
#define IN_PIN_PPS2_RPF0         4   /* Assign RPF0  as Input Pin */
#define IN_PIN_PPS2_RPB1         5   /* Assign RPB1  as Input Pin */
#define IN_PIN_PPS2_RPE5         6   /* Assign RPE5  as Input Pin */
#define IN_PIN_PPS2_RPC13        7   /* Assign RPC13 as Input Pin */
#define IN_PIN_PPS2_RPB3         8   /* Assign RPB3  as Input Pin */
//                               9   - RESERVED
#define IN_PIN_PPS2_RPC4         10  /* Assign RPC4  as Input Pin */
#define IN_PIN_PPS2_RPD15        11  /* Assign RPD15 as Input Pin */
#define IN_PIN_PPS2_RPG0         12  /* Assign RPG0  as Input Pin */
#define IN_PIN_PPS2_RPA15        13  /* Assign RPA15 as Input Pin */
#define IN_PIN_PPS2_RPD7         14  /* Assign RPD7  as Input Pin */
//                               15  - RESERVED

/* Input Pins Group 3 */
#define IN_FN_PPS3_INT2          INT2Rbits.INT2R
#define IN_FN_PPS3_T3CK          T3CKRbits.T3CKR
#define IN_FN_PPS3_T8CK          T8CKRbits.T8CKR
#define IN_FN_PPS3_IC2           IC2Rbits.IC2R
#define IN_FN_PPS3_IC5           IC5Rbits.IC5R
#define IN_FN_PPS3_IC9           IC9Rbits.IC9R
#define IN_FN_PPS3_U1CTS         U1CTSRbits.U1CTSR
#define IN_FN_PPS3_U2RX          U2RXRbits.U2RXR
#define IN_FN_PPS3_U5CTS         U5CTSRbits.U5CTSR
#define IN_FN_PPS3_SS1           SS1Rbits.SS1R
#define IN_FN_PPS3_SS3           SS3Rbits.SS3R
#define IN_FN_PPS3_SS4           SS4Rbits.SS4R
#define IN_FN_PPS3_SS5           SS5Rbits.SS5R
#define IN_FN_PPS3_C2RX          C2RXRbits.C2RXR

#define IN_PIN_PPS3_RPD9         0   /* Assign RPD9  as Input Pin */
#define IN_PIN_PPS3_RPG6         1   /* Assign RPG6  as Input Pin */
#define IN_PIN_PPS3_RPB8         2   /* Assign RPB8  as Input Pin */
#define IN_PIN_PPS3_RPB15        3   /* Assign RPB15 as Input Pin */
#define IN_PIN_PPS3_RPD4         4   /* Assign RPD4  as Input Pin */
#define IN_PIN_PPS3_RPB0         5   /* Assign RPB0  as Input Pin */
#define IN_PIN_PPS3_RPE3         6   /* Assign RPE3  as Input Pin */
#define IN_PIN_PPS3_RPB7         7   /* Assign RPB7  as Input Pin */
//                               8   - RESERVED
#define IN_PIN_PPS3_RPF12        9   /* Assign RPF12 as Input Pin */
#define IN_PIN_PPS3_RPD12        10  /* Assign RPD12 as Input Pin */
#define IN_PIN_PPS3_RPF8         11  /* Assign RPF8  as Input Pin */
#define IN_PIN_PPS3_RPC3         12  /* Assign RPC3  as Input Pin */
#define IN_PIN_PPS3_RPE9         13  /* Assign RPE9  as Input Pin */
//                               14  - RESERVED
//                               15 - RESERVED
    
/* Input Pins Group 4 */
#define IN_FN_PPS4_INT1          INT1Rbits.INT1R
#define IN_FN_PPS4_T4CK          T4CKRbits.T4CKR
#define IN_FN_PPS4_T9CK          T9CKRbits.T9CKR    
#define IN_FN_PPS4_IC1           IC1Rbits.IC1R
#define IN_FN_PPS4_IC6           IC6Rbits.IC6R   
#define IN_FN_PPS4_U3CTS         U3CTSRbits.U3CTSR
#define IN_FN_PPS4_U4RX          U4RXRbits.U4RXR
#define IN_FN_PPS4_U6RX          U6RXRbits.U6RXR
#define IN_FN_PPS4_SS2           SS2Rbits.SS2R
#define IN_FN_PPS4_SDI6          SDI6Rbits.SDI6R
#define IN_FN_PPS4_OCFA          OCFARbits.OCFAR
#define IN_FN_PPS4_REFCLKI3      REFCLKI3Rbits.REFCLKI3R

#define IN_PIN_PPS4_RPD1         0   /* Assign RPD1  as Input Pin */
#define IN_PIN_PPS4_RPG9         1   /* Assign RPG9  as Input Pin */
#define IN_PIN_PPS4_RPB14        2   /* Assign RPB14 as Input Pin */
#define IN_PIN_PPS4_RPD0         3   /* Assign RPD0  as Input Pin */
#define IN_PIN_PPS4_RPB6         5   /* Assign RPB6  as Input Pin */
#define IN_PIN_PPS4_RPD5         6   /* Assign RPD5  as Input Pin */
#define IN_PIN_PPS4_RPB2         7   /* Assign RPB2  as Input Pin */
#define IN_PIN_PPS4_RPF3         8   /* Assign RPF3  as Input Pin */
#define IN_PIN_PPS4_RPF13        9   /* Assign RPF13 as Input Pin */
#define IN_PIN_PPS4_NULL         10  /* Assign       as No Connect */
#define IN_PIN_PPS4_RPF2         11  /* Assign RPF2  as Input Pin */
#define IN_PIN_PPS4_RPC2         12  /* Assign RPC2  as Input Pin */
#define IN_PIN_PPS4_RPE8         13  /* Assign RPE8  as Input Pin */
//                               14  - RESERVED
//                               15  - RESERVED

/*********************************************************************
 Macro:             PPSInput(grp,fn,pin)

 PreCondition:     None

 Side Effects:     None

 Overview:          The macro assigns given pin as input pin by configuring register RPINRx.

 Parameters:grp - the group number that the peripheral or pin function

            fn - function to be assigned for particular pin
            *   TxCK
            *   INTx
            *   ICx
            *   OCFx
            *   UxRX
            *   UxCTS
            *   SDIx
            *   SCKxIN
            *   SSxIN

            pin - pin number(x) for which functionality has to be assigned
            *   RPx

 Returns:       None

 Note:              None
 ********************************************************************/
#define PPSInput(grp,fn,pin) IN_FN_PPS##grp##_##fn = IN_PIN_PPS##grp##_##pin    


/*===========================================================================*/
/*Section:  Remappable Peripheral Outputs:                                   */
/*===========================================================================*/
    
/* Output Pin Group 1 */
#define OUT_PIN_PPS1_RPD2        RPD2Rbits.RPD2R
#define OUT_PIN_PPS1_RPG8        RPG8Rbits.RPG8R
#define OUT_PIN_PPS1_RPF4        RPF4Rbits.RPF4R
#define OUT_PIN_PPS1_RPD10       RPD10Rbits.RPD10R
#define OUT_PIN_PPS1_RPF1        RPF1Rbits.RPF1R
#define OUT_PIN_PPS1_RPB9        RPB9Rbits.RPB9R
#define OUT_PIN_PPS1_RPB10       RPB10Rbits.RPB10R
#define OUT_PIN_PPS1_RPC14       RPC14Rbits.RPC14R
#define OUT_PIN_PPS1_RPB5        RPB5Rbits.RPB5R
#define OUT_PIN_PPS1_RPC1        RPC1Rbits.RPC1R
#define OUT_PIN_PPS1_RPD14       RPD14Rbits.RPD14R
#define OUT_PIN_PPS1_RPG1        RPG1Rbits.RPG1R
#define OUT_PIN_PPS1_RPA14       RPA14Rbits.RPA14R
#define OUT_PIN_PPS1_RPD6        RPD6Rbits.RPD6R
    
#define OUT_FN_PPS1_NULL         0  /* No Connect */
#define OUT_FN_PPS1_U3TX         1  /* RPn tied to U3TX */
#define OUT_FN_PPS1_U4RTS        2  /* RPn tied to U4RTS_BAR */
//                               3  - RESERVED
//                               4  - RESERVED
#define OUT_FN_PPS1_SDO1         5  /* RPn tied to SDO1 */
#define OUT_FN_PPS1_SDO2         6  /* RPn tied to SDO2 */
#define OUT_FN_PPS1_SDO3         7  /* RPn tied to SDO3 */
//                               8  - RESERVED
#define OUT_FN_PPS1_SDO5         9  /* RPn tied to SDO5 */
#define OUT_FN_PPS1_SS6          10 /* RPn tied to SS6 */
#define OUT_FN_PPS1_OC3          11 /* RPn tied to OC3 */
#define OUT_FN_PPS1_OC6          12 /* RPn tied to OC6 */
#define OUT_FN_PPS1_REFCLKO4     13 /* RPn tied to REFCLKO4 */
#define OUT_FN_PPS1_C2OUT        14 /* RPn tied to C2OUT */
#define OUT_FN_PPS1_C1TX         15 /* RPn tied to C1TX */

/* Output Pin Group 2 */
#define OUT_PIN_PPS2_RPD3        RPD3Rbits.RPD3R
#define OUT_PIN_PPS2_RPG7        RPG7Rbits.RPG7R
#define OUT_PIN_PPS2_RPF5        RPF5Rbits.RPF5R
#define OUT_PIN_PPS2_RPD11       RPD11Rbits.RPD11R
#define OUT_PIN_PPS2_RPF0        RPF0Rbits.RPF0R
#define OUT_PIN_PPS2_RPB1        RPB1Rbits.RPB1R
#define OUT_PIN_PPS2_RPE5        RPE5Rbits.RPE5R
#define OUT_PIN_PPS2_RPC13       RPC13Rbits.RPC13R
#define OUT_PIN_PPS2_RPB3        RPB3Rbits.RPB3R
#define OUT_PIN_PPS2_RPC4        RPC4Rbits.RPC4R
#define OUT_PIN_PPS2_RPD15       RPD15Rbits.RPD15R
#define OUT_PIN_PPS2_RPG0        RPG0Rbits.RPG0R
#define OUT_PIN_PPS2_RPA15       RPA15Rbits.RPA15R
#define OUT_PIN_PPS2_RPD7        RPD7Rbits.RPD7R

#define OUT_FN_PPS2_NULL         0  /* No Connect */
#define OUT_FN_PPS2_U1TX         1  /* RPn tied to U1TX */
#define OUT_FN_PPS2_U2RTS        2  /* RPn tied to U2RTS */
#define OUT_FN_PPS2_U5TX         3  /* RPn tied to U5TX */
#define OUT_FN_PPS2_U6RTS        4  /* RPn tied to U6RTS */
#define OUT_FN_PPS2_SDO1         5  /* RPn tied to SDO1 */
#define OUT_FN_PPS2_SDO2         6  /* RPn tied to SDO2 */
#define OUT_FN_PPS2_SDO3         7  /* RPn tied to SDO3 */
#define OUT_FN_PPS2_SDO4         8  /* RPn tied to SDO4 */
#define OUT_FN_PPS2_SDO5         9  /* RPn tied to SDO5 */
//                               10 - RESERVED
#define OUT_FN_PPS2_OC4          11 /* RPn tied to OC4 */
#define OUT_FN_PPS2_OC7          12 /* RPn tied to OC7 */
//                               13 - RESERVED
//                               14 - RESERVED
#define OUT_FN_PPS1_REFCLKO1     15 /* RPn tied to REFCLKO1 */

/* Output Pin Group 3 */
#define OUT_PIN_PPS3_RPD9        RPD9Rbits.RPD9R
#define OUT_PIN_PPS3_RPG6        RPG6Rbits.RPG6R
#define OUT_PIN_PPS3_RPB8        RPB8Rbits.RPB8R
#define OUT_PIN_PPS3_RPB15       RPB15Rbits.RPB15R
#define OUT_PIN_PPS3_RPD4        RPD4Rbits.RPD4R
#define OUT_PIN_PPS3_RPB0        RPB0Rbits.RPB0R
#define OUT_PIN_PPS3_RPE3        RPE3Rbits.RPE3R
#define OUT_PIN_PPS3_RPB7        RPB7Rbits.RPB7R
#define OUT_PIN_PPS3_RPB2        RPB2Rbits.RPB2R
#define OUT_PIN_PPS3_RPF12       RPF12Rbits.RPF12R
#define OUT_PIN_PPS3_RPD12       RPD12Rbits.RPD12R
#define OUT_PIN_PPS3_RPF8        RPF8Rbits.RPF8R
#define OUT_PIN_PPS3_RPC3        RPC3Rbits.RPC3R
#define OUT_PIN_PPS3_RPE9        RPE9Rbits.RPE9R

#define OUT_FN_PPS3_NULL         0  /* No Connect */
#define OUT_FN_PPS3_U3RTS        1  /* RPn tied to U3RTS */
#define OUT_FN_PPS3_U4TX         2  /* RPn tied to U4TX */
//                               3  - RESERVED
#define OUT_FN_PPS3_U6TX         4  /* RPn tied to U6TX */
#define OUT_FN_PPS3_SS1          5  /* RPn tied to SS1 */
//                               6  - RESERVED
#define OUT_FN_PPS3_SS3          7  /* RPn tied to SS3 */
#define OUT_FN_PPS3_SS4          8  /* RPn tied to SS4 */
#define OUT_FN_PPS3_SS5          9  /* RPn tied to SS5 */
#define OUT_FN_PPS3_SDO6         10 /* RPn tied to SDO6 */
#define OUT_FN_PPS3_OC5          11 /* RPn tied to OC5 */
#define OUT_FN_PPS3_OC8          12 /* RPn tied to OC8 */
//                               13 - RESERVED
#define OUT_FN_PPS3_C1OUT        14 /* RPn tied to C1OUT */
#define OUT_FN_PPS3_REFCLKO3     15 /* RPn tied to REFCLKO3 */

/* Output Pin Group 4 */
#define OUT_PIN_PPS4_RPD1        RPD1Rbits.RPD1R
#define OUT_PIN_PPS4_RPG9        RPG9Rbits.RPG9R
#define OUT_PIN_PPS4_RPB14       RPB14Rbits.RPB14R
#define OUT_PIN_PPS4_RPD0        RPD0Rbits.RPD0R
#define OUT_PIN_PPS4_RPB6        RPB6Rbits.RPB6R
#define OUT_PIN_PPS4_RPD5        RPD5Rbits.RPD5R
#define OUT_PIN_PPS4_RPB2        RPB2Rbits.RPB2R
#define OUT_PIN_PPS4_RPF3        RPF3Rbits.RPF3R
#define OUT_PIN_PPS4_RPF13       RPF13Rbits.RPF13R
#define OUT_PIN_PPS4_RPC2        RPC2Rbits.RPC2R
#define OUT_PIN_PPS4_RPE8        RPE8Rbits.RPE8R
#define OUT_PIN_PPS4_RPF2        RPF2Rbits.RPF2R
    
#define OUT_FN_PPS4_NULL         0  /* No Connect */
#define OUT_FN_PPS4_U1RTS        1  /* RPn tied to U1RTS */
#define OUT_FN_PPS4_U2TX         2  /* RPn tied to U2TX */
#define OUT_FN_PPS4_U5RTS        3  /* RPn tied to U5RTS */
#define OUT_FN_PPS4_U6TX         4  /* RPn tied to U6TX */
//                               5  - RESERVED
#define OUT_FN_PPS4_SS2          6  /* RPn tied to SS2_BAR */
//                               7  - RESERVED
#define OUT_FN_PPS4_SDO4         8  /* RPn tied to SDO4 */
//                               9  - RESERVED
#define OUT_FN_PPS4_SDO6         10 /* RPn tied to SDO6 */
#define OUT_FN_PPS4_OC2          11 /* RPn tied to OC2 */
#define OUT_FN_PPS4_OC1          12 /* RPn tied to OC1 */
#define OUT_FN_PPS4_OC9          13 /* RPn tied to OC1 */
//                               14 - RESERVED
#define OUT_FN_PPS4_C2TX         15 /* RPn tied to C2TX */   


 /*********************************************************************
  Macro:            PPSOutput(grp,pin,fn)

  PreCondition:     None

  Side Effects:     None

  Overview:          The macro assigns given pin as output pin by configuring register RPORx.

  Parameters:
            grp - the group number that the peripheral or pin function

            pin - pin number(x) for which functionality has to be assigned
            *   RPx

            fn - function to be assigned for particular pin
            *   NULL
            *   CxOUT
            *   UxTX
            *   UxRTS
            *   SDOx
            *   SCKxOUT
            *   SSxOUT
            *   OCx
            *   CTMU

  Returns:      None

  Note:             None
 ********************************************************************/
#define PPSOutput(grp,pin,fn)   OUT_PIN_PPS##grp##_##pin = OUT_FN_PPS##grp##_##fn
/*----------------------------------------------------------------------------------------------------*/

 /*********************************************************************
  Macro:            PPSUnLock
  PreCondition:     The System must be unlocked
  Side Effects:     None
  Overview:          The macro performs the unlocking sequence for PPS assignment.
  Parameters:   None
  Returns:      None
  Note:             None
 ********************************************************************/
#define  PPSUnLock                  CFGCONbits.IOLOCK = 0;

 /*********************************************************************
  Macro:            PPSLock
  PreCondition:     The System must be unlocked
  Side Effects:     None
  Overview:          The macro performs the locking sequence for PPS assignment.
  Parameters:   None
  Returns:      None
 Note:              None
 ********************************************************************/
#define  PPSLock                    CFGCONbits.IOLOCK = 1;    


#ifdef	__cplusplus
}
#endif

#endif	/* PPS_H */

