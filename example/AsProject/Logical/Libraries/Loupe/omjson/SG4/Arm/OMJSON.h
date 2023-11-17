/* Automation Studio generated header file */
/* Do not edit ! */
/* OMJSON 1.04.0 */

#ifndef _OMJSON_
#define _OMJSON_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _OMJSON_VERSION
#define _OMJSON_VERSION 1.04.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "AsHttp.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "vartools.h"
		#include "databuffer.h"
		#include "websocket.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "AsHttp.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "vartools.h"
		#include "databuffer.h"
		#include "websocket.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "AsHttp.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "vartools.h"
		#include "databuffer.h"
		#include "websocket.h"
		#include "tcpcomm.h"
		#include "stringext.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define JSON_DEFAULT_SERVERPORT 8000U
 #define JSON_DEFAULT_BUFFERSIZE 100000U
 #define JSON_DEFAULT_MAXJSONOBJECTLENGTH 100000U
 #define JSON_DEFAULT_MAXITERATIONS 10000U
 #define JSON_DEFAULT_TIMEOUT 30000U
 #define JSON_MAX_CLIENTS 5U
 #define JSON_MAI_CLIENTS 4U
 #define JSON_MAI_STRUCTLEVEL 19U
 #define JSON_MAI_CACHEVAR 400U
 #define JSON_MAI_CACHEITEM 20000U
 #define JSON_STRLEN_ERROR 320U
 #define JSON_STRLEN_PREFIX 400U
 #define JSON_STRLEN_SUFFIX 20U
 #define JSON_STRLEN_IP 15U
 #define JSON_STRLEN_SERVICENAMEPREFIX 20U
 #define JSON_STRLEN_WSKEYHEADER 18U
 #define JSON_STRLEN_WSCONNECTMESSAGE 129U
 #define JSON_WS_MAGICSTRING "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"
#else
 _GLOBAL_CONST unsigned short JSON_DEFAULT_SERVERPORT;
 _GLOBAL_CONST unsigned long JSON_DEFAULT_BUFFERSIZE;
 _GLOBAL_CONST unsigned long JSON_DEFAULT_MAXJSONOBJECTLENGTH;
 _GLOBAL_CONST unsigned long JSON_DEFAULT_MAXITERATIONS;
 _GLOBAL_CONST unsigned long JSON_DEFAULT_TIMEOUT;
 _GLOBAL_CONST unsigned short JSON_MAX_CLIENTS;
 _GLOBAL_CONST unsigned short JSON_MAI_CLIENTS;
 _GLOBAL_CONST unsigned char JSON_MAI_STRUCTLEVEL;
 _GLOBAL_CONST unsigned short JSON_MAI_CACHEVAR;
 _GLOBAL_CONST unsigned short JSON_MAI_CACHEITEM;
 _GLOBAL_CONST unsigned short JSON_STRLEN_ERROR;
 _GLOBAL_CONST unsigned short JSON_STRLEN_PREFIX;
 _GLOBAL_CONST unsigned short JSON_STRLEN_SUFFIX;
 _GLOBAL_CONST unsigned short JSON_STRLEN_IP;
 _GLOBAL_CONST unsigned short JSON_STRLEN_SERVICENAMEPREFIX;
 _GLOBAL_CONST unsigned short JSON_STRLEN_WSKEYHEADER;
 _GLOBAL_CONST unsigned short JSON_STRLEN_WSCONNECTMESSAGE;
 _GLOBAL_CONST plcstring JSON_WS_MAGICSTRING[37];
#endif




/* Datatypes and datatypes of function blocks */
typedef enum JSON_ERR_enum
{	JSON_ERR_INVALIDINPUT = 50000,
	JSON_ERR_MEMALLOC,
	JSON_ERR_MAXLEVELREACHED,
	JSON_ERR_PARSE,
	JSON_ERR_HUH,
	JSON_ERR_CACHEFULLITEMS,
	JSON_ERR_CACHEFULLVARS,
	JSON_ERR_CACHEEMPTY,
	JSON_ERR_MAXITERATIONS,
	JSON_ERR_WS_KEYNOTFOUND,
	JSON_ERR_WS_FRAGMENT,
	JSON_ERR_WS_RSV,
	JSON_ERR_WS_OPCODE,
	JSON_ERR_WS_MASK,
	JSON_ERR_WS_PAYLOADLENGTH,
	JSON_ERR_TCP_FRAGMENT,
	JSON_ERR_TCP_BAD_PACKET,
	JSON_ERR_NO_LICENSE,
	JSON_ERR_WS_MAX_CLIENTS,
	JSON_ERR_WS_INVALID_MAX_CLIENTS,
	JSON_ERR_WS_,
	JSON_ERR_
} JSON_ERR_enum;

