                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbConnect						(*connects to an existing database; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		pServerName		: UDINT;				(*pointer to IP address or host name of the database server, e.g. "sun.galaxy.one"*)
		pUserName		: UDINT;				(*pointer to the user name*)
		pPassword		: UDINT;				(*pointer to the user password*)
		pDatabaseName	: UDINT;				(*pointer to the name of the database*)
		databaseSystem	: UDINT;				(*database system*)
	END_VAR
	
	VAR_OUTPUT
		status		 	: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError		 	: INT;					(*error number of the database*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbConnectEnc						(*connects to an existing database using given encoding; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		pServerName		: UDINT;				(*pointer to IP address or host name of the database server, e.g. "sun.galaxy.one"*)
		pUserName		: UDINT;				(*pointer to the user name*)
		pPassword		: UDINT;				(*pointer to the user password*)
		pDatabaseName	: UDINT;				(*pointer to the name of the database*)
		databaseSystem	: UDINT;				(*database system*)
		pEncoding		: UDINT;				(*character encoding*)
	END_VAR
	
	VAR_OUTPUT
		status		 	: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError		 	: INT;					(*error number of the database*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbExecuteSql						(*executes an SQL statement; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
		pSqlStatement	: UDINT;				(*pointer to the SQL statement*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbGetAffectedRows				(*determines the number of rows affected by an INSERT, UPDATE or DELETE SQL statement; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
		affectedRows: UDINT;					(*number of affected rows*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbGetColumnCount					(*determines the number of columns in the result set of an SELECT SQL statement; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
		columnCount 	: INT;					(*number of columns in the result set*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbFetchNextRow					(*fetches the next row into the memory; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbGetData						(*gets the data of the current row of the given column*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
		columnIdx		: UDINT;				(*the data column index*)
		dataType		: INT;					(*type of the data*)
		pData			: UDINT;				(*pointer to the data buffer*)
		dataSize		: UDINT;				(*size of the data buffer*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
		actDataSize		: UDINT;				(*size of the written data or needed data size*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbDisconnect						(*disconnects the connection to the database; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbGetInfo						(*gets database information; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
		infoType		: UINT;					(*type of information*)
		pServerInfo		: UDINT;				(*pointer to buffer for the database information*)
		serverInfoSize	: UDINT;				(*size of the buffer*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
		actServerInfoSize	: UINT;				(*current size of database information or needed size*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK dbGetErrorMessage				(*gets the current database error message; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;					(*enables execution*)
		connectionIdent	: UDINT;				(*identifier of the database connection*)
		pErrorMessage	: UDINT;				(*buffer for the database error message*)
		errorMessageSize: UDINT;				(*size of the buffer*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		dbError			: INT;					(*error number of the database*)
		sqlState		: ARRAY [0..5] OF USINT;(*five-character SQLSTATE code*)
		nativeError		: DINT;					(*native error code, specific to the data source*)
		actErrorMessageSize	: INT;				(*current size for the error message of the database or necessary size*)
	END_VAR
	
	VAR
		_statemachine	: UINT;					(*internal variable*)
		_result			: UINT;					(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
