(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: OMJSON
 * File: OMJSON.typ
 * Author: davidblackburn
 * Created: September 22, 2014
 ********************************************************************
 * Data types of library OMJSON
 ********************************************************************)

TYPE
	JSON_WS_OPCODE_enum : 
		(
		JSON_WS_OPCODE_CONTINUATION := 0, (*Not supported*)
		JSON_WS_OPCODE_TEXT := 1,
		JSON_WS_OPCODE_BINARY := 2, (*Not supported*)
		JSON_WS_OPCODE_CLOSE := 8,
		JSON_WS_OPCODE_PING := 9, (*Not supported*)
		JSON_WS_OPCODE_PONG := 10 (*Not supported*)
		);
	JSON_ERR_enum : 
		(
		JSON_ERR_INVALIDINPUT := 50000,
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
		);
	jsonWSS_client_info_typ : 	STRUCT 
		Connected : BOOL;
		TimeSinceLastRequest_ms : UDINT;
		ClientIP : STRING[TCPCOMM_STRLEN_IPADDRESS];
		ClientPort : UINT;
	END_STRUCT;
	jsonWSS_client_debug_typ : 	STRUCT 
		socketConnectCount : DINT;
		websocketConnectCount : DINT;
		socketDisconnectCountTimeout : DINT;
		socketDisconnectCountOpcode : DINT;
		socketDisconnectCountError : DINT;
		socketDisconnectCountRecvLength0 : DINT;
		socketInvalidCountError : DINT;
		noDataCount : DINT;
		dataCount : DINT;
		justRightCount : DINT;
		tooBigCount : DINT;
		tooSmallCount : DINT;
		doubleDataCount : DINT;
		oldDataReceived : BOOL;
	END_STRUCT;
	jsonWSServer_int_client_typ : 	STRUCT 
		tcpStream : TCPStream_typ;
		pReceiveData : UDINT;
		pSendData : UDINT;
		messageBuffer : datbufBuffer_typ;
		wsConnect : jsonWSConnect;
		wsConnected : BOOL;
		wsDecode : jsonWSDecode;
		wsEncode : jsonWSEncode;
		writeVariable : jsonWriteVariable;
		readVariableList : jsonReadVariableList;
		debug : jsonWSS_client_debug_typ;
		excessDataLength : DINT;
		requestTimer : TON_10ms;
		pCache : REFERENCE TO jsonCache_typ;
	END_STRUCT;
	jsonWSServer_Internal_typ : 	STRUCT 
		initialized : BOOL;
		tcpServer : TCPConnectionMgr_typ;
		client : ARRAY[0..JSON_MAI_CLIENTS]OF jsonWSServer_int_client_typ;
		requestTimer : TON_10ms;
		iClient : UINT;
		connectedClients : UINT;
		maxClients : UINT;
	END_STRUCT;
	jsonHTTPServer_Int_Debug_typ : 	STRUCT 
		readSendCommand : BOOL;
	END_STRUCT;
	jsonHTTPServer_Int_Write_typ : 	STRUCT 
		webService : httpService;
		pUri : UDINT;
		pRequestData : UDINT;
		ResponseHeader : httpResponseHeader_t;
		processed : BOOL;
		writeVariable : jsonWriteVariable;
	END_STRUCT;
	jsonHTTPServer_Int_Read_typ : 	STRUCT 
		webService : httpService;
		pUri : UDINT;
		pRequestData : UDINT;
		ResponseHeader : httpResponseHeader_t;
		processed : BOOL;
		readVariableList : jsonReadVariableList;
	END_STRUCT;
	jsonHTTPServer_Internal_typ : 	STRUCT 
		initialized : BOOL;
		read : jsonHTTPServer_Int_Read_typ;
		write : jsonHTTPServer_Int_Write_typ;
		debug : jsonHTTPServer_Int_Debug_typ;
	END_STRUCT;
	jsonWSConnect_Internal_typ : 	STRUCT 
		encodeBase64 : httpEncodeBase64;
	END_STRUCT;
	JSON_TYPE_enum : 
		(
		JSON_TYPE_INVALID := 0,
		JSON_TYPE_OBJECT_ELEMENT,
		JSON_TYPE_ARRAY_ELEMENT
		);
	jsonStructLevel_typ : 	STRUCT 
		variable : varVariable_typ;
		iItem : UINT;
		jsonType : JSON_TYPE_enum;
	END_STRUCT;
	jsonWriteVariable_Int_typ : 	STRUCT 
		initialized : BOOL;
		pJSONObject : UDINT;
		pChar : UDINT;
		iStructLevel : INT;
		structLevel : ARRAY[0..JSON_MAI_STRUCTLEVEL]OF jsonStructLevel_typ;
	END_STRUCT;
	jsonReadVariableList_Int_typ : 	STRUCT 
		initialized : BOOL;
		outputBuffer : datbufBuffer_typ;
		readVariable : jsonReadVariable;
	END_STRUCT;
	jsonReadVariable_Int_typ : 	STRUCT 
		initialized : BOOL;
		outputBuffer : datbufBuffer_typ;
		variableName : STRING[VAR_STRLEN_NAME];
		addVariableToCache : jsonAddVariableToCache;
	END_STRUCT;
	jsonAddVariableToCache_Int_typ : 	STRUCT 
		initialized : BOOL;
		iStructLevel : INT;
		structLevel : ARRAY[0..JSON_MAI_STRUCTLEVEL]OF jsonStructLevel_typ;
	END_STRUCT;
	jsonCache_typ : 	STRUCT 
		iVariable : UINT;
		variable : ARRAY[0..JSON_MAI_CACHEVAR]OF jsonCacheVariable_typ;
		iItem : UINT;
		item : ARRAY[0..JSON_MAI_CACHEITEM]OF jsonCacheItem_typ;
	END_STRUCT;
	jsonCacheVariable_typ : 	STRUCT 
		name : STRING[VAR_STRLEN_NAME];
		iStart : UINT;
		iEnd : UINT;
	END_STRUCT;
	jsonCacheItem_typ : 	STRUCT 
		prefix : STRING[JSON_STRLEN_PREFIX];
		variable : varVariable_typ;
		suffix : STRING[JSON_STRLEN_SUFFIX];
	END_STRUCT;
	jsonReadVarNoCache_Int_typ : 	STRUCT 
		initialized : BOOL;
		outputBuffer : datbufBuffer_typ;
		iStructLevel : INT;
		structLevel : ARRAY[0..JSON_MAI_STRUCTLEVEL]OF jsonStructLevel_typ;
	END_STRUCT;
END_TYPE
