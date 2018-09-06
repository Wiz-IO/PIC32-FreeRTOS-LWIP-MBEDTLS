/*
		FileName: nvm.h
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

#ifndef NVM_H
#define	NVM_H

#include <xc.h>
#include "fan_common.h"
#include "fan_int.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define PAGE_SIZE                               4096                // # of 32-bit Instructions per Page
#define BYTE_PAGE_SIZE                          (4 * PAGE_SIZE)     // Page size in Bytes
#define ROW_SIZE                                512                 // # of 32-bit Instructions per Row
#define BYTE_ROW_SIZE                           (4 * ROW_SIZE)      // # Row size in Bytes
#define NUM_ROWS_PAGE                           8                   //Number of Rows per Page

#define _DRV_NVM_KVA_TO_PA(address)             (address & 0x1FFFFFFF)    
    
    
#ifndef mNVMUnlockOpLock
#define mNVMUnlockOpLock                        mNVMUnlockOpLockLLD
#endif
    
#ifndef NVMSelectMemoryOperation
#define NVMSelectMemoryOperation                NVMSelectMemoryOperationLLD
#endif
    
#ifndef NVMEnableMemoryModify
#define NVMEnableMemoryModify                   NVMEnableMemoryModifyLLD
#endif  
    
#ifndef NVMInhibitMemoryModify
#define NVMInhibitMemoryModify                  NVMInhibitMemoryModifyLLD
#endif 
    
#ifndef NVMWriteFlashKeySequence
#define NVMWriteFlashKeySequence                NVMWriteFlashKeySequenceLLD
#endif 
    
#ifndef NVMReadFlash
#define NVMReadFlash                            NVMReadFlashLLd
#endif 
    
#ifndef NVMWriteFlashStart
#define NVMWriteFlashStart                      NVMWriteFlashStartLLD
#endif     
    
#ifndef NVMStartFlashErase
#define NVMStartFlashErase                      NVMStartFlashEraseLLD
#endif 

#ifndef NVMHasFlashWriteCycleCompleted
#define NVMHasFlashWriteCycleCompleted          NVMHasFlashWriteCycleCompletedLLD
#endif 
    
#ifndef NVMToModifyFlashAddress
#define NVMToModifyFlashAddress                 NVMToModifyFlashAddressLLD
#endif 

#ifndef NVMProvideFlashData
#define NVMProvideFlashData                     NVMProvideFlashDataLLD
#endif 
    
#ifndef NVMBlockDataSourceAddress
#define NVMBlockDataSourceAddress               NVMBlockDataSourceAddressLLD
#endif     
    
#ifndef NVMProvideFlashQuadData
#define NVMProvideFlashQuadData                 NVMProvideFlashQuadDataLLD
#endif  
    
#ifndef NVMProvideExistsQuadData
#define NVMProvideExistsQuadData                NVMProvideExistsQuadDataLLD
#endif  
    
#ifndef NVMHasWriteOperationTerminated
#define NVMHasWriteOperationTerminated          NVMHasWriteOperationTerminatedLLD
#endif  
    
#ifndef NVMSelectFlashSwapLock
#define NVMSelectFlashSwapLock                  NVMSelectFlashSwapLockLLD
#endif      
    
#ifndef NVMGetFlashSwapLockStatus
#define NVMGetFlashSwapLockStatus               NVMGetFlashSwapLockStatusLLD
#endif  

#ifndef NVMSetLowerRegionProgramFlashBank1
#define NVMSetLowerRegionProgramFlashBank1      NVMSetLowerRegionProgramFlashBank1LLD
#endif  
    
#ifndef NVMSetLowerRegionProgramFlashBank2
#define NVMSetLowerRegionProgramFlashBank2      NVMSetLowerRegionProgramFlashBank2LLD
#endif      
    
#ifndef NVMIsProgramFlashBank2LowerRegion
#define NVMIsProgramFlashBank2LowerRegion       NVMIsProgramFlashBank2LowerRegionLLD
#endif  
    
#ifndef NVMOperation
#define NVMOperation                            _NVMOperationLLD
#endif      
    
#ifndef NVMWriteWord
#define NVMWriteWord                            NVMWriteWordLLD
#endif  
    
#ifndef NVMWriteQuadWord
#define NVMWriteQuadWord                        NVMWriteQuadWordLLD
#endif     
    
#ifndef NVMWriteRow
#define NVMWriteRow                             NVMWriteRowLLD
#endif 

#ifndef NVMErasePage
#define NVMErasePage                            NVMErasePageLLD
#endif 

#ifndef NVMFlashErase
#define NVMFlashErase                           NVMFlashEraseLLD
#endif     
   
#ifndef NVMClearError
#define NVMClearError                           NVMClearErrorLLD
#endif    
    
#ifndef NVMProgram
#define NVMProgram                              NVMProgramLLD
#endif    
    
#ifndef NVMIsError   
#define NVMIsError                              mNVMIsErrorLLD
#endif  
      
/* NVM Flash Memory programming keys */    
typedef enum {

    NVM_UNLOCK_KEY1 = 0xAA996655,
    NVM_UNLOCK_KEY2 = 0x556699AA

} NVM_UNLOCK_KEYS;

