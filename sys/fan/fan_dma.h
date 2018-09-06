/*
		FileName: dma.h
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

#ifndef DMA_H
#define	DMA_H

#include <xc.h>
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define _DMA_CHANNELS       // DMA channels exist

// common DMA definitions

// translation macros to use the definitions of the available channel
// assumption that DMA channel 0 is always available

// __DCHxREGbits_t definition
#define _DCH_REG_BITS_(x, REG)		__DCH ## x ## REG ## bits_t
#define _X_DCH_REG_BITS_(x, REG)	_DCH_REG_BITS_(x, REG)		// concat macro

#define __DCHxCONbits_t			_X_DCH_REG_BITS_(0, CON)
#define __DCHxECONbits_t		_X_DCH_REG_BITS_(0, ECON)
#define __DCHxINTbits_t			_X_DCH_REG_BITS_(0, INT)



// corresponding reg masks definitions
#define _DCH_REG_MASK_(x, REG, m)	_DCH ## x ## REG ##_ ## m
#define _X_DCH_REG_MASK_(x, REG, m)	_DCH_REG_MASK_(x, REG, m)			// concat macro


#define __DCHxCON_MASK_(m)		_X_DCH_REG_MASK_(0, CON, m)
#define __DCHxECON_MASK_(m)		_X_DCH_REG_MASK_(0, ECON, m)
#define __DCHxINT_MASK_(m)		_X_DCH_REG_MASK_(0, INT, m)

#define __DCHxINT_w_MASK                            0xFFFFFFFF
#define __DCHxINT_CHERIF_MASK                       _DCH0INT_CHERIF_MASK   
#define __DCHxINT_CHTAIF_MASK                       _DCH0INT_CHTAIF_MASK 
#define __DCHxINT_CHCCIF_MASK                       _DCH0INT_CHCCIF_MASK
#define __DCHxINT_CHBCIF_MASK                       _DCH0INT_CHBCIF_MASK 
    
// DMA Interrupt Channel.
#define INT_SOURCE_DMA(chn)             /*DOM-IGNORE-BEGIN*/(INT_SOURCE_DMA_0 + (chn))          /*DOM-IGNORE-END*/

typedef struct
{
	// DCHxCON
    union {
	__DCHxCONbits_t	con;
    unsigned int    con_w;
    };
	unsigned int	conClr;
	unsigned int	conSet;
	unsigned int	conInv;
	// DCHxECON
    union {
	__DCHxECONbits_t econ;
    unsigned int    econ_w;
    };
	unsigned int 	econClr;
	unsigned int 	econSet;
	unsigned int 	econInv;
	// DCHxINT
    union {
	__DCHxINTbits_t	intr;
    unsigned int    intr_w;
    };
	unsigned int	intrClr;
	unsigned int	intrSet;
	unsigned int	intrInv;
	// DCHxSSA
	unsigned int	ssa;
	unsigned int	ssaClr;
	unsigned int	ssaSet;
	unsigned int	ssaInv;
	// DCHxDSA
	unsigned int	dsa;
	unsigned int	dsaClr;
	unsigned int	dsaSet;
	unsigned int	dsaInv;
	// DCHxSSIZ
	unsigned int	ssiz;
	unsigned int	ssizClr;
	unsigned int	ssizSet;
	unsigned int	ssizInv;
	// DCHxDSIZ
	unsigned int	dsiz;
	unsigned int	dsizClr;
	unsigned int	dsizSet;
	unsigned int	dsizInv;
	// DCHxSPTR
	unsigned int	sptr;
	unsigned int	sptrClr;
	unsigned int	sptrSet;
	unsigned int	sptrInv;
	// DCHxDPTR
	unsigned int	dptr;
	unsigned int	dptrClr;
	unsigned int	dptrSet;
	unsigned int	dptrInv;
	// DCHxCSIZ
	unsigned int	csiz;
	unsigned int	csizClr;
	unsigned int	csizSet;
	unsigned int	csizInv;
	// DCHxCPTR
	unsigned int	cptr;
	unsigned int	cptrClr;
	unsigned int	cptrSet;
	unsigned int	cptrInv;
	// DCHxDAT
	unsigned int	dat;
	unsigned int	datClr;
	unsigned int	datSet;
	unsigned int	datInv;
}_DmaRegMap;		// layout of the DMA registers
// NOTE: The layout of this structure is the same as the physical layout of a channel registers!




#define		DMA_EVENT_MASK		(__DCHxECON_MASK_(CHAIRQ_MASK)|__DCHxECON_MASK_(CHSIRQ_MASK)|__DCHxECON_MASK_(PATEN_MASK)|__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK))
								// mask in DCHxECON that preserves just the events and deletes the CFORCE and CABORT

#define		DMA_IFLAG_MASK		(__DCHxINT_MASK_(CHERIF_MASK)|__DCHxINT_MASK_(CHTAIF_MASK)|__DCHxINT_MASK_(CHCCIF_MASK)|__DCHxINT_MASK_(CHBCIF_MASK)| \
								__DCHxINT_MASK_(CHDHIF_MASK)|__DCHxINT_MASK_(CHDDIF_MASK)|__DCHxINT_MASK_(CHSHIF_MASK)|__DCHxINT_MASK_(CHSDIF_MASK))
								// mask in DCHxINT that keeps just the int flags




#define		_DmaChnWaitAbort(pReg)	while((pReg)->econ.CABORT)		// waiting for the channel operation to be aborted procedure
#define		_DmaChnWaitStop(pReg)	while((pReg)->con.CHBUSY)		// waiting for the channel to stop    
    
    
    
// existent DMA channels
    typedef enum
    {
        DMA_CHANNEL0 = 0,
        DMA_CHANNEL1,
        DMA_CHANNEL2,
        DMA_CHANNEL3,
        DMA_CHANNEL4,
        DMA_CHANNEL5,
        DMA_CHANNEL6,
        DMA_CHANNEL7,
        DMA_CHANNELS        // number of current available channels
    }DmaChannel;


    // Relative Dma channels priority, between each other
    typedef enum
    {
        DMA_CHN_PRI0,
        DMA_CHN_PRI1,
        DMA_CHN_PRI2,
        DMA_CHN_PRI3
    }DmaChannelPri;


    // high level definitions for the API functions

    typedef enum
    {
        DMA_OPEN_DEFAULT = 0,                                   // DMA default operation
        DMA_OPEN_AUTO   = _DCH0CON_CHAEN_MASK,                  // DMA channel is auto enabled
        DMA_OPEN_CHAIN_LOW  = (_DCH0CON_CHCHN_MASK|_DCH0CON_CHCHNS_MASK),   // DMA channel is chained to lower channel
        DMA_OPEN_CHAIN_HI  = (_DCH0CON_CHCHN_MASK),             // DMA channel is chained to higher channel
        DMA_OPEN_DET_EN = _DCH0CON_CHAED_MASK,                  // events detection enabled while channel off
        DMA_OPEN_ENABLE = _DCH0CON_CHEN_MASK,                   // DMA channel is enabled after open
        DMA_OPEN_MATCH  = 0x80000000,                           // DMA channel stops on match
    }DmaOpenFlags;  // flags for the channel open


    typedef enum
    {
        DMA_EV_ERR =            0x1,        // address error event
        DMA_EV_ABORT =          0x2,        // transfer abort event
        DMA_EV_CELL_DONE =      0x4,        // cell transfer complete event
        DMA_EV_BLOCK_DONE =     0x8,        // block transfer complete event
        DMA_EV_DST_HALF =       0x10,       // destination half event
        DMA_EV_DST_FULL =       0x20,       // destination full event
        DMA_EV_SRC_HALF =       0x40,       // source half event
        DMA_EV_SRC_FULL =       0x80,       // source full event

        DMA_EV_ALL_EVNTS=       (DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_CELL_DONE|DMA_EV_BLOCK_DONE|DMA_EV_DST_HALF|
                                    DMA_EV_DST_FULL|DMA_EV_SRC_HALF|DMA_EV_SRC_FULL)                // all available events
    }DmaEvFlags;    // flags for controlling the DMA channel events; Bit fields from the processor header file.


    typedef enum
    {
        DMA_TXFER_OK,           // the transfer was performed successfully
        DMA_TXFER_ADD_ERR,      // address error while performing the transfer
        DMA_TXFER_ABORT,        // the DMA transfer was aborted
        DMA_TXFER_BC_ERR,       // block complete not set after the DMA transfer performed
        DMA_TXFER_CC_ERR,       // cell complete not set after the DMA transfer performed
        DMA_TXFER_TMO           // DMA transfer timeout
    }DmaTxferRes;       // DMA transfer result

    typedef enum
    {
        DMA_WAIT_NOT,       // don't wait for the transfer to complete, return immediately
        DMA_WAIT_CELL,      // wait for the cell transfer to complete, than return
        DMA_WAIT_BLOCK      // wait for the block transfer to complete, than return
    }DmaWaitMode;       // DMA transfer wait mode

    typedef enum
    {
        DMA_CHKSUM_CRC,     // LFSR CRC
        DMA_CHKSUM_IP,      // IP Checksum
    }DmaChksumType;     // DMA SFM supported checksum types

    typedef enum
    {
        DMA_BITO_MSb,       // MSb first (not reflected)
        DMA_BITO_LSb,       // LSb first (reflected)
    }DmaBitOrder;       // DMA SFM supported bit ordering

    typedef enum
    {
        DMA_REORDER_NOT,    // no reordering, destination matches the source
        DMA_REORDER_ENDIAN, // change endianess on word (32 bit) boundaries: LE<->BE
        DMA_REORDER_SWAP_HALF,  // swap half words (16 bit) within word (32 bit)
        DMA_REORDER_SWAP_BYTE,  // swap bytes within half word (16 bit)
    }DmaReorderMode;    // DMA SFM supported re-ordering modes


