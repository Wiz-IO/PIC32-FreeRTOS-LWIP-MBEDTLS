/*
		FileName: pmp.h
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

#ifndef PMP_H
#define	PMP_H

#include <xc.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum {BUF0, BUF1, BUF2, BUF3}BUFFER ;

/******************************************************************************
 * Parallel Master Port General Purpose macros
 *
 * Macros:
 *          To enable/disable module's opeation when cpu is in IDLE mode
 *                  mPMPIdleStop(void)
 *                  mPMPIdleContinue(void)
 *
 *          To enable/disable PMP module
 *                  mPMPEnable(void)
 *                  mPMPDisable(void)
 *
 *          To check if Master Mode I,II read/write is busy
 *                  mPMPGetBusyFlag(void)
 *                  mPMPIsPMPBusy(void)
 *
 * PreCondition:    None
 *
 * Parameters:           None
 *
 * Returns:          None
 *
 * Example:         mIsPMPBusy();
 *
 *****************************************************************************/
#define mPMPIdleStop()                          (PMCONSET = _PMCON_SIDL_MASK)
#define mPMPIdleContinue()                      (PMCONCLR = _PMCON_SIDL_MASK)
#define mPMPEnable()                            (PMCONSET = _PMCON_ON_MASK)
#define mPMPDisable()                           (PMCONCLR = _PMCON_ON_MASK)
#define mPMPGetBusyFlag()                       (PMMODEbits.BUSY)
#define mIsPMPBusy()                            (PMMODEbits.BUSY)


/******************************************************************************
  Parallel Master Port Open Function

  Function:        void PMPOpen(unsigned int CONTROL, unsigned int MODE, unsigned int PORT, unsigned int INTERRUPT)

  PreCondition:    None

  Parameters:
         CONTROL   - control bits
         MODE      - mode bits
         PORT      - port bits
         INTERRUPT - interrupt bits
                   - these are Bit-wise OR values of defined bit-masks, see example below

  Remarks:          An absent symbol assumes corresponding bit(s)
                    are disabled, or default value, and will be set = 0.

  Returns:          None

  Example:
  <code>
  #define CONTROL  (PMP_ON | PMP_IDLE_CON | PMP_MUX_DATA8_LOWER | PMP_READ_WRITE_EN | \
                   PMP_CS2_CS1_EN | PMP_LATCH_POL_HI | PMP_CS2_POL_LO | PMP_CS1_POL_LO |\
                   PMP_WRITE_POL_LO | PMP_READ_POL_LO)

  #define MODE     (PMP_IRQ_OFF | PMP_AUTO_ADDR_OFF | PMP_DATA_BUS_8 | PMP_MODE_MASTER2 |\
                   PMP_WAIT_BEG_3 | PMP_WAIT_MID_7 | PMP_WAIT_END_3 )

  #define PORT     (PMP_PEN_ALL)

  #define INT      (PMP_INT_OFF)

                   PMPOpen(CONTROL, MODE, PORT, INT);
  </code>

 ******************************************************************************/
