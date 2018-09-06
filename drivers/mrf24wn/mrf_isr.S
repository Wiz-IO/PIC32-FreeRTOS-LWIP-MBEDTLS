/*
 *  Created on: 30.08.2017
 *      Author: Georgi Angelov
 */

#include <xc.h>
#include <sys/asm.h>
#include "FreeRTOSConfig.h"
#include "ISR_Support.h"

.extern  ISR_MRF24WN 
.extern  portSAVE_CONTEXT 
.extern  portRESTORE_CONTEXT 

.section	.vector_18,code, keep
   .equ     __vector_dispatch_18, isr_mrf24wn
   .global  __vector_dispatch_18
   .set     nomicromips
   .set     noreorder
   .set     nomips16
   .set     noat
   .ent  isr_mrf24wn

isr_mrf24wn:
    portSAVE_CONTEXT
    la    s6,  ISR_MRF24WN
    jalr  s6
    nop
    portRESTORE_CONTEXT
    .end	isr_mrf24wn

/* EOF ************************************************************************/