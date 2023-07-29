
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpService (*offers a webservice ; asynchronous execution*)
	VAR_INPUT
		enable : BOOL; (*enables execution, registers webservice; asynchronous execution*)
		send : BOOL; (*on positive edge response will be sent*)
		abort : BOOL; (*request handling aborts on positive edge*)
		option : UDINT; (*options such as service type, protocol version (HTTP/1.0 , HTTP/1.1), see httpOPTIONS_XXX*)
		pServiceName : UDINT; (*ressource name of webservice, see httpOPTION_SERVICE_TYPE_XXX*)
		pUri : UDINT; (*URI buffer string given as a pointer, an URI may look like "hello.cgi?name=myName"*)
		uriSize : UDINT; (*size of uri data puffer*)
		pRequestHeader : UDINT; (*pointer to httpRequestHeader_t, optional*)
		pRequestData : UDINT; (*request data puffer string given as a pointer*)
		requestDataSize : UDINT; (*size of request data buffer*)
		pResponseHeader : UDINT; (*pointer to httpResponseHeader_t, optional*)
		pResponseData : UDINT; (*response data string given as a pointer*)
		responseDataLen : UDINT; (*length of response data*)
		pStatistics : UDINT; (*pointer to httpStatistics_t, optional*)
		pStruct : UDINT; (*reserve*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY,0xXXXX = see help*)
		method : UINT; (*method of incoming request, see httpMETHOD_XXX*)
		requestDataLen : UDINT; (*length of request data*)
		phase : UINT; (*current phase of request response handling of the webservice, see httpPHASE_XXX*)
	END_VAR
	VAR
		_i_state : UDINT; (*internal variable*)
		_i_result : UINT; (*internal variable*)
		_ident : UDINT; (*internal variable*)
		_oldEnable : UDINT; (*internal variable*)
		_oldAbort : UDINT; (*internal variable*)
		_oldSend : UDINT; (*internal variable*)
		_state : UDINT; (*internal variable*)
		_internal : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpClient (*sends and recieves HTTP messages (web requests); asynchronous execution*)
	VAR_INPUT
		enable : BOOL; (*enables execution; asynchronous execution*)
		send : BOOL; (*sends request data on positive edge*)
		abort : BOOL; (*disconnects and resets client state on positive edge*)
		option : UDINT; (*options, e.g protocol version (HTTP1.0 / 1.1)*)
		pHost : UDINT; (*host name or ip of server to connect to given as a pointer*)
		hostPort : UINT; (*port number of server to connect to*)
		method : UDINT; (*request method see httpMETHOD_XXX*)
		pUri : UDINT; (*request uri given as a pointer, e.g. "/index.html" or "/hello.cgi?name=myName"*)
		pRequestHeader : UDINT; (*pointer to httpRequestHeader_t, optional*)
		pRequestData : UDINT; (*pointer to request data, typically string data*)
		requestDataLen : UDINT; (*length of request data*)
		pResponseHeader : UDINT; (*pointer to httpResponseHeader_t, optional*)
		pResponseData : UDINT; (*pointer to response data buffer, typically string data*)
		responseDataSize : UDINT; (*size of response data buffer*)
		pStatistics : UDINT; (*pointer to httpStatistics_t, optional*)
		pStruct : UDINT; (*reserve*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY,
0xXXXX = see help*)
		tcpStatus : UINT; (*status of the tcp connection*)
		httpStatus : UINT; (*status code of response, e.g. 200 for "OK", 404 for "Not Found"*)
		responseDataLen : UDINT; (*length of response (bytes)*)
		phase : UINT; (*current phase of request response handling of the webservice, see httpPHASE_XXX*)
	END_VAR
	VAR
		_i_state : UDINT; (*internal variable*)
		_i_result : UINT; (*internal variable*)
		_ident : UDINT; (*internal variable*)
		_oldEnable : UDINT; (*internal variable*)
		_oldAbort : UDINT; (*internal variable*)
		_oldSend : UDINT; (*internal variable*)
		_state : UDINT; (*internal variable*)
		_internal : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpsService (*offers a webservice over HTTPs; asynchronous execution*)
	VAR_INPUT
		enable : BOOL; (*enables execution, registers webservice; asynchronous execution*)
		send : BOOL; (*on positive edge response will be sent*)
		abort : BOOL; (*request handling aborts on positive edge*)
		option : UDINT; (*options such as service type, protocol version (HTTP/1.0 , HTTP/1.1), see httpOPTIONS_XXX*)
		pServiceName : UDINT; (*ressource name of webservice, see httpOPTION_SERVICE_TYPE_XXX*)
		pUri : UDINT; (*URI buffer string given as a pointer, an URI may look like "hello.cgi?name=myName"*)
		uriSize : UDINT; (*size of uri data puffer*)
		pRequestHeader : UDINT; (*pointer to httpRequestHeader_t, optional*)
		pRequestData : UDINT; (*request data puffer string given as a pointer*)
		requestDataSize : UDINT; (*size of request data buffer*)
		pResponseHeader : UDINT; (*pointer to httpResponseHeader_t, optional*)
		pResponseData : UDINT; (*response data string given as a pointer*)
		responseDataLen : UDINT; (*length of response data*)
		pStatistics : UDINT; (*pointer to httpStatistics_t, optional*)
		pStruct : UDINT; (*reserve*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY,0xXXXX = see help*)
		method : UINT; (*method of incoming request, see httpMETHOD_XXX*)
		requestDataLen : UDINT; (*length of request data*)
		phase : UINT; (*current phase of request response handling of the webservice, see httpPHASE_XXX*)
	END_VAR
	VAR
		_i_state : UDINT; (*internal variable*)
		_i_result : UINT; (*internal variable*)
		_ident : UDINT; (*internal variable*)
		_oldEnable : UDINT; (*internal variable*)
		_oldAbort : UDINT; (*internal variable*)
		_oldSend : UDINT; (*internal variable*)
		_state : UDINT; (*internal variable*)
		_internal : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpsClient (*sends and recieves HTTPs messages (web requests); asynchronous execution*)
	VAR_INPUT
		enable : BOOL; (*enables execution; asynchronous execution*)
		send : BOOL; (*sends request data on positive edge*)
		abort : BOOL; (*disconnects and resets client state on positive edge*)
		option : UDINT; (*options, e.g protocol version (HTTP1.0 / 1.1)*)
		sslCfgIdent : UDINT; (*identifier of the SSL configuration*)
		pHost : UDINT; (*host name or ip of server to connect to given as a pointer*)
		hostPort : UINT; (*port number of server to connect to*)
		method : UDINT; (*request method see httpMETHOD_XXX*)
		pUri : UDINT; (*request uri given as a pointer, e.g. "/index.html" or "/hello.cgi?name=myName"*)
		pRequestHeader : UDINT; (*pointer to httpRequestHeader_t, optional*)
		pRequestData : UDINT; (*pointer to request data, typically string data*)
		requestDataLen : UDINT; (*length of request data*)
		pResponseHeader : UDINT; (*pointer to httpResponseHeader_t, optional*)
		pResponseData : UDINT; (*pointer to response data buffer, typically string data*)
		responseDataSize : UDINT; (*size of response data buffer*)
		pStatistics : UDINT; (*pointer to httpStatistics_t, optional*)
		pStruct : UDINT; (*reserve*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY,
0xXXXX = see help*)
		tcpStatus : UINT; (*status of the ssl connection (tcp and ssl)*)
		httpStatus : UINT; (*status code of response, e.g. 200 for "OK", 404 for "Not Found"*)
		responseDataLen : UDINT; (*length of response (bytes)*)
		phase : UINT; (*current phase of request response handling of the webservice, see httpPHASE_XXX*)
	END_VAR
	VAR
		_i_state : UDINT; (*internal variable*)
		_i_result : UINT; (*internal variable*)
		_ident : UDINT; (*internal variable*)
		_oldEnable : UDINT; (*internal variable*)
		_oldAbort : UDINT; (*internal variable*)
		_oldSend : UDINT; (*internal variable*)
		_state : UDINT; (*internal variable*)
		_internal : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpUtf8ToString (*converts a UTF8 string in string with respect to given code page mapping*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string (UTF8 encoded), given as a pointer*)
		pDest : UDINT; (*destination buffer*)
		destSize : UDINT; (*size of destination buffer*)
		pMappingTable : UDINT; (*pointer to WSTRING[255],  mapping table for code page, see help*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*string length of the string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpStringToUtf8 (*converts a string in UTF8 string with respect to given code page mapping*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pDest : UDINT; (*destination buffer*)
		destSize : UDINT; (*size of destination buffer*)
		pMappingTable : UDINT; (*pointer to WSTRING[255],  mapping table for code page, see help*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*string length of the UTF8 string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpUtf8ToWString (*converts a UTF8 encoded string in wide character string*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pDest : UDINT; (*destination buffer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*wide character string length*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpWStringToUtf8 (*converts a wide character string in UTF8 string*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pDest : UDINT; (*destination buffer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*string length of the UTF8 encoded string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpDecodeBase64 (*decodes base64 encoded string in binary data or string*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*encoded string, given as a pointer*)
		srcLen : UDINT; (*length of encoded string*)
		pDest : UDINT; (*destination buffer, given as a pointer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*length of decoded data*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpEncodeBase64 (*encodes binary data or a string in a base64 encoded string*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input data, given as a pointer*)
		srcLen : UDINT; (*length of input data*)
		pDest : UDINT; (*destination buffer, given as a pointer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*length of encoded string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpEncodeUrl (*encodes special chars in the given string according the URL encoding*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pDest : UDINT; (*destination buffer, given as a pointer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*length of encoded string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpDecodeUrl (*decodes an URL encoded string*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pDest : UDINT; (*destination buffer, given as a pointer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*length of decoded string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpGetParamUrl (*retrieves the string value of the given parameter.*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*input string, given as a pointer*)
		pParam : UDINT; (*search string given as a pointer*)
		pValue : UDINT; (*value string buffer given as a pointer*)
		valueSize : UDINT; (*size of value buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		valueLen : UDINT; (*length of value string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpSetParamUrl (*adds a parameter and its value with respect to URL encoding*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pParam : UDINT; (*name string given as a pointer*)
		pValue : UDINT; (*value string buffer given as a pointer*)
		pDest : UDINT; (*resulting string buffer given as pointer*)
		destSize : UDINT; (*size of destination buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		destLen : UDINT; (*length of resulted string*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpSetBoundary (*adds the boundary information to the HTTP message header*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pStruct : UDINT; (*pointer to the header structure (httpRequestHeader_t or httpResponseHeader_t)*)
		pBoundary : UDINT; (*boundary string given as a pointer. A boundary has no more than 70 chars and is unambiguous*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpGetBoundary (*retrieves the boundary value of the given header structure*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pStruct : UDINT; (*pointer to the header structure (httpRequestHeader_t or httpResponseHeader_t)*)
		pBoundary : UDINT; (*boundary string buffer given as a pointer*)
		boundarySize : UDINT; (*size of boundary buffer, preferrably slighly more than 70 bytes*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		boundaryLen : UDINT; (*length of the retrieved boundary if any*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpSetMultipartMessage (*sets respectivly appends a multipart message*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pDest : UDINT; (*destination buffer string given as a pointer*)
		destSize : UDINT; (*size of destination buffer*)
		pBoundary : UDINT; (*boundary string to seperate multipart message given as a pointer*)
		pMessageHeader : UDINT; (*header string given as a pointer, contains header for multipart message, if any*)
		pMessageData : UDINT; (*message body given as a pointer, contains data for multipart message*)
		messageDataLen : UDINT; (*length of message data*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		_messageLen : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK httpGetMultipartMessage (*gets next multipart message information on each call*)
	VAR_INPUT
		enable : BOOL; (*enables execution*)
		pSrc : UDINT; (*source string given as a pointer, contains one or more multipart messages*)
		pBoundary : UDINT; (*boundary string given as a pointer, seperator of the multipart messages*)
		pMessageHeader : UDINT; (*string buffer for a optional message header given as a pointer*)
		messageHeaderSize : UDINT; (*size of message header buffer*)
		pMessageData : UDINT; (*string buffer for message data given as a pointer*)
		messageDataSize : UDINT; (*size of message data buffer*)
	END_VAR
	VAR_OUTPUT
		status : UINT; (*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		messageHeaderLen : UDINT; (*length of current header, if any*)
		messageDataLen : UDINT; (*length of current data*)
		messageLen : UDINT; (*offset to current message ending*)
	END_VAR
	VAR
		_internal : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
