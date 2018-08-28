# PIC32-FreeRTOS-LWIP-MBEDTLS
Microchip Curiosity PIC32MZ - FreeRTOS - LWIP - MBEDTLS

**Hardware**
* Curiosity PIC32MZEF Development Board PIC32MZ2048EFM + MRF24WN0MA on-board 
https://www.microchip.com/DevelopmentTools/ProductDetails/dm320104

**Software**
* MPLAB-X + XC32
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
```
#define portTIMER_PRESCALE	64 /* 1:0, 8:1, 64:2, 256:3 */
#define portPRESCALE_BITS	2
```
umm_malloc_cfg.h 
```
#define UMM_MALLOC_CFG__HEAP_SIZE   (configTOTAL_HEAP_SIZE)
```
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
dhcp_start(netif=0x80020200) w01
dhcp_start(): starting new DHCP client
dhcp_start(): allocated dhcpdhcp_start(): starting DHCP configuration
dhcp_discover()
transaction id xid(446B9B3D)
dhcp_discover: making request
dhcp_discover: realloc()ing
dhcp_discover: sendto(DISCOVER, IP_ADDR_BROADCAST, DHCP_SERVER_PORT)
dhcp_discover: deleting()ing
dhcp_discover: SELECTING
dhcp_discover(): set request timeout 2000 msecs
[MRF] DHCP started[MRF] ConnectionStateUpdate( 1, 0 )
[MRF] Connected to AP
[MRF] ReceiveCB()
dhcp_recv(pbuf = 0x8000b4ac) from DHCP server 192.168.12.1 port 67
pbuf->len = 300
pbuf->tot_len = 300
searching DHCP_OPTION_MESSAGE_TYPE
DHCP_OFFER received in DHCP_STATE_SELECTING state
dhcp_handle_offer(netif=0x80020200) w01
dhcp_handle_offer(): server 0x010CA8C0
dhcp_handle_offer(): offer for 0x240CA8C0
dhcp_select(netif=0x80020200) w01
transaction id xid(446B9B3D)
dhcp_select: REQUESTING
dhcp_select(): set request timeout 2000 msecs
[MRF] ReceiveCB()
dhcp_recv(pbuf = 0x8000b4ac) from DHCP server 192.168.12.1 port 67
pbuf->len = 300
pbuf->tot_len = 300
searching DHCP_OPTION_MESSAGE_TYPE
DHCP_ACK received
dhcp_bind(netif=0x80020200) w01
dhcp_bind(): t0 renewal timer 86400 secs
dhcp_bind(): set request timeout 86400000 msecs
dhcp_bind(): t1 renewal timer 43200 secs
dhcp_bind(): set request timeout 43200000 msecs
dhcp_bind(): t2 rebind timer 75600 secs
dhcp_bind(): set request timeout 75600000 msecs
dhcp_bind(): IP: 0x240CA8C0 SN: 0x00FFFFFF GW: 0x010CA8C0
netif: netmask of interface w0 set to 255.255.255.0
netif: GW address of interface w0 set to 192.168.12.1
netif_set_ipaddr: netif address being changed
netif: IP address of interface w0 set to 192.168.12.36
[MRF] ReceiveCB()
```

**MBEDTLS**

...

in process....