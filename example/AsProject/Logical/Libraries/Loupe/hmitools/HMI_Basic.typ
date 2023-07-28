(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: HMITypLib
 * File: HMITypLib.typ
 * Author: David
 * Created: March 10, 2011
 ********************************************************************
 * Data types of library HMITypLib
 ********************************************************************)

TYPE
	HMI_StatusBits_enum : 
		(
		HMI_STATBIT_VIS := 0,
		HMI_STATBIT_LOCK,
		HMI_STATBIT_FOCUS,
		HMI_STATBIT_TOUCHPAD
		);
	HMI_Layer_typ : 	STRUCT 
		StatusDP : UINT;
	END_STRUCT;
	HMI_Shape_typ : 	STRUCT 
		StatusDP : UINT;
		ColorDP : UINT;
	END_STRUCT;
	HMI_Scale_typ : 	STRUCT 
		Value : REAL;
		MinDP : REAL;
		MaxDP : REAL;
		RangeStartDP : REAL;
		RangeEndDP : REAL;
		RangeColorDP : UINT;
		StatusDP : UINT;
		ColorDP : UINT;
	END_STRUCT;
	HMI_Listbox_typ : 	STRUCT 
		IndexDP : DINT;
		MinDP : UINT;
		MaxDP : UINT;
		OptionDP : UINT;
		StatusDP : UINT;
		ColorDP : UINT;
		CompletionDP : UINT;
		PageSize : UINT;
	END_STRUCT;
	HMI_Bitmap_typ : 	STRUCT 
		IndexDP : UINT;
		StatusDP : UINT;
	END_STRUCT;
	HMI_StringIn_typ : 	STRUCT 
		String : STRING[HMI_STRLEN_IN];
		StatusDP : UINT;
		ColorDP : UINT;
		CompletionDP : UINT;
	END_STRUCT;
	HMI_Dropdown_typ : 	STRUCT 
		IndexDP : UINT;
		StatusDP : UINT;
		ColorDP : UINT;
	END_STRUCT;
	HMI_TextBox_typ : 	STRUCT 
		IndexDP : UINT;
		StatusDP : UINT;
		ColorDP : UINT;
	END_STRUCT;
	HMI_NumericIn_typ : 	STRUCT 
		Value : REAL;
		MinDP : REAL;
		MaxDP : REAL;
		StatusDP : UINT;
		ColorDP : UINT;
		CompletionDP : UINT;
	END_STRUCT;
	HMI_NumericOut_typ : 	STRUCT 
		Value : REAL;
		StatusDP : UINT;
		ColorDP : UINT;
	END_STRUCT;
	HMI_ButtonVC3_typ : 	STRUCT 
		CMD : USINT;
		Lock : UINT;
		ColorDP : UINT;
		LEDDP : USINT;
	END_STRUCT;
	HMI_Button_typ : 	STRUCT 
		CMD : BOOL;
		Confirm : BOOL;
		StatusDP : UINT;
		IndexDP : UINT;
		ColorDP : UINT;
		LEDDP : USINT;
	END_STRUCT;
	HMI_SecondaryTab_typ : 	STRUCT 
		ChangeToSecondaryTab : BOOL; (*CMD to change to this secondary tab*)
		PageIndex : UINT; (*Page index for this secondary tab*)
	END_STRUCT;
	HMI_PrimaryTab_typ : 	STRUCT 
		CurrentSecondaryTab : UINT; (*Current secondary tab*)
		ChangeToPrimaryTab : BOOL; (*CMD to change to this primary tab*)
		Group : UINT; (*Group to which the primary tab belongs*)
		SecondaryTabArray : ARRAY[0..HMI_MAI_TABS]OF HMI_SecondaryTab_typ; (*Array of secondary tabs*)
	END_STRUCT;
	HMI_Tabs_typ : 	STRUCT 
		CurrentPrimaryTab : UINT;
		PrimaryTabArray : ARRAY[0..HMI_MAI_TABS]OF HMI_PrimaryTab_typ;
	END_STRUCT;
	HMI_Basic_typ : 	STRUCT 
		PageChangeDP : UINT;
		PageCurrentDP : UINT;
		LanguageChangeDP : UINT;
		LanguageCurrentDP : UINT;
		ScreensaverDP : UINT;
		ScreensaverTimeDP : UINT;
		BacklightDP : UINT;
		BacklightTimeDP : UINT;
		CalibrationStateDP : UINT;
		VCHandle : UDINT;
		Tabs : HMI_Tabs_typ;
	END_STRUCT;
END_TYPE
