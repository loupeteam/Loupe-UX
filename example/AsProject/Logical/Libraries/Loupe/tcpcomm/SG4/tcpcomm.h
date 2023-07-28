/* Automation Studio generated header file */
/* Do not edit ! */
/* tcpcomm 0.10.0 */

#ifndef _TCPCOMM_
#define _TCPCOMM_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _tcpcomm_VERSION
#define _tcpcomm_VERSION 0.10.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsTCP.h"
#endif
#ifdef _SG4
		#include "AsTCP.h"
#endif
#ifdef _SGC
		#include "AsTCP.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define TCPCOMM_STRLEN_IPADDRESS 255U
 #define TCPCOMM_STRLEN_ERRORSTRING 320U
#else
 _GLOBAL_CONST unsigned char TCPCOMM_STRLEN_IPADDRESS;
 _GLOBAL_CONST unsigned short TCPCOMM_STRLEN_ERRORSTRING;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum TCPCOMM_MODE_enum
{	TCPCOMM_MODE_SERVER = 50000,
	TCPCOMM_MODE_CLIENT
} TCPCOMM_MODE_enum;

typedef enum TCPCOMM_ERR_enum
{	TCPCOMM_ERR_INVALIDINPUT = 50000,
	TCPCOMM_ERR_SENDDATATOOLARGE,
	TCPCOMM_ERR_
} TCPCOMM_ERR_enum;

typedef enum TCPCOMM_ST_enum
{	TCPCOMM_ST_CLOSED,
	TCPCOMM_ST_OPENING,
	TCPCOMM_ST_IOCTL,
	TCPCOMM_ST_LISTEN,
	TCPCOMM_ST_RUNNING,
	TCPCOMM_ST_CLOSE_CONNECTION,
	TCPCOMM_ST_CLOSING,
	TCPCOMM_ST_ERROR
} TCPCOMM_ST_enum;

typedef enum TCPCOMM_SEND_ST_enum
{	TCPCOMM_SEND_ST_IDLE,
	TCPCOMM_SEND_ST_SEND
} TCPCOMM_SEND_ST_enum;

typedef enum TCPCOMM_RECV_ST_enum
{	TCPCOMM_RECV_ST_READ
} TCPCOMM_RECV_ST_enum;

typedef struct TCPStream_Int_Debug_Mng_typ
{	unsigned char New_Member;
} TCPStream_Int_Debug_Mng_typ;

typedef struct TCPStream_Int_Debug_Recv_typ
{	plcbit enable[2];
	unsigned short status[2];
} TCPStream_Int_Debug_Recv_typ;

typedef struct TCPStream_Int_Debug_Send_typ
{	unsigned char New_Member;
} TCPStream_Int_Debug_Send_typ;

typedef struct TCPStream_Int_Debug_typ
{	struct TCPStream_Int_Debug_Mng_typ manage;
	struct TCPStream_Int_Debug_Recv_typ receive;
	struct TCPStream_Int_Debug_Send_typ send;
} TCPStream_Int_Debug_typ;

typedef struct TCPStream_Int_FUB_typ
{	struct TcpSend Send;
	struct TcpRecv Receive;
	struct TcpClose Close;
} TCPStream_Int_FUB_typ;

typedef struct TCPStream_Internal_typ
{	enum TCPCOMM_ST_enum CommState;
	unsigned long Ident;
	unsigned long UID;
	struct TCPStream_Int_FUB_typ FUB;
	struct TCPStream_Int_Debug_typ debug;
} TCPStream_Internal_typ;

typedef struct TCPConnection_Desc_typ
{	plcstring IPAddress[256];
	unsigned short Port;
	unsigned short Ident;
	unsigned long UID;
} TCPConnection_Desc_typ;

typedef struct TCPStream_OUT_typ
{	struct TCPConnection_Desc_typ Connection;
	plcbit Active;
	plcbit Receiving;
	plcbit DataReceived;
	unsigned long ReceivedDataLength;
	plcbit Sending;
	plcbit DataSent;
	unsigned long SentDataLength;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[321];
} TCPStream_OUT_typ;

typedef struct TCPStream_IN_PAR_typ
{	struct TCPConnection_Desc_typ Connection;
	unsigned long pReceiveData;
	unsigned long MaxReceiveLength;
	unsigned short ReceiveFlags;
	plcbit AllowContinuousReceive;
	unsigned long pSendData;
	unsigned long SendLength;
	unsigned short SendFlags;
	plcbit AllowContinuousSend;
} TCPStream_IN_PAR_typ;

typedef struct TCPStream_IN_CMD_typ
{	plcbit Receive;
	plcbit Send;
	plcbit Close;
	plcbit AcknowledgeData;
	plcbit AcknowledgeError;
} TCPStream_IN_CMD_typ;

typedef struct TCPStream_IN_typ
{	struct TCPStream_IN_CMD_typ CMD;
	struct TCPStream_IN_PAR_typ PAR;
} TCPStream_IN_typ;

typedef struct TCPStream_typ
{	struct TCPStream_IN_typ IN;
	struct TCPStream_OUT_typ OUT;
	struct TCPStream_Internal_typ Internal;
} TCPStream_typ;

typedef struct TCPConnectionMgr_Int_FUB_typ
{	struct TcpOpen Open;
	struct TcpOpenSsl OpenSSL;
	struct TcpIoctl Ioctl;
	struct TcpServer Server;
	struct TcpClient Client;
	struct TcpClose Close;
} TCPConnectionMgr_Int_FUB_typ;

typedef struct TCPConnectionMgr_Internal_typ
{	struct TCPConnectionMgr_Int_FUB_typ FUB;
	enum TCPCOMM_ST_enum CommState;
	enum TCPCOMM_MODE_enum Mode;
	unsigned long Ident;
	unsigned long ConnectionUID;
} TCPConnectionMgr_Internal_typ;

typedef struct TCPConnectionMgr_OUT_typ
{	plcbit NewConnectionAvailable;
	struct TCPConnection_Desc_typ Connection;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[321];
} TCPConnectionMgr_OUT_typ;

typedef struct TCPConnectionMgr_IN_CFG_typ
{	enum TCPCOMM_MODE_enum Mode;
	plcstring LocalIPAddress[256];
	unsigned short LocalPort;
	plcstring RemoteIPAddress[256];
	unsigned short RemotePort;
	unsigned long SendBufferSize;
	plcbit UseSSL;
	unsigned long SSLCertificate;
} TCPConnectionMgr_IN_CFG_typ;

typedef struct TCPConnectionMgr_IN_CMD_typ
{	plcbit Enable;
	plcbit AcknowledgeConnection;
	plcbit AcknowledgeError;
} TCPConnectionMgr_IN_CMD_typ;

typedef struct TCPConnectionMgr_IN_typ
{	struct TCPConnectionMgr_IN_CMD_typ CMD;
	struct TCPConnectionMgr_IN_CFG_typ CFG;
} TCPConnectionMgr_IN_typ;

typedef struct TCPConnectionMgr_typ
{	struct TCPConnectionMgr_IN_typ IN;
	struct TCPConnectionMgr_OUT_typ OUT;
	struct TCPConnectionMgr_Internal_typ Internal;
} TCPConnectionMgr_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short TCPManageConnection(struct TCPConnectionMgr_typ* t);
_BUR_PUBLIC unsigned short TCPStreamReceive(struct TCPStream_typ* t);
_BUR_PUBLIC unsigned short TCPStreamSend(struct TCPStream_typ* t);


#ifdef __cplusplus
};
#endif
#endif /* _TCPCOMM_ */