// common local inline functions
/*********************************************************************
 * Function:        unsigned int _VirtToPhys(const void* p)
 *
 * PreCondition:    None
 *
 * Input:           p   - pointer to be converted.
 *
 * Output:          a physical address corresponding to the virtual input pointer
 *
 * Side Effects:    None
 *
 * Overview:        Virtual to physical translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
_VirtToPhys(const void* p)
{
    return (int)p<0?((int)p&0x1fffffffL):(unsigned int)((unsigned char*)p+0x40000000L);
}

/*********************************************************************
 * Function:        void* _PhysToVirtK0(unsigned int a)
 *
 * PreCondition:    None
 *
 * Input:           a   - address to be converted.
 *
 * Output:          a virtual pointer corresponding to the physical input address
 *
 * Side Effects:    None
 *
 * Overview:        Physical to virtual translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void* __attribute__((always_inline)) 
_PhysToVirtK0(unsigned int a)
{
    return a<0x40000000L?(void*)(a|0x80000000L):(void*)(a-0x40000000L);
}

/*********************************************************************
 * Function:        void* _PhysToVirtK1(unsigned int a)
 *
 * PreCondition:    None
 *
 * Input:           a   - address to be converted.
 *
 * Output:          a virtual pointer corresponding to the physical input address
 *
 * Side Effects:    None
 *
 * Overview:        Physical to virtual translation helper.
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void* __attribute__((always_inline)) 
_PhysToVirtK1(unsigned int a)
{
    return a<0x40000000L?(void*)(a|0xa0000000L):(void*)(a-0x40000000L);
}



/*********************************************************************
 * Function:        void _DmaChnInitOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Makes sure the DMA controller is on and running
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
_DmaChnInitOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);    // abort channel
        DMACONCLR=_DMACON_SUSPEND_MASK;     // unsuspend
        DMACONSET=_DMACON_ON_MASK;      // make sure it's on
    _DmaChnWaitAbort(pReg);         // wait operation abort

}

/*********************************************************************
 * Function:        void _DmaChnAbortOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Does not turn on the DMA controller, does not unsuspend
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
_DmaChnAbortOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);        // abort
        _DmaChnWaitAbort(pReg);             // wait abort
}

/*********************************************************************
 * Function:        void _DmaChnOpenOp(_DmaRegMap* pReg)
 *
 * PreCondition:    None
 *
 * Input:       None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        Aborts the current operation on the specified channel.
 *          Turns on the DMA controller but does not perform unsuspend
 *
 * Note:            None.
 ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
_DmaChnOpenOp(volatile _DmaRegMap* pReg)
{
    pReg->econSet=__DCHxECON_MASK_(CABORT_MASK);        // abort
        DMACONSET=_DMACON_ON_MASK;          // make sure it's on
    _DmaChnWaitAbort(pReg);             // wait abort
}    
    
    
    /*********************************************************************
     * Function:        void DmaChnOpen(DmaChannel chn, DmaChannelPri chPri, DmaOpenFlags oFlags)
     *
     * PreCondition:    chPri  - valid channel priority, 0-3
     *
     * Input:           chn    - channel to be configured in the DMA controller
     *                  chPri  - the priority given to the channel, 0-3
     *                  oFlags - orred flags specifying the open mode:
     *                           DMA_OPEN_DEFAULT: DMA default operation mode
     *                           DMA_OPEN_AUTO: DMA channel is auto enabled
     *                           DMA_OPEN_CHAIN_LOW: DMA channel is chained to lower channel
     *                           DMA_OPEN_CHAIN_HI: DMA channel is chained to higher channel
     *                           DMA_OPEN_DET_EN: events detection enabled while channel off
     *                           DMA_OPEN_ENABLE: DMA channel is enabled when opened
     *                           DMA_OPEN_MATCH:    DMA channel stops on match
     *
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function opens and configures the selected DMA channel using the supplied user flags and priority.
     *
     * Note:            - This is a high level access function that doesn't give access to all the settings possible for a DMA channel.
     *                  Use the low level functions to address special settings.
     *                  - The channel is turned off, the pending interrupts are cleared, interrupts are disabled.
     *                  After that the channel is configured.
     *                  - After calling this function, the channel should be enabled using DmaChnEnable(chn) call
     *                  if DMA_OPEN_ENABLE flag was not specified.
     *                  - If the CRC is attached to the submitted channel, the CRC append mode will be turned off.
     *                  This way, the transfer will occur correctly together with CRC calculation.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  User has to call event channel functions to enable the event flags if needed.
     *
     * Example:         DmaChnOpen(DMA_CHANNEL2, DMA_CHN_PRI2, DMA_OPEN_AUTO|DMA_OPEN_MATCH|DMA_OPEN_ENABLE);
     ********************************************************************/
 extern __inline__ void __attribute__((always_inline)) 
 DmaChnOpen( DmaChannel chn, DmaChannelPri chPri, DmaOpenFlags oFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;
	unsigned int crcCon;

	INTEnable(INT_SOURCE_DMA(chn), INT_DISABLED);           // disable the channel interrupts
	_DmaChnOpenOp(pReg);                                    // abort operation, DMA controller ON
	
	
	crcCon = DCRCCONbits.CRCCH;                             // read current CRC control word
	if(crcCon == chn)
	{
		DCRCCONCLR = _DCRCCON_CRCAPP_MASK;                  // clear append mode
	}


	pReg->econClr = __DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK);		// disable start and abort irqs, no pattern enabled
	
	pReg->intrClr = __DCHxINT_w_MASK;                       // disable events, clear existing flags

	INTClearFlag(INT_SOURCE_DMA(chn));                      // clear the existing channel interrupt flags
	
	if(oFlags&DMA_OPEN_MATCH)
	{
		pReg->econSet = __DCHxECON_MASK_(PATEN_MASK);
	}
	
	pReg->con_w = (chPri & __DCHxCON_MASK_(CHPRI_MASK))|(oFlags&(~DMA_OPEN_MATCH));	// set the control word
}

    /*********************************************************************
     * Function:        void DmaChnEnable(DmaChannel chn)
     *
     * PreCondition:    None
     *
     * Input:           chn     - channel to be enabled
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables a previously configured DMA channel.
     *
     * Note:            DmaChnOpen()/DmaChnConfigure() should have been called before.
     *
     * Example:         DmaChnEnable(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnEnable( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->conSet =__DCHxCON_MASK_(CHEN_MASK);	// enable the channel
}

    /*********************************************************************
     * Function:        void DmaChnDisable(DmaChannel chn)
     *
     * PreCondition:    None
     *
     * Input:           chn     - selected channel in the DMA controller
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function disables a DMA channel. The channel operation stops.
     *
     * Note:            None.
     *
     * Example:         DmaChnDisable(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnDisable( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	pReg->conClr=__DCHxCON_MASK_(CHEN_MASK);	// disable the channel
	_DmaChnWaitStop(pReg);			// wait to actually stop
}
    
    /*********************************************************************
     * Function:        void DmaChnSetTxfer(DmaChannel chn, const void* vSrcAdd, void* vDstAdd, int srcSize, int dstSize, int cellSize)
     *
     * PreCondition:    chn     - valid DMA channel
     *              - vSrcAdd, vDstAdd  - valid pointers
     *                              - 0 < srcSize <= DmaGetMaxTxferSize()
     *                              - 0 < dstSize <= DmaGetMaxTxferSize()
     *                              - 0 < cellSize <= DmaGetMaxTxferSize()
     *
     * Input:           chn         - DMA channel number
     *                              - vSrcAdd: source of the DMA transfer
     *                              - vDstAdd: destination of the DMA transfer
     *                              - srcSize: source buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped arround
     *                              - dstSize: destination buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped around
     *                              - cellSize: cell transfer size, 1 to DmaGetMaxTxferSize() bytes.
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the transfer characteristics for a DMA channel transfer:
     *                  the source and the destination addresses.
     *                  the source and destination lengths
     *                  and the number of bytes transferred per event.
     *
     * Note:            The function clears the existing DMA channel event flags.
     *                  The source to destination byte re-ordering is affected by DmaSfmConfigure(), DmaSfmTxferReorder().
     *
     * Example:         DmaChnSetTxfer(DMA_CHANNEL3, &U2RXREG, dstBuff, 1, 200, 1);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetTxfer( DmaChannel chn, const void* vSrcAdd, void* vDstAdd, int srcSize, int dstSize, int cellSize )   
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	pReg->ssa = _VirtToPhys(vSrcAdd);		// set src address
	pReg->dsa = _VirtToPhys(vDstAdd);		// set dst address

	pReg->ssiz = srcSize;                   // set src size
	pReg->dsiz = dstSize;                   // set dst size
	pReg->csiz = cellSize;                  // set transfer (cell) size

	pReg->intrClr = DMA_IFLAG_MASK;	// clear any previous set flags	
}   
    
    /*********************************************************************
     * Function:        void DmaChnSetSrcAdd(DmaChannel chn, const void* vSrcAdd)
     *
     * PreCondition:    chn     - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *              - vSrcAdd: source (virtual) of the DMA transfer
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function is a helper to set directly the transfer source address.
     *
     * Note:            None.
     *
     * Example:         DmaChnSetSrcAdd(DMA_CHANNEL2, srcBuff+sizeof(srcBuff));
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetSrcAdd( DmaChannel chn, const void* vSrcAdd )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->ssa = _VirtToPhys(vSrcAdd);           // set src address
}
    

    /*********************************************************************
     * Function:        void DmaChnSetDstAdd(DmaChannel chn, void* vDstAdd)
     *
     * PreCondition:    chn     - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                              - vDstAdd: destination (virtual) of the DMA transfer
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function is a helper to set directly the transfer destination address.
     *
     * Note:            None
     *
     * Example:         DmaChnSetDstAdd(DMA_CHANNEL2, dstBuff+sizeof(dstBuff));
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetDstAdd( DmaChannel chn, void* vDstAdd )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->dsa = _VirtToPhys(vDstAdd);		// set dst address
}
    
    /*********************************************************************
     * Function:        void DmaChnSetMatchPattern(DmaChannel chn, int pattern)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  pattern -  the match pattern
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the curent match pattern for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         DmaChnSetMatchPattern(DMA_CHANNEL3, '\r');
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetMatchPattern( DmaChannel chn, int pattern )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->dat = pattern;	// set the match pattern
}

    /*********************************************************************
     * Function:        int DmaChnGetMatchPattern(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          The channel match pattern.
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the curent match pattern for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         int pattern=DmaChnGetMatchPattern(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaChnGetMatchPattern( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	return pReg->dat;		// read the match pattern
}
    
    /*********************************************************************
     * Function:        int DmaGetMaxTxferSize(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          The maximum transfer capacity for a DMA channel, in bytes.
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the maximum number of bytes that can be transferred by a DMA channel.
     *
     * Note:            Revision dependant.
     *
     * Example:         int dmaMaxSz=DmaGetMaxTxferSize();
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaGetMaxTxferSize( void )
{
    return 65536;
}

    /*********************************************************************
     * Function:        DmaTxferRes DmaChnStartTxfer(DmaChannel chn, DmaWaitMode wMode, unsigned long retries)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  wMode   - if DMA_WAIT_NOT, return immediately
     *                          - if DMA_WAIT_CELL, return after the cell transfer complete
     *                          - if DMA_WAIT_BLOCK, return after the whole transfer is done
     *                  retries - retry counter: if transfer not complete after so many retries, return with tmo.
     *                              If 0, wait forever.
     *
     * Output:          DMA_TXFER_OK if not waiting for the transfer completion or if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function initiates (forces) a DMA transfer for the selected DMA channel.
     *                  The DMA channel is enabled.
     *                  If waiting for the transfer completion needed (user doesn't use an ISR to catch
     *                  this event) the function will periodically query the DMA controller for the
     *                  transfer completion status.
     *                  If DMA_WAIT_BLOCK is specified and multiple cell transfers are needed to complete
     *                  the block transfer than the function will re-force the transfer for each cell.
     *
     * Note:            This function can not ne used when the DMA channel is triggerred
     *                  by hardware interrupt requests.
     *                  This is because the transfers are software forced, theere is no
     *                  wait for the occurrence of the hardware trigger.
     *
     * Example:         DmaChnStartTxfer(DMA_CHANNEL2, DMA_WAIT_BLOCK, 0);
     ********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnStartTxfer( DmaChannel chn, DmaWaitMode wMode, unsigned long retries )
{
	DmaTxferRes		txRes  = DMA_TXFER_OK;				// operation result
	int			useRetries = retries!=0;
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	pReg->intrClr   = DMA_IFLAG_MASK;                   // clear any previous bits
	pReg->conSet    = __DCHxCON_MASK_(CHEN_MASK);       // make sure it's enabled
	pReg->econSet   = __DCHxECON_MASK_(CFORCE_MASK);	// force the transfer start

	if(wMode != DMA_WAIT_NOT)
	{	// wait untill the cell/block transfer is done
		unsigned int		maxSize;                    // max size of bytes transferred: source or destination
		unsigned int		sSize, dSize;               // source and destination size
		unsigned int		xSize;                      // cell size
		unsigned int		nCells;                     // no of cells to transfer

		if(wMode == DMA_WAIT_CELL)
		{
			nCells = 1;                                   // transfer just one cell
		}
		else
		{
			sSize=pReg->ssiz ? pReg->ssiz : DmaGetMaxTxferSize();
			dSize=pReg->dsiz ? pReg->dsiz : DmaGetMaxTxferSize();
			xSize=pReg->csiz ? pReg->csiz : DmaGetMaxTxferSize();

			maxSize = sSize>=dSize?sSize:dSize;           // max size, the actual size of the block transfer
			nCells = (maxSize+xSize-1)/xSize;
		}

		nCells--;                                       // first cell txfer already initiated

		while(1)
		{
			unsigned int	intBits;                    // DMA controller event bits

			// see if transfer is done
			intBits = pReg->intr_w;                     // read the device event register
			if((intBits & __DCHxINT_CHERIF_MASK) || (intBits & __DCHxINT_CHTAIF_MASK))
			{
				txRes = (intBits & __DCHxINT_CHERIF_MASK) ? DMA_TXFER_ADD_ERR : DMA_TXFER_ABORT;		// errors or aborted
				break;
			}
			else if(intBits & __DCHxINT_CHBCIF_MASK)
			{
				break;                                  // block transferred, done
			}
			else if(intBits & __DCHxINT_CHCCIF_MASK)
			{
				if(wMode == DMA_WAIT_CELL)
				{
					break;                              // cell transferred, we're done
				}
				else
				{
					if(nCells)
					{
						pReg->intrClr =__DCHxINT_MASK_(CHCCIF_MASK);		// clear flag
						pReg->econSet =__DCHxECON_MASK_(CFORCE_MASK);	// force another transfer start
						nCells--;
					}
					else
					{
						txRes = DMA_TXFER_BC_ERR;	// we should have had CHBCIF set! this shouldn't happen!
						break;
					}
				}
			}
			// transfer not done yet
			if(useRetries)
			{
				if(retries-- == 0)
				{
					txRes = DMA_TXFER_TMO;
					break;
				}
			}

		}
	}
	return txRes;
}
      
    /*********************************************************************
     * Function:        void DmaChnForceTxfer(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function forces a DMA transfer to occur for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         DmaChnForceTxfer(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnForceTxfer( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->econSet = __DCHxECON_MASK_(CFORCE_MASK);
}

    /*********************************************************************
     * Function:        void DmaChnAbortTxfer(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function aborts a current undergoing DMA transfer for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         DmaChnAbortTxfer(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnAbortTxfer( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	pReg->econSet = __DCHxECON_MASK_(CABORT_MASK);
	if(!(DMACONbits.SUSPEND))
	{
		_DmaChnWaitAbort(pReg);	// wait to actually abort
	}
}

    /*********************************************************************
     * Function:        void DmaChnSetEvEnableFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the event enable flags for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  enabled for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaChnSetEvEnableFlags(DMA_CHANNEL3, DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_BLOCK_DONE|DMA_EV_SRC_FULL);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetEvEnableFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;   
    
	pReg->intrSet = eFlags << __DCHxINT_MASK_(CHERIE_POSITION);	// set the event control register
}
     
    /*********************************************************************
     * Function:        void DmaChnClrEvEnableFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function clears the event enable flags for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  disabled for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaChnClrEvEnableFlags(DMA_CHANNEL3, DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_BLOCK_DONE|DMA_EV_SRC_FULL);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnClrEvEnableFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->intrClr = eFlags << __DCHxINT_MASK_(CHERIE_POSITION);
}

    /*********************************************************************
     * Function:        void DmaChnWriteEvEnableFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the event enable flags for the selected DMA channel.
     *                  The channel event flags are forced to the eFlags value.
     *
     * Note:            None.
     *
     * Example:         DmaChnWriteEvEnableFlags(DMA_CHANNEL3, DMA_EV_ALL_EVNTS);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnWriteEvEnableFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->intrClr = DMA_EV_ALL_EVNTS << __DCHxINT_MASK_(CHERIE_POSITION);	// clear all events
	pReg->intrSet = eFlags << __DCHxINT_MASK_(CHERIE_POSITION);		// set the req event flags
}
     
    /*********************************************************************
     * Function:        DmaEvFlags DmaChnGetEvEnableFlags(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          - event flags with the following significance:
     *                      - DMA_EV_ERR: address error event
     *                      - DMA_EV_ABORT: transfer abort event
     *                      - DMA_EV_CELL_DONE: cell transfer complete event
     *                      - DMA_EV_BLOCK_DONE: block transfer complete event
     *                      - DMA_EV_DST_HALF: destination half event
     *                      - DMA_EV_DST_FULL: destination full event
     *                      - DMA_EV_SRC_HALF: source half event
     *                      - DMA_EV_SRC_FULL: source full event
     *                      - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the event enabled flags for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         DmaEvFlags enabledFlags=DmaChnGetEvEnableFlags(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ DmaEvFlags __attribute__((always_inline)) 
DmaChnGetEvEnableFlags( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;     
    
	return pReg->intr_w >> __DCHxINT_MASK_(CHERIE_POSITION); // get the event control register
}

    /*********************************************************************
     * Function:        void DmaChnClrEvFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function clears the event flags for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  cleared for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaChnClrEvFlags(DMA_CHANNEL3, DMA_EV_ALL_EVNTS);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnClrEvFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->intrClr = eFlags << __DCHxINT_MASK_(CHERIF_POSITION);
}

    /*********************************************************************
     * Function:        DmaEvFlags DmaChnGetEvFlags(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          event flags with the following significance:
     *                      - DMA_EV_ERR: address error event
     *                      - DMA_EV_ABORT: transfer abort event
     *                      - DMA_EV_CELL_DONE: cell transfer complete event
     *                      - DMA_EV_BLOCK_DONE: block transfer complete event
     *                      - DMA_EV_DST_HALF: destination half event
     *                      - DMA_EV_DST_FULL: destination full event
     *                      - DMA_EV_SRC_HALF: source half event
     *                      - DMA_EV_SRC_FULL: source full event
     *                      - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the event flags for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         DmaEvFlags intSetFlags=DmaChnGetEvFlags(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ DmaEvFlags __attribute__((always_inline)) 
DmaChnGetEvFlags( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;     
    
	return (pReg->intr_w >> __DCHxINT_MASK_(CHERIF_POSITION)) & DMA_EV_ALL_EVNTS;		// return the corresponding bits
}

    // high level helpers for fast strcpy/memcpy transfers

    /*********************************************************************
     * Function:        DmaTxferRes DmaChnMemcpy(void* s1, const void* s2, int n, DmaChannel chn, DmaChannelPri chPri)
     *
     * PreCondition:    chn     - a valid DMA channel
     *                  s1, s2  - valid memory pointers
     *                  n>0, n<=DmaGetMaxTxferSize()
     *
     * Input:           s1      - destination pointer
     *                  s2      - source pointer
     *                  n       - number of bytes to transfer
     *                  chn     - the DMA channel to perform the transfer
     *                  chPri   - the desired channel priority
     *
     * Output:          DMA_TXFER_OK if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function configures a DMA channel for a fast memory transfer.
     *          Then it copies one block of memory from source to destination.
     *
     *
     * Note:            - If the SFM is attached to the submitted channel, the SFM append mode will be turned off.
     *                    This way, the transfer will occur correctly together with checksum calculation.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  - Multiple channels could be opened to perform fast memory transfers, if necessary.
     *                  - The function clears the suspend state and resumes the operation of the DMA controller.
     *                  - The source to destination byte re-ordering is affected by DmaSfmConfigure(), DmaSfmTxferReorder().
     *
     * Example:     res=DmaChnMemcpy(pDst, pSrc, buffSz, DMA_CHANNEL0, DMA_CHN_PRI3);
     ********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnMemcpy( void* s1, const void* s2, int n, DmaChannel chn, DmaChannelPri chPri )
{
    unsigned int crcCon;
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	_DmaChnInitOp(pReg);                            // DMA controller on, remove SUSPEND, abort previous operation

	crcCon = DCRCCON;                               // read current control word
	if((crcCon & _DCRCCON_CRCCH_MASK ) == chn)
	{
		DCRCCONCLR=_DCRCCON_CRCAPP_MASK;            // clear append mode
	}

	pReg->con_w = chPri;	// not enabled, +CHPRI
	pReg->econClr = (__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK));		// disable start and abort irqs, no pattern enabled

	pReg->intrClr = __DCHxINT_w_MASK;               // disable events, clear existing flags


	pReg->ssa = _VirtToPhys(s2);                    // set src address
	pReg->dsa = _VirtToPhys(s1);                    // set dst address

	pReg->ssiz = pReg->dsiz = pReg->csiz = n;       // 0 size is max

	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}

    /*********************************************************************
     * Function:        DmaTxferRes DmaChnStrcpy(char* s1, const char* s2, DmaChannel chn, DmaChannelPri chPri)
     *
     * PreCondition:    chn     - a valid DMA channel
     *                  s1, s2  - valid memory pointers
     *
     * Input:           s1      - destination pointer
     *                  s2      - source pointer
     *                  chn     - the DMA channel to perform the transfer
     *                  chPri   - the desired channel priority
     *
     * Output:          DMA_TXFER_OK if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function configures a DMA channel for a fast memory transfer.
     *          Then it copies one zero terminated string from source to destination.
     *
     *
     * Note:            - If the SFM is attached to the submitted channel, the SFM append mode will be turned off.
     *                    This way, the transfer will occur correctly together with checksum calculation.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  - Multiple channels could be opened to perform fast memory transfers, if necessary.
     *                  - The function clears the suspend state and resumes the operation of the DMA controller.
     *                  - The source to destination byte re-ordering is affected by DmaSfmConfigure(), DmaSfmTxferReorder().
     *
     *
     * Example:     res=DmaChnStrcpy(str1, str2, DMA_CHANNEL1, DMA_CHN_PRI3);
     *********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnStrcpy( char* s1, const char* s2, DmaChannel chn, DmaChannelPri chPri )
{
    unsigned int crcCon;
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	_DmaChnInitOp(pReg);                            // DMA controller on, abort previous operation

	crcCon = DCRCCON;                               // read current control word
	if((crcCon & _DCRCCON_CRCCH_MASK ) == chn)
	{
		DCRCCONCLR =_DCRCCON_CRCAPP_MASK;           // clear append mode
	}

	pReg->con_w = chPri;	// not enabled, +CHPRI
	pReg->econClr = (__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK));		// disable start and abort irqs
	pReg->econSet = __DCHxECON_MASK_(PATEN_MASK);	// patern enable
	
	pReg->intrClr = __DCHxINT_w_MASK;               // disable events, clear existing flags
	pReg->dat = 0x0;                                // end for strcpy

	pReg->ssa = _VirtToPhys(s2);                    // set src address
	pReg->dsa = _VirtToPhys(s1);                    // set dst address

	pReg->ssiz = pReg->dsiz = pReg->csiz = 0x0;     // size is max

	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}

    /*********************************************************************
     * Function:        DmaTxferRes DmaChnStrncpy(char* s1, const char* s2, int n, DmaChannel chn, DmaChannelPri chPri)
     *
     * PreCondition:    chn     - a valid DMA channel
     *              - s1, s2    - valid memory pointers
     *                              - 0 < n <= DmaGetMaxTxferSize()
     *
     * Input:           s1      - destination pointer
     *                  s2      - source pointer
     *                  n   - max number of bytes to transfer
     *                  chn     - the DMA channel to perform the transfer
     *                  chPri   - the desired channel priority
     *
     * Output:          DMA_TXFER_OK if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function configures a DMA channel for a fast memory transfer.
     *          Then it copies one zero terminated string from source to destination.
     *          It copies no more than n characters from s2.
     *
     *
     * Note:            - If the SFM is attached to the submitted channel, the SFM append mode will be turned off.
     *                    This way, the transfer will occur correctly together with checksum calculation.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  - Multiple channels could be opened to perform fast memory transfers, if necessary.
     *                  - The function clears the suspend state and resumes the operation of the DMA controller.
     *                  - The source to destination byte re-ordering is affected by DmaSfmConfigure(), DmaSfmTxferReorder().
     *
     *
     * Example:     res=DmaChnStrncpy(str1, str2, MAX_STR_LEN, DMA_CHANNEL1, DMA_CHN_PRI3);
     ********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnStrncpy( char* s1, const char* s2, int n, DmaChannel chn, DmaChannelPri chPri )
{
    unsigned int crcCon;
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	_DmaChnInitOp(pReg);                                // DMA controller on, abort previous operation

	crcCon = DCRCCON;                                   // read current control word
    if((crcCon & _DCRCCON_CRCCH_MASK ) == chn)
	{
		DCRCCONCLR = _DCRCCON_CRCAPP_MASK;              // clear append mode
	}

	pReg->con_w = chPri;                                // not enabled, +CHPRI
	pReg->econClr = (__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK));		// disable start and abort irqs
	pReg->econSet = __DCHxECON_MASK_(PATEN_MASK);       // patern enable
	pReg->dat = 0x0;                                    // end for strcpy
	
	pReg->intrClr = __DCHxINT_w_MASK;            // disable events, clear existing flags

	pReg->ssa = _VirtToPhys(s2);                        // set src address
	pReg->dsa = _VirtToPhys(s1);                        // set dst address

	pReg->ssiz = pReg->dsiz = pReg->csiz = n;           // set sizes

	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}
     
    /*********************************************************************
     * Function:        DmaTxferRes DmaChnMemCrc(void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri)
     *
     * PreCondition:    chn    - a valid DMA channel
     *                  d, s   - valid memory pointer
     *                  n>0, n<=DmaGetMaxTxferSize()
     *
     * Input:           d     - address where to deposit the result
     *                  s     - source buffer pointer
     *                  n     - number of bytes in the pointer
     *                  chn   - the DMA channel to use
     *                  chPri - the desired channel priority
     *
     * Output:          DMA_TXFER_OK if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function is a helper that calculates the CRC of a memory block.
     *                  The function configures the DMA channel for a fast memory transfer and calculates the CRC.
     *
     *
     * Note:            - The CRC generator must have been previously configured using DmaSfmCrcConfigure()
     *                  - No transfer is done, just the CRC is calculated.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  - Append mode is enabled and the data transfer re-ordering is disabled (illegal combination, see DmaSfmTxferReorder()).
     *                  - The checksum type is switched to CRC.
     *                  - The way the data is fed into the checksum calculation block is affected by DmaSfmConfigure().
     *
     * Example:          int myCrc; DmaChnMemCrc(&myCrc, srcBuff, sizeof(srcBuff), DMA_CHANNEL2, DMA_CHN_PRI3);
     ********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnMemCrc( void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri )     
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	DCRCCONCLR = _DCRCCON_CRCEN_MASK;                           // stop the crc
	
	_DmaChnInitOp(pReg);                                        // DMA controller on, abort previous operation

	pReg->con_w = chPri;                                        // not enabled, +CHPRI
	pReg->econClr = (__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK));		// disable start and abort irqs, no pattern enabled

	pReg->intrClr = __DCHxINT_w_MASK;                           // disable events, clear existing flags
    
#if 1
	DCRCCONCLR = _DCRCCON_CRCCH_MASK|_DCRCCON_CRCTYP_MASK|_DCRCCON_WBO_MASK;		// clear channel no; switch to CRC; append+ WBO is illegal!
#else
	DCRCCONCLR = _DCRCCON_CRCCH_MASK;                           // clear channel no
#endif

	DCRCCONSET = _DCRCCON_CRCEN_MASK|_DCRCCON_CRCAPP_MASK|(chn<<_DCRCCON_CRCCH_POSITION);		// set channel number, CRCEN, CRCAPP

	pReg->ssa = _VirtToPhys(s);                                 // set src address
	pReg->dsa = _VirtToPhys(d);                                 // set dst address

	pReg->ssiz = pReg->dsiz = pReg->csiz = n;                   // 0 size is max 
	
	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}     
     
    /*********************************************************************
     * Function:        DmaTxferRes DmaChnMemChecksum(void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri)
     *
     * PreCondition:    chn    - a valid DMA channel
     *                  d, s   - valid memory pointer
     *                  n>0, n<=DmaGetMaxTxferSize()
     *
     * Input:           d     - address where to deposit the result
     *                  s     - source buffer pointer
     *                  n     - number of bytes in the pointer
     *                  chn   - the DMA channel to use
     *                  chPri - the desired channel priority
     *
     * Output:          DMA_TXFER_OK if the transfer ended normally,
     *                  an DmaTxferRes error code  otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function is a helper that calculates the IP checksum of a memory block.
     *                  The function configures the DMA channel for a fast memory transfer and calculates the IP checksum.
     *
     *
     * Note:            - The checksum generator must have been previously seeded using DmaSfmSetSeed()
     *                  - No transfer is done, just the checksum is calculated.
     *                  - The start and abort Irqs will be disabled and the channel event enable flags are disabled.
     *                  - Append mode is enabled and the data transfer re-ordering is disabled (illegal combination, see DmaSfmTxferReorder()).
     *                  - The checksum type is switched to IP checksum.
     *                  - The way the data is fed into the checksum calculation block is affected by DmaSfmConfigure().
     *
     * Example:          int myChecksum; DmaChnMemChecksum(&myChecksum, srcBuff, sizeof(srcBuff), DMA_CHANNEL1, DMA_CHN_PRI3);
     ********************************************************************/
