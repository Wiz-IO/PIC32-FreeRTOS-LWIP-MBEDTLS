/*
		FileName: ports.h
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

#ifndef PORTS_H
#define	PORTS_H

#include <xc.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

/******************************************************************************
 * Parameter values to be used with ConfigINTx() & SetPriorityINTx()
 *****************************************************************************/
// Interrupt enable/disable values
#define EXT_INT_ENABLE          (1 << 15)
#define EXT_INT_DISABLE         (0)         /* Default */

// Interrupt edge modes - must be any one value only
#define RISING_EDGE_INT         (1 << 3)
#define FALLING_EDGE_INT        (0)         /* Default */

// Priority values - must be any one value only
#define EXT_INT_PRI_7         (7) //Priority 7
#define EXT_INT_PRI_6         (6) //Priority 6
#define EXT_INT_PRI_5         (5) //Priority 5
#define EXT_INT_PRI_4         (4) //Priority 4
#define EXT_INT_PRI_3         (3) //Priority 3
#define EXT_INT_PRI_2         (2) //Priority 2
#define EXT_INT_PRI_1         (1) //Priority 1
#define EXT_INT_PRI_0         (0) //Priority Default    
    
/******************************************************************************
 * <combinewith ConfigINT1, ConfigINT2, ConfigINT3, ConfigINT4>
 *
 * External INTx Control Function
 *
 * Function:        void ConfigINTx(unsigned int config)
 *
 * Description:     This macro configures an external interrupt as follows:
 *                  1. clears the INTx interrupt flag
 *                  2. sets the INTx priority
 *                  3. sets the INTx edge selection (rising or falling)
 *                  4. enables the INTx interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigINT0(EXT_INT_PRI_1 | RISING_EDGE_INT | EXT_INT_ENABLE)
 *
 *****************************************************************************/
#define ConfigINT0(config)  (mINT0ClearIntFlag(), mINT0SetIntPriority((config) & 7),\
        mINT0SetEdgeMode(((config) >> 3) & 1), mINT0IntEnable((config) >> 15))

#define ConfigINT1(config)  (mINT1ClearIntFlag(), mINT1SetIntPriority((config) & 7),\
        mINT1SetEdgeMode(((config) >> 3) & 1), mINT1IntEnable((config) >> 15))

#define ConfigINT2(config)  (mINT2ClearIntFlag(), mINT2SetIntPriority((config) & 7),\
        mINT2SetEdgeMode(((config) >> 3) & 1), mINT2IntEnable((config) >> 15))

#define ConfigINT3(config)  (mINT3ClearIntFlag(), mINT3SetIntPriority((config) & 7),\
        mINT3SetEdgeMode(((config) >> 3) & 1), mINT3IntEnable((config) >> 15))

#define ConfigINT4(config)  (mINT4ClearIntFlag(), mINT4SetIntPriority((config) & 7),\
        mINT4SetEdgeMode(((config) >> 3) & 1), mINT4IntEnable((config) >> 15))
    
/******************************************************************************
 * <combinewith SetPriorityInt1, SetPriorityInt2, SetPriorityInt3, SetPriorityInt4,
 * SetPriorityINT0, SetPriorityINT1, SetPriorityINT2, SetPriorityINT3, SetPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetPriorityINTx(unsigned int priority)
 *
 * Description:     This macro sets the priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: A Priority value
 *
 * Output:          None
 *
 * Example:         SetPriorityInt0(EXT_INT_PRI_5)
 *
 *****************************************************************************/
#define SetPriorityInt0             SetPriorityINT0
#define SetPriorityInt1             SetPriorityINT1
#define SetPriorityInt2             SetPriorityINT2
#define SetPriorityInt3             SetPriorityINT3
#define SetPriorityInt4             SetPriorityINT4

#define SetPriorityINT0(priority)   (mINT0SetIntPriority(priority))
#define SetPriorityINT1(priority)   (mINT1SetIntPriority(priority))
#define SetPriorityINT2(priority)   (mINT2SetIntPriority(priority))
#define SetPriorityINT3(priority)   (mINT3SetIntPriority(priority))
#define SetPriorityINT4(priority)   (mINT4SetIntPriority(priority))


/******************************************************************************
 * Sub-priority values to be used with SetSubPriorityIntx
 *****************************************************************************/
#define EXT_INT_SUB_PRI_3           (3 << 4) //sub priority 3
#define EXT_INT_SUB_PRI_2           (2 << 4) //sub priority 2
#define EXT_INT_SUB_PRI_1           (1 << 4) //sub priority 1
#define EXT_INT_SUB_PRI_0           (0 << 4) //sub priority default

/******************************************************************************
 * <combinewith SetSubPriorityINT1, SetSubPriorityINT2, SetSubPriorityINT3, SetSubPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetSubPriorityINTx(unsigned int subPriority)
 *
 * Description:     This macro sets the sub-priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          A Sub-priority value
 *
 * Output:          None
 *
 * Example:         SetSubPriorityInt0(EXT_INT_SUB_PRI_2)
 *
 *****************************************************************************/
#define SetSubPriorityINT0(subpriority) (mINT0SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT1(subpriority) (mINT1SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT2(subpriority) (mINT2SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT3(subpriority) (mINT3SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT4(subpriority) (mINT4SetIntSubPriority((subpriority) >> 4))


/******************************************************************************
 * <combinewith CloseINT1, CloseINT2, CloseINT3, CloseINT4>
 *
 * External INTx Control Function
 *
 * Function:        void CloseINTx(void)
 *
 * Description:     This macro disables the external interrupt and clears corresponding flag.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseINT0()
 *
 *****************************************************************************/
#define CloseINT0()    (mINT0IntEnable(0), mINT0ClearIntFlag())
#define CloseINT1()    (mINT1IntEnable(0), mINT1ClearIntFlag())
#define CloseINT2()    (mINT2IntEnable(0), mINT2ClearIntFlag())
#define CloseINT3()    (mINT3IntEnable(0), mINT3ClearIntFlag())
#define CloseINT4()    (mINT4IntEnable(0), mINT4ClearIntFlag())

/******************************************************************************
 * <combinewith EnableINT1, EnableINT2, EnableINT3, EnableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void EnableINTx(void)
 *
 * Description:     This macro enables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableINT4()
 *
 *****************************************************************************/
#define EnableINT0    (mINT0IntEnable(1))
#define EnableINT1    (mINT1IntEnable(1))
#define EnableINT2    (mINT2IntEnable(1))
#define EnableINT3    (mINT3IntEnable(1))
#define EnableINT4    (mINT4IntEnable(1))

/******************************************************************************
 * <combinewith DisableINT1, DisableINT2, DisableINT3, DisableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void DisableINTx(void)
 *
 * Description:     This macro disables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableINT0()
 *
 *****************************************************************************/
#define DisableINT0             (mINT0IntEnable(0))
#define DisableINT1             (mINT1IntEnable(0))
#define DisableINT2             (mINT2IntEnable(0))
#define DisableINT3             (mINT3IntEnable(0))
#define DisableINT4             (mINT4IntEnable(0))


/******************************************************************************
 * Parameter values to be used with ConfigINTCN()
 *****************************************************************************/
// Change Interrupt ON/OFF values.
#define CHANGE_INT_ON               (1 << 23)
#define CHANGE_INT_OFF              (0)             /* Default */

// Change Interrupt Priority Values
#define CHANGE_INT_PRI_7            (7) //Priority 7
#define CHANGE_INT_PRI_6            (6) //Priority 6
#define CHANGE_INT_PRI_5            (5) //Priority 5
#define CHANGE_INT_PRI_4            (4) //Priority 4
#define CHANGE_INT_PRI_3            (3) //Priority 3
#define CHANGE_INT_PRI_2            (2) //Priority 2
#define CHANGE_INT_PRI_1            (1) //Priority 1
#define CHANGE_INT_PRI_0            (0) //Priority default    


/******************************************************************************
 * Change Notice Interrupt Control Function
 *
 * Function:        void ConfigIntCN(unsigned int config)
 *
 * Description:     This macro configures Change Notice interrupts as follows
 *                  1. clears CN interrupt flag
 *                  2. sets CN interrupt priority
 *                  3. enables CN interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CHANGE_INT_PRIx and
 *                  CHANGE_INT_XXX sets
 *
 * Output:          None
 *
 * Example:         ConfigIntCN(CHANGE_INT_PRI_3 |
 *                                CHANGE_INT_ON)
 *
 *****************************************************************************/    
#ifdef _PORTA     
  #define ConfigIntCNA(config) (mCNAClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNAIntEnable(((config) >> 23)))
#endif    
  #define ConfigIntCNB(config) (mCNBClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNBIntEnable(((config) >> 23)))
  #define ConfigIntCNC(config) (mCNCClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNCIntEnable(((config) >> 23)))
  #define ConfigIntCND(config) (mCNDClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNDIntEnable(((config) >> 23)))
  #define ConfigIntCNE(config) (mCNEClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNEIntEnable(((config) >> 23)))
  #define ConfigIntCNF(config) (mCNFClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNFIntEnable(((config) >> 23)))
  #define ConfigIntCNG(config) (mCNGClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNGIntEnable(((config) >> 23))) 
#ifdef _PORTH
  #define ConfigIntCNH(config) (mCNHClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNHIntEnable(((config) >> 23)))
#endif
#ifdef _PORTJ
  #define ConfigIntCNJ(config) (mCNJClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNJIntEnable(((config) >> 23)))
#endif
#ifdef _PORTK
  #define ConfigIntCNK(config) (mCNKClearIntFlag(), mCNSetIntPriority(((config) & 7)), mCNKIntEnable(((config) >> 23)))
#endif

/******************************************************************************
 * <combinewith CN0_PULLUP_ENABLE, CN1_PULLUP_ENABLE, CN2_PULLUP_ENABLE, CN3_PULLUP_ENABLE,
 *  CN4_PULLUP_ENABLE, CN5_PULLUP_ENABLE, CN6_PULLUP_ENABLE, CN7_PULLUP_ENABLE, CN8_PULLUP_ENABLE,
 *  CN9_PULLUP_ENABLE, CN10_PULLUP_ENABLE, CN11_PULLUP_ENABLE, CN12_PULLUP_ENABLE, CN13_PULLUP_ENABLE,
 *  CN14_PULLUP_ENABLE, CN15_PULLUP_ENABLE, CN16_PULLUP_ENABLE, CN17_PULLUP_ENABLE, CN18_PULLUP_ENABLE,
 *  CN19_PULLUP_ENABLE, CN20_PULLUP_ENABLE, CN_PULLUP_DISABLE_ALL>
 *
 * Parameter values to be used with ConfigCNPullups()
 *****************************************************************************/ 

#ifdef _PORTA    
  #define CNA15_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA15_POSITION)
  #define CNA14_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA14_POSITION)
  #define CNA10_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA10_POSITION)
  #define CNA9_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA9_POSITION)
  #define CNA7_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA7_POSITION)
  #define CNA6_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA6_POSITION)
  #define CNA5_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA5_POSITION)
  #define CNA4_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA4_POSITION)
  #define CNA3_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA3_POSITION)
  #define CNA2_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA2_POSITION)
  #define CNA1_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA1_POSITION)
  #define CNA0_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA0_POSITION)
  #define CNA_PULLUP_DISABLE_ALL              (0)             /* Default */
#endif
  #define CNB15_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB15_POSITION)
  #define CNB14_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB14_POSITION)
  #define CNB13_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB13_POSITION)
  #define CNB12_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB12_POSITION)
  #define CNB11_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB11_POSITION)
  #define CNB10_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB10_POSITION)
  #define CNB9_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB9_POSITION)
  #define CNB8_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB8_POSITION)
  #define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
  #define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
  #define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
  #define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
  #define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
  #define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
  #define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
  #define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNC15_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC15_POSITION)
  #define CNC14_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC14_POSITION)
  #define CNC13_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC13_POSITION)
  #define CNC12_PULLUP_ENABLE                 (1 << _CNPUC_CNPUC12_POSITION)
  #define CNC4_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC4_POSITION)
  #define CNC3_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC3_POSITION)
  #define CNC2_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC2_POSITION)
  #define CNC1_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC1_POSITION)
  #define CNC_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CND15_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD15_POSITION)
  #define CND14_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD14_POSITION)
  #define CND13_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD13_POSITION)
  #define CND12_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD12_POSITION)
  #define CND11_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD11_POSITION)
  #define CND10_PULLUP_ENABLE                 (1 << _CNPUD_CNPUD10_POSITION)
  #define CND9_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD9_POSITION)
  #define CND7_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD7_POSITION)
  #define CND6_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD6_POSITION)
  #define CND5_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD5_POSITION)
  #define CND4_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD4_POSITION)
  #define CND3_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD3_POSITION)
  #define CND2_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD2_POSITION)
  #define CND1_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD1_POSITION)
  #define CND0_PULLUP_ENABLE                  (1 << _CNPUD_CNPUD0_POSITION)
  #define CND_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNE9_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE9_POSITION)
  #define CNE8_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE8_POSITION)
  #define CNE7_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE7_POSITION)
  #define CNE6_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE6_POSITION)
  #define CNE5_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE5_POSITION)
  #define CNE4_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE4_POSITION)
  #define CNE3_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE3_POSITION)
  #define CNE2_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE2_POSITION)
  #define CNE1_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE1_POSITION)
  #define CNE0_PULLUP_ENABLE                  (1 << _CNPUE_CNPUE0_POSITION)
  #define CNE_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNF13_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF13_POSITION)
  #define CNF12_PULLUP_ENABLE                 (1 << _CNPUF_CNPUF12_POSITION)
  #define CNF8_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF8_POSITION)
  #define CNF5_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF5_POSITION)
  #define CNF4_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF4_POSITION)
  #define CNF3_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF3_POSITION)
  #define CNF2_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF2_POSITION)
  #define CNF1_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF1_POSITION)
  #define CNF0_PULLUP_ENABLE                  (1 << _CNPUF_CNPUF0_POSITION)
  #define CNF_PULLUP_DISABLE_ALL              (0)             /* Default */

  #define CNG15_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG15_POSITION)
  #define CNG14_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG14_POSITION)
  #define CNG13_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG13_POSITION)
  #define CNG12_PULLUP_ENABLE                 (1 << _CNPUG_CNPUG12_POSITION)    
  #define CNG9_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG9_POSITION)
  #define CNG8_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG8_POSITION)
  #define CNG7_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG7_POSITION)
  #define CNG6_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG6_POSITION)
  #define CNG1_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG1_POSITION)
  #define CNG0_PULLUP_ENABLE                  (1 << _CNPUG_CNPUG0_POSITION)
  #define CNG_PULLUP_DISABLE_ALL              (0)             /* Default */    
