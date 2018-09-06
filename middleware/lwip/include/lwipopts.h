#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#include "FreeRTOSConfig.h"

#define NO_SYS                          0

#define TCPIP_THREAD_PRIO               TASK_PRIORITY_HIGH
#define TCPIP_THREAD_NAME              "TCPIP"
#define TCPIP_THREAD_STACKSIZE          (10*1024u)

#define TCPIP_MBOX_SIZE                 16
#define DEFAULT_RAW_RECVMBOX_SIZE       16
#define DEFAULT_UDP_RECVMBOX_SIZE       16
#define DEFAULT_TCP_RECVMBOX_SIZE       16
#define DEFAULT_ACCEPTMBOX_SIZE         16

#define LWIP_RAW                        1 /* for ping */

//fix http IOT issue
#define LWIP_WND_SCALE                  1
#define TCP_RCV_SCALE                   1
#define MEMP_NUM_NETDB                  4

//fix reuse address issue
#define SO_REUSE                        1
#define LWIP_SO_RCVTIMEO                1
//for ip display
#define LWIP_NETIF_STATUS_CALLBACK      1

#define ETH_PAD_SIZE                    0

#define LWIP_CALLBACK_API               1

/*
   ------------------------------------
   ---------- Memory options ----------
   ------------------------------------
*/
/* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
   byte alignment -> define MEM_ALIGNMENT to 2. */
#define MEM_ALIGNMENT           4

/**
* MEMP_MEM_MALLOC==1: Use mem_malloc/mem_free instead of the lwip pool allocator.
* Especially useful with MEM_LIBC_MALLOC but handle with care regarding execution
* speed and usage from interrupts!
*/
#define MEMP_MEM_MALLOC         1


/* MEM_SIZE: the size of the heap memory. If the application will send
a lot of data that needs to be copied, this should be set high. */
#define MEM_SIZE                (16 * 1024)

/**
 * SYS_LIGHTWEIGHT_PROT==1: if you want inter-task protection for certain
 * critical regions during buffer allocation, deallocation and memory
 * allocation and deallocation.
 */
#define SYS_LIGHTWEIGHT_PROT            1

/*
   ------------------------------------------------
   ---------- Internal Memory Pool Sizes ----------
   ------------------------------------------------
*/

/* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
   sends a lot of data out of ROM (or other static memory), this
   should be set high. */
#define MEMP_NUM_PBUF           8
/* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
   per active UDP "connection". */
#define MEMP_NUM_UDP_PCB        4
/* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
   connections. */
#define MEMP_NUM_TCP_PCB        8
/* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
   connections. */
#define MEMP_NUM_TCP_PCB_LISTEN 16
/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. */
#define MEMP_NUM_TCP_SEG        255

/**
 * MEMP_NUM_ARP_QUEUE: the number of simulateously queued outgoing
 * packets (pbufs) that are waiting for an ARP request (to resolve
 * their destination address) to finish.
 * (requires the ARP_QUEUEING option)
 */
#define MEMP_NUM_ARP_QUEUE      8

/**
 * MEMP_NUM_NETCONN: the number of struct netconns.
 * (only needed if you use the sequential API, like api_lib.c)
 * NUM_SOCKETS
 */
#define MEMP_NUM_NETCONN        8

/*
   ----------------------------------
   ---------- Pbuf options ----------
   ----------------------------------
*/
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE          10

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE       1664

/**
 * PBUF_LINK_HLEN: the number of bytes that should be allocated for a
 * link level header. The default is 14, the standard value for
 * Ethernet.
 */
#define RESERVED_HLEN            0    //depend on CFG_CONNSYS_TXD_PAD_SIZE
#define PBUF_LINK_ENCAPSULATION_HLEN 2 // for WiFi headroom (TX zero copy)
#define PBUF_LINK_HLEN           (RESERVED_HLEN + 14 + ETH_PAD_SIZE)
/*
   ---------------------------------
   ---------- TCP options ----------
   ---------------------------------
*/
#define LWIP_TCP                1
#define TCP_TTL                 255

