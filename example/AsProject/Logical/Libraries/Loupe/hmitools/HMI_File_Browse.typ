(*
* File: HMI_File_Browse.typ
* Copyright (c) 2023 Loupe
* https://loupe.team
* 
* This file is part of HMITools, licensed under the MIT License.
* 
*)

TYPE
	HMI_File_Browse_internal_typ : 	STRUCT 
		TempFileList : UDINT;
		TempFileSelection : STRING[LIST_BOX_STRING_SIZE];
		oldFileIndex : DINT;
		oldFileSelection : STRING[LIST_BOX_STRING_SIZE];
		NameFilter : STRING[LIST_BOX_STRING_SIZE];
		PathStrSize : UINT;
		InternalBrowsingPath : STRING[LIST_BOX_STRING_SIZE];
		i : UINT;
		IsolatedChar : USINT;
		FileNameSelector : ListBoxFub;
		FileExtensionSelector : ListBoxFub;
		Directory : DirectoryFub;
		TON_0 : TON;
	END_STRUCT;
END_TYPE
