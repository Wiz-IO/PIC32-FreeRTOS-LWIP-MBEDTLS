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

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=middleware/freertos/portable/MemMang/umm_malloc.c middleware/freertos/portable/MPLAB/PIC32MZ/port.c middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S middleware/freertos/croutine.c middleware/freertos/event_groups.c middleware/freertos/list.c middleware/freertos/queue.c middleware/freertos/stream_buffer.c middleware/freertos/tasks.c middleware/freertos/timers.c sys/sys.c sys/sys_config.c sys/sys_trap.c sys/sys_debug.c sys/sys_common.c main.c middleware/wizio/wrap_mem.c middleware/wizio/freertos_common.c drivers/mrf24wn/mrf_hal.c drivers/mrf24wn/mrf_isr.S drivers/mrf24wn/mrf_lib.c drivers/mrf24wn/mrf_osal.c drivers/mrf24wn/mrf.c drivers/mrf24wn/mrf_netif.c app_driver.c middleware/lwip/api/api_lib.c middleware/lwip/api/api_msg.c middleware/lwip/api/err.c middleware/lwip/api/netbuf.c middleware/lwip/api/netdb.c middleware/lwip/api/netifapi.c middleware/lwip/api/sockets.c middleware/lwip/api/tcpip.c middleware/lwip/core/def.c middleware/lwip/core/dns.c middleware/lwip/core/inet_chksum.c middleware/lwip/core/init.c middleware/lwip/core/ip.c middleware/lwip/core/ipv4/autoip.c middleware/lwip/core/ipv4/dhcp.c middleware/lwip/core/ipv4/etharp.c middleware/lwip/core/ipv4/icmp.c middleware/lwip/core/ipv4/igmp.c middleware/lwip/core/ipv4/ip4.c middleware/lwip/core/ipv4/ip4_addr.c middleware/lwip/core/ipv4/ip4_frag.c middleware/lwip/core/ipv6/dhcp6.c middleware/lwip/core/ipv6/ethip6.c middleware/lwip/core/ipv6/icmp6.c middleware/lwip/core/ipv6/inet6.c middleware/lwip/core/ipv6/ip6.c middleware/lwip/core/ipv6/ip6_addr.c middleware/lwip/core/ipv6/ip6_frag.c middleware/lwip/core/ipv6/mld6.c middleware/lwip/core/ipv6/nd6.c middleware/lwip/core/mem.c middleware/lwip/core/memp.c middleware/lwip/core/netif.c middleware/lwip/core/pbuf.c middleware/lwip/core/raw.c middleware/lwip/core/stats.c middleware/lwip/core/sys.c middleware/lwip/core/tcp.c middleware/lwip/core/tcp_in.c middleware/lwip/core/tcp_out.c middleware/lwip/core/timeouts.c middleware/lwip/core/udp.c middleware/lwip/netif/ethernet.c middleware/lwip/netif/ethernetif.c middleware/lwip/netif/lowpan6.c middleware/lwip/netif/ppp/auth.c middleware/lwip/netif/ppp/ccp.c middleware/lwip/netif/ppp/chap-md5.c middleware/lwip/netif/ppp/chap-new.c middleware/lwip/netif/ppp/chap_ms.c middleware/lwip/netif/ppp/demand.c middleware/lwip/netif/ppp/eap.c middleware/lwip/netif/ppp/ecp.c middleware/lwip/netif/ppp/eui64.c middleware/lwip/netif/ppp/fsm.c middleware/lwip/netif/ppp/ipcp.c middleware/lwip/netif/ppp/ipv6cp.c middleware/lwip/netif/ppp/lcp.c middleware/lwip/netif/ppp/magic.c middleware/lwip/netif/ppp/mppe.c middleware/lwip/netif/ppp/multilink.c middleware/lwip/netif/ppp/polarssl/arc4.c middleware/lwip/netif/ppp/polarssl/des.c middleware/lwip/netif/ppp/polarssl/md4.c middleware/lwip/netif/ppp/polarssl/md5.c middleware/lwip/netif/ppp/polarssl/sha1.c middleware/lwip/netif/ppp/ppp.c middleware/lwip/netif/ppp/pppapi.c middleware/lwip/netif/ppp/pppcrypt.c middleware/lwip/netif/ppp/pppoe.c middleware/lwip/netif/ppp/pppol2tp.c middleware/lwip/netif/ppp/pppos.c middleware/lwip/netif/ppp/upap.c middleware/lwip/netif/ppp/utils.c middleware/lwip/netif/ppp/vj.c middleware/lwip/netif/slipif.c middleware/lwip/port/sys_arch.c app_lwip.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o ${OBJECTDIR}/middleware/freertos/croutine.o ${OBJECTDIR}/middleware/freertos/event_groups.o ${OBJECTDIR}/middleware/freertos/list.o ${OBJECTDIR}/middleware/freertos/queue.o ${OBJECTDIR}/middleware/freertos/stream_buffer.o ${OBJECTDIR}/middleware/freertos/tasks.o ${OBJECTDIR}/middleware/freertos/timers.o ${OBJECTDIR}/sys/sys.o ${OBJECTDIR}/sys/sys_config.o ${OBJECTDIR}/sys/sys_trap.o ${OBJECTDIR}/sys/sys_debug.o ${OBJECTDIR}/sys/sys_common.o ${OBJECTDIR}/main.o ${OBJECTDIR}/middleware/wizio/wrap_mem.o ${OBJECTDIR}/middleware/wizio/freertos_common.o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o ${OBJECTDIR}/drivers/mrf24wn/mrf.o ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o ${OBJECTDIR}/app_driver.o ${OBJECTDIR}/middleware/lwip/api/api_lib.o ${OBJECTDIR}/middleware/lwip/api/api_msg.o ${OBJECTDIR}/middleware/lwip/api/err.o ${OBJECTDIR}/middleware/lwip/api/netbuf.o ${OBJECTDIR}/middleware/lwip/api/netdb.o ${OBJECTDIR}/middleware/lwip/api/netifapi.o ${OBJECTDIR}/middleware/lwip/api/sockets.o ${OBJECTDIR}/middleware/lwip/api/tcpip.o ${OBJECTDIR}/middleware/lwip/core/def.o ${OBJECTDIR}/middleware/lwip/core/dns.o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o ${OBJECTDIR}/middleware/lwip/core/init.o ${OBJECTDIR}/middleware/lwip/core/ip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o ${OBJECTDIR}/middleware/lwip/core/mem.o ${OBJECTDIR}/middleware/lwip/core/memp.o ${OBJECTDIR}/middleware/lwip/core/netif.o ${OBJECTDIR}/middleware/lwip/core/pbuf.o ${OBJECTDIR}/middleware/lwip/core/raw.o ${OBJECTDIR}/middleware/lwip/core/stats.o ${OBJECTDIR}/middleware/lwip/core/sys.o ${OBJECTDIR}/middleware/lwip/core/tcp.o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o ${OBJECTDIR}/middleware/lwip/core/timeouts.o ${OBJECTDIR}/middleware/lwip/core/udp.o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o ${OBJECTDIR}/middleware/lwip/netif/slipif.o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o ${OBJECTDIR}/app_lwip.o
POSSIBLE_DEPFILES=${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d ${OBJECTDIR}/middleware/freertos/croutine.o.d ${OBJECTDIR}/middleware/freertos/event_groups.o.d ${OBJECTDIR}/middleware/freertos/list.o.d ${OBJECTDIR}/middleware/freertos/queue.o.d ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d ${OBJECTDIR}/middleware/freertos/tasks.o.d ${OBJECTDIR}/middleware/freertos/timers.o.d ${OBJECTDIR}/sys/sys.o.d ${OBJECTDIR}/sys/sys_config.o.d ${OBJECTDIR}/sys/sys_trap.o.d ${OBJECTDIR}/sys/sys_debug.o.d ${OBJECTDIR}/sys/sys_common.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d ${OBJECTDIR}/middleware/wizio/freertos_common.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d ${OBJECTDIR}/app_driver.o.d ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d ${OBJECTDIR}/middleware/lwip/api/err.o.d ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d ${OBJECTDIR}/middleware/lwip/api/netdb.o.d ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d ${OBJECTDIR}/middleware/lwip/api/sockets.o.d ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d ${OBJECTDIR}/middleware/lwip/core/def.o.d ${OBJECTDIR}/middleware/lwip/core/dns.o.d ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d ${OBJECTDIR}/middleware/lwip/core/init.o.d ${OBJECTDIR}/middleware/lwip/core/ip.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d ${OBJECTDIR}/middleware/lwip/core/mem.o.d ${OBJECTDIR}/middleware/lwip/core/memp.o.d ${OBJECTDIR}/middleware/lwip/core/netif.o.d ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d ${OBJECTDIR}/middleware/lwip/core/raw.o.d ${OBJECTDIR}/middleware/lwip/core/stats.o.d ${OBJECTDIR}/middleware/lwip/core/sys.o.d ${OBJECTDIR}/middleware/lwip/core/tcp.o.d ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d ${OBJECTDIR}/middleware/lwip/core/udp.o.d ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d ${OBJECTDIR}/middleware/lwip/netif/slipif.o.d ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d ${OBJECTDIR}/app_lwip.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o ${OBJECTDIR}/middleware/freertos/croutine.o ${OBJECTDIR}/middleware/freertos/event_groups.o ${OBJECTDIR}/middleware/freertos/list.o ${OBJECTDIR}/middleware/freertos/queue.o ${OBJECTDIR}/middleware/freertos/stream_buffer.o ${OBJECTDIR}/middleware/freertos/tasks.o ${OBJECTDIR}/middleware/freertos/timers.o ${OBJECTDIR}/sys/sys.o ${OBJECTDIR}/sys/sys_config.o ${OBJECTDIR}/sys/sys_trap.o ${OBJECTDIR}/sys/sys_debug.o ${OBJECTDIR}/sys/sys_common.o ${OBJECTDIR}/main.o ${OBJECTDIR}/middleware/wizio/wrap_mem.o ${OBJECTDIR}/middleware/wizio/freertos_common.o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o ${OBJECTDIR}/drivers/mrf24wn/mrf.o ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o ${OBJECTDIR}/app_driver.o ${OBJECTDIR}/middleware/lwip/api/api_lib.o ${OBJECTDIR}/middleware/lwip/api/api_msg.o ${OBJECTDIR}/middleware/lwip/api/err.o ${OBJECTDIR}/middleware/lwip/api/netbuf.o ${OBJECTDIR}/middleware/lwip/api/netdb.o ${OBJECTDIR}/middleware/lwip/api/netifapi.o ${OBJECTDIR}/middleware/lwip/api/sockets.o ${OBJECTDIR}/middleware/lwip/api/tcpip.o ${OBJECTDIR}/middleware/lwip/core/def.o ${OBJECTDIR}/middleware/lwip/core/dns.o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o ${OBJECTDIR}/middleware/lwip/core/init.o ${OBJECTDIR}/middleware/lwip/core/ip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o ${OBJECTDIR}/middleware/lwip/core/mem.o ${OBJECTDIR}/middleware/lwip/core/memp.o ${OBJECTDIR}/middleware/lwip/core/netif.o ${OBJECTDIR}/middleware/lwip/core/pbuf.o ${OBJECTDIR}/middleware/lwip/core/raw.o ${OBJECTDIR}/middleware/lwip/core/stats.o ${OBJECTDIR}/middleware/lwip/core/sys.o ${OBJECTDIR}/middleware/lwip/core/tcp.o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o ${OBJECTDIR}/middleware/lwip/core/timeouts.o ${OBJECTDIR}/middleware/lwip/core/udp.o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o ${OBJECTDIR}/middleware/lwip/netif/slipif.o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o ${OBJECTDIR}/app_lwip.o

# Source Files
SOURCEFILES=middleware/freertos/portable/MemMang/umm_malloc.c middleware/freertos/portable/MPLAB/PIC32MZ/port.c middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S middleware/freertos/croutine.c middleware/freertos/event_groups.c middleware/freertos/list.c middleware/freertos/queue.c middleware/freertos/stream_buffer.c middleware/freertos/tasks.c middleware/freertos/timers.c sys/sys.c sys/sys_config.c sys/sys_trap.c sys/sys_debug.c sys/sys_common.c main.c middleware/wizio/wrap_mem.c middleware/wizio/freertos_common.c drivers/mrf24wn/mrf_hal.c drivers/mrf24wn/mrf_isr.S drivers/mrf24wn/mrf_lib.c drivers/mrf24wn/mrf_osal.c drivers/mrf24wn/mrf.c drivers/mrf24wn/mrf_netif.c app_driver.c middleware/lwip/api/api_lib.c middleware/lwip/api/api_msg.c middleware/lwip/api/err.c middleware/lwip/api/netbuf.c middleware/lwip/api/netdb.c middleware/lwip/api/netifapi.c middleware/lwip/api/sockets.c middleware/lwip/api/tcpip.c middleware/lwip/core/def.c middleware/lwip/core/dns.c middleware/lwip/core/inet_chksum.c middleware/lwip/core/init.c middleware/lwip/core/ip.c middleware/lwip/core/ipv4/autoip.c middleware/lwip/core/ipv4/dhcp.c middleware/lwip/core/ipv4/etharp.c middleware/lwip/core/ipv4/icmp.c middleware/lwip/core/ipv4/igmp.c middleware/lwip/core/ipv4/ip4.c middleware/lwip/core/ipv4/ip4_addr.c middleware/lwip/core/ipv4/ip4_frag.c middleware/lwip/core/ipv6/dhcp6.c middleware/lwip/core/ipv6/ethip6.c middleware/lwip/core/ipv6/icmp6.c middleware/lwip/core/ipv6/inet6.c middleware/lwip/core/ipv6/ip6.c middleware/lwip/core/ipv6/ip6_addr.c middleware/lwip/core/ipv6/ip6_frag.c middleware/lwip/core/ipv6/mld6.c middleware/lwip/core/ipv6/nd6.c middleware/lwip/core/mem.c middleware/lwip/core/memp.c middleware/lwip/core/netif.c middleware/lwip/core/pbuf.c middleware/lwip/core/raw.c middleware/lwip/core/stats.c middleware/lwip/core/sys.c middleware/lwip/core/tcp.c middleware/lwip/core/tcp_in.c middleware/lwip/core/tcp_out.c middleware/lwip/core/timeouts.c middleware/lwip/core/udp.c middleware/lwip/netif/ethernet.c middleware/lwip/netif/ethernetif.c middleware/lwip/netif/lowpan6.c middleware/lwip/netif/ppp/auth.c middleware/lwip/netif/ppp/ccp.c middleware/lwip/netif/ppp/chap-md5.c middleware/lwip/netif/ppp/chap-new.c middleware/lwip/netif/ppp/chap_ms.c middleware/lwip/netif/ppp/demand.c middleware/lwip/netif/ppp/eap.c middleware/lwip/netif/ppp/ecp.c middleware/lwip/netif/ppp/eui64.c middleware/lwip/netif/ppp/fsm.c middleware/lwip/netif/ppp/ipcp.c middleware/lwip/netif/ppp/ipv6cp.c middleware/lwip/netif/ppp/lcp.c middleware/lwip/netif/ppp/magic.c middleware/lwip/netif/ppp/mppe.c middleware/lwip/netif/ppp/multilink.c middleware/lwip/netif/ppp/polarssl/arc4.c middleware/lwip/netif/ppp/polarssl/des.c middleware/lwip/netif/ppp/polarssl/md4.c middleware/lwip/netif/ppp/polarssl/md5.c middleware/lwip/netif/ppp/polarssl/sha1.c middleware/lwip/netif/ppp/ppp.c middleware/lwip/netif/ppp/pppapi.c middleware/lwip/netif/ppp/pppcrypt.c middleware/lwip/netif/ppp/pppoe.c middleware/lwip/netif/ppp/pppol2tp.c middleware/lwip/netif/ppp/pppos.c middleware/lwip/netif/ppp/upap.c middleware/lwip/netif/ppp/utils.c middleware/lwip/netif/ppp/vj.c middleware/lwip/netif/slipif.c middleware/lwip/port/sys_arch.c app_lwip.c


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
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o: middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.ok ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d" "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d"  -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o: drivers/mrf24wn/mrf_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.ok ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d" "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d"  -o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o drivers/mrf24wn/mrf_isr.S  -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d",--defsym=__ICD2RAM=1,--defsym=__MPLAB_DEBUG=1,--gdwarf-2,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1
	
else
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o: middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.ok ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.err 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d" "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.d"  -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.S  -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port_asm.o.asm.d",--gdwarf-2
	
${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o: drivers/mrf24wn/mrf_isr.S  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.ok ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.err 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d" "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d" -t $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC} $(MP_EXTRA_AS_PRE)  -c -mprocessor=$(MP_PROCESSOR_OPTION) -I"middleware/freertos/include" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.d"  -o ${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o drivers/mrf24wn/mrf_isr.S  -DXPRJ_default=$(CND_CONF)  -legacy-libc  -Wa,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_AS_POST),-MD="${OBJECTDIR}/drivers/mrf24wn/mrf_isr.o.asm.d",--gdwarf-2
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o: middleware/freertos/portable/MemMang/umm_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MemMang" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o middleware/freertos/portable/MemMang/umm_malloc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o: middleware/freertos/portable/MPLAB/PIC32MZ/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o middleware/freertos/portable/MPLAB/PIC32MZ/port.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/croutine.o: middleware/freertos/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/croutine.o.d" -o ${OBJECTDIR}/middleware/freertos/croutine.o middleware/freertos/croutine.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/event_groups.o: middleware/freertos/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/event_groups.o.d" -o ${OBJECTDIR}/middleware/freertos/event_groups.o middleware/freertos/event_groups.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/list.o: middleware/freertos/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/list.o.d" -o ${OBJECTDIR}/middleware/freertos/list.o middleware/freertos/list.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/queue.o: middleware/freertos/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/queue.o.d" -o ${OBJECTDIR}/middleware/freertos/queue.o middleware/freertos/queue.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/stream_buffer.o: middleware/freertos/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" -o ${OBJECTDIR}/middleware/freertos/stream_buffer.o middleware/freertos/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/tasks.o: middleware/freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/tasks.o.d" -o ${OBJECTDIR}/middleware/freertos/tasks.o middleware/freertos/tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/timers.o: middleware/freertos/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/timers.o.d" -o ${OBJECTDIR}/middleware/freertos/timers.o middleware/freertos/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys.o: sys/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys.o.d 
	@${RM} ${OBJECTDIR}/sys/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys.o.d" -o ${OBJECTDIR}/sys/sys.o sys/sys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_config.o: sys/sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_config.o.d" -o ${OBJECTDIR}/sys/sys_config.o sys/sys_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_trap.o: sys/sys_trap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_trap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_trap.o.d" -o ${OBJECTDIR}/sys/sys_trap.o sys/sys_trap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_debug.o: sys/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_debug.o.d" -o ${OBJECTDIR}/sys/sys_debug.o sys/sys_debug.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_common.o: sys/sys_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_common.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_common.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_common.o.d" -o ${OBJECTDIR}/sys/sys_common.o sys/sys_common.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/wrap_mem.o: middleware/wizio/wrap_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" -o ${OBJECTDIR}/middleware/wizio/wrap_mem.o middleware/wizio/wrap_mem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/freertos_common.o: middleware/wizio/freertos_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" -o ${OBJECTDIR}/middleware/wizio/freertos_common.o middleware/wizio/freertos_common.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o: drivers/mrf24wn/mrf_hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o drivers/mrf24wn/mrf_hal.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o: drivers/mrf24wn/mrf_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o drivers/mrf24wn/mrf_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o: drivers/mrf24wn/mrf_osal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o drivers/mrf24wn/mrf_osal.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf.o: drivers/mrf24wn/mrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf.o drivers/mrf24wn/mrf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o: drivers/mrf24wn/mrf_netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o drivers/mrf24wn/mrf_netif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app_driver.o: app_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_driver.o.d 
	@${RM} ${OBJECTDIR}/app_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/app_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/app_driver.o.d" -o ${OBJECTDIR}/app_driver.o app_driver.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_lib.o: middleware/lwip/api/api_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_lib.o middleware/lwip/api/api_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_msg.o: middleware/lwip/api/api_msg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_msg.o middleware/lwip/api/api_msg.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/err.o: middleware/lwip/api/err.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/err.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/err.o.d" -o ${OBJECTDIR}/middleware/lwip/api/err.o middleware/lwip/api/err.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netbuf.o: middleware/lwip/api/netbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netbuf.o middleware/lwip/api/netbuf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netdb.o: middleware/lwip/api/netdb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netdb.o middleware/lwip/api/netdb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netifapi.o: middleware/lwip/api/netifapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netifapi.o middleware/lwip/api/netifapi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/sockets.o: middleware/lwip/api/sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" -o ${OBJECTDIR}/middleware/lwip/api/sockets.o middleware/lwip/api/sockets.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/tcpip.o: middleware/lwip/api/tcpip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" -o ${OBJECTDIR}/middleware/lwip/api/tcpip.o middleware/lwip/api/tcpip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/def.o: middleware/lwip/core/def.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/def.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/def.o.d" -o ${OBJECTDIR}/middleware/lwip/core/def.o middleware/lwip/core/def.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/dns.o: middleware/lwip/core/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/dns.o.d" -o ${OBJECTDIR}/middleware/lwip/core/dns.o middleware/lwip/core/dns.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/inet_chksum.o: middleware/lwip/core/inet_chksum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" -o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o middleware/lwip/core/inet_chksum.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/init.o: middleware/lwip/core/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/init.o.d" -o ${OBJECTDIR}/middleware/lwip/core/init.o middleware/lwip/core/init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ip.o: middleware/lwip/core/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ip.o middleware/lwip/core/ip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o: middleware/lwip/core/ipv4/autoip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o middleware/lwip/core/ipv4/autoip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o: middleware/lwip/core/ipv4/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o middleware/lwip/core/ipv4/dhcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o: middleware/lwip/core/ipv4/etharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o middleware/lwip/core/ipv4/etharp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o: middleware/lwip/core/ipv4/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o middleware/lwip/core/ipv4/icmp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o: middleware/lwip/core/ipv4/igmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o middleware/lwip/core/ipv4/igmp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o: middleware/lwip/core/ipv4/ip4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o middleware/lwip/core/ipv4/ip4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o: middleware/lwip/core/ipv4/ip4_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o middleware/lwip/core/ipv4/ip4_addr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o: middleware/lwip/core/ipv4/ip4_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o middleware/lwip/core/ipv4/ip4_frag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o: middleware/lwip/core/ipv6/dhcp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o middleware/lwip/core/ipv6/dhcp6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o: middleware/lwip/core/ipv6/ethip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o middleware/lwip/core/ipv6/ethip6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o: middleware/lwip/core/ipv6/icmp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o middleware/lwip/core/ipv6/icmp6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o: middleware/lwip/core/ipv6/inet6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o middleware/lwip/core/ipv6/inet6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o: middleware/lwip/core/ipv6/ip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o middleware/lwip/core/ipv6/ip6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o: middleware/lwip/core/ipv6/ip6_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o middleware/lwip/core/ipv6/ip6_addr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o: middleware/lwip/core/ipv6/ip6_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o middleware/lwip/core/ipv6/ip6_frag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o: middleware/lwip/core/ipv6/mld6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o middleware/lwip/core/ipv6/mld6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o: middleware/lwip/core/ipv6/nd6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o middleware/lwip/core/ipv6/nd6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/mem.o: middleware/lwip/core/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/mem.o.d" -o ${OBJECTDIR}/middleware/lwip/core/mem.o middleware/lwip/core/mem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/memp.o: middleware/lwip/core/memp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/memp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/memp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/memp.o middleware/lwip/core/memp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/netif.o: middleware/lwip/core/netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/netif.o.d" -o ${OBJECTDIR}/middleware/lwip/core/netif.o middleware/lwip/core/netif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/pbuf.o: middleware/lwip/core/pbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/core/pbuf.o middleware/lwip/core/pbuf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/raw.o: middleware/lwip/core/raw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/raw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/raw.o.d" -o ${OBJECTDIR}/middleware/lwip/core/raw.o middleware/lwip/core/raw.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/stats.o: middleware/lwip/core/stats.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/stats.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/stats.o.d" -o ${OBJECTDIR}/middleware/lwip/core/stats.o middleware/lwip/core/stats.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/sys.o: middleware/lwip/core/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/sys.o.d" -o ${OBJECTDIR}/middleware/lwip/core/sys.o middleware/lwip/core/sys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp.o: middleware/lwip/core/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp.o middleware/lwip/core/tcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_in.o: middleware/lwip/core/tcp_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o middleware/lwip/core/tcp_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_out.o: middleware/lwip/core/tcp_out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o middleware/lwip/core/tcp_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/timeouts.o: middleware/lwip/core/timeouts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" -o ${OBJECTDIR}/middleware/lwip/core/timeouts.o middleware/lwip/core/timeouts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/udp.o: middleware/lwip/core/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/udp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/udp.o middleware/lwip/core/udp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernet.o: middleware/lwip/netif/ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o middleware/lwip/netif/ethernet.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernetif.o: middleware/lwip/netif/ethernetif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o middleware/lwip/netif/ethernetif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/lowpan6.o: middleware/lwip/netif/lowpan6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o middleware/lwip/netif/lowpan6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o: middleware/lwip/netif/ppp/auth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o middleware/lwip/netif/ppp/auth.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o: middleware/lwip/netif/ppp/ccp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o middleware/lwip/netif/ppp/ccp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o: middleware/lwip/netif/ppp/chap-md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o middleware/lwip/netif/ppp/chap-md5.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o: middleware/lwip/netif/ppp/chap-new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o middleware/lwip/netif/ppp/chap-new.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o: middleware/lwip/netif/ppp/chap_ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o middleware/lwip/netif/ppp/chap_ms.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o: middleware/lwip/netif/ppp/demand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o middleware/lwip/netif/ppp/demand.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o: middleware/lwip/netif/ppp/eap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o middleware/lwip/netif/ppp/eap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o: middleware/lwip/netif/ppp/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o middleware/lwip/netif/ppp/ecp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o: middleware/lwip/netif/ppp/eui64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o middleware/lwip/netif/ppp/eui64.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o: middleware/lwip/netif/ppp/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o middleware/lwip/netif/ppp/fsm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o: middleware/lwip/netif/ppp/ipcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o middleware/lwip/netif/ppp/ipcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o: middleware/lwip/netif/ppp/ipv6cp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o middleware/lwip/netif/ppp/ipv6cp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o: middleware/lwip/netif/ppp/lcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o middleware/lwip/netif/ppp/lcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o: middleware/lwip/netif/ppp/magic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o middleware/lwip/netif/ppp/magic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o: middleware/lwip/netif/ppp/mppe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o middleware/lwip/netif/ppp/mppe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o: middleware/lwip/netif/ppp/multilink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o middleware/lwip/netif/ppp/multilink.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o: middleware/lwip/netif/ppp/polarssl/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o middleware/lwip/netif/ppp/polarssl/arc4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o: middleware/lwip/netif/ppp/polarssl/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o middleware/lwip/netif/ppp/polarssl/des.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o: middleware/lwip/netif/ppp/polarssl/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o middleware/lwip/netif/ppp/polarssl/md4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o: middleware/lwip/netif/ppp/polarssl/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o middleware/lwip/netif/ppp/polarssl/md5.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o: middleware/lwip/netif/ppp/polarssl/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o middleware/lwip/netif/ppp/polarssl/sha1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o: middleware/lwip/netif/ppp/ppp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o middleware/lwip/netif/ppp/ppp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o: middleware/lwip/netif/ppp/pppapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o middleware/lwip/netif/ppp/pppapi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o: middleware/lwip/netif/ppp/pppcrypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o middleware/lwip/netif/ppp/pppcrypt.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o: middleware/lwip/netif/ppp/pppoe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o middleware/lwip/netif/ppp/pppoe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o: middleware/lwip/netif/ppp/pppol2tp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o middleware/lwip/netif/ppp/pppol2tp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o: middleware/lwip/netif/ppp/pppos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o middleware/lwip/netif/ppp/pppos.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o: middleware/lwip/netif/ppp/upap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o middleware/lwip/netif/ppp/upap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o: middleware/lwip/netif/ppp/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o middleware/lwip/netif/ppp/utils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o: middleware/lwip/netif/ppp/vj.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o middleware/lwip/netif/ppp/vj.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/slipif.o: middleware/lwip/netif/slipif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/slipif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/slipif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/slipif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/slipif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/slipif.o middleware/lwip/netif/slipif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/port/sys_arch.o: middleware/lwip/port/sys_arch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/port" 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" -o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o middleware/lwip/port/sys_arch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app_lwip.o: app_lwip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_lwip.o.d 
	@${RM} ${OBJECTDIR}/app_lwip.o 
	@${FIXDEPS} "${OBJECTDIR}/app_lwip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/app_lwip.o.d" -o ${OBJECTDIR}/app_lwip.o app_lwip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
else
${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o: middleware/freertos/portable/MemMang/umm_malloc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MemMang" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MemMang/umm_malloc.o middleware/freertos/portable/MemMang/umm_malloc.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o: middleware/freertos/portable/MPLAB/PIC32MZ/port.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ" 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o.d" -o ${OBJECTDIR}/middleware/freertos/portable/MPLAB/PIC32MZ/port.o middleware/freertos/portable/MPLAB/PIC32MZ/port.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/croutine.o: middleware/freertos/croutine.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/croutine.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/croutine.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/croutine.o.d" -o ${OBJECTDIR}/middleware/freertos/croutine.o middleware/freertos/croutine.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/event_groups.o: middleware/freertos/event_groups.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/event_groups.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/event_groups.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/event_groups.o.d" -o ${OBJECTDIR}/middleware/freertos/event_groups.o middleware/freertos/event_groups.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/list.o: middleware/freertos/list.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/list.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/list.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/list.o.d" -o ${OBJECTDIR}/middleware/freertos/list.o middleware/freertos/list.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/queue.o: middleware/freertos/queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/queue.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/queue.o.d" -o ${OBJECTDIR}/middleware/freertos/queue.o middleware/freertos/queue.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/stream_buffer.o: middleware/freertos/stream_buffer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/stream_buffer.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/stream_buffer.o.d" -o ${OBJECTDIR}/middleware/freertos/stream_buffer.o middleware/freertos/stream_buffer.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/tasks.o: middleware/freertos/tasks.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/tasks.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/tasks.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/tasks.o.d" -o ${OBJECTDIR}/middleware/freertos/tasks.o middleware/freertos/tasks.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/freertos/timers.o: middleware/freertos/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/freertos" 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o.d 
	@${RM} ${OBJECTDIR}/middleware/freertos/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/freertos/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/freertos/timers.o.d" -o ${OBJECTDIR}/middleware/freertos/timers.o middleware/freertos/timers.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys.o: sys/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys.o.d 
	@${RM} ${OBJECTDIR}/sys/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys.o.d" -o ${OBJECTDIR}/sys/sys.o sys/sys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_config.o: sys/sys_config.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_config.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_config.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_config.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_config.o.d" -o ${OBJECTDIR}/sys/sys_config.o sys/sys_config.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_trap.o: sys/sys_trap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_trap.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_trap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_trap.o.d" -o ${OBJECTDIR}/sys/sys_trap.o sys/sys_trap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_debug.o: sys/sys_debug.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_debug.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_debug.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_debug.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_debug.o.d" -o ${OBJECTDIR}/sys/sys_debug.o sys/sys_debug.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/sys/sys_common.o: sys/sys_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/sys" 
	@${RM} ${OBJECTDIR}/sys/sys_common.o.d 
	@${RM} ${OBJECTDIR}/sys/sys_common.o 
	@${FIXDEPS} "${OBJECTDIR}/sys/sys_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/sys/sys_common.o.d" -o ${OBJECTDIR}/sys/sys_common.o sys/sys_common.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/wrap_mem.o: middleware/wizio/wrap_mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/wrap_mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/wizio/wrap_mem.o.d" -o ${OBJECTDIR}/middleware/wizio/wrap_mem.o middleware/wizio/wrap_mem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/wizio/freertos_common.o: middleware/wizio/freertos_common.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/wizio" 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o.d 
	@${RM} ${OBJECTDIR}/middleware/wizio/freertos_common.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/wizio/freertos_common.o.d" -o ${OBJECTDIR}/middleware/wizio/freertos_common.o middleware/wizio/freertos_common.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o: drivers/mrf24wn/mrf_hal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_hal.o drivers/mrf24wn/mrf_hal.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o: drivers/mrf24wn/mrf_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_lib.o drivers/mrf24wn/mrf_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o: drivers/mrf24wn/mrf_osal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_osal.o drivers/mrf24wn/mrf_osal.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf.o: drivers/mrf24wn/mrf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf.o drivers/mrf24wn/mrf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o: drivers/mrf24wn/mrf_netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/drivers/mrf24wn" 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d 
	@${RM} ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o 
	@${FIXDEPS} "${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o.d" -o ${OBJECTDIR}/drivers/mrf24wn/mrf_netif.o drivers/mrf24wn/mrf_netif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app_driver.o: app_driver.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_driver.o.d 
	@${RM} ${OBJECTDIR}/app_driver.o 
	@${FIXDEPS} "${OBJECTDIR}/app_driver.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/app_driver.o.d" -o ${OBJECTDIR}/app_driver.o app_driver.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_lib.o: middleware/lwip/api/api_lib.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_lib.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_lib.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_lib.o middleware/lwip/api/api_lib.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/api_msg.o: middleware/lwip/api/api_msg.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/api_msg.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/api_msg.o.d" -o ${OBJECTDIR}/middleware/lwip/api/api_msg.o middleware/lwip/api/api_msg.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/err.o: middleware/lwip/api/err.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/err.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/err.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/err.o.d" -o ${OBJECTDIR}/middleware/lwip/api/err.o middleware/lwip/api/err.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netbuf.o: middleware/lwip/api/netbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netbuf.o middleware/lwip/api/netbuf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netdb.o: middleware/lwip/api/netdb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netdb.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netdb.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netdb.o middleware/lwip/api/netdb.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/netifapi.o: middleware/lwip/api/netifapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/netifapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/netifapi.o.d" -o ${OBJECTDIR}/middleware/lwip/api/netifapi.o middleware/lwip/api/netifapi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/sockets.o: middleware/lwip/api/sockets.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/sockets.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/sockets.o.d" -o ${OBJECTDIR}/middleware/lwip/api/sockets.o middleware/lwip/api/sockets.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/api/tcpip.o: middleware/lwip/api/tcpip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/api" 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/api/tcpip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/api/tcpip.o.d" -o ${OBJECTDIR}/middleware/lwip/api/tcpip.o middleware/lwip/api/tcpip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/def.o: middleware/lwip/core/def.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/def.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/def.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/def.o.d" -o ${OBJECTDIR}/middleware/lwip/core/def.o middleware/lwip/core/def.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/dns.o: middleware/lwip/core/dns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/dns.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/dns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/dns.o.d" -o ${OBJECTDIR}/middleware/lwip/core/dns.o middleware/lwip/core/dns.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/inet_chksum.o: middleware/lwip/core/inet_chksum.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/inet_chksum.o.d" -o ${OBJECTDIR}/middleware/lwip/core/inet_chksum.o middleware/lwip/core/inet_chksum.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/init.o: middleware/lwip/core/init.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/init.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/init.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/init.o.d" -o ${OBJECTDIR}/middleware/lwip/core/init.o middleware/lwip/core/init.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ip.o: middleware/lwip/core/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ip.o middleware/lwip/core/ip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o: middleware/lwip/core/ipv4/autoip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/autoip.o middleware/lwip/core/ipv4/autoip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o: middleware/lwip/core/ipv4/dhcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/dhcp.o middleware/lwip/core/ipv4/dhcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o: middleware/lwip/core/ipv4/etharp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/etharp.o middleware/lwip/core/ipv4/etharp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o: middleware/lwip/core/ipv4/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/icmp.o middleware/lwip/core/ipv4/icmp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o: middleware/lwip/core/ipv4/igmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/igmp.o middleware/lwip/core/ipv4/igmp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o: middleware/lwip/core/ipv4/ip4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4.o middleware/lwip/core/ipv4/ip4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o: middleware/lwip/core/ipv4/ip4_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_addr.o middleware/lwip/core/ipv4/ip4_addr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o: middleware/lwip/core/ipv4/ip4_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv4" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv4/ip4_frag.o middleware/lwip/core/ipv4/ip4_frag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o: middleware/lwip/core/ipv6/dhcp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/dhcp6.o middleware/lwip/core/ipv6/dhcp6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o: middleware/lwip/core/ipv6/ethip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ethip6.o middleware/lwip/core/ipv6/ethip6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o: middleware/lwip/core/ipv6/icmp6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/icmp6.o middleware/lwip/core/ipv6/icmp6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o: middleware/lwip/core/ipv6/inet6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/inet6.o middleware/lwip/core/ipv6/inet6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o: middleware/lwip/core/ipv6/ip6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6.o middleware/lwip/core/ipv6/ip6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o: middleware/lwip/core/ipv6/ip6_addr.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_addr.o middleware/lwip/core/ipv6/ip6_addr.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o: middleware/lwip/core/ipv6/ip6_frag.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/ip6_frag.o middleware/lwip/core/ipv6/ip6_frag.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o: middleware/lwip/core/ipv6/mld6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/mld6.o middleware/lwip/core/ipv6/mld6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o: middleware/lwip/core/ipv6/nd6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core/ipv6" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o.d" -o ${OBJECTDIR}/middleware/lwip/core/ipv6/nd6.o middleware/lwip/core/ipv6/nd6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/mem.o: middleware/lwip/core/mem.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/mem.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/mem.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/mem.o.d" -o ${OBJECTDIR}/middleware/lwip/core/mem.o middleware/lwip/core/mem.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/memp.o: middleware/lwip/core/memp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/memp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/memp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/memp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/memp.o middleware/lwip/core/memp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/netif.o: middleware/lwip/core/netif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/netif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/netif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/netif.o.d" -o ${OBJECTDIR}/middleware/lwip/core/netif.o middleware/lwip/core/netif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/pbuf.o: middleware/lwip/core/pbuf.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/pbuf.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/pbuf.o.d" -o ${OBJECTDIR}/middleware/lwip/core/pbuf.o middleware/lwip/core/pbuf.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/raw.o: middleware/lwip/core/raw.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/raw.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/raw.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/raw.o.d" -o ${OBJECTDIR}/middleware/lwip/core/raw.o middleware/lwip/core/raw.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/stats.o: middleware/lwip/core/stats.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/stats.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/stats.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/stats.o.d" -o ${OBJECTDIR}/middleware/lwip/core/stats.o middleware/lwip/core/stats.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/sys.o: middleware/lwip/core/sys.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/sys.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/sys.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/sys.o.d" -o ${OBJECTDIR}/middleware/lwip/core/sys.o middleware/lwip/core/sys.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp.o: middleware/lwip/core/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp.o middleware/lwip/core/tcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_in.o: middleware/lwip/core/tcp_in.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_in.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_in.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_in.o middleware/lwip/core/tcp_in.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/tcp_out.o: middleware/lwip/core/tcp_out.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/tcp_out.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/tcp_out.o.d" -o ${OBJECTDIR}/middleware/lwip/core/tcp_out.o middleware/lwip/core/tcp_out.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/timeouts.o: middleware/lwip/core/timeouts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/timeouts.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/timeouts.o.d" -o ${OBJECTDIR}/middleware/lwip/core/timeouts.o middleware/lwip/core/timeouts.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/core/udp.o: middleware/lwip/core/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/core" 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/core/udp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/core/udp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/core/udp.o.d" -o ${OBJECTDIR}/middleware/lwip/core/udp.o middleware/lwip/core/udp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernet.o: middleware/lwip/netif/ethernet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernet.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernet.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernet.o middleware/lwip/netif/ethernet.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ethernetif.o: middleware/lwip/netif/ethernetif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ethernetif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ethernetif.o middleware/lwip/netif/ethernetif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/lowpan6.o: middleware/lwip/netif/lowpan6.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/lowpan6.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/lowpan6.o middleware/lwip/netif/lowpan6.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o: middleware/lwip/netif/ppp/auth.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/auth.o middleware/lwip/netif/ppp/auth.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o: middleware/lwip/netif/ppp/ccp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ccp.o middleware/lwip/netif/ppp/ccp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o: middleware/lwip/netif/ppp/chap-md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-md5.o middleware/lwip/netif/ppp/chap-md5.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o: middleware/lwip/netif/ppp/chap-new.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap-new.o middleware/lwip/netif/ppp/chap-new.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o: middleware/lwip/netif/ppp/chap_ms.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/chap_ms.o middleware/lwip/netif/ppp/chap_ms.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o: middleware/lwip/netif/ppp/demand.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/demand.o middleware/lwip/netif/ppp/demand.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o: middleware/lwip/netif/ppp/eap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eap.o middleware/lwip/netif/ppp/eap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o: middleware/lwip/netif/ppp/ecp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ecp.o middleware/lwip/netif/ppp/ecp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o: middleware/lwip/netif/ppp/eui64.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/eui64.o middleware/lwip/netif/ppp/eui64.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o: middleware/lwip/netif/ppp/fsm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/fsm.o middleware/lwip/netif/ppp/fsm.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o: middleware/lwip/netif/ppp/ipcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipcp.o middleware/lwip/netif/ppp/ipcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o: middleware/lwip/netif/ppp/ipv6cp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ipv6cp.o middleware/lwip/netif/ppp/ipv6cp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o: middleware/lwip/netif/ppp/lcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/lcp.o middleware/lwip/netif/ppp/lcp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o: middleware/lwip/netif/ppp/magic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/magic.o middleware/lwip/netif/ppp/magic.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o: middleware/lwip/netif/ppp/mppe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/mppe.o middleware/lwip/netif/ppp/mppe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o: middleware/lwip/netif/ppp/multilink.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/multilink.o middleware/lwip/netif/ppp/multilink.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o: middleware/lwip/netif/ppp/polarssl/arc4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/arc4.o middleware/lwip/netif/ppp/polarssl/arc4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o: middleware/lwip/netif/ppp/polarssl/des.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/des.o middleware/lwip/netif/ppp/polarssl/des.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o: middleware/lwip/netif/ppp/polarssl/md4.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md4.o middleware/lwip/netif/ppp/polarssl/md4.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o: middleware/lwip/netif/ppp/polarssl/md5.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/md5.o middleware/lwip/netif/ppp/polarssl/md5.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o: middleware/lwip/netif/ppp/polarssl/sha1.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/polarssl/sha1.o middleware/lwip/netif/ppp/polarssl/sha1.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o: middleware/lwip/netif/ppp/ppp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/ppp.o middleware/lwip/netif/ppp/ppp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o: middleware/lwip/netif/ppp/pppapi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppapi.o middleware/lwip/netif/ppp/pppapi.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o: middleware/lwip/netif/ppp/pppcrypt.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppcrypt.o middleware/lwip/netif/ppp/pppcrypt.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o: middleware/lwip/netif/ppp/pppoe.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppoe.o middleware/lwip/netif/ppp/pppoe.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o: middleware/lwip/netif/ppp/pppol2tp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppol2tp.o middleware/lwip/netif/ppp/pppol2tp.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o: middleware/lwip/netif/ppp/pppos.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/pppos.o middleware/lwip/netif/ppp/pppos.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o: middleware/lwip/netif/ppp/upap.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/upap.o middleware/lwip/netif/ppp/upap.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o: middleware/lwip/netif/ppp/utils.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/utils.o middleware/lwip/netif/ppp/utils.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o: middleware/lwip/netif/ppp/vj.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif/ppp" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/ppp/vj.o middleware/lwip/netif/ppp/vj.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/netif/slipif.o: middleware/lwip/netif/slipif.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/netif" 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/slipif.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/netif/slipif.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/netif/slipif.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/netif/slipif.o.d" -o ${OBJECTDIR}/middleware/lwip/netif/slipif.o middleware/lwip/netif/slipif.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/middleware/lwip/port/sys_arch.o: middleware/lwip/port/sys_arch.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/middleware/lwip/port" 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d 
	@${RM} ${OBJECTDIR}/middleware/lwip/port/sys_arch.o 
	@${FIXDEPS} "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/middleware/lwip/port/sys_arch.o.d" -o ${OBJECTDIR}/middleware/lwip/port/sys_arch.o middleware/lwip/port/sys_arch.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
${OBJECTDIR}/app_lwip.o: app_lwip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_lwip.o.d 
	@${RM} ${OBJECTDIR}/app_lwip.o 
	@${FIXDEPS} "${OBJECTDIR}/app_lwip.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"sys" -I"middleware/freertos/include" -I"middleware/freertos/portable/MemMang" -I"middleware/freertos/portable/MPLAB/PIC32MZ" -I"middleware/wizio" -I"drivers/mrf24wn" -I"middleware/lwip/include" -I"middleware/lwip/port/include" -MMD -MF "${OBJECTDIR}/app_lwip.o.d" -o ${OBJECTDIR}/app_lwip.o app_lwip.c    -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD) 
	
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
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    drivers\mrf24wn\wdrvext_mz_ef.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x0:0x37F   -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--wrap,malloc,--wrap,free
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  drivers/mrf24wn/wdrvext_mz_ef.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/WizIO32.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}    drivers\mrf24wn\wdrvext_mz_ef.a      -DXPRJ_default=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=_min_heap_size=1024,--gc-sections,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml,--wrap,malloc,--wrap,free
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
