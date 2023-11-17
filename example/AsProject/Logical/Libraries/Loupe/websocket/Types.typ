(*
 * File: Types.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of WebSocket, licensed under the MIT License.
 *)
TYPE
	WSHeader_typ : 	STRUCT 
		fin : BOOL;
		rsv : USINT;
		opCode : USINT;
		mask : BOOL;
		maskingKey : ARRAY[0..3]OF USINT;
		frameLength : UDINT;
	END_STRUCT;
	WS_OpCode_enum : 
		(
		WS_OPCODE_CONTINUATION := 0,
		WS_OPCODE_TEXT := 1,
		WS_OPCODE_BINARY := 2,
		WS_OPCODE_RESERVED_NON_CONTROL := 3,
		WS_OPCODE_CONNECTION_CLOSE := 8,
		WS_OPCODE_PING := 9,
		WS_OPCODE_PONG := 10,
		WS_OPCODE_RESERVED_CONTROL := 11
		);
	WS_ERR_enum : 
		(
		WS_ERR_OK,
		WS_ERR_INVALID_INPUT := 5500,
		WS_ERR_NOT_IMPLEMENTED,
		WS_ERR_PAYLOAD_LENGTH,
		WS_ERR_MEM_ALLOC,
		WS_ERR_NO_LICENSE,
		WS_ERR_KEY_NOT_FOUND, (*5505*)
		WS_ERR_PARTIAL_HTTP_MESSAGE,
		WS_ERR_INVALID_HTTP_MESSAGE,
		WS_ERR_BUFFER_FULL,
		WS_ERR_ (*5509*)
		);
	WS_Mode_enum : 
		(
		WS_MODE_SERVER := 50000,
		WS_MODE_CLIENT
		);
	MaskingKey_typ :ARRAY[0..3]OF USINT;
END_TYPE

(*Internal types*)

TYPE
	WSDecode_Internal_typ : 	STRUCT 
		mask : wsMask;
	END_STRUCT;
	WSEncode_Internal_typ : 	STRUCT 
		mask : wsMask;
	END_STRUCT;
	WSConnect_Internal_typ : 	STRUCT 
		encodeBase64 : httpEncodeBase64;
	END_STRUCT;
END_TYPE
