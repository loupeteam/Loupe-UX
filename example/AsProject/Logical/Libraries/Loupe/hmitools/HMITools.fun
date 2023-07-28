(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: HMITools
 * File: HMITools.fun
 * Author: Josh
 * Created: November 07, 2012
 ********************************************************************
 * Functions and function blocks of library HMITools
 ********************************************************************)
(*
Application Ready Functions

These can be connected directly to an HMI with minimal work
*)

FUNCTION_BLOCK HMIFileBrowse (*HMI Ready file Selection function block with extensions*)
	VAR_INPUT
		Enable : BOOL; (*Enable Function Block*)
		Refresh : BOOL;
		FileDevice : STRING[80]; (*File device to look for files/directories*)
		EnableDirectorySearch : BOOL; (*Enable to look for directories*)
		EnableDataObjects : BOOL;
		BrowseToDirectory : BOOL; (*Command to browse into selected directory *)
		pDirectorySearchPath : UDINT; (*Search path within the file device*)
		pFileList : UDINT; (*List to hold file names*)
		MaxFiles : UDINT; (*Maximum number of file names list will hold*)
		pFileExtList : UDINT; (*List to hold file extensions*)
		MaxExt : UINT; (*Maximum number of file extensions list will hold*)
		FileIndex : DINT; (*Selected file index*)
		FileSelection : STRING[LIST_BOX_STRING_SIZE]; (*Selected file name*)
		FileExtIndex : DINT; (*Selected file extension index*)
		FileExtSelection : STRING[LIST_BOX_STRING_SIZE]; (*Selected file extension*)
	END_VAR
	VAR_OUTPUT
		CompletionDP : BOOL;
		CurrentPath : STRING[LIST_BOX_STRING_SIZE];
		NumFiles : UINT;
		Status : STRING[LIST_BOX_STRING_SIZE];
	END_VAR
	VAR
		Internal : HMI_File_Browse_internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK ListBoxFub (*HMI Ready list box*)
	VAR_INPUT
		Enable : BOOL; (*Enable function block*)
		Selection : UDINT; (*Address of Selection String*)
		SelectionList : UDINT; (*List of strings to select from*)
		IndexDP : DINT; (*List box select index*)
		MinDP : UINT; (*List box min DP*)
		MaxDP : UINT; (*List box max DP*)
		OptionDP : UINT; (*List box option DP*)
		StatusDP : UINT; (*List box Status DP*)
		ColorDP : UINT; (*List box Color DP*)
		PageSize : UINT; (*Page size*)
	END_VAR
	VAR_OUTPUT
		CompletionDP : BOOL;
	END_VAR
	VAR
		Files : REFERENCE TO ARRAY[0..0] OF STRING[LIST_BOX_STRING_SIZE];
		intIndex : DINT := 1;
		pValue : REFERENCE TO STRING[LIST_BOX_STRING_SIZE];
		oValue : STRING[LIST_BOX_STRING_SIZE];
	END_VAR
END_FUNCTION_BLOCK

FUNCTION LogView_init : BOOL (*Allocates resources for caching data from logger*)
	VAR_INPUT
		LogView : LogView_typ;
	END_VAR
END_FUNCTION

FUNCTION LogView_cyclic : BOOL (*Handles caching data from logger*)
	VAR_INPUT
		LogView : LogView_typ;
	END_VAR
	VAR
		iNewEntry : LogData;
		MaxTopIndex : UDINT;
		pEntry : REFERENCE TO LogData;
	END_VAR
END_FUNCTION

FUNCTION LogView_HMI : BOOL (*Handles displaying alarms from buffer on HMI*)
	VAR_INPUT
		LogView : LogView_typ;
		LogViewHMI : LogView_HMI_typ;
	END_VAR
	VAR
		iLogData : REFERENCE TO LogData;
		pLogList : REFERENCE TO ARRAY[0..99] OF STRING[LIST_BOX_STRING_SIZE];
		iNumDisplay : UINT;
		i : UINT;
		iOffsetCount : UDINT;
		iOffset : UDINT;
		TempErrorID : STRING[8];
	END_VAR
END_FUNCTION

FUNCTION Editor_fn : BOOL (*HMI Ready editor control *)
	VAR_INPUT
		EditorController : HMI_Editor_Controller_typ;
	END_VAR
END_FUNCTION

FUNCTION TrendFn : BOOL (*Function for controlling a trend object. Function should be called in the Init and Cyclic subroutines.*)
	VAR_IN_OUT
		t : HMI_Trend_typ; (*Trend control object*)
	END_VAR
	VAR
		i : USINT; (*Loop counter*)
	END_VAR
END_FUNCTION

FUNCTION HMI_TabControlFn_Cyclic : BOOL (*Handle tab based page switching*)
	VAR_IN_OUT
		t : HMI_Basic_typ; (*HMI_Basic control object*)
	END_VAR
	VAR
		p : UINT; (*Primary tab index*)
		ss : UINT; (*Secondary tab index for looping*)
		SecondaryTabIndex : UINT; (*Intermediate variable for primary tab page changes*)
		PrimaryActive : BOOL; (*At least one primary tab is active*)
		SecondaryActive : BOOL; (*At least one secondary tab is active*)
	END_VAR
