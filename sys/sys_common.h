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
#include <ctype.h>    
    
unsigned char spi_calutate_brg(unsigned int pb_clk, unsigned int spi_clk);    
void ByteToHexStr(unsigned char * source, char * dest, int sourceLen);    
int strStartsWith(const char *line, const char *prefix);
int strncasecmp(const char *s1, const char *s2, size_t n) ;

/* in at_tok.c */
char * strsep(char **stringp, const char *delim);

#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

