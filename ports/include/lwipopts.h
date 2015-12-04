/**
 * \file lwipopts.h - Configuration options for lwIP
 *
 * Copyright (c) 2010 Texas Instruments Incorporated
 */
/*
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 * Author: Adam Dunkels <adam@sics.se>
 *
 */

#ifndef __LWIPOPTS_H__
#define __LWIPOPTS_H__

#if 0
/*****************************************************************************
**                           CONFIGURATIONS
*****************************************************************************/

/*
** The below macro should be defined for using lwIP with cache. For cache
** enabling, pbuf pool shall be cache line aligned. This is done by using
** separate pool for each memory. The alignment of pbuf pool to cache line
** size is done in /ports/cpsw/include/arch/cc.h.
*/
#define LWIP_CACHE_ENABLED
#define SOC_CACHELINE_SIZE_BYTES        32            /* Number of bytes in
                                                         a cache line */
/*
** The timeout for DHCP completion. lwIP library will wait for DHCP
** completion for (LWIP_DHCP_TIMEOUT / 100) seconds.
*/
#define LWIP_DHCP_TIMEOUT               500

/*
** The number of times DHCP is attempted. Each time, the library will wait
** for (LWIP_DHCP_TIMEOUT / 100) seconds for DHCP completion.
*/
#define NUM_DHCP_TRIES                  5

#define LWIP_ETHERNET                   1
#define LWIP_ARP                        1

/*****************************************************************************
**            lwIP SPECIFIC DEFINITIONS - To be used by lwIP stack
*****************************************************************************/
#define HOST_TMR_INTERVAL               0
#define DYNAMIC_HTTP_HEADERS

/*****************************************************************************
**                    Platform specific locking
*****************************************************************************/
#define SYS_LIGHTWEIGHT_PROT            1
#define NO_SYS                          0
#define NO_SYS_NO_TIMERS                0

/*****************************************************************************
**                          Memory Options
*****************************************************************************/
#define MEM_ALIGNMENT                   4
#define MEM_SIZE                        (512 * 1024) /* 256K */

#define MEMP_NUM_PBUF                   96
#define MEMP_NUM_TCP_PCB                32
#define MEMP_NUM_TCP_SEG                32

/* ---------- Pbuf options ---------- */


#ifdef LWIP_CACHE_ENABLED
#define MEMP_SEPARATE_POOLS             1            /* We want the pbuf pool cache line aligned*/
#endif

#define MEMP_NUM_SYS_TIMEOUT (LWIP_TCP + IP_REASSEMBLY + LWIP_ARP + (2*LWIP_DHCP) + LWIP_AUTOIP + LWIP_IGMP + LWIP_DNS + PPP_SUPPORT)

/*****************************************************************************
**                           IP Options
*****************************************************************************/
#define IP_REASSEMBLY                   0
#define IP_FRAG                         0

/*****************************************************************************
**                           DHCP Options
*****************************************************************************/
#define LWIP_DHCP                       1
#define DHCP_DOES_ARP_CHECK             0

/*****************************************************************************
**                           Auto IP  Options
*****************************************************************************/
#define LWIP_AUTOIP                     1
#define LWIP_DHCP_AUTOIP_COOP           ((LWIP_DHCP) && (LWIP_AUTOIP))

/*****************************************************************************
**                           TCP  Options
*****************************************************************************/
#define TCP_MSS                         1500
#define TCP_WND                         (8 * TCP_MSS)
#define TCP_SND_BUF                     (8 * TCP_MSS)
#define TCP_OVERSIZE                    TCP_MSS

/*****************************************************************************
**                           PBUF  Options
*****************************************************************************/
#define PBUF_LINK_HLEN                  14
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE                  256

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE               1524

#define ETH_PAD_SIZE                    0
#define LWIP_NETCONN                    1

/*****************************************************************************
**                           Socket  Options
*****************************************************************************/
#define LWIP_SOCKET                     1

