(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: OMJSON
 * File: OMJSON.fun
 * Author: davidblackburn
 * Created: September 22, 2014
 ********************************************************************
 * Functions and function blocks of library OMJSON
 ********************************************************************)

FUNCTION_BLOCK jsonWebSocketServer (*Serve variables via JSON and WebSockets*) (*$GROUP=User*)
	VAR_INPUT
		pCacheArray : UDINT; (*Address of the variable cache array. Number of elements in array needs to be equal to numClients*)
		maxClients : UINT; (*Number of clients supported at a time. 0 defaults to 1*)
		ServerIP : STRING[TCPCOMM_STRLEN_IPADDRESS]; (*IP Address of the server*)
		ServerPort : UINT; (*Port to be used by server*)
		BufferSize : UDINT; (*Size of buffers. N buffers will be allocated, so the total memory requirement is N*BufferSize.*)
		MaxIterations : UDINT; (*Maximum number of iterations for looping through variables.*)
		AcknowledgeError : BOOL; (*Acknowledge errors. Automatically reset by FUB.*)
		Timeout : UDINT; (*Max time in miliseconds since last message from client before forcing disconnect*)
	END_VAR
	VAR_OUTPUT
		ClientInfo : ARRAY[0..JSON_MAI_CLIENTS] OF jsonWSS_client_info_typ;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[JSON_STRLEN_ERROR];
	END_VAR
	VAR
		internal : jsonWSServer_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonWSConnect (*Negotiate a new WebSocket connection*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pInputMessage : UDINT;
		pOutputMessage : UDINT;
		MaxOutputMessageLength : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		OutputMessageLength : UDINT;
	END_VAR
	VAR
		internal : jsonWSConnect_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonWSDecode (*Decode a WebSocket frame*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pFrame : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		FIN : BOOL;
		RSV : USINT;
		OpCode : USINT;
		MASK : BOOL;
		MaskingKey : ARRAY[0..3] OF USINT;
		pPayloadData : UDINT;
		HeaderLength : UDINT;
		PayloadLength : UDINT;
		FrameLength : UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonWSEncode (*Encode data into a WebSocket frame*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pFrame : UDINT;
		MaxFrameLength : UDINT;
		FIN : BOOL;
		RSV : USINT;
		OpCode : USINT;
		MASK : BOOL; (*NOT SUPPORTED*)
		PayloadLength : UDINT;
		MaskingKey : ARRAY[0..3] OF USINT; (*NOT SUPPORTED*)
		pPayloadData : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		FrameLength : UDINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonHTTPServer (*Serve variables via JSON and HTTP*) (*$GROUP=User*)
	VAR_INPUT
		pCache : UDINT; (*Address of the variable cache*)
		ServiceNamePrefix : STRING[JSON_STRLEN_SERVICENAMEPREFIX]; (*Optional service name prefix*)
		BufferSize : UDINT; (*Size of buffers. N buffers will be allocated, so the total memory requirement is N*BufferSize.*)
		MaxIterations : UDINT; (*Maximum number of iterations for looping through variables.*)
		AcknowledgeError : BOOL; (*Acknowledge errors. Automatically reset by FUB.*)
	END_VAR
	VAR_OUTPUT
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[JSON_STRLEN_ERROR];
	END_VAR
	VAR
		internal : jsonHTTPServer_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonWriteVariable (*Write variable values received as a JSON object*) (*$GROUP=User*)
	VAR_INPUT
		pJSONObject : UDINT; (*Address of the JSON object*)
		MaxJSONObjectLength : UDINT; (*Maximum length of the JSON object*)
		MaxIterations : UDINT; (*Maximum number of iterations for expanding structures*)
	END_VAR
	VAR_OUTPUT
		Status : UINT; (*0 = Done, 65535 = Busy, other values are errors*)
	END_VAR
	VAR
		internal : jsonWriteVariable_Int_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonReadVariableList (*Convert a list of variables into a JSON object*) (*$GROUP=User*)
	VAR_INPUT
		pVariableList : UDINT;
		pCache : UDINT;
		BufferSize : UDINT;
		MaxIterations : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		pJSONObject : UDINT;
		JSONObjectLength : UDINT;
	END_VAR
	VAR
		internal : jsonReadVariableList_Int_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonReadVariable (*Convert a variable into a JSON object*) (*$GROUP=User*)
	VAR_INPUT
		pVariableName : UDINT;
		pCache : UDINT;
		BufferSize : UDINT;
		MaxIterations : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		pJSONObject : UDINT;
		JSONObjectLength : UDINT;
	END_VAR
	VAR
		internal : jsonReadVariable_Int_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonAddVariableToCache (*Add a variable to the JSON variable cache*) (*$GROUP=User*)
	VAR_INPUT
		pVariableName : UDINT;
		pCache : UDINT;
		MaxIterations : UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
		iVariable : UINT;
	END_VAR
	VAR
		internal : jsonAddVariableToCache_Int_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK jsonReadVariableNoCache (*Convert a variable into a JSON object without caching*) (*$GROUP=User*)
	VAR_INPUT
		pVariableName : UDINT; (*Address of name of variable to convert to JSON*)
		BufferSize : UDINT; (*Size of internal data buffer*)
		MaxIterations : UDINT; (*Maximum number of iterations for expanding structures*)
	END_VAR
	VAR_OUTPUT
		Status : UINT; (*0 = Done, 65535 = Busy, other values are errors*)
		pJSONObject : UDINT; (*Address of the generated JSON object*)
		JSONObjectLength : UDINT; (*Length of the generated JSON object*)
	END_VAR
	VAR
		internal : jsonReadVarNoCache_Int_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION jsonUnescape : UDINT (*Unescape JSON string*)
	VAR_INPUT
		pDest : UDINT;
		pSrc : UDINT;
		maxLength : UDINT;
		reentry : UDINT;
	END_VAR
END_FUNCTION

FUNCTION jsonEscape : UDINT (*Escape JSON string*)
	VAR_INPUT
		pDest : UDINT;
		pSrc : UDINT;
		maxLength : UDINT;
		reentry : UDINT;
	END_VAR
END_FUNCTION
