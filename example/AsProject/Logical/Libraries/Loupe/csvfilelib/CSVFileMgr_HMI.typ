(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: CSVFileLib
 * File: CSVFileMgr_HMI.typ
 * Author: David Blackburn
 * Created: March 22, 2012
 ********************************************************************
 * Data types of library CSVFileLib
 ********************************************************************)

TYPE
	CSVFileMgr_HMI_Internal_typ : 	STRUCT 
		ProgressTimer : TON_10ms;
		HMI_CMD_Active : BOOL;
		HMI_CMD_Active_Old : BOOL;
	END_STRUCT;
	CSVFileMgr_HMI_TextSnippets_typ : 	STRUCT 
		FileName : STRING[CSV_STRLEN_FILENAME];
		PopupHeader : STRING[CSV_STRLEN_FILENAME];
		Action : STRING[CSV_STRLEN_FILENAME];
		ProgressLabel : STRING[CSV_STRLEN_FILENAME];
		ErrorID : UINT;
		ErrorString : STRING[CSV_STRLEN_ERROR];
	END_STRUCT;
	CSVFileMgr_HMI_ErrorStatus_typ : 	STRUCT 
		StatusDP : UINT;
		AcknowledgeError : HMI_Button_typ;
	END_STRUCT;
	CSVFileMgr_HMI_Progress_typ : 	STRUCT 
		StatusDP : UINT;
		Progress : UDINT;
	END_STRUCT;
	CSVFileMgr_HMI_DeleteConfirm_typ : 	STRUCT 
		StatusDP : UINT;
		Yes : HMI_Button_typ;
		No : HMI_Button_typ;
	END_STRUCT;
	CSVFileMgr_HMI_DialogBox_typ : 	STRUCT 
		StatusDP : UINT;
		FileNameList : ARRAY[0..CSV_MAI_FILELIST]OF STRING[LIST_BOX_STRING_SIZE];
		FileBrowser : HMIFileBrowse;
		PageUp : HMI_Button_typ;
		PageDown : HMI_Button_typ;
		Action : HMI_Button_typ;
		Cancel : HMI_Button_typ;
	END_STRUCT;
	CSVFileMgr_HMI_Main_typ : 	STRUCT 
		OpenFile : HMI_Button_typ;
		UpdateFile : HMI_Button_typ;
		SaveVariableListToFile : HMI_Button_typ;
		DeleteFile : HMI_Button_typ;
	END_STRUCT;
	CSVFileMgr_HMI_typ : 	STRUCT 
		Main : CSVFileMgr_HMI_Main_typ;
		DialogBox : CSVFileMgr_HMI_DialogBox_typ;
		DeleteConfirm : CSVFileMgr_HMI_DeleteConfirm_typ;
		Progress : CSVFileMgr_HMI_Progress_typ;
		ErrorStatus : CSVFileMgr_HMI_ErrorStatus_typ;
		TextSnippets : CSVFileMgr_HMI_TextSnippets_typ;
		Internal : CSVFileMgr_HMI_Internal_typ;
	END_STRUCT;
END_TYPE
