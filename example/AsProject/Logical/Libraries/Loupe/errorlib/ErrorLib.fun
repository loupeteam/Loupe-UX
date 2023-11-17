(*
 * File: ErrorLib.fun
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of ErrorLib, licensed under the MIT License.
 * 
  ********************************************************************
 * Functions and function blocks of library ErrorLib
 ********************************************************************)

FUNCTION errcolAddSourceByAddress : UINT (*Add a source to the ErrorCollector by providing addresses. This relaxes the restriction on data types*)
	VAR_INPUT
		pSourceName : UDINT;
		pErrorActive : UDINT;
		pErrorString : UDINT;
		pErrorID : UDINT;
		pAcknowledge : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolAddSourceByName : UINT (*Add a source to the ErrorCollector by providing a variable name. This requires the variable to have certain elements*)
	VAR_INPUT
		pSourceName : UDINT;
		pVarName : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolAddError : UINT (*User function to add an error to the error list*)
	VAR_INPUT
		pSourceName : UDINT;
		pErrorString : UDINT;
		ErrorID : UINT;
		pAcknowledge : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolAcknowledge : UINT (*Acknowledge an error in the error list*)
	VAR_INPUT
		ErrorIndex : UINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION ErrorCollectorFn_Init : UINT (*Initialize an ErrorCollector*)
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION ErrorCollectorFn_Cyclic : UINT (*Cyclic control of an ErrorCollector*)
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION ErrorCollectorFn_HMI_Cyclic : UINT (*Cyclic HMI handling for ErrorCollector*)
	VAR_IN_OUT
		HMI : ErrorCollector_HMI_typ;
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalSetError : UINT (*Set error status on ErrorCollector*)
	VAR_INPUT
		ErrorID : UINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolIntGenerateDisplayString : UINT (*Generate a string for display and logging*)
	VAR_INPUT
		pDisplayString : UDINT;
		DisplayStringLength : UDINT;
		pTimestamp : UDINT;
		pSourceName : UDINT;
		ErrorID : UINT;
		pErrorString : UDINT;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalAddError : UINT (*Internal function to add an error to the error list*)
	VAR_INPUT
		SourceIndex : UINT;
		pTimestamp : UDINT;
		pSourceName : UDINT;
		pSourceTask : UDINT;
		ErrorID : UINT;
		pErrorString : UDINT;
		pAcknowledge : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalLogError : UINT (*Add an error to the logger*)
	VAR_INPUT
		pSourceName : UDINT;
		ErrorID : UINT;
		pErrorString : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalLogAcknowledge : UINT (*Log that an error was acknowledged*)
	VAR_INPUT
		pSourceName : UDINT;
		ErrorID : UINT;
		pErrorString : UDINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalRemoveError : UINT (*Remove an error from the error list*)
	VAR_INPUT
		ErrorIndex : UINT;
	END_VAR
	VAR_IN_OUT
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION

FUNCTION errcolInternalRefreshHMIDisplay : UINT (*Refresh the HMI display array*)
	VAR_IN_OUT
		HMI : ErrorCollector_HMI_typ;
		t : ErrorCollector_typ;
	END_VAR
END_FUNCTION
