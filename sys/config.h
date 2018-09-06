
/* 
 * File:   config.h
 * Author: Georgi Angelov
 *
 * Created on 04.09.2018, 21:15
 */

#ifndef ___CONFIG_H
#define	___CONFIG_H

#define SYS_CLK_FREQ                (200000000ul)
#define SYS_CLK_BUS_PERIPHERAL_1    (100000000ul)

#define FREERTOS

#define DEBUG               /* GLOBAL ENABLE */
#define DBG_SPEED           115200
//#define DBG_USE_DMA    
#define DBG_BUF_MAX 512     /* for DMA debug buffer is coherent */

// WIFI SSID mrf.h /////////////////////////////////////////////////////////////
//#define WDRV_DEFAULT_SSID         "Comet Guest Room"    
#define WDRV_DEFAULT_SSID           "THE WIZARD"


#endif	/* ___CONFIG_H */



 