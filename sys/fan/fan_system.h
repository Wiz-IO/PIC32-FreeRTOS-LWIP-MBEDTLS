/*
		FileName: system.h
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


#ifndef _SYSTEM_HEADER_FILE
#define _SYSTEM_HEADER_FILE

#include <xc.h>
#include "fan_int.h"
#include "fan_lock.h"
#include "fan_pcache.h"


#ifdef __cplusplus
extern "C"
  {
#endif
    
    
// *****************************************************************************
// *****************************************************************************
// Section: SYS Data Types
// *****************************************************************************
// *****************************************************************************    
    
    
// *****************************************************************************
/* SYS Initialize structure

  Summary:
    Identifies the system device control initialize structure.

  Description:
    This structure identifies the system device control initialize structure.

  Remarks:
    None.
*/    
    
    
// *****************************************************************************
/* SYS_CACHE_COHERENCY enumeration

   Summary:
    System L1 cache coherency settings.

   Description:
    This enumeration defines the supported system L1 cache coherency settings.

   Remarks:
    Used to read or write cache coherency policy for kseg0.
*/

typedef enum
{
    SYS_CACHE_WRITETHROUGH_NO_WRITEALLOCATE = 0,

    SYS_CACHE_WRITETHROUGH_WRITEALLOCATE = 1,

    SYS_CACHE_DISABLE = 2,

    SYS_CACHE_WRITEBACK_WRITEALLOCATE = 3

} SYS_CACHE_COHERENCY;
    
    
// *****************************************************************************
/* Function:
    void SYSSetCacheCoherency(SYS_CACHE_COHERENCY cacheCoherency)

  Summary:
    Set the cache coherency attribute for kseg0.

  Description:
    Set the cache coherency attribute for kseg0.

  Remarks:
    Use with caution. May cause unpredictable behavior in a running
    system.
*/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
SYSSetCacheCoherency( SYS_CACHE_COHERENCY cacheCoherency )
{
    uint32_t cp0;
    cp0 = _mfc0(16, 0);
    cp0 &= ~0x07;
    cp0 |= cacheCoherency;
    _mtc0(16, 0, cp0);
}    
    
// *****************************************************************************
/* Function:
    SYS_CACHE_COHERENCY SYSGetCacheCoherency(void)

  Summary:
    Returns the current cache coherency attribute for kseg0.

  Description:
    Returns the current cache coherency attribute for kseg0.

  Remarks:
    None.
*/
SYS_CACHE_COHERENCY extern inline __attribute__((nomips16,nomicromips,always_inline)) 
SYSGetCacheCoherency( void )
{
    return _mfc0(16, 0) & 0x03;
}

/*********************************************************************
 * Function:        void CheKseg0CacheOff(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          none
 * Side Effects:    Sets the CCA field in the Config register of Co-
 *                  processor 0 to the value "010"b
 * Overview:        This routine is used to disable cacheability of KSEG0.
 *
 * Note:            This macro cannot be executed in MIPS16 mode
 *
 ********************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
CheKseg0CacheOff( void )
{
    SYSSetCacheCoherency(SYS_CACHE_DISABLE); 
}

/*********************************************************************
 * Function:        void CheKseg0CacheOn(void)
 *
 * PreCondition:    None
 * Input:           None
 * Output:          none
 * Side Effects:    Sets the CCA field in the Config register of Co-
 *                  processor 0 to the value "011"b
 * Overview:        This routine is used to enable cacheability of KSEG0.
 *
 * Note:            This macro cannot be executed in MIPS16 mode
 *
 ********************************************************************/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
CheKseg0CacheOn( void )
{
    SYSSetCacheCoherency(SYS_CACHE_WRITEBACK_WRITEALLOCATE); 
}

// *****************************************************************************
/* Function:
    void SysPerformanceConfig( unsigned int sysclk, 
                               PCACHE_PREFETCH_ENABLE prefetch )

  Summary:
    Configures the PFM wait states and prefetch (cache) module for maximum 
    performance.

  Description:
    This function configures the PFM wait states and prefetch (cache) module 
    for maximum performance.

  Remarks:
    None.
*/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
SysPerformanceConfig( unsigned int sysclk, PCACHE_PREFETCH_ENABLE prefetch )
{
    unsigned int status;
    BOOL ecc;

    /* Interrupts must be disabled when enabling the Prefetch Cache Module */
    status = INTDisableInterrupts();
//    CheKseg0CacheOff();
    
    /* Set the PFM wait states based on the system clock and ECC setting */
    if( PcacheExistsWaitState() )
    {
        int ws; /* number of wait states */

        /* Is ECC enabled? */
        /* TODO: replace register read with plib when available */
        ecc = (((CFGCON & 0x00000030) >> 4) < 2) ? TRUE : FALSE;
        if(sysclk <= (ecc ? 74000000 : 60000000))
            ws = 0;
        else if(sysclk <= (ecc ? 140000000 : 120000000))
            ws = 1;
        else if(sysclk <= (ecc ? 200000000 : 200000000))
            ws = 2;
        else
            ws = 4;
        
        PcacheSetWaitState(ws);
    }

    /* Enable Prefetch Cache Module */
    if( PcacheExistsPrefetchEnable() )
    {
        PcacheSetPrefetchEnable(prefetch);       
    }
    
//    CheKseg0CacheOn();
    INTRestoreInterrupts(status);
}


// *****************************************************************************
/* Function:
    void SysWaitStateConfig( unsigned int sysclk )

  Summary:
    Configures the PFM wait states for maximum performance.

  Description:
    This function configures the PFM wait states module 
    for maximum performance.

  Remarks:
    None.
*/
void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
SysWaitStateConfig( unsigned int sysclk )
{
    unsigned int status;
    BOOL ecc;

    /* Interrupts must be disabled when enabling the Prefetch Cache Module */
    status = INTDisableInterrupts();
    
    int ws; /* number of wait states */

    /* Is ECC enabled? */
    /* TODO: replace register read with plib when available */
    ecc = (((CFGCON & 0x00000030) >> 4) < 2) ? TRUE : FALSE;
    if(sysclk <= (ecc ? 74000000 : 60000000))
        ws = 0;
    else if(sysclk <= (ecc ? 140000000 : 120000000))
        ws = 1;
    else if(sysclk <= (ecc ? 200000000 : 200000000))
        ws = 2;
    else
        ws = 4;
        
    PcacheSetWaitState(ws);
    
    INTRestoreInterrupts(status);
}


#ifdef __cplusplus
  }
#endif
#endif

