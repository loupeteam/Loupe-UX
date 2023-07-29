
FUNCTION_BLOCK tgProtect
	VAR_INPUT
		productCode : UDINT;
		orderNumber : STRING[255];
		description : STRING[255];
		reaction : DWORD;
		allowSimulation : BOOL;
	END_VAR
	VAR_OUTPUT
		status : UINT;
		licenseRegistered : BOOL;
		licenseOk : BOOL;
		availableLicenses : UDINT;
		neededLicenses : UDINT;
		licenseIdent : UDINT;
	END_VAR
	VAR
		internal : tgProtect_internal_typ;
	END_VAR
END_FUNCTION_BLOCK
