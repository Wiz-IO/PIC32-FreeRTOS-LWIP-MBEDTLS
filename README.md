# PIC32-FreeRTOS-LWIP-MBEDTLS
Microchip Curiosity PIC32MZ - FreeRTOS - LWIP - MBEDTLS

**Hardware**
* Curiosity PIC32MZEF Development Board PIC32MZ2048EFM + MRF24WN0MA on-board 
https://www.microchip.com/DevelopmentTools/ProductDetails/dm320104

**Software**
* FreeRTOS v10.1.0 + umm_malloc
* lwip v2.0.2
* mbedtls
* MRF24WN Driver: at this stage - just to work

**PORTING**

**Board**

Config board at 200 mips
Debug: UART1 (DMA later)

**FreeRTOS**

FreeRTOSConfig.h
port.c - portTICK_PERIOD_MS = 10 msec
#define portTIMER_PRESCALE	64 /* 1:0, 8:1, 64:2, 256:3 */
#define portPRESCALE_BITS	2

umm_malloc_cfg.h 
#define UMM_MALLOC_CFG__HEAP_SIZE   (configTOTAL_HEAP_SIZE)

Linker options: --wrap,malloc --wrap,free
```
TEST...
[APP] --- BEGIN ---
[APP] - DRIVER -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WiFi Connecting . . .
[MRF] ConnectionStateSet( 1 )
[MRF] ConnectionStateUpdate( 1, 0 )
[MRF] Connected to AP
[MRF] ReceiveCB()
[MRF] ReceiveCB()
```

**LWIP**

```
TEST...
netif: netmask of interface .. set to 255.0.0.0
netif: GW address of interface .. set to 127.0.0.1
netif_set_ipaddr: netif address being changed
netif: IP address of interface .. set to 127.0.0.1
netif: added interface lo IP addr 127.0.0.1 netmask 255.0.0.0 gw 127.0.0.1
dns_init: initializing
[APP] --- BEGIN ---
[APP] - LWIP -
netif: IP address of interface .. set to 0.0.0.0
netif: netmask of interface .. set to 0.0.0.0
netif: GW address of interface .. set to 0.0.0.0
netif: added interface w0 IP addr 0.0.0.0 netmask 0.0.0.0 gw 0.0.0.0
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WiFi Connecting . . .
[MRF] ConnectionStateSet( 1 )
[MRF] ConnectionStateUpdate( 1, 0 )
[MRF] Connected to AP
[MRF] ReceiveCB()
```

**MBEDTLS**

...

in process....
