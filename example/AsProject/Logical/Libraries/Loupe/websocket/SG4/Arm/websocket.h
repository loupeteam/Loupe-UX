/* Automation Studio generated header file */
/* Do not edit ! */
/* websocket 0.02.0 */

#ifndef _WEBSOCKET_
#define _WEBSOCKET_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _websocket_VERSION
#define _websocket_VERSION 0.02.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsHttp.h"
		#include "sys_lib.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif
#ifdef _SG4
		#include "AsHttp.h"
		#include "sys_lib.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif
#ifdef _SGC
		#include "AsHttp.h"
		#include "sys_lib.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define WS_HEADER_MAX_LEN 14U
 #define WS_HEADER_MIN_LEN 2U
 #define WS_STRLEN_ERRORSTRING 320U
 #define WS_STRLEN_CONNECTMESSAGE 129U
 #define WS_STRLEN_KEYHEADER 18U
 #define WS_SOC_MAGICSTRING "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"
#else
 _GLOBAL_CONST unsigned char WS_HEADER_MAX_LEN;
 _GLOBAL_CONST unsigned char WS_HEADER_MIN_LEN;
 _GLOBAL_CONST unsigned short WS_STRLEN_ERRORSTRING;
 _GLOBAL_CONST unsigned char WS_STRLEN_CONNECTMESSAGE;
 _GLOBAL_CONST unsigned short WS_STRLEN_KEYHEADER;
 _GLOBAL_CONST plcstring WS_SOC_MAGICSTRING[37];
#endif




/* Datatypes and datatypes of function blocks */
typedef enum WS_OpCode_enum
{	WS_OPCODE_CONTINUATION = 0,
	WS_OPCODE_TEXT = 1,
	WS_OPCODE_BINARY = 2,
	WS_OPCODE_RESERVED_NON_CONTROL = 3,
	WS_OPCODE_CONNECTION_CLOSE = 8,
	WS_OPCODE_PING = 9,
	WS_OPCODE_PONG = 10,
	WS_OPCODE_RESERVED_CONTROL = 11
} WS_OpCode_enum;

typedef enum WS_ERR_enum
{	WS_ERR_OK,
	WS_ERR_INVALID_INPUT = 5500,
	WS_ERR_NOT_IMPLEMENTED,
	WS_ERR_PAYLOAD_LENGTH,
	WS_ERR_MEM_ALLOC,
	WS_ERR_NO_LICENSE,
	WS_ERR_KEY_NOT_FOUND,
	WS_ERR_PARTIAL_HTTP_MESSAGE,
	WS_ERR_INVALID_HTTP_MESSAGE,
	WS_ERR_BUFFER_FULL,
	WS_ERR_
} WS_ERR_enum;

typedef enum WS_Mode_enum
{	WS_MODE_SERVER = 50000,
	WS_MODE_CLIENT
} WS_Mode_enum;

typedef struct WSHeader_typ
{	plcbit fin;
	unsigned char rsv;
	unsigned char opCode;
	plcbit mask;
	unsigned char maskingKey[4];
	unsigned long frameLength;
} WSHeader_typ;

typedef unsigned char MaskingKey_typ[4];

typedef struct wsMask
{
	/* VAR_INPUT (analog) */
	unsigned long src;
	unsigned long srcLength;
	unsigned long dest;
	unsigned long destSize;
	MaskingKey_typ maskingKey;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLength;
} wsMask_typ;

typedef struct WSDecode_Internal_typ
{	struct wsMask mask;
} WSDecode_Internal_typ;

typedef struct WSEncode_Internal_typ
{	struct wsMask mask;
} WSEncode_Internal_typ;

typedef struct WSConnect_Internal_typ
{	struct httpEncodeBase64 encodeBase64;
} WSConnect_Internal_typ;

typedef struct WSConnectionManager_In_Cmd_typ
{	plcbit enable;
	plcbit acknowledgeConnection;
	plcbit acknowledgeError;
} WSConnectionManager_In_Cmd_typ;

typedef struct WSConnectionManager_In_Cfg_typ
{	enum WS_Mode_enum mode;
	plcstring localIPAddress[256];
	unsigned long localPort;
	plcstring remoteIPAddress[256];
	unsigned long remotePort;
	unsigned long sendBufferSize;
	plcbit useSSL;
	unsigned long sslCertificate;
} WSConnectionManager_In_Cfg_typ;

typedef struct WSConnectionManager_In_typ
{	struct WSConnectionManager_In_Cmd_typ cmd;
	struct WSConnectionManager_In_Cfg_typ cfg;
} WSConnectionManager_In_typ;

typedef struct WSConnectionManager_Desc_typ
{	struct TCPConnection_Desc_typ parameters;
	enum WS_Mode_enum mode;
} WSConnectionManager_Desc_typ;

typedef struct WSConnectionManager_Out_typ
{	plcbit newConnectionAvailable;
	struct WSConnectionManager_Desc_typ connection;
	plcbit error;
	unsigned short errorID;
	plcstring errorString[321];
} WSConnectionManager_Out_typ;

typedef struct WSConnectionManager_Internal_typ
{	struct TCPConnectionMgr_typ tcpConnection;
} WSConnectionManager_Internal_typ;