/*****************************************************************************
**                          Debugging options
*****************************************************************************/
#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_OFF
#define LWIP_DBG_TYPES_ON               (LWIP_DBG_ON | LWIP_DBG_TRACE \
                                         |LWIP_DBG_STATE | LWIP_DBG_FRESH)
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define ETHARP_DEBUG                    LWIP_DBG_OFF
#define SYS_DEBUG                       LWIP_DBG_OFF
#define RAW_DEBUG                       LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
#define PBUF_DEBUG                      LWIP_DBG_OFF
#define TCPIP_DEBUG                     LWIP_DBG_OFF
#define APP_DEBUG                       LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
#define TIMERS_DEBUG                    LWIP_DBG_ON
#define LWIP_STATS                      0
#define LWIP_STATS_DISPLAY              0
#define LWIP_STATS_POSIX                0

/**
 * LWIP_COMPAT_SOCKETS==1: Enable BSD-style sockets functions names.
 * (only used if you use sockets.c)
 */
#define LWIP_COMPAT_SOCKETS             1

#define LWIP_TIMEVAL_PRIVATE            0
#define LWIP_RAW                        0

#define configMAX_PRIORITIES            100
#define TCPIP_THREAD_PRIO               20
#define TCPIP_THREAD_STACKSIZE          8192
#define TCPIP_MBOX_SIZE                 10
#define DEFAULT_TCP_RECVMBOX_SIZE       (sizeof(void *))
#define DEFAULT_ACCEPTMBOX_SIZE         10
#define TCPIP_THREAD_NAME               "TCP_"

#else
/*****************************************************************************
**                           CONFIGURATIONS
*****************************************************************************/

/*
** The below macro should be defined for using lwIP with cache. For cache
** enabling, pbuf pool shall be cache line aligned. This is done by using
** separate pool for each memory. The alignment of pbuf pool to cache line
** size is done in /ports/cpsw/include/arch/cc.h.
*/
#define LWIP_CACHE_ENABLED
#define SOC_CACHELINE_SIZE_BYTES        32            /* Number of bytes in
                                                         a cache line */

#define LWIP_ETHERNET                   1
#define LWIP_ARP                        1

/*****************************************************************************
**            lwIP SPECIFIC DEFINITIONS - To be used by lwIP stack
*****************************************************************************/
#define HOST_TMR_INTERVAL               0
#define DYNAMIC_HTTP_HEADERS

/*****************************************************************************
**                    Platform specific locking
*****************************************************************************/
#define SYS_LIGHTWEIGHT_PROT            0
#define NO_SYS                          0
#define NO_SYS_NO_TIMERS                0



/* ---------- Memory options ---------- */
/* MEM_ALIGNMENT: should be set to the alignment of the CPU for which
   lwIP is compiled. 4 byte alignment -> define MEM_ALIGNMENT to 4, 2
   byte alignment -> define MEM_ALIGNMENT to 2. */
#define MEM_ALIGNMENT           4

/* MEM_SIZE: the size of the heap memory. If the application will send
a lot of data that needs to be copied, this should be set high. */
#define MEM_SIZE                (10 *1024)

/* MEMP_NUM_PBUF: the number of memp struct pbufs. If the application
   sends a lot of data out of ROM (or other static memory), this
   should be set high. */
#define MEMP_NUM_PBUF           50
/* MEMP_NUM_UDP_PCB: the number of UDP protocol control blocks. One
   per active UDP "connection". */
#define MEMP_NUM_UDP_PCB        6
/* MEMP_NUM_TCP_PCB: the number of simulatenously active TCP
   connections. */
#define MEMP_NUM_TCP_PCB        10
/* MEMP_NUM_TCP_PCB_LISTEN: the number of listening TCP
   connections. */
#define MEMP_NUM_TCP_PCB_LISTEN 5
/* MEMP_NUM_TCP_SEG: the number of simultaneously queued TCP
   segments. */
#define MEMP_NUM_TCP_SEG        12
/* MEMP_NUM_SYS_TIMEOUT: the number of simulateously active
   timeouts. */
#define MEMP_NUM_SYS_TIMEOUT    10


/* ---------- Pbuf options ---------- */
/* PBUF_POOL_SIZE: the number of buffers in the pbuf pool. */
#define PBUF_POOL_SIZE          10

/* PBUF_POOL_BUFSIZE: the size of each pbuf in the pbuf pool. */
#define PBUF_POOL_BUFSIZE       1524


/* ---------- TCP options ---------- */
#define LWIP_TCP                1
#define TCP_TTL                 255