typedef enum {

    NVM_ROW_SIZE = 0x800,
    NVM_PAGE_SIZE = 0x4000

} NVM_ROW_PAGE_SIZE;

typedef enum {

    WORD_PROGRAM_OPERATION = 0x1,
    ROW_PROGRAM_OPERATION = 0x3,
    PAGE_ERASE_OPERATION = 0x4,
    FLASH_ERASE_OPERATION = 0x7,
    UPPER_FLASH_REGION_ERASE_OPERATION = 0x6,
    LOWER_FLASH_REGION_ERASE_OPERATION = 0x5,
    QUAD_WORD_PROGRAM_OPERATION = 0x2,
    NO_OPERATION = 0x0

} NVM_OPERATION_MODE;

typedef enum {

    LOWER_BOOT_ALIAS_AREA = 0x8,
    UPPER_BOOT_ALIAS_AREA = 0x0

} NVM_BOOT_MEMORY_AREA;

typedef enum {

    LOWER_BOOT_ALIAS_PAGE4 = 0xC,
    LOWER_BOOT_ALIAS_PAGE3 = 0xB,
    LOWER_BOOT_ALIAS_PAGE2 = 0xA,
    LOWER_BOOT_ALIAS_PAGE1 = 0x9,
    LOWER_BOOT_ALIAS_PAGE0 = 0x8,
    UPPER_BOOT_ALIAS_PAGE4 = 0x4,
    UPPER_BOOT_ALIAS_PAGE3 = 0x3,
    UPPER_BOOT_ALIAS_PAGE2 = 0x2,
    UPPER_BOOT_ALIAS_PAGE1 = 0x1,
    UPPER_BOOT_ALIAS_PAGE0 = 0x0

} NVM_BOOT_MEMORY_PAGE;

typedef enum {

    NVM_FLASH_SWAP_UNLOCKED = 0x0,
    NVM_FLASH_SWAP_LOCKED = 0x1,
    NVM_FLASH_SWAP_LOCKED_UNTIL_RESET = 0x3

} NVM_FLASH_SWAP_LOCK_TYPE;

typedef enum {

    NVM_LOWER_PROGRAM_FLASH_MEMRY = 0x0,
    NVM_UPPER_PROGRAM_FLASH_MEMRY

} NVM_FLASH_ERASE_REGION_TYPE;


/*********************  start of low level functions **************************************/

/*********************************************************************
  Function:        void mNVMUnlockOpLock(op)

  PreCondition:    None

  Input:           Operator to be performed between unlocking and locking the NVM.

  Output:          None


  Side Effects:    The system will be unlocked, the NVM operation(s) passed as 
            parameter will be executed and the system will be locked again.

  Note:            None
 ********************************************************************/
#define mNVMUnlockOpLockLLD(op)    do{int intStat; intStat=INTDisableInterrupts(); \
            NVMKEY = 0; NVMKEY = 0xAA996655; NVMKEY = 0x556699AA; \
            (op); \
            NVMKEY = 0x33333333; \
            INTRestoreInterrupts(intStat);}while(0)