typedef struct WSConnectionManager_typ
{	struct WSConnectionManager_In_typ in;
	struct WSConnectionManager_Out_typ out;
	struct WSConnectionManager_Internal_typ internal;
} WSConnectionManager_typ;

typedef struct WSStream_IN_CMD_typ
{	plcbit receive;
	plcbit send;
	plcbit close;
	plcbit acknowledgeData;
	plcbit acknowledgeError;
} WSStream_IN_CMD_typ;

typedef struct WSStream_IN_PAR_typ
{	struct WSConnectionManager_Desc_typ connection;
	unsigned long pReceiveData;
	unsigned long maxReceiveLength;
	unsigned short receiveFlags;
	plcbit allowContinuousReceive;
	unsigned long pSendData;
	unsigned long sendLength;
	struct WSHeader_typ sendHeader;
	unsigned short sendFlags;
	plcbit allowContinuousSend;
} WSStream_IN_PAR_typ;

typedef struct WSStream_IN_CFG_typ
{	unsigned long bufferSize;
} WSStream_IN_CFG_typ;

typedef struct WSStream_IN_typ
{	struct WSStream_IN_CMD_typ cmd;
	struct WSStream_IN_PAR_typ par;
	struct WSStream_IN_CFG_typ cfg;
} WSStream_IN_typ;

typedef struct WSStream_OUT_typ
{	struct WSConnectionManager_Desc_typ connection;
	plcbit active;
	plcbit connected;
	plcbit receiving;
	struct WSHeader_typ header;
	plcbit partialDataReceived;
	plcbit dataReceived;
	unsigned long receivedDataLength;
	plcbit sending;
	plcbit dataSent;
	unsigned long sentDataLength;
	plcbit error;
	unsigned short errorID;
	plcstring errorString[321];
} WSStream_OUT_typ;

typedef struct WSStream_Int_Debug_typ
{	unsigned char New_Member;
} WSStream_Int_Debug_typ;

typedef struct wsDecode
{
	/* VAR_INPUT (analog) */
	unsigned long pFrame;
	unsigned long frameLength;
	unsigned long pPayload;
	unsigned long payloadSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char rsv;
	unsigned char opCode;
	MaskingKey_typ maskingKey;
	unsigned long headerLength;
	unsigned long payloadLength;
	unsigned long decodeLength;
	/* VAR (analog) */
	struct WSDecode_Internal_typ internal;
	/* VAR_OUTPUT (digital) */
	plcbit partialHeader;
	plcbit partialFrame;
	plcbit fin;
	plcbit mask;
} wsDecode_typ;

typedef struct wsEncode
{
	/* VAR_INPUT (analog) */
	unsigned long pFrame;
	unsigned long frameSize;
	unsigned char rsv;
	unsigned char opCode;
	MaskingKey_typ maskingKey;
	unsigned long pPayload;
	unsigned long payloadLength;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long frameLength;
	/* VAR (analog) */
	struct WSEncode_Internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit fin;
	plcbit mask;
} wsEncode_typ;

typedef struct wsConnect
{
	/* VAR_INPUT (analog) */
	unsigned long pInputMessage;
	unsigned long pOutputMessage;
	unsigned long outputMessageSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long outputMessageLength;
	/* VAR (analog) */
	struct WSConnect_Internal_typ internal;
} wsConnect_typ;

typedef struct WSStream_Int_FUB_typ
{	struct TCPStream_typ tcpStream;
	struct wsDecode wsDecode;
	struct wsEncode wsEncode;
	struct wsConnect wsConnect;
	struct wsMask wsMask;
} WSStream_Int_FUB_typ;

typedef struct WSStream_Internal_typ
{	struct WSStream_Int_Debug_typ debug;
	struct WSStream_Int_FUB_typ fub;
	struct WSConnectionManager_Desc_typ connection;
	plcbit initialized;
	plcbit connected;
	plcbit connectionUpgraded;
	unsigned short connectionState;
	unsigned long bufferSize;
	unsigned long sendBuffer;
	unsigned long recieveBuffer;
	plcbit prevSend;
} WSStream_Internal_typ;

typedef struct WSStream_typ
{	struct WSStream_IN_typ in;
	struct WSStream_OUT_typ out;
	struct WSStream_Internal_typ internal;
} WSStream_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void wsConnect(struct wsConnect* inst);
_BUR_PUBLIC void wsDecode(struct wsDecode* inst);
_BUR_PUBLIC void wsEncode(struct wsEncode* inst);
_BUR_PUBLIC void wsMask(struct wsMask* inst);
_BUR_PUBLIC plcbit wsManageConnection(struct WSConnectionManager_typ* inst);
_BUR_PUBLIC plcbit wsSend(struct WSStream_typ* inst);
_BUR_PUBLIC plcbit wsReceive(struct WSStream_typ* inst);
_BUR_PUBLIC unsigned long wsGetErrorMsg(unsigned long dest, signed long errorID, unsigned long destSize);
_BUR_PUBLIC plcbit wsModeIsValid(signed long mode);


__asm__(".section \".plc\"");

/* Additional IEC dependencies */
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/tcpcomm/TCPComm.var\\\" scope \\\"global\\\"\\n\"");

__asm__(".previous");

#ifdef __cplusplus
};
#endif
#endif /* _WEBSOCKET_ */