#define mPMPOpen(control, mode, port, interrupt)\
(\
    PMCON = (control), PMMODE = (mode), PMAEN = (port), mPMPClearIntFlag(),\
    mPMPSetIntPriority(((interrupt) & 7)), mPMPSetIntSubPriority((((interrupt)>> 4) & 3)),\
    mPMPIntEnable(((interrupt) >> 15))\
)


    /******************************************************************************
     * Available options for CONTROL parameter
     *****************************************************************************/
        // On/off control - values are mutually exclusive
        #define PMP_ON                              (1 << _PMCON_ON_POSITION)       /* Configure PMP enabled */
        #define PMP_OFF                             (0)                             /* Default */

        /* STOP DURING IDLE control - values are mutually exclusive */
        #define PMP_IDLE_CON                        (0)                             /* Operate during IDLE  - default */
        #define PMP_IDLE_STOP                       (1 << _PMCON_SIDL_POSITION)

        /* PMP Address multiplexing mode - values are mutually exclusive */
        #define PMP_MUX_DATA16_ALL                  (3 << _PMCON_ADRMUX_POSITION)   /* Configure 11 = All 16-bits addrs muxed on 16-bit data */
        #define PMP_MUX_DATA8_ALL                   (2 << _PMCON_ADRMUX_POSITION)   /* Configure 10 = All 16-bits addrs muxed on 8-bit data */
        #define PMP_MUX_DATA8_LOWER                 (1 << _PMCON_ADRMUX_POSITION)   /* Configure 01 = Lower 8-bits addrs muxed on 8-bit data */
        #define PMP_MUX_OFF                         (0)                             /* Default */

        /* PMP Input buffer type  - values are mutually exclusive */
        #define PMP_TTL                             (1 << _PMCON_PMPTTL_POSITION)   /* Configure 1 = TTL inputs */
        #define PMP_ST                              (0)                             /* Configure 0 = Schmidt Trigger inputs - default */

        /* Read and Write Strobes enables - values are mutually exclusive */
        #define PMP_READ_WRITE_EN                   (3 << _PMCON_PTRDEN_POSITION)   /* Configure RD, RD/WR strobe = ON; WR, WR/ENB strobe = ON */
        #define PMP_WRITE_EN                        (2 << _PMCON_PTRDEN_POSITION)   /* Configure WR, WR/ENB strobe = ON */
        #define PMP_READ_EN                         (1 << _PMCON_PTRDEN_POSITION)   /* Configure RD, RD/WR strobe = ON */
        #define PMP_READ_WRITE_OFF                  (0)                             /* Default */

        /* Chip select control - values are mutually exclusive */
        #define PMP_CS2_CS1_EN                      (1 << _PMCON_CSF1_POSITION)     /* Configure 10 = CS1 and CS2 are chip selects */
        #define PMP_CS2_EN                          (1 << _PMCON_CSF0_POSITION)     /* Configure 01 = CS2 = chip select, CS1 = A14 */
        #define PMP_CS2_CS1_OFF                     (0)                             /* Configure 00 = CS2 = A15, CS1 = A14  - default */

        /* PMP Address latch control - values are mutually exclusive */
        #define PMP_LATCH_POL_HI                    (1 << _PMCON_ALP_POSITION)      /* Configure PMALL, PMALH = active high */
        #define PMP_LATCH_POL_LO                    (0)                             /* Configure PMALL, PMALH = active low - default */

        /* CS polarity control - values are mutually exclusive */
        #define PMP_CS2_POL_HI                      (1 << _PMCON_CS2P_POSITION)     /* Configure CS2 polarity = active high */
        #define PMP_CS2_POL_LO                      (0)                             /* Configure CS2 polarity = active low - default */
        #define PMP_CS1_POL_HI                      (1 << _PMCON_CS1P_POSITION)     /* Configure CS1 polarity = active high */
        #define PMP_CS1_POL_LO                      (0)                             /* Configure CS1 polarity = active low - default */

        /* RD/RW/WR/ENB POLARITY bit control - values are mutually exclusive */
        #define PMP_WRITE_POL_HI                    (1 << _PMCON_WRSP_POSITION)     /* Configure Write/ENB strobe polarity = active high */
        #define PMP_WRITE_POL_LO                    (0)                             /* Configure Write/ENB strobe polarity = active low - default */
        #define PMP_READ_POL_HI                     (1 << _PMCON_RDSP_POSITION)     /* Configure Read/RW strobe polarity = active high */
        #define PMP_READ_POL_LO                     (0)                             /* Configure Read/RW strobe polarity = active low */


    /******************************************************************************
     * Available options for MODE parameter
     *****************************************************************************/
        /* PMP interrupt mode - values are mutually exclusive */
        #define PMP_IRQ_BUF_FULL                    (2 << _PMMODE_IRQM_POSITION)    /* Configure Interrupt on buffer full */
        #define PMP_IRQ_READ_WRITE                  (1 << _PMMODE_IRQM_POSITION)    /* Configure Interrupt at end of R/W cycle */
        #define PMP_IRQ_OFF                         (0)

        /* Auto Increment/Decrement FUNCTION SELECTION BITS configuration bit mask defines - values are mutually exclusive */
        #define PMP_AUTO_ADDR_BUFFER                (3 << _PMMODE_INCM_POSITION)    /* Configure 11 = SLAVE R/W buffers auto increment */
        #define PMP_AUTO_ADDR_DEC                   (2 << _PMMODE_INCM_POSITION)    /* Configure 10 = Addrs decrements on every R/W cycle */
        #define PMP_AUTO_ADDR_INC                   (1 << _PMMODE_INCM_POSITION)    /* Configure 01 = Addrs increments on every R/W cycle */
        #define PMP_AUTO_ADDR_OFF                   (0)

        /* MODE16/8 FUNCTION BITS configuration bit mask defines - values are mutually exclusive */
        #define PMP_DATA_BUS_16                     (1 << _PMMODE_MODE16_POSITION)  /* Configure 16-bit data mode */
        #define PMP_DATA_BUS_8                      (0)                             /* Configure 8-bit data mode (default)*/

        /* Master/Slave MODE FUNCTION SELECTION BITS configuration bit mask defines - values are mutually exclusive */
        #define PMP_MODE_MASTER1                    (3 << _PMMODE_MODE_POSITION)    /* Configure MASTER mode 1 */
        #define PMP_MODE_MASTER2                    (2 << _PMMODE_MODE_POSITION)    /* Configure MASTER modw 2 */
        #define PMP_MODE_ESLAVE                     (1 << _PMMODE_MODE_POSITION)    /* Configure SLAVE enhanced mode */
        #define PMP_MODE_SLAVE                      (0)                             /* Configure SLAVE mode */

        /* PMP Beginning phase wait states - values are mutually exclusive */
        #define PMP_WAIT_BEG_4                      (3 << _PMMODE_WAITB_POSITION)   /* Configure 4 Tpb WAIT */
        #define PMP_WAIT_BEG_3                      (2 << _PMMODE_WAITB_POSITION)   /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_BEG_2                      (1 << _PMMODE_WAITB_POSITION)   /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_BEG_1                      (0)                             /* Configure 1 Tpb WAIT */

        /* PMP Middle phase wait states - values are mutually exclusive */
        #define PMP_WAIT_MID_15                     (15 << _PMMODE_WAITM_POSITION)  /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_MID_14                     (14 << _PMMODE_WAITM_POSITION)  /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_MID_13                     (13 << _PMMODE_WAITM_POSITION)  /* Configure 1 Tpb WAIT */
        #define PMP_WAIT_MID_12                     (12 << _PMMODE_WAITM_POSITION)  /* Configure 4 Tpb WAIT */
        #define PMP_WAIT_MID_11                     (11 << _PMMODE_WAITM_POSITION)  /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_MID_10                     (10 << _PMMODE_WAITM_POSITION)  /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_MID_9                      (9 << _PMMODE_WAITM_POSITION)   /* Configure 1 Tpb WAIT */
        #define PMP_WAIT_MID_8                      (8 << _PMMODE_WAITM_POSITION)   /* Configure 4 Tpb WAIT */
        #define PMP_WAIT_MID_7                      (7 << _PMMODE_WAITM_POSITION)   /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_MID_6                      (6 << _PMMODE_WAITM_POSITION)   /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_MID_5                      (5 << _PMMODE_WAITM_POSITION)   /* Configure 1 Tpb WAIT */
        #define PMP_WAIT_MID_4                      (4 << _PMMODE_WAITM_POSITION)   /* Configure 4 Tpb WAIT */
        #define PMP_WAIT_MID_3                      (3 << _PMMODE_WAITM_POSITION)   /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_MID_2                      (2 << _PMMODE_WAITM_POSITION)   /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_MID_1                      (1 << _PMMODE_WAITM_POSITION)   /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_MID_0                      (0)                             /* Configure 1 Tpb WAIT */

        /* PMP end phase wait states - values are mutually exclusive  */
        #define PMP_WAIT_END_4                      (3 << _PMMODE_WAITE_POSITION)   /* Configure 4 Tpb WAIT */
        #define PMP_WAIT_END_3                      (2 << _PMMODE_WAITE_POSITION)   /* Configure 3 Tpb WAIT */
        #define PMP_WAIT_END_2                      (1 << _PMMODE_WAITE_POSITION)   /* Configure 2 Tpb WAIT */
        #define PMP_WAIT_END_1                      (0 << _PMMODE_WAITE_POSITION)   /* Configure 1 Tpb WAIT */