//******************************************************************************
/* Function :  NVMSelectMemoryOperationLLD

  Summary:
    Implements Default variant of NVMSelectMemoryOperationLLD 

  Description:
    This template implements the Default variant of the NVMSelectMemoryOperationLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0"))) 
NVMSelectMemoryOperationLLD( NVM_OPERATION_MODE	opmode )
{
    /* Clear and Set, as NVMCON contains status bits and 
       hence need to be accessed atomically.
       Using bit field access may erroneously cause status bits to get cleared */
    NVMCONCLR = _NVMCON_NVMOP_MASK;
    NVMCONSET = ( _NVMCON_NVMOP_MASK & (((uint32_t)opmode) << _NVMCON_NVMOP_POSITION) );
}    
    
//******************************************************************************
/* Function :  NVMEnableMemoryModifyLLD

  Summary:
    Implements Default variant of NVMEnableMemoryModifyLLD 

  Description:
    This template implements the Default variant of the NVMEnableMemoryModifyLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMEnableMemoryModifyLLD( void )
{
    NVMCONSET = _NVMCON_WREN_MASK;
}

//******************************************************************************
/* Function :  NVMInhibitMemoryModifyLLD

  Summary:
    Implements Default variant of NVMInhibitMemoryModifyLLD 

  Description:
    This template implements the Default variant of the NVMInhibitMemoryModifyLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMInhibitMemoryModifyLLD( void )
{
    NVMCONCLR = _NVMCON_WREN_MASK;
}

//******************************************************************************
/* Function :  NVMWriteFlashKeySequenceLLD

  Summary:
    Implements Default variant of NVMWriteFlashKeySequenceLLD 

  Description:
    This template implements the Default variant of the NVMWriteFlashKeySequenceLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMWriteFlashKeySequenceLLD( uint32_t keysequence ) 
{
    NVMKEY = keysequence;
}

//******************************************************************************
/* Function :  NVMReadFlashLLD

  Summary:
    Implements Default variant of NVMReadFlashLLD 

  Description:
    This template implements the Default variant of the NVMReadFlashLLD function.
*/
extern __inline__ uint32_t __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMReadFlashLLD( uint32_t address )
{
    return ( *((uint32_t *)(address)) );
}

//******************************************************************************
/* Function :  NVMWriteFlashStartLLD

  Summary:
    Implements Default variant of NVMWriteFlashStartLLD 

  Description:
    This template implements the Default variant of the NVMWriteFlashStartLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMWriteFlashStartLLD( void )
{
    NVMCONSET = _NVMCON_WR_MASK;
}

//******************************************************************************
/* Function :  NVMStartFlashEraseLLD

  Summary:
    Implements Default variant of NVMStartFlashEraseLLD 

  Description:
    This template implements the Default variant of the NVMStartFlashEraseLLD function.
*/
extern __inline__ void __attribute__((always_inline)) 
NVMStartFlashEraseLLD( void )
{
    NVMCONSET = _NVMCON_WR_MASK;
}

//******************************************************************************
/* Function :  NVM_FlashWriteCycleHasCompletedLLD

  Summary:
    Implements Default variant of PLIB_NVM_FlashWriteCycleHasCompletedLLD 

  Description:
    This template implements the Default variant of the PLIB_NVM_FlashWriteCycleHasCompletedLLD function.
*/
extern __inline__ BOOL __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMHasFlashWriteCycleCompletedLLD( void )
{
    return (!(BOOL)NVMCONbits.WR);
}

//******************************************************************************
/* Function :  NVMToModifyFlashAddressLLD

  Summary:
    Implements Default variant of NVMToModifyFlashAddressLLD 

  Description:
    This template implements the Default variant of the NVMToModifyFlashAddressLLD function.
*/
extern __inline__ void __attribute__((nomicromips, always_inline)) __attribute__((optimize("-O0")))
NVMToModifyFlashAddressLLD( uint32_t address )
{
    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    NVMADDR = address;
}

