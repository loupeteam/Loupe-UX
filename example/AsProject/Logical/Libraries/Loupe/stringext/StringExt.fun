(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: StringExt
 * File: StringExt.fun
 * Author: David Blackburn
 * Created: January 26, 2012
 ********************************************************************
 * Functions and function blocks of library StringExt
 ********************************************************************)

FUNCTION lstrip : UDINT (*Strips the leading characters from a string*)
	VAR_INPUT
		pString : UDINT;
		pChars : UDINT;
	END_VAR
END_FUNCTION

FUNCTION rstrip : UDINT (*Strips the trailing characters from a string*)
	VAR_INPUT
		pString : UDINT;
		pChars : UDINT;
	END_VAR
END_FUNCTION

FUNCTION atoui : UDINT (*Converts a string to a UDINT value, allowing values greater than the DINT maximum*)
	VAR_INPUT
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION uitoa : UDINT (*Converts a UDINT to a string, allowing values greater than the DINT maximum*)
	VAR_INPUT
		Value : UDINT;
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION ByteToHexString : UDINT (*Converts bytes to a hex string*)
	VAR_INPUT
		pByte : UDINT;
		NumBytes : UDINT;
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION HexStringToDINT : DINT (*Converts a Hex String to a DINT*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pHexStr : UDINT;
	END_VAR
END_FUNCTION

FUNCTION GenerateTimestampMS_1 : UINT (*Generate a time stamp string from a DTStructure variable*)
	VAR_INPUT
		pDTStructure : UDINT;
		pTimestamp : UDINT;
		TimestampLength : UDINT;
	END_VAR
END_FUNCTION

FUNCTION GenerateTimestampMS : UINT (*Generate a time stamp string from a DTStructure variable*)
	VAR_INPUT
		pDTStructure : UDINT;
		pTimestamp : UDINT;
		TimestampLength : UDINT;
	END_VAR
END_FUNCTION

FUNCTION GenerateTimestamp : UINT (*Generate a time stamp string from a DATE_AND_TIME variable*)
	VAR_INPUT
		DT1 : DATE_AND_TIME;
		pTimestamp : UDINT;
		TimestampLength : UDINT;
	END_VAR
END_FUNCTION

FUNCTION strncat4 : UINT (*Combine strings pSource1 through pSource4 into pDest, with ' / ' between source strings*) (*$GROUP=User*)
	VAR_INPUT
		pDest : UDINT;
		pSource1 : UDINT;
		pSource2 : UDINT;
		pSource3 : UDINT;
		pSource4 : UDINT;
		MaxLength : UDINT;
	END_VAR
END_FUNCTION

FUNCTION ToUpper : UDINT (*Converts a string to upper case*) (*$GROUP=User*)
	VAR_INPUT
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION ToLower : UDINT (*Converts a string to lower case*) (*$GROUP=User*)
	VAR_INPUT
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION Timestamp_TO_DT : DATE_AND_TIME
	VAR_INPUT
		pDT : UDINT;
		pTimestamp : UDINT;
	END_VAR
END_FUNCTION

FUNCTION appendArrayIndex : UDINT (*Appends [Value] to string*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Value : UDINT;
		pString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION SplitFileName : UDINT (*Seperates file extension from file name*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		pFileName : UDINT; (*Pointer to the string containing file name and extension*)
		pName : UDINT; (*Pointer to location to copy file name (optional)*)
		pExtension : UDINT; (*Pointer to location to copy extension (optional)*)
	END_VAR
END_FUNCTION

FUNCTION stringlcpy : UDINT (*Copies strings safely*)
	VAR_INPUT
		pDest : UDINT;
		pSrc : UDINT;
		dSize : UDINT;
	END_VAR
END_FUNCTION

FUNCTION stringlcat : UDINT (*Concats strings safely*)
	VAR_INPUT
		pDest : UDINT;
		pSrc : UDINT;
		dSize : UDINT;
	END_VAR
END_FUNCTION

FUNCTION string2wstring : UDINT (*Converts String to WString*)
	VAR_INPUT
		pDest : UDINT; (*Pointer to String where contents will be copied*)
		pSrc : UDINT; (*Pointer to WString of contents to be converted*)
		dSize : UDINT; (*Size of destination String*)
	END_VAR
END_FUNCTION

FUNCTION wstring2string : UDINT (*Converts Wstring to String*)
	VAR_INPUT
		pDest : UDINT; (*Pointer to WString where contents will be copied*)
		pSrc : UDINT; (*Pointer to String of contents to be converted*)
		dSize : UDINT; (*Size of destination WString*)
	END_VAR
END_FUNCTION

FUNCTION char2wchar : UINT (*Converts Char to WChar*)
	VAR_INPUT
		character : USINT; (*Char to be converted*)
	END_VAR
END_FUNCTION

FUNCTION wchar2char : USINT (*Converts WChar to Char*)
	VAR_INPUT
		wcharacter : UINT; (*WChar to be converted*)
	END_VAR
END_FUNCTION

FUNCTION formatString : DINT (*Safe fromat string similar to sprintf*)
	VAR_INPUT
		dest : STRING[80]; (*Destination of formatted string*)
		destSize : UDINT; (*Size of destination*)
		format : STRING[80]; (*String with formatters*)
		pArgs : StrExtArgs_typ; (*Pointer to argument structure*)
	END_VAR
END_FUNCTION

FUNCTION stringfTime : UDINT (*Format time to string*)
	VAR_INPUT
		dest : UDINT; (*Pointer to destination*)
		destSize : UDINT; (*Size of destination*)
		format : UDINT; (*Format to use*)
		time : DATE_AND_TIME; (*Time to format*)
	END_VAR
END_FUNCTION

FUNCTION stringpTime : DATE_AND_TIME (*Parse time string*)
	VAR_INPUT
		src : UDINT; (*String to parse*)
		format : UDINT; (*Assumed format of time string*)
	END_VAR
END_FUNCTION
