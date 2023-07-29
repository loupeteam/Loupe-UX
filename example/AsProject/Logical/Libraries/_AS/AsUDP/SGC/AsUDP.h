/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASUDP_
#define _ASUDP_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define udpINVALID_IDENT 0U
 #define udpIP_TOS_MINCOST 2U
 #define udpIP_TOS_RELIABILITY 4U
 #define udpIP_TOS_THROUGHPUT 8U
 #define udpIP_TOS_LOWDELAY 16U
 #define udpOPT_BROADCAST 4U
 #define udpOPT_REUSEPORT 2U
 #define udpOPT_REUSEADDR 1U
 #define udpMSG_DONTROUTE 2U
 #define udpMSG_PEEK 1U
 #define udpID_MAX_GET 3002U
 #define udpID_LIST_GET 3001U
 #define udpIP_TTL_GET 2012U
 #define udpIP_TTL_SET 2011U
 #define udpIP_TOS_GET 2010U
 #define udpIP_TOS_SET 2009U
 #define udpIP_MULTICAST_LOOP_GET 2008U
 #define udpIP_MULTICAST_LOOP_SET 2007U
 #define udpIP_MULTICAST_TTL_GET 2006U
 #define udpIP_MULTICAST_TTL_SET 2005U
 #define udpIP_MULTICAST_IF_GET 2004U
 #define udpIP_MULTICAST_IF_SET 2003U
 #define udpIP_DROP_MEMBERSHIP 2002U
 #define udpIP_ADD_MEMBERSHIP 2001U
 #define udpSO_ADDRESS_GET 1007U
 #define udpSO_RCVBUF_GET 1006U
 #define udpSO_RCVBUF_SET 1005U
 #define udpSO_SNDBUF_GET 1004U
 #define udpSO_SNDBUF_SET 1003U
 #define udpSO_BROADCAST_GET 1002U
 #define udpSO_BROADCAST_SET 1001U
 #define udpERR_SYSTEM 32599U
 #define udpERR_SOCKET_CONNECT 32552U
 #define udpERR_SOCKET_BIND 32551U
 #define udpERR_SOCKET_CREATE 32550U
 #define udpERR_INTERFACE 32511U
 #define udpERR_UNREACHABLE 32510U
 #define udpERR_ACCESS 32509U
 #define udpERR_CONNREFUSED 32508U
 #define udpERR_WOULDBLOCK 32507U
 #define udpERR_SENTLEN 32506U
 #define udpERR_NO_DATA 32505U
 #define udpERR_INVALID_IOCTL 32504U
 #define udpERR_PARAMETER 32503U
 #define udpERR_ALREADY_EXIST 32502U
 #define udpERR_NOMORE_IDENTS 32501U
 #define udpERR_INVALID_IDENT 32500U
