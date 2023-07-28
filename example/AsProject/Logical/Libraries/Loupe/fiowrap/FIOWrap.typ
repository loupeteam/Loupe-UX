(********************************************************************
 * COPYRIGHT --  Automation Resources Group
 ********************************************************************
 * Library: FIOWrap
 * File: FIOWrap.typ
 * Author: blackburnd
 * Created: June 18, 2009
 ********************************************************************
 * Data types of library FIOWrap
 ********************************************************************)

TYPE
	FIOWRAP_ERR_enum : 
		(
		FIOWRAP_ERR_INVALIDOP := 50000,
		FIOWRAP_ERR_INVALIDFILTER,
		FIOWRAP_ERR_INVALIDDIR,
		FIOWRAP_ERR_MAXFILESIZE
		);
	FIOWRAP_OP_enum : 
		(
		FIOWRAP_OP_INVALID := 0,
		FIOWRAP_OP_OPEN,
		FIOWRAP_OP_SAVEAS,
		FIOWRAP_OP_APPEND,
		FIOWRAP_OP_APPEND_NEW,
		FIOWRAP_OP_SCAN,
		FIOWRAP_OP_DELETE,
		FIOWRAP_OP_DELETE_ALL,
		FIOWRAP_OP_ERROR
		);
	FIOWRAP_ST_enum : 
		(
		FIOWRAP_ST_WAIT := 0, (*0*)
		FIOWRAP_ST_OPEN, (*1*)
		FIOWRAP_ST_CREATE, (*2*)
		FIOWRAP_ST_READ, (*3*)
		FIOWRAP_ST_WRITE, (*4*)
		FIOWRAP_ST_CLOSE, (*5*)
		FIOWRAP_ST_DELETE, (*6*)
		FIOWRAP_ST_DELETE_FILE, (*7*)
		FIOWRAP_ST_DELETE_DIR, (*8*)
		FIOWRAP_ST_RENAME, (*9*)
		FIOWRAP_ST_ERROR := 999, (*999*)
		FIOWRAP_ST_
		);
	FIOWrap_Int_FUB_typ : 	STRUCT 
		Open : FileOpen;
		Create : FileCreate;
		Read : FileRead;
		Write : FileWrite;
		Close : FileClose;
		Delete : FileDelete;
		Rename : FileRename;
		GetTime : DTGetTime;
	END_STRUCT;
	FIOWrap_Internal_typ : 	STRUCT 
		FileID : UDINT; (*File Ident for reading and writing*)
		FileLen : UDINT; (*Length of the current file for appending*)
		FileCreated : BOOL; (*Error happened after opening file.  Need to close and then go to error state.*)
		ErrorClose : BOOL; (*Error happened after opening file.  Need to close and then go to error state.*)
		CurrOperation : DINT;
		State : DINT;
		Timestamp : STRING[30];
		newFileName : STRING[FIOWRAP_STRLEN_NAME];
		Name : STRING[FIOWRAP_STRLEN_NAME];
		Extension : STRING[FIOWRAP_STRLEN_NAME];
		FUB : FIOWrap_Int_FUB_typ;
		CMD : FIOWrap_IN_CMD_typ;
		DTStruct : DTStructure;
		TempStr : STRING[FIOWRAP_STRLEN_NAME];
	END_STRUCT;
	FIOWrap_OUT_STAT_typ : 	STRUCT 
		Busy : BOOL;
		Done : BOOL;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[FIOWRAP_STRLEN_ERROR];
		ErrorLevel : USINT;
		ReadyForCMD : BOOL;
		NewFile : BOOL; (*Length of the current file for appending*)
		FileLen : UDINT; (*Length of the current file for appending*)
	END_STRUCT;
	FIOWrap_OUT_typ : 	STRUCT 
		STAT : FIOWrap_OUT_STAT_typ;
	END_STRUCT;
	FIOWrap_IN_PAR_typ : 	STRUCT 
		FileDevice : STRING[FIOWRAP_STRLEN_NAME]; (*File device name*)
		FileName : STRING[FIOWRAP_STRLEN_NAME]; (*File name (with extension)*)
		Suffix : STRING[FIOWRAP_STRLEN_NAME]; (*File name (with extension)*)
		pData : UDINT; (*Address of the data to be read or written*)
		len : UDINT; (*Length of the data to be read or written*)
		offset : UDINT; (*Offset within the file to read/write from/to.*)
		MaxFileSize : UDINT; (*Maximum file size (only evaluated when appending to a file)*)
		MultiFile : BOOL;
	END_STRUCT;
	FIOWrap_IN_CMD_typ : 	STRUCT 
		Open : BOOL; (*Open a file and read its contents*)
		SaveAs : BOOL; (*Save data to a file*)
		AppendToFile : BOOL; (*Append data to the end of a file*)
		Delete : BOOL;
		AcknowledgeError : BOOL;
	END_STRUCT;
	FIOWrap_IN_typ : 	STRUCT 
		CMD : FIOWrap_IN_CMD_typ;
		PAR : FIOWrap_IN_PAR_typ;
	END_STRUCT;
	FIOWrap_typ : 	STRUCT 
		IN : FIOWrap_IN_typ;
		OUT : FIOWrap_OUT_typ;
		Internal : FIOWrap_Internal_typ;
	END_STRUCT;
	FIOManage_Int_FUB_typ : 	STRUCT 
		DirOpen : DirOpen;
		DirClose : DirClose;
		DirRead : DirReadEx;
		DeleteDir : DirDeleteEx;
		Delete : FileDelete;
	END_STRUCT;
	FIOManage_Internal_typ : 	STRUCT 
		DirID : UDINT; (*File Ident for reading and writing*)
		NumDirs : UDINT; (*Length of the current file for appending*)
		NumItems : UDINT; (*Length of the current file for appending*)
		CurrOperation : FIOWRAP_OP_enum;
		ErrorClose : BOOL; (*Error happened after opening file.  Need to close and then go to error state.*)
		State : DINT;
		index : USINT;
		FilterName : STRING[FIOWRAP_STRLEN_NAME];
		ItemName : STRING[FIOWRAP_STRLEN_NAME];
		FileExtension : STRING[FIOWRAP_STRLEN_NAME];
		Name : STRING[FIOWRAP_STRLEN_NAME];
		Extension : STRING[FIOWRAP_STRLEN_NAME];
		NumItemsDelete : DINT;
		ItemInfo : fiDIR_READ_EX_DATA;
		ItemInfoCache : ARRAY[0..FIOWRAP_MAI_DELETE]OF fiDIR_READ_EX_DATA;
		NewestIndex : USINT;
		OldestIndex : USINT;
		FUB : FIOManage_Int_FUB_typ;
		CMD : FIOManage_IN_CMD_typ;
	END_STRUCT;
	FIOManage_OUT_STAT_typ : 	STRUCT 
		Busy : BOOL;
		Done : BOOL;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[FIOWRAP_STRLEN_ERROR];
		ErrorLevel : USINT;
		ReadyForCMD : BOOL;
	END_STRUCT;
	FIOManage_OUT_typ : 	STRUCT 
		STAT : FIOManage_OUT_STAT_typ;
	END_STRUCT;
	FIOManage_IN_PAR_typ : 	STRUCT 
		FileDevice : STRING[FIOWRAP_STRLEN_NAME]; (*File device name*)
		Directory : STRING[FIOWRAP_STRLEN_NAME]; (*Directory to navigate to*)
		ItemName : STRING[FIOWRAP_STRLEN_NAME]; (*Address of the data to be read or written*)
		MaxNumItems : UDINT; (*Maximum file size (only evaluated when appending to a file)*)
		Mode : USINT; (*Maximum file size (only evaluated when appending to a file)*)
	END_STRUCT;
	FIOManage_IN_CMD_typ : 	STRUCT 
		Scan : BOOL;
		DeleteAll : BOOL;
		AcknowledgeError : BOOL;
	END_STRUCT;
	FIOManage_IN_typ : 	STRUCT 
		CMD : FIOManage_IN_CMD_typ;
		PAR : FIOManage_IN_PAR_typ;
	END_STRUCT;
	FIOManage_typ : 	STRUCT 
		IN : FIOManage_IN_typ;
		OUT : FIOManage_OUT_typ;
		Internal : FIOManage_Internal_typ;
	END_STRUCT;
END_TYPE