#ifdef _PORTH
  #define CNH15_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH15_POSITION)
  #define CNH14_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH14_POSITION)
  #define CNH13_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH13_POSITION)
  #define CNH12_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH12_POSITION)
  #define CNH11_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH11_POSITION)
  #define CNH10_PULLUP_ENABLE                 (1 << _CNPUH_CNPUH10_POSITION)
  #define CNH9_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH9_POSITION)
  #define CNH8_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH8_POSITION)
  #define CNH7_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH7_POSITION)
  #define CNH6_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH6_POSITION)
  #define CNH5_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH5_POSITION)
  #define CNH4_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH4_POSITION)
  #define CNH3_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH3_POSITION)
  #define CNH2_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH2_POSITION)
  #define CNH1_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH1_POSITION)
  #define CNH0_PULLUP_ENABLE                  (1 << _CNPUH_CNPUH0_POSITION)
  #define CNH_PULLUP_DISABLE_ALL              (0)             /* Default */
#endif    
#ifdef _PORTJ
  #define CNJ15_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ15_POSITION)
  #define CNJ14_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ14_POSITION)
  #define CNJ13_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ13_POSITION)
  #define CNJ12_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ12_POSITION)
  #define CNJ11_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ11_POSITION)
  #define CNJ10_PULLUP_ENABLE                 (1 << _CNPUJ_CNPUJ10_POSITION)
  #define CNJ9_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ9_POSITION)
  #define CNJ8_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ8_POSITION)
  #define CNJ7_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ7_POSITION)
  #define CNJ6_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ6_POSITION)
  #define CNJ5_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ5_POSITION)
  #define CNJ4_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ4_POSITION)
  #define CNJ3_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ3_POSITION)
  #define CNJ2_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ2_POSITION)
  #define CNJ1_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ1_POSITION)
  #define CNJ0_PULLUP_ENABLE                  (1 << _CNPUJ_CNPUJ0_POSITION)
  #define CNJ_PULLUP_DISABLE_ALL              (0)             /* Default */
#endif     
#ifdef _PORTK
  #define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
  #define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
  #define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
  #define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
  #define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
  #define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
  #define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
  #define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
  #define CNB_PULLUP_DISABLE_ALL              (0)             /* Default */
#endif 


/******************************************************************************
 * Change Notice Pullup Enable Control Function
 *
 * Function:        void ConfigCNPullups(unsigned int config)
 *
 * Description:     Configures Change Notice pull-ups
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_PULLUP_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         To enable CN0 & CN1 pullups and disable all others
 *                  ConfigCNPullups(CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 *****************************************************************************/
#ifdef _PORTA    
  #define ConfigCNAPullups(config)     CNPUA = config
#endif
  #define ConfigCNBPullups(config)     CNPUB = config
  #define ConfigCNCPullups(config)     CNPUC = config
  #define ConfigCNDPullups(config)     CNPUD = config
  #define ConfigCNEPullups(config)     CNPUE = config
  #define ConfigCNFPullups(config)     CNPUF = config
  #define ConfigCNGPullups(config)     CNPUG = config    
#ifdef _PORTH
  #define ConfigCNHPullups(config)     CNPUH = config
#endif
#ifdef _PORTJ
  #define ConfigCNJPullups(config)     CNPUJ = config
#endif
#ifdef _PORTK
  #define ConfigCNKPullups(config)     CNPUK = config    
#endif


/******************************************************************************
 * Parameter values to be used with mCNOpen()
 *****************************************************************************/
#ifdef _PORTA    
  #define CNA_ON                           (1 << _CNCONA_ON_POSITION)     /* CN ON */
  #define CNA_OFF                          (0)  /* CN OFF */
  #define CNA_EDGEDETECT_ON                (1 << _CNCONA_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNA_EDGEDETECT_OFF               (0) /* Edge Detection OFF */
#endif
  #define CNB_ON                           (1 << _CNCONB_ON_POSITION)     /* CN ON */
  #define CNB_OFF                          (0)  /* CN OFF */
  #define CNB_EDGEDETECT_ON                (1 << _CNCONB_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNB_EDGEDETECT_OFF               (0) /* Edge Detection OFF */

  #define CNC_ON                           (1 << _CNCONC_ON_POSITION)     /* CN ON */
  #define CNC_OFF                          (0)  /* CN OFF */
  #define CNC_EDGEDETECT_ON                (1 << _CNCONC_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNC_EDGEDETECT_OFF               (0) /* Edge Detection OFF */

  #define CND_ON                           (1 << _CNCOND_ON_POSITION)     /* CN ON */
  #define CND_OFF                          (0)  /* CN OFF */
  #define CND_EDGEDETECT_ON                (1 << _CNCOND_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CND_EDGEDETECT_OFF               (0) /* Edge Detection OFF */

  #define CNE_ON                           (1 << _CNCONE_ON_POSITION)     /* CN ON */
  #define CNE_OFF                          (0)  /* CN OFF */
  #define CNE_EDGEDETECT_ON                (1 << _CNCONE_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNE_EDGEDETECT_OFF               (0) /* Edge Detection OFF */

  #define CNF_ON                           (1 << _CNCONF_ON_POSITION)     /* CN ON */
  #define CNF_OFF                          (0)  /* CN OFF */
  #define CNF_EDGEDETECT_ON                (1 << _CNCONF_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNF_EDGEDETECT_OFF               (0) /* Edge Detection OFF */

  #define CNG_ON                           (1 << _CNCONG_ON_POSITION)     /* CN ON */
  #define CNG_OFF                          (0)  /* CN OFF */
  #define CNG_EDGEDETECT_ON                (1 << _CNCONG_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNG_EDGEDETECT_OFF               (0) /* Edge Detection OFF */
#ifdef _PORTH    
  #define CNH_ON                           (1 << _CNCONH_ON_POSITION)     /* CN ON */
  #define CNH_OFF                          (0)  /* CN OFF */
  #define CNH_EDGEDETECT_ON                (1 << _CNCONH_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNH_EDGEDETECT_OFF               (0) /* Edge Detection OFF */    
#endif    
#ifdef _PORTJ    
  #define CNJ_ON                           (1 << _CNCONJ_ON_POSITION)     /* CN ON */
  #define CNJ_OFF                          (0)  /* CN OFF */
  #define CNJ_EDGEDETECT_ON                (1 << _CNCONJ_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNJ_EDGEDETECT_OFF               (0) /* Edge Detection OFF */    
#endif       
#ifdef _PORTK    
  #define CNK_ON                           (1 << _CNCONK_ON_POSITION)     /* CN ON */
  #define CNK_OFF                          (0)  /* CN OFF */
  #define CNK_EDGEDETECT_ON                (1 << _CNCONK_EDGEDETECT_POSITION)    /* Edge Detection ON */
  #define CNK_EDGEDETECT_OFF               (0) /* Edge Detection OFF */    
#endif       

/******************************************************************
 * <combinewith CN0_ENABLE, CN1_ENABLE, CN2_ENABLE, CN3_ENABLE,
 * CN4_ENABLE, CN5_ENABLE, CN6_ENABLE, CN7_ENABLE, CN8_ENABLE,
 * CN9_ENABLE, CN10_ENABLE, CN11_ENABLE, CN12_ENABLE, CN13_ENABLE,
 * CN14_ENABLE, CN15_ENABLE, CN16_ENABLE, CN17_ENABLE, CN18_ENABLE,
 * CN19_ENABLE, CN20_ENABLE, CN_DISABLE_ALL>
 *
 * Change notice enable flags
 *******************************************************************/    
    
#ifdef _PORTA
  #define CNA15_ENABLE                 (1 << _CNENA_CNIEA15_POSITION)
  #define CNA14_ENABLE                 (1 << _CNENA_CNIEA14_POSITION)
  #define CNA10_ENABLE                 (1 << _CNENA_CNIEA10_POSITION)
  #define CNA9_ENABLE                  (1 << _CNENA_CNIEA9_POSITION)
  #define CNA7_ENABLE                  (1 << _CNENA_CNIEA7_POSITION)
  #define CNA6_ENABLE                  (1 << _CNENA_CNIEA6_POSITION)
  #define CNA5_ENABLE                  (1 << _CNENA_CNIEA5_POSITION)
  #define CNA4_ENABLE                  (1 << _CNENA_CNIEA4_POSITION)
  #define CNA3_ENABLE                  (1 << _CNENA_CNIEA3_POSITION)
  #define CNA2_ENABLE                  (1 << _CNENA_CNIEA2_POSITION)
  #define CNA1_ENABLE                  (1 << _CNENA_CNIEA1_POSITION)
  #define CNA0_ENABLE                  (1 << _CNENA_CNIEA0_POSITION)
  #define CNA_DISABLE_ALL              (0)             /* Default */
