                                                                      
TYPE		
	dongleInfo_t  : STRUCT					(*information of a B&R dongle*)
		boxMask			:UINT;				(*boxmask*)
		serNo			:UDINT;				(*serial number*)
		majorFirmwareVersion	:USINT;		(*major firmware version*)
		minorFirmwareVersion	:USINT; 	(*minor firmware version*)
	END_STRUCT;	
	
	licenseInfo_t  : STRUCT					(*license details*)
		firmCode 		: UDINT; 			(*firm code of the license*)
		productCode		: UDINT; 			(*product code of the license*)
		count			: UDINT;			(*number of available licenses*)
		orderNumber		: STRING[255];		(*order number of the license*)
		description		: STRING[255];		(*license description*)		
	END_STRUCT;
	
	neededLicenseInfo_t  : STRUCT			(*details of a needed license*)
		firmCode 		: UDINT; 			(*firm code of the license*)
		productCode		: UDINT; 			(*product code of the license*)
		neededCount		: UDINT;			(*needed number of licenses*)
		count			: UDINT;			(*number of available licenses*)
		reaction		: DWORD; 			(*reaction in case of missing license*)
		orderNumber		: STRING[255];		(*order number of the license*)
		description		: STRING[255];		(*license description*)		
	END_STRUCT;
END_TYPE
