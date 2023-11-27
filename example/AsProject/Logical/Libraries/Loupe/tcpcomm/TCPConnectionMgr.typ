(*
 * File: TCPConnectionMgr.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of TCPComm, licensed under the MIT License.
 *
 *)

TYPE
	TCPCOMM_MODE_enum : 
		(
		TCPCOMM_MODE_SERVER := 50000,
		TCPCOMM_MODE_CLIENT
		);
	TCPCOMM_ERR_enum : 
		(
		TCPCOMM_ERR_INVALIDINPUT := 50000,
		TCPCOMM_ERR_SENDDATATOOLARGE,
		TCPCOMM_ERR_
		);
	TCPCOMM_ST_enum : 
		(
		TCPCOMM_ST_CLOSED,
		TCPCOMM_ST_OPENING,
		TCPCOMM_ST_IOCTL,
		TCPCOMM_ST_LISTEN,
		TCPCOMM_ST_RUNNING,
		TCPCOMM_ST_CLOSE_CONNECTION,
		TCPCOMM_ST_CLOSING,
		TCPCOMM_ST_ERROR
		);
	TCPCOMM_SEND_ST_enum : 
		(
		TCPCOMM_SEND_ST_IDLE,
		TCPCOMM_SEND_ST_SEND
		);
	TCPCOMM_RECV_ST_enum : 
		(
		TCPCOMM_RECV_ST_READ
		);
	TCPConnection_Desc_typ : 	STRUCT 
		IPAddress : STRING[TCPCOMM_STRLEN_IPADDRESS];
		Port : UINT;
		Ident : UINT;
		UID : UDINT;
	END_STRUCT;
	TCPConnectionMgr_Int_FUB_typ : 	STRUCT 
		Open : TcpOpen;
		OpenSSL : TcpOpenSsl;
		Ioctl : TcpIoctl;
		Server : TcpServer;
		Client : TcpClient;
		Close : TcpClose;
	END_STRUCT;
	TCPConnectionMgr_Internal_typ : 	STRUCT 
		FUB : TCPConnectionMgr_Int_FUB_typ;
		CommState : TCPCOMM_ST_enum;
		Mode : TCPCOMM_MODE_enum;
		Ident : UDINT;
		ConnectionUID : UDINT;
	END_STRUCT;
	TCPConnectionMgr_OUT_typ : 	STRUCT 
		NewConnectionAvailable : BOOL;
		Connection : TCPConnection_Desc_typ;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[TCPCOMM_STRLEN_ERRORSTRING];
	END_STRUCT;
	TCPConnectionMgr_IN_CFG_typ : 	STRUCT 
		Mode : TCPCOMM_MODE_enum;
		LocalIPAddress : STRING[TCPCOMM_STRLEN_IPADDRESS];
		LocalPort : UINT;
		RemoteIPAddress : STRING[TCPCOMM_STRLEN_IPADDRESS];
		RemotePort : UINT;
		SendBufferSize : UDINT;
		UseSSL : BOOL;
		SSLCertificate : UDINT;
	END_STRUCT;
	TCPConnectionMgr_IN_CMD_typ : 	STRUCT 
		Enable : BOOL;
		AcknowledgeConnection : BOOL;
		AcknowledgeError : BOOL;
	END_STRUCT;
	TCPConnectionMgr_IN_typ : 	STRUCT 
		CMD : TCPConnectionMgr_IN_CMD_typ;
		CFG : TCPConnectionMgr_IN_CFG_typ;
	END_STRUCT;
	TCPConnectionMgr_typ : 	STRUCT 
		IN : TCPConnectionMgr_IN_typ;
		OUT : TCPConnectionMgr_OUT_typ;
		Internal : TCPConnectionMgr_Internal_typ;
	END_STRUCT;
END_TYPE