extern __inline__ DmaTxferRes __attribute__((always_inline)) 
DmaChnMemChecksum( void* d, const void* s, int n, DmaChannel chn, DmaChannelPri chPri )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	DCRCCONCLR = _DCRCCON_CRCEN_MASK;                           // stop the SFM
	
	_DmaChnInitOp(pReg);                                        // DMA controller on, abort previous operation

	pReg->con_w = chPri;                                        // not enabled, +CHPRI
	pReg->econClr = (__DCHxECON_MASK_(SIRQEN_MASK)|__DCHxECON_MASK_(AIRQEN_MASK)|__DCHxECON_MASK_(PATEN_MASK));		// disable start and abort irqs, no pattern enabled

	pReg->intrClr = __DCHxINT_w_MASK;                           // disable events, clear existing flags


	DCRCCONCLR = _DCRCCON_CRCCH_MASK|_DCRCCON_WBO_MASK;         // clear channel no; append+ WBO is illegal!

	DCRCCONSET = _DCRCCON_CRCTYP_MASK|_DCRCCON_CRCEN_MASK|_DCRCCON_CRCAPP_MASK|(chn<<_DCRCCON_CRCCH_POSITION);		// set channel number; switch to IP chksum; CRCEN, CRCAPP

	pReg->ssa = _VirtToPhys(s);                                 // set src address
	pReg->dsa = _VirtToPhys(d);                                 // set dst address

	pReg->ssiz = pReg->dsiz = pReg->csiz = n;                   // 0 size is max 
	
	return DmaChnStartTxfer(chn, DMA_WAIT_BLOCK, 0);
}
     
    // High level Special Function Module (SFM) functions

    /*********************************************************************
     * Function:        void DmaSfmConfigure(DmaChksumType cType, DmaBitOrder bitO, DmaReorderMode rMode)
     *
     * PreCondition:    cType, bitO, rMode - valid values
     *
     * Input:           cType - checksum type to be calculated: CRC or IP Checksum
     *                  bitO  - the bit order to be used MSb or LSb first
     *                  rMode - the reordering mode of the bytes when calculating the checksum
     *
     * Output:          None
     *
     * Side Effects:    Whenever the Transfer re-ordering is enabled the rMode setting will influence the destination data layout
     *
     * Overview:        The function configures the SFM module by setting the parameters that define the behavior:
     *                      - the type of the checksum to be calculated (either CRC or IP checksum are supported)
     *                      - the bit ordering (how a specific byte is used in the checksum calculation: MSb or LSb first)
     *                      - the data re-ordering (how bytes are re-ordered before calculating the checksum).
     *                      All these values affect the way the checksum is calculated.
     *
     * Note:            None
     *
     * Example:         DmaSfmConfigure(DMA_CHKSUM_CRC, DMA_BITO_LSb, DMA_REORDER_ENDIAN);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaSfmConfigure( DmaChksumType cType, DmaBitOrder bitO, DmaReorderMode rMode )
{
    DCRCCONCLR = _DCRCCON_CRCTYP_MASK|_DCRCCON_BITO_MASK|_DCRCCON_BYTO_MASK;
    DCRCCONSET = (cType << _DCRCCON_CRCTYP_POSITION)|(bitO << _DCRCCON_BITO_POSITION)|(rMode << _DCRCCON_BYTO_POSITION);
}     

    /*********************************************************************
     * Function:        void DmaSfmTxferReorder(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable - boolean to enable/disable the re-ordering of the data transfer
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function configures the data transfer re-ordering of the SFM module.
     *                  If the re-ordering is enabled, the data is read from the source, re-ordered accordingly and then written to the destination.
     *                  Otherwise the data is written to the destination un-modified.
     *                  The re-ordering is the one specified by the DmaReorderMode parameter in the DmaSfmConfigure() call.
     *
     *
     * Note:            - The data transfer re-ordering should be used only for normal (background mode) data transfers.
     *                  - In append mode the data transfer re-ordering should not be enabled (undefined behavior)!
     *                  - Whenever the data re-ordering is enabled, the transfer should be aligned at both ends (source and destination).
     *                    Un-aligned transfers are not supported (undefined behavior)!
     *
     * Example:         DmaSfmTxferReorder();
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaSfmTxferReorder( int enable )
{
    DCRCCONCLR = _DCRCCON_WBO_MASK;
    DCRCCONSET = (enable << _DCRCCON_WBO_POSITION);
}
     
     /*********************************************************************
     * Function:        void DmaSfmCrcConfigure(unsigned int polynomial, int pLen, unsigned int seed)
     *
     * PreCondition:    pLen   - valid polynomial length within 1-32
     *
     * Input:           polynomial  - the layout of the CRC generator
     *                  pLen        - the length of the CRC generator polynomial
     *                  seed        - the initial seed of the CRC generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function configures the SFM CRC module by setting the parameters that define the generator polynomial:
     *                  - the length of the CRC generator polynomial, pLen;
     *                  - the function sets the layout of the shift stages that take place in the CRC generation.
     *                    Setting a bit to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                    If bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *                    Note that in a proper CRC polynomial, both the most significant bit (MSb) and least significant bit(LSb)
     *                    are always a '1'. Considering the generator polynomial: X^16+X^15+X^2+1, the value to be written as
     *                    feedback should be 0x8005, or 0x8004, but not 0x018005;
     *                  - the function sets the seed of the CRC generator. This is the initial data present in the
     *                   CRC shift register before the CRC calculation begins. A good initial value is usually 0xffffffff.
     *
     * Note:            - Bit 0 of the generator polynomial is always XOR'ed.
     *                  - When the append mode is set, the attached DMA channel has to have destination size <=4.
     *                    Upon the transfer completion the calculated CRC is stored at the destination address.
     *                  - When append mode is cleared, the DMA transfer occurs normally, and the CRC value is available using
     *                    the CrcResult() function.
     *                  - The CRC module should be configured before enabled.
     *                  - These settings are relevant only when the SFM is configured for the CRC type of checksum.
     *                  - The checksum register is the same for CRC or IP checksum mode. Therefore, this function changes also the seed for the IP checksum.
     *                  - The way the data is fed into the checksum calculation block and the type of the checksum performed is affected by DmaSfmConfigure().
     *
     * Example:         DmaSfmCrcConfigure(0x04c11db7, 32, 0xffffffff);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaSfmCrcConfigure( unsigned int polynomial, int pLen, unsigned int seed )
{
    DCRCCONCLR = _DCRCCON_PLEN_MASK;
    DCRCCONSET = (pLen-1) << _DCRCCON_PLEN_POSITION;
    DCRCDATA = seed;
    DCRCXOR = polynomial;
}

#define DmaCrcConfigure DmaSfmCrcConfigure          // PIC32_3xx backward compatibility name     

    /*********************************************************************
     * Function:        void DmaSfmAttachChannel(DmaChannel chn, int appendMode)
     *
     * PreCondition:    chn    - valid DMA channel
     *
     * Input:           chn         - the DMA channel to be attached to the checksum module.
     *                  appendMode  - if TRUE the data passed to the checksum generator is not transferred to destination
     *                                but it's written to the destination address when the block transfer is complete.
     *                              - if FALSE the data is transferred normally while the checksum is calculated.
     *                                The checksum will be available using the DmaSfmChecksum function.
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function attaches the SFM checksum module to a DMA channel and enables the checksum generator.
     *                  From now on, all the DMA traffic is directed to the SFM checksum generator. Once the DMA block transfer
     *                  is complete, the checksum result is available in the checksum data register.
     *                  If append mode is enabled, no data transfer takes place but the checksum result will be deposited at the DMA destination address.

     *
     * Note:            If append mode is enabled the data transfer re-ordering is disabled (illegal combination, see DmaSfmTxferReorder()).
     *
     * Example:         DmaSfmAttachChannel(DMA_CHANNEL0, TRUE);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaSfmAttachChannel( DmaChannel chn, int appendMode )
{
	unsigned int	conClr, conSet;
	
	conClr = _DCRCCON_CRCEN_MASK | _DCRCCON_CRCCH_MASK;                     // stop the crc
	conSet = _DCRCCON_CRCEN_MASK | (chn << _DCRCCON_CRCCH_POSITION);        // re-enable, set the channel no
	if(appendMode)
	{
		conSet |= _DCRCCON_CRCAPP_MASK;
		conClr |= _DCRCCON_WBO_MASK;                                        // append+ WBO is illegal!
	}
	else
	{
		conClr |= _DCRCCON_CRCAPP_MASK;
	}

	DCRCCONCLR = conClr;                                                    // clear
	DCRCCONSET = conSet;                                                    // write back
}

#define CrcAttachChannel    DmaSfmAttachChannel                             // PIC32_3xx backward compatibility name

    /*********************************************************************
     * Function:        unsigned int DmaSfmChecksum(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the current value of the checksum generator.
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the calculated checksum value.
     *
     * Note:            - The function returns the valid checksum result. The masking out the unused MSbits in the checksum register is done by the hardware.
     *                  - The way the data is fed into the checksum calculation block and the type of the checksum performed is affected by DmaSfmConfigure().
     *
     * Example:         unsigned int myChk=DmaSfmChecksum();
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaSfmChecksum( void )
{
    return DCRCDATA;
}

#define     CrcResult   DmaSfmChecksum              // PIC32_3xx backward compatibility name
#define     DmaCrcGetValue  DmaSfmChecksum          // PIC32_3xx backward compatibility name

    /*********************************************************************
     * Function:        void DmaSfmSetSeed(unsigned int seed)
     *
     * PreCondition:    None
     *
     * Input:           seed    - the initial seed of the checksum generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the seed of the checksum generator. This is the initial data present in the
     *                  CRC shift register or the IP checksum calculator before the actual transfer/calculation begins.
     *
     * Note:            When the SFM is configured for IP checksum mode, only the least significant 16 bits are relevant.
     *
     * Example:         DmaSfmSetSeed(0xffffffff);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaSfmSetSeed( unsigned int seed )
{
    DCRCDATA = seed;
}

#define     DmaCrcSetSeed   DmaSfmSetSeed           // PIC32_3xx backward compatibility name

/*********************  end of high level functions ****************************************/

    // low level definitions for the API functions


    typedef struct
    {
        union
        {
            struct
            {
                unsigned int chn:   3;      // last active DMA channel
                unsigned int rdOp:  1;      // last DMA operation, read if 1, write if 0
            };
            unsigned int    w;                      // word access
        }lastAccess;
        void*   lastAddress;        // most recent DMA address
    }DmaStatus;         // DMA controller status

    typedef enum
    {
        DMA_GFLG_SUSPEND =  _DMACON_SUSPEND_MASK,   // suspend DMA controller operation
        DMA_GFLG_ON =       _DMACON_ON_MASK,        // DMA module enabled/desabled
        //
        DMA_GFLG_ALL_FLAGS= DMA_GFLG_SUSPEND|DMA_GFLG_ON        // all flags
    }DmaGlblFlags;  // flags for controlling global DMA controller behavior. From processor header file.




    typedef enum
    {
        DMA_EV_ABORT_IRQ_EN =       _DCH0ECON_AIRQEN_MASK,
        DMA_EV_START_IRQ_EN =       _DCH0ECON_SIRQEN_MASK,
        // use DMA_EV_START_IRQ() and DMA_EV_ABORT_IRQ() below for selecting
        // the start and abort IRQ signals
        DMA_EV_MATCH_EN =           _DCH0ECON_PATEN_MASK,


        // compiler use only field
        _DMA_EV_MAX_MASK =     _DCH0ECON_CHAIRQ_MASK,
    }DmaEvCtrlFlags;    /*DMA channel event control fields accessible as flags also
                          part of DmaEvCtrlFlags:
                        */
    #define DMA_EV_START_IRQ(irq)   (DMA_EV_START_IRQ_EN | ((irq)<<_DCH0ECON_CHSIRQ_POSITION))  // NOTE: irq has to be a symbol from the processor header file
    #define DMA_EV_ABORT_IRQ(irq)   (DMA_EV_ABORT_IRQ_EN | ((irq)<<_DCH0ECON_CHAIRQ_POSITION))  // NOTE: irq has to be a symbol from the processor header file

    // DMA channel event control as a structure:
    #define DmaEvCtrl   __DCH0ECONbits_t




    typedef enum
    {
        DMA_CTL_AUTO_EN =       _DCH0CON_CHAEN_MASK,
        DMA_CTL_CHAIN_EN =      _DCH0CON_CHCHN_MASK,
        DMA_CTL_DET_EN =        _DCH0CON_CHAED_MASK,
        DMA_CTL_CHN_EN =        _DCH0CON_CHEN_MASK,
        DMA_CTL_CHAIN_DIR =     _DCH0CON_CHCHNS_MASK,
        // use the DMA_CTL_PRI() below for selecting the DMA
        // channel priority
    }DmaChnCtrlFlags;   // controlling the DMA channel with flags
    // also part of DmaChnCtrlFlags:
    #define DMA_CTL_PRI(pri)    ((pri)&_DCH0CON_CHPRI_MASK) // DMA Control channel priority

    // DMA channel control as a structure:
    #define DmaChnCtrl      __DCH0CONbits_t

    typedef struct
    {
        void*   vSrcAdd;        // source of the DMA transfer, virtual
        void*   vDstAdd;        // destination of the DMA transfer, virtual
        int srcSize;        // source buffer size, 1 to DmaGetMaxTxferSize() bytes. Wrapped around.
        int dstSize;        // destination buffer size, 1 to DmaGetMaxTxferSize() bytes. Wrapped around.
        int cellSize;       // no of bytes txferred per event, 1 to DmaGetMaxTxferSize().
    }DmaTxferCtrl;      // transfer setting: the transfer source, destination addresses and size, cell size

    /********************** low level DMA channel functions *******************************/



    // Global DMA controller functions

    /*********************************************************************
     * Function:        void DmaEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable - boolean to enable/disable the DMA controller
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:       The function enables/disables the DMA controller.
     *
     * Note:           None.
     *
     * Example:        DmaEnable(1);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaEnable(int enable)
    {
        if(enable)
        {
            DMACONSET = _DMACON_ON_MASK;
        }
        else
        {
            DMACONCLR = _DMACON_ON_MASK;
            while(DMACONbits.ON);       // wait to take effect
        }
    }
    
    /*********************************************************************
     * Function:        void DmaReset(void)
     *
     * PreCondition:    None
     *
     * Input:       None
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function resets the DMA controller.
     *
     * Note:            None.
     *
     * Example:        DmaReset();
     ********************************************************************/
    #define            DmaReset()   DmaEnable(0)


    /*********************************************************************
     * Function:        int DmaSuspend(void)
     *
     * PreCondition:    None
     *
     * Input:       None
     *
     * Output:          true if the DMA was previously suspended, false otherwise
     *
     *
     * Side Effects:    None
     *
     * Overview:        The function suspends the DMA controller.
     *
     * Note:            After the execution of this function the DMA operation is supposed to be suspended.
     *                  I.e. the function has to wait for the suspension to take place!
     *
     * Example:         int susp=DmaSuspend();
     ********************************************************************/
     extern __inline__ int __attribute__((always_inline)) DmaSuspend(void)
    {
        int suspSt;
        if(!(suspSt = DMACONbits.SUSPEND))
        {
            DMACONSET = _DMACON_SUSPEND_MASK;       // suspend
            while((DMACONbits.DMABUSY));            // wait to be actually suspended
        }
        return suspSt;
    }    
    
    /*********************************************************************
     * Function:        void DmaResume(int susp)
     *
     * PreCondition:    None
     *
     * Input:       the desired DMA suspended state.
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function restores the DMA controller activity to the old suspended mode.
     *
     * Note:            None.
     *
     * Example:         int isSusp=DmaSuspend(); {....}; DmaResume(isSusp);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaResume(int susp)
    {
        if(susp)
        {
            DmaSuspend();
        }
        else
        {
            DMACONCLR = _DMACON_SUSPEND_MASK;       // resume DMA activity
        }
    } 
     
    /*********************************************************************
     * Function:        void DmaGetStatus(DmaStatus* pStat)
     *
     * PreCondition:    pStat   - valid pointer
     *
     * Input:           pStat   - pointer to a DmaStatus structure to store the current DMA controller
     *                          status, carrying the following info:
     *                              - chn:  the last active DMA channel
     *                              - rdOp: the last DMA operation, read/write
     *                              - lastAddress: the most recent DMA address
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function updates the info for the current DMA controller status.
     *                  It updates the last DMA: operation, channel used and address.
     *
     * Note:            None.
     *
     * Example:         DmaStatus stat; DmaGetStatus(&stat);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaGetStatus(DmaStatus* pStat)   
    {
        pStat->lastAccess.w = DMASTAT;			// update the last access
        pStat->lastAddress = (void*)DMAADDR;		// update the last DMA address
    }     
     
    /*********************************************************************
     * Function:        void DmaSetGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be set, having the following fields:
     *          - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *          - DMA_GFLG_ON: DMA controller enabled/desabled
     *          - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It sets the specified flags. Any flag that is set in the gFlags will be
     *                  enabled, the other flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaSetGlobalFlags(DMA_GFLG_ON);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSetGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACONSET = gFlags;
    }     

    /*********************************************************************
     * Function:        void DmaClrGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be cleared, having the following fields:
     *                               - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                               - DMA_GFLG_ON: DMA controller enabled/desabled
     *                               - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It clears the specified flags. Any flag that is set in the gFlags will be
     *                  cleared, the other flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         DmaClrGlobalFlags(DMA_GFLG_SUSPEND);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaClrGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACONCLR = gFlags;
    }    
    
    /*********************************************************************
     * Function:        void DmaWriteGlobalFlags(DmaGlblFlags gFlags)
     *
     * PreCondition:    None
     *
     * Input:           gFlags - flags to be set, having the following fields:
     *                                 - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                                 - DMA_GFLG_ON: DMA controller enabled/desabled
     *                                 - DMA_GFLG_ALL_FLAGS: all flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function affects the global behavior of the DMA controller.
     *                  It forces the flags to have the specified gFlags value.
     *
     * Note:            None.
     *
     * Example:         DmaWriteGlobalFlags(DMA_GFLG_ALL_FLAGS);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaWriteGlobalFlags(DmaGlblFlags gFlags)
    {
        DMACON = gFlags;
    }    
    
    /*********************************************************************
     * Function:        DmaGlblFlags DmaGetGlobalFlags(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          The current DMA controller flags settings.
     *                              - DMA_GFLG_SUSPEND: DMA controller operation suspend
     *                              - DMA_GFLG_ON: DMA controller enabled/desabled
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the global flags of the DMA controller.
     *
     * Note:            None.
     *
     * Example:         DmaGlblFlags dmaFlags=DmaGetGlobalFlags();
     ********************************************************************/
    extern __inline__ DmaGlblFlags __attribute__((always_inline)) DmaGetGlobalFlags(void)
    {
        return (DmaGlblFlags)DMACON;
    }    
    
    // Direct Channel control functions

    typedef enum
    {
        DMA_CONFIG_DEFAULT = 0,                             // DMA default operation
        DMA_CONFIG_AUTO = _DCH0CON_CHAEN_MASK,              // DMA channel is auto enabled
        DMA_CONFIG_CHAIN_LOW  = (_DCH0CON_CHCHN_MASK|_DCH0CON_CHCHNS_MASK), // DMA channel is chained to lower channel
        DMA_CONFIG_CHAIN_HI  = (_DCH0CON_CHCHN_MASK),       // DMA channel is chained to higher channel
        DMA_CONFIG_DET_EN = _DCH0CON_CHAED_MASK,            // events detection enabled while channel off
        DMA_CONFIG_ENABLE = _DCH0CON_CHEN_MASK,             // DMA channel is enabled after open
        DMA_CONFIG_MATCH    = 0x80000000,                   // DMA channel stops on match
    }DmaConfigFlags;    // flags for the channel configuration    
 
    /*********************************************************************
     * Function:        void DmaChnConfigure(DmaChannel chn, DmaChannelPri chPri, DmaConfigFlags cFlags)
     *
     * PreCondition:    chPri  - valid channel priority, 0-3
     *
     * Input:           chn    - channel to be configured in the DMA controller
     *                  chPri  - the priority given to the channel, 0-3
     *                  cFlags - orred flags specifying the configuration:
     *                           DMA_CONFIG_DEFAULT: DMA default operation mode
     *                           DMA_CONFIG_AUTO:   DMA channel is auto enabled
     *                           DMA_CONFIG_CHAIN_LOW: DMA channel is chained to lower channel
     *                           DMA_CONFIG_CHAIN_HI: DMA channel is chained to higher channel
     *                           DMA_CONFIG_DET_EN: events detection enabled while channel off
     *                           DMA_CONFIG_ENABLE: DMA channel is enabled when opened
     *                           DMA_CONFIG_MATCH:  DMA channel stops on match
     *
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function configures the selected DMA channel using the supplied user flags and priority.
     *
     * Note:            - The channel is NOT turned off. It should be turned off before calling this function.
     *                  The channel is just configured.
     *                  - After calling this function, the channel should be enabled using DmaChnEnable(chn) call
     *                  if DMA_CONFIG_ENABLE flag was not specified.
     *                  - The function does not touch the interrupt flags, interrupt enables, etc.
     *                  The interrupt flags should have been previously cleared and interrupts disabled before calling this function.
     *                  - The start and abort Irqs, the channel event enable flags are not touched/cleared by this function.
     *                  User has to call event channel functions to clear/enable the event flags if needed.
     *
     * Example:         DmaChnDisable(DMA_CHANNEL2); DmaChnConfigure(DMA_CHANNEL2, DMA_CHN_PRI2, DMA_CONFIG_AUTO|DMA_CONFIG_MATCH|DMA_CONFIG_ENABLE);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline))    
DmaChnConfigure( DmaChannel chn, DmaChannelPri chPri, DmaConfigFlags cFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	
	if(cFlags & DMA_CONFIG_MATCH)
	{
		pReg->econSet = __DCHxECON_MASK_(PATEN_MASK);
	}
	else
	{
		pReg->econClr = __DCHxECON_MASK_(PATEN_MASK);
	}
	
	pReg->con_w = (chPri&__DCHxCON_MASK_(CHPRI_MASK)) | (cFlags&(~DMA_CONFIG_MATCH));	// set the control word
}
    
    /*********************************************************************
     * Function:        int DmaChnGetSrcPnt(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          Current channel source pointer.
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the current source pointer for the selected DMA channel.
     *                  It is the current offset, 0 to DmaGetMaxTxferSize()-1, in the source transfer buffer.
     *
     * Note:            None
     *
     * Example:         int srcPnt=DmaChnGetSrcPnt(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaChnGetSrcPnt( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;   
    
	return pReg->sptr;              // read the src pointer
}

    /*********************************************************************
     * Function:        int DmaChnGetDstPnt(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          Current channel destination pointer.
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the current destination pointer for the selected DMA channel.
     *                  It is the current offset, 0 to DmaGetMaxTxferSize()-1, in the destination transfer buffer.
     *
     * Note:            None
     *
     * Example:         int dstPnt=DmaChnGetDstPnt(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaChnGetDstPnt( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	return pReg->dptr;
}
    
    /*********************************************************************
     * Function:        int DmaChnGetCellPnt(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          Current channel transfer pointer.
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the current transfer progress pointer for the selected DMA channel.
     *                  It ranges 0 to DmaGetMaxTxferSize()-1.
     *
     * Note:            None
     *
     * Example:         int cellPnt=DmaChnGetCellPnt(DMA_CHANNEL3);
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaChnGetCellPnt( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;     
    
	return pReg->cptr;
}
    
    /*********************************************************************
     * Function:        void DmaChnSetEventControlFlags(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaEvCtrl   -   either a DmaEvCtrl structure field, carrying the following info:
     *                                      - AIRQEN: enable/disable the abort IRQ action
     *                                      - SIRQEN: enable/disable the start IRQ action
     *                                      - PATEN: enable/disable the pattern match and abort
     *                                  or any of the DmaEvCtrlFlags:
     *                                      DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the events that start and abort the transfer
     *                  for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  enabled for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnSetEventControlFlags(DMA_CHANNEL3, DMA_EV_MATCH_EN|DMA_EV_START_IRQ_EN;
     *                  or:
     *                      DmaEvCtrl evCtrl; evCtrl.w=0; evCtrl.PATEN=1; evCtrl.SIRQEN=1;
     *                      DmaChnSetEventControlFlags(DMA_CHANNEL3, evCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetEventControlFlags( DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;     
    
	pReg->econSet = dmaEvCtrl & DMA_EVENT_MASK;         // set the events. Don't touch Abort and Force!
}

    /*********************************************************************
     * Function:        void DmaChnClrEventControlFlags(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaEvCtrl   -   either a DmaEvCtrl structure field, carrying the following info:
     *                                      - AIRQEN: enable/disable the abort IRQ action
     *                                      - SIRQEN: enable/disable the start IRQ action
     *                                      - PATEN: enable/disable the pattern match and abort
     *                                  or any of the DmaEvCtrlFlags:
     *                                      DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function clears the events that start and abort the transfer
     *                  for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  disabled for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnClrEventControlFlags(DMA_CHANNEL3, DMA_EV_MATCH_EN|DMA_EV_START_IRQ_EN);
     *                  or:
     *                      DmaEvCtrl evCtrl; evCtrl.w=0; evCtrl.PATEN=1; evCtrl.AIRQEN=1;
     *                      DmaChnClrEventControlFlags(DMA_CHANNEL3, evCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnClrEventControlFlags( DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;
    
	pReg->econClr = dmaEvCtrl & DMA_EVENT_MASK;         // clear the events. Don't touch Abort and Force!
}
     
    /*********************************************************************
     * Function:        void DmaChnWriteEventControlFlags(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaEvCtrl   -   either a DmaEvCtrl structure field, carrying the following info:
     *                                      - AIRQEN: enable/disable the abort IRQ action
     *                                      - SIRQEN: enable/disable the start IRQ action
     *                                      - PATEN: enable/disable the pattern match and abort
     *                                      - CHSIRQ: IRQ number to start the DMA channel transfer
     *                                      - CHAIRQ: IRQ number to abort the DMA channel transfer
     *                                  or any of the DmaEvCtrlFlags:
     *                                      DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(irq)|DMA_EV_ABORT_IRQ(irq)
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function writes the events that start and abort the transfer
     *                  for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnWriteEventControlFlags(DMA_CHANNEL3, DMA_EV_MATCH_EN|DMA_EV_START_IRQ(_UART2_RX_IRQ));
     *                  or:
     *                      DmaEvCtrl evCtrl; evCtrl.w=0; evCtrl.AIRQEN=1; evCtrl.PATEN=1; evCtrl.CHSIRQ=_UART2_RX_IRQ;
     *                      DmaChnWriteEventControlFlags(DMA_CHANNEL3, evCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnWriteEventControlFlags( DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->econ_w = dmaEvCtrl & DMA_EVENT_MASK;          // write the events. Don't touch Abort and Force!
}
     
    /*********************************************************************
     * Function:        void DmaChnSetEventControl(DmaChannel chn, DmaEvCtrlFlags dmaEvCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaEvCtrl   -   either a DmaEvCtrl structure field, carrying the following info:
     *                                      - AIRQEN: enable/disable the abort IRQ action
     *                                      - SIRQEN: enable/disable the start IRQ action
     *                                      - PATEN: enable/disable the pattern match and abort
     *                                      - CHSIRQ: IRQ number to start the DMA channel transfer
     *                                      - CHAIRQ: IRQ number to abort the DMA channel transfer
     *                                  or any of the DmaEvCtrlFlags:
     *                                      DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(irq)|DMA_EV_ABORT_IRQ(irq)
     *
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the events that start and abort the transfer
     *                  for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  enabled for the selected channel, the other channel event flags won't be touched.
     *
     * Note:           A shorter name for DmaChnWriteEventControlFlags();
     *
     * Example:         either:
     *                      DmaChnSetEventControl(DMA_CHANNEL3, DMA_EV_MATCH_EN|DMA_EV_START_IRQ(_UART2_RX_IRQ));
     *                  or:
     *                      DmaEvCtrl evCtrl; evCtrl.w=0; evCtrl.AIRQEN=1; evCtrl.PATEN=1; evCtrl.CHSIRQ=_UART2_RX_IRQ;
     *                      DmaChnSetEventControl(DMA_CHANNEL3, evCtrl.w);
     *
     ********************************************************************/
