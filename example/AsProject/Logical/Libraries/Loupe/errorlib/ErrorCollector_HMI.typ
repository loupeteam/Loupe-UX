(*
 * File: ErrorCollector_HMI.typ
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of ErrorLib, licensed under the MIT License.
 * 
  ********************************************************************
 * Data types of library ErrorLib
 ********************************************************************)

TYPE
	ErrorCollector_HMI_Internal_typ : 	STRUCT 
		ErrorIndex : ARRAY[0..ERRCOL_MAI_ERRORINFO]OF UINT;
		NumDisplayErrors : UINT;
		OldNumErrors : UINT;
		OldSearchString : STRING[ERRCOL_STRLEN_DISPLAYSTRING];
	END_STRUCT;
	ErrorCollector_HMI_typ : 	STRUCT 
		SearchString : STRING[ERRCOL_STRLEN_DISPLAYSTRING];
		ErrorList : ARRAY[0..ERRCOL_MAI_ERRORINFO]OF STRING[ERRCOL_STRLEN_DISPLAYSTRING];
		ErrorListbox : HMI_Listbox_typ;
		ErrorText : STRING[ERRCOL_STRLEN_DISPLAYSTRING];
		Acknowledge : HMI_Button_typ;
		AcknowledgeAll : HMI_Button_typ;
		Internal : ErrorCollector_HMI_Internal_typ;
	END_STRUCT;
END_TYPE
