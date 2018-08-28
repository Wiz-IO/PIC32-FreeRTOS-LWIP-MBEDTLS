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
[APP] --- BEGIN ---
[APP] - WIFI -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WiFi Connecting . . .
[MRF] ConnectionStateUpdate( 1 ) 
[MRF] DHCP started
[MRF] Connected to AP
[MRF] DHCP GOT IP: 192.168.12.36
[APP] WIFI READY
[APP] - IP: 192.168.12.36
[APP] - GW: 192.168.12.1
[APP] - MS: 255.255.255.0
[APP] - D0: 244.0.0.128
[APP] - D1: 248.0.0.128
[DNS] INPROGRESS
[DNS] google.com IP: 220.24.2.128
[DNS] DONE
HTTP/1.0 404 Not Found
Content-Type: text/html; charset=UTF-8
Referrer-Policy: no-referrer
Content-Length: 1570
Date: Tue, 28 Aug 2018 13:15:04 GMT
<!DOCTYPE html>
<html lang=en>
  <meta charset=utf-8>
  <meta name=viewport content="initial-scale=1, minimum-scale=1, width=device-width">
  <title>Error 404 (Not Found)!!1</title>
```

**MBEDTLS**

...

in process....
