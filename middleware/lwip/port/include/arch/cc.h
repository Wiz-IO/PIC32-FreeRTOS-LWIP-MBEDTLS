/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */
#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#include "sys.h"
#include "debug.h"

/* Include some files for defining library routines */
#include <stdint.h> 
#include <stdio.h> /* printf, fflush, FILE */
#include <string.h>
#include <stdlib.h> /* abort */
#include <errno.h>
#if (!defined(__CC_ARM)) && (!defined(__ICCARM__))
#include <sys/time.h>
#endif

#define BYTE_ORDER  LITTLE_ENDIAN
#define LWIP_PLATFORM_BYTESWAP 0

/** @todo fix some warnings: don't use #pragma if compiling with cygwin gcc */
//#ifndef __GNUC__
#if (!defined(__ICCARM__)) && (!defined(__GNUC__)) && (!defined(__CC_ARM))
	#include <limits.h>
	#pragma warning (disable: 4244) /* disable conversion warning (implicit integer promotion!) */
	#pragma warning (disable: 4127) /* conditional expression is constant */
	#pragma warning (disable: 4996) /* 'strncpy' was declared deprecated */
	#pragma warning (disable: 4103) /* structure packing changed by including file */
#endif

//#define LWIP_PROVIDE_ERRNO

/* Define generic types used in lwIP */
typedef uint8_t   u8_t;
typedef int8_t    s8_t;
typedef uint16_t  u16_t;
typedef int16_t   s16_t;
typedef uint32_t  u32_t;
typedef int32_t   s32_t;
typedef uintptr_t mem_ptr_t;
typedef u32_t sys_prot_t;

/* Define (sn)printf formatters for these lwIP types */
#define X8_F  "02x"
#define U16_F "hu"
#define S16_F "hd"
#define X16_F "hx"
#define U32_F "u"
#define S32_F "d"
#define X32_F "X"
#define SZT_F U32_F

#define PACK_STRUCT_STRUCT __attribute__( (packed) )

#define LWIP_LOGE(fmt,...)   TRACE("[ERR] "fmt,##__VA_ARGS__)
#define LWIP_LOGW(fmt,...)   TRACE("[WRN] "fmt,##__VA_ARGS__)
#define LWIP_LOGI(fmt,...)   TRACE(fmt,##__VA_ARGS__)

#define LWIP_PLATFORM_DIAG(x)   do { LWIP_LOGI x; } while(0)
#define LWIP_PLATFORM_ASSERT(x) do { TRACE("[ASSERT] \"%s\" failed at line %d in %s\n", x, __LINE__, __FILE__); } while(0)
#define LWIP_ERROR(message, expression, handler) do { if (!(expression)) { TRACE("[ASSERT] \"%s\" failed at line %d in %s\n", message, __LINE__, __FILE__); handler;} } while(0)

u32_t dns_lookup_external_hosts_file(const char *name);

#define LWIP_RAND() ((u32_t)rand())

#endif /* __ARCH_CC_H__ */
