# PIC32-FreeRTOS-LWIP-MBEDTLS
Microchip Curiosity PIC32MZ - FreeRTOS - LWIP - MBEDTLS

**Hardware**
* Curiosity PIC32MZEF Development Board PIC32MZ2048EFM + MRF24WN0MA on-board 
https://www.microchip.com/DevelopmentTools/ProductDetails/dm320104

**Software**
* Compiler MPLAB-X + XC32
* FreeRTOS v10.1.0 (heap_4.c)
* lwip v2.0.2
* mbedtls
* MRF24WN Driver: at this stage - just to work as client
* OTHER:
    * cJSON || jsmn
    * RIL (later, ppp for Quectel modules)
    * ping
    * sntp
    * httpclient
    * MQTT Client - Eclipse Paho (in progress...)
    * AWS (later)
    * fatfs (later, SD card)
    * coap (maybe)

**PORTING**

before tests: edit sys/config.h for WIFI SSID name, wifi driver is not tested with security

![ScreenShot](https://raw.githubusercontent.com/Wiz-IO/PIC32-FreeRTOS-LWIP-MBEDTLS/master/https.png)

**Board**

* Board run at 200 mips
* Debug: UART1 (DMA later)

**FreeRTOS**

FreeRTOSConfig.h portTICK_PERIOD_MS is 1 msec


**LWIP**

SOCKET TEST...
```
[APP] - BEGIN -
[APP] - SOCKET -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WIFI Connecting . . .
[MRF] WIFI Connected to AP
[APP] WIFI READY
[APP] - IP: 192.168.12.36
[APP] - GW: 192.168.12.1
[APP] - MS: 255.255.255.0
[APP] - D0: 244.0.0.128
[APP] - D1: 248.0.0.128
[DNS] www.wizio.eu IP: 228.24.2.128
HTTP/1.1 200 OK
Date: Wed, 29 Aug 2018 10:18:16 GMT
Server: Apache
X-Powered-By: PHP/5.2.17
Cache-Control: max-age=0
Expires: Wed, 29 Aug 2018 10:18:16 GMT
Connection: close
Content-Type: text/html
[APACHE] Hello World ( 29.08.2018  13:18:16 )
[APP] DONE
```

HTTP TEST...
```
[APP] - BEGIN -
[APP] - HTTP TEST -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WIFI Connecting . . .
[MRF] WIFI Connected to AP
[APP] WIFI READY
[HTTP] Data received: [APACHE] Hello World ( 29.08.2018  10:57:33 )
[HTTP] Data received: [APACHE] Hello World ( 29.08.2018  10:58:35 )
```


**MBEDTLS**

Soft crypto - full

Hard crypto - tested with this project 
* ALT_MD5
* ALT_SHA1/256 (SHA224 is not supported from PIC32)
* Hash message limit 8k - pic32_crypto.h, #define PIC32_MAX_MEMORY_LIMIT (8*1024)
* ALT_AES (ecb, cbc) 
* ALT_DES/3 (ecb, cbc) 
* Enable engine from - middleware\mbedtls\configs\config-pic32-basic.h  bottom at the file


```
[MRF] Init Done
[MRF] WIFI Connecting . . .
[MRF] WIFI Connected to AP
[APP] WIFI READY
[HTTP] GET: http://www.wizio.eu/test.php
[HTTP] Elapsed: 42 mSec
[HTTP] Received: [APACHE] Hello World ( 03.09.2018 15:04:37 )
[HTTPS] GET: https://tlstest.paypal.com/
[HTTPS] Elapsed: 250 mSec
[HTTPS] Received: PayPal_Connection_OK
[HTTPS] GET: https://raw.githubusercon.../LIB/master/test_https
[HTTPS] Elapsed: 413 mSec
[HTTPS] Received: [GITHUB] https test url
[HTTPS] GET: https://os.mbed.com/media...bed_official/hello.txt
[HTTPS] Elapsed: 329 mSec
[HTTPS] Received: Hello world!
```

project is in process....

**If you want to help / support - contact me**
