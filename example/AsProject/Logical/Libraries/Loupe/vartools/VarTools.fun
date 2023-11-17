(*
 * File: VarTools.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of VarTools, licensed under the MIT License.
 *
 *)

FUNCTION varGetInfo : UINT (*Get variable information*) (*$GROUP=User*)
	VAR_INPUT
		pVariable : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varGetValue : UINT (*Get the value of a variable as a string*) (*$GROUP=User*)
	VAR_INPUT
		pVariable : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varGetLrealValue : UINT (*Get the value of a variable as an lreal*)
	VAR_INPUT
		pVariable : UDINT;
		pValue : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varGetRealValue : UINT (*Get the value of a variable as a real*) (*$GROUP=User*)
	VAR_INPUT
		pVariable : UDINT;
		pValue : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varRefresh : UINT (*Force refresh of variable information in next getValue call*)
	VAR_INPUT
		pVariable : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varSetValue : UINT (*Set the value of a variable from a string*) (*$GROUP=User*)
	VAR_INPUT
		pVariable : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varGetVariableList : UINT (*Get a list of all local and global variables with a given name*) (*$GROUP=User*)
	VAR_INPUT
		pVariableName : UDINT;
		List : UDINT;
	END_VAR
END_FUNCTION

FUNCTION varPopulateMemberNames : BOOL
	VAR_INPUT
		PVName : STRING[80];
		prefix : USINT;
	END_VAR
END_FUNCTION

FUNCTION_BLOCK varVariableWatch
	VAR_INPUT
		pVariable : {REDUND_UNREPLICABLE} UDINT;
	END_VAR
	VAR_OUTPUT
		Status : UINT;
	END_VAR
	VAR
		iName : STRING[VAR_STRLEN_NAME];
		iValue : STRING[VAR_STRLEN_VALUE];
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK variableBrowser (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		VariableName : STRING[VAR_STRLEN_VALUE];
		MemberIndex : INT;
		Back : BOOL;
	END_VAR
	VAR_OUTPUT
		CurrentVariable : STRING[VAR_STRLEN_VALUE];
		MemberName : ARRAY[0..VAR_MAI_MEMBERS] OF STRING[VAR_STRLEN_NAME];
		MemberValue : ARRAY[0..VAR_MAI_MEMBERS] OF STRING[VAR_STRLEN_VALUE];
		MemberInfo : ARRAY[0..VAR_MAI_MEMBERS] OF varVariable_typ;
		NumberMembers : UINT;
		info : varVariable_typ;
	END_VAR
	VAR
		iMemberWatch : ARRAY[0..VAR_MAI_MEMBERS] OF varVariableWatch;
		iCurrentWatch : varVariableWatch;
		iLevel : ARRAY[0..19] OF STRING[32];
		iLevelIndex : USINT;
		iMemberIndex : USINT;
	END_VAR
END_FUNCTION_BLOCK