/* Controls if TCP should queue segments that arrive out of
   order. Define to 0 if your device is low on memory. */
#define TCP_QUEUE_OOSEQ         1

/* TCP Maximum segment size. */
#define TCP_MSS                 1476/*1476*/
//#define TCP_OVERSIZE            0

/* TCP sender buffer space (bytes). */
#define TCP_SND_BUF             (12 * 1024)

/* TCP sender buffer space (pbufs). This must be at least = 2 *
   TCP_SND_BUF/TCP_MSS for things to work. */
#define TCP_SND_QUEUELEN        ((4 * (TCP_SND_BUF) + (TCP_MSS - 1))/(TCP_MSS))

/* TCP receive window. */
#define TCP_WND                 (24 * 1024)

/* Maximum number of retransmissions of data segments. */
#define TCP_MAXRTX              12

/* Maximum number of retransmissions of SYN segments. */
#define TCP_SYNMAXRTX           4

#define LWIP_RANDOMIZE_INITIAL_LOCAL_PORTS 1

/*
   ---------------------------------
   ---------- ARP options ----------
   ---------------------------------
*/
#define LWIP_ARP        1
#define ARP_TABLE_SIZE  10
#define ARP_QUEUEING    1

/* ---------- IP options ---------- */
/* Define IP_FORWARD to 1 if you wish to have the ability to forward
   IP packets across network interfaces. If you are going to run lwIP
   on a device with only one network interface, define this to 0. */
#define IP_FORWARD              0

/* If defined to 1, IP options are allowed (but not parsed). If
   defined to 0, all packets with IP options are dropped. */
#define IP_OPTIONS              1

#define IP_REASSEMBLY           1

/**
 * IP_REASS_MAX_PBUFS: Total maximum amount of pbufs waiting to be reassembled.
 * Since the received pbufs are enqueued, be sure to configure
 * PBUF_POOL_SIZE > IP_REASS_MAX_PBUFS so that the stack is still able to receive
 * packets even if the maximum amount of fragments is enqueued for reassembly!
 */
#define IP_REASS_MAX_PBUFS      10
/* ---------- ICMP options ---------- */
#define ICMP_TTL                255


/* ---------- DHCP options ---------- */
/* Define LWIP_DHCP to 1 if you want DHCP configuration of
   interfaces. DHCP is not implemented in lwIP 0.5.1, however, so
   turning this on does currently not work. */
#define LWIP_DHCP                       1
#define LWIP_DHCP_CHECK_LINK_UP         1
/* 1 if you want to do an ARP check on the offered address (recommended). */
#define DHCP_DOES_ARP_CHECK             0

/* ---------- UDP options ---------- */
#define LWIP_UDP                1
#define UDP_TTL                 255

/*
   ------------------------------------
   ---------- AUTOIP options ----------
   ------------------------------------
*/
//#define LWIP_AUTOIP            1
//#define LWIP_DHCP_AUTOIP_COOP  1

/*
   ----------------------------------
   ---------- DNS options -----------
   ----------------------------------
*/
#define LWIP_DNS               1

/*
   ---------------------------------
   ---------- PPP options ----------
   ---------------------------------
*/
#define PPP_SUPPORT            0


/*
   ------------------------------------------------
   ---------- Network Interfaces options ----------
   ------------------------------------------------
*/

/**
 * LWIP_NETIF_LOOPBACK==1: Support sending packets with a destination IP
 * address equal to the netif IP address, looping them back up the stack.
 */
#define LWIP_NETIF_LOOPBACK             1


/**
 * LWIP_LOOPBACK_MAX_PBUFS: Maximum number of pbufs on queue for loopback
 * sending for each netif (0 = disabled)
 */
#define LWIP_LOOPBACK_MAX_PBUFS         12


