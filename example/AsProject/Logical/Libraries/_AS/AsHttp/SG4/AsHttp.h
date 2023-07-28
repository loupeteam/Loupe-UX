/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASHTTP_
#define _ASHTTP_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define httpPHASE_WAITING 4U
 #define httpPHASE_RECEIVED 3U
 #define httpPHASE_RECEIVING 2U
 #define httpPHASE_SENDING 1U
 #define httpPHASE_NOT_CONNECTED 0U
 #define httpOPTION_SERVICE_TYPE_LEAF 8U
 #define httpOPTION_SERVICE_TYPE_EXT 6U
 #define httpOPTION_SERVICE_TYPE_NAME 2U
 #define httpOPTION_SERVICE_TYPE_ROOT 4U
 #define httpOPTION_HTTP_11 1U
 #define httpOPTION_HTTP_10 0U
 #define httpMETHOD_DELETE 4U
 #define httpMETHOD_PUT 3U
 #define httpMETHOD_POST 2U
 #define httpMETHOD_GET 1U
 #define httpERR_SYSTEM 35579U
 #define httpERR_INVALID_SSL_CONFIG 35568U
 #define httpERR_SSL_HANDSHAKE_FAILED 35567U
 #define httpERR_ILLEGAL_CHARACTERS 35566U
 #define httpERR_NOT_FOUND 35565U
 #define httpERR_CLIENT_TCP_DISCONNECTED 35564U
 #define httpERR_CLIENT_TCP_INVALID_HOST 35563U
 #define httpERR_CLIENT_TCP_CONN_FAILED 35562U
 #define httpERR_CLIENT_TCP_CONN_CLOSED 35561U
 #define httpERR_CLIENT_NO_MORE_IDENTS 35560U
 #define httpERR_CLIENT_ERR_SOCKET_CREATE 35559U
 #define httpERR_SERVICE_LINK_FAILED 35558U
 #define httpERR_SERVICE_NO_WEBSERVER 35557U
 #define httpERR_METHOD_UNSUPPORTED 35556U
 #define httpERR_NO_DATA 35555U
 #define httpERR_INVALID_PARAM 35554U
 #define httpERR_HEADER_SIZE_USERLINE 35553U
 #define httpERR_HEADER_SIZE_RAW 35552U
 #define httpERR_DATA_SIZE 35551U
 #define httpERR_BUFFER_SIZE 35550U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short httpPHASE_WAITING;
 _GLOBAL_CONST unsigned short httpPHASE_RECEIVED;
 _GLOBAL_CONST unsigned short httpPHASE_RECEIVING;
 _GLOBAL_CONST unsigned short httpPHASE_SENDING;
 _GLOBAL_CONST unsigned short httpPHASE_NOT_CONNECTED;
 _GLOBAL_CONST unsigned short httpOPTION_SERVICE_TYPE_LEAF;
 _GLOBAL_CONST unsigned short httpOPTION_SERVICE_TYPE_EXT;
 _GLOBAL_CONST unsigned short httpOPTION_SERVICE_TYPE_NAME;
 _GLOBAL_CONST unsigned short httpOPTION_SERVICE_TYPE_ROOT;
 _GLOBAL_CONST unsigned short httpOPTION_HTTP_11;
 _GLOBAL_CONST unsigned short httpOPTION_HTTP_10;
 _GLOBAL_CONST unsigned short httpMETHOD_DELETE;
 _GLOBAL_CONST unsigned short httpMETHOD_PUT;
 _GLOBAL_CONST unsigned short httpMETHOD_POST;
 _GLOBAL_CONST unsigned short httpMETHOD_GET;
 _GLOBAL_CONST unsigned short httpERR_SYSTEM;
 _GLOBAL_CONST unsigned short httpERR_INVALID_SSL_CONFIG;
 _GLOBAL_CONST unsigned short httpERR_SSL_HANDSHAKE_FAILED;
 _GLOBAL_CONST unsigned short httpERR_ILLEGAL_CHARACTERS;
 _GLOBAL_CONST unsigned short httpERR_NOT_FOUND;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_TCP_DISCONNECTED;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_TCP_INVALID_HOST;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_TCP_CONN_FAILED;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_TCP_CONN_CLOSED;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_NO_MORE_IDENTS;
 _GLOBAL_CONST unsigned short httpERR_CLIENT_ERR_SOCKET_CREATE;
 _GLOBAL_CONST unsigned short httpERR_SERVICE_LINK_FAILED;
 _GLOBAL_CONST unsigned short httpERR_SERVICE_NO_WEBSERVER;
 _GLOBAL_CONST unsigned short httpERR_METHOD_UNSUPPORTED;
 _GLOBAL_CONST unsigned short httpERR_NO_DATA;
 _GLOBAL_CONST unsigned short httpERR_INVALID_PARAM;
 _GLOBAL_CONST unsigned short httpERR_HEADER_SIZE_USERLINE;
 _GLOBAL_CONST unsigned short httpERR_HEADER_SIZE_RAW;
 _GLOBAL_CONST unsigned short httpERR_DATA_SIZE;
 _GLOBAL_CONST unsigned short httpERR_BUFFER_SIZE;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct httpHeaderLine_t
{	plcstring name[51];
	plcstring value[81];
} httpHeaderLine_t;