#endif
  #define CNB15_ENABLE                 (1 << _CNENB_CNIEB15_POSITION)
  #define CNB14_ENABLE                 (1 << _CNENB_CNIEB14_POSITION)
  #define CNB13_ENABLE                 (1 << _CNENB_CNIEB13_POSITION)
  #define CNB12_ENABLE                 (1 << _CNENB_CNIEB12_POSITION)
  #define CNB11_ENABLE                 (1 << _CNENB_CNIEB11_POSITION)
  #define CNB10_ENABLE                 (1 << _CNENB_CNIEB10_POSITION)
  #define CNB9_ENABLE                  (1 << _CNENB_CNIEB9_POSITION)
  #define CNB8_ENABLE                  (1 << _CNENB_CNIEB8_POSITION)
  #define CNB7_ENABLE                  (1 << _CNENB_CNIEB7_POSITION)
  #define CNB6_ENABLE                  (1 << _CNENB_CNIEB6_POSITION)
  #define CNB5_ENABLE                  (1 << _CNENB_CNIEB5_POSITION)
  #define CNB4_ENABLE                  (1 << _CNENB_CNIEB4_POSITION)
  #define CNB3_ENABLE                  (1 << _CNENB_CNIEB3_POSITION)
  #define CNB2_ENABLE                  (1 << _CNENB_CNIEB2_POSITION)
  #define CNB1_ENABLE                  (1 << _CNENB_CNIEB1_POSITION)
  #define CNB0_ENABLE                  (1 << _CNENB_CNIEB0_POSITION)
  #define CNB_DISABLE_ALL              (0)             /* Default */

  #define CNC15_ENABLE                 (1 << _CNENC_CNIEC15_POSITION)
  #define CNC14_ENABLE                 (1 << _CNENC_CNIEC14_POSITION)
  #define CNC13_ENABLE                 (1 << _CNENC_CNIEC13_POSITION)
  #define CNC12_ENABLE                 (1 << _CNENC_CNIEC12_POSITION)
  #define CNC4_ENABLE                  (1 << _CNENC_CNIEC4_POSITION)
  #define CNC3_ENABLE                  (1 << _CNENC_CNIEC3_POSITION)
  #define CNC2_ENABLE                  (1 << _CNENC_CNIEC2_POSITION)
  #define CNC1_ENABLE                  (1 << _CNENC_CNIEC1_POSITION)
  #define CNC_DISABLE_ALL              (0)             /* Default */

  #define CND15_ENABLE                 (1 << _CNEND_CNIED15_POSITION)
  #define CND14_ENABLE                 (1 << _CNEND_CNIED14_POSITION)
  #define CND13_ENABLE                 (1 << _CNEND_CNIED13_POSITION)
  #define CND12_ENABLE                 (1 << _CNEND_CNIED12_POSITION)
  #define CND11_ENABLE                 (1 << _CNEND_CNIED11_POSITION)
  #define CND10_ENABLE                 (1 << _CNEND_CNIED10_POSITION)
  #define CND9_ENABLE                  (1 << _CNEND_CNIED9_POSITION)
  #define CND7_ENABLE                  (1 << _CNEND_CNIED7_POSITION)
  #define CND6_ENABLE                  (1 << _CNEND_CNIED6_POSITION)
  #define CND5_ENABLE                  (1 << _CNEND_CNIED5_POSITION)
  #define CND4_ENABLE                  (1 << _CNEND_CNIED4_POSITION)
  #define CND3_ENABLE                  (1 << _CNEND_CNIED3_POSITION)
  #define CND2_ENABLE                  (1 << _CNEND_CNIED2_POSITION)
  #define CND1_ENABLE                  (1 << _CNEND_CNIED1_POSITION)
  #define CND0_ENABLE                  (1 << _CNEND_CNIED0_POSITION)
  #define CND_DISABLE_ALL              (0)             /* Default */

  #define CNE9_ENABLE                  (1 << _CNENE_CNIEE9_POSITION)
  #define CNE8_ENABLE                  (1 << _CNENE_CNIEE8_POSITION)
  #define CNE7_ENABLE                  (1 << _CNENE_CNIEE7_POSITION)
  #define CNE6_ENABLE                  (1 << _CNENE_CNIEE6_POSITION)
  #define CNE5_ENABLE                  (1 << _CNENE_CNIEE5_POSITION)
  #define CNE4_ENABLE                  (1 << _CNENE_CNIEE4_POSITION)
  #define CNE3_ENABLE                  (1 << _CNENE_CNIEE3_POSITION)
  #define CNE2_ENABLE                  (1 << _CNENE_CNIEE2_POSITION)
  #define CNE1_ENABLE                  (1 << _CNENE_CNIEE1_POSITION)
  #define CNE0_ENABLE                  (1 << _CNENE_CNIEE0_POSITION)
  #define CNE_DISABLE_ALL              (0)             /* Default */

  #define CNF13_ENABLE                 (1 << _CNENF_CNIEF13_POSITION)
  #define CNF12_ENABLE                 (1 << _CNENF_CNIEF12_POSITION)
  #define CNF8_ENABLE                  (1 << _CNENF_CNIEF8_POSITION)
  #define CNF5_ENABLE                  (1 << _CNENF_CNIEF5_POSITION)
  #define CNF4_ENABLE                  (1 << _CNENF_CNIEF4_POSITION)
  #define CNF3_ENABLE                  (1 << _CNENF_CNIEF3_POSITION)
  #define CNF2_ENABLE                  (1 << _CNENF_CNIEF2_POSITION)
  #define CNF1_ENABLE                  (1 << _CNENF_CNIEF1_POSITION)
  #define CNF0_ENABLE                  (1 << _CNENF_CNIEF0_POSITION)
  #define CNF_DISABLE_ALL              (0)             /* Default */

  #define CNG15_ENABLE                 (1 << _CNENG_CNIEG15_POSITION)
  #define CNG14_ENABLE                 (1 << _CNENG_CNIEG14_POSITION)
  #define CNG13_ENABLE                 (1 << _CNENG_CNIEG13_POSITION)
  #define CNG12_ENABLE                 (1 << _CNENG_CNIEG12_POSITION)
  #define CNG9_ENABLE                  (1 << _CNENG_CNIEG9_POSITION)
  #define CNG8_ENABLE                  (1 << _CNENG_CNIEG8_POSITION)
  #define CNG7_ENABLE                  (1 << _CNENG_CNIEG7_POSITION)
  #define CNG6_ENABLE                  (1 << _CNENG_CNIEG6_POSITION)
  #define CNG1_ENABLE                  (1 << _CNENG_CNIEG1_POSITION)
  #define CNG0_ENABLE                  (1 << _CNENG_CNIEG0_POSITION)
  #define CNG_DISABLE_ALL              (0)             /* Default */
#ifdef _PORTH
  #define CNH15_ENABLE                 (1 << _CNENH_CNIEH15_POSITION)
  #define CNH14_ENABLE                 (1 << _CNENH_CNIEH14_POSITION)
  #define CNH13_ENABLE                 (1 << _CNENH_CNIEH13_POSITION)
  #define CNH12_ENABLE                 (1 << _CNENH_CNIEH12_POSITION)
  #define CNH11_ENABLE                 (1 << _CNENH_CNIEH11_POSITION)
  #define CNH10_ENABLE                 (1 << _CNENH_CNIEH10_POSITION)
  #define CNH9_ENABLE                  (1 << _CNENH_CNIEH9_POSITION)
  #define CNH8_ENABLE                  (1 << _CNENH_CNIEH8_POSITION)
  #define CNH7_ENABLE                  (1 << _CNENH_CNIEH7_POSITION)
  #define CNH6_ENABLE                  (1 << _CNENH_CNIEH6_POSITION)
  #define CNH5_ENABLE                  (1 << _CNENH_CNIEH5_POSITION)
  #define CNH4_ENABLE                  (1 << _CNENH_CNIEH4_POSITION)
  #define CNH3_ENABLE                  (1 << _CNENH_CNIEH3_POSITION)
  #define CNH2_ENABLE                  (1 << _CNENH_CNIEH2_POSITION)
  #define CNH1_ENABLE                  (1 << _CNENH_CNIEH1_POSITION)
  #define CNH0_ENABLE                  (1 << _CNENH_CNIEH0_POSITION)
  #define CNH_DISABLE_ALL              (0)             /* Default */
#endif    
#ifdef _PORTJ
  #define CNJ15_ENABLE                 (1 << _CNENJ_CNIEJ15_POSITION)
  #define CNJ14_ENABLE                 (1 << _CNENJ_CNIEJ14_POSITION)
  #define CNJ13_ENABLE                 (1 << _CNENJ_CNIEJ13_POSITION)
  #define CNJ12_ENABLE                 (1 << _CNENJ_CNIEJ12_POSITION)
  #define CNJ11_ENABLE                 (1 << _CNENJ_CNIEJ11_POSITION)
  #define CNJ10_ENABLE                 (1 << _CNENJ_CNIEJ10_POSITION)
  #define CNJ9_ENABLE                  (1 << _CNENJ_CNIEJ9_POSITION)
  #define CNJ8_ENABLE                  (1 << _CNENJ_CNIEJ8_POSITION)
  #define CNJ7_ENABLE                  (1 << _CNENJ_CNIEJ7_POSITION)
  #define CNJ6_ENABLE                  (1 << _CNENJ_CNIEJ6_POSITION)
  #define CNJ5_ENABLE                  (1 << _CNENJ_CNIEJ5_POSITION)
  #define CNJ4_ENABLE                  (1 << _CNENJ_CNIEJ4_POSITION)
  #define CNJ3_ENABLE                  (1 << _CNENJ_CNIEJ3_POSITION)
  #define CNJ2_ENABLE                  (1 << _CNENJ_CNIEJ2_POSITION)
  #define CNJ1_ENABLE                  (1 << _CNENJ_CNIEJ1_POSITION)
  #define CNJ0_ENABLE                  (1 << _CNENJ_CNIEJ0_POSITION)
  #define CNJ_DISABLE_ALL              (0)             /* Default */
#endif   
#ifdef _PORTK
  #define CNK7_ENABLE                  (1 << _CNENK_CNIEK7_POSITION)
  #define CNK6_ENABLE                  (1 << _CNENK_CNIEK6_POSITION)
  #define CNK5_ENABLE                  (1 << _CNENK_CNIEK5_POSITION)
  #define CNK4_ENABLE                  (1 << _CNENK_CNIEK4_POSITION)
  #define CNK3_ENABLE                  (1 << _CNENK_CNIEK3_POSITION)
  #define CNK2_ENABLE                  (1 << _CNENK_CNIEK2_POSITION)
  #define CNK1_ENABLE                  (1 << _CNENK_CNIEK1_POSITION)
  #define CNK0_ENABLE                  (1 << _CNENK_CNIEK0_POSITION)
  #define CNK_DISABLE_ALL              (0)             /* Default */
#endif       
    

/******************************************************************************
 * Change Notice Open Control Function
 *
 * Function:        void mCNOpen(unsigned int control, unsigned int pins, unsigned int pullup)
 *
 * Description:     Configures Change Notice interrupt, enables specified
 *                  change notice inputs and pullups and configures the CNCON register.
 *                  Attention: This function does not enable the CN interrupt nor its priorities.
 *                  The user should use macro ConfigIntCN to enable the CN interrupt and set the
 *                  desired priorities only after reading the corresponding ports.
 *                  See Notes below.
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
* Example:          Enable the change notice module, select pins CN0 & CN1 and enable
 *                  corresponding weak pull-ups.
 *                  mCNOpen(CN_ON | CN_IDLE_CON, CN0_ENABLE | CN1_ENABLE,
 *                  CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 * Notes:           It is recommended to disable vector interrupts prior to configuring
 *                  the change notice module and to use the following sequence to
 *                  prevent spurious change notice interrupts during configuration:
 *
 *                  1. setup the change notice module, pins and optional pullups
 *                  mCNOpen(control, pins, pullups).
 *
 *                  2. read every port that has a corresponding enabled change notice pins
 *                  var = mPORTARead;
 *                  var = PORTBRead;
 *                  ...
 *
 *                  3. setup the change notice interrupts
 *                  ConfigIntCN(interrupt).
 *
 *****************************************************************************/
#ifdef _PORTA
  #define mCNAOpen(configA, pinsA, pullupsA)\
          (CNCONACLR = 0xFFFF, CNCONASET = ((configA) | CNA_ON), CNENA = (pinsA), CNPUA = (pullupsA))
#endif
  #define mCNBOpen(configB, pinsB, pullupsB)\
          (CNCONBCLR = 0xFFFF, CNCONBSET = ((configB) | CNB_ON), CNENB = (pinsB), CNPUB = (pullupsB))
  #define mCNCOpen(configC, pinsC, pullupsC)\
          (CNCONCCLR = 0xFFFF, CNCONCSET = ((configC) | CNC_ON), CNENC = (pinsC), CNPUC = (pullupsC))
  #define mCNDOpen(configD, pinsD, pullupsD)\
          (CNCONDCLR = 0xFFFF, CNCONDSET = ((configD) | CND_ON), CNEND = (pinsD), CNPUD = (pullupsD))
  #define mCNEOpen(configE, pinsE, pullupsE)\
          (CNCONECLR = 0xFFFF, CNCONESET = ((configE) | CNE_ON), CNENE = (pinsE), CNPUE = (pullupsE))
  #define mCNFOpen(configF, pinsF, pullupsF)\
          (CNCONFCLR = 0xFFFF, CNCONFSET = ((configF) | CNF_ON), CNENF = (pinsF), CNPUF = (pullupsF))
  #define mCNGOpen(configG, pinsG, pullupsG)\
          (CNCONGCLR = 0xFFFF, CNCONGSET = ((configG) | CNG_ON), CNENG = (pinsG), CNPUG = (pullupsG))
#ifdef _PORTH
  #define mCNHOpen(configH, pinsH, pullupsH)\
          (CNCONHCLR = 0xFFFF, CNCONHSET = ((configH) | CNG_ON), CNENH = (pinsH), CNPUH = (pullupsH))
#endif
#ifdef _PORTJ
  #define mCNJOpen(configJ, pinsJ, pullupsJ)\
          (CNCONJCLR = 0xFFFF, CNCONJSET = ((configJ) | CNG_ON), CNENJ = (pinsJ), CNPUJ = (pullupsJ))
#endif
#ifdef _PORTK
  #define mCNKOpen(configK, pinsK, pullupsK)\
          (CNCONKCLR = 0xFFFF, CNCONKSET = ((configK) | CNG_ON), CNENK = (pinsK), CNPUK = (pullupsK))
#endif    
    
    
/******************************************************************************
 * Change Notice Close Control Function
 *
 * Function:        void mCNClose(void)
 *
 * Description:     Disables Change Notice interrupt, disables all
 *                  change notice inputs and pullups
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         mCNClose();
 *
 *****************************************************************************/
#ifdef _PORTA
  #define mCNAClose() (mCNAClearIntFlag(), mCNAIntEnable(0), CNCONACLR = (1 << 15), CNENA = 0, CNPUA = 0)
#endif
  #define mCNBClose() (mCNBClearIntFlag(), mCNBIntEnable(0), CNCONBCLR = (1 << 15), CNENB = 0, CNPUB = 0)
  #define mCNCClose() (mCNCClearIntFlag(), mCNCIntEnable(0), CNCONCCLR = (1 << 15), CNENC = 0, CNPUC = 0)
  #define mCNDClose() (mCNDClearIntFlag(), mCNDIntEnable(0), CNCONDCLR = (1 << 15), CNEND = 0, CNPUD = 0)
  #define mCNEClose() (mCNEClearIntFlag(), mCNEIntEnable(0), CNCONECLR = (1 << 15), CNENE = 0, CNPUE = 0)
  #define mCNFClose() (mCNFClearIntFlag(), mCNFIntEnable(0), CNCONFCLR = (1 << 15), CNENF = 0, CNPUF = 0)
  #define mCNGClose() (mCNGClearIntFlag(), mCNGIntEnable(0), CNCONGCLR = (1 << 15), CNENG = 0, CNPUG = 0)
#ifdef _PORTH
  #define mCNHClose() (mCNHClearIntFlag(), mCNHIntEnable(0), CNCONHCLR = (1 << 15), CNENH = 0, CNPUH = 0)