#define DmaChnSetEventControl(chn, dmaEvCtrl)   DmaChnWriteEventControlFlags(chn, dmaEvCtrl)     
     
    /*********************************************************************
     * Function:        DmaEvCtrlFlags DmaChnGetEventControl(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          -   either a DmaEvCtrl structure field, carrying the following info:
     *                          - AIRQEN: enable/disable the abort IRQ action
     *                          - SIRQEN: enable/disable the start IRQ action
     *                          - PATEN: enable/disable the pattern match and abort
     *                          - CHSIRQ: IRQ number to start the DMA channel transfer
     *                          - CHAIRQ: IRQ number to abort the DMA channel transfer
     *                      or any of the DmaEvCtrlFlags:
     *                          DMA_EV_ABORT_IRQ_EN|DMA_EV_START_IRQ_EN|DMA_EV_MATCH_EN|DMA_EV_START_IRQ(irq)|DMA_EV_ABORT_IRQ(irq)
     *
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the events that start and abort the transfer
     *                  for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaEvCtrlFlags evCtrlW=DmaChnGetEventControl(DMA_CHANNEL3); if(evCtrlW&DMA_EV_MATCH_EN) {...}
     *                  or:
     *                      DmaEvCtrl evCtrl; evCtrl.w=DmaChnGetEventControl(DMA_CHANNEL3); if(evCtrl.PATEN){...}
     *
     ********************************************************************/