typedef struct httpRawHeader_t
{	unsigned long pData;
	unsigned long dataSize;
	unsigned long dataLen;
} httpRawHeader_t;

typedef struct httpResponseHeader_t
{	plcstring protocol[21];
	plcstring status[281];
	plcstring contentType[101];
	unsigned long contentLength;
	plcstring connection[81];
	plcstring keepAlive[81];
	struct httpHeaderLine_t userLine[8];
	struct httpRawHeader_t rawHeader;
} httpResponseHeader_t;

typedef struct httpRequestHeader_t
{	plcstring protocol[21];
	plcstring host[281];
	plcstring contentType[101];
	unsigned long contentLength;
	plcstring connection[81];
	plcstring keepAlive[81];
	struct httpHeaderLine_t userLine[8];
	struct httpRawHeader_t rawHeader;
} httpRequestHeader_t;

typedef struct httpStatistics_t
{	unsigned long requestCounter;
	plcdt timeOfLastRequest;
	unsigned long responseCounter;
	plcdt timeOfLastResponse;
	unsigned long errorCounter;
	unsigned long lastError;
} httpStatistics_t;

typedef struct httpService
{
	/* VAR_INPUT (analog) */
	unsigned long option;
	unsigned long pServiceName;
	unsigned long pUri;
	unsigned long uriSize;
	unsigned long pRequestHeader;
	unsigned long pRequestData;
	unsigned long requestDataSize;
	unsigned long pResponseHeader;
	unsigned long pResponseData;
	unsigned long responseDataLen;
	unsigned long pStatistics;
	unsigned long pStruct;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short method;
	unsigned long requestDataLen;
	unsigned short phase;
	/* VAR (analog) */
	unsigned long _i_state;
	unsigned short _i_result;
	unsigned long _ident;
	unsigned long _oldEnable;
	unsigned long _oldAbort;
	unsigned long _oldSend;
	unsigned long _state;
	unsigned long _internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit send;
	plcbit abort;
} httpService_typ;

typedef struct httpClient
{
	/* VAR_INPUT (analog) */
	unsigned long option;
	unsigned long pHost;
	unsigned short hostPort;
	unsigned long method;
	unsigned long pUri;
	unsigned long pRequestHeader;
	unsigned long pRequestData;
	unsigned long requestDataLen;
	unsigned long pResponseHeader;
	unsigned long pResponseData;
	unsigned long responseDataSize;
	unsigned long pStatistics;
	unsigned long pStruct;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short tcpStatus;
	unsigned short httpStatus;
	unsigned long responseDataLen;
	unsigned short phase;
	/* VAR (analog) */
	unsigned long _i_state;
	unsigned short _i_result;
	unsigned long _ident;
	unsigned long _oldEnable;
	unsigned long _oldAbort;
	unsigned long _oldSend;
	unsigned long _state;
	unsigned long _internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit send;
	plcbit abort;
} httpClient_typ;

typedef struct httpsService
{
	/* VAR_INPUT (analog) */
	unsigned long option;
	unsigned long pServiceName;
	unsigned long pUri;
	unsigned long uriSize;
	unsigned long pRequestHeader;
	unsigned long pRequestData;
	unsigned long requestDataSize;
	unsigned long pResponseHeader;
	unsigned long pResponseData;
	unsigned long responseDataLen;
	unsigned long pStatistics;
	unsigned long pStruct;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short method;
	unsigned long requestDataLen;
	unsigned short phase;
	/* VAR (analog) */
	unsigned long _i_state;
	unsigned short _i_result;
	unsigned long _ident;
	unsigned long _oldEnable;
	unsigned long _oldAbort;
	unsigned long _oldSend;
	unsigned long _state;
	unsigned long _internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit send;
	plcbit abort;
} httpsService_typ;