#endif
#ifdef _PORTJ
  #define mCNJClose() (mCNJClearIntFlag(), mCNJIntEnable(0), CNCONJCLR = (1 << 15), CNENJ = 0, CNPUJ = 0)
#endif
#ifdef _PORTK
  #define mCNKClose() (mCNKClearIntFlag(), mCNKIntEnable(0), CNCONKCLR = (1 << 15), CNENK = 0, CNPUK = 0)
#endif


/******************************************************************************
 * Change Notice Enable Interrupt Control Function
 *
 * Function:        void mCNEnable(void)
 *
 * Description:     Enables/Disables Change Notice Interrupt
 *
 * PreCondition:    Assumes Change Notice interrupt priorities have already been
 *                  set as well as the individual CN inputs
 *
 * Inputs:          CHANGE_INT_ON, CHANGE_INT_OFF
 *
 * Output:          None
 *
 * Example:         mCNEnable(CHANGE_INT_ON);
 *
 *****************************************************************************/
#ifdef _PORTA    
  #define mCNAEnable(config) (mCNAIntEnable((config) >> 23))
#endif
  #define mCNBEnable(config) (mCNBIntEnable((config) >> 23))
  #define mCNCEnable(config) (mCNCIntEnable((config) >> 23))
  #define mCNDEnable(config) (mCNDIntEnable((config) >> 23))
  #define mCNEEnable(config) (mCNEIntEnable((config) >> 23))
  #define mCNFEnable(config) (mCNFIntEnable((config) >> 23))
  #define mCNGEnable(config) (mCNGIntEnable((config) >> 23))    
#ifdef _PORTH
  #define mCNHEnable(config) (mCNHIntEnable((config) >> 23))
#endif    
#ifdef _PORTJ
  #define mCNJEnable(config) (mCNJIntEnable((config) >> 23))
#endif      
#ifdef _PORTK
  #define mCNKEnable(config) (mCNKIntEnable((config) >> 23))
#endif      
    

/******************************************************************************
 * <combinewith EnableCN0, EnableCN1, EnableCN2, EnableCN3, EnableCN4, EnableCN5,
 * EnableCN6, EnableCN7, EnableCN8, EnableCN9, EnableCN10, EnableCN11, EnableCN12, EnableCN13,
 * EnableCN14, EnableCN15, EnableCN16, EnableCN17, EnableCN18, EnableCN19, EnableCN20>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void EnableCNx(void)
 *
 * Description:     Enables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableCN0()
 *
 *****************************************************************************/
#ifdef _PORTA    
  #define EnableCNA15                (CNENASET =  CNA15_ENABLE)
  #define EnableCNA14                (CNENASET =  CNA14_ENABLE)
  #define EnableCNA10                (CNENASET =  CNA10_ENABLE)
  #define EnableCNA9                 (CNENASET =   CNA9_ENABLE)
  #define EnableCNA7                 (CNENASET =   CNA7_ENABLE)
  #define EnableCNA6                 (CNENASET =   CNA6_ENABLE)
  #define EnableCNA5                 (CNENASET =   CNA5_ENABLE)
  #define EnableCNA4                 (CNENASET =   CNA4_ENABLE)
  #define EnableCNA3                 (CNENASET =   CNA3_ENABLE)
  #define EnableCNA2                 (CNENASET =   CNA2_ENABLE)
  #define EnableCNA1                 (CNENASET =   CNA1_ENABLE)
  #define EnableCNA0                 (CNENASET =   CNA0_ENABLE)
#endif
  #define EnableCNB15                (CNENBSET =  CNB15_ENABLE)
  #define EnableCNB14                (CNENBSET =  CNB14_ENABLE)
  #define EnableCNB13                (CNENBSET =  CNB13_ENABLE)
  #define EnableCNB12                (CNENBSET =  CNB12_ENABLE)
  #define EnableCNB11                (CNENBSET =  CNB11_ENABLE)
  #define EnableCNB10                (CNENBSET =  CNB10_ENABLE)
  #define EnableCNB9                 (CNENBSET =   CNB9_ENABLE)
  #define EnableCNB8                 (CNENBSET =   CNB8_ENABLE)
  #define EnableCNB7                 (CNENBSET =   CNB7_ENABLE)
  #define EnableCNB6                 (CNENBSET =   CNB6_ENABLE)
  #define EnableCNB5                 (CNENBSET =   CNB5_ENABLE)
  #define EnableCNB4                 (CNENBSET =   CNB4_ENABLE)
  #define EnableCNB3                 (CNENBSET =   CNB3_ENABLE)
  #define EnableCNB2                 (CNENBSET =   CNB2_ENABLE)
  #define EnableCNB1                 (CNENBSET =   CNB1_ENABLE)
  #define EnableCNB0                 (CNENBSET =   CNB0_ENABLE)

  #define EnableCNC15                (CNENCSET =  CNC15_ENABLE)
  #define EnableCNC14                (CNENCSET =  CNC14_ENABLE)
  #define EnableCNC13                (CNENCSET =  CNC13_ENABLE)
  #define EnableCNC12                (CNENCSET =  CNC12_ENABLE)
  #define EnableCNC4                 (CNENCSET =   CNC4_ENABLE)
  #define EnableCNC3                 (CNENCSET =   CNC3_ENABLE)
  #define EnableCNC2                 (CNENCSET =   CNC2_ENABLE)
  #define EnableCNC1                 (CNENCSET =   CNC1_ENABLE)

  #define EnableCND15                (CNENDSET =  CND15_ENABLE)
  #define EnableCND14                (CNENDSET =  CND14_ENABLE)
  #define EnableCND13                (CNENDSET =  CND13_ENABLE)
  #define EnableCND12                (CNENDSET =  CND12_ENABLE)
  #define EnableCND11                (CNENDSET =  CND11_ENABLE)
  #define EnableCND10                (CNENDSET =  CND10_ENABLE)
  #define EnableCND9                 (CNENDSET =   CND9_ENABLE)
  #define EnableCND7                 (CNENDSET =   CND7_ENABLE)
  #define EnableCND6                 (CNENDSET =   CND6_ENABLE)
  #define EnableCND5                 (CNENDSET =   CND5_ENABLE)
  #define EnableCND4                 (CNENDSET =   CND4_ENABLE)
  #define EnableCND3                 (CNENDSET =   CND3_ENABLE)
  #define EnableCND2                 (CNENDSET =   CND2_ENABLE)
  #define EnableCND1                 (CNENDSET =   CND1_ENABLE)
  #define EnableCND0                 (CNENDSET =   CND0_ENABLE)

  #define EnableCNE9                 (CNENESET =   CNE9_ENABLE)
  #define EnableCNE8                 (CNENESET =   CNE8_ENABLE)
  #define EnableCNE7                 (CNENESET =   CNE7_ENABLE)
  #define EnableCNE6                 (CNENESET =   CNE6_ENABLE)
  #define EnableCNE5                 (CNENESET =   CNE5_ENABLE)
  #define EnableCNE4                 (CNENESET =   CNE4_ENABLE)
  #define EnableCNE3                 (CNENESET =   CNE3_ENABLE)
  #define EnableCNE2                 (CNENESET =   CNE2_ENABLE)
  #define EnableCNE1                 (CNENESET =   CNE1_ENABLE)
  #define EnableCNE0                 (CNENESET =   CNE0_ENABLE)

  #define EnableCNF13                (CNENFSET =  CNF13_ENABLE)
  #define EnableCNF12                (CNENFSET =  CNF12_ENABLE)
  #define EnableCNF8                 (CNENFSET =   CNF8_ENABLE)
  #define EnableCNF5                 (CNENFSET =   CNF5_ENABLE)
  #define EnableCNF4                 (CNENFSET =   CNF4_ENABLE)
  #define EnableCNF3                 (CNENFSET =   CNF3_ENABLE)
  #define EnableCNF2                 (CNENFSET =   CNF2_ENABLE)
  #define EnableCNF1                 (CNENFSET =   CNF1_ENABLE)
  #define EnableCNF0                 (CNENFSET =   CNF0_ENABLE)

  #define EnableCNG15                (CNENGSET =  CNG15_ENABLE)
  #define EnableCNG14                (CNENGSET =  CNG14_ENABLE)
  #define EnableCNG13                (CNENGSET =  CNG13_ENABLE)
  #define EnableCNG12                (CNENGSET =  CNG12_ENABLE)
  #define EnableCNG9                 (CNENGSET =   CNG9_ENABLE)
  #define EnableCNG8                 (CNENGSET =   CNG8_ENABLE)
  #define EnableCNG7                 (CNENGSET =   CNG7_ENABLE)
  #define EnableCNG6                 (CNENGSET =   CNG6_ENABLE)
  #define EnableCNG1                 (CNENGSET =   CNG1_ENABLE)
  #define EnableCNG0                 (CNENGSET =   CNG0_ENABLE)    
#ifdef _PORTH
  #define EnableCNH15                (CNENHSET =  CNH15_ENABLE)
  #define EnableCNH14                (CNENHSET =  CNH14_ENABLE)
  #define EnableCNH13                (CNENHSET =  CNH13_ENABLE)
  #define EnableCNH12                (CNENHSET =  CNH12_ENABLE)
  #define EnableCNH11                (CNENHSET =  CNH11_ENABLE)
  #define EnableCNH10                (CNENHSET =  CNH10_ENABLE)
  #define EnableCNH9                 (CNENHSET =   CNH9_ENABLE)
  #define EnableCNH8                 (CNENHSET =   CNH8_ENABLE)
  #define EnableCNH7                 (CNENHSET =   CNH7_ENABLE)
  #define EnableCNH6                 (CNENHSET =   CNH6_ENABLE)
  #define EnableCNH5                 (CNENHSET =   CNH5_ENABLE)
  #define EnableCNH4                 (CNENHSET =   CNH4_ENABLE)
  #define EnableCNH3                 (CNENHSET =   CNH3_ENABLE)
  #define EnableCNH2                 (CNENHSET =   CNH2_ENABLE)
  #define EnableCNH1                 (CNENHSET =   CNH1_ENABLE)
  #define EnableCNH0                 (CNENHSET =   CNH0_ENABLE)
#endif    
#ifdef _PORTJ
  #define EnableCNJ15                (CNENJSET =  CNJ15_ENABLE)
  #define EnableCNJ14                (CNENJSET =  CNJ14_ENABLE)
  #define EnableCNJ13                (CNENJSET =  CNJ13_ENABLE)
  #define EnableCNJ12                (CNENJSET =  CNJ12_ENABLE)
  #define EnableCNJ11                (CNENJSET =  CNJ11_ENABLE)
  #define EnableCNJ10                (CNENJSET =  CNJ10_ENABLE)
  #define EnableCNJ9                 (CNENJSET =   CNJ9_ENABLE)
  #define EnableCNJ8                 (CNENJSET =   CNJ8_ENABLE)
  #define EnableCNJ7                 (CNENJSET =   CNJ7_ENABLE)
  #define EnableCNJ6                 (CNENJSET =   CNJ6_ENABLE)
  #define EnableCNJ5                 (CNENJSET =   CNJ5_ENABLE)
  #define EnableCNJ4                 (CNENJSET =   CNJ4_ENABLE)
  #define EnableCNJ3                 (CNENJSET =   CNJ3_ENABLE)
  #define EnableCNJ2                 (CNENJSET =   CNJ2_ENABLE)
  #define EnableCNJ1                 (CNENJSET =   CNJ1_ENABLE)
  #define EnableCNJ0                 (CNENJSET =   CNJ0_ENABLE)
#endif       
#ifdef _PORTK
  #define EnableCNK7                 (CNENKSET =   CNK7_ENABLE)
  #define EnableCNK6                 (CNENKSET =   CNK6_ENABLE)
  #define EnableCNK5                 (CNENKSET =   CNK5_ENABLE)
  #define EnableCNK4                 (CNENKSET =   CNK4_ENABLE)
  #define EnableCNK3                 (CNENKSET =   CNK3_ENABLE)
  #define EnableCNK2                 (CNENKSET =   CNK2_ENABLE)
  #define EnableCNK1                 (CNENKSET =   CNK1_ENABLE)
  #define EnableCNK0                 (CNENKSET =   CNK0_ENABLE)
#endif       
    

/******************************************************************************
 * <combinewith DisableCN0, DisableCN1, DisableCN2, DisableCN3, DisableCN4, DisableCN5,
 * DisableCN6, DisableCN7, DisableCN8, DisableCN9, DisableCN10, DisableCN11, DisableCN12,
 * DisableCN13, DisableCN14, DisableCN15, DisableCN16, DisableCN17, DisableCN18, DisableCN19,
 * DisableCN20, DisableCN_ALL>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void DisableCNx(void)
 *
 * Description:     Disables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableCN0()
 *
 *****************************************************************************/