typedef enum JSON_TYPE_enum
{	JSON_TYPE_INVALID = 0,
	JSON_TYPE_OBJECT_ELEMENT,
	JSON_TYPE_ARRAY_ELEMENT
} JSON_TYPE_enum;

typedef struct jsonWSS_client_info_typ
{	plcbit Connected;
	unsigned long TimeSinceLastRequest_ms;
	plcstring ClientIP[256];
	unsigned short ClientPort;
} jsonWSS_client_info_typ;

typedef struct jsonWSS_client_debug_typ
{	signed long socketConnectCount;
	signed long websocketConnectCount;
	signed long socketDisconnectCountTimeout;
	signed long socketDisconnectCountOpcode;
	signed long socketDisconnectCountError;
	signed long socketDisconnectCountRecvLength0;
	signed long socketInvalidCountError;
	signed long noDataCount;
	signed long dataCount;
	signed long justRightCount;
	signed long tooBigCount;
	signed long tooSmallCount;
	signed long doubleDataCount;
	plcbit oldDataReceived;
} jsonWSS_client_debug_typ;

typedef struct jsonStructLevel_typ
{	struct varVariable_typ variable;
	unsigned short iItem;
	enum JSON_TYPE_enum jsonType;
} jsonStructLevel_typ;

typedef struct jsonWriteVariable_Int_typ
{	plcbit initialized;
	unsigned long pJSONObject;
	unsigned long pChar;
	signed short iStructLevel;
	struct jsonStructLevel_typ structLevel[20];
} jsonWriteVariable_Int_typ;

typedef struct jsonWriteVariable
{
	/* VAR_INPUT (analog) */
	unsigned long pJSONObject;
	unsigned long MaxJSONObjectLength;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	struct jsonWriteVariable_Int_typ internal;
} jsonWriteVariable_typ;

typedef struct jsonAddVariableToCache_Int_typ
{	plcbit initialized;
	signed short iStructLevel;
	struct jsonStructLevel_typ structLevel[20];
} jsonAddVariableToCache_Int_typ;

typedef struct jsonAddVariableToCache
{
	/* VAR_INPUT (analog) */
	unsigned long pVariableName;
	unsigned long pCache;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	unsigned short iVariable;
	/* VAR (analog) */
	struct jsonAddVariableToCache_Int_typ internal;
} jsonAddVariableToCache_typ;

typedef struct jsonReadVariable_Int_typ
{	plcbit initialized;
	struct datbufBuffer_typ outputBuffer;
	plcstring variableName[121];
	struct jsonAddVariableToCache addVariableToCache;
} jsonReadVariable_Int_typ;

typedef struct jsonReadVariable
{
	/* VAR_INPUT (analog) */
	unsigned long pVariableName;
	unsigned long pCache;
	unsigned long BufferSize;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	unsigned long pJSONObject;
	unsigned long JSONObjectLength;
	/* VAR (analog) */
	struct jsonReadVariable_Int_typ internal;
} jsonReadVariable_typ;

typedef struct jsonReadVariableList_Int_typ
{	plcbit initialized;
	struct datbufBuffer_typ outputBuffer;
	struct jsonReadVariable readVariable;
} jsonReadVariableList_Int_typ;

typedef struct jsonReadVariableList
{
	/* VAR_INPUT (analog) */
	unsigned long pVariableList;
	unsigned long pCache;
	unsigned long BufferSize;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	unsigned long pJSONObject;
	unsigned long JSONObjectLength;
	/* VAR (analog) */
	struct jsonReadVariableList_Int_typ internal;
} jsonReadVariableList_typ;

typedef struct jsonWSServer_int_client_typ
{	struct WSStream_typ wsStream;
	unsigned long pReceiveData;
	unsigned long pSendData;
	struct datbufBuffer_typ messageBuffer;
	plcbit wsConnected;
	struct jsonWriteVariable writeVariable;
	struct jsonReadVariableList readVariableList;
	struct jsonWSS_client_debug_typ debug;
	struct TON_10ms requestTimer;
	struct jsonCache_typ* pCache;
} jsonWSServer_int_client_typ;

typedef struct jsonWSServer_Internal_typ
{	plcbit initialized;
	struct WSConnectionManager_typ wsServer;
	struct jsonWSServer_int_client_typ client[5];
	struct TON_10ms requestTimer;
	unsigned short iClient;
	unsigned short connectedClients;
	unsigned short maxClients;
} jsonWSServer_Internal_typ;

typedef struct jsonHTTPServer_Int_Debug_typ
{	plcbit readSendCommand;
} jsonHTTPServer_Int_Debug_typ;

