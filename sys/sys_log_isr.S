/*
 *  Created on: 30.08.2017
 *      Author: Georgi Angelov
 */

#include <xc.h>
#include <sys/asm.h> 
#include "FreeRTOSConfig.h"
#include "ISR_Support.h"
#include "config.h" 

/* DEBUG DMA Interrupt */    
#ifdef DBG_DMA   

.extern  ISR_DMA0 
.extern  portSAVE_CONTEXT 
.extern  portRESTORE_CONTEXT 
    
   .section .vector_134, code, keep
   .equ     __vector_dispatch_134, IntVectorSysDmaInstance0
   .global  __vector_dispatch_134
   .set     nomicromips
   .set     noreorder
   .set     nomips16
   .set     noat
   .ent  IntVectorSysDmaInstance0

IntVectorSysDmaInstance0:  
    portSAVE_CONTEXT    
    la    s6,  ISR_DMA0
    jalr  s6
    nop     
    portRESTORE_CONTEXT
    .end	IntVectorSysDmaInstance0
            
#endif