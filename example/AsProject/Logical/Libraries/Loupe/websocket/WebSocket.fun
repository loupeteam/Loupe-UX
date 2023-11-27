(*
 * File: WebSocket.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of WebSocket, licensed under the MIT License.
 *)

FUNCTION wsManageConnection : BOOL
	VAR_INPUT
		inst : WSConnectionManager_typ;
	END_VAR
END_FUNCTION

FUNCTION wsSend : BOOL
	VAR_INPUT
		inst : WSStream_typ;
	END_VAR
END_FUNCTION

FUNCTION wsReceive : BOOL
	VAR_INPUT
		inst : WSStream_typ;
	END_VAR
END_FUNCTION
(*Utility Fns*)

FUNCTION wsGetErrorMsg : UDINT
	VAR_INPUT
		dest : UDINT;
		errorID : DINT;
		destSize : UDINT;
	END_VAR
END_FUNCTION

FUNCTION wsModeIsValid : BOOL
	VAR_INPUT
		mode : DINT;
	END_VAR
END_FUNCTION
(*Low Level Fns*)

FUNCTION_BLOCK wsConnect (*Negotiate a new WebSocket connection TODO: Figure out how to add functionality later*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pInputMessage : UDINT;
		pOutputMessage : UDINT;
		outputMessageSize : UDINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		outputMessageLength : UDINT;
	END_VAR
	VAR
		internal : WSConnect_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK wsDecode (*Decode a WebSocket frame*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pFrame : UDINT;
		frameLength : UDINT;
		pPayload : UDINT;
		payloadSize : UDINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		partialHeader : BOOL;
		partialFrame : BOOL;
		fin : BOOL;
		rsv : USINT;
		opCode : USINT;
		mask : BOOL;
		maskingKey : MaskingKey_typ;
		headerLength : UDINT;
		payloadLength : UDINT;
		decodeLength : UDINT;
	END_VAR
	VAR
		internal : WSDecode_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK wsEncode (*Encode data into a WebSocket frame*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pFrame : UDINT;
		frameSize : UDINT;
		fin : BOOL;
		rsv : USINT;
		opCode : USINT;
		mask : BOOL; (*NOT SUPPORTED*)
		maskingKey : MaskingKey_typ; (*NOT SUPPORTED*)
		pPayload : UDINT;
		payloadLength : UDINT;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		frameLength : UDINT;
	END_VAR
	VAR
		internal : WSEncode_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK wsMask (*Mask / Unmask Src into Dest*)
	VAR_INPUT
		src : UDINT; (*Pointer to STRING with original data*)
		srcLength : UDINT; (*Length of data*)
		dest : UDINT; (*Pointer to STRING to destination*)
		destSize : UDINT; (*Size of destination*)
		maskingKey : MaskingKey_typ; (*Masking Key, if 0 then a key will be generated*)
	END_VAR
	VAR_OUTPUT
		status : UINT;
		destLength : UDINT; (*Length of dest*)
	END_VAR
END_FUNCTION_BLOCK
