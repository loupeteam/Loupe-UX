(*
 * File: WSStream.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of WebSocket, licensed under the MIT License.
 *)

(*For each client lets instantiate an interface*)
TYPE
	WSStream_typ : 	STRUCT 
		in : WSStream_IN_typ;
		out : WSStream_OUT_typ;
		internal : WSStream_Internal_typ;
	END_STRUCT;
	WSStream_IN_typ : 	STRUCT 
		cmd : WSStream_IN_CMD_typ;
		par : WSStream_IN_PAR_typ;
		cfg : WSStream_IN_CFG_typ;
	END_STRUCT;
	WSStream_IN_CMD_typ : 	STRUCT 
		receive : BOOL;
		send : BOOL;
		close : BOOL;
		acknowledgeData : BOOL;
		acknowledgeError : BOOL;
	END_STRUCT;
	WSStream_IN_PAR_typ : 	STRUCT 
		connection : WSConnectionManager_Desc_typ;
		pReceiveData : UDINT;
		maxReceiveLength : UDINT;
		receiveFlags : UINT;
		allowContinuousReceive : BOOL;
		pSendData : UDINT;
		sendLength : UDINT;
		sendHeader : WSHeader_typ;
		sendFlags : UINT;
		allowContinuousSend : BOOL;
	END_STRUCT;
	WSStream_IN_CFG_typ : 	STRUCT 
		bufferSize : UDINT;
	END_STRUCT;
	WSStream_OUT_typ : 	STRUCT 
		connection : WSConnectionManager_Desc_typ;
		active : BOOL;
		connected : BOOL;
		receiving : BOOL;
		header : WSHeader_typ;
		partialDataReceived : BOOL;
		dataReceived : BOOL;
		receivedDataLength : UDINT;
		sending : BOOL;
		dataSent : BOOL;
		sentDataLength : UDINT;
		error : BOOL;
		errorID : UINT;
		errorString : STRING[TCPCOMM_STRLEN_ERRORSTRING];
	END_STRUCT;
	WSStream_Internal_typ : 	STRUCT 
		debug : WSStream_Int_Debug_typ;
		fub : WSStream_Int_FUB_typ;
		connection : WSConnectionManager_Desc_typ;
		initialized : BOOL;
		connected : BOOL;
		connectionUpgraded : BOOL;
		connectionState : UINT;
		bufferSize : UDINT;
		sendBuffer : UDINT;
		recieveBuffer : UDINT;
		prevSend : BOOL;
	END_STRUCT;
	WSStream_Int_Debug_typ : 	STRUCT 
		New_Member : USINT;
	END_STRUCT;
	WSStream_Int_FUB_typ : 	STRUCT 
		tcpStream : TCPStream_typ;
		wsDecode : wsDecode;
		wsEncode : wsEncode;
		wsConnect : wsConnect;
		wsMask : wsMask;
	END_STRUCT;
END_TYPE