END_FUNCTION
(*
Application Builder Functions

These functions can be used as building blocks
*)

FUNCTION HMI_Hide : BOOL (*Hide an item on the screen*)
	VAR_IN_OUT
		StatusDP : UINT; (*Item StatusDP*)
	END_VAR
END_FUNCTION

FUNCTION HMI_Show : BOOL (*Show an item on the screen*)
	VAR_IN_OUT
		StatusDP : UINT; (*Item StatusDP*)
	END_VAR
END_FUNCTION

FUNCTION HMI_Lock : BOOL (*Lock an item on the screen*)
	VAR_IN_OUT
		StatusDP : UINT; (*Item StatusDP*)
	END_VAR
END_FUNCTION

FUNCTION HMI_Unlock : BOOL (*Unlock an item on the screen*)
	VAR_IN_OUT
		StatusDP : UINT; (*Item StatusDP*)
	END_VAR
END_FUNCTION

FUNCTION HMI_SetFocus : BOOL (*Sets the focus for an item on the screen. FOCUS MUST BE RESET!*)
	VAR_IN_OUT
		StatusDP : UINT;
	END_VAR
END_FUNCTION

FUNCTION HMI_ResetFocus : BOOL (*Resets the focus bit for an item on the screen. THIS DOES NOT MOVE THE FOCUS!*)
	VAR_IN_OUT
		StatusDP : UINT;
	END_VAR
END_FUNCTION

FUNCTION HMI_OpenTouchpad : BOOL (*Opens the touchpad for an item on the screen*)
	VAR_IN_OUT
		StatusDP : UINT;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK DirectoryFub (*Loads a directory and files on file extension*)
	VAR_INPUT
		Enable : BOOL; (*Enable function block*)
		Refresh : BOOL;
		EnableDirectorySearch : BOOL; (*Enable to look for directories*)
		ShowHiddenFiles : BOOL; (*Enable showing files that start with a dot*)
		FileDevice : STRING[80]; (*Directory file device*)
		pPath : UDINT; (*Search path within the file device*)
		MaxValues : UDINT; (*Maximum number of files that list will hold*)
		NameFilter : STRING[LIST_BOX_STRING_SIZE]; (*File/Diretory name filter*)
		FileList : UDINT; (*List to hold file names*)
		FileExt : STRING[LIST_BOX_STRING_SIZE]; (*File extension to filter*)
	END_VAR
	VAR_OUTPUT
		NumFiles : UINT;
		status : UINT;
		Updating : BOOL;
		Initialized : BOOL;
	END_VAR
	VAR
		DirectoryOpen : DirOpen;
		DirectoryRead : DirReadEx;
		DirectoryClose : DirClose;
		Ident : UDINT;
		State : USINT;
		ListFileIndex : UINT;
		index : UINT;
		Files : REFERENCE TO ARRAY[0..0] OF STRING[LIST_BOX_STRING_SIZE];
		DirData : fiDIR_READ_EX_DATA;
		TempString : STRING[LIST_BOX_STRING_SIZE];
		TempExtension : STRING[LIST_BOX_STRING_SIZE];
		lcTempString : STRING[LIST_BOX_STRING_SIZE];
		lcNameFilter : STRING[LIST_BOX_STRING_SIZE];
		iNameFilter : STRING[LIST_BOX_STRING_SIZE]; (*File/Diretory name filter*)
		UpdateTimer : TON;
		i : UINT;
		IsolatedChar : USINT;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION EditorControl : BOOL (*Controls an HMI edit control*)
	VAR_INPUT
		Editor : HMI_EditControl_typ;
	END_VAR
END_FUNCTION

FUNCTION ControlTouch : UINT (*Handles a custom HMI control*)
	VAR_INPUT
		StatusDP : REFERENCE TO UINT;
	END_VAR
	VAR
		State : UINT;
	END_VAR
END_FUNCTION

FUNCTION ControlDismiss : BOOL (*Handles a custom HMI control*)
	VAR_INPUT
		StatusDP : REFERENCE TO UINT;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK Trend_ZoomScroll (*Smart handling of trend zooming and scaling*)
	VAR_INPUT
		ZoomBase : REAL; (*Factor for zooming in and out. Will be multiplied or divided by to zoom. E.g. a ZoomBase of 2 will double or half the range when zooming in or out, respectively.*)
		ZoomIn : BOOL; (*Zoom in command*)
		ZoomOut : BOOL; (*Zoom out command*)
		ScrollBase : REAL; (*Factor for scrolling positive or negative. Percentage of current range to scroll. E.g. a ScrollBase of 0.1 will scroll 10% of current range in the positive or negative direction.*)
		ScrollPos : BOOL; (*Scroll positive command*)
		ScrollNeg : BOOL; (*Scroll negative command*)
		Reset : BOOL; (*Reset to default scroll and zoom and set to AutoUpdate scrolling*)
	END_VAR
	VAR_OUTPUT
		ZoomDP : REAL; (*ZoomDatapoint for VC object*)
		ScrollDP : REAL; (*ScrollDatapoint for VC object*)
		ModeDP : UINT; (*Mode datapoint for time scrolling (1 = AutoUpdate, 0 = No AutoUpdate).*)
	END_VAR
	VAR
		Init : BOOL; (*Flag to set ZoomDP and ScrollDP to default values*)
		Midpt : REAL; (*Current midpoint of the display. Used to calculate scroll while zooming to maintain the midpoint of the display.*)
	END_VAR