extern __inline__ DmaEvCtrlFlags __attribute__((always_inline)) 
DmaChnGetEventControl( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;   
    
	return pReg->econ_w;                // get the current events.
}

    /*********************************************************************
     * Function:        void DmaChnSetControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaChnCtrl  -   either a DmaChnCtrl structure field, carrying the following info:
     *                                      - autoEn: enable/disable the automatic mode
     *                                      - chainEn: enable/disable channel chaining
     *                                      - detectEn: enable/disable events detection when channel disabled
     *                                      - chEn: enable/disable channel functionality
     *                                      - chainDir: chain direction: chain to lower(1)/higher(0),pri channel
     *                                  or any of the DmaChnCtrlFlags flags:
     *                                      DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the selected DMA channel control flags:
     *                  the chaining or auto mode, and events detection.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the dmaChnCtrl will be
     *                  set for the selected channel, the other channel control flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnSetControlFlags(DMA_CHANNEL3, DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
     *                  or:
     *                      DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.autoEn=1; chCtrl.chainEn=1;
     *                      DmaChnSetControlFlags(DMA_CHANNEL3, chCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnSetControlFlags( DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->conSet = dmaChnCtrl;                  // set the control register fields
}

    /*********************************************************************
     * Function:        void DmaChnClrControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaChnCtrl  -   either a DmaChnCtrl structure field, carrying the following info:
     *                                      - autoEn: enable/disable the automatic mode
     *                                      - chainEn: enable/disable channel chaining
     *                                      - detectEn: enable/disable events detection when channel disabled
     *                                      - chEn: enable/disable channel functionality
     *                                      - chainDir: chain direction: chain to lower(1)/higher(0),pri channel
     *                                  or any of the DmaChnCtrlFlags flags:
     *                                      DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function clears the selected DMA channel control flags:
     *                  the chaining or auto mode and events detection.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the dmaChnCtrl will be
     *                  cleared for the selected channel, the other channel control flags won't be touched.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnClrControlFlags(DMA_CHANNEL3, DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
     *                  or:
     *                      DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.autoEn=1; chCtrl.chainEn=1;
     *                      DmaChnClrControlFlags(DMA_CHANNEL3, chCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnClrControlFlags( DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->conClr = dmaChnCtrl;                  // set the control register fields
}

    /*********************************************************************
     * Function:        void DmaChnWriteControlFlags(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *                  dmaChnCtrl  -   either a DmaChnCtrl structure field, carrying the following info:
     *                                      - chPri: channel priority 0-3
     *                                      - autoEn: enable/disable the automatic mode
     *                                      - chainEn: enable/disable channel chaining
     *                                      - detectEn: enable/disable events detection when channel disabled
     *                                      - chEn: enable/disable channel functionality
     *                                      - chainDir: chain direction: chain to lower(1)/higher(0),pri channel
     *                                  or any of the DmaChnCtrlFlags flags:
     *                                      DMA_CTL_PRI(pri)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables/disables the selected DMA channel and also sets
     *                  the channel priority, chaining mode or auto and events detection.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnWriteControlFlags(DMA_CHANNEL3, DMA_CTL_PRI(DMA_CHN_PRI2)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
     *                  or:
     *                      DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.chPri=DMA_CHN_PRI2; chCtrl.autoEn=1; chCtrl.chainEn=1;
     *                      DmaChnWriteControlFlags(DMA_CHANNEL3, chCtrl.w);
     *
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnWriteControlFlags( DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->con_w = dmaChnCtrl;                   // set the control register fields
}

    /*********************************************************************
     * Function:        void DmaChnSetControl(DmaChannel chn, DmaChnCtrlFlags dmaChnCtrl)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:       chn     - DMA channel number
     *                  dmaChnCtrl  -   either a DmaChnCtrl structure field, carrying the following info:
     *                      - chPri: channel priority 0-3
     *                      - autoEn: enable/disable the automatic mode
     *                      - chainEn: enable/disable channel chaining
     *                      - detectEn: enable/disable events detection when channel disabled
     *                      - chEn: enable/disable channel functionality
     *                      - chainDir: chain direction: chain to lower(1)/higher(0),pri channel
     *                  or any of the DmaChnCtrlFlags flags:
     *                      DMA_CTL_PRI(pri)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables/disables the selected DMA channel and also sets
     *                  the channel priority, chaining mode or auto and events detection.
     *
     * Note:            Another name ( backward compatible) for DmaChnWriteControlFlags().
     *
     * Example:         either:
     *                      DmaChnSetControl(DMA_CHANNEL3, DMA_CTL_PRI(DMA_CHN_PRI2)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN);
     *                  or:
     *                      DmaChnCtrl chCtrl; chCtrl.w=0; chCtrl.chPri=DMA_CHN_PRI2; chCtrl.autoEn=1; chCtrl.chainEn=1;
     *          DmaChnSetControl(DMA_CHANNEL3, chCtrl.w);
     *
     ********************************************************************/
 #define DmaChnSetControl(chn, dmaChnCtrl)   DmaChnWriteControlFlags(chn, dmaChnCtrl)

    /*********************************************************************
     * Function:        DmaChnCtrlFlags DmaChnGetControlFlags(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn         - DMA channel number
     *
     * Output:          - either a DmaChnCtrl structure field, carrying the following info:
     *                          - chPri: channel priority 0-3
     *                          - autoEn: enable/disable the automatic mode
     *                          - chainEn: enable/disable channel chaining
     *                          - detectEn: enable/disable events detection when channel disabled
     *                          - chEn: enable/disable channel functionality
     *                          - chainDir: chain direction: chain to lower(1)/higher(0),pri channel
     *                      or any of the DmaChnCtrlFlags flags:
     *                          DMA_CTL_PRI(pri)|DMA_CTL_AUTO_EN|DMA_CTL_CHAIN_EN|DMA_CTL_DET_EN|DMA_CTL_CHN_EN|DMA_CTL_CHAIN_DIR
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the current control settings for the selected DMA channel,
     *                  including the channel enable/disable status, the channel priority,
     *                  chaining mode, auto mode and events detection.
     *
     * Note:            None.
     *
     * Example:         either:
     *                      DmaChnCtrlFlags ctrl=DmaChnGetControlFlags(DMA_CHANNEL3); if(ctrl&DMA_CTL_AUTO_EN) {...}
     *                  or:
     *                      DmaChnCtrl chnCtrl; chnCtrl.w=DmaChnGetControlFlags(DMA_CHANNEL3); if(chnCtrl.autoEn) {...}
     *
     ********************************************************************/
