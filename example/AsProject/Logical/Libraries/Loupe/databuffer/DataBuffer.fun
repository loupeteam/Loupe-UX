(*
* File: DataBuffer.fun
* Copyright (c) 2023 Loupe
* https://loupe.team
* 
* This file is part of DataBuffer, licensed under the MIT License.
* 
*)

FUNCTION datbufClearBuffer : UINT (*Clear a data buffer*) (*$GROUP=User*)
	VAR_INPUT
		pBuffer : UDINT;
	END_VAR
END_FUNCTION

FUNCTION datbufInitBuffer : UINT (*Initialize a data buffer*) (*$GROUP=User*)
	VAR_INPUT
		pBuffer : UDINT;
		maxLength : UDINT;
	END_VAR
END_FUNCTION

FUNCTION datbufAppendToBuffer : UINT (*Append data to a data buffer*) (*$GROUP=User*)
	VAR_INPUT
		pBuffer : UDINT;
		pData : UDINT;
		dataLength : UDINT;
	END_VAR
END_FUNCTION
