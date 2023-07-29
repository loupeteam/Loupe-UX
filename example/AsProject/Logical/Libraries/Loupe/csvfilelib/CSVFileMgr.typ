(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: CSVFileLib
 * File: CSVFileMgr.typ
 * Author: David Blackburn
 * Created: March 08, 2012
 ********************************************************************
 * Data types of library CSVFileLib
 ********************************************************************)

TYPE
	CSVFileVariable_typ : 	STRUCT 
		Name : STRING[CSV_STRLEN_VARNAME];
		Value : STRING[CSV_STRLEN_VARVALUE];
		Description : STRING[CSV_STRLEN_VARDESCRIPTION];
		Address : UDINT;
		DataType : UDINT;
		Length : UDINT;
		Dimension : UINT;
	END_STRUCT;
	CSVFileMgr_StructLevel_typ : 	STRUCT 
		Name : STRING[CSV_STRLEN_VARNAME];
		DataType : UDINT;
		Length : UDINT;
		Dimension : UINT;
		iItem : UINT;
	END_STRUCT;
	CSVFileMgr_StructData_typ : 	STRUCT 
		iLevel : INT;
		Level : ARRAY[0..CSV_MAI_LEVEL]OF CSVFileMgr_StructLevel_typ;
	END_STRUCT;
	CSVFileMgr_Int_Buffer_typ : 	STRUCT 
		pData : UDINT;
		CurrentLength : UDINT;
		MaxLength : UDINT;
	END_STRUCT;
	CSVFileMgr_Internal_typ : 	STRUCT 
		Initialized : BOOL;
		CurrOperation : DINT;
		ProcessStatus : UINT;
		ExpandStatus : UINT;
		ExpandError : BOOL;
		ReadBuffer : CSVFileMgr_Int_Buffer_typ;
		WriteBuffer : CSVFileMgr_Int_Buffer_typ;
		LogBuffer : CSVFileMgr_Int_Buffer_typ;
		pLine : UDINT;
		LineNumber : UDINT;
		pToken : UDINT;
		pString : UDINT;
		pReentry : UDINT;
		SuccessfulLineCount : UDINT;
		FailedLineCount : UDINT;
		ScanCount : UDINT;
		StructureData : CSVFileMgr_StructData_typ;
		iVar : USINT;
		FileRename : FileRename;
		FIOWrap : FIOWrap_typ;
		CMD : CSVFileMgr_IN_CMD_typ;
		TempFileName : STRING[CSV_STRLEN_TEMPFILENAME];
		TemplateVariable : CSVFileVariable_typ;
		pUserVariable : UDINT;
		StartState : DINT;
	END_STRUCT;
	CSVFileMgr_OUT_STAT_typ : 	STRUCT 
		Busy : BOOL;
		Done : BOOL;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[CSV_STRLEN_ERROR];
		ErrorLevel : USINT;
		ErrorState : DINT;
		State : DINT;
	END_STRUCT;
	CSVFileMgr_OUT_typ : 	STRUCT 
		STAT : CSVFileMgr_OUT_STAT_typ;
	END_STRUCT;
	CSVFileMgr_IN_CFG_typ : 	STRUCT 
		MaxFileSize : UDINT;
		MaxLineLength : UDINT;
		MaxLinesPerScan : UDINT;
		VerboseLog : BOOL;
		LogFileName : STRING[CSV_STRLEN_FILENAME];
		DisableLogging : BOOL;
		LoggerName : STRING[LOG_STRLEN_LOGGERNAME];
		DoubleSigFigs : USINT;
	END_STRUCT;
	CSVFileMgr_IN_PAR_typ : 	STRUCT 
		FileDevice : STRING[CSV_STRLEN_FILEDEVICE];
		FileName : STRING[CSV_STRLEN_FILENAME];
		VariableList : ARRAY[0..CSV_MAI_VARLIST]OF STRING[CSV_STRLEN_VARNAME];
		Prefix : STRING[CSV_STRLEN_VARNAME];
		pUserVariable : UDINT;
	END_STRUCT;
	CSVFileMgr_IN_CMD_typ : 	STRUCT 
		OpenFile : BOOL;
		UpdateFile : BOOL;
		SaveVariableListToFile : BOOL;
		DeleteFile : BOOL;
		AcknowledgeError : BOOL;
	END_STRUCT;
	CSVFileMgr_IN_typ : 	STRUCT 
		CMD : CSVFileMgr_IN_CMD_typ;
		PAR : CSVFileMgr_IN_PAR_typ;
		CFG : CSVFileMgr_IN_CFG_typ;
	END_STRUCT;
	CSVFileMgr_typ : 	STRUCT 
		IN : CSVFileMgr_IN_typ;
		OUT : CSVFileMgr_OUT_typ;
		Internal : CSVFileMgr_Internal_typ;
	END_STRUCT;
END_TYPE
