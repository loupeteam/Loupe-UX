
TYPE
	httpResponseHeader_t : 	STRUCT  (*response header structure*)
		protocol : STRING[20]; (*HTTP/1.0 or HTTP/1.1*)
		status : STRING[280]; (*HTTP status line e.g. "200 OK" , "404 Not Found"*)
		contentType : STRING[100]; (*MIME type specifying message body, e.g. "text/html"*)
		contentLength : UDINT; (*length of message data, should be equal to responseDataLen, optional input*)
		connection : STRING[80]; (*valid tokens are "Close" or "Keep-Alive", default is "Close"*)
		keepAlive : STRING[80]; (*e.g. "timeout=5, max=100", optional*)
		userLine : ARRAY[0..7]OF httpHeaderLine_t; (*userspecific headerlines, optional*)
		rawHeader : httpRawHeader_t; (*interface to add / get formatted headers, optional*)
	END_STRUCT;
	httpRequestHeader_t : 	STRUCT  (*request header structure*)
		protocol : STRING[20]; (*protocol version e.g. "HTTP/1.0" or "HTTP/1.1", optional input*)
		host : STRING[280]; (*host name or ip address of the server and port number if <> 80, optional input*)
		contentType : STRING[100]; (*MIME type specifying message body, e.g. "text/html", optional input*)
		contentLength : UDINT; (*length of message data, should be equal to requestDataLen, optional input*)
		connection : STRING[80]; (*valid tokens are "Close" or "Keep-Alive", default is "Close", optional input*)
		keepAlive : STRING[80]; (*e.g. "timeout=5, max=100", optional input*)
		userLine : ARRAY[0..7]OF httpHeaderLine_t; (*userspecific headerlines, optional*)
		rawHeader : httpRawHeader_t; (*interface to add / get formatted headers, optional*)
	END_STRUCT;
	httpHeaderLine_t : 	STRUCT  (*structure containing information of one header line*)
		name : STRING[50]; (*header field name, e.g. "User-Agent" to get / set the user-agent header entry*)
		value : STRING[80]; (*header field value, e.g. "B&R Client"*)
	END_STRUCT;
	httpRawHeader_t : 	STRUCT  (*buffer handling structure for raw (formatted) headers*)
		pData : UDINT; (*pointer to data buffer, where the header is copied*)
		dataSize : UDINT; (*max. length of data buffer in bytes*)
		dataLen : UDINT; (*length of the header bytes copied out*)
	END_STRUCT;
	httpStatistics_t : 	STRUCT  (*informational structure*)
		requestCounter : UDINT; (*counts requests*)
		timeOfLastRequest : DATE_AND_TIME; (*timestamp of last request*)
		responseCounter : UDINT; (*counts responses*)
		timeOfLastResponse : DATE_AND_TIME; (*timestamp of last response*)
		errorCounter : UDINT; (*counts errors, e.g. connection errors, aborts *)
		lastError : UDINT; (*error number, if any*)
	END_STRUCT;
END_TYPE
