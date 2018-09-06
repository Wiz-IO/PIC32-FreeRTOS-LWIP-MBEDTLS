/* 
 * File:   sys_log.h
 * Author: Georgi Angelov
 *
 * Created on 05.09.2018, 09:36
 */

#ifndef SYS_LOG_H
#define	SYS_LOG_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "config.h" 
#include <xc.h>    
#include <stdarg.h>
#include <stdio.h>
   
#undef printf
    
void sys_log_init(int32_t brg);
int Printf(const char * frm, ...);

#ifdef DEBUG
#   define printf                   Printf
#   define LOG(_F_, ARG...)         Printf( (const char*) _F_, ##ARG )
#   define LOG_ERROR()              Printf("[ERROR] %s() File: %s at Line %d\n", __FUNCTION__, __FILE__, __LINE__)
#else
#   define printf(_F_, ...)
#   define LOG(_STR_, arg...) 
#   define LOG_ERROR()
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* SYS_LOG_H */