typedef struct httpsClient
{
	/* VAR_INPUT (analog) */
	unsigned long option;
	unsigned long sslCfgIdent;
	unsigned long pHost;
	unsigned short hostPort;
	unsigned long method;
	unsigned long pUri;
	unsigned long pRequestHeader;
	unsigned long pRequestData;
	unsigned long requestDataLen;
	unsigned long pResponseHeader;
	unsigned long pResponseData;
	unsigned long responseDataSize;
	unsigned long pStatistics;
	unsigned long pStruct;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned short tcpStatus;
	unsigned short httpStatus;
	unsigned long responseDataLen;
	unsigned short phase;
	/* VAR (analog) */
	unsigned long _i_state;
	unsigned short _i_result;
	unsigned long _ident;
	unsigned long _oldEnable;
	unsigned long _oldAbort;
	unsigned long _oldSend;
	unsigned long _state;
	unsigned long _internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit send;
	plcbit abort;
} httpsClient_typ;

typedef struct httpUtf8ToString
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	unsigned long pMappingTable;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpUtf8ToString_typ;

typedef struct httpStringToUtf8
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	unsigned long pMappingTable;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpStringToUtf8_typ;

typedef struct httpUtf8ToWString
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpUtf8ToWString_typ;

typedef struct httpWStringToUtf8
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpWStringToUtf8_typ;

typedef struct httpDecodeBase64
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long srcLen;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpDecodeBase64_typ;

typedef struct httpEncodeBase64
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long srcLen;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpEncodeBase64_typ;

typedef struct httpEncodeUrl
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpEncodeUrl_typ;

typedef struct httpDecodeUrl
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpDecodeUrl_typ;

typedef struct httpGetParamUrl
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pParam;
	unsigned long pValue;
	unsigned long valueSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long valueLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpGetParamUrl_typ;

typedef struct httpSetParamUrl
{
	/* VAR_INPUT (analog) */
	unsigned long pParam;
	unsigned long pValue;
	unsigned long pDest;
	unsigned long destSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long destLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpSetParamUrl_typ;

typedef struct httpSetBoundary
{
	/* VAR_INPUT (analog) */
	unsigned long pStruct;
	unsigned long pBoundary;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpSetBoundary_typ;

typedef struct httpGetBoundary
{
	/* VAR_INPUT (analog) */
	unsigned long pStruct;
	unsigned long pBoundary;
	unsigned long boundarySize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long boundaryLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpGetBoundary_typ;

typedef struct httpSetMultipartMessage
{
	/* VAR_INPUT (analog) */
	unsigned long pDest;
	unsigned long destSize;
	unsigned long pBoundary;
	unsigned long pMessageHeader;
	unsigned long pMessageData;
	unsigned long messageDataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned long _messageLen;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpSetMultipartMessage_typ;

typedef struct httpGetMultipartMessage
{
	/* VAR_INPUT (analog) */
	unsigned long pSrc;
	unsigned long pBoundary;
	unsigned long pMessageHeader;
	unsigned long messageHeaderSize;
	unsigned long pMessageData;
	unsigned long messageDataSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long messageHeaderLen;
	unsigned long messageDataLen;
	unsigned long messageLen;
	/* VAR (analog) */
	unsigned long _internal;
	/* VAR_INPUT (digital) */
	plcbit enable;
} httpGetMultipartMessage_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void httpService(struct httpService* inst);
_BUR_PUBLIC void httpClient(struct httpClient* inst);
_BUR_PUBLIC void httpsService(struct httpsService* inst);
_BUR_PUBLIC void httpsClient(struct httpsClient* inst);
_BUR_PUBLIC void httpUtf8ToString(struct httpUtf8ToString* inst);
_BUR_PUBLIC void httpStringToUtf8(struct httpStringToUtf8* inst);
_BUR_PUBLIC void httpUtf8ToWString(struct httpUtf8ToWString* inst);
_BUR_PUBLIC void httpWStringToUtf8(struct httpWStringToUtf8* inst);
_BUR_PUBLIC void httpDecodeBase64(struct httpDecodeBase64* inst);
_BUR_PUBLIC void httpEncodeBase64(struct httpEncodeBase64* inst);
_BUR_PUBLIC void httpEncodeUrl(struct httpEncodeUrl* inst);
_BUR_PUBLIC void httpDecodeUrl(struct httpDecodeUrl* inst);
_BUR_PUBLIC void httpGetParamUrl(struct httpGetParamUrl* inst);
_BUR_PUBLIC void httpSetParamUrl(struct httpSetParamUrl* inst);
_BUR_PUBLIC void httpSetBoundary(struct httpSetBoundary* inst);
_BUR_PUBLIC void httpGetBoundary(struct httpGetBoundary* inst);
_BUR_PUBLIC void httpSetMultipartMessage(struct httpSetMultipartMessage* inst);
_BUR_PUBLIC void httpGetMultipartMessage(struct httpGetMultipartMessage* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASHTTP_ */