#else
 _IEC_CONST unsigned long udpINVALID_IDENT = 0U;
 _IEC_CONST unsigned long udpIP_TOS_MINCOST = 2U;
 _IEC_CONST unsigned long udpIP_TOS_RELIABILITY = 4U;
 _IEC_CONST unsigned long udpIP_TOS_THROUGHPUT = 8U;
 _IEC_CONST unsigned long udpIP_TOS_LOWDELAY = 16U;
 _IEC_CONST unsigned long udpOPT_BROADCAST = 4U;
 _IEC_CONST unsigned long udpOPT_REUSEPORT = 2U;
 _IEC_CONST unsigned long udpOPT_REUSEADDR = 1U;
 _IEC_CONST unsigned long udpMSG_DONTROUTE = 2U;
 _IEC_CONST unsigned long udpMSG_PEEK = 1U;
 _IEC_CONST unsigned long udpID_MAX_GET = 3002U;
 _IEC_CONST unsigned long udpID_LIST_GET = 3001U;
 _IEC_CONST unsigned long udpIP_TTL_GET = 2012U;
 _IEC_CONST unsigned long udpIP_TTL_SET = 2011U;
 _IEC_CONST unsigned long udpIP_TOS_GET = 2010U;
 _IEC_CONST unsigned long udpIP_TOS_SET = 2009U;
 _IEC_CONST unsigned long udpIP_MULTICAST_LOOP_GET = 2008U;
 _IEC_CONST unsigned long udpIP_MULTICAST_LOOP_SET = 2007U;
 _IEC_CONST unsigned long udpIP_MULTICAST_TTL_GET = 2006U;
 _IEC_CONST unsigned long udpIP_MULTICAST_TTL_SET = 2005U;
 _IEC_CONST unsigned long udpIP_MULTICAST_IF_GET = 2004U;
 _IEC_CONST unsigned long udpIP_MULTICAST_IF_SET = 2003U;
 _IEC_CONST unsigned long udpIP_DROP_MEMBERSHIP = 2002U;
 _IEC_CONST unsigned long udpIP_ADD_MEMBERSHIP = 2001U;
 _IEC_CONST unsigned long udpSO_ADDRESS_GET = 1007U;
 _IEC_CONST unsigned long udpSO_RCVBUF_GET = 1006U;
 _IEC_CONST unsigned long udpSO_RCVBUF_SET = 1005U;
 _IEC_CONST unsigned long udpSO_SNDBUF_GET = 1004U;
 _IEC_CONST unsigned long udpSO_SNDBUF_SET = 1003U;
 _IEC_CONST unsigned long udpSO_BROADCAST_GET = 1002U;
 _IEC_CONST unsigned long udpSO_BROADCAST_SET = 1001U;
 _IEC_CONST unsigned short udpERR_SYSTEM = 32599U;
 _IEC_CONST unsigned short udpERR_SOCKET_CONNECT = 32552U;
 _IEC_CONST unsigned short udpERR_SOCKET_BIND = 32551U;
 _IEC_CONST unsigned short udpERR_SOCKET_CREATE = 32550U;
 _IEC_CONST unsigned short udpERR_INTERFACE = 32511U;
 _IEC_CONST unsigned short udpERR_UNREACHABLE = 32510U;
 _IEC_CONST unsigned short udpERR_ACCESS = 32509U;
 _IEC_CONST unsigned short udpERR_CONNREFUSED = 32508U;
 _IEC_CONST unsigned short udpERR_WOULDBLOCK = 32507U;
 _IEC_CONST unsigned short udpERR_SENTLEN = 32506U;
 _IEC_CONST unsigned short udpERR_NO_DATA = 32505U;
 _IEC_CONST unsigned short udpERR_INVALID_IOCTL = 32504U;
 _IEC_CONST unsigned short udpERR_PARAMETER = 32503U;
 _IEC_CONST unsigned short udpERR_ALREADY_EXIST = 32502U;
 _IEC_CONST unsigned short udpERR_NOMORE_IDENTS = 32501U;
 _IEC_CONST unsigned short udpERR_INVALID_IDENT = 32500U;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct udpIP_MREQ_typ
{	unsigned long pMcastAddr;
	unsigned long pIfAddr;
} udpIP_MREQ_typ;

typedef struct udpSO_ADDRESS_typ
{	unsigned long pPort;
	unsigned long pIpAddr;
} udpSO_ADDRESS_typ;

typedef struct UdpOpen
{
	/* VAR_INPUT (analog) */
	unsigned long pIfAddr;
	unsigned short port;
	unsigned long options;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpOpen_typ;

typedef struct UdpClose
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpClose_typ;

typedef struct UdpConnect
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pHost;
	unsigned short port;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpConnect_typ;

typedef struct UdpDisconnect
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpDisconnect_typ;

typedef struct UdpSend
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pHost;
	unsigned short port;
	unsigned long pData;
	unsigned long datalen;
	unsigned long flags;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long sentlen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpSend_typ;

typedef struct UdpRecv
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pData;
	unsigned long datamax;
	unsigned long flags;
	unsigned long pIpAddr;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long recvlen;
	unsigned short port;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpRecv_typ;

typedef struct UdpIoctl
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long ioctl;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long outlen;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} UdpIoctl_typ;



/* Prototyping of functions and function blocks */
void UdpOpen(struct UdpOpen* inst);
void UdpClose(struct UdpClose* inst);
void UdpConnect(struct UdpConnect* inst);
void UdpDisconnect(struct UdpDisconnect* inst);
void UdpSend(struct UdpSend* inst);
void UdpRecv(struct UdpRecv* inst);
void UdpIoctl(struct UdpIoctl* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASUDP_ */

                                                           
