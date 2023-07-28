
TYPE
	tgProtect_internal_typ : 	STRUCT 
		FUB : tgProtect_int_FUB_typ;
	END_STRUCT;
	tgProtect_int_FUB_typ : 	STRUCT 
		registerLicense : guardRegisterLicense;
		checkLicense : guardCheckLicense;
	END_STRUCT;
END_TYPE