#ifdef _PORTA 
  #define DisableCNA15                (CNENACLR = (1 << _CNENA_CNIEA15_POSITION))
  #define DisableCNA14                (CNENACLR = (1 << _CNENA_CNIEA14_POSITION))
  #define DisableCNA10                (CNENACLR = (1 << _CNENA_CNIEA10_POSITION))
  #define DisableCNA9                 (CNENACLR = (1 << _CNENA_CNIEA9_POSITION))
  #define DisableCNA7                 (CNENACLR = (1 << _CNENA_CNIEA7_POSITION))
  #define DisableCNA6                 (CNENACLR = (1 << _CNENA_CNIEA6_POSITION))
  #define DisableCNA5                 (CNENACLR = (1 << _CNENA_CNIEA5_POSITION))
  #define DisableCNA4                 (CNENACLR = (1 << _CNENA_CNIEA4_POSITION))
  #define DisableCNA3                 (CNENACLR = (1 << _CNENA_CNIEA3_POSITION))
  #define DisableCNA2                 (CNENACLR = (1 << _CNENA_CNIEA2_POSITION))
  #define DisableCNA1                 (CNENACLR = (1 << _CNENA_CNIEA1_POSITION))
  #define DisableCNA0                 (CNENACLR = (1 << _CNENA_CNIEA0_POSITION))
  #define DisableCNA_ALL              (CNENACLR = (0xFFFF))
#endif
  #define DisableCNB15                (CNENBCLR = (1 << _CNENB_CNIEB15_POSITION))
  #define DisableCNB14                (CNENBCLR = (1 << _CNENB_CNIEB14_POSITION))
  #define DisableCNB13                (CNENBCLR = (1 << _CNENB_CNIEB13_POSITION))
  #define DisableCNB12                (CNENBCLR = (1 << _CNENB_CNIEB12_POSITION))
  #define DisableCNB11                (CNENBCLR = (1 << _CNENB_CNIEB11_POSITION))
  #define DisableCNB10                (CNENBCLR = (1 << _CNENB_CNIEB10_POSITION))
  #define DisableCNB9                 (CNENBCLR = (1 << _CNENB_CNIEB9_POSITION))
  #define DisableCNB8                 (CNENBCLR = (1 << _CNENB_CNIEB8_POSITION))
  #define DisableCNB7                 (CNENBCLR = (1 << _CNENB_CNIEB7_POSITION))
  #define DisableCNB6                 (CNENBCLR = (1 << _CNENB_CNIEB6_POSITION))
  #define DisableCNB5                 (CNENBCLR = (1 << _CNENB_CNIEB5_POSITION))
  #define DisableCNB4                 (CNENBCLR = (1 << _CNENB_CNIEB4_POSITION))
  #define DisableCNB3                 (CNENBCLR = (1 << _CNENB_CNIEB3_POSITION))
  #define DisableCNB2                 (CNENBCLR = (1 << _CNENB_CNIEB2_POSITION))
  #define DisableCNB1                 (CNENBCLR = (1 << _CNENB_CNIEB1_POSITION))
  #define DisableCNB0                 (CNENBCLR = (1 << _CNENB_CNIEB0_POSITION))
  #define DisableCNB_ALL              (CNENBCLR = (0xFFFF))

  #define DisableCNC15                (CNENCCLR = (1 << _CNENC_CNIEC15_POSITION))
  #define DisableCNC14                (CNENCCLR = (1 << _CNENC_CNIEC14_POSITION))
  #define DisableCNC13                (CNENCCLR = (1 << _CNENC_CNIEC13_POSITION))
  #define DisableCNC12                (CNENCCLR = (1 << _CNENC_CNIEC12_POSITION))
  #define DisableCNC4                 (CNENCCLR = (1 << _CNENC_CNIEC4_POSITION))
  #define DisableCNC3                 (CNENCCLR = (1 << _CNENC_CNIEC3_POSITION))
  #define DisableCNC2                 (CNENCCLR = (1 << _CNENC_CNIEC2_POSITION))
  #define DisableCNC1                 (CNENCCLR = (1 << _CNENC_CNIEC1_POSITION))
  #define DisableCNC_ALL              (CNENCCLR = (0xFFFF))

  #define DisableCND15                (CNENDCLR = (1 << _CNEND_CNIED15_POSITION))
  #define DisableCND14                (CNENDCLR = (1 << _CNEND_CNIED14_POSITION))
  #define DisableCND13                (CNENDCLR = (1 << _CNEND_CNIED13_POSITION))
  #define DisableCND12                (CNENDCLR = (1 << _CNEND_CNIED12_POSITION))
  #define DisableCND11                (CNENDCLR = (1 << _CNEND_CNIED11_POSITION))
  #define DisableCND10                (CNENDCLR = (1 << _CNEND_CNIED10_POSITION))
  #define DisableCND9                 (CNENDCLR = (1 << _CNEND_CNIED9_POSITION))
  #define DisableCND7                 (CNENDCLR = (1 << _CNEND_CNIED7_POSITION))
  #define DisableCND6                 (CNENDCLR = (1 << _CNEND_CNIED6_POSITION))
  #define DisableCND5                 (CNENDCLR = (1 << _CNEND_CNIED5_POSITION))
  #define DisableCND4                 (CNENDCLR = (1 << _CNEND_CNIED4_POSITION))
  #define DisableCND3                 (CNENDCLR = (1 << _CNEND_CNIED3_POSITION))
  #define DisableCND2                 (CNENDCLR = (1 << _CNEND_CNIED2_POSITION))
  #define DisableCND1                 (CNENDCLR = (1 << _CNEND_CNIED1_POSITION))
  #define DisableCND0                 (CNENDCLR = (1 << _CNEND_CNIED0_POSITION))
  #define DisableCND_ALL              (CNENDCLR = (0xFFFF))

  #define DisableCNE9                 (CNENECLR = (1 << _CNENE_CNIEE9_POSITION))
  #define DisableCNE8                 (CNENECLR = (1 << _CNENE_CNIEE8_POSITION))
  #define DisableCNE7                 (CNENECLR = (1 << _CNENE_CNIEE7_POSITION))
  #define DisableCNE6                 (CNENECLR = (1 << _CNENE_CNIEE6_POSITION))
  #define DisableCNE5                 (CNENECLR = (1 << _CNENE_CNIEE5_POSITION))
  #define DisableCNE4                 (CNENECLR = (1 << _CNENE_CNIEE4_POSITION))
  #define DisableCNE3                 (CNENECLR = (1 << _CNENE_CNIEE3_POSITION))
  #define DisableCNE2                 (CNENECLR = (1 << _CNENE_CNIEE2_POSITION))
  #define DisableCNE1                 (CNENECLR = (1 << _CNENE_CNIEE1_POSITION))
  #define DisableCNE0                 (CNENECLR = (1 << _CNENE_CNIEE0_POSITION))
  #define DisableCNE_ALL              (CNENECLR = (0xFFFF))

  #define DisableCNF13                (CNENFCLR = (1 << _CNENF_CNIEF13_POSITION))
  #define DisableCNF12                (CNENFCLR = (1 << _CNENF_CNIEF12_POSITION))
  #define DisableCNF8                 (CNENFCLR = (1 << _CNENF_CNIEF8_POSITION))
  #define DisableCNF5                 (CNENFCLR = (1 << _CNENF_CNIEF5_POSITION))
  #define DisableCNF4                 (CNENFCLR = (1 << _CNENF_CNIEF4_POSITION))
  #define DisableCNF3                 (CNENFCLR = (1 << _CNENF_CNIEF3_POSITION))
  #define DisableCNF2                 (CNENFCLR = (1 << _CNENF_CNIEF2_POSITION))
  #define DisableCNF1                 (CNENFCLR = (1 << _CNENF_CNIEF1_POSITION))
  #define DisableCNF0                 (CNENFCLR = (1 << _CNENF_CNIEF0_POSITION))
  #define DisableCNF_ALL              (CNENFCLR = (0xFFFF))
 
  #define DisableCNG15                (CNENGCLR = (1 << _CNENG_CNIEG15_POSITION))
  #define DisableCNG14                (CNENGCLR = (1 << _CNENG_CNIEG14_POSITION))
  #define DisableCNG13                (CNENGCLR = (1 << _CNENG_CNIEG13_POSITION))
  #define DisableCNG12                (CNENGCLR = (1 << _CNENG_CNIEG12_POSITION))    
  #define DisableCNG9                 (CNENGCLR = (1 << _CNENG_CNIEG9_POSITION))
  #define DisableCNG8                 (CNENGCLR = (1 << _CNENG_CNIEG8_POSITION))
  #define DisableCNG7                 (CNENGCLR = (1 << _CNENG_CNIEG7_POSITION))
  #define DisableCNG6                 (CNENGCLR = (1 << _CNENG_CNIEG6_POSITION))
  #define DisableCNG1                 (CNENGCLR = (1 << _CNENG_CNIEG1_POSITION))
  #define DisableCNG0                 (CNENGCLR = (1 << _CNENG_CNIEG0_POSITION))
  #define DisableCNG_ALL              (CNENGCLR = (0xFFFF))    
#ifdef _PORTH
  #define DisableCNH15                (CNENHCLR = (1 << _CNENH_CNIEH15_POSITION))
  #define DisableCNH14                (CNENHCLR = (1 << _CNENH_CNIEH14_POSITION))
  #define DisableCNH13                (CNENHCLR = (1 << _CNENH_CNIEH13_POSITION))
  #define DisableCNH12                (CNENHCLR = (1 << _CNENH_CNIEH12_POSITION))
  #define DisableCNH11                (CNENHCLR = (1 << _CNENH_CNIEH11_POSITION))
  #define DisableCNH10                (CNENHCLR = (1 << _CNENH_CNIEH10_POSITION))
  #define DisableCNH9                 (CNENHCLR = (1 << _CNENH_CNIEH9_POSITION))
  #define DisableCNH8                 (CNENHCLR = (1 << _CNENH_CNIEH8_POSITION))
  #define DisableCNH7                 (CNENHCLR = (1 << _CNENH_CNIEH7_POSITION))
  #define DisableCNH6                 (CNENHCLR = (1 << _CNENH_CNIEH6_POSITION))
  #define DisableCNH5                 (CNENHCLR = (1 << _CNENH_CNIEH5_POSITION))
  #define DisableCNH4                 (CNENHCLR = (1 << _CNENH_CNIEH4_POSITION))
  #define DisableCNH3                 (CNENHCLR = (1 << _CNENH_CNIEH3_POSITION))
  #define DisableCNH2                 (CNENHCLR = (1 << _CNENH_CNIEH2_POSITION))
  #define DisableCNH1                 (CNENHCLR = (1 << _CNENH_CNIEH1_POSITION))
  #define DisableCNH0                 (CNENHCLR = (1 << _CNENH_CNIEH0_POSITION))
  #define DisableCNH_ALL              (CNENHCLR = (0xFFFF))
#endif    
#ifdef _PORTJ
  #define DisableCNJ15                (CNENJCLR = (1 << _CNENJ_CNIEJ15_POSITION))
  #define DisableCNJ14                (CNENJCLR = (1 << _CNENJ_CNIEJ14_POSITION))
  #define DisableCNJ13                (CNENJCLR = (1 << _CNENJ_CNIEJ13_POSITION))
  #define DisableCNJ12                (CNENJCLR = (1 << _CNENJ_CNIEJ12_POSITION))
  #define DisableCNJ11                (CNENJCLR = (1 << _CNENJ_CNIEJ11_POSITION))
  #define DisableCNJ10                (CNENJCLR = (1 << _CNENJ_CNIEJ10_POSITION))
  #define DisableCNJ9                 (CNENJCLR = (1 << _CNENJ_CNIEJ9_POSITION))
  #define DisableCNJ8                 (CNENJCLR = (1 << _CNENJ_CNIEJ8_POSITION))
  #define DisableCNJ7                 (CNENJCLR = (1 << _CNENJ_CNIEJ7_POSITION))
  #define DisableCNJ6                 (CNENJCLR = (1 << _CNENJ_CNIEJ6_POSITION))
  #define DisableCNJ5                 (CNENJCLR = (1 << _CNENJ_CNIEJ5_POSITION))
  #define DisableCNJ4                 (CNENJCLR = (1 << _CNENJ_CNIEJ4_POSITION))
  #define DisableCNJ3                 (CNENJCLR = (1 << _CNENJ_CNIEJ3_POSITION))
  #define DisableCNJ2                 (CNENJCLR = (1 << _CNENJ_CNIEJ2_POSITION))
  #define DisableCNJ1                 (CNENJCLR = (1 << _CNENJ_CNIEJ1_POSITION))
  #define DisableCNJ0                 (CNENJCLR = (1 << _CNENJ_CNIEJ0_POSITION))
  #define DisableCNJ_ALL              (CNENJCLR = (0xFFFF))
#endif       
#ifdef _PORTK
  #define DisableCNK7                 (CNENKCLR = (1 << _CNENK_CNIEK7_POSITION))
  #define DisableCNK6                 (CNENKCLR = (1 << _CNENK_CNIEK6_POSITION))
  #define DisableCNK5                 (CNENKCLR = (1 << _CNENK_CNIEK5_POSITION))
  #define DisableCNK4                 (CNENKCLR = (1 << _CNENK_CNIEK4_POSITION))
  #define DisableCNK3                 (CNENKCLR = (1 << _CNENK_CNIEK3_POSITION))
  #define DisableCNK2                 (CNENKCLR = (1 << _CNENK_CNIEK2_POSITION))
  #define DisableCNK1                 (CNENKCLR = (1 << _CNENK_CNIEK1_POSITION))
  #define DisableCNK0                 (CNENKCLR = (1 << _CNENK_CNIEK0_POSITION))
  #define DisableCNK_ALL              (CNENKCLR = (0xFFFF))