/*
   ------------------------------------
   ---------- LOOPIF options ----------
   ------------------------------------
*/
/**
 * LWIP_HAVE_LOOPIF==1: Support loop interface (127.0.0.1) and loopif.c
 */
#define LWIP_HAVE_LOOPIF                1


#define MEM_LIBC_MALLOC                 1
#define LWIP_TIMEVAL_PRIVATE            0 /* <sys/time.h> in cc.h */ 
#define LWIP_PROVIDE_ERRNO              1 /* 1 for Legacy Libs OFF */


#define LWIP_DEBUG                      1                

#undef LWIP_DBG_MIN_LEVEL
#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_ALL

#undef ETHARP_DEBUG
#undef NETIF_DEBUG
#undef PBUF_DEBUG
#undef API_LIB_DEBUG
#undef API_MSG_DEBUG
#undef SOCKETS_DEBUG
#undef ICMP_DEBUG
#undef IGMP_DEBUG
#undef INET_DEBUG
#undef IP_DEBUG
#undef IP6_DEBUG
#undef IP_REASS_DEBUG
#undef RAW_DEBUG
#undef MEM_DEBUG
#undef MEMP_DEBUG
#undef SYS_DEBUG
#undef TIMERS_DEBUG
#undef TCP_DEBUG
#undef TCP_INPUT_DEBUG
#undef TCP_FR_DEBUG
#undef TCP_RTO_DEBUG
#undef TCP_CWND_DEBUG
#undef TCP_WND_DEBUG
#undef TCP_OUTPUT_DEBUG
#undef TCP_RST_DEBUG
#undef TCP_QLEN_DEBUG
#undef UDP_DEBUG
#undef TCPIP_DEBUG
#undef PPP_DEBUG
#undef SLIP_DEBUG
#undef DHCP_DEBUG
#undef AUTOIP_DEBUG
#undef SNMP_MSG_DEBUG
#undef SNMP_MIB_DEBUG
#undef DNS_DEBUG

#define ETHARP_DEBUG                    LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_OFF
#define PBUF_DEBUG                      LWIP_DBG_OFF
#define API_LIB_DEBUG                   LWIP_DBG_OFF
#define API_MSG_DEBUG                   LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
#define ICMP_DEBUG                      LWIP_DBG_OFF
#define IGMP_DEBUG                      LWIP_DBG_OFF
#define INET_DEBUG                      LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define IP6_DEBUG                       LWIP_DBG_OFF
#define IP_REASS_DEBUG                  LWIP_DBG_OFF
#define RAW_DEBUG                       LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
#define SYS_DEBUG                       LWIP_DBG_OFF
#define TIMERS_DEBUG                    LWIP_DBG_OFF
#define TCP_DEBUG                       LWIP_DBG_OFF
#define TCP_INPUT_DEBUG                 LWIP_DBG_OFF
#define TCP_FR_DEBUG                    LWIP_DBG_OFF
#define TCP_RTO_DEBUG                   LWIP_DBG_OFF
#define TCP_CWND_DEBUG                  LWIP_DBG_OFF
#define TCP_WND_DEBUG                   LWIP_DBG_OFF
#define TCP_OUTPUT_DEBUG                LWIP_DBG_OFF
#define TCP_RST_DEBUG                   LWIP_DBG_OFF
#define TCP_QLEN_DEBUG                  LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define TCPIP_DEBUG                     LWIP_DBG_OFF
#define PPP_DEBUG                       LWIP_DBG_OFF
#define SLIP_DEBUG                      LWIP_DBG_OFF
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define AUTOIP_DEBUG                    LWIP_DBG_OFF
#define SNMP_MSG_DEBUG                  LWIP_DBG_OFF
#define SNMP_MIB_DEBUG                  LWIP_DBG_OFF
#define DNS_DEBUG                       LWIP_DBG_OFF

#endif /* __LWIPOPTS_H__ */