END_FUNCTION_BLOCK
(*
Log Viewer
*)

FUNCTION LogViewerGetAlarmString : UDINT
	VAR_INPUT
		t : LogView_GetAlarm;
		AlarmIndex : UDINT;
		LoggerIdent : UDINT;
	END_VAR
	VAR_IN_OUT
		OutputString : STRING[LIST_BOX_STRING_SIZE];
	END_VAR
END_FUNCTION

FUNCTION LogViewerCreateString : BOOL (*Log Viewer helper function to create the log string*)
	VAR_INPUT
		ReadData : asarlogREAD;
		ASCIIData : ARRAY[0..255] OF USINT;
	END_VAR
	VAR_IN_OUT
		OutputString : STRING[LIST_BOX_STRING_SIZE];
	END_VAR
	VAR
		iString : STRING[LIST_BOX_STRING_SIZE];
		iConvString : STRING[LIST_BOX_STRING_SIZE];
	END_VAR
END_FUNCTION
(*
Editor Control Functions
*)

FUNCTION EditControl_CS_replaceline : UDINT (*Editor Control helper*)
	VAR_INPUT
		Text : STRING[80];
		Line : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_append : UDINT (*Editor Control helper*)
	VAR_INPUT
		Text : STRING[80];
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_getline : UDINT (*Editor Control helper *)
	VAR_INPUT
		Line : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_goto : UDINT (*Editor Control helper*)
	VAR_INPUT
		Line : UINT;
		Col : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_highlight : UDINT (*Editor Control helper*)
	VAR_INPUT
		Value : UINT;
		Mode : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_insert : UDINT (*Editor Control helper*)
	VAR_INPUT
		Text : STRING[80];
		Line : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_read : UDINT (*Editor Control helper*)
	VAR_INPUT
		Offset : UINT;
		Count : UINT;
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
	VAR
		temp : STRING[80];
	END_VAR
END_FUNCTION

FUNCTION EditControl_CS_replacemarked : UDINT (*Editor Control helper*)
	VAR_INPUT
		Text : STRING[80];
	END_VAR
	VAR_IN_OUT
		Output : STRING[80];
	END_VAR
END_FUNCTION
(*
Internal Functions, these functions should not be use, they are meant only for internal use
*)

FUNCTION HMI_FindCurrentTab : BOOL (*Function to find the current primary and secondary tab based on the current page*)
	VAR_IN_OUT
		t : HMI_Basic_typ; (*HMI_Basic control object*)
	END_VAR
	VAR
		p : UINT; (*Primary tab index*)
		ss : UINT; (*Secondary tab index*)
	END_VAR
END_FUNCTION

FUNCTION FindIndexOfString : DINT (*TODO: Add your comment here*)
	VAR_INPUT
		Value : STRING[LIST_BOX_STRING_SIZE];
		List : UDINT;
		MaxList : UDINT;
	END_VAR
	VAR
		Files : REFERENCE TO ARRAY[0..0] OF STRING[LIST_BOX_STRING_SIZE];
		iteration : UDINT;
		TempString : STRING[320];
		TempString1 : STRING[320];
	END_VAR
END_FUNCTION

FUNCTION RecipeMgr : DINT (*Manage copying recipes to and from a running system and the HMI*) (*$GROUP=User*)
	VAR_INPUT
		Rec : RecipeMgr_typ;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK FileQueue
	VAR_INPUT
		FileDevice : STRING[80];
		Path : STRING[320]; (*Maximum number of files that list will hold*)
		Next : BOOL;
		Cancel : BOOL;
	END_VAR
	VAR_OUTPUT
		FileName : STRING[80];
		Execute : BOOL;
		Done : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : UDINT;
	END_VAR
	VAR
		internal : RecipeUpdater_Internal_typ;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION GetDataObjectList : UINT (* *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		List : UDINT;
		MaxObjects : UDINT;
	END_VAR
	VAR
		Files : REFERENCE TO ARRAY[0..0] OF STRING[LIST_BOX_STRING_SIZE];
		index : UINT;
		numberVariables : UINT;
		objectIndex : UINT;
		Item : MO_List_typ;
		duplicate : BOOL;
	END_VAR
END_FUNCTION
