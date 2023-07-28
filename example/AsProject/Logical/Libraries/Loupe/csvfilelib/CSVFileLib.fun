(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: CSVFileLib
 * File: CSVFileLib.fun
 * Author: David Blackburn
 * Created: January 04, 2012
 ********************************************************************
 * Functions and function blocks of library CSVFileLib
 ********************************************************************)

FUNCTION CSVFn_Init : UINT (*CSVFileMgr initialization function*)
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION CSVOpenFile_Init : UINT (*Open a file in an INIT routine*)
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION CSVFn_Cyclic : UINT (*CSVFileMgr cyclic function*)
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvInitBuffer : UINT (*Initialize a buffer*)
	VAR_INPUT
		BufferLength : UDINT;
	END_VAR
	VAR_IN_OUT
		pBuffer : CSVFileMgr_Int_Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION csvClearBuffer : UINT (*Clear a buffer*)
	VAR_IN_OUT
		pBuffer : CSVFileMgr_Int_Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION csvAddToBuffer : UINT (*Add data to the end of a buffer, checking for overflow*)
	VAR_INPUT
		pData : UDINT;
		DataLength : UDINT;
	END_VAR
	VAR_IN_OUT
		pBuffer : CSVFileMgr_Int_Buffer_typ;
	END_VAR
END_FUNCTION

FUNCTION csvSetError : UINT (*Set error status on CSVFileMgr*)
	VAR_INPUT
		ErrorID : UINT;
	END_VAR
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvExpandVar : UINT (*Expand a complex variable into simple variables*)
	VAR_INPUT
		pVarName : UDINT;
	END_VAR
	VAR_IN_OUT
		pBuffer : CSVFileMgr_Int_Buffer_typ;
		pStructData : CSVFileMgr_StructData_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvProcessData : UINT (*Process data from file*)
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvAddLogInfo : UINT (*Add information to the parse status log*)
	VAR_INPUT
		InfoID : UINT;
		LineNumber : UDINT;
		pAddInfo : UDINT;
	END_VAR
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvParseLine : UINT (*Parse one line of the file*)
	VAR_INPUT
		pLine : UDINT;
		LineNumber : UDINT;
	END_VAR
	VAR_IN_OUT
		pVariable : CSVFileVariable_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvGetVarInfo : UINT (*Get variable address and data type based on variable name*)
	VAR_INPUT
		LineNumber : UDINT;
	END_VAR
	VAR_IN_OUT
		pVariable : CSVFileVariable_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvOpenVar : UINT (*Process one variable of an Open operation*)
	VAR_INPUT
		LineNumber : UDINT;
	END_VAR
	VAR_IN_OUT
		pVariable : CSVFileVariable_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvSaveVar : UINT (*Process one variable of a Save operation*)
	VAR_INPUT
		LineNumber : UDINT;
	END_VAR
	VAR_IN_OUT
		pVariable : CSVFileVariable_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvWriteHeader : UINT (*Write the header to the file*)
	VAR_IN_OUT
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvRemovePrefix : UINT (*Remove the prefix from the string if necessary*)
	VAR_INPUT
		MaxLength : UDINT;
	END_VAR
	VAR_IN_OUT
		String : STRING[1];
		Prefix : STRING[1];
	END_VAR
END_FUNCTION

FUNCTION csvAddPrefix : UINT (*Add a prefix to a string, unconditionally*)
	VAR_INPUT
		MaxLength : UDINT;
	END_VAR
	VAR_IN_OUT
		String : STRING[1];
		Prefix : STRING[1];
	END_VAR
END_FUNCTION

FUNCTION CSVFn_HMI_Cyclic : UINT (*CSVFileMgr cyclic HMI function*)
	VAR_IN_OUT
		HMI : CSVFileMgr_HMI_typ;
		t : CSVFileMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION csvhmiGenerateFileListString : UINT (*Generate the file list string for a given file*)
	VAR_INPUT
		pFileListString : UDINT;
	END_VAR
	VAR_IN_OUT
		pDirReadData : fiDIR_READ_DATA;
	END_VAR
END_FUNCTION

FUNCTION csvDTOA : UDINT (*Convert double to string*)
	VAR_INPUT
		value : LREAL;
		pString : UDINT;
		numSigFigs : USINT;
	END_VAR
END_FUNCTION