//******************************************************************************
/* Function :  NVMProvideFlashDataLLD

  Summary:
    Implements Default variant of NVMProvideFlashDataLLD 

  Description:
    This template implements the Default variant of the NVMProvideFlashDataLLD function.
*/
extern __inline__ void __attribute__((always_inline)) 
NVMProvideFlashDataLLD( uint32_t data )
{
    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    NVMDATA0 = data;
}

//******************************************************************************
/* Function :  NVMBlockDataSourceAddressLLD

  Summary:
    Implements Default variant of NVMBlockDataSourceAddressLLD 

  Description:
    This template implements the Default variant of the NVMBlockDataSourceAddressLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMBlockDataSourceAddressLLD( uint32_t address )
{
    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    NVMSRCADDR = address;
}

//******************************************************************************
/* Function :  NVMProvideFlashQuadDataLLD

  Summary:
    Implements Default variant of NVMProvideFlashQuadDataLLD 

  Description:
    This template implements the Default variant of the NVMProvideFlashQuadDataLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMProvideFlashQuadDataLLD( uint32_t *data )
{
    int int_status; // storage for current Interrupt Enable state
    uint8_t flashData;
    
    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    // Disable Interrupts
    asm volatile("di %0" : "=r"(int_status));
    
    for(flashData = 0u; flashData < 4u; flashData++)
    {
        *(volatile uint32_t *)(&NVMDATA0 + (flashData * 4u)) = *(data + flashData);
    }  
    
    // Restore Interrupts
    if(int_status & 0x00000001)
    {
        asm volatile("ei");
    }    
}

//******************************************************************************
/* Function :  NVMProvideExistsQuadDataLLD

  Summary:
    Implements Default variant of NVMProvideExistsQuadDataLLD

  Description:
    This template implements the Default variant of the NVMProvideExistsQuadDataLLD function.
*/
extern __inline__ BOOL __attribute__((always_inline)) 
NVMProvideExistsQuadDataLLD( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  NVMHasWriteOperationTerminatedLLD

  Summary:
    Implements Default variant of NVMHasWriteOperationTerminatedLLD 

  Description:
    This template implements the Default variant of the NVMHasWriteOperationTerminatedLLD function.
*/
extern __inline__ BOOL __attribute__((always_inline)) 
NVMHasWriteOperationTerminatedLLD( void )
{
    return (BOOL)NVMCONbits.WRERR;
}

//******************************************************************************
/* Function :  NVMSelectFlashSwapLockLLD

  Summary:
    Implements Default variant of NVMSelectFlashSwapLockLLD 

  Description:
    This template implements the Default variant of the NVMSelectFlashSwapLockLLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0"))) 
NVMSelectFlashSwapLockLLD( NVM_FLASH_SWAP_LOCK_TYPE lockType )
{
    NVMCON2bits.SWAPLOCK = lockType;
}

//******************************************************************************
/* Function :  NVMGetFlashSwapLockStatusLLD

  Summary:
    Implements Default variant of NVMGetFlashSwapLockStatusLLD 

  Description:
    This template implements the Default variant of the NVMGetFlashSwapLockStatusLLD function.
*/
extern __inline__ NVM_FLASH_SWAP_LOCK_TYPE __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMGetFlashSwapLockStatusLLD( void )
{
    return (NVM_FLASH_SWAP_LOCK_TYPE)NVMCON2bits.SWAPLOCK;
}



//******************************************************************************
/* Function :  NVMSetLowerRegionProgramFlashBank1LLD

  Summary:
    Implements Default variant of NVMSetLowerRegionProgramFlashBank1LLD 

  Description:
    This template implements the Default variant of the NVMSetLowerRegionProgramFlashBank1LLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0"))) 
NVMSetLowerRegionProgramFlashBank1LLD( void )
{
    NVMCONCLR = _NVMCON_PFSWAP_MASK;
}

//******************************************************************************
/* Function :  NVMSetLowerRegionProgramFlashBank2LLD

  Summary:
    Implements Default variant of NVMSetLowerRegionProgramFlashBank2LLD 

  Description:
    This template implements the Default variant of the NVMSetLowerRegionProgramFlashBank2LLD function.
*/
extern __inline__ void __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMSetLowerRegionProgramFlashBank2LLD( void )
{
    NVMCONSET = _NVMCON_PFSWAP_MASK;
}

//******************************************************************************
/* Function :  NVMIsProgramFlashBank2LowerRegionLLD

  Summary:
    Implements Default variant of NVMIsProgramFlashBank2LowerRegionLLD 

  Description:
    This template implements the Default variant of the NVMIsProgramFlashBank2LowerRegionLLD function.
*/
extern __inline__ BOOL __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMIsProgramFlashBank2LowerRegionLLD( void )
{
    return (BOOL)NVMCONbits.PFSWAP;
}

/*********************************************************************
 * Function:        NVMIsErrorLLD()
 *
 * Description:     Reads the NVMCON Error flags.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          '0' if error flag is not set.
 *
 * Example:         if(NVMIsErrorLLD())
 *                      NVMClearErrorLLD();
 ********************************************************************/
#define mNVMIsErrorLLD()    (NVMCON & (_NVMCON_WRERR_MASK | _NVMCON_LVDERR_MASK))

/*********************  end of low level functions ****************************************/


/* Helper function */
extern __inline__ unsigned int __attribute__((nomicromips, always_inline)) __attribute__((optimize("-O0")))
_NVMOperationLLD( uint32_t nvmop )
{
int int_status; // storage for current Interrupt Enable state
int dma_susp; // storage for current DMA state

    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    
    // set the operation, assumes WREN = 0
    NVMCONbits.NVMOP = nvmop; // NVMOP for Word programming

    // Enable Flash for write operation and set the NVMOP
    NVMCONbits.WREN = 1;

    // Disable Interrupts
    asm volatile("di %0" : "=r"(int_status));
    
    // Disable DMA
    if(!(dma_susp=DMACONbits.SUSPEND))
    {
        DMACONSET=_DMACON_SUSPEND_MASK; // suspend
        while((DMACONbits.DMABUSY)); // wait to be actually suspended
    }
    
    NVMKEY = 0x0;
    NVMKEY = 0xAA996655;
    NVMKEY = 0x556699AA;
    NVMCONSET = 1 << 15; // must be an atomic instruction
    
    // Restore DMA
    if(!dma_susp)
    {
        DMACONCLR=_DMACON_SUSPEND_MASK; // resume DMA activity
    }
    
    // Restore Interrupts
    if(int_status & 0x00000001)
    {
        asm volatile("ei");
    }
    
    // Wait for WR bit to clear
    while(NVMCONbits.WR);
    
    // Disable future Flash Write/Erase operations
    NVMCONbits.WREN = 0;
    
    // Return Error Status
    return(mNVMIsErrorLLD());
}

/* Helper function */
//#pragma GCC optimize 0
extern __inline__ BOOL __attribute__((nomicromips, always_inline)) __attribute__((optimize("-O0")))
_NVMIsPageBlankLLD( void* address )
{
    BOOL result = TRUE;
    unsigned int i;

    volatile unsigned int *faddress;
    faddress = (volatile unsigned int *)PA_TO_KVA1((KVA_TO_PA(address) & (~NVM_PAGE_SIZE + 1)));
    
    for( i=0; i<(NVM_PAGE_SIZE/4); i++ )
    {
        if( 0xFFFFFFFF != *faddress++)
        {
            result = FALSE;
            break;
        }
    }
    return result;
}

/*********************************************************************
 * Function:        unsigned int NVMClearErrorLLD(void)
 *
 * Description:     If the NVMCON error flag is set, it can only be cleared
 *                  by performing an NVM NOP opertion.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NMVClearErrorLLD()
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline))
NVMClearErrorLLD( void )
{
    unsigned int res; 
    
    res = _NVMOperationLLD(NO_OPERATION);
    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMWriteWordLLD(void* address, unsigned int data)
 *
 * Description:     The smallest block of data that can be programmed in
 *                  a single operation is 1 instruction word (4 Bytes).  The word at
 *                  the location pointed to by NVMADDR is programmed.
 *
 * PreCondition:    None
 *
 * Inputs:          address:   Destination address to write.
 *                  data:      Word to write.
 *
 * Output:          '0' if operation completed successfully.
 *                  '1' if ECC settings is not supported.
 * Example:         NVMWriteWordLLD((void*) 0xBD000000, 0x12345678)
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) __attribute__((optimize("-O0"))) 
NVMWriteWordLLD( void* address, unsigned int data )
{
    unsigned int res;
    unsigned int addr = _DRV_NVM_KVA_TO_PA((unsigned int)address);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO    
    uint32_t processorStatus;   
    BOOL nvm_inten_flag = FALSE;
    BOOL usb_inten_flag = FALSE;
#endif  
    
    if( CFGCONbits.ECCCON < DEVCON_ECC_DISABLED_LOCKED )
    {
       return 1;                // Error unsupported mode for Word write op. 
    }
#ifdef NVM_USE_ADDITIONAL_SYNCHRO
    processorStatus = INTDisableInterrupts();
    nvm_inten_flag = mFCEGetIntEnable();
    usb_inten_flag = IEC4bits.USBIE;
    mFCEIntEnable(FALSE);        
    IEC4bits.USBDMAIE = 0;
    IEC4bits.USBIE = 0;
#endif    
    if( mNVMIsErrorLLD() )
    {
        res = NVMClearErrorLLD();
    }
    NVMToModifyFlashAddressLLD(addr);
    NVMProvideFlashDataLLD(data);
    res = _NVMOperationLLD(WORD_PROGRAM_OPERATION); 
#ifdef NVM_USE_ADDITIONAL_SYNCHRO    
    mFCEClearIntFlag();
    if(nvm_inten_flag) mFCEIntEnable(TRUE);
    if(nvm_inten_flag)
    {
        IEC4bits.USBIE = 1;     
        IEC4bits.USBDMAIE = 1;
    }
    INTRestoreInterrupts(processorStatus);
#endif    
    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMWriteWordLLD(void* address, unsigned int data)
 *
 * Description:     The smallest block of data that can be programmed in
 *                  a single operation is 1 instruction word (4 Bytes).  The word at
 *                  the location pointed to by NVMADDR is programmed.
 *
 * PreCondition:    None
 *
 * Inputs:          address:   Destination address to write.
 *                  data:      Word to write.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMWriteWordLLD((void*) 0xBD000000, 0x12345678)
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline))
NVMWriteQuadWordLLD( void* address, unsigned int* data )
{
    unsigned int res = 0;
    unsigned int addr = _DRV_NVM_KVA_TO_PA((unsigned int)address);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO    
    uint32_t processorStatus;   
    BOOL nvm_inten_flag = FALSE;
    BOOL usb_inten_flag = FALSE;
#endif  
    
    if( NVMProvideExistsQuadDataLLD() )
    {
#ifdef NVM_USE_ADDITIONAL_SYNCHRO
        processorStatus = INTDisableInterrupts();
        nvm_inten_flag = mFCEGetIntEnable();
        usb_inten_flag = IEC4bits.USBIE;
        mFCEIntEnable(FALSE);        
        IEC4bits.USBDMAIE = 0;
        IEC4bits.USBIE = 0;
#endif 
        if( mNVMIsErrorLLD() )
        {
            res = NVMClearErrorLLD();
        }
        NVMToModifyFlashAddressLLD(addr);
        NVMProvideFlashQuadDataLLD(data);
        res = _NVMOperationLLD(QUAD_WORD_PROGRAM_OPERATION);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO        
        mFCEClearIntFlag();
        if(nvm_inten_flag) mFCEIntEnable(TRUE);
        if(nvm_inten_flag)
        {
            IEC4bits.USBIE = 1;     
            IEC4bits.USBDMAIE = 1;
        }
        INTRestoreInterrupts(processorStatus);
#endif 
    }
    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMWriteRowLLD(void* address, void* data)
 *
 * Description:     The largest block of data that can be programmed in
 *                  a single operation is 1 row 512 instructions ( 2KBytes).  The row at
 *                  the location pointed to by NVMADDR is programmed with the data buffer
 *                  pointed to by NVMSRCADDR.
 *
 * PreCondition:    The row of data must be pre-loaded into a buffer in RAM.
 *
 * Inputs:          address:  Destination Row address to write.
 *                  data:  Location of data to write.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMWriteRowLLD((void*) 0xBD000000, (void*) 0xA0000000)
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline))
NVMWriteRowLLD( void* address, void* data )
{
    unsigned int res;
    unsigned int addr = _DRV_NVM_KVA_TO_PA((unsigned int)address);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO    
    uint32_t processorStatus;   
    BOOL nvm_inten_flag = FALSE;
    BOOL usb_inten_flag = FALSE;

    processorStatus = INTDisableInterrupts();
    nvm_inten_flag = mFCEGetIntEnable();
    usb_inten_flag = IEC4bits.USBIE;
    mFCEIntEnable(FALSE);        
    IEC4bits.USBDMAIE = 0;
    IEC4bits.USBIE = 0;
#endif     
    if( mNVMIsErrorLLD() )
    {
        res = NVMClearErrorLLD();
    }
    NVMToModifyFlashAddressLLD(addr);
    NVMBlockDataSourceAddressLLD(_DRV_NVM_KVA_TO_PA((unsigned int)data));
    res = _NVMOperationLLD(ROW_PROGRAM_OPERATION);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO        
    mFCEClearIntFlag();
    if(nvm_inten_flag) mFCEIntEnable(TRUE);
    if(nvm_inten_flag)
    {
        IEC4bits.USBIE = 1;     
        IEC4bits.USBDMAIE = 1;
    }
    INTRestoreInterrupts(processorStatus);
#endif     
    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMErasePageLLD(void* address)
 *
 * Description:     A page erase will erase a single page of program flash,
 *                  which equates to 4k instructions (16KBytes). The page to
 *                  be erased is selected using NVMADDR. The lower bytes of
 *                  the address given by NVMADDR are ignored in page selection.
 *
 * PreCondition:    None
 *
 * Inputs:          address:  Destination page address to Erase.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMErasePageLLD((void*) 0xBD000000)
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) __attribute__((optimize("-O0")))
NVMErasePageLLD( void* address )
{
    unsigned int res = 0; 
#ifdef NVM_USE_ADDITIONAL_SYNCHRO    
    uint32_t processorStatus;   
    BOOL nvm_inten_flag = FALSE;
    BOOL usb_inten_flag = FALSE;
#endif    
    if( ! _NVMIsPageBlankLLD(address))    
    {
#ifdef NVM_USE_ADDITIONAL_SYNCHRO        
        processorStatus = INTDisableInterrupts();
        nvm_inten_flag = mFCEGetIntEnable();
        usb_inten_flag = IEC4bits.USBIE;
        mFCEIntEnable(FALSE);        
        IEC4bits.USBDMAIE = 0;
        IEC4bits.USBIE = 0;
#endif        
        if( mNVMIsErrorLLD() )
        {
            res = NVMClearErrorLLD();
        }
        NVMToModifyFlashAddressLLD(_DRV_NVM_KVA_TO_PA((volatile unsigned int)address));
        res = _NVMOperationLLD(PAGE_ERASE_OPERATION);
#ifdef NVM_USE_ADDITIONAL_SYNCHRO        
        mFCEClearIntFlag();
        if(nvm_inten_flag) mFCEIntEnable(TRUE);
        if(nvm_inten_flag)
        {
            IEC4bits.USBIE = 1;     
            IEC4bits.USBDMAIE = 1;
        }
        INTRestoreInterrupts(processorStatus);
#endif        
    }
    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMFlashEraseLLD(NVM_FLASH_ERASE_REGION_TYPE region)
 *
 * Description:     NVMFlashErase will erase a single flash region of program flash,
 *
 * PreCondition:    None
 *
 * Inputs:          region:  Destination flash region to Erase.
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMFlashEraseLLD(UPPER_FLASH_REGION_ERASE_OPERATION);
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline)) 
NVMFlashEraseLLD( NVM_FLASH_ERASE_REGION_TYPE region )
{
    unsigned int res;    
    NVM_OPERATION_MODE mode;
    
    if(region == NVM_LOWER_PROGRAM_FLASH_MEMRY)
    {
        mode = LOWER_FLASH_REGION_ERASE_OPERATION;
    }
    else if(region == NVM_UPPER_PROGRAM_FLASH_MEMRY)
    {
        mode = UPPER_FLASH_REGION_ERASE_OPERATION;   
    }
    else
    {
        return 1;
    }
    
    if( mNVMIsErrorLLD() )
    {
        res = NVMClearErrorLLD();
    }
    res = _NVMOperationLLD(mode);

    return res;
}

/*********************************************************************
 * Function:        unsigned int NVMProgramLLD(void* address, const void* data, unsigned int size void * pagebuff)
 *
 * Description:     Programs size characters from the source buffer to
 *                  Flash memory starting at the destination address.
 *
 * PreCondition:    None
 *
 * Inputs:          address:  Destination address to start writing from.
 *                  data:  Location of data to write.
 *                  size:  Number of bytes to write.
 *                  pagebuff:   Ram buffer to preserve 1 page worth of data
 *
 * Output:          '0' if operation completed successfully.
 *
 * Example:         NVMProgramLLD((void*) 0xBD000000, (const void*) 0xA0000000, 4096, (void *) 0xA0002000)
 ********************************************************************/
extern __inline__ unsigned int __attribute__((always_inline))  __attribute__((optimize("-O0")))
NVMProgramLLD( void * address, const void * data, unsigned int size, void* pagebuff )
{
    unsigned int res = 0;
    unsigned int pageStartAddr;
    unsigned int numBefore, numAfter, numLeftInPage;
    unsigned int index;

	// 1. Make sure that the size and pagebuff are word aligned
	if(size & 0x03 || (unsigned int)pagebuff & 3)
		return 1;

	if (size == 0)
		return 0;			// nothing to program

    // 2. Calculate Page Start address
    pageStartAddr = (unsigned int)address & (~(BYTE_PAGE_SIZE - 1));

    // 3. Calculate the number of bytes that need to be copied from Flash.
	numBefore = (unsigned int)address &   (BYTE_PAGE_SIZE - 1);

	// 4. Make a copy of original data, if necessary
	memcpy(pagebuff, (const void *)pageStartAddr, numBefore);

    while(size)
    {
        // 5. Determine how many to copy from Source data
        numLeftInPage = BYTE_PAGE_SIZE - numBefore;

        if(size <= numLeftInPage)
        {
            // Copy all of it
            memcpy((pagebuff + numBefore), (const void *)data, size);

            // Calculate the number of bytes that need to be stored after the address.
            numAfter = numLeftInPage - size;

            // Copy whats left
    	    if(numAfter)
    		    memcpy((pagebuff + numBefore + size), (const void *)((unsigned int)address + size), numAfter);

            size = 0;
        }
        else
        {
            // Copy numLeft of it
            memcpy((pagebuff + numBefore), (const void *)data, numLeftInPage);

            // decrement size
            size -= numLeftInPage;
            // Increment addresses
            address += numLeftInPage;
			data    += numLeftInPage;
        }

        if( mNVMIsErrorLLD() )
        {
            res = NVMClearErrorLLD();
        }
        // Erase the Page
        res = NVMErasePageLLD((void *)pageStartAddr);
        if(res) return res;
        
        // Program the Page
        for(index = 0; index < NUM_ROWS_PAGE; index++)
        {
            res = NVMWriteRowLLD((void *)(pageStartAddr + (index * BYTE_ROW_SIZE)), (void *)(pagebuff + (index * BYTE_ROW_SIZE)));
            if(res) return res;
        }
		numBefore = 0;			// done with partial page, move to page boundary
		pageStartAddr = (unsigned int)address;
    }

    return 0;
}


#ifdef	__cplusplus
}
#endif

#endif	/* NVM_H */