#endif   
    

/******************************************************************************
 * PORT Parameter values to be used with mPORTxxx macros
 *****************************************************************************/

 #define BIT_31                       (1 << 31)
 #define BIT_30                       (1 << 30)
 #define BIT_29                       (1 << 29)
 #define BIT_28                       (1 << 28)
 #define BIT_27                       (1 << 27)
 #define BIT_26                       (1 << 26)
 #define BIT_25                       (1 << 25)
 #define BIT_24                       (1 << 24)
 #define BIT_23                       (1 << 23)
 #define BIT_22                       (1 << 22)
 #define BIT_21                       (1 << 21)
 #define BIT_20                       (1 << 20)
 #define BIT_19                       (1 << 19)
 #define BIT_18                       (1 << 18)
 #define BIT_17                       (1 << 17)
 #define BIT_16                       (1 << 16)
 #define BIT_15                       (1 << 15)
 #define BIT_14                       (1 << 14)
 #define BIT_13                       (1 << 13)
 #define BIT_12                       (1 << 12)
 #define BIT_11                       (1 << 11)
 #define BIT_10                       (1 << 10)
 #define BIT_9                        (1 << 9)
 #define BIT_8                        (1 << 8)
 #define BIT_7                        (1 << 7)
 #define BIT_6                        (1 << 6)
 #define BIT_5                        (1 << 5)
 #define BIT_4                        (1 << 4)
 #define BIT_3                        (1 << 3)
 #define BIT_2                        (1 << 2)
 #define BIT_1                        (1 << 1)
 #define BIT_0                        (1 << 0)

 #define IOPORT_PIN_15                  BIT_15
 #define IOPORT_PIN_14                  BIT_14
 #define IOPORT_PIN_13                  BIT_13
 #define IOPORT_PIN_12                  BIT_12
 #define IOPORT_PIN_11                  BIT_11
 #define IOPORT_PIN_10                  BIT_10
 #define IOPORT_PIN_9                   BIT_9
 #define IOPORT_PIN_8                   BIT_8
 #define IOPORT_PIN_7                   BIT_7
 #define IOPORT_PIN_6                   BIT_6
 #define IOPORT_PIN_5                   BIT_5
 #define IOPORT_PIN_4                   BIT_4
 #define IOPORT_PIN_3                   BIT_3
 #define IOPORT_PIN_2                   BIT_2
 #define IOPORT_PIN_1                   BIT_1
 #define IOPORT_PIN_0                   BIT_0    

 #define IOPORT_BIT_15                  BIT_15
 #define IOPORT_BIT_14                  BIT_14
 #define IOPORT_BIT_13                  BIT_13
 #define IOPORT_BIT_12                  BIT_12
 #define IOPORT_BIT_11                  BIT_11
 #define IOPORT_BIT_10                  BIT_10
 #define IOPORT_BIT_9                   BIT_9
 #define IOPORT_BIT_8                   BIT_8
 #define IOPORT_BIT_7                   BIT_7
 #define IOPORT_BIT_6                   BIT_6
 #define IOPORT_BIT_5                   BIT_5
 #define IOPORT_BIT_4                   BIT_4
 #define IOPORT_BIT_3                   BIT_3
 #define IOPORT_BIT_2                   BIT_2
 #define IOPORT_BIT_1                   BIT_1
 #define IOPORT_BIT_0                   BIT_0 
    
typedef enum {
    IOPORT_A = 0,
    IOPORT_B,
    IOPORT_C,
    IOPORT_D,
    IOPORT_E,
    IOPORT_F,
    IOPORT_G,
    IOPORT_H,
    IOPORT_J,
    IOPORT_K,              
    IOPORT_NUM
} IoPortId;    

/******************************************************************************
 * Set Pins as Digital Input
 *
 * Function:        PORTSetPinsDigitalIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as digital inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/  
extern inline void __attribute__((always_inline)) 
PORTSetPinsDigitalIn( IoPortId portId, unsigned int inputs )
{
    volatile unsigned int *pTRIS_Set = (volatile unsigned int *)(0xBF860018 + (0x100*((unsigned int)portId)));
    volatile unsigned int *pANSEL_Clr = (volatile unsigned int *)(0xBF860004 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pTRIS_Set      = inputs;
    if( portId == (IOPORT_NUM-1) ) return;
    *pANSEL_Clr   = (0x0000FFFF & inputs);
}
    
/******************************************************************************
 * Set Pins as Digital Output
 *
 * Function:        PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as digital outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTSetPinsDigitalOut( IoPortId portId, unsigned int outputs )
{
    volatile unsigned int *pTRIS_Clr = (volatile unsigned int *)(0xBF860014 + (0x100*((unsigned int)portId)));
    volatile unsigned int *pANSEL_Clr = (volatile unsigned int *)(0xBF860004 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pTRIS_Clr    = outputs;
    if( portId == (IOPORT_NUM-1) ) return;
    *pANSEL_Clr   = (0x0000FFFF & outputs);    
}

/******************************************************************************
 * Set Pins as Analog Input
 *
 * Function:        PORTSetPinsAnalogIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as Analog inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTSetPinsAnalogIn( IoPortId portId, unsigned int inputs )
{
    volatile unsigned int *pTRIS_Set = (volatile unsigned int *)(0xBF860018 + (0x100*((unsigned int)portId)));
    volatile unsigned int *pANSEL_Set = (volatile unsigned int *)(0xBF860008 + (0x100*((unsigned int)portId)));
    
    if( portId >= (IOPORT_NUM-1) ) return;
    *pANSEL_Set   = (0x0000FFFF & inputs);   
    *pTRIS_Set    = inputs;
}

/******************************************************************************
 * Set Pins as Analog Output
 *
 * Function:        PORTSetPinsAnalogOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as analog outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTSetPinsAnalogOut( IoPortId portId, unsigned int outputs )
{
    volatile unsigned int *pTRIS_Clr = (volatile unsigned int *)(0xBF860014 + (0x100*((unsigned int)portId)));
    volatile unsigned int *pANSEL_Set = (volatile unsigned int *)(0xBF860008 + (0x100*((unsigned int)portId)));
    
    if( portId >= (IOPORT_NUM-1) ) return;
    *pANSEL_Set   = (0x0000FFFF & outputs);   
    *pTRIS_Clr    = outputs;    
}

/******************************************************************************
 * Reset PORT pins
 *
 * Function:        PORTResetPins(IoPortId portId, unsigned int pins)
 *
 * Description:     Resets IOPORT pins to their POR state
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  pins: Bit-wise ORed of port pin bits.
 *
 *
 * Output:          None
 *
 * Example:         PORTResetPins(IOPORT_D, IOPORT_PIN_15);// Set Port D, bit 15 to input, latch at zero
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTResetPins( IoPortId portId, unsigned int pins )
{
    volatile unsigned int *pTRIS_Set = (volatile unsigned int *)(0xBF860018 + (0x100*((unsigned int)portId)));
    volatile unsigned int *pLAT_Clr = (volatile unsigned int *)(0xBF860034 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pTRIS_Set   = pins;
    *pLAT_Clr    = pins;
}

/******************************************************************************
 * Reads digital port
 *
 * Function:        unsigned int    PORTRead(IoPortId portId);
 *
 * Description:     Reads from a selected port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTRead(IOPORT_B);
 *
 *****************************************************************************/