extern __inline__ DmaChnCtrlFlags __attribute__((always_inline)) 
DmaChnGetControlFlags( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	return pReg->con_w;
}

    /*********************************************************************
     * Function:        int DmaChnGetEvDetect(DmaChannel chn)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *
     * Output:          TRUE if an DMA event was detected, FALSE otherwise.
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the current event detection for the selected DMA channel.
     *
     * Note:            None.
     *
     * Example:         int evDetect=DmaChnGetEvDetect(DMA_CHANNEL3);
     *
     ********************************************************************/
extern __inline__ int __attribute__((always_inline)) 
DmaChnGetEvDetect( DmaChannel chn )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;   
    
	return pReg->con.CHEDET;
}

    /*********************************************************************
     * Function:        void DmaChnGetTxfer(DmaChannel chn, DmaTxferCtrl* pTxCtrl, int mapToK0)
     *
     * PreCondition:    chn     - valid DMA channel
     *                  pTxCtrl - valid pointer
     *
     * Input:           chn         - DMA channel number
     *                  pTxCtrl     - pointer to a DmaTxferCtrl that will carry the following info:
     *                              - vSrcAdd: source of the DMA transfer
     *                              - vDstAdd: destination of the DMA transfer
     *                              - srcSize: source buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped arround
     *                              - dstSize: destination buffer size, 1 to DmaGetMaxTxferSize() bytes, wrapped around
     *                              - cellSize: cell transfer size, 1 to DmaGetMaxTxferSize() bytes.
     *                  mapToK0     - if TRUE, a Kernel address is mapped to KSeg0, else KSeg1.
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function retrieves the transfer characteristics for a DMA channel transfer:
     *                  the source and the destination addresses.
     *                  It also retrieves the source and destination lengths
     *                  and the number of bytes transferred per event.
     *
     * Note:            None
     *
     * Example:         DmaTxferCtrl txCtl; DmaChnGetTxfer(DMA_CHANNEL3, &txCtl, FALSE);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnGetTxfer( DmaChannel chn, DmaTxferCtrl* pTxCtrl, int mapToK0 )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;

	pTxCtrl->vSrcAdd = mapToK0 ? _PhysToVirtK0(pReg->ssa) : _PhysToVirtK1(pReg->ssa);	// get src address
	pTxCtrl->vDstAdd = mapToK0 ? _PhysToVirtK0(pReg->dsa) : _PhysToVirtK1(pReg->dsa);	// get dst address

	pTxCtrl->srcSize = pReg->ssiz ? pReg->ssiz : DmaGetMaxTxferSize();                  // get src size
	pTxCtrl->dstSize = pReg->dsiz ? pReg->dsiz : DmaGetMaxTxferSize();                  // get dst size
	pTxCtrl->cellSize = pReg->csiz ? pReg->csiz : DmaGetMaxTxferSize();                 // get transfer (cell) size
}

    // Low level checksum functions

    /*********************************************************************
     * Function:        void DmaSfmEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable _ boolean to enable/disable the SFM functionality
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables/diables the checksum module functionality.
     *                  When enabled the attached DMA channel transfers are routed to the SFM module.
     *
     * Note:            The SFM module should be properly configured before enabled.
     *
     * Example:         DmaSfmEnable(1);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmEnable(int enable)
    {
        if(enable)
        {
            DCRCCONSET = _DCRCCON_CRCEN_MASK;
        }
        else
        {
            DCRCCONCLR = _DCRCCON_CRCEN_MASK;
        }
    }
    
    #define DmaCrcEnable    DmaSfmEnable            // PIC32_3xx backward compatibility

    /*********************************************************************
     * Function:        int DmaSfmGetEnable(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          TRUE, if the SFM module is enabled
     *          FALSE otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the SFM module enabling status.
     *
     * Note:            None
     *
     * Example:     int isSfmEnabled=DmaSfmGetEnable();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaSfmGetEnable(void)
    {
        return DCRCCONbits.CRCEN != 0;
    }
    
    #define     DmaCrcGetEnable     DmaSfmGetEnable         // PIC32_3xx backward compatibility

    /*********************************************************************
     * Function:        void DmaSfmAppendEnable(int enable)
     *
     * PreCondition:    None
     *
     * Input:           enable _ boolean to enable/disable the SFM append mode
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function enables the SFM append mode. In this mode, the attached DMA channel reads
     *                  the source data but does not write it to the destination address. The data it's just passed
     *                  to the checksum generator for CRC/IP checksum calculation.
     *                  When the block transfer is completed, the checksum result is written to the
     *                  DMA channel destination address.
     *
     * Note:            The SFM module should be properly configured before enabled.
     *
     * Example:         DmaSfmAppendModeEnable(TRUE);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmAppendEnable(int enable)
    {
        if(enable)
        {
            DCRCCONSET = _DCRCCON_CRCAPP_MASK;
        }
        else
        {
            DCRCCONCLR = _DCRCCON_CRCAPP_MASK;
        }
    }
    
    #define     DmaCrcAppendModeEnable  DmaSfmAppendEnable          // PIC32_3xx backward compatibility
    
    /*********************************************************************
     * Function:        int DmaSfmGetAppendMode(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          TRUE, if the SFM append mode is enabled
     *                  FALSE otherwise
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the SFM module enabling status.
     *
     * Note:            None
     *
     * Example:         int isAppendEnabled=DmaSfmGetAppendMode();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaSfmGetAppendMode(void)
    {
        return DCRCCONbits.CRCAPP != 0;
    }
    
    #define DmaCrcGetAppendMode DmaSfmGetAppendMode                 // PIC32_3xx backward compatibility    
    
    /*********************************************************************
     * Function:        void DmaSfmSetAttach(DmaChannel chn)
     *
     * PreCondition:    chn     - valid DMA channel
     *
     * Input:           chn - the DMA channel to be attached to the SFM module (the DMA channel transfers will be routed to the SFM module)
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function directly attaches a DMA channel to the SFM module.
     *
     * Note:            None
     *
     * Example:         DmaSfmSetAttach(DMA_CHANNEL3);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaSfmSetAttach(DmaChannel chn)
    {
        DCRCCONCLR = _DCRCCON_CRCCH_MASK;
        DCRCCONSET = chn;
    }
    
    #define     DmaCrcSetAttach     DmaSfmSetAttach                 // PIC32_3xx backward compatibility
    
    /*********************************************************************
     * Function:        DmaChannel DmaSfmGetAttach(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the DMA channel that is currently attached to the CRC module
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the DMA channel number that is currently attached to the SFM module.
     *
     * Note:            None
     *
     * Example:         DmaChannel chn=DmaSfmGetAttach();
     ********************************************************************/
    extern __inline__ DmaChannel __attribute__((always_inline)) DmaSfmGetAttach(void)
    {
        return (DmaChannel)DCRCCONbits.CRCCH;
    }
    
    #define     DmaCrcGetAttach     DmaSfmGetAttach                 // PIC32_3xx backward compatibility   
    
    /*********************************************************************
     * Function:        void DmaCrcSetPLen(int pLen)
     *
     * PreCondition:    pLen - valid polynomial length within 1-32
     *
     * Input:           pLen    - the length of the CRC generator polynomial
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The length of the CRC generator polynomial is set as being pLen;
     *
     * Note:            None
     *
     * Example:         DmaCrcSetPLen(32);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaCrcSetPLen(int pLen)
    {
        DCRCCONCLR = _DCRCCON_PLEN_MASK;
        DCRCCONSET = (pLen)-1;
    }   
    
    /*********************************************************************
     * Function:        int DmaCrcGetPLen(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the length of the CRC generator polynomial
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the current length of the CRC generator polynomial.
     *                  It's always a number between 1 and 32.
     *
     * Note:            None
     *
     * Example:         int polyLen=DmaCrcGetPLen();
     ********************************************************************/
    extern __inline__ int __attribute__((always_inline)) DmaCrcGetPLen(void)
    {
        return  DCRCCONbits.PLEN+1;
    }

    /*********************************************************************
     * Function:        void DmaCrcSetShiftFeedback(unsigned int feedback)
     *
     * PreCondition:    None
     *
     * Input:           feedback - the layout of the CRC generator
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the layout of the shift stages that take place in the CRC generation.
     *                  Setting a bit to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                  If bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *
     * Note:            Bit 0 of the generator polynomial is always XOR'ed.
     *
     * Example:         DmaCrcSetShiftFeedback(0x04c11db7);
     ********************************************************************/
    extern __inline__ void __attribute__((always_inline)) DmaCrcSetShiftFeedback(unsigned int feedback)
    {
        DCRCXOR = feedback;
    }

    /*********************************************************************
     * Function:        unsigned int DmaCrcGetShiftFeedback(void)
     *
     * PreCondition:    None
     *
     * Input:           None
     *
     * Output:          the current layout of the CRC generator
     *
     * Side Effects:    None
     *
     * Overview:        The function returns the layout of the shift stages that take place in the CRC generation.
     *                  A bit set to 1 enables the XOR input from the MSb (pLen bit) to the selected stage in the shift register.
     *                  If a bit is cleared, the selected shift stage gets data directly from the previous stage in the shift register.
     *
     * Note:            Bit 0 of the generator polynomial is always XOR'ed.
     *
     * Example:         int feedback=DmaCrcGetShiftFeedback();
     ********************************************************************/
    extern __inline__ unsigned int __attribute__((always_inline)) DmaCrcGetShiftFeedback(void)
    {
        return DCRCXOR;
    }
    
    
    // Channel test/debug and special functions

    /*********************************************************************
     * Function:        void DmaChnSetEvFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function sets the event flags for the selected DMA channel.
     *                  Multiple flags can be orr-ed together. Any flag that is set in the eFlags will be
     *                  set for the selected channel, the other channel event flags won't be touched.
     *
     * Note:            This is intended as a channel test function.
     *
     * Example:         DmaChnSetEvFlags(DMA_CHANNEL0, DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_BLOCK_DONE|DMA_EV_SRC_FULL);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline))     
DmaChnSetEvFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->intrSet = (eFlags << __DCHxINT_MASK_(CHERIF_POSITION));               // set the corresponding bits
}
     
    /*********************************************************************
     * Function:        void DmaChnWriteEvFlags(DmaChannel chn, DmaEvFlags eFlags)
     *
     * PreCondition:    chn - valid DMA channel
     *
     * Input:           chn     - DMA channel number
     *                  eFlags  - event flags with the following significance:
     *                              - DMA_EV_ERR: address error event
     *                              - DMA_EV_ABORT: transfer abort event
     *                              - DMA_EV_CELL_DONE: cell transfer complete event
     *                              - DMA_EV_BLOCK_DONE: block transfer complete event
     *                              - DMA_EV_DST_HALF: destination half event
     *                              - DMA_EV_DST_FULL: destination full event
     *                              - DMA_EV_SRC_HALF: source half event
     *                              - DMA_EV_SRC_FULL: source full event
     *                              - DMA_EV_ALL_EVNTS: all of the above flags
     *
     * Output:          None
     *
     * Side Effects:    None
     *
     * Overview:        The function writes the event flags for the selected DMA channel.
     *                  The channel event flags are forced to the eFlags value.
     *
     * Note:            This is intended as a channel test function.
     *
     * Example:         DmaChnWriteEvFlags(DMA_CHANNEL0, DMA_EV_ERR|DMA_EV_ABORT|DMA_EV_BLOCK_DONE|DMA_EV_SRC_FULL);
     ********************************************************************/
extern __inline__ void __attribute__((always_inline)) 
DmaChnWriteEvFlags( DmaChannel chn, DmaEvFlags eFlags )
{
	register volatile _DmaRegMap*	pReg = ((_DmaRegMap*)&DCH0CON) + chn;    
    
	pReg->intr_w = (eFlags << __DCHxINT_MASK_(CHERIF_POSITION));                // set the corresponding bits
}
     
    
#ifdef	__cplusplus
}
#endif

#endif	/* DMA_H */