/* Controls if TCP should queue segments that arrive out of
   order. Define to 0 if your device is low on memory. */
#define TCP_QUEUE_OOSEQ         0

/* TCP Maximum segment size. */
#define TCP_MSS                 (1500 - 40)   /* TCP_MSS = (Ethernet MTU - IP header size - TCP header size) */

/* TCP sender buffer space (bytes). */
#define TCP_SND_BUF             (4*TCP_MSS)

/*  TCP_SND_QUEUELEN: TCP sender buffer space (pbufs). This must be at least
  as much as (2 * TCP_SND_BUF/TCP_MSS) for things to work. */

#define TCP_SND_QUEUELEN        (2* TCP_SND_BUF/TCP_MSS)

/* TCP receive window. */
#define TCP_WND                 (2*TCP_MSS)


/* ---------- Pbuf options ---------- */

#ifdef LWIP_CACHE_ENABLED
#define MEMP_SEPARATE_POOLS             1            /* We want the pbuf pool cache line aligned*/
#endif

/*****************************************************************************
**                           IP Options
*****************************************************************************/
#define IP_REASSEMBLY                   0
#define IP_FRAG                         0

/*****************************************************************************
**                           DHCP Options
*****************************************************************************/
#define LWIP_DHCP                       1
#define DHCP_DOES_ARP_CHECK             0

/*****************************************************************************
**                           Auto IP  Options
*****************************************************************************/
#define LWIP_AUTOIP                     1
#define LWIP_DHCP_AUTOIP_COOP           ((LWIP_DHCP) && (LWIP_AUTOIP))


/*****************************************************************************
**                           PBUF  Options
*****************************************************************************/

#define ETH_PAD_SIZE                    0
#define LWIP_NETCONN                    1

/*****************************************************************************
**                           Socket  Options
*****************************************************************************/
#define LWIP_SOCKET                     1

/*****************************************************************************
**                          Debugging options
*****************************************************************************/
#define LWIP_DBG_MIN_LEVEL              LWIP_DBG_LEVEL_OFF
#define LWIP_DBG_TYPES_ON               (LWIP_DBG_ON | LWIP_DBG_TRACE \
                                         |LWIP_DBG_STATE | LWIP_DBG_FRESH)
#define DHCP_DEBUG                      LWIP_DBG_OFF
#define NETIF_DEBUG                     LWIP_DBG_OFF
#define IP_DEBUG                        LWIP_DBG_OFF
#define UDP_DEBUG                       LWIP_DBG_OFF
#define ETHARP_DEBUG                    LWIP_DBG_OFF
#define SYS_DEBUG                       LWIP_DBG_OFF
#define RAW_DEBUG                       LWIP_DBG_OFF
#define MEM_DEBUG                       LWIP_DBG_OFF
#define MEMP_DEBUG                      LWIP_DBG_OFF
#define PBUF_DEBUG                      LWIP_DBG_OFF
#define TCPIP_DEBUG                     LWIP_DBG_OFF
#define APP_DEBUG                       LWIP_DBG_OFF
#define SOCKETS_DEBUG                   LWIP_DBG_OFF
#define TIMERS_DEBUG                    LWIP_DBG_ON
#define LWIP_STATS                      0
#define LWIP_STATS_DISPLAY              0
#define LWIP_STATS_POSIX                0

/**
 * LWIP_COMPAT_SOCKETS==1: Enable BSD-style sockets functions names.
 * (only used if you use sockets.c)
 */
#define LWIP_COMPAT_SOCKETS             1
#define LWIP_RAW                        0

#define LWIP_PROVIDE_ERRNO 1
#define TCPIP_THREAD_NAME              "TCP/IP"
#define TCPIP_THREAD_STACKSIZE          1000
#define TCPIP_MBOX_SIZE                 5
#define DEFAULT_UDP_RECVMBOX_SIZE       2000
#define DEFAULT_TCP_RECVMBOX_SIZE       2000
#define DEFAULT_ACCEPTMBOX_SIZE         2000
#define DEFAULT_THREAD_STACKSIZE        500
#define TCPIP_THREAD_PRIO               (100)
#define LWIP_COMPAT_MUTEX               1

#define LWIP_TIMEVAL_PRIVATE            0
#endif


#endif /* __LWIPOPTS_H__ */
