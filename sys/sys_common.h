/* 
 * File:   common.h
 * Author: HP
 *
 * Created on 22 Август 2018, 22:28
 */

#ifndef COMMON_H
#define	COMMON_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
    
unsigned char spi_calutate_brg(unsigned int pb_clk, unsigned int spi_clk);    
void ByteToHexStr(unsigned char * source, char * dest, int sourceLen);    


#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

