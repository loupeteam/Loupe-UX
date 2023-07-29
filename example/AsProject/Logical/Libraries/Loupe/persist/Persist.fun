(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: Persist
 * File: Persist.fun
 * Author: davidblackburn
 * Created: October 04, 2013
 ********************************************************************
 * Functions and function blocks of library Persist
 ********************************************************************)

FUNCTION PersistFn_Init : UINT (*Copy values from persistent memory to working memory*) (*$GROUP=User*)
	VAR_IN_OUT
		Persistence : Persistence_typ;
	END_VAR
END_FUNCTION

FUNCTION PersistFn_Cyclic : UINT (*Copy values from working memory to persistent memory*) (*$GROUP=User*)
	VAR_IN_OUT
		Persistence : Persistence_typ;
	END_VAR
END_FUNCTION

FUNCTION persistInternalMapMemory : UINT (*Internal: Determine memory addresses*) (*$GROUP=User*)
	VAR_IN_OUT
		Persistence : Persistence_typ;
	END_VAR
END_FUNCTION

FUNCTION persistInternalBackup : UINT (*Internal: Backup to persistent memory*) (*$GROUP=User*)
	VAR_IN_OUT
		Persistence : Persistence_typ;
	END_VAR
END_FUNCTION

FUNCTION persistInternalRestore : UINT (*Internal: Restore from persistent memory*) (*$GROUP=User*)
	VAR_IN_OUT
		Persistence : Persistence_typ;
	END_VAR
END_FUNCTION