#ifndef _PMAEN_PTEN0_POSITION
        #define _PMAEN_PTEN0_POSITION                    0x00000000
        #define _PMAEN_PTEN0_MASK                        0x00000001
        #define _PMAEN_PTEN0_LENGTH                      0x00000001

        #define _PMAEN_PTEN1_POSITION                    0x00000001
        #define _PMAEN_PTEN1_MASK                        0x00000002
        #define _PMAEN_PTEN1_LENGTH                      0x00000001

        #define _PMAEN_PTEN2_POSITION                    0x00000002
        #define _PMAEN_PTEN2_MASK                        0x00000004
        #define _PMAEN_PTEN2_LENGTH                      0x00000001

        #define _PMAEN_PTEN3_POSITION                    0x00000003
        #define _PMAEN_PTEN3_MASK                        0x00000008
        #define _PMAEN_PTEN3_LENGTH                      0x00000001

        #define _PMAEN_PTEN4_POSITION                    0x00000004
        #define _PMAEN_PTEN4_MASK                        0x00000010
        #define _PMAEN_PTEN4_LENGTH                      0x00000001

        #define _PMAEN_PTEN5_POSITION                    0x00000005
        #define _PMAEN_PTEN5_MASK                        0x00000020
        #define _PMAEN_PTEN5_LENGTH                      0x00000001

        #define _PMAEN_PTEN6_POSITION                    0x00000006
        #define _PMAEN_PTEN6_MASK                        0x00000040
        #define _PMAEN_PTEN6_LENGTH                      0x00000001

        #define _PMAEN_PTEN7_POSITION                    0x00000007
        #define _PMAEN_PTEN7_MASK                        0x00000080
        #define _PMAEN_PTEN7_LENGTH                      0x00000001

        #define _PMAEN_PTEN8_POSITION                    0x00000008
        #define _PMAEN_PTEN8_MASK                        0x00000100
        #define _PMAEN_PTEN8_LENGTH                      0x00000001

        #define _PMAEN_PTEN9_POSITION                    0x00000009
        #define _PMAEN_PTEN9_MASK                        0x00000200
        #define _PMAEN_PTEN9_LENGTH                      0x00000001

        #define _PMAEN_PTEN10_POSITION                   0x0000000A
        #define _PMAEN_PTEN10_MASK                       0x00000400
        #define _PMAEN_PTEN10_LENGTH                     0x00000001

        #define _PMAEN_PTEN11_POSITION                   0x0000000B
        #define _PMAEN_PTEN11_MASK                       0x00000800
        #define _PMAEN_PTEN11_LENGTH                     0x00000001

        #define _PMAEN_PTEN12_POSITION                   0x0000000C
        #define _PMAEN_PTEN12_MASK                       0x00001000
        #define _PMAEN_PTEN12_LENGTH                     0x00000001

        #define _PMAEN_PTEN13_POSITION                   0x0000000D
        #define _PMAEN_PTEN13_MASK                       0x00002000
        #define _PMAEN_PTEN13_LENGTH                     0x00000001

        #define _PMAEN_PTEN14_POSITION                   0x0000000E
        #define _PMAEN_PTEN14_MASK                       0x00004000
        #define _PMAEN_PTEN14_LENGTH                     0x00000001

        #define _PMAEN_PTEN15_POSITION                   0x0000000F
        #define _PMAEN_PTEN15_MASK                       0x00008000
        #define _PMAEN_PTEN15_LENGTH                     0x00000001
