#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=apps/app_http.c drivers/mrf24wn/mrf.c drivers/mrf24wn/mrf_hal.c drivers/mrf24wn/mrf_lib.c drivers/mrf24wn/mrf_osal.c drivers/mrf24wn/mrf_isr.S middleware/freertos/portable/MemMang/umm_malloc.c middleware/freertos/portable/MPLAB/PIC32MZ/port.c middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S middleware/freertos/croutine.c middleware/freertos/event_groups.c middleware/freertos/list.c middleware/freertos/queue.c middleware/freertos/stream_buffer.c middleware/freertos/tasks.c middleware/freertos/timers.c middleware/http/httpclient.c middleware/lwip/api/api_lib.c middleware/lwip/api/api_msg.c middleware/lwip/api/err.c middleware/lwip/api/netbuf.c middleware/lwip/api/netdb.c middleware/lwip/api/netifapi.c middleware/lwip/api/sockets.c middleware/lwip/api/tcpip.c middleware/lwip/core/ipv4/autoip.c middleware/lwip/core/ipv4/dhcp.c middleware/lwip/core/ipv4/etharp.c middleware/lwip/core/ipv4/icmp.c middleware/lwip/core/ipv4/igmp.c middleware/lwip/core/ipv4/ip4.c middleware/lwip/core/ipv4/ip4_addr.c middleware/lwip/core/ipv4/ip4_frag.c middleware/lwip/core/ipv6/dhcp6.c middleware/lwip/core/ipv6/ethip6.c middleware/lwip/core/ipv6/icmp6.c middleware/lwip/core/ipv6/inet6.c middleware/lwip/core/ipv6/ip6.c middleware/lwip/core/ipv6/ip6_addr.c middleware/lwip/core/ipv6/ip6_frag.c middleware/lwip/core/ipv6/mld6.c middleware/lwip/core/ipv6/nd6.c middleware/lwip/core/def.c middleware/lwip/core/dns.c middleware/lwip/core/inet_chksum.c middleware/lwip/core/init.c middleware/lwip/core/ip.c middleware/lwip/core/mem.c middleware/lwip/core/memp.c middleware/lwip/core/netif.c middleware/lwip/core/pbuf.c middleware/lwip/core/raw.c middleware/lwip/core/stats.c middleware/lwip/core/sys.c middleware/lwip/core/tcp.c middleware/lwip/core/tcp_in.c middleware/lwip/core/tcp_out.c middleware/lwip/core/timeouts.c middleware/lwip/core/udp.c middleware/lwip/netif/ppp/polarssl/arc4.c middleware/lwip/netif/ppp/polarssl/des.c middleware/lwip/netif/ppp/polarssl/md4.c middleware/lwip/netif/ppp/polarssl/md5.c middleware/lwip/netif/ppp/polarssl/sha1.c middleware/lwip/netif/ppp/auth.c middleware/lwip/netif/ppp/ccp.c middleware/lwip/netif/ppp/chap-md5.c middleware/lwip/netif/ppp/chap-new.c middleware/lwip/netif/ppp/chap_ms.c middleware/lwip/netif/ppp/demand.c middleware/lwip/netif/ppp/eap.c middleware/lwip/netif/ppp/ecp.c middleware/lwip/netif/ppp/eui64.c middleware/lwip/netif/ppp/fsm.c middleware/lwip/netif/ppp/ipcp.c middleware/lwip/netif/ppp/ipv6cp.c middleware/lwip/netif/ppp/lcp.c middleware/lwip/netif/ppp/magic.c middleware/lwip/netif/ppp/mppe.c middleware/lwip/netif/ppp/multilink.c middleware/lwip/netif/ppp/ppp.c middleware/lwip/netif/ppp/pppapi.c middleware/lwip/netif/ppp/pppcrypt.c middleware/lwip/netif/ppp/pppoe.c middleware/lwip/netif/ppp/pppol2tp.c middleware/lwip/netif/ppp/pppos.c middleware/lwip/netif/ppp/upap.c middleware/lwip/netif/ppp/utils.c middleware/lwip/netif/ppp/vj.c middleware/lwip/netif/ethernet.c middleware/lwip/netif/ethernetif.c middleware/lwip/port/sys_arch.c middleware/mbedtls/port/alt_md5.c middleware/mbedtls/port/alt_sha256.c middleware/mbedtls/port/alt_sha1.c middleware/mbedtls/aes.c middleware/mbedtls/aesni.c middleware/mbedtls/arc4.c middleware/mbedtls/asn1parse.c middleware/mbedtls/asn1write.c middleware/mbedtls/base64.c middleware/mbedtls/bignum.c middleware/mbedtls/blowfish.c middleware/mbedtls/camellia.c middleware/mbedtls/ccm.c middleware/mbedtls/certs.c middleware/mbedtls/cipher.c middleware/mbedtls/cipher_wrap.c middleware/mbedtls/cmac.c middleware/mbedtls/ctr_drbg.c middleware/mbedtls/debug.c middleware/mbedtls/des.c middleware/mbedtls/dhm.c middleware/mbedtls/ecdh.c middleware/mbedtls/ecdsa.c middleware/mbedtls/ecjpake.c middleware/mbedtls/ecp.c middleware/mbedtls/ecp_curves.c middleware/mbedtls/entropy.c middleware/mbedtls/entropy_poll.c middleware/mbedtls/error.c middleware/mbedtls/gcm.c middleware/mbedtls/havege.c middleware/mbedtls/hmac_drbg.c middleware/mbedtls/md.c middleware/mbedtls/md2.c middleware/mbedtls/md4.c middleware/mbedtls/md5.c middleware/mbedtls/md_wrap.c middleware/mbedtls/memory_buffer_alloc.c middleware/mbedtls/net_sockets.c middleware/mbedtls/oid.c middleware/mbedtls/padlock.c middleware/mbedtls/pem.c middleware/mbedtls/pk.c middleware/mbedtls/pkcs11.c middleware/mbedtls/pkcs12.c middleware/mbedtls/pkcs5.c middleware/mbedtls/pkparse.c middleware/mbedtls/pkwrite.c middleware/mbedtls/pk_wrap.c middleware/mbedtls/platform.c middleware/mbedtls/ripemd160.c middleware/mbedtls/rsa.c middleware/mbedtls/sha1.c middleware/mbedtls/sha256.c middleware/mbedtls/sha512.c middleware/mbedtls/ssl_cache.c middleware/mbedtls/ssl_ciphersuites.c middleware/mbedtls/ssl_cli.c middleware/mbedtls/ssl_cookie.c middleware/mbedtls/ssl_srv.c middleware/mbedtls/ssl_ticket.c middleware/mbedtls/ssl_tls.c middleware/mbedtls/threading.c middleware/mbedtls/timing.c middleware/mbedtls/version.c middleware/mbedtls/version_features.c middleware/mbedtls/x509.c middleware/mbedtls/x509write_crt.c middleware/mbedtls/x509write_csr.c middleware/mbedtls/x509_create.c middleware/mbedtls/x509_crl.c middleware/mbedtls/x509_crt.c middleware/mbedtls/x509_csr.c middleware/mbedtls/xtea.c middleware/wizio/freertos_common.c middleware/wizio/wrap_mem.c sys/sys.c sys/sys_common.c sys/sys_config.c sys/sys_rtcc.c sys/sys_trap.c sys/sys_log.c sys/sys_log_isr.S main.c middleware/wizio/pic32mz-crypt.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/apps/app_http.o ${OBJECTDIR}/drivers/mrf24wn/mrf.o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o ${OBJECTDIR}/middleware/freertos/croutine.o ${OBJECTDIR}/middleware/freertos/event_groups.o ${OBJECTDIR}/middleware/freertos/list.o ${OBJECTDIR}/middleware/freertos/queue.o ${OBJECTDIR}/middleware/freertos/stream_buffer.o ${OBJECTDIR}/middleware/freertos/tasks.o ${OBJECTDIR}/middleware/freertos/timers.o ${OBJECTDIR}/middleware/http/httpclient.o ${OBJECTDIR}/middleware/lwip/api/api_lib.o ${OBJECTDIR}/middleware/lwip/api/api_msg.o ${OBJECTDIR}/middleware/lwip/api/err.o ${OBJECTDIR}/middleware/lwip/api/netbuf.o ${OBJECTDIR}/middleware/lwip/api/netdb.o ${OBJECTDIR}/middleware/lwip/api/netifapi.o ${OBJECTDIR}/middleware/lwip/api/sockets.o ${OBJECTDIR}/middleware/lwip/api/tcpip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o ${OBJECTDIR}/middleware/lwip/core/def.o ${OBJECTDIR}/middleware/lwip/core/dns.o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o ${OBJECTDIR}/middleware/lwip/core/init.o ${OBJECTDIR}/middleware/lwip/core/ip.o ${OBJECTDIR}/middleware/lwip/core/mem.o ${OBJECTDIR}/middleware/lwip/core/memp.o ${OBJECTDIR}/middleware/lwip/core/netif.o ${OBJECTDIR}/middleware/lwip/core/pbuf.o ${OBJECTDIR}/middleware/lwip/core/raw.o ${OBJECTDIR}/middleware/lwip/core/stats.o ${OBJECTDIR}/middleware/lwip/core/sys.o ${OBJECTDIR}/middleware/lwip/core/tcp.o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o ${OBJECTDIR}/middleware/lwip/core/timeouts.o ${OBJECTDIR}/middleware/lwip/core/udp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o ${OBJECTDIR}/middleware/mbedtls/aes.o ${OBJECTDIR}/middleware/mbedtls/aesni.o ${OBJECTDIR}/middleware/mbedtls/arc4.o ${OBJECTDIR}/middleware/mbedtls/asn1parse.o ${OBJECTDIR}/middleware/mbedtls/asn1write.o ${OBJECTDIR}/middleware/mbedtls/base64.o ${OBJECTDIR}/middleware/mbedtls/bignum.o ${OBJECTDIR}/middleware/mbedtls/blowfish.o ${OBJECTDIR}/middleware/mbedtls/camellia.o ${OBJECTDIR}/middleware/mbedtls/ccm.o ${OBJECTDIR}/middleware/mbedtls/certs.o ${OBJECTDIR}/middleware/mbedtls/cipher.o ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o ${OBJECTDIR}/middleware/mbedtls/cmac.o ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o ${OBJECTDIR}/middleware/mbedtls/debug.o ${OBJECTDIR}/middleware/mbedtls/des.o ${OBJECTDIR}/middleware/mbedtls/dhm.o ${OBJECTDIR}/middleware/mbedtls/ecdh.o ${OBJECTDIR}/middleware/mbedtls/ecdsa.o ${OBJECTDIR}/middleware/mbedtls/ecjpake.o ${OBJECTDIR}/middleware/mbedtls/ecp.o ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o ${OBJECTDIR}/middleware/mbedtls/entropy.o ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o ${OBJECTDIR}/middleware/mbedtls/error.o ${OBJECTDIR}/middleware/mbedtls/gcm.o ${OBJECTDIR}/middleware/mbedtls/havege.o ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o ${OBJECTDIR}/middleware/mbedtls/md.o ${OBJECTDIR}/middleware/mbedtls/md2.o ${OBJECTDIR}/middleware/mbedtls/md4.o ${OBJECTDIR}/middleware/mbedtls/md5.o ${OBJECTDIR}/middleware/mbedtls/md_wrap.o ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o ${OBJECTDIR}/middleware/mbedtls/net_sockets.o ${OBJECTDIR}/middleware/mbedtls/oid.o ${OBJECTDIR}/middleware/mbedtls/padlock.o ${OBJECTDIR}/middleware/mbedtls/pem.o ${OBJECTDIR}/middleware/mbedtls/pk.o ${OBJECTDIR}/middleware/mbedtls/pkcs11.o ${OBJECTDIR}/middleware/mbedtls/pkcs12.o ${OBJECTDIR}/middleware/mbedtls/pkcs5.o ${OBJECTDIR}/middleware/mbedtls/pkparse.o ${OBJECTDIR}/middleware/mbedtls/pkwrite.o ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o ${OBJECTDIR}/middleware/mbedtls/platform.o ${OBJECTDIR}/middleware/mbedtls/ripemd160.o ${OBJECTDIR}/middleware/mbedtls/rsa.o ${OBJECTDIR}/middleware/mbedtls/sha1.o ${OBJECTDIR}/middleware/mbedtls/sha256.o ${OBJECTDIR}/middleware/mbedtls/sha512.o ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o ${OBJECTDIR}/middleware/mbedtls/threading.o ${OBJECTDIR}/middleware/mbedtls/timing.o ${OBJECTDIR}/middleware/mbedtls/version.o ${OBJECTDIR}/middleware/mbedtls/version_features.o ${OBJECTDIR}/middleware/mbedtls/x509.o ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o ${OBJECTDIR}/middleware/mbedtls/x509_create.o ${OBJECTDIR}/middleware/mbedtls/x509_crl.o ${OBJECTDIR}/middleware/mbedtls/x509_crt.o ${OBJECTDIR}/middleware/mbedtls/x509_csr.o ${OBJECTDIR}/middleware/mbedtls/xtea.o ${OBJECTDIR}/middleware/wizio/freertos_common.o ${OBJECTDIR}/middleware/wizio/wrap_mem.o ${OBJECTDIR}/sys/sys.o ${OBJECTDIR}/sys/sys_common.o ${OBJECTDIR}/sys/sys_config.o ${OBJECTDIR}/sys/sys_rtcc.o ${OBJECTDIR}/sys/sys_trap.o ${OBJECTDIR}/sys/sys_log.o ${OBJECTDIR}/sys/sys_log_isr.o ${OBJECTDIR}/main.o ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o
POSSIBLE_DEPFILES=${OBJECTDIR}/apps/app_http.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d ${OBJECTDIR}/middleware/freertos/croutine.o.d ${OBJECTDIR}/middleware/freertos/event_groups.o.d ${OBJECTDIR}/middleware/freertos/list.o.d ${OBJECTDIR}/middleware/freertos/queue.o.d ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d ${OBJECTDIR}/middleware/freertos/tasks.o.d ${OBJECTDIR}/middleware/freertos/timers.o.d ${OBJECTDIR}/middleware/http/httpclient.o.d ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d ${OBJECTDIR}/middleware/lwip/api/err.o.d ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d ${OBJECTDIR}/middleware/lwip/api/netdb.o.d ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d ${OBJECTDIR}/middleware/lwip/api/sockets.o.d ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d ${OBJECTDIR}/middleware/lwip/core/def.o.d ${OBJECTDIR}/middleware/lwip/core/dns.o.d ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d ${OBJECTDIR}/middleware/lwip/core/init.o.d ${OBJECTDIR}/middleware/lwip/core/ip.o.d ${OBJECTDIR}/middleware/lwip/core/mem.o.d ${OBJECTDIR}/middleware/lwip/core/memp.o.d ${OBJECTDIR}/middleware/lwip/core/netif.o.d ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d ${OBJECTDIR}/middleware/lwip/core/raw.o.d ${OBJECTDIR}/middleware/lwip/core/stats.o.d ${OBJECTDIR}/middleware/lwip/core/sys.o.d ${OBJECTDIR}/middleware/lwip/core/tcp.o.d ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d ${OBJECTDIR}/middleware/lwip/core/udp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d ${OBJECTDIR}/middleware/mbedtls/aes.o.d ${OBJECTDIR}/middleware/mbedtls/aesni.o.d ${OBJECTDIR}/middleware/mbedtls/arc4.o.d ${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d ${OBJECTDIR}/middleware/mbedtls/asn1write.o.d ${OBJECTDIR}/middleware/mbedtls/base64.o.d ${OBJECTDIR}/middleware/mbedtls/bignum.o.d ${OBJECTDIR}/middleware/mbedtls/blowfish.o.d ${OBJECTDIR}/middleware/mbedtls/camellia.o.d ${OBJECTDIR}/middleware/mbedtls/ccm.o.d ${OBJECTDIR}/middleware/mbedtls/certs.o.d ${OBJECTDIR}/middleware/mbedtls/cipher.o.d ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d ${OBJECTDIR}/middleware/mbedtls/cmac.o.d ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d ${OBJECTDIR}/middleware/mbedtls/debug.o.d ${OBJECTDIR}/middleware/mbedtls/des.o.d ${OBJECTDIR}/middleware/mbedtls/dhm.o.d ${OBJECTDIR}/middleware/mbedtls/ecdh.o.d ${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d ${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d ${OBJECTDIR}/middleware/mbedtls/ecp.o.d ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d ${OBJECTDIR}/middleware/mbedtls/entropy.o.d ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d ${OBJECTDIR}/middleware/mbedtls/error.o.d ${OBJECTDIR}/middleware/mbedtls/gcm.o.d ${OBJECTDIR}/middleware/mbedtls/havege.o.d ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d ${OBJECTDIR}/middleware/mbedtls/md.o.d ${OBJECTDIR}/middleware/mbedtls/md2.o.d ${OBJECTDIR}/middleware/mbedtls/md4.o.d ${OBJECTDIR}/middleware/mbedtls/md5.o.d ${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d ${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d ${OBJECTDIR}/middleware/mbedtls/oid.o.d ${OBJECTDIR}/middleware/mbedtls/padlock.o.d ${OBJECTDIR}/middleware/mbedtls/pem.o.d ${OBJECTDIR}/middleware/mbedtls/pk.o.d ${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d ${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d ${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d ${OBJECTDIR}/middleware/mbedtls/pkparse.o.d ${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d ${OBJECTDIR}/middleware/mbedtls/platform.o.d ${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d ${OBJECTDIR}/middleware/mbedtls/rsa.o.d ${OBJECTDIR}/middleware/mbedtls/sha1.o.d ${OBJECTDIR}/middleware/mbedtls/sha256.o.d ${OBJECTDIR}/middleware/mbedtls/sha512.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d ${OBJECTDIR}/middleware/mbedtls/threading.o.d ${OBJECTDIR}/middleware/mbedtls/timing.o.d ${OBJECTDIR}/middleware/mbedtls/version.o.d ${OBJECTDIR}/middleware/mbedtls/version_features.o.d ${OBJECTDIR}/middleware/mbedtls/x509.o.d ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d ${OBJECTDIR}/middleware/mbedtls/x509_create.o.d ${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d ${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d ${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d ${OBJECTDIR}/middleware/mbedtls/xtea.o.d ${OBJECTDIR}/middleware/wizio/freertos_common.o.d ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d ${OBJECTDIR}/sys/sys.o.d ${OBJECTDIR}/sys/sys_common.o.d ${OBJECTDIR}/sys/sys_config.o.d ${OBJECTDIR}/sys/sys_rtcc.o.d ${OBJECTDIR}/sys/sys_trap.o.d ${OBJECTDIR}/sys/sys_log.o.d ${OBJECTDIR}/sys/sys_log_isr.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/apps/app_http.o ${OBJECTDIR}/drivers/mrf24wn/mrf.o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o ${OBJECTDIR}/middleware/freertos/croutine.o ${OBJECTDIR}/middleware/freertos/event_groups.o ${OBJECTDIR}/middleware/freertos/list.o ${OBJECTDIR}/middleware/freertos/queue.o ${OBJECTDIR}/middleware/freertos/stream_buffer.o ${OBJECTDIR}/middleware/freertos/tasks.o ${OBJECTDIR}/middleware/freertos/timers.o ${OBJECTDIR}/middleware/http/httpclient.o ${OBJECTDIR}/middleware/lwip/api/api_lib.o ${OBJECTDIR}/middleware/lwip/api/api_msg.o ${OBJECTDIR}/middleware/lwip/api/err.o ${OBJECTDIR}/middleware/lwip/api/netbuf.o ${OBJECTDIR}/middleware/lwip/api/netdb.o ${OBJECTDIR}/middleware/lwip/api/netifapi.o ${OBJECTDIR}/middleware/lwip/api/sockets.o ${OBJECTDIR}/middleware/lwip/api/tcpip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o ${OBJECTDIR}/middleware/lwip/core/def.o ${OBJECTDIR}/middleware/lwip/core/dns.o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o ${OBJECTDIR}/middleware/lwip/core/init.o ${OBJECTDIR}/middleware/lwip/core/ip.o ${OBJECTDIR}/middleware/lwip/core/mem.o ${OBJECTDIR}/middleware/lwip/core/memp.o ${OBJECTDIR}/middleware/lwip/core/netif.o ${OBJECTDIR}/middleware/lwip/core/pbuf.o ${OBJECTDIR}/middleware/lwip/core/raw.o ${OBJECTDIR}/middleware/lwip/core/stats.o ${OBJECTDIR}/middleware/lwip/core/sys.o ${OBJECTDIR}/middleware/lwip/core/tcp.o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o ${OBJECTDIR}/middleware/lwip/core/timeouts.o ${OBJECTDIR}/middleware/lwip/core/udp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o ${OBJECTDIR}/middleware/mbedtls/aes.o ${OBJECTDIR}/middleware/mbedtls/aesni.o ${OBJECTDIR}/middleware/mbedtls/arc4.o ${OBJECTDIR}/middleware/mbedtls/asn1parse.o ${OBJECTDIR}/middleware/mbedtls/asn1write.o ${OBJECTDIR}/middleware/mbedtls/base64.o ${OBJECTDIR}/middleware/mbedtls/bignum.o ${OBJECTDIR}/middleware/mbedtls/blowfish.o ${OBJECTDIR}/middleware/mbedtls/camellia.o ${OBJECTDIR}/middleware/mbedtls/ccm.o ${OBJECTDIR}/middleware/mbedtls/certs.o ${OBJECTDIR}/middleware/mbedtls/cipher.o ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o ${OBJECTDIR}/middleware/mbedtls/cmac.o ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o ${OBJECTDIR}/middleware/mbedtls/debug.o ${OBJECTDIR}/middleware/mbedtls/des.o ${OBJECTDIR}/middleware/mbedtls/dhm.o ${OBJECTDIR}/middleware/mbedtls/ecdh.o ${OBJECTDIR}/middleware/mbedtls/ecdsa.o ${OBJECTDIR}/middleware/mbedtls/ecjpake.o ${OBJECTDIR}/middleware/mbedtls/ecp.o ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o ${OBJECTDIR}/middleware/mbedtls/entropy.o ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o ${OBJECTDIR}/middleware/mbedtls/error.o ${OBJECTDIR}/middleware/mbedtls/gcm.o ${OBJECTDIR}/middleware/mbedtls/havege.o ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o ${OBJECTDIR}/middleware/mbedtls/md.o ${OBJECTDIR}/middleware/mbedtls/md2.o ${OBJECTDIR}/middleware/mbedtls/md4.o ${OBJECTDIR}/middleware/mbedtls/md5.o ${OBJECTDIR}/middleware/mbedtls/md_wrap.o ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o ${OBJECTDIR}/middleware/mbedtls/net_sockets.o ${OBJECTDIR}/middleware/mbedtls/oid.o ${OBJECTDIR}/middleware/mbedtls/padlock.o ${OBJECTDIR}/middleware/mbedtls/pem.o ${OBJECTDIR}/middleware/mbedtls/pk.o ${OBJECTDIR}/middleware/mbedtls/pkcs11.o ${OBJECTDIR}/middleware/mbedtls/pkcs12.o ${OBJECTDIR}/middleware/mbedtls/pkcs5.o ${OBJECTDIR}/middleware/mbedtls/pkparse.o ${OBJECTDIR}/middleware/mbedtls/pkwrite.o ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o ${OBJECTDIR}/middleware/mbedtls/platform.o ${OBJECTDIR}/middleware/mbedtls/ripemd160.o ${OBJECTDIR}/middleware/mbedtls/rsa.o ${OBJECTDIR}/middleware/mbedtls/sha1.o ${OBJECTDIR}/middleware/mbedtls/sha256.o ${OBJECTDIR}/middleware/mbedtls/sha512.o ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o ${OBJECTDIR}/middleware/mbedtls/threading.o ${OBJECTDIR}/middleware/mbedtls/timing.o ${OBJECTDIR}/middleware/mbedtls/version.o ${OBJECTDIR}/middleware/mbedtls/version_features.o ${OBJECTDIR}/middleware/mbedtls/x509.o ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o ${OBJECTDIR}/middleware/mbedtls/x509_create.o ${OBJECTDIR}/middleware/mbedtls/x509_crl.o ${OBJECTDIR}/middleware/mbedtls/x509_crt.o ${OBJECTDIR}/middleware/mbedtls/x509_csr.o ${OBJECTDIR}/middleware/mbedtls/xtea.o ${OBJECTDIR}/middleware/wizio/freertos_common.o ${OBJECTDIR}/middleware/wizio/wrap_mem.o ${OBJECTDIR}/sys/sys.o ${OBJECTDIR}/sys/sys_common.o ${OBJECTDIR}/sys/sys_config.o ${OBJECTDIR}/sys/sys_rtcc.o ${OBJECTDIR}/sys/sys_trap.o ${OBJECTDIR}/sys/sys_log.o ${OBJECTDIR}/sys/sys_log_isr.o ${OBJECTDIR}/main.o ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o

# Source Files
SOURCEFILES=apps/app_http.c drivers/mrf24wn/mrf.c drivers/mrf24wn/mrf_hal.c drivers/mrf24wn/mrf_lib.c drivers/mrf24wn/mrf_osal.c drivers/mrf24wn/mrf_isr.S middleware/freertos/portable/MemMang/umm_malloc.c middleware/freertos/portable/MPLAB/PIC32MZ/port.c middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S middleware/freertos/croutine.c middleware/freertos/event_groups.c middleware/freertos/list.c middleware/freertos/queue.c middleware/freertos/stream_buffer.c middleware/freertos/tasks.c middleware/freertos/timers.c middleware/http/httpclient.c middleware/lwip/api/api_lib.c middleware/lwip/api/api_msg.c middleware/lwip/api/err.c middleware/lwip/api/netbuf.c middleware/lwip/api/netdb.c middleware/lwip/api/netifapi.c middleware/lwip/api/sockets.c middleware/lwip/api/tcpip.c middleware/lwip/core/ipv4/autoip.c middleware/lwip/core/ipv4/dhcp.c middleware/lwip/core/ipv4/etharp.c middleware/lwip/core/ipv4/icmp.c middleware/lwip/core/ipv4/igmp.c middleware/lwip/core/ipv4/ip4.c middleware/lwip/core/ipv4/ip4_addr.c middleware/lwip/core/ipv4/ip4_frag.c middleware/lwip/core/ipv6/dhcp6.c middleware/lwip/core/ipv6/ethip6.c middleware/lwip/core/ipv6/icmp6.c middleware/lwip/core/ipv6/inet6.c middleware/lwip/core/ipv6/ip6.c middleware/lwip/core/ipv6/ip6_addr.c middleware/lwip/core/ipv6/ip6_frag.c middleware/lwip/core/ipv6/mld6.c middleware/lwip/core/ipv6/nd6.c middleware/lwip/core/def.c middleware/lwip/core/dns.c middleware/lwip/core/inet_chksum.c middleware/lwip/core/init.c middleware/lwip/core/ip.c middleware/lwip/core/mem.c middleware/lwip/core/memp.c middleware/lwip/core/netif.c middleware/lwip/core/pbuf.c middleware/lwip/core/raw.c middleware/lwip/core/stats.c middleware/lwip/core/sys.c middleware/lwip/core/tcp.c middleware/lwip/core/tcp_in.c middleware/lwip/core/tcp_out.c middleware/lwip/core/timeouts.c middleware/lwip/core/udp.c middleware/lwip/netif/ppp/polarssl/arc4.c middleware/lwip/netif/ppp/polarssl/des.c middleware/lwip/netif/ppp/polarssl/md4.c middleware/lwip/netif/ppp/polarssl/md5.c middleware/lwip/netif/ppp/polarssl/sha1.c middleware/lwip/netif/ppp/auth.c middleware/lwip/netif/ppp/ccp.c middleware/lwip/netif/ppp/chap-md5.c middleware/lwip/netif/ppp/chap-new.c middleware/lwip/netif/ppp/chap_ms.c middleware/lwip/netif/ppp/demand.c middleware/lwip/netif/ppp/eap.c middleware/lwip/netif/ppp/ecp.c middleware/lwip/netif/ppp/eui64.c middleware/lwip/netif/ppp/fsm.c middleware/lwip/netif/ppp/ipcp.c middleware/lwip/netif/ppp/ipv6cp.c middleware/lwip/netif/ppp/lcp.c middleware/lwip/netif/ppp/magic.c middleware/lwip/netif/ppp/mppe.c middleware/lwip/netif/ppp/multilink.c middleware/lwip/netif/ppp/ppp.c middleware/lwip/netif/ppp/pppapi.c middleware/lwip/netif/ppp/pppcrypt.c middleware/lwip/netif/ppp/pppoe.c middleware/lwip/netif/ppp/pppol2tp.c middleware/lwip/netif/ppp/pppos.c middleware/lwip/netif/ppp/upap.c middleware/lwip/netif/ppp/utils.c middleware/lwip/netif/ppp/vj.c middleware/lwip/netif/ethernet.c middleware/lwip/netif/ethernetif.c middleware/lwip/port/sys_arch.c middleware/mbedtls/port/alt_md5.c middleware/mbedtls/port/alt_sha256.c middleware/mbedtls/port/alt_sha1.c middleware/mbedtls/aes.c middleware/mbedtls/aesni.c middleware/mbedtls/arc4.c middleware/mbedtls/asn1parse.c middleware/mbedtls/asn1write.c middleware/mbedtls/base64.c middleware/mbedtls/bignum.c middleware/mbedtls/blowfish.c middleware/mbedtls/camellia.c middleware/mbedtls/ccm.c middleware/mbedtls/certs.c middleware/mbedtls/cipher.c middleware/mbedtls/cipher_wrap.c middleware/mbedtls/cmac.c middleware/mbedtls/ctr_drbg.c middleware/mbedtls/debug.c middleware/mbedtls/des.c middleware/mbedtls/dhm.c middleware/mbedtls/ecdh.c middleware/mbedtls/ecdsa.c middleware/mbedtls/ecjpake.c middleware/mbedtls/ecp.c middleware/mbedtls/ecp_curves.c middleware/mbedtls/entropy.c middleware/mbedtls/entropy_poll.c middleware/mbedtls/error.c middleware/mbedtls/gcm.c middleware/mbedtls/havege.c middleware/mbedtls/hmac_drbg.c middleware/mbedtls/md.c middleware/mbedtls/md2.c middleware/mbedtls/md4.c middleware/mbedtls/md5.c middleware/mbedtls/md_wrap.c middleware/mbedtls/memory_buffer_alloc.c middleware/mbedtls/net_sockets.c middleware/mbedtls/oid.c middleware/mbedtls/padlock.c middleware/mbedtls/pem.c middleware/mbedtls/pk.c middleware/mbedtls/pkcs11.c middleware/mbedtls/pkcs12.c middleware/mbedtls/pkcs5.c middleware/mbedtls/pkparse.c middleware/mbedtls/pkwrite.c middleware/mbedtls/pk_wrap.c middleware/mbedtls/platform.c middleware/mbedtls/ripemd160.c middleware/mbedtls/rsa.c middleware/mbedtls/sha1.c middleware/mbedtls/sha256.c middleware/mbedtls/sha512.c middleware/mbedtls/ssl_cache.c middleware/mbedtls/ssl_ciphersuites.c middleware/mbedtls/ssl_cli.c middleware/mbedtls/ssl_cookie.c middleware/mbedtls/ssl_srv.c middleware/mbedtls/ssl_ticket.c middleware/mbedtls/ssl_tls.c middleware/mbedtls/threading.c middleware/mbedtls/timing.c middleware/mbedtls/version.c middleware/mbedtls/version_features.c middleware/mbedtls/x509.c middleware/mbedtls/x509write_crt.c middleware/mbedtls/x509write_csr.c middleware/mbedtls/x509_create.c middleware/mbedtls/x509_crl.c middleware/mbedtls/x509_crt.c middleware/mbedtls/x509_csr.c middleware/mbedtls/xtea.c middleware/wizio/freertos_common.c middleware/wizio/wrap_mem.c sys/sys.c sys/sys_common.c sys/sys_config.c sys/sys_rtcc.c sys/sys_trap.c sys/sys_log.c sys/sys_log_isr.S main.c middleware/wizio/pic32mz-crypt.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MZ2048EFM100
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o: drivers/mrf24wn/mrf_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.ok ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d" "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d"  -o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o drivers/mrf24wn/mrf_isr.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o: middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.ok ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d" "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d"  -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/sys/sys_log_isr.o: sys/sys_log_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o.ok ${OBJECTDIR}/sys/sys_log_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_log_isr.o.d" "${OBJECTDIR}/sys/sys_log_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/sys/sys_log_isr.o.d"  -o ${OBJECTDIR}/sys/sys_log_isr.o sys/sys_log_isr.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/sys/sys_log_isr.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o: drivers/mrf24wn/mrf_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.ok ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d" "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d"  -o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o drivers/mrf24wn/mrf_isr.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d",--gdwarf-2
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o: middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.ok ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d" "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d"  -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d",--gdwarf-2
	
${OBJECTDIR}/sys/sys_log_isr.o: sys/sys_log_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o 
	@${RM} ${OBJECTDIR}/sys/sys_log_isr.o.ok ${OBJECTDIR}/sys/sys_log_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_log_isr.o.d" "${OBJECTDIR}/sys/sys_log_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/sys/sys_log_isr.o.d"  -o ${OBJECTDIR}/sys/sys_log_isr.o sys/sys_log_isr.S  -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/sys/sys_log_isr.o.asm.d",--gdwarf-2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/apps/app_http.o: apps/app_http.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/apps" 
	@${RM} ${OBJECTDIR}/apps/app_http.o.d 
	@${RM} ${OBJECTDIR}/apps/app_http.o 
	@${FIXDEPS} "${OBJECTDIR}/apps/app_http.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/apps/app_http.o.d" -o ${OBJECTDIR}/apps/app_http.o apps/app_http.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf.o: drivers/mrf24wn/mrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf.o drivers/mrf24wn/mrf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o: drivers/mrf24wn/mrf_hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o drivers/mrf24wn/mrf_hal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o: drivers/mrf24wn/mrf_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o drivers/mrf24wn/mrf_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o: drivers/mrf24wn/mrf_osal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o drivers/mrf24wn/mrf_osal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o: middleware/freertos/portable/MemMang/umm_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MemMang" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o middleware/freertos/portable/MemMang/umm_malloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o: middleware/freertos/portable/MPLAB/PIC32MZ/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o middleware/freertos/portable/MPLAB/PIC32MZ/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/croutine.o: middleware/freertos/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/croutine.o.d" -o ${OBJECTDIR}/middleware/freertos/croutine.o middleware/freertos/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/event_groups.o: middleware/freertos/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/event_groups.o.d" -o ${OBJECTDIR}/middleware/freertos/event_groups.o middleware/freertos/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/list.o: middleware/freertos/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/list.o.d" -o ${OBJECTDIR}/middleware/freertos/list.o middleware/freertos/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/queue.o: middleware/freertos/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/queue.o.d" -o ${OBJECTDIR}/middleware/freertos/queue.o middleware/freertos/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/stream_buffer.o: middleware/freertos/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" -o ${OBJECTDIR}/middleware/freertos/stream_buffer.o middleware/freertos/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/tasks.o: middleware/freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/tasks.o.d" -o ${OBJECTDIR}/middleware/freertos/tasks.o middleware/freertos/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/timers.o: middleware/freertos/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/timers.o.d" -o ${OBJECTDIR}/middleware/freertos/timers.o middleware/freertos/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/http/httpclient.o: middleware/http/httpclient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/http" 
	@${RM} ${OBJECTDIR}/middleware/http/httpclient.o.d 
	@${RM} ${OBJECTDIR}/middleware/http/httpclient.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/http/httpclient.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/http/httpclient.o.d" -o ${OBJECTDIR}/middleware/http/httpclient.o middleware/http/httpclient.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_lib.o: middleware/lwip/api/api_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_lib.o middleware/lwip/api/api_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_msg.o: middleware/lwip/api/api_msg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_msg.o middleware/lwip/api/api_msg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/err.o: middleware/lwip/api/err.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/err.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/err.o.d" -o ${OBJECTDIR}/middleware/lwip/api/err.o middleware/lwip/api/err.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netbuf.o: middleware/lwip/api/netbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netbuf.o middleware/lwip/api/netbuf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netdb.o: middleware/lwip/api/netdb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netdb.o middleware/lwip/api/netdb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netifapi.o: middleware/lwip/api/netifapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netifapi.o middleware/lwip/api/netifapi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/sockets.o: middleware/lwip/api/sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" -o ${OBJECTDIR}/middleware/lwip/api/sockets.o middleware/lwip/api/sockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/tcpip.o: middleware/lwip/api/tcpip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" -o ${OBJECTDIR}/middleware/lwip/api/tcpip.o middleware/lwip/api/tcpip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o: middleware/lwip/core/ipv4/autoip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o middleware/lwip/core/ipv4/autoip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o: middleware/lwip/core/ipv4/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o middleware/lwip/core/ipv4/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o: middleware/lwip/core/ipv4/etharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o middleware/lwip/core/ipv4/etharp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o: middleware/lwip/core/ipv4/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o middleware/lwip/core/ipv4/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o: middleware/lwip/core/ipv4/igmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o middleware/lwip/core/ipv4/igmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o: middleware/lwip/core/ipv4/ip4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o middleware/lwip/core/ipv4/ip4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o: middleware/lwip/core/ipv4/ip4_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o middleware/lwip/core/ipv4/ip4_addr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o: middleware/lwip/core/ipv4/ip4_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o middleware/lwip/core/ipv4/ip4_frag.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o: middleware/lwip/core/ipv6/dhcp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o middleware/lwip/core/ipv6/dhcp6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o: middleware/lwip/core/ipv6/ethip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o middleware/lwip/core/ipv6/ethip6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o: middleware/lwip/core/ipv6/icmp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o middleware/lwip/core/ipv6/icmp6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o: middleware/lwip/core/ipv6/inet6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o middleware/lwip/core/ipv6/inet6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o: middleware/lwip/core/ipv6/ip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o middleware/lwip/core/ipv6/ip6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o: middleware/lwip/core/ipv6/ip6_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o middleware/lwip/core/ipv6/ip6_addr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o: middleware/lwip/core/ipv6/ip6_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o middleware/lwip/core/ipv6/ip6_frag.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o: middleware/lwip/core/ipv6/mld6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o middleware/lwip/core/ipv6/mld6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o: middleware/lwip/core/ipv6/nd6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o middleware/lwip/core/ipv6/nd6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/def.o: middleware/lwip/core/def.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/def.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/def.o.d" -o ${OBJECTDIR}/middleware/lwip/core/def.o middleware/lwip/core/def.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/dns.o: middleware/lwip/core/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/dns.o.d" -o ${OBJECTDIR}/middleware/lwip/core/dns.o middleware/lwip/core/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/inet_chksum.o: middleware/lwip/core/inet_chksum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" -o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o middleware/lwip/core/inet_chksum.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/init.o: middleware/lwip/core/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/init.o.d" -o ${OBJECTDIR}/middleware/lwip/core/init.o middleware/lwip/core/init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ip.o: middleware/lwip/core/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ip.o middleware/lwip/core/ip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/mem.o: middleware/lwip/core/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/mem.o.d" -o ${OBJECTDIR}/middleware/lwip/core/mem.o middleware/lwip/core/mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/memp.o: middleware/lwip/core/memp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/memp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/memp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/memp.o middleware/lwip/core/memp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/netif.o: middleware/lwip/core/netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/netif.o.d" -o ${OBJECTDIR}/middleware/lwip/core/netif.o middleware/lwip/core/netif.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/pbuf.o: middleware/lwip/core/pbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/core/pbuf.o middleware/lwip/core/pbuf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/raw.o: middleware/lwip/core/raw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/raw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/raw.o.d" -o ${OBJECTDIR}/middleware/lwip/core/raw.o middleware/lwip/core/raw.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/stats.o: middleware/lwip/core/stats.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/stats.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/stats.o.d" -o ${OBJECTDIR}/middleware/lwip/core/stats.o middleware/lwip/core/stats.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/sys.o: middleware/lwip/core/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/sys.o.d" -o ${OBJECTDIR}/middleware/lwip/core/sys.o middleware/lwip/core/sys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp.o: middleware/lwip/core/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp.o middleware/lwip/core/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_in.o: middleware/lwip/core/tcp_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o middleware/lwip/core/tcp_in.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_out.o: middleware/lwip/core/tcp_out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o middleware/lwip/core/tcp_out.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/timeouts.o: middleware/lwip/core/timeouts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" -o ${OBJECTDIR}/middleware/lwip/core/timeouts.o middleware/lwip/core/timeouts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/udp.o: middleware/lwip/core/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/udp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/udp.o middleware/lwip/core/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o: middleware/lwip/netif/ppp/polarssl/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o middleware/lwip/netif/ppp/polarssl/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o: middleware/lwip/netif/ppp/polarssl/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o middleware/lwip/netif/ppp/polarssl/des.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o: middleware/lwip/netif/ppp/polarssl/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o middleware/lwip/netif/ppp/polarssl/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o: middleware/lwip/netif/ppp/polarssl/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o middleware/lwip/netif/ppp/polarssl/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o: middleware/lwip/netif/ppp/polarssl/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o middleware/lwip/netif/ppp/polarssl/sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o: middleware/lwip/netif/ppp/auth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o middleware/lwip/netif/ppp/auth.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o: middleware/lwip/netif/ppp/ccp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o middleware/lwip/netif/ppp/ccp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o: middleware/lwip/netif/ppp/chap-md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o middleware/lwip/netif/ppp/chap-md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o: middleware/lwip/netif/ppp/chap-new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o middleware/lwip/netif/ppp/chap-new.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o: middleware/lwip/netif/ppp/chap_ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o middleware/lwip/netif/ppp/chap_ms.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o: middleware/lwip/netif/ppp/demand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o middleware/lwip/netif/ppp/demand.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o: middleware/lwip/netif/ppp/eap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o middleware/lwip/netif/ppp/eap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o: middleware/lwip/netif/ppp/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o middleware/lwip/netif/ppp/ecp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o: middleware/lwip/netif/ppp/eui64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o middleware/lwip/netif/ppp/eui64.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o: middleware/lwip/netif/ppp/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o middleware/lwip/netif/ppp/fsm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o: middleware/lwip/netif/ppp/ipcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o middleware/lwip/netif/ppp/ipcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o: middleware/lwip/netif/ppp/ipv6cp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o middleware/lwip/netif/ppp/ipv6cp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o: middleware/lwip/netif/ppp/lcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o middleware/lwip/netif/ppp/lcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o: middleware/lwip/netif/ppp/magic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o middleware/lwip/netif/ppp/magic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o: middleware/lwip/netif/ppp/mppe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o middleware/lwip/netif/ppp/mppe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o: middleware/lwip/netif/ppp/multilink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o middleware/lwip/netif/ppp/multilink.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o: middleware/lwip/netif/ppp/ppp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o middleware/lwip/netif/ppp/ppp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o: middleware/lwip/netif/ppp/pppapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o middleware/lwip/netif/ppp/pppapi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o: middleware/lwip/netif/ppp/pppcrypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o middleware/lwip/netif/ppp/pppcrypt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o: middleware/lwip/netif/ppp/pppoe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o middleware/lwip/netif/ppp/pppoe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o: middleware/lwip/netif/ppp/pppol2tp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o middleware/lwip/netif/ppp/pppol2tp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o: middleware/lwip/netif/ppp/pppos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o middleware/lwip/netif/ppp/pppos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o: middleware/lwip/netif/ppp/upap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o middleware/lwip/netif/ppp/upap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o: middleware/lwip/netif/ppp/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o middleware/lwip/netif/ppp/utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o: middleware/lwip/netif/ppp/vj.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o middleware/lwip/netif/ppp/vj.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernet.o: middleware/lwip/netif/ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o middleware/lwip/netif/ethernet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernetif.o: middleware/lwip/netif/ethernetif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o middleware/lwip/netif/ethernetif.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/port/sys_arch.o: middleware/lwip/port/sys_arch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/port" 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" -o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o middleware/lwip/port/sys_arch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o: middleware/mbedtls/port/alt_md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o middleware/mbedtls/port/alt_md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o: middleware/mbedtls/port/alt_sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o middleware/mbedtls/port/alt_sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o: middleware/mbedtls/port/alt_sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o middleware/mbedtls/port/alt_sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/aes.o: middleware/mbedtls/aes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aes.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aes.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/aes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/aes.o.d" -o ${OBJECTDIR}/middleware/mbedtls/aes.o middleware/mbedtls/aes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/aesni.o: middleware/mbedtls/aesni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aesni.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aesni.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/aesni.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/aesni.o.d" -o ${OBJECTDIR}/middleware/mbedtls/aesni.o middleware/mbedtls/aesni.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/arc4.o: middleware/mbedtls/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/arc4.o.d" -o ${OBJECTDIR}/middleware/mbedtls/arc4.o middleware/mbedtls/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/asn1parse.o: middleware/mbedtls/asn1parse.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1parse.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d" -o ${OBJECTDIR}/middleware/mbedtls/asn1parse.o middleware/mbedtls/asn1parse.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/asn1write.o: middleware/mbedtls/asn1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1write.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1write.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/asn1write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/asn1write.o.d" -o ${OBJECTDIR}/middleware/mbedtls/asn1write.o middleware/mbedtls/asn1write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/base64.o: middleware/mbedtls/base64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/base64.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/base64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/base64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/base64.o.d" -o ${OBJECTDIR}/middleware/mbedtls/base64.o middleware/mbedtls/base64.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/bignum.o: middleware/mbedtls/bignum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/bignum.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/bignum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/bignum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/bignum.o.d" -o ${OBJECTDIR}/middleware/mbedtls/bignum.o middleware/mbedtls/bignum.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/blowfish.o: middleware/mbedtls/blowfish.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/blowfish.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/blowfish.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/blowfish.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/blowfish.o.d" -o ${OBJECTDIR}/middleware/mbedtls/blowfish.o middleware/mbedtls/blowfish.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/camellia.o: middleware/mbedtls/camellia.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/camellia.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/camellia.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/camellia.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/camellia.o.d" -o ${OBJECTDIR}/middleware/mbedtls/camellia.o middleware/mbedtls/camellia.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ccm.o: middleware/mbedtls/ccm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ccm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ccm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ccm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ccm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ccm.o middleware/mbedtls/ccm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/certs.o: middleware/mbedtls/certs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/certs.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/certs.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/certs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/certs.o.d" -o ${OBJECTDIR}/middleware/mbedtls/certs.o middleware/mbedtls/certs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cipher.o: middleware/mbedtls/cipher.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cipher.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cipher.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cipher.o middleware/mbedtls/cipher.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o: middleware/mbedtls/cipher_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o middleware/mbedtls/cipher_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cmac.o: middleware/mbedtls/cmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cmac.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cmac.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cmac.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cmac.o middleware/mbedtls/cmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o: middleware/mbedtls/ctr_drbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o middleware/mbedtls/ctr_drbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/debug.o: middleware/mbedtls/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/debug.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/debug.o.d" -o ${OBJECTDIR}/middleware/mbedtls/debug.o middleware/mbedtls/debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/des.o: middleware/mbedtls/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/des.o.d" -o ${OBJECTDIR}/middleware/mbedtls/des.o middleware/mbedtls/des.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/dhm.o: middleware/mbedtls/dhm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/dhm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/dhm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/dhm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/dhm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/dhm.o middleware/mbedtls/dhm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecdh.o: middleware/mbedtls/ecdh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdh.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdh.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecdh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecdh.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecdh.o middleware/mbedtls/ecdh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecdsa.o: middleware/mbedtls/ecdsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdsa.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecdsa.o middleware/mbedtls/ecdsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecjpake.o: middleware/mbedtls/ecjpake.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecjpake.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecjpake.o middleware/mbedtls/ecjpake.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecp.o: middleware/mbedtls/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecp.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecp.o middleware/mbedtls/ecp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecp_curves.o: middleware/mbedtls/ecp_curves.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o middleware/mbedtls/ecp_curves.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/entropy.o: middleware/mbedtls/entropy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/entropy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/entropy.o.d" -o ${OBJECTDIR}/middleware/mbedtls/entropy.o middleware/mbedtls/entropy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/entropy_poll.o: middleware/mbedtls/entropy_poll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d" -o ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o middleware/mbedtls/entropy_poll.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/error.o: middleware/mbedtls/error.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/error.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/error.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/error.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/error.o.d" -o ${OBJECTDIR}/middleware/mbedtls/error.o middleware/mbedtls/error.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/gcm.o: middleware/mbedtls/gcm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/gcm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/gcm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/gcm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/gcm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/gcm.o middleware/mbedtls/gcm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/havege.o: middleware/mbedtls/havege.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/havege.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/havege.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/havege.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/havege.o.d" -o ${OBJECTDIR}/middleware/mbedtls/havege.o middleware/mbedtls/havege.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o: middleware/mbedtls/hmac_drbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d" -o ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o middleware/mbedtls/hmac_drbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md.o: middleware/mbedtls/md.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md.o middleware/mbedtls/md.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md2.o: middleware/mbedtls/md2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md2.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md2.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md2.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md2.o middleware/mbedtls/md2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md4.o: middleware/mbedtls/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md4.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md4.o middleware/mbedtls/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md5.o: middleware/mbedtls/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md5.o middleware/mbedtls/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md_wrap.o: middleware/mbedtls/md_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md_wrap.o middleware/mbedtls/md_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o: middleware/mbedtls/memory_buffer_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d" -o ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o middleware/mbedtls/memory_buffer_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/net_sockets.o: middleware/mbedtls/net_sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/net_sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d" -o ${OBJECTDIR}/middleware/mbedtls/net_sockets.o middleware/mbedtls/net_sockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/oid.o: middleware/mbedtls/oid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/oid.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/oid.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/oid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/oid.o.d" -o ${OBJECTDIR}/middleware/mbedtls/oid.o middleware/mbedtls/oid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/padlock.o: middleware/mbedtls/padlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/padlock.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/padlock.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/padlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/padlock.o.d" -o ${OBJECTDIR}/middleware/mbedtls/padlock.o middleware/mbedtls/padlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pem.o: middleware/mbedtls/pem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pem.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pem.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pem.o middleware/mbedtls/pem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pk.o: middleware/mbedtls/pk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pk.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pk.o middleware/mbedtls/pk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs11.o: middleware/mbedtls/pkcs11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs11.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs11.o middleware/mbedtls/pkcs11.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs12.o: middleware/mbedtls/pkcs12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs12.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs12.o middleware/mbedtls/pkcs12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs5.o: middleware/mbedtls/pkcs5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs5.o middleware/mbedtls/pkcs5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkparse.o: middleware/mbedtls/pkparse.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkparse.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkparse.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkparse.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkparse.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkparse.o middleware/mbedtls/pkparse.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkwrite.o: middleware/mbedtls/pkwrite.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkwrite.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkwrite.o middleware/mbedtls/pkwrite.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pk_wrap.o: middleware/mbedtls/pk_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o middleware/mbedtls/pk_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/platform.o: middleware/mbedtls/platform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/platform.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/platform.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/platform.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/platform.o.d" -o ${OBJECTDIR}/middleware/mbedtls/platform.o middleware/mbedtls/platform.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ripemd160.o: middleware/mbedtls/ripemd160.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ripemd160.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ripemd160.o middleware/mbedtls/ripemd160.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/rsa.o: middleware/mbedtls/rsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/rsa.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/rsa.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/rsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/rsa.o.d" -o ${OBJECTDIR}/middleware/mbedtls/rsa.o middleware/mbedtls/rsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha1.o: middleware/mbedtls/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha1.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha1.o middleware/mbedtls/sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha256.o: middleware/mbedtls/sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha256.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha256.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha256.o middleware/mbedtls/sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha512.o: middleware/mbedtls/sha512.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha512.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha512.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha512.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha512.o middleware/mbedtls/sha512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cache.o: middleware/mbedtls/ssl_cache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o middleware/mbedtls/ssl_cache.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o: middleware/mbedtls/ssl_ciphersuites.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o middleware/mbedtls/ssl_ciphersuites.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cli.o: middleware/mbedtls/ssl_cli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o middleware/mbedtls/ssl_cli.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o: middleware/mbedtls/ssl_cookie.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o middleware/mbedtls/ssl_cookie.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_srv.o: middleware/mbedtls/ssl_srv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o middleware/mbedtls/ssl_srv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o: middleware/mbedtls/ssl_ticket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o middleware/mbedtls/ssl_ticket.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_tls.o: middleware/mbedtls/ssl_tls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o middleware/mbedtls/ssl_tls.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/threading.o: middleware/mbedtls/threading.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/threading.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/threading.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/threading.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/threading.o.d" -o ${OBJECTDIR}/middleware/mbedtls/threading.o middleware/mbedtls/threading.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/timing.o: middleware/mbedtls/timing.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/timing.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/timing.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/timing.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/timing.o.d" -o ${OBJECTDIR}/middleware/mbedtls/timing.o middleware/mbedtls/timing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/version.o: middleware/mbedtls/version.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/version.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/version.o.d" -o ${OBJECTDIR}/middleware/mbedtls/version.o middleware/mbedtls/version.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/version_features.o: middleware/mbedtls/version_features.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version_features.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version_features.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/version_features.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/version_features.o.d" -o ${OBJECTDIR}/middleware/mbedtls/version_features.o middleware/mbedtls/version_features.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509.o: middleware/mbedtls/x509.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509.o middleware/mbedtls/x509.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509write_crt.o: middleware/mbedtls/x509write_crt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o middleware/mbedtls/x509write_crt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509write_csr.o: middleware/mbedtls/x509write_csr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o middleware/mbedtls/x509write_csr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_create.o: middleware/mbedtls/x509_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_create.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_create.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_create.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_create.o middleware/mbedtls/x509_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_crl.o: middleware/mbedtls/x509_crl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crl.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_crl.o middleware/mbedtls/x509_crl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_crt.o: middleware/mbedtls/x509_crt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_crt.o middleware/mbedtls/x509_crt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_csr.o: middleware/mbedtls/x509_csr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_csr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_csr.o middleware/mbedtls/x509_csr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/xtea.o: middleware/mbedtls/xtea.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/xtea.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/xtea.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/xtea.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/xtea.o.d" -o ${OBJECTDIR}/middleware/mbedtls/xtea.o middleware/mbedtls/xtea.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/freertos_common.o: middleware/wizio/freertos_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" -o ${OBJECTDIR}/middleware/wizio/freertos_common.o middleware/wizio/freertos_common.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/wrap_mem.o: middleware/wizio/wrap_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" -o ${OBJECTDIR}/middleware/wizio/wrap_mem.o middleware/wizio/wrap_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys.o: sys/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys.o.d 
	@${RM} ${OBJECTDIR}/sys/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys.o.d" -o ${OBJECTDIR}/sys/sys.o sys/sys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_common.o: sys/sys_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_common.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_common.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_common.o.d" -o ${OBJECTDIR}/sys/sys_common.o sys/sys_common.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_config.o: sys/sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_config.o.d" -o ${OBJECTDIR}/sys/sys_config.o sys/sys_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_rtcc.o: sys/sys_rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_rtcc.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_rtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_rtcc.o.d" -o ${OBJECTDIR}/sys/sys_rtcc.o sys/sys_rtcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_trap.o: sys/sys_trap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_trap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_trap.o.d" -o ${OBJECTDIR}/sys/sys_trap.o sys/sys_trap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_log.o: sys/sys_log.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_log.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_log.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_log.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_log.o.d" -o ${OBJECTDIR}/sys/sys_log.o sys/sys_log.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o: middleware/wizio/pic32mz-crypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d" -o ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o middleware/wizio/pic32mz-crypt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/apps/app_http.o: apps/app_http.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/apps" 
	@${RM} ${OBJECTDIR}/apps/app_http.o.d 
	@${RM} ${OBJECTDIR}/apps/app_http.o 
	@${FIXDEPS} "${OBJECTDIR}/apps/app_http.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/apps/app_http.o.d" -o ${OBJECTDIR}/apps/app_http.o apps/app_http.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf.o: drivers/mrf24wn/mrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf.o drivers/mrf24wn/mrf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o: drivers/mrf24wn/mrf_hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o drivers/mrf24wn/mrf_hal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o: drivers/mrf24wn/mrf_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o drivers/mrf24wn/mrf_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o: drivers/mrf24wn/mrf_osal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o drivers/mrf24wn/mrf_osal.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o: middleware/freertos/portable/MemMang/umm_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MemMang" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o middleware/freertos/portable/MemMang/umm_malloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o: middleware/freertos/portable/MPLAB/PIC32MZ/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o middleware/freertos/portable/MPLAB/PIC32MZ/port.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/croutine.o: middleware/freertos/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/croutine.o.d" -o ${OBJECTDIR}/middleware/freertos/croutine.o middleware/freertos/croutine.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/event_groups.o: middleware/freertos/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/event_groups.o.d" -o ${OBJECTDIR}/middleware/freertos/event_groups.o middleware/freertos/event_groups.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/list.o: middleware/freertos/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/list.o.d" -o ${OBJECTDIR}/middleware/freertos/list.o middleware/freertos/list.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/queue.o: middleware/freertos/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/queue.o.d" -o ${OBJECTDIR}/middleware/freertos/queue.o middleware/freertos/queue.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/stream_buffer.o: middleware/freertos/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" -o ${OBJECTDIR}/middleware/freertos/stream_buffer.o middleware/freertos/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/tasks.o: middleware/freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/tasks.o.d" -o ${OBJECTDIR}/middleware/freertos/tasks.o middleware/freertos/tasks.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/timers.o: middleware/freertos/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/freertos/timers.o.d" -o ${OBJECTDIR}/middleware/freertos/timers.o middleware/freertos/timers.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/http/httpclient.o: middleware/http/httpclient.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/http" 
	@${RM} ${OBJECTDIR}/middleware/http/httpclient.o.d 
	@${RM} ${OBJECTDIR}/middleware/http/httpclient.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/http/httpclient.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/http/httpclient.o.d" -o ${OBJECTDIR}/middleware/http/httpclient.o middleware/http/httpclient.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_lib.o: middleware/lwip/api/api_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_lib.o middleware/lwip/api/api_lib.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_msg.o: middleware/lwip/api/api_msg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_msg.o middleware/lwip/api/api_msg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/err.o: middleware/lwip/api/err.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/err.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/err.o.d" -o ${OBJECTDIR}/middleware/lwip/api/err.o middleware/lwip/api/err.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netbuf.o: middleware/lwip/api/netbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netbuf.o middleware/lwip/api/netbuf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netdb.o: middleware/lwip/api/netdb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netdb.o middleware/lwip/api/netdb.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netifapi.o: middleware/lwip/api/netifapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netifapi.o middleware/lwip/api/netifapi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/sockets.o: middleware/lwip/api/sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" -o ${OBJECTDIR}/middleware/lwip/api/sockets.o middleware/lwip/api/sockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/tcpip.o: middleware/lwip/api/tcpip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" -o ${OBJECTDIR}/middleware/lwip/api/tcpip.o middleware/lwip/api/tcpip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o: middleware/lwip/core/ipv4/autoip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o middleware/lwip/core/ipv4/autoip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o: middleware/lwip/core/ipv4/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o middleware/lwip/core/ipv4/dhcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o: middleware/lwip/core/ipv4/etharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o middleware/lwip/core/ipv4/etharp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o: middleware/lwip/core/ipv4/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o middleware/lwip/core/ipv4/icmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o: middleware/lwip/core/ipv4/igmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o middleware/lwip/core/ipv4/igmp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o: middleware/lwip/core/ipv4/ip4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o middleware/lwip/core/ipv4/ip4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o: middleware/lwip/core/ipv4/ip4_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o middleware/lwip/core/ipv4/ip4_addr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o: middleware/lwip/core/ipv4/ip4_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o middleware/lwip/core/ipv4/ip4_frag.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o: middleware/lwip/core/ipv6/dhcp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o middleware/lwip/core/ipv6/dhcp6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o: middleware/lwip/core/ipv6/ethip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o middleware/lwip/core/ipv6/ethip6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o: middleware/lwip/core/ipv6/icmp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o middleware/lwip/core/ipv6/icmp6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o: middleware/lwip/core/ipv6/inet6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o middleware/lwip/core/ipv6/inet6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o: middleware/lwip/core/ipv6/ip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o middleware/lwip/core/ipv6/ip6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o: middleware/lwip/core/ipv6/ip6_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o middleware/lwip/core/ipv6/ip6_addr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o: middleware/lwip/core/ipv6/ip6_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o middleware/lwip/core/ipv6/ip6_frag.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o: middleware/lwip/core/ipv6/mld6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o middleware/lwip/core/ipv6/mld6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o: middleware/lwip/core/ipv6/nd6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o middleware/lwip/core/ipv6/nd6.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/def.o: middleware/lwip/core/def.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/def.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/def.o.d" -o ${OBJECTDIR}/middleware/lwip/core/def.o middleware/lwip/core/def.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/dns.o: middleware/lwip/core/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/dns.o.d" -o ${OBJECTDIR}/middleware/lwip/core/dns.o middleware/lwip/core/dns.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/inet_chksum.o: middleware/lwip/core/inet_chksum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" -o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o middleware/lwip/core/inet_chksum.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/init.o: middleware/lwip/core/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/init.o.d" -o ${OBJECTDIR}/middleware/lwip/core/init.o middleware/lwip/core/init.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ip.o: middleware/lwip/core/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ip.o middleware/lwip/core/ip.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/mem.o: middleware/lwip/core/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/mem.o.d" -o ${OBJECTDIR}/middleware/lwip/core/mem.o middleware/lwip/core/mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/memp.o: middleware/lwip/core/memp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/memp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/memp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/memp.o middleware/lwip/core/memp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/netif.o: middleware/lwip/core/netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/netif.o.d" -o ${OBJECTDIR}/middleware/lwip/core/netif.o middleware/lwip/core/netif.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/pbuf.o: middleware/lwip/core/pbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/core/pbuf.o middleware/lwip/core/pbuf.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/raw.o: middleware/lwip/core/raw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/raw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/raw.o.d" -o ${OBJECTDIR}/middleware/lwip/core/raw.o middleware/lwip/core/raw.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/stats.o: middleware/lwip/core/stats.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/stats.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/stats.o.d" -o ${OBJECTDIR}/middleware/lwip/core/stats.o middleware/lwip/core/stats.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/sys.o: middleware/lwip/core/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/sys.o.d" -o ${OBJECTDIR}/middleware/lwip/core/sys.o middleware/lwip/core/sys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp.o: middleware/lwip/core/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp.o middleware/lwip/core/tcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_in.o: middleware/lwip/core/tcp_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o middleware/lwip/core/tcp_in.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_out.o: middleware/lwip/core/tcp_out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o middleware/lwip/core/tcp_out.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/timeouts.o: middleware/lwip/core/timeouts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" -o ${OBJECTDIR}/middleware/lwip/core/timeouts.o middleware/lwip/core/timeouts.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/udp.o: middleware/lwip/core/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/udp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/udp.o middleware/lwip/core/udp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o: middleware/lwip/netif/ppp/polarssl/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o middleware/lwip/netif/ppp/polarssl/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o: middleware/lwip/netif/ppp/polarssl/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o middleware/lwip/netif/ppp/polarssl/des.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o: middleware/lwip/netif/ppp/polarssl/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o middleware/lwip/netif/ppp/polarssl/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o: middleware/lwip/netif/ppp/polarssl/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o middleware/lwip/netif/ppp/polarssl/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o: middleware/lwip/netif/ppp/polarssl/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o middleware/lwip/netif/ppp/polarssl/sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o: middleware/lwip/netif/ppp/auth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o middleware/lwip/netif/ppp/auth.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o: middleware/lwip/netif/ppp/ccp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o middleware/lwip/netif/ppp/ccp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o: middleware/lwip/netif/ppp/chap-md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o middleware/lwip/netif/ppp/chap-md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o: middleware/lwip/netif/ppp/chap-new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o middleware/lwip/netif/ppp/chap-new.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o: middleware/lwip/netif/ppp/chap_ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o middleware/lwip/netif/ppp/chap_ms.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o: middleware/lwip/netif/ppp/demand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o middleware/lwip/netif/ppp/demand.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o: middleware/lwip/netif/ppp/eap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o middleware/lwip/netif/ppp/eap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o: middleware/lwip/netif/ppp/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o middleware/lwip/netif/ppp/ecp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o: middleware/lwip/netif/ppp/eui64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o middleware/lwip/netif/ppp/eui64.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o: middleware/lwip/netif/ppp/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o middleware/lwip/netif/ppp/fsm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o: middleware/lwip/netif/ppp/ipcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o middleware/lwip/netif/ppp/ipcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o: middleware/lwip/netif/ppp/ipv6cp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o middleware/lwip/netif/ppp/ipv6cp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o: middleware/lwip/netif/ppp/lcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o middleware/lwip/netif/ppp/lcp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o: middleware/lwip/netif/ppp/magic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o middleware/lwip/netif/ppp/magic.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o: middleware/lwip/netif/ppp/mppe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o middleware/lwip/netif/ppp/mppe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o: middleware/lwip/netif/ppp/multilink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o middleware/lwip/netif/ppp/multilink.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o: middleware/lwip/netif/ppp/ppp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o middleware/lwip/netif/ppp/ppp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o: middleware/lwip/netif/ppp/pppapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o middleware/lwip/netif/ppp/pppapi.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o: middleware/lwip/netif/ppp/pppcrypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o middleware/lwip/netif/ppp/pppcrypt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o: middleware/lwip/netif/ppp/pppoe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o middleware/lwip/netif/ppp/pppoe.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o: middleware/lwip/netif/ppp/pppol2tp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o middleware/lwip/netif/ppp/pppol2tp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o: middleware/lwip/netif/ppp/pppos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o middleware/lwip/netif/ppp/pppos.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o: middleware/lwip/netif/ppp/upap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o middleware/lwip/netif/ppp/upap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o: middleware/lwip/netif/ppp/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o middleware/lwip/netif/ppp/utils.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o: middleware/lwip/netif/ppp/vj.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o middleware/lwip/netif/ppp/vj.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernet.o: middleware/lwip/netif/ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o middleware/lwip/netif/ethernet.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernetif.o: middleware/lwip/netif/ethernetif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o middleware/lwip/netif/ethernetif.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/port/sys_arch.o: middleware/lwip/port/sys_arch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/port" 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" -o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o middleware/lwip/port/sys_arch.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o: middleware/mbedtls/port/alt_md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_md5.o middleware/mbedtls/port/alt_md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o: middleware/mbedtls/port/alt_sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha256.o middleware/mbedtls/port/alt_sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o: middleware/mbedtls/port/alt_sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls/port" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o.d" -o ${OBJECTDIR}/middleware/mbedtls/port/alt_sha1.o middleware/mbedtls/port/alt_sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/aes.o: middleware/mbedtls/aes.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aes.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aes.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/aes.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/aes.o.d" -o ${OBJECTDIR}/middleware/mbedtls/aes.o middleware/mbedtls/aes.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/aesni.o: middleware/mbedtls/aesni.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aesni.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/aesni.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/aesni.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/aesni.o.d" -o ${OBJECTDIR}/middleware/mbedtls/aesni.o middleware/mbedtls/aesni.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/arc4.o: middleware/mbedtls/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/arc4.o.d" -o ${OBJECTDIR}/middleware/mbedtls/arc4.o middleware/mbedtls/arc4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/asn1parse.o: middleware/mbedtls/asn1parse.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1parse.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/asn1parse.o.d" -o ${OBJECTDIR}/middleware/mbedtls/asn1parse.o middleware/mbedtls/asn1parse.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/asn1write.o: middleware/mbedtls/asn1write.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1write.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/asn1write.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/asn1write.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/asn1write.o.d" -o ${OBJECTDIR}/middleware/mbedtls/asn1write.o middleware/mbedtls/asn1write.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/base64.o: middleware/mbedtls/base64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/base64.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/base64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/base64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/base64.o.d" -o ${OBJECTDIR}/middleware/mbedtls/base64.o middleware/mbedtls/base64.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/bignum.o: middleware/mbedtls/bignum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/bignum.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/bignum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/bignum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/bignum.o.d" -o ${OBJECTDIR}/middleware/mbedtls/bignum.o middleware/mbedtls/bignum.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/blowfish.o: middleware/mbedtls/blowfish.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/blowfish.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/blowfish.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/blowfish.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/blowfish.o.d" -o ${OBJECTDIR}/middleware/mbedtls/blowfish.o middleware/mbedtls/blowfish.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/camellia.o: middleware/mbedtls/camellia.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/camellia.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/camellia.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/camellia.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/camellia.o.d" -o ${OBJECTDIR}/middleware/mbedtls/camellia.o middleware/mbedtls/camellia.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ccm.o: middleware/mbedtls/ccm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ccm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ccm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ccm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ccm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ccm.o middleware/mbedtls/ccm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/certs.o: middleware/mbedtls/certs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/certs.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/certs.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/certs.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/certs.o.d" -o ${OBJECTDIR}/middleware/mbedtls/certs.o middleware/mbedtls/certs.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cipher.o: middleware/mbedtls/cipher.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cipher.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cipher.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cipher.o middleware/mbedtls/cipher.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o: middleware/mbedtls/cipher_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cipher_wrap.o middleware/mbedtls/cipher_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/cmac.o: middleware/mbedtls/cmac.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cmac.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/cmac.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/cmac.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/cmac.o.d" -o ${OBJECTDIR}/middleware/mbedtls/cmac.o middleware/mbedtls/cmac.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o: middleware/mbedtls/ctr_drbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ctr_drbg.o middleware/mbedtls/ctr_drbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/debug.o: middleware/mbedtls/debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/debug.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/debug.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/debug.o.d" -o ${OBJECTDIR}/middleware/mbedtls/debug.o middleware/mbedtls/debug.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/des.o: middleware/mbedtls/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/des.o.d" -o ${OBJECTDIR}/middleware/mbedtls/des.o middleware/mbedtls/des.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/dhm.o: middleware/mbedtls/dhm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/dhm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/dhm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/dhm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/dhm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/dhm.o middleware/mbedtls/dhm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecdh.o: middleware/mbedtls/ecdh.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdh.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdh.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecdh.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecdh.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecdh.o middleware/mbedtls/ecdh.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecdsa.o: middleware/mbedtls/ecdsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecdsa.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecdsa.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecdsa.o middleware/mbedtls/ecdsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecjpake.o: middleware/mbedtls/ecjpake.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecjpake.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecjpake.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecjpake.o middleware/mbedtls/ecjpake.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecp.o: middleware/mbedtls/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecp.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecp.o middleware/mbedtls/ecp.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ecp_curves.o: middleware/mbedtls/ecp_curves.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ecp_curves.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ecp_curves.o middleware/mbedtls/ecp_curves.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/entropy.o: middleware/mbedtls/entropy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/entropy.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/entropy.o.d" -o ${OBJECTDIR}/middleware/mbedtls/entropy.o middleware/mbedtls/entropy.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/entropy_poll.o: middleware/mbedtls/entropy_poll.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/entropy_poll.o.d" -o ${OBJECTDIR}/middleware/mbedtls/entropy_poll.o middleware/mbedtls/entropy_poll.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/error.o: middleware/mbedtls/error.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/error.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/error.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/error.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/error.o.d" -o ${OBJECTDIR}/middleware/mbedtls/error.o middleware/mbedtls/error.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/gcm.o: middleware/mbedtls/gcm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/gcm.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/gcm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/gcm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/gcm.o.d" -o ${OBJECTDIR}/middleware/mbedtls/gcm.o middleware/mbedtls/gcm.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/havege.o: middleware/mbedtls/havege.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/havege.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/havege.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/havege.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/havege.o.d" -o ${OBJECTDIR}/middleware/mbedtls/havege.o middleware/mbedtls/havege.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o: middleware/mbedtls/hmac_drbg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o.d" -o ${OBJECTDIR}/middleware/mbedtls/hmac_drbg.o middleware/mbedtls/hmac_drbg.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md.o: middleware/mbedtls/md.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md.o middleware/mbedtls/md.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md2.o: middleware/mbedtls/md2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md2.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md2.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md2.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md2.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md2.o middleware/mbedtls/md2.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md4.o: middleware/mbedtls/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md4.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md4.o middleware/mbedtls/md4.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md5.o: middleware/mbedtls/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md5.o middleware/mbedtls/md5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/md_wrap.o: middleware/mbedtls/md_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/md_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/md_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/md_wrap.o middleware/mbedtls/md_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o: middleware/mbedtls/memory_buffer_alloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o.d" -o ${OBJECTDIR}/middleware/mbedtls/memory_buffer_alloc.o middleware/mbedtls/memory_buffer_alloc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/net_sockets.o: middleware/mbedtls/net_sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/net_sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/net_sockets.o.d" -o ${OBJECTDIR}/middleware/mbedtls/net_sockets.o middleware/mbedtls/net_sockets.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/oid.o: middleware/mbedtls/oid.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/oid.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/oid.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/oid.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/oid.o.d" -o ${OBJECTDIR}/middleware/mbedtls/oid.o middleware/mbedtls/oid.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/padlock.o: middleware/mbedtls/padlock.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/padlock.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/padlock.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/padlock.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/padlock.o.d" -o ${OBJECTDIR}/middleware/mbedtls/padlock.o middleware/mbedtls/padlock.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pem.o: middleware/mbedtls/pem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pem.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pem.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pem.o middleware/mbedtls/pem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pk.o: middleware/mbedtls/pk.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pk.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pk.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pk.o middleware/mbedtls/pk.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs11.o: middleware/mbedtls/pkcs11.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs11.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs11.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs11.o middleware/mbedtls/pkcs11.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs12.o: middleware/mbedtls/pkcs12.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs12.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs12.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs12.o middleware/mbedtls/pkcs12.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkcs5.o: middleware/mbedtls/pkcs5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkcs5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkcs5.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkcs5.o middleware/mbedtls/pkcs5.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkparse.o: middleware/mbedtls/pkparse.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkparse.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkparse.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkparse.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkparse.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkparse.o middleware/mbedtls/pkparse.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pkwrite.o: middleware/mbedtls/pkwrite.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pkwrite.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pkwrite.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pkwrite.o middleware/mbedtls/pkwrite.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/pk_wrap.o: middleware/mbedtls/pk_wrap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/pk_wrap.o.d" -o ${OBJECTDIR}/middleware/mbedtls/pk_wrap.o middleware/mbedtls/pk_wrap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/platform.o: middleware/mbedtls/platform.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/platform.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/platform.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/platform.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/platform.o.d" -o ${OBJECTDIR}/middleware/mbedtls/platform.o middleware/mbedtls/platform.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ripemd160.o: middleware/mbedtls/ripemd160.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ripemd160.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ripemd160.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ripemd160.o middleware/mbedtls/ripemd160.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/rsa.o: middleware/mbedtls/rsa.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/rsa.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/rsa.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/rsa.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/rsa.o.d" -o ${OBJECTDIR}/middleware/mbedtls/rsa.o middleware/mbedtls/rsa.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha1.o: middleware/mbedtls/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha1.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha1.o middleware/mbedtls/sha1.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha256.o: middleware/mbedtls/sha256.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha256.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha256.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha256.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha256.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha256.o middleware/mbedtls/sha256.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/sha512.o: middleware/mbedtls/sha512.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha512.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/sha512.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/sha512.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/sha512.o.d" -o ${OBJECTDIR}/middleware/mbedtls/sha512.o middleware/mbedtls/sha512.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cache.o: middleware/mbedtls/ssl_cache.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cache.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cache.o middleware/mbedtls/ssl_cache.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o: middleware/mbedtls/ssl_ciphersuites.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_ciphersuites.o middleware/mbedtls/ssl_ciphersuites.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cli.o: middleware/mbedtls/ssl_cli.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cli.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cli.o middleware/mbedtls/ssl_cli.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o: middleware/mbedtls/ssl_cookie.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_cookie.o middleware/mbedtls/ssl_cookie.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_srv.o: middleware/mbedtls/ssl_srv.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_srv.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_srv.o middleware/mbedtls/ssl_srv.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o: middleware/mbedtls/ssl_ticket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_ticket.o middleware/mbedtls/ssl_ticket.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/ssl_tls.o: middleware/mbedtls/ssl_tls.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/ssl_tls.o.d" -o ${OBJECTDIR}/middleware/mbedtls/ssl_tls.o middleware/mbedtls/ssl_tls.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/threading.o: middleware/mbedtls/threading.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/threading.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/threading.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/threading.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/threading.o.d" -o ${OBJECTDIR}/middleware/mbedtls/threading.o middleware/mbedtls/threading.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/timing.o: middleware/mbedtls/timing.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/timing.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/timing.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/timing.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/timing.o.d" -o ${OBJECTDIR}/middleware/mbedtls/timing.o middleware/mbedtls/timing.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/version.o: middleware/mbedtls/version.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/version.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/version.o.d" -o ${OBJECTDIR}/middleware/mbedtls/version.o middleware/mbedtls/version.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/version_features.o: middleware/mbedtls/version_features.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version_features.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/version_features.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/version_features.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/version_features.o.d" -o ${OBJECTDIR}/middleware/mbedtls/version_features.o middleware/mbedtls/version_features.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509.o: middleware/mbedtls/x509.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509.o middleware/mbedtls/x509.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509write_crt.o: middleware/mbedtls/x509write_crt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509write_crt.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509write_crt.o middleware/mbedtls/x509write_crt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509write_csr.o: middleware/mbedtls/x509write_csr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509write_csr.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509write_csr.o middleware/mbedtls/x509write_csr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_create.o: middleware/mbedtls/x509_create.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_create.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_create.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_create.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_create.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_create.o middleware/mbedtls/x509_create.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_crl.o: middleware/mbedtls/x509_crl.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crl.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_crl.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_crl.o middleware/mbedtls/x509_crl.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_crt.o: middleware/mbedtls/x509_crt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_crt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_crt.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_crt.o middleware/mbedtls/x509_crt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/x509_csr.o: middleware/mbedtls/x509_csr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/x509_csr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/x509_csr.o.d" -o ${OBJECTDIR}/middleware/mbedtls/x509_csr.o middleware/mbedtls/x509_csr.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/mbedtls/xtea.o: middleware/mbedtls/xtea.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/mbedtls" 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/xtea.o.d 
	@${RM} ${OBJECTDIR}/middleware/mbedtls/xtea.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/mbedtls/xtea.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/mbedtls/xtea.o.d" -o ${OBJECTDIR}/middleware/mbedtls/xtea.o middleware/mbedtls/xtea.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/freertos_common.o: middleware/wizio/freertos_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" -o ${OBJECTDIR}/middleware/wizio/freertos_common.o middleware/wizio/freertos_common.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/wrap_mem.o: middleware/wizio/wrap_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" -o ${OBJECTDIR}/middleware/wizio/wrap_mem.o middleware/wizio/wrap_mem.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys.o: sys/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys.o.d 
	@${RM} ${OBJECTDIR}/sys/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys.o.d" -o ${OBJECTDIR}/sys/sys.o sys/sys.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_common.o: sys/sys_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_common.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_common.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_common.o.d" -o ${OBJECTDIR}/sys/sys_common.o sys/sys_common.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_config.o: sys/sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_config.o.d" -o ${OBJECTDIR}/sys/sys_config.o sys/sys_config.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_rtcc.o: sys/sys_rtcc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_rtcc.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_rtcc.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_rtcc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_rtcc.o.d" -o ${OBJECTDIR}/sys/sys_rtcc.o sys/sys_rtcc.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_trap.o: sys/sys_trap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_trap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_trap.o.d" -o ${OBJECTDIR}/sys/sys_trap.o sys/sys_trap.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_log.o: sys/sys_log.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_log.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_log.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_log.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/sys/sys_log.o.d" -o ${OBJECTDIR}/sys/sys_log.o sys/sys_log.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o: middleware/wizio/pic32mz-crypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"sys/fan" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -I"drivers/mrf24wn" -I"middleware" -I"middleware/mbedtls/include" -I"middleware/mbedtls/configs" -I"middleware/http" -I"apps" -MMD -MF "${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o.d" -o ${OBJECTDIR}/middleware/wizio/pic32mz-crypt.o middleware/wizio/pic32mz-crypt.c    -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD) 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  drivers/mrf24wn/wdrvext_mz_ef.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    drivers\mrf24wn\wdrvext_mz_ef.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--wrap,malloc,--wrap,free
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  drivers/mrf24wn/wdrvext_mz_ef.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    drivers\mrf24wn\wdrvext_mz_ef.a      -DXPRJ_default=$(CND_CONF)  -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--wrap,malloc,--wrap,free
	${MP_CC_DIR}\\xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
