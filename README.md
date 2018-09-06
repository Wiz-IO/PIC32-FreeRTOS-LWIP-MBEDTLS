# PIC32-FreeRTOS-LWIP-MBEDTLS
Microchip Curiosity PIC32MZ - FreeRTOS - LWIP - MBEDTLS

**Hardware**
* Curiosity PIC32MZEF Development Board PIC32MZ2048EFM + MRF24WN0MA on-board 
https://www.microchip.com/DevelopmentTools/ProductDetails/dm320104

**Software**
* Compiler MPLAB-X + XC32
* FreeRTOS v10.1.0 + umm_malloc
* lwip v2.0.2
* mbedtls
* MRF24WN Driver: at this stage - just to work
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

before tests: sys/config.h for WIFI SSID name, wifi driver is not tested with security

![ScreenShot](https://raw.githubusercontent.com/Wiz-IO/PIC32-FreeRTOS-LWIP-MBEDTLS/master/https.png)

**Board**

Config board at 200 mips

Debug: UART1 (DMA later)

**FreeRTOS**

FreeRTOSConfig.h
port.c - portTICK_PERIOD_MS = 1 msec

Linker options: --wrap,malloc --wrap,free

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

PING TEST...
```
[APP] - BEGIN -
[APP] - PING TEST -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WIFI Connecting . . .
[MRF] WIFI Connected to AP
[APP] WIFI READY
[PING-I]: ping: send seq(0x0001) 172.217.169.110
[PING-I]: ping: recv seq(0x0001) 172.217.169.110, 20 ms
.........
[PING-I]: 172.217.169.110, Packets: Sent = 3, Received =1, Lost = 2 (66% loss)
[PING-I]:  Packets: min = 20, max =20, avg = 6
```

SNTP TEST...
```
[APP] - BEGIN -
[APP] - SNTP TEST -
[APP] - BLINK -
[MRF] MAC: 001EC03B2D2F
[MRF] Init Done
[MRF] WIFI Connecting . . .
[MRF] WIFI Connected to AP
[APP] WIFI READY
[SNTP]: sntp_request: current server address is 87.97.157.120
[SNTP]: sntp_send_request: Sending request to server
[SNTP]: sntp_set_system_time input:  1535541550 s,0 us
[SNTP]: sntp(3 7 29 
[SNTP]: 11:19:10 118)
[SNTP]: sntp(atx):(0:240)
[SNTP]: sntp st1(0)
[SNTP]: sntp(3  8  29 
[SNTP]: 11:19:10 18)
[SNTP]: sntp st2(0)
[SNTP]: sntp_process: Wed Aug 29 11:19:10 2018
[SNTP]: sntp_recv: Scheduled next time request: 3600000 ms
```


**MBEDTLS**

Hardware support for: ALT_MD5 ... ALT_SHA224 is not supported from PIC32, ALT_SHA1 and ALT_SHA256 is not tested "on-air"

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
