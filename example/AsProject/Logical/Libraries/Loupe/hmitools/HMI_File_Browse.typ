(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: HMITools
 * File: HMI_File_Browse.typ
 * Author: David Blackburn
 * Created: March 22, 2012
 ********************************************************************
 * Data types of library HMITools
 ********************************************************************)

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