#endif

    /******************************************************************************
     * Available options for PORT parameter
     *****************************************************************************/
        /* PMP Port enable control- values are mutually exclusive  */
        #define PMP_PEN_ALL                         (0xFFFF)                        /* Enable All PMA and PMCS PINS*/
        #define PMP_PEN_15                          (1 << _PMAEN_PTEN15_POSITION)   /* Enable Addrs PIN 15 */
        #define PMP_PEN_14                          (1 << _PMAEN_PTEN14_POSITION)   /* Enable Addrs PIN 14 */
        #define PMP_PEN_13                          (1 << _PMAEN_PTEN13_POSITION)   /* Enable Addrs PIN 13 */
        #define PMP_PEN_12                          (1 << _PMAEN_PTEN12_POSITION)   /* Enable Addrs PIN 12 */
        #define PMP_PEN_11                          (1 << _PMAEN_PTEN11_POSITION)   /* Enable Addrs PIN 11 */
        #define PMP_PEN_10                          (1 << _PMAEN_PTEN10_POSITION)   /* Enable Addrs PIN 10 */
        #define PMP_PEN_9                           (1 << _PMAEN_PTEN9_POSITION)    /* Enable Addrs PIN 9 */
        #define PMP_PEN_8                           (1 << _PMAEN_PTEN8_POSITION)    /* Enable Addrs PIN 8 */
        #define PMP_PEN_7                           (1 << _PMAEN_PTEN7_POSITION)    /* Enable Addrs PIN 7 */
        #define PMP_PEN_6                           (1 << _PMAEN_PTEN6_POSITION)    /* Enable Addrs PIN 6 */
        #define PMP_PEN_5                           (1 << _PMAEN_PTEN5_POSITION)    /* Enable Addrs PIN 5 */
        #define PMP_PEN_4                           (1 << _PMAEN_PTEN4_POSITION)    /* Enable Addrs PIN 4 */
        #define PMP_PEN_3                           (1 << _PMAEN_PTEN3_POSITION)    /* Enable Addrs PIN 3 */
        #define PMP_PEN_2                           (1 << _PMAEN_PTEN2_POSITION)    /* Enable Addrs PIN 2 */
        #define PMP_PEN_1                           (1 << _PMAEN_PTEN1_POSITION)    /* Enable Addrs PIN 1 */
        #define PMP_PEN_0                           (1 << _PMAEN_PTEN0_POSITION)    /* Enable Addrs PIN 0 */
        #define PMP_PEN_OFF                         (0)                             /* Disable all */


    /******************************************************************************
     * Available options for INTERRUPT parameter
     *****************************************************************************/
        // PMP interrupt control - values are mutually exclusive
        #define PMP_INT_ON                          (1 << 15)                       /* Interrupt enable/disable bit */
        #define PMP_INT_OFF                         (0)                             /* Interrupt flag position */

        // PMP interrupt priority - values are mutually exclusive
        #define PMP_INT_PRI_7                       (7)                             /* Interrupt Priority 7 */
        #define PMP_INT_PRI_6                       (6)                             /* Interrupt Priority 6 */
        #define PMP_INT_PRI_5                       (5)                             /* Interrupt Priority 5 */
        #define PMP_INT_PRI_4                       (4)                             /* Interrupt Priority 4 */
        #define PMP_INT_PRI_3                       (3)                             /* Interrupt Priority 3 */
        #define PMP_INT_PRI_2                       (2)                             /* Interrupt Priority 2 */
        #define PMP_INT_PRI_1                       (1)                             /* Interrupt Priority 1 */
        #define PMP_INT_PRI_0                       (0)                             /* Interrupt Priority 0 */

        // PMP interrupt sub-priority - values are mutually exclusive
        #define PMP_INT_SUB_PRI_3                   (3 << 4)                        /* Interrupt Sub-Priority 3 */
        #define PMP_INT_SUB_PRI_2                   (2 << 4)                        /* Interrupt Sub-Priority 2 */
        #define PMP_INT_SUB_PRI_1                   (1 << 4)                        /* Interrupt Sub-Priority 1 */
        #define PMP_INT_SUB_PRI_0                   (0 << 4)                        /* Interrupt Sub-Priority 0 */
    /***********************************
     * End parameter values
     ************************************/


