(*
 * File: Persist.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of Persist, licensed under the MIT License.
 *
 * ********************************************************************
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
