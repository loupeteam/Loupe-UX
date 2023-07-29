(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: ErrorLib
 * File: ErrorCollector.typ
 * Author: David Blackburn
 * Created: November 18, 2011
 ********************************************************************
 * Data types of library ErrorLib
 ********************************************************************)

TYPE
	ErrorCollector_Int_Source_typ : 	STRUCT 
		SourceName : STRING[ERRCOL_STRLEN_SOURCENAME];
		SourceTask : STRING[ERRCOL_STRLEN_SOURCETASK];
		pErrorActive : UDINT;
		pErrorString : UDINT;
		pErrorID : UDINT;
		pAcknowledge : UDINT;
		OldErrorActive : BOOL;
		OldErrorID : UINT;
		Log : BOOL;
		AddToList : BOOL;
		Timestamp : STRING[ERRCOL_STRLEN_TIMESTAMP];
	END_STRUCT;
	ErrorCollector_Internal_typ : 	STRUCT 
		Initialized : BOOL;
		pSource : REFERENCE TO ErrorCollector_Int_Source_typ;
		NumSources : UINT;
		NumErrors : UINT;
		Timestamp : STRING[ERRCOL_STRLEN_TIMESTAMP];
	END_STRUCT;
	ErrorCollector_OUT_ErrorInfo_typ : 	STRUCT 
		Timestamp : STRING[ERRCOL_STRLEN_TIMESTAMP];
		SourceName : STRING[ERRCOL_STRLEN_SOURCENAME];
		ErrorString : STRING[ERRCOL_STRLEN_ERRORSTRING];
		ErrorID : UINT;
		Active : BOOL;
		Acknowledged : BOOL;
		SourceIndex : UINT;
		SourceTask : STRING[ERRCOL_STRLEN_SOURCETASK];
		pAcknowledge : UDINT;
	END_STRUCT;
	ErrorCollector_OUT_STAT_typ : 	STRUCT 
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[ERRCOL_STRLEN_ERRORSTRING];
	END_STRUCT;
	ErrorCollector_OUT_typ : 	STRUCT 
		STAT : ErrorCollector_OUT_STAT_typ;
		ErrorCount : UINT;
		ErrorInfo : ARRAY[0..ERRCOL_MAI_ERRORINFO]OF ErrorCollector_OUT_ErrorInfo_typ;
	END_STRUCT;
	ErrorColl_IN_CFG_ElemNames_typ : 	STRUCT 
		ErrorActive : STRING[ERRCOL_STRLEN_ELEMNAME];
		ErrorString : STRING[ERRCOL_STRLEN_ELEMNAME];
		ErrorID : STRING[ERRCOL_STRLEN_ELEMNAME];
		Acknowledge : STRING[ERRCOL_STRLEN_ELEMNAME];
	END_STRUCT;
	ErrorCollector_IN_CFG_typ : 	STRUCT 
		ErrorCollectorSourceName : STRING[ERRCOL_STRLEN_SOURCENAME];
		MaxSources : UINT;
		StructureElementNames : ErrorColl_IN_CFG_ElemNames_typ;
		DisableLogging : BOOL;
		LoggerName : STRING[LOG_STRLEN_LOGGERNAME];
	END_STRUCT;
	ErrorCollector_IN_PAR_typ : 	STRUCT 
		ErrorIndex : UINT;
	END_STRUCT;
	ErrorCollector_IN_CMD_typ : 	STRUCT 
		AcknowledgeError : BOOL;
		AcknowledgeErrorAtIndex : BOOL;
		AcknowledgeAllErrors : BOOL;
	END_STRUCT;
	ErrorCollector_IN_typ : 	STRUCT 
		CMD : ErrorCollector_IN_CMD_typ;
		PAR : ErrorCollector_IN_PAR_typ;
		CFG : ErrorCollector_IN_CFG_typ;
	END_STRUCT;
	ErrorCollector_typ : 	STRUCT 
		IN : ErrorCollector_IN_typ;
		OUT : ErrorCollector_OUT_typ;
		Internal : ErrorCollector_Internal_typ;
	END_STRUCT;
END_TYPE
