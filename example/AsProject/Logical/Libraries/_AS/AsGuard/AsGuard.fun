 
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardRegisterLicense 		(*registers a license for guarding*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		firmCode 		: UDINT; 			(*firm code of the license*)
		productCode		: UDINT; 			(*product code of the license*)
		orderNumber		: STRING[255];		(*order number of the license*)
		description		: STRING[255];		(*license description*)		
		registerType	: DWORD;			(*register license always or only if license is available*)
		reaction		: DWORD; 			(*reaction in case of missing license*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT;				(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident 			: UDINT;			(*identifier of the license*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardCheckLicense (*checks the status of a license*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		ident 			: UDINT; 			(*identifier of the license*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		availableLicenses: UDINT;			(*available licenses*)
		neededLicenses	: UDINT;			(*needed licenses*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardDeregisterLicense 		(*deregisters a license from guarding*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		ident			: UDINT; 			(*identifier of the license*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetContext      		(*reads the context data of the specified dongle*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
		firmCode 		: UDINT; 			(*firm code*)
		maxContextDataCount : UDINT;        (*maximum size of the buffer for the context data*)
		pContextData	: UDINT;			(*pointer to the buffer for the context data*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		contextDataCount : UDINT;			(*current size of context data, in case of error the required size of context data*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardUpdateLicenses      	(*programs a dongle with the licenses specified in the license data buffer*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		licenseDataCount: UDINT;			(*license data size*)
		pLicenseData	: UDINT;			(*license data*)		
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetDongles			 	(*gets dongle with the licenses specified in the license files*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		pDongleInfos 	: REFERENCE TO dongleInfo_t;	(*buffer to store the dongle information*)
		dongleInfoSize	: UDINT;			(*size of the array "pDongleInfos"*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		neededSize		: UDINT; 			(*used or needed array size*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardReadOperatingTime(*reads operating time*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
		counterType	    : UDINT;		    (*type of the counter*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		operatingTime   : UDINT;			(*operating time*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardStartCustomOpTimeCounter(*starts customer operating time counter*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
		counterType	    : UDINT;		    (*type of the counter*)
		cfgUpdateSeconds: UDINT;		    (*seconds until next counter update*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident           : UDINT;            (*ident*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardStopCustomOpTimeCounter(*stops customer operating time counter*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		ident	 		: UDINT; 			(*ident*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardReadData			 	(*reads user data*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		userData 	    : ARRAY [0..241] OF USINT;	(*buffer to store the user data*)
		usedSize		: UDINT; 			(*used array size*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardWriteData			 	(*writes user data*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
		userData 	    : ARRAY [0..241] OF USINT;	(*user data*)
		userDataLen		: UDINT;			(*used buffer size*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetStatus			 	(*gets the license status of the target*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, guardERR_LICENSE_STATUS_UNKNOWN, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		licenseOk	 	: BOOL; 			(*current license status ok?*)
		reactionStatus 	: DWORD; 			(*reaction status*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetLicenses			 	(*gets the available licenses on the target*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		maxNumLicenses	: UDINT;			(*maximal number of licenses in buffer*)
		pLicenses		: UDINT;			(*buffer for licenses (ARRAY of licenseInfo_t)*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		numLicenses		: UDINT;			(*number of licenses on target*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetDongleLicenses		(*gets the available licenses of a specified dongle on the target*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		boxMask 		: UINT; 			(*box mask of the dongle*)
		serNo			: UDINT; 			(*serial number of the dongle*)
		maxNumLicenses	: UDINT;			(*maximal number of licenses in buffer*)
		pLicenses		: UDINT;			(*buffer for licenses (ARRAY of licenseInfo_t)*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		numLicenses		: UDINT;			(*number of licenses on target*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK guardGetNeededLicenses		(*gets the needed licenses*)
	VAR_INPUT
		enable 			: BOOL; 			(*enables execution*)
		maxNumNeededLicenses	: UDINT;	(*maximal number of needed licenses in buffer*)
		pNeededLicenses	: UDINT;			(*buffer for needed licenses (ARRAY of neededLicenseInfo_t)*)
	END_VAR
	VAR_OUTPUT
		status 			: UINT; 			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		numNeededLicenses	: UDINT;		(*number of needed licenses on target*)
	END_VAR
	VAR
		_statemachine	: UINT;				(*internal variable*)
		_result			: UINT;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