/******************************************************************************
 * Parallel Master Port Close Function
 *
 * Macro:           void PMPClose(void)
 *
 * Description:     Disables PMP module, clears PMP interrupt enable and PMP
 *                  interrupt flag.
 *
 * Inputs:          None
 *
 * Returns:          None
 *
 * Example:         PMPClose();
 *
 *****************************************************************************/
#define mPMPClose()     (    mPMPIntEnable(0), mPMPDisable(), mPMPClearIntFlag())


/******************************************************************************
 * Parallel Master Port Set Address Function
 *
 * Function:        PMPSetAddress(unsigned short)
 *
 * PreCondition:    None
 *
 * Parameters:           (unsigned short) addrs
 *
 * Returns:          None
 *
 * Example:         PMPSetAddress(0x4800);
 *
 * Note             Copies argument #1 into the PMADDR register.
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPSetAddress( unsigned int addrs )
{
    while(mIsPMPBusy());
    PMADDR = addrs;
}

/******************************************************************************
 * Parallel Master Port Read Byte Macro
 *
 * Macro:           mPMPMasterReadByte ()
 *
 * PreCondition:    None
 *
 * Parameters:           None
 *
 * Returns:          (unsigned char) value
 *
 * Example:         value = mPMPMasterReadByte();
 *
 * Remarks:            This macro calls function PMPMasterRead() and casts return
 *                  value = unsigned char
 *
 *****************************************************************************/
#define mPMPMasterReadByte()             ((unsigned char) PMPMasterRead())


/******************************************************************************
 * Parallel Master Port Read Word Macro
 *
 * Macro:           mPMPMasterReadWord ()
 *
 * PreCondition:    None
 *
 * Parameters:           None
 *
 * Returns:          (unsigned short) value
 *
 * Example:         value = mPMPMasterReadWord();
 *
 * Remarks:            This macro calls function PMPMasterRead() and casts return
 *                  value = unsigned word
 *
 *****************************************************************************/
#define mPMPMasterReadWord()             ((unsigned short) PMPMasterRead())

