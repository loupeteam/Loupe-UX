(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: DataBuffer
 * File: DataBuffer.fun
 * Author: davidblackburn
 * Created: June 23, 2014
 ********************************************************************
 * Functions and function blocks of library DataBuffer
 ********************************************************************)

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