typedef struct jsonHTTPServer_Int_Write_typ
{	struct httpService webService;
	unsigned long pUri;
	unsigned long pRequestData;
	struct httpResponseHeader_t ResponseHeader;
	plcbit processed;
	struct jsonWriteVariable writeVariable;
} jsonHTTPServer_Int_Write_typ;

typedef struct jsonHTTPServer_Int_Read_typ
{	struct httpService webService;
	unsigned long pUri;
	unsigned long pRequestData;
	struct httpResponseHeader_t ResponseHeader;
	plcbit processed;
	struct jsonReadVariableList readVariableList;
} jsonHTTPServer_Int_Read_typ;

typedef struct jsonHTTPServer_Internal_typ
{	plcbit initialized;
	struct jsonHTTPServer_Int_Read_typ read;
	struct jsonHTTPServer_Int_Write_typ write;
	struct jsonHTTPServer_Int_Debug_typ debug;
} jsonHTTPServer_Internal_typ;

typedef struct jsonWSConnect_Internal_typ
{	struct httpEncodeBase64 encodeBase64;
} jsonWSConnect_Internal_typ;

typedef struct jsonCacheVariable_typ
{	plcstring name[121];
	unsigned short iStart;
	unsigned short iEnd;
} jsonCacheVariable_typ;

typedef struct jsonCacheItem_typ
{	plcstring prefix[401];
	struct varVariable_typ variable;
	plcstring suffix[21];
} jsonCacheItem_typ;

typedef struct jsonCache_typ
{	unsigned short iVariable;
	struct jsonCacheVariable_typ variable[401];
	unsigned short iItem;
	struct jsonCacheItem_typ item[20001];
} jsonCache_typ;

typedef struct jsonReadVarNoCache_Int_typ
{	plcbit initialized;
	struct datbufBuffer_typ outputBuffer;
	signed short iStructLevel;
	struct jsonStructLevel_typ structLevel[20];
} jsonReadVarNoCache_Int_typ;

typedef struct jsonWebSocketServer
{
	/* VAR_INPUT (analog) */
	unsigned long pCacheArray;
	unsigned short maxClients;
	plcstring ServerIP[256];
	unsigned short ServerPort;
	unsigned long BufferSize;
	unsigned long MaxIterations;
	unsigned long Timeout;
	/* VAR_OUTPUT (analog) */
	struct jsonWSS_client_info_typ ClientInfo[5];
	unsigned short ErrorID;
	plcstring ErrorString[321];
	/* VAR (analog) */
	struct jsonWSServer_Internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit AcknowledgeError;
	/* VAR_OUTPUT (digital) */
	plcbit Error;
} jsonWebSocketServer_typ;

typedef struct jsonHTTPServer
{
	/* VAR_INPUT (analog) */
	unsigned long pCache;
	plcstring ServiceNamePrefix[21];
	unsigned long BufferSize;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short ErrorID;
	plcstring ErrorString[321];
	/* VAR (analog) */
	struct jsonHTTPServer_Internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit AcknowledgeError;
	/* VAR_OUTPUT (digital) */
	plcbit Error;
} jsonHTTPServer_typ;

typedef struct jsonReadVariableNoCache
{
	/* VAR_INPUT (analog) */
	unsigned long pVariableName;
	unsigned long BufferSize;
	unsigned long MaxIterations;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	unsigned long pJSONObject;
	unsigned long JSONObjectLength;
	/* VAR (analog) */
	struct jsonReadVarNoCache_Int_typ internal;
} jsonReadVariableNoCache_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void jsonWebSocketServer(struct jsonWebSocketServer* inst);
_BUR_PUBLIC void jsonHTTPServer(struct jsonHTTPServer* inst);
_BUR_PUBLIC void jsonWriteVariable(struct jsonWriteVariable* inst);
_BUR_PUBLIC void jsonReadVariableList(struct jsonReadVariableList* inst);
_BUR_PUBLIC void jsonReadVariable(struct jsonReadVariable* inst);
_BUR_PUBLIC void jsonAddVariableToCache(struct jsonAddVariableToCache* inst);
_BUR_PUBLIC void jsonReadVariableNoCache(struct jsonReadVariableNoCache* inst);
_BUR_PUBLIC unsigned long jsonUnescape(unsigned long pDest, unsigned long pSrc, unsigned long maxLength, unsigned long reentry);
_BUR_PUBLIC unsigned long jsonEscape(unsigned long pDest, unsigned long pSrc, unsigned long maxLength, unsigned long reentry);


__asm__(".section \".plc\"");

/* Additional IEC dependencies */
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/tcpcomm/TCPComm.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/vartools/VarTools.var\\\" scope \\\"global\\\"\\n\"");

__asm__(".previous");

#ifdef __cplusplus
};
#endif
#endif /* _OMJSON_ */