/******************************************************************************
 * Parallel Master Port Master mode I,II Read Function
 *
 * Function:        unsigned int PMPMasterRead(void)
 *
 * PreCondition:    None
 *
 * Parameters:           None
 *
 * Returns:          (unsigned int) - Returns the current contents of PMDIN register
 *
 * Example:         value = PMPMasterRead();
 *
 * Remarks:            Returns the current contents of PMDIN register
 *
 *                  Note 1: This function is blocking while the PMMODE busy flag
 *                  is being polled.
 *
 *                  Note 2: Due to the architecture of the PMP module, the data
 *                  obtained from the PMDIN register is actually the latched value
 *                  from the previous read operation.  Refer to the PIC32MX Family
 *                  Reference Manual for further details regarding this behavior.
 *
 *                  Note 3: Depending on the PMP mode, the data could be 8-bit or 16-bit.
 *                  However, the value returned is always 32-bits wide (unsigned int).
 *                  For example, in 8-bit mode, a value of 0xFF read from an external
 *                  device will be returned from this function as 0x000000FF.
 *                  Likewise, in 16-bit mode, a value of 0xFFFF read from an external
 *                  device will be returned as 0x0000FFFF.
 *
 *                  Note 3: Use macros mPMPMasterReadWord or mPMPMasterReadByte to
 *                  provide a return value cast to the appropriate size.
 *                  mPMPMasterReadWord and mPMPMasterReadByte call PMPMasterRead().
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern inline unsigned int __attribute__((always_inline)) 
PMPMasterRead( void )
{
    while(mIsPMPBusy());
    return(PMDIN);
}

/******************************************************************************
 * Parallel Master Port Read a block of bytes (8-bit)
 *
 * Function:        void PMPMasterReadByteBlock(unsigned int, unsigned int,
 *                                              unsigned char*)
 *
 * PreCondition:    None
 *
 * Parameters:
                    Argument #1 (unsigned int) addrs = starting address
 *                  Argument #2 (unsigned int) bytes = number of bytes to read
 *                  Argument #3 (unsigned char*) pDest = byte data destination
 *
 * Returns:          None
 *
 * Example:         PMPMasterReadByteBlock(0x6400, 32, &myArray);
 *
 * Remarks:            Reads N bytes (argument #2) starting at location specified
 *                  in (argument #1) and stores the data at destination
 *                  specified by byte pointer (argument #3)
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern __inline__ void __attribute__((always_inline)) 
PMPMasterReadByteBlock( unsigned int addrs, unsigned int bytes, unsigned char* pDest )
{

    unsigned int ix, incMode;

    while(mIsPMPBusy());

    // Save PMMODE.INCM bits so they can be restored later
    incMode = (PMMODE & 0x1800);

    // Temporarily switch to auto-inc mode for efficiency
    PMMODESET = 0x0800;

    for(ix=0; ix < bytes; ix++)
	{
        if(ix == 0)
        {
            // Setup the initial address
            PMPSetAddress(addrs);
            // trash old data/latch new data at initial address
            PMPMasterRead();
        }
        else
        {
            // Read previous data and latch new data
            *pDest++ = PMPMasterRead();
        }
    }
    // Must read the last latched value
    *pDest = PMPMasterRead();

    // Restore the previous inc mode
    PMMODECLR = 0x1800;
    PMMODESET = incMode;
}

/******************************************************************************
 * Parallel Master Port Read a block of words (16-bit)
 *
 * Function:        void PMPMasterReadWordBlock(unsigned int, unsigned int,
 *                                              unsigned short*)
 *
 * PreCondition:    None
 *
 * Parameters:
                    Argument #1 (unsigned int) addrs = starting address
 *                  Argument #2 (unsigned int) words = number of words to read
 *                  Argument #3 (unsigned short*) pDest = word data destination
 *
 * Returns:          None
 *
 * Example:         PMPMasterReadWordBlock(0x6400, 16, &myArray);
 *
 * Remarks:            Reads N words (argument #2) starting at location specified
 *                  in (argument #1) and stores the data at destination
 *                  specified by byte pointer (argument #3)
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern __inline__ void __attribute__((always_inline)) 
PMPMasterReadWordBlock( unsigned int addrs, unsigned int words, unsigned short* pDest )
{
    unsigned int ix, incMode;

    while(mIsPMPBusy());

    // Save PMMODE.INCM bits so they can be restored later
    incMode = (PMMODE & 0x1800);

    // Temporarily switch to auto-inc mode for efficiency
    PMMODESET = 0x0800;

    for(ix=0; ix < words; ix++)
	{
        if(ix == 0)
        {
            // Setup the initial address
            PMPSetAddress(addrs);
            // trash old data/latch new data at initial address
            PMPMasterRead();
        }
        else
        {
            // Read previous data and latch new data
            *pDest++ =  PMPMasterRead();
        }
    }
    // Must read the last latched value
    *pDest = PMPMasterRead();

    // Restore the previous inc mode
    PMMODECLR = 0x1800;
    PMMODESET = incMode;
}

/******************************************************************************
 * Parallel Master Port Master mode I,II Write Function
 *
 * Function:        void PMPMasterWrite(unsigned int)
 *
 * PreCondition:    None
 *
 * Parameters:
                    Argument #1 (unsigned int) value to be written to PMDIN register
 *
 * Returns:         None
 *
 * Example:         PMPMasterWrite(0xAA);
 *
 * Remarks:         In 8-bit data mode, the 8-bits of data appear on the lower 8
 *                  data lines while the upper 8-bits are not used.
 *                  In 16-bit data mode, the lower 8-bits appear on the lower 8
 *                  data lines and the upper 8-bits of data appear on the upper
 *                  8 data lines.
 *
 *                  Note 1: This function is blocking while the PMMODE busy flag
 *                  is being polled.
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPMasterWrite( unsigned short value )
{
    while(mIsPMPBusy());
    PMDIN = value;
}

/******************************************************************************
 * Parallel Master Port Write a block of bytes (8-bit)
 *
 * Function:        void PMPMasterWriteByteBlock(unsigned int, unsigned int,
 *                                               unsigned char*)
 *
 * PreCondition:    None
 *
 * Parameters:
                    (unsigned int) addrs - starting address
 *                  (unsigned int) bytes - number of bytes to read
 *                  (unsigned char*) source - byte data destination
 *
 * Returns:          None
 *
 * Example:         PMPMasterWriteByteBlock(0x8000, 0x800, &myArray);
 *
 * Overview:        Writes N bytes (argument #2) starting at location specified
 *                  in (argument #1), from the destination specified by
 *                  byte pointer (argument #3)
 *
 * Remarks:            Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPMasterWriteByteBlock( unsigned int addrs, unsigned int bytes, unsigned char* source )
{
    unsigned int ix, incMode;

    while(mIsPMPBusy());

    // Save PMMODE.INCM bits so they can be restored later
    incMode = (PMMODE & 0x1800);

    // Temporarily switch to auto-inc mode for efficiency
    PMMODESET = 0x0800;

    PMPSetAddress(addrs);

    for(ix=0; ix < bytes; ix++)
        PMPMasterWrite(*source++);

    // Restore the previous inc mode
    PMMODECLR = 0x1800;
    PMMODESET = incMode;
}

/******************************************************************************
 * Parallel Master Port Write a block of words (16-bit)
 *
 * Function:        void PMPMasterWriteWordBlock(unsigned int, unsigned int,
 *                                               unsigned short*)
 *
 * PreCondition:    None
 *
 * Parameters:
                    Argument #1 (unsigned int) addrs = starting address
 *                  Argument #2 (unsigned int) words = number of words to write
 *                  Argument #3 (unsigned char*) source = word data destination
 *
 * Returns:          None
 *
 * Example:         PMPMasterWriteWordBlock(0x8000, 16, &myArray);
 *
 * Remarks:            Writes N words (argument #2) starting at location specified
 *                  in (argument #1), from the destination specified by
 *                  word pointer (argument #3).
 *
 *                  Use in MASTER mode 1 or 2, MODE[1:0] = 10, 11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPMasterWriteWordBlock( unsigned int addrs, unsigned int words, unsigned short* source )
{
    unsigned int ix, incMode;

    while(mIsPMPBusy());

    // Save PMMODE.INCM bits so they can be restored later
    incMode = (PMMODE & 0x1800);

    // Temporarily switch to auto-inc mode for efficiency
    PMMODESET = 0x0800;

    PMPSetAddress(addrs);

    for(ix=0; ix < words; ix++)
        PMPMasterWrite(*source++);

    // Restore the previous inc mode
    PMMODECLR = 0x1800;
    PMMODESET = incMode;
}

/******************************************************************************
 * Parallel Master Port Read Slave Buffer Function
 *
 * Function:        unsigned int PMPSlaveReadBuffer(enum BUFFER)
 *
 * PreCondition:    None
 *
 * Parameters:           (enum BUFFER) 0..3
 *
 * Returns:          The value in selected buffer register.
 *
 * Example:         value = PMPSlaveReadBuffer(BUF0);
 *
 * Remarks:            Reads the value in PMDIN register.
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00 and INCM[1:0]=11
 *                  or SLAVE ENHANCED mode, MODE[1:0] = 01
 *****************************************************************************/
