/*
		FileName: pcache.h
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

#ifndef PCACHE_H
#define	PCACHE_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum {

    PCACHE_PREFETCH_DISABLE = 0x00,
    PCACHE_PREFETCH_ENABLE_CPU_INST = 0x01,
    PCACHE_PREFETCH_ENABLE_CPU_INST_DATA = 0x02,
    PCACHE_PREFETCH_ENABLE_ALL = 0x03

} PCACHE_PREFETCH_ENABLE;    
    
typedef struct pfm_regs {
    __PRECONbits_t PRECON;
    volatile unsigned int PRECONCLR;
    volatile unsigned int PRECONSET;
    volatile unsigned int PRECONINV;
    __PRESTATbits_t PRESTAT;
    volatile unsigned int PRESTATCLR;
    volatile unsigned int PRESTATSET;
    volatile unsigned int PRESTATINV;
} pfm_register_t;    
    

//******************************************************************************
/* Function :  PcacheExistsWaitState

  Summary:
    Implements MZ variant of PcacheExistsWaitState

  Description:
    This template implements the MZ variant of the PcacheExistsWaitState function.
*/

#define PLIB_PCACHE_ExistsWaitState PLIB_PCACHE_ExistsWaitState
#define PLIB_PCACHE_ExistsWaitState PLIB_PCACHE_ExistsWaitState
BOOL extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheExistsWaitState( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  PcacheWaitStateSet

  Summary:
    Implements MZ variant of PcacheWaitStateSet 

  Description:
    This template implements the MZ variant of the PcacheWaitStateSet function.
    Operation is not atomic.
*/

void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheSetWaitState( uint32_t clocks )
{
    volatile pfm_register_t *regs = (pfm_register_t *)_PCACHE_BASE_ADDRESS;
    regs->PRECON.PFMWS = clocks;
}

//******************************************************************************
/* Function :  PcacheWaitStateGet

  Summary:
    Implements MZ variant of PcacheWaitStateGet 

  Description:
    This template implements the MZ variant of the PcacheWaitStateGet function.
    Operation is atomic.
*/

uint32_t extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheGetWaitState( void )
{
    volatile pfm_register_t *regs = (pfm_register_t *)_PCACHE_BASE_ADDRESS;
    return (uint32_t)(regs->PRECON.PFMWS);
}    

//******************************************************************************
/* Function :  PcacheExistsPrefetchEnable

  Summary:
    Implements MZ variant of PcacheExistsPrefetchEnable
PCACHE_E
  Description:
    This template implements the MZ variant of the PcacheExistsPrefetchEnable function.
*/

BOOL extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheExistsPrefetchEnable( void )
{
    return TRUE;
}

//******************************************************************************
/* Function :  PcachePrefetchEnableSet

  Summary:
    Implements MZ variant of PcachePCACHE_PrefetchEnableSet 

  Description:
    This template implements the MZ variant of the PcachePCACHE_PrefetchEnableSet function.
    Operation is not atomic.
*/

void extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheSetPrefetchEnable( PCACHE_PREFETCH_ENABLE region )
{
    volatile pfm_register_t *regs = (pfm_register_t *)_PCACHE_BASE_ADDRESS;
    regs->PRECON.PREFEN = region;
}

//******************************************************************************
/* Function :  PcachePrefetchEnableGet

  Summary:
    Implements MZ variant of PcachePCACHE_PrefetchEnableGet 

  Description:
    This template implements the MZ variant of the PcachePCACHE_PrefetchEnableGet function.
    Operation is atomic.
*/

PCACHE_PREFETCH_ENABLE extern inline __attribute__((nomips16,nomicromips,always_inline)) 
PcacheGetPrefetchEnable( void )
{
    volatile pfm_register_t *regs = (pfm_register_t *)_PCACHE_BASE_ADDRESS;
    return (PCACHE_PREFETCH_ENABLE)(regs->PRECON.PREFEN);
}


#ifdef	__cplusplus
}
#endif

#endif	/* PCACHE_H */

