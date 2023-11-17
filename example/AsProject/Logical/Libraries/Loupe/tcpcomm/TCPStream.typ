(*
 * File: TCPStream.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of TCPComm, licensed under the MIT License.
 *
 *)

(*For each client lets instantiate an interface*)

TYPE
	TCPStream_Int_Debug_Mng_typ : 	STRUCT 
		New_Member : {REDUND_UNREPLICABLE} USINT;
	END_STRUCT;
	TCPStream_Int_Debug_Recv_typ : 	STRUCT 
		enable : {REDUND_UNREPLICABLE} ARRAY[0..1]OF BOOL;
		status : {REDUND_UNREPLICABLE} ARRAY[0..1]OF UINT;
	END_STRUCT;
	TCPStream_Int_Debug_Send_typ : 	STRUCT 
		New_Member : {REDUND_UNREPLICABLE} USINT;
	END_STRUCT;
	TCPStream_Int_Debug_typ : 	STRUCT 
		manage : {REDUND_UNREPLICABLE} TCPStream_Int_Debug_Mng_typ;
		receive : {REDUND_UNREPLICABLE} TCPStream_Int_Debug_Recv_typ;
		send : {REDUND_UNREPLICABLE} TCPStream_Int_Debug_Send_typ;
	END_STRUCT;
	TCPStream_Int_FUB_typ : 	STRUCT 
		Send : TcpSend;
		Receive : TcpRecv;
		Close : TcpClose;
	END_STRUCT;
	TCPStream_Internal_typ : 	STRUCT 
		CommState : TCPCOMM_ST_enum;
		Ident : UDINT;
		UID : UDINT;
		FUB : TCPStream_Int_FUB_typ;
		debug : {REDUND_UNREPLICABLE} TCPStream_Int_Debug_typ;
	END_STRUCT;
	TCPStream_OUT_typ : 	STRUCT 
		Connection : TCPConnection_Desc_typ;
		Active : BOOL;
		Receiving : BOOL;
		DataReceived : BOOL;
		ReceivedDataLength : UDINT;
		Sending : BOOL;
		DataSent : BOOL;
		SentDataLength : UDINT;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[TCPCOMM_STRLEN_ERRORSTRING];
	END_STRUCT;
	TCPStream_IN_PAR_typ : 	STRUCT 
		Connection : TCPConnection_Desc_typ;
		pReceiveData : UDINT;
		MaxReceiveLength : UDINT;
		ReceiveFlags : UINT;
		AllowContinuousReceive : BOOL;
		pSendData : UDINT;
		SendLength : UDINT;
		SendFlags : UINT;
		AllowContinuousSend : BOOL;
	END_STRUCT;
	TCPStream_IN_CMD_typ : 	STRUCT 
		Receive : BOOL;
		Send : BOOL;
		Close : BOOL;
		AcknowledgeData : BOOL;
		AcknowledgeError : BOOL;
	END_STRUCT;
	TCPStream_IN_typ : 	STRUCT 
		CMD : TCPStream_IN_CMD_typ;
		PAR : TCPStream_IN_PAR_typ;
	END_STRUCT;
	TCPStream_typ : 	STRUCT 
		IN : TCPStream_IN_typ;
		OUT : TCPStream_OUT_typ;
		Internal : TCPStream_Internal_typ;
	END_STRUCT;
END_TYPE