extern inline unsigned char __attribute__((always_inline)) 
PMPSlaveReadBuffer( BUFFER buf )
{
    volatile unsigned char* pReg;

    pReg = (volatile unsigned char*) &PMDIN;
	return  (*(pReg += buf));
}

/******************************************************************************
 * Parallel Master Port Read Enhanced Slave Buffers Function
 *
 * Function:        void PMPSlaveReadBuffers(unsigned char*)
 *
 * PreCondition:    None
 *
 * Parameters:           (unsigned char* ) pointer to destination array
 *
 * Returns:          The contents of the (4) 8-bit slave buffer registers.
 *
 * Example:         PMPSlaveReadBuffers(&myArray);
 *
 * Remarks:            Copies 4 bytes from DATAIN buffers to a starting location
 *                  pointed to by input parameter.
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00 and INCM[1:0]=11
 *                  or SLAVE ENHANCED mode, MODE[1:0] = 01
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPSlaveReadBuffers( unsigned char* pDest )
{
	volatile unsigned char* pReg;

    pReg = (volatile unsigned char*) &PMDIN;    // assign pointer to PMDIN register

    *pDest++ = *pReg++;                         // copy first buffer
    *pDest++ = *pReg++;                         // copy second buffer
    *pDest++ = *pReg++;                         // copy third buffer
    *pDest =   *pReg;                           // and copy the last buffer
}

/******************************************************************************
 * Parallel Master Port Write Slave Buffer Function
 *
 * Function:        void PMPSlaveWriteBuffer(enum BUFFER, unsigned char)
 *
 * PreCondition:    None
 *
 * Parameters:           Argument #1 (enum BUFFER) = 0..3
 *                  Argument #2 (unsigned char) = value to be written
 *
 * Returns:          None
 *
 * Example:         PMPSlaveWriteBuffer(BUF2, 0x88);
 *
 * Remarks:            Writes the desired value into the selected output buffer.
 *                  This function does not check or modify the OBUF bit and
 *                  therefore it is the user's responsibility to check for
 *                  an overflow condition.
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *                  or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPSlaveWriteBuffer( BUFFER buf, unsigned char value )
{
    volatile unsigned char* pReg;

    pReg =  (volatile unsigned char*) &PMDOUT;          // assign byte pointer
    *(pReg += buf) = value;
}

/******************************************************************************
 * Parallel Master Port Write Enhanced Slave Buffers Function
 *
 * Function:        void PMPSlaveWriteBuffers(unsigned char*)
 *
 * PreCondition:    None
 *
 * Parameters:           (unsigned char*) source = pointer to data
 *
 * Returns:          None
 *
 * Example:         PMPSlaveWriteBuffers(&myArray);
 *
 * Remarks:            Copies 4 bytes, addressed by the pointer argument #1, into
 *                  the corresponding PMDOUT registers.
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00
 *                  or SLAVE ENHANCED mode, MODE[1:0] = 00  and INCM[1:0]=11
 *****************************************************************************/
