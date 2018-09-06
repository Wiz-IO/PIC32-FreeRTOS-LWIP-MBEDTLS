/*
 *  Created on: 30.08.2018
 *      Author: Georgi Angelov
 */

#ifndef MRF_LIB_H
#define	MRF_LIB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h> 
#include <stdbool.h> 
    
void WDRV_Config(void);
void WDRV_Connect(void);
bool WDRV_isPacketValid(uint8_t const *const frame);
void MRF_ClientCacheUpdate(bool connected, uint8_t *mac);


#ifdef	__cplusplus
}
#endif

#endif	/* MRF_LIB_H */

