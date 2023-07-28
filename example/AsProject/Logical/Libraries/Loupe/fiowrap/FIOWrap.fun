(********************************************************************
 * COPYRIGHT --  Automation Resources Group
 ********************************************************************
 * Library: FIOWrap
 * File: FIOWrap.fun
 * Author: blackburnd
 * Created: June 18, 2009
 ********************************************************************
 * Functions and function blocks of library FIOWrap
 ********************************************************************)

FUNCTION FIOManageFn_Cyclic : BOOL
	VAR_IN_OUT
		t : FIOManage_typ;
	END_VAR
END_FUNCTION

FUNCTION FIOWrapFn_Cyclic : BOOL (*This function manages file reads and writes.*)
	VAR_IN_OUT
		t : FIOWrap_typ; (*FIOWrap Mgr structure*)
	END_VAR
END_FUNCTION

FUNCTION fiowSetError : BOOL (*Set error status on FIOWrap*)
	VAR_INPUT
		ErrorID : UINT;
	END_VAR
	VAR_IN_OUT
		t : FIOWrap_typ;
	END_VAR
END_FUNCTION

FUNCTION fiomSetError : BOOL
	VAR_INPUT
		ErrorID : UINT;
	END_VAR
	VAR_IN_OUT
		t : FIOManage_typ;
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION fioOpenFile_Init : UINT (*Open a file in the init subroutine*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_IN_OUT
		t : FIOWrap_typ;
	END_VAR
END_FUNCTION