extern inline void __attribute__((always_inline)) 
PMPSlaveWriteBuffers( unsigned char* source )
{
	volatile unsigned char* pDest;

	pDest = (volatile unsigned char*) &PMDOUT;

    *pDest++ = *source++;
    *pDest++ = *source++;
    *pDest++ = *source++;
    *pDest =   *source;
}

/******************************************************************************
 * Parallel Master Port Read Slave Macro
 *
 * Macro:           mPMPSlaveRead ()
 *
 * PreCondition:    None
 *
 * Parameters:           None
 *
 * Returns:          8-bit value in slave buffer register
 *
 * Example:         value = mPMPSlaveRead();
 *
 * Remarks:
                    Reads the value in PMDIN register
 *
 *                  Note 1: This macro does not check the status of the
 *                  PMSTAT.IBF (input buffer full) bit prior to reading the
 *                  PMDIN register.  It is recommended that the user's software
 *                  verify PMSTAT.IBF = 1 prior to reading the PMDIN register.
 *
 *                  Note 2: If an external master write occurs before the current
 *                  contents of the PMDIN register is performed, the IBOV flag
 *                  will be set, indicating an overflow.  This function does
 *                  not check or modify the IBOV bit.  Therefore it should the
 *                  user's responsibility to check for an overflow condition.
 *
 *                  Use in SLAVE LEGACY mode, MODE[1:0] = 00
 *****************************************************************************/
#define mPMPSlaveRead()             (PMDIN)

/******************************************************************************
 * Parallel Master Port Slave Write Macro
 *
 * Macro:           mPMPSlaveWrite(unsigned char)
 *
 * PreCondition:    None
 *
 * Parameters:           (unsigned char) - _value
 *
 * Returns:         None
 *
 * Example:         mPMPSlaveWrite(0x20);
 *
 * Remarks:
                    Writes argument #1 into PMDOUT register.
 *
 *                  Note 1: This function does not check the status of the
 *                  PMSTAT.OBE (output buffer empty) bit prior to writing to the
 *                  PMDOUT register.  It is recommended that the user's software
 *                  verify PMSTAT.OBE = 1 prior to writing the PMDOUT register.
 *
 *                  Use in SLAVE LEGACY mode, MODE[1:0] = 00
 *****************************************************************************/
#define mPMPSlaveWrite(_value)              (PMDOUT = (unsigned char) (_value))

/******************************************************************************
 * Parallel Master Port Slave mode general purpose macros
 *
 * Macros:
 *          To read Slave Output Buffer Empty Flags
 *                  mIsPMPSlaveBufferEmpty(void)
 *                  mPMPGetBufferEmptyFlags((enum BUFFER) _buffer)
 *
 *          To read Slave Input Buffer Full Flags
 *                  mIsPMPSlaveBufferFull(void)
 *                  mPMPGetBufferFullFlags((enum BUFFER) _buffer)
 *
 *          To read/clear Slave Output Buffer Underflow Flags
 *                  mIsPMPSlaveBufferUnderflow(void)
 *                  mPMPClearBufferUnderflow(void)
 *
 *          To read/clear Slave Input Buffer Overflow Flags
 *                  mIsPMPSlaveBufferOverflow(void)
 *                  mPMPClearBufferOverflow(void)
 *
 * PreCondition:    None
 *
 * Parameters:      Depends
 *
 * Returns:          None
 *
 * Example:         mPMPClearBufferOverflowFlag();
 *
 *                  Use in SLAVE BUFFERED mode, MODE[1:0] = 00 and INCM[1:0]=11
 *                  or SLAVE ENHANCED mode, MODE[1:0] = 01
 *****************************************************************************/
#define mIsPMPSlaveBufferFull()                 (PMSTATbits.IBF)
#define mPMPGetBufferFullFlags(_buffer)         ((PMSTAT & (1 << ((BUFFER) (_buffer) + 8)))\
                                                >> ((BUFFER) (_buffer) + 8))
#define mIsPMPSlaveBufferOverflow()             (PMSTATbits.IBOV)
#define mPMPClearBufferOverflow()               (PMSTATCLR = _PMSTAT_IBOV_MASK)

#define mIsPMPSlaveBufferEmpty()                (PMSTATbits.OBE)
#define mPMPGetBufferEmptyFlags(_buffer)        ((PMSTAT & (1 << (BUFFER )(_buffer)))\
                                                >> (BUFFER) (_buffer))
#define mIsPMPSlaveBufferUnderflow()            (PMSTATbits.OBUF)
#define mPMPClearBufferUnderflow()              (PMSTATCLR = _PMSTAT_OBUF_MASK)


#ifdef	__cplusplus
}
#endif

#endif	/* PMP_H */

