#ifndef _UMM_MALLOC_CFG_H
#define _UMM_MALLOC_CFG_H

#include "sys.h"
#include "FreeRTOSConfig.h"

#define UMM_MALLOC_CFG__HEAP_SIZE   (configTOTAL_HEAP_SIZE)
#define UMM_H_ATTPACKPRE
#define UMM_H_ATTPACKSUF            __attribute__((__packed__))
#define UMM_CRITICAL_ENTRY()        DISABLE_INT()
#define UMM_CRITICAL_EXIT()         ENABLE_INT()

#endif // _UMM_MALLOC_CFG_H



