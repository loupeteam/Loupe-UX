(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Persist
 * File: Persist.typ
 * Author: davidblackburn
 * Created: October 04, 2013
 ********************************************************************
 * Data types of library Persist
 ********************************************************************)
(*Public types*)

TYPE
	PERSIST_ERR_enum : 
		(
		PERSIST_ERR_INVALIDINPUT := 50000,
		PERSIST_ERR_OUTOFMEMORY,
		PERSIST_ERR_DATAMOVED_CHANGED
		);
	Persistence_Int_VarInfo_typ : 	STRUCT 
		pWorkingVariable : UDINT;
		sizeofWorkingVariable : UDINT;
		pPersistentMemory : UDINT;
	END_STRUCT;
	Persistence_Internal_typ : 	STRUCT 
		WorkingVariableInfo : ARRAY[0..PERSIST_MAI_VARLIST]OF Persistence_Int_VarInfo_typ;
		ValidWorkingVariable : Persistence_Int_VarInfo_typ;
		iVariable : USINT;
		DataValid : BOOL;
	END_STRUCT;
	Persistence_OUT_STAT_typ : 	STRUCT 
		RequiredMemory : UDINT; (*Number of bytes required to store every variable in WorkingVariableList*)
		Initialized : BOOL;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[PERSIST_STRLEN_ERRORSTRING];
	END_STRUCT;
	Persistence_OUT_typ : 	STRUCT 
		STAT : Persistence_OUT_STAT_typ;
	END_STRUCT;
	Persistence_IN_typ : 	STRUCT 
		pPersistentVariable : UDINT; (*Address of the persistent variable*)
		sizeofPersistentVariable : UDINT; (*Size of the persistent variable*)
		pDataValid : UDINT; (*Address of the DataValid variable. If *pDataValid == TRUE, then persistent memory is copied to working memory on startup. If *pDataValid == FALSE, then persistent memory is NOT copied to working memory*)
		WorkingVariableList : ARRAY[0..PERSIST_MAI_VARLIST]OF STRING[PERSIST_STRLEN_VARNAME]; (*List of working variables to be managed*)
	END_STRUCT;
	Persistence_typ : 	STRUCT 
		IN : Persistence_IN_typ;
		OUT : Persistence_OUT_typ;
		Internal : Persistence_Internal_typ;
	END_STRUCT;
END_TYPE
