(*
 * File: WSMgr.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of WebSocket, licensed under the MIT License.
 *)
TYPE
	WSConnectionManager_typ : 	STRUCT 
		in : WSConnectionManager_In_typ;
		out : WSConnectionManager_Out_typ;
		internal : WSConnectionManager_Internal_typ;
	END_STRUCT;
	WSConnectionManager_In_typ : 	STRUCT 
		cmd : WSConnectionManager_In_Cmd_typ;
		cfg : WSConnectionManager_In_Cfg_typ;
	END_STRUCT;
	WSConnectionManager_In_Cmd_typ : 	STRUCT 
		enable : BOOL;
		acknowledgeConnection : BOOL;
		acknowledgeError : BOOL;
	END_STRUCT;
	WSConnectionManager_In_Cfg_typ : 	STRUCT 
		mode : WS_Mode_enum;
		localIPAddress : STRING[TCPCOMM_STRLEN_IPADDRESS];
		localPort : UDINT;
		remoteIPAddress : STRING[TCPCOMM_STRLEN_IPADDRESS];
		remotePort : UDINT;
		sendBufferSize : UDINT;
		useSSL : BOOL;
		sslCertificate : UDINT;
	END_STRUCT;
	WSConnectionManager_Out_typ : 	STRUCT 
		newConnectionAvailable : BOOL;
		connection : WSConnectionManager_Desc_typ;
		error : BOOL;
		errorID : UINT;
		errorString : STRING[WS_STRLEN_ERRORSTRING];
	END_STRUCT;
	WSConnectionManager_Desc_typ : 	STRUCT 
		parameters : TCPConnection_Desc_typ;
		mode : WS_Mode_enum;
	END_STRUCT;
	WSConnectionManager_Internal_typ : 	STRUCT 
		tcpConnection : TCPConnectionMgr_typ;
	END_STRUCT;
END_TYPE