extern inline unsigned int __attribute__((always_inline)) 
PORTRead( IoPortId portId )
{
    volatile unsigned int *pPORT = (volatile unsigned int *)(0xBF860020 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return 0;
    return(*pPORT);   
}

/******************************************************************************
 * Reads digital port bits
 *
 * Function:        unsigned int    PORTReadBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Reads selected pins from port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be read
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTReadBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
extern inline unsigned int __attribute__((always_inline)) 
PORTReadBits( IoPortId portId, unsigned int bits )
{
    volatile unsigned int *pPORT = (volatile unsigned int *)(0xBF860020 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return 0;
    return(*pPORT & bits);    
}

/******************************************************************************
 * Writes to a digital port
 *
 * Function:        void    PORTWrite(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes to PORT register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          None
 *
 * Example:         PORTWrite(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/  
extern inline void __attribute__((always_inline)) 
PORTWrite( IoPortId portId, unsigned int bits )
{
    volatile unsigned int *pLAT = (volatile unsigned int *)(0xBF860030 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pLAT = bits;    
}

/******************************************************************************
 * Sets digital port bits
 *
 * Function:        void    PORTSetBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTSET register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTSetBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTSetBits( IoPortId portId, unsigned int bits )
{
    volatile unsigned int *pLAT_Set = (volatile unsigned int *)(0xBF860038 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pLAT_Set = bits;     
}

/******************************************************************************
 * Clears digital port bits
 *
 * Function:        void    PORTClearBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTCLR register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTClearBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTClearBits( IoPortId portId, unsigned int bits )
{
    volatile unsigned int *pLAT_Clr = (volatile unsigned int *)(0xBF860034 + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pLAT_Clr = bits;      
}

/******************************************************************************
 * Toggle digital port bits
 *
 * Function:        void    PORTToggleBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTINV register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTToggleBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PORTToggleBits( IoPortId portId, unsigned int bits )
{
    volatile unsigned int *pLAT_Inv = (volatile unsigned int *)(0xBF86003C + (0x100*((unsigned int)portId)));
    
    if( portId >= IOPORT_NUM ) return;
    *pLAT_Inv = bits;       
}


/******************************************************************************
 * <combinewith mPORTAGetDirection, mPORTAReadDirectionBits, mPORTARead ,mPORTAReadBits, mPORTAReadLatch,
 * mPORTAReadLatchBits, mPORTAWrite, mPORTASetBits, mPORTAClearBits, mPORTAToggleBits, mPORTAOpenDrainOpen,
 * mPORTAOpenDrainClose, mPORTACloseAll, mPORTACloseBits, mPORTASetPinsDigitalIn, mPORTASetPinsDigitalOut,
 * mPORTBDirection, mPORTBGetDirection, mPORTBReadDirectionBits, mPORTBRead ,mPORTBReadBits, mPORTBReadLatch,
 * mPORTBReadLatchBits, mPORTBWrite, mPORTBSetBits, mPORTBClearBits, mPORTBToggleBits, mPORTBOpenDrainOpen,
 * mPORTBOpenDrainClose, mPORTBCloseAll, mPORTBCloseBits, mPORTBSetPinsDigitalIn, mPORTBSetPinsDigitalOut,
 * mPORTBSetPinsAnalogOut, mPORTBSetPinsAnalogIn,
 * mPORTCDirection, mPORTCGetDirection, mPORTCReadDirectionBits, mPORTCRead ,mPORTCReadBits, mPORTCReadLatch,
 * mPORTCReadLatchBits, mPORTCWrite, mPORTCSetBits, mPORTCClearBits, mPORTCToggleBits, mPORTCOpenDrainOpen,
 * mPORTCOpenDrainClose, mPORTCCloseAll, mPORTCCloseBits, mPORTCSetPinsDigitalIn, mPORTCSetPinsDigitalOut,
 * mPORTDDirection, mPORTDGetDirection, mPORTDReadDirectionBits, mPORTDRead ,mPORTDReadBits, mPORTDReadLatch,
 * mPORTDReadLatchBits, mPORTDWrite, mPORTDSetBits, mPORTDClearBits, mPORTDToggleBits, mPORTDOpenDrainOpen,
 * mPORTDOpenDrainClose, mPORTDCloseAll, mPORTDCloseBits, mPORTDSetPinsDigitalIn, mPORTDSetPinsDigitalOut,
 * mPORTBEirection, mPORTEGetDirection, mPORTEReadDirectionBits, mPORTERead ,mPORTEReadBits, mPORTEReadLatch,
 * mPORTEReadLatchBits, mPORTEWrite, mPORTESetBits, mPORTEClearBits, mPORTEToggleBits, mPORTEOpenDrainOpen,
 * mPORTEOpenDrainClose, mPORTECloseAll, mPORTECloseBits, mPORTESetPinsDigitalIn, mPORTESetPinsDigitalOut,
 * mPORTFDirection, mPORTFGetDirection, mPORTFReadDirectionBits, mPORTFRead ,mPORTFReadBits, mPORTFReadLatch,
 * mPORTFReadLatchBits, mPORTFWrite, mPORTFSetBits, mPORTFClearBits, mPORTFToggleBits, mPORTFOpenDrainOpen,
 * mPORTFOpenDrainClose, mPORTFCloseAll, mPORTFCloseBits, mPORTFSetPinsDigitalIn, mPORTFSetPinsDigitalOut,
 * mPORTGDirection, mPORTGGetDirection, mPORTGReadDirectionBits, mPORTGRead ,mPORTGReadBits, mPORTGReadLatch,
 * mPORTGReadLatchBits, mPORTGWrite, mPORTGSetBits, mPORTGClearBits, mPORTGToggleBits, mPORTGOpenDrainOpen,
 * mPORTGOpenDrainClose, mPORTGCloseAll, mPORTGCloseBits, mPORTGSetPinsDigitalIn, mPORTGSetPinsDigitalOut,
 * mPORTHDirection, mPORTHGetDirection, mPORTHReadDirectionBits, mPORTHRead ,mPORTHReadBits, mPORTHReadLatch,
 * mPORTHReadLatchBits, mPORTHWrite, mPORTHSetBits, mPORTHClearBits, mPORTHToggleBits, mPORTHOpenDrainOpen,
 * mPORTHOpenDrainClose, mPORTHCloseAll, mPORTHCloseBits, mPORTHSetPinsDigitalIn, mPORTHSetPinsDigitalOut,
 * mPORTJDirection, mPORTJGetDirection, mPORTJReadDirectionBits, mPORTJRead ,mPORTJReadBits, mPORTJReadLatch,
 * mPORTJReadLatchBits, mPORTJWrite, mPORTJSetBits, mPORTJClearBits, mPORTJToggleBits, mPORTJOpenDrainOpen,
 * mPORTJOpenDrainClose, mPORTJCloseAll, mPORTJCloseBits, mPORTJSetPinsDigitalIn, mPORTJSetPinsDigitalOut,
 * mPORTKDirection, mPORTKGetDirection, mPORTKReadDirectionBits, mPORTKRead ,mPORTKReadBits, mPORTKReadLatch,
 * mPORTKReadLatchBits, mPORTKWrite, mPORTKSetBits, mPORTKClearBits, mPORTKToggleBits, mPORTKOpenDrainOpen,
 * mPORTKOpenDrainClose, mPORTKCloseAll, mPORTKCloseBits, mPORTKSetPinsDigitalIn, mPORTKSetPinsDigitalOut>
 *
 * GPIO Control Macros
 *
 * Description:
 *          To set I/O pin directions for a PORTx
 *                  void mPORTxConfig(unsigned int _direction)
 *                  unsigned int mPORTxGetConfig(void)
 *                  unsigned int mPORTxReadConfigBit(unsigned int _bits)
 *
 *          To read an input pin
 *                  unsigned int mPORTxRead(void)
 *                  unsigned int mPORTxReadBit(unsigned int _bits)
 *
 *          To write to an output pin
 *                  void mPORTxWrite(unsigned int _value)
 *                  unsigned int mPORTxReadLatch(void)
 *                  unsigned int mPORTxReadLatchBit(unsigned int _bits)
 *
 *          To configure select pins in a PORT without affecting other pins
 *                  void mPORTxSetPinsDigitalInput(unsigned int _inputs)
 *                  void mPORTxSetPinsDigitalOutput(unsigned int _outputs)
 *                  void mPORTxSetPinsAnalogInput(unsigned int _inputs)
 *                  void mPORTxSetPinsAnalogOutput(unsigned int _outputs)
 *                  void mPORTxOutputConfig(unsigned int _outputs)
 *                  void mPORTxInputConfig(unsigned int _inputs)
 *
 *          To manipulate select pins in a PORT without affecting other pins
 *                  void mPORTxSetbits(unsigned int _bits)
 *                  void mPORTxClearBits(unsigned int _bits)
 *                  void mPORTxToggleBits(unsigned int _bits)
 *
 *          To make a PORT all input and clear latch values.
 *                  void mPORTxCloseAll(void)
 *                  void mPORTxCloseBits(unsigned int _bits)
 *
 *          To configure open drain I/Os in a PORT.
 *                  void mPORTxOpenDrainOpen(unsigned int _bits)
 *                  void mPORTxOpenDrainClose(unsigned int _bits)
 *
 *
 * Example:         mPORTCSetPinsDigitalOutput(IOPORT_PIN_5 | IOPORT_PIN_6)
 *
 *****************************************************************************/

#if defined _PORTA
/******************************************************************************
 * PORTA macros
 *****************************************************************************/
  #define mPORTADirection(_tris)              (TRISA = (unsigned int)(_tris))
  #define mPORTAGetDirection()                (TRISA)
  #define mPORTAReadDirectionBits(_bits)      (TRISA & (unsigned int)(_bits))

  #define mPORTARead()                        (PORTA)
  #define mPORTAReadBits(_bits)               (PORTA & (unsigned int)(_bits))
  #define mPORTAReadLatch()                   (LATA)
  #define mPORTAReadLatchBits(_bits)          (LATA & (unsigned int)(_bits))

  #define mPORTAWrite(_lat)                   (LATA = (unsigned int)(_lat))
  #define mPORTASetBits(_bits)                (LATASET = (unsigned int)(_bits))
  #define mPORTAClearBits(_bits)              (LATACLR = (unsigned int)(_bits))
  #define mPORTAToggleBits(_bits)             (LATAINV = (unsigned int)(_bits))

  #define mPORTAOpenDrainOpen(_bits)          (ODCASET = (unsigned int)(_bits), TRISACLR = (unsigned int)(_bits))
  #define mPORTAOpenDrainClose(_bits)         (ODCACLR = (unsigned int)(_bits), TRISASET = (unsigned int)(_bits))

  #define mPORTACloseAll()                    (TRISASET = 0xFFFFFFFF, LATACLR = 0xFFFFFFFF)
  #define mPORTACloseBits(_bits)              (TRISASET = (unsigned int)(_bits), LATACLR = (unsigned int)(_bits))

  #define mPORTASetPinsAnalogOut(_outputs)    (TRISACLR = (unsigned int)(_outputs), ANSELASET = (unsigned int)(_outputs))
  #define mPORTASetPinsAnalogIn(_inputs)      (TRISASET = (unsigned int)(_inputs),  ANSELASET = (unsigned int)(_inputs) )
  #define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs), ANSELACLR = (unsigned int)(_outputs))
  #define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs),  ANSELACLR = (unsigned int)(_inputs) )
#endif  //end PORTA

#if defined _PORTB
/******************************************************************************
 * PORTB macros
 *****************************************************************************/
  #define mPORTBDirection(_tris)              (TRISB = (unsigned int)(_tris))
  #define mPORTBGetDirection()                (TRISB)
  #define mPORTBReadDirectionBits(_bits)      (TRISB & (unsigned int)(_bits))

  #define mPORTBRead()                        (PORTB)
  #define mPORTBReadBits(_bits)               (PORTB & (unsigned int)(_bits))
  #define mPORTBReadLatch()                   (LATB)
  #define mPORTBReadLatchBits(_bits)          (LATB & (unsigned int)(_bits))

  #define mPORTBWrite(_lat)                   (LATB = (unsigned int)(_lat))
  #define mPORTBSetBits(_bits)                (LATBSET = (unsigned int)(_bits))
  #define mPORTBClearBits(_bits)              (LATBCLR = (unsigned int)(_bits))
  #define mPORTBToggleBits(_bits)             (LATBINV = (unsigned int)(_bits))

  #define mPORTBOpenDrainOpen(_bits)          (ODCBSET = (unsigned int)(_bits), TRISBCLR = (unsigned int)(_bits))
  #define mPORTBOpenDrainClose(_bits)         (ODCBCLR = (unsigned int)(_bits), TRISBSET = (unsigned int)(_bits))

  #define mPORTBCloseAll()                    (TRISBSET = 0xFFFFFFFF, LATBCLR = 0xFFFFFFFF)
  #define mPORTBCloseBits(_bits)              (TRISBSET = (unsigned int)(_bits), LATBCLR = (unsigned int)(_bits))

  #define mPORTBSetPinsAnalogOut(_outputs)    (TRISBCLR = (unsigned int)(_outputs), ANSELBSET = (unsigned int)(_outputs))
  #define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),  ANSELBSET = (unsigned int)(_inputs) )
  #define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs), ANSELBCLR = (unsigned int)(_outputs))
  #define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),  ANSELBCLR = (unsigned int)(_inputs) )
#endif  //end PORTB

#if defined _PORTC
/******************************************************************************
 * PORTC macros
 *****************************************************************************/
  #define mPORTCDirection(_tris)              (TRISC = (unsigned int)(_tris))
  #define mPORTCGetDirection()                (TRISC)
  #define mPORTCReadDirectionBits(_bits)      (TRISC & (unsigned int)(_bits))

  #define mPORTCRead()                        (PORTC)
  #define mPORTCReadBits(_bits)               (PORTC & (unsigned int)(_bits))
  #define mPORTCReadLatch()                   (LATC)
  #define mPORTCReadLatchBits(_bits)          (LATC & (unsigned int)(_bits))

  #define mPORTCWrite(_lat)                   (LATC = (unsigned int)(_lat))
  #define mPORTCSetBits(_bits)                (LATCSET = (unsigned int)(_bits))
  #define mPORTCClearBits(_bits)              (LATCCLR = (unsigned int)(_bits))
  #define mPORTCToggleBits(_bits)             (LATCINV = (unsigned int)(_bits))

  #define mPORTCOpenDrainOpen(_bits)          (ODCCSET = (unsigned int)(_bits), TRISCCLR = (unsigned int)(_bits))
  #define mPORTCOpenDrainClose(_bits)         (ODCCCLR = (unsigned int)(_bits), TRISCSET = (unsigned int)(_bits))

  #define mPORTCCloseAll()                    (TRISCSET = 0xFFFFFFFF, LATCCLR = 0xFFFFFFFF)
  #define mPORTCCloseBits(_bits)              (TRISCSET = (unsigned int)(_bits), LATCCLR = (unsigned int)(_bits))

  #define mPORTCSetPinsAnalogOut(_outputs)    (TRISCCLR = (unsigned int)(_outputs), ANSELCSET = (unsigned int)(_outputs))
  #define mPORTCSetPinsAnalogIn(_inputs)      (TRISCSET = (unsigned int)(_inputs),  ANSELCSET = (unsigned int)(_inputs) )
  #define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs), ANSELCCLR = (unsigned int)(_outputs))
  #define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs),  ANSELCCLR = (unsigned int)(_inputs) )
#endif  // end PORTC

#if defined _PORTD
/******************************************************************************
 * PORTD macros
 *****************************************************************************/
  #define mPORTDDirection(_tris)              (TRISD = (unsigned int)(_tris))
  #define mPORTDGetDirection()                (TRISD)
  #define mPORTDReadDirectionBits(_bits)      (TRISD & (unsigned int)(_bits))

  #define mPORTDRead()                        (PORTD)
  #define mPORTDReadBits(_bits)               (PORTD & (unsigned int)(_bits))
  #define mPORTDReadLatch()                   (LATD)
  #define mPORTDReadLatchBits(_bits)          (LATD & (unsigned int)(_bits))

  #define mPORTDWrite(_lat)                   (LATD = (unsigned int)(_lat))
  #define mPORTDSetBits(_bits)                (LATDSET = (unsigned int)(_bits))
  #define mPORTDClearBits(_bits)              (LATDCLR = (unsigned int)(_bits))
  #define mPORTDToggleBits(_bits)             (LATDINV = (unsigned int)(_bits))

  #define mPORTDOpenDrainOpen(_bits)          (TRISDCLR = (unsigned int)(_bits), ODCDSET = (unsigned int)(_bits))
  #define mPORTDOpenDrainClose(_bits)         (TRISDSET = (unsigned int)(_bits), ODCDCLR = (unsigned int)(_bits))

  #define mPORTDCloseAll()                    (TRISDSET = 0xFFFFFFFF, LATDCLR = 0xFFFFFFFF)
  #define mPORTDCloseBits(_bits)              (TRISDSET = (unsigned int)(_bits), LATDCLR = (unsigned int)(_bits))

  #define mPORTDSetPinsAnalogOut(_outputs)    (TRISDCLR = (unsigned int)(_outputs), ANSELDSET = (unsigned int)(_outputs))
  #define mPORTDSetPinsAnalogIn(_inputs)      (TRISDSET = (unsigned int)(_inputs),  ANSELDSET = (unsigned int)(_inputs) )
  #define mPORTDSetPinsDigitalOut(_outputs)   (TRISDCLR = (unsigned int)(_outputs), ANSELDCLR = (unsigned int)(_outputs))
  #define mPORTDSetPinsDigitalIn(_inputs)     (TRISDSET = (unsigned int)(_inputs),  ANSELDCLR = (unsigned int)(_inputs) )
#endif  // end PORTD

#if defined _PORTE
/******************************************************************************
 * PORTE macros
 *****************************************************************************/
  #define mPORTEDirection(_tris)              (TRISE = (unsigned int)(_tris))
  #define mPORTEGetDirection()                (TRISE)
  #define mPORTEReadDirectionBits(_bits)      (TRISE & (unsigned int)(_bits))

  #define mPORTERead()                        (PORTE)
  #define mPORTEReadBits(_bits)               (PORTE & (unsigned int)(_bits))
  #define mPORTEReadLatch()                   (LATE)
  #define mPORTEReadLatchBits(_bits)          (LATE & (unsigned int)(_bits))

  #define mPORTEWrite(_lat)                   (LATE = (unsigned int)(_lat))
  #define mPORTESetBits(_bits)                (LATESET = (unsigned int)(_bits))
  #define mPORTEClearBits(_bits)              (LATECLR = (unsigned int)(_bits))
  #define mPORTEToggleBits(_bits)             (LATEINV = (unsigned int)(_bits))

  #define mPORTEOpenDrainOpen(_bits)          (ODCESET = (unsigned int)(_bits), TRISECLR = (unsigned int)(_bits))
  #define mPORTEOpenDrainClose(_bits)         (ODCECLR = (unsigned int)(_bits), TRISESET = (unsigned int)(_bits))

  #define mPORTECloseAll()                    (TRISESET = 0xFFFFFFFF, LATECLR = 0xFFFFFFFF)
  #define mPORTECloseBits(_bits)              (TRISESET = (unsigned int)(_bits), LATECLR = (unsigned int)(_bits))

  #define mPORTESetPinsAnalogOut(_outputs)    (TRISECLR = (unsigned int)(_outputs), ANSELESET = (unsigned int)(_outputs))
  #define mPORTESetPinsAnalogIn(_inputs)      (TRISESET = (unsigned int)(_inputs),  ANSELESET = (unsigned int)(_inputs) )
  #define mPORTESetPinsDigitalOut(_outputs)   (TRISECLR = (unsigned int)(_outputs), ANSELECLR = (unsigned int)(_outputs))
  #define mPORTESetPinsDigitalIn(_inputs)     (TRISESET = (unsigned int)(_inputs),  ANSELECLR = (unsigned int)(_inputs) )
#endif  // end PORTE    
    
#if defined _PORTF
/******************************************************************************
 * PORTF macros
 *****************************************************************************/
  #define mPORTFDirection(_tris)              (TRISF = (unsigned int)(_tris))
  #define mPORTFGetDirection()                (TRISF)
  #define mPORTFReadDirectionBits(_bits)      (TRISF & (unsigned int)(_bits))

  #define mPORTFRead()                        (PORTF)
  #define mPORTFReadBits(_bits)               (PORTF & (unsigned int)(_bits))
  #define mPORTFReadLatch()                   (LATF)
  #define mPORTFReadLatchBits(_bits)          (LATF & (unsigned int)(_bits))

  #define mPORTFWrite(_lat)                   (LATF = (unsigned int)(_lat))
  #define mPORTFSetBits(_bits)                (LATFSET = (unsigned int)(_bits))
  #define mPORTFClearBits(_bits)              (LATFCLR = (unsigned int)(_bits))
  #define mPORTFToggleBits(_bits)             (LATFINV = (unsigned int)(_bits))

  #define mPORTFOpenDrainOpen(_bits)          (ODCFSET = (unsigned int)(_bits), TRISFCLR = (unsigned int)(_bits))
  #define mPORTFOpenDrainClose(_bits)         (ODCFCLR = (unsigned int)(_bits), TRISFSET = (unsigned int)(_bits))

  #define mPORTFCloseAll()                    (TRISFSET = 0xFFFFFFFF, LATFCLR = 0xFFFFFFFF)
  #define mPORTFCloseBits(_bits)              (TRISFSET = (unsigned int)(_bits), LATFCLR = (unsigned int)(_bits))

  #define mPORTFSetPinsAnalogOut(_outputs)    (TRISFCLR = (unsigned int)(_outputs), ANSELFSET = (unsigned int)(_outputs))
  #define mPORTFSetPinsAnalogIn(_inputs)      (TRISFSET = (unsigned int)(_inputs),  ANSELFSET = (unsigned int)(_inputs) )
  #define mPORTFSetPinsDigitalOut(_outputs)   (TRISFCLR = (unsigned int)(_outputs), ANSELFCLR = (unsigned int)(_outputs))
  #define mPORTFSetPinsDigitalIn(_inputs)     (TRISFSET = (unsigned int)(_inputs),  ANSELFCLR = (unsigned int)(_inputs) )
#endif  // end PORTF

#if defined _PORTG
/******************************************************************************
 * PORTG macros
 *****************************************************************************/
  #define mPORTGDirection(_tris)              (TRISG = (unsigned int)(_tris))
  #define mPORTGGetDirection()                (TRISG)
  #define mPORTGReadDirectionBits(_bits)      (TRISG & (unsigned int)(_bits))

  #define mPORTGRead()                        (PORTG)
  #define mPORTGReadBits(_bits)               (PORTG & (unsigned int)(_bits))
  #define mPORTGReadLatch()                   (LATG)
  #define mPORTGReadLatchBits(_bits)          (LATG & (unsigned int)(_bits))

  #define mPORTGWrite(_lat)                   (LATG = (unsigned int)(_lat))
  #define mPORTGSetBits(_bits)                (LATGSET = (unsigned int)(_bits))
  #define mPORTGClearBits(_bits)              (LATGCLR = (unsigned int)(_bits))
  #define mPORTGToggleBits(_bits)             (LATGINV = (unsigned int)(_bits))

  #define mPORTGOpenDrainOpen(_bits)          (ODCGSET = (unsigned int)(_bits), TRISGCLR = (unsigned int)(_bits))
  #define mPORTGOpenDrainClose(_bits)         (ODCGCLR = (unsigned int)(_bits), TRISGSET = (unsigned int)(_bits))

  #define mPORTGCloseAll()                    (TRISGSET = 0xFFFFFFFF, LATGCLR = 0xFFFFFFFF)
  #define mPORTGCloseBits(_bits)              (TRISGSET = (unsigned int)(_bits), LATGCLR = (unsigned int)(_bits))

  #define mPORTGSetPinsAnalogOut(_outputs)    (TRISGCLR = (unsigned int)(_outputs), ANSELGSET = (unsigned int)(_outputs))
  #define mPORTGSetPinsAnalogIn(_inputs)      (TRISGSET = (unsigned int)(_inputs),  ANSELGSET = (unsigned int)(_inputs) )
  #define mPORTGSetPinsDigitalOut(_outputs)   (TRISGCLR = (unsigned int)(_outputs), ANSELGCLR = (unsigned int)(_outputs))
  #define mPORTGSetPinsDigitalIn(_inputs)     (TRISGSET = (unsigned int)(_inputs),  ANSELGCLR = (unsigned int)(_inputs) )
#endif  // end PORTG

#if defined _PORTH
/******************************************************************************
 * PORTH macros
 *****************************************************************************/
  #define mPORTHDirection(_tris)              (TRISH = (unsigned int)(_tris))
  #define mPORTHGetDirection()                (TRISH)
  #define mPORTHReadDirectionBits(_bits)      (TRISH & (unsigned int)(_bits))

  #define mPORTHRead()                        (PORTH)
  #define mPORTHReadBits(_bits)               (PORTH & (unsigned int)(_bits))
  #define mPORTHReadLatch()                   (LATH)
  #define mPORTHReadLatchBits(_bits)          (LATH & (unsigned int)(_bits))

  #define mPORTHWrite(_lat)                   (LATH = (unsigned int)(_lat))
  #define mPORTHSetBits(_bits)                (LATHSET = (unsigned int)(_bits))
  #define mPORTHClearBits(_bits)              (LATHCLR = (unsigned int)(_bits))
  #define mPORTHToggleBits(_bits)             (LATHINV = (unsigned int)(_bits))

  #define mPORTHOpenDrainOpen(_bits)          (ODCHSET = (unsigned int)(_bits), TRISHCLR = (unsigned int)(_bits))
  #define mPORTHOpenDrainClose(_bits)         (ODCHCLR = (unsigned int)(_bits), TRISHSET = (unsigned int)(_bits))

  #define mPORTHCloseAll()                    (TRISHSET = 0xFFFFFFFF, LATHCLR = 0xFFFFFFFF)
  #define mPORTHCloseBits(_bits)              (TRISHSET = (unsigned int)(_bits), LATHCLR = (unsigned int)(_bits))

  #define mPORTHSetPinsAnalogOut(_outputs)    (TRISHCLR = (unsigned int)(_outputs), ANSELHSET = (unsigned int)(_outputs))
  #define mPORTHSetPinsAnalogIn(_inputs)      (TRISHSET = (unsigned int)(_inputs),  ANSELHSET = (unsigned int)(_inputs) )
  #define mPORTHSetPinsDigitalOut(_outputs)   (TRISHCLR = (unsigned int)(_outputs), ANSELHCLR = (unsigned int)(_outputs))
  #define mPORTHSetPinsDigitalIn(_inputs)     (TRISHSET = (unsigned int)(_inputs),  ANSELHCLR = (unsigned int)(_inputs) )
#endif  // end PORTH

#if defined _PORTJ
/******************************************************************************
 * PORTJ macros
 *****************************************************************************/
  #define mPORTJDirection(_tris)              (TRISJ = (unsigned int)(_tris))
  #define mPORTJGetDirection()                (TRISJ)
  #define mPORTJReadDirectionBits(_bits)      (TRISJ & (unsigned int)(_bits))

  #define mPORTJRead()                        (PORTJ)
  #define mPORTJReadBits(_bits)               (PORTJ & (unsigned int)(_bits))
  #define mPORTJReadLatch()                   (LATJ)
  #define mPORTJReadLatchBits(_bits)          (LATJ & (unsigned int)(_bits))

  #define mPORTJWrite(_lat)                   (LATJ = (unsigned int)(_lat))
  #define mPORTJSetBits(_bits)                (LATJSET = (unsigned int)(_bits))
  #define mPORTJClearBits(_bits)              (LATJCLR = (unsigned int)(_bits))
  #define mPORTJToggleBits(_bits)             (LATJINV = (unsigned int)(_bits))

  #define mPORTJOpenDrainOpen(_bits)          (ODCJSET = (unsigned int)(_bits), TRISJCLR = (unsigned int)(_bits))
  #define mPORTJOpenDrainClose(_bits)         (ODCJCLR = (unsigned int)(_bits), TRISJSET = (unsigned int)(_bits))

  #define mPORTJCloseAll()                    (TRISJSET = 0xFFFFFFFF, LATJCLR = 0xFFFFFFFF)
  #define mPORTJCloseBits(_bits)              (TRISJSET = (unsigned int)(_bits), LATJCLR = (unsigned int)(_bits))

  #define mPORTJSetPinsAnalogOut(_outputs)    (TRISJCLR = (unsigned int)(_outputs), ANSELJSET = (unsigned int)(_outputs))
  #define mPORTJSetPinsAnalogIn(_inputs)      (TRISJSET = (unsigned int)(_inputs),  ANSELJSET = (unsigned int)(_inputs) )
  #define mPORTJSetPinsDigitalOut(_outputs)   (TRISJCLR = (unsigned int)(_outputs), ANSELJCLR = (unsigned int)(_outputs))
  #define mPORTJSetPinsDigitalIn(_inputs)     (TRISJSET = (unsigned int)(_inputs),  ANSELJCLR = (unsigned int)(_inputs) )
#endif  // end PORTJ

#if defined _PORTK
/******************************************************************************
 * PORTK macros
 *****************************************************************************/
  #define mPORTKDirection(_tris)              (TRISK = (unsigned int)(_tris))
  #define mPORTKGetDirection()                (TRISK)
  #define mPORTKReadDirectionBits(_bits)      (TRISK & (unsigned int)(_bits))

  #define mPORTKRead()                        (PORTK)
  #define mPORTKReadBits(_bits)               (PORTK & (unsigned int)(_bits))
  #define mPORTKReadLatch()                   (LATK)
  #define mPORTKReadLatchBits(_bits)          (LATK & (unsigned int)(_bits))

  #define mPORTKWrite(_lat)                   (LATK = (unsigned int)(_lat))
  #define mPORTKSetBits(_bits)                (LATKSET = (unsigned int)(_bits))
  #define mPORTKClearBits(_bits)              (LATKCLR = (unsigned int)(_bits))
  #define mPORTKToggleBits(_bits)             (LATKINV = (unsigned int)(_bits))

  #define mPORTKOpenDrainOpen(_bits)          (ODCKSET = (unsigned int)(_bits), TRISKCLR = (unsigned int)(_bits))
  #define mPORTKOpenDrainClose(_bits)         (ODCKCLR = (unsigned int)(_bits), TRISKSET = (unsigned int)(_bits))

  #define mPORTKCloseAll()                    (TRISKSET = 0xFFFFFFFF, LATKCLR = 0xFFFFFFFF)
  #define mPORTKCloseBits(_bits)              (TRISKSET = (unsigned int)(_bits), LATKCLR = (unsigned int)(_bits))

  #define mPORTKSetPinsDigitalOut(_outputs)   (TRISKCLR = (unsigned int)(_outputs))
  #define mPORTKSetPinsDigitalIn(_inputs)     (TRISKSET = (unsigned int)(_inputs))
#endif  // end PORTK


/******************************************************************************
 * Parameter values to be used with mJTAGPortEnable()
 *****************************************************************************/
#define DEBUG_JTAGPORT_ON                       (1)
#define DEBUG_JTAGPORT_OFF                      (0) // Debug JTAG Off

/******************************************************************************
 * JTAG macro       void mJTAGPortEnable(unsigned int enable)
 *
 * Function:
 *                  To enable/disable JTAG module
 *                  mJTAGEnable(unsigned int _enable)
 *
 * Description:     Enables or disables JTAG port.
 *
 * PreCondition:    None
 *
 * Inputs:          0 = disable, 1 = enable
 *
 * Output:          None
 *
 * Example:         mJTAGPortEnable(1)
 *
 *****************************************************************************/
#define mJTAGPortEnable(_enable) (CFGCONbits.JTAGEN = (_enable))

#ifdef	__cplusplus
}
#endif

#endif	/* PORTS_H */

