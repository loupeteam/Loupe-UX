(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: EditorControl
 * File: EditorControl.typ
 * Author: Josh
 * Created: November 13, 2012
 ********************************************************************
 * Local data types of program EditorControl
 ********************************************************************)
(*Application Editor*)

TYPE
	HMI_Editor_Controller_typ : 	STRUCT 
		CMD : HMI_Editor_Controller_CMD_typ;
		HMI : HMI_EditControl_typ;
		Internal : HMI_Editor_Controller_int_typ;
	END_STRUCT;
	HMI_Editor_Controller_int_typ : 	STRUCT 
		CMD : HMI_Editor_Controller_CMD_typ;
	END_STRUCT;
	HMI_Editor_Controller_CMD_typ : 	STRUCT 
		Load : BOOL;
		Save : BOOL;
		Clear : BOOL;
	END_STRUCT;
END_TYPE

(*HMI Connections*)

TYPE
	HMI_EditControl_Internal_typ : 	STRUCT 
		CurrentLineText : STRING[200];
		CurrentLineIndex : UINT;
		CommandState : USINT;
		EditText : STRING[80];
		DesiredLine : USINT;
		DesiredColumn : USINT;
		Offset : USINT;
		Count : USINT;
		highlightmode : USINT;
	END_STRUCT;
	HMI_EditControl_Runtime_Edit_typ : 	STRUCT 
		CursorLineDp : UINT;
		CursorColumnDp : UINT;
		InsertModeDp : UINT;
		ModifiedDp : UINT;
		SelectionModeDp : UINT;
	END_STRUCT;
	HMI_EditControl_Runtime_Comp_typ : 	STRUCT 
		CompletionDP : UINT;
	END_STRUCT;
	HMI_EditControl_Runtime_Cmds_typ : 	STRUCT 
		ResponseDp : STRING[80];
		RequestDp : STRING[80];
		StatusDP : UINT;
	END_STRUCT;
	HMI_EditControl_Runtime_typ : 	STRUCT 
		StatusDp : UINT;
		BusyDp : UINT;
		Commands : HMI_EditControl_Runtime_Cmds_typ;
		Completion : HMI_EditControl_Runtime_Comp_typ;
		Edit : HMI_EditControl_Runtime_Edit_typ;
	END_STRUCT;
	HMI_EditControl_Value_typ : 	STRUCT 
		Content : STRING[1000];
		URLDp : STRING[80];
	END_STRUCT;
	HMI_EditControl_typ : 	STRUCT 
		Value : HMI_EditControl_Value_typ;
		Runtime : HMI_EditControl_Runtime_typ;
		internal : HMI_EditControl_Internal_typ;
		Command : HMI_EditControl_CMDS;
	END_STRUCT;
	HMI_EditControl_CMDS : 
		(
		EC_,
		EC_APPEND,
		EC_CLEAR,
		EC_DELETE,
		EC_GET_LINE,
		EC_GET_MARKED_TEXT,
		EC_GET_TEXT_SIZE,
		EC_GOTO,
		EC_HIGHLIGHT,
		EC_INSERT,
		EC_LOAD,
		EC_READ,
		EC_REPLACE_MARKED_TEXT,
		EC_SAVE,
		EC_UPDATE
		);
END_TYPE
