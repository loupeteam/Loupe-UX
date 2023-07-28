
{REDUND_ERROR} FUNCTION_BLOCK safeRemoteControl (*Remote Control Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		SafeLOGICStatus : RemoteControlStatusTypeV1; (*SafeLOGIC status*)
	END_VAR
	VAR
		i_state : UINT; (*internal variable*)
		i_result : UINT; (*internal variable*)
		i_tmp : UDINT; (*internal variable*)
		i_handle : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeRemoteControl_V2 (*Remote Control Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		SafeLOGICStatus : RemoteControlStatusTypeV2; (*SafeLOGIC status*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeDownloadApplication (*Download Application Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		ApplicationCRC : UDINT; (*application CRC*)
	END_VAR
	VAR
		i_state : UINT; (*internal variable*)
		i_result : UINT; (*internal variable*)
		i_tmp : UDINT; (*internal variable*)
		i_handle : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeDownloadApplication_V2 (*Download Application Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		ApplicationCRC : UDINT; (*application CRC*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeDownloadData (*Download Data Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,... *)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		Timestamp : UDINT; (*timestamp from data*)
	END_VAR
	VAR
		i_state : UINT; (*internal variable*)
		i_result : UINT; (*internal variable*)
		i_tmp : UDINT; (*internal variable*)
		i_handle : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeDownloadData_V2 (*Download Data Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,... *)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		Timestamp : UDINT; (*timestamp from data*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeConfigurationOnTarget (*Configuration On Target Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,...*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		Timestamp : UDINT; (*timestamp of data*)
	END_VAR
	VAR
		i_state : UINT; (*internal variable*)
		i_result : UINT; (*internal variable*)
		i_tmp : UDINT; (*internal variable*)
		i_handle : UDINT; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeConfigurationOnTarget_V2 (*Configuration On Target Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,...*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		Timestamp : UDINT; (*timestamp of data*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION safeLibraryVersion : UINT (*returns the actual library version*)
END_FUNCTION

{REDUND_ERROR} FUNCTION_BLOCK safeDownloadFile (*Download File Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		Timestamp : UDINT; (*timestamp from data*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeCheckTable (*Check Table Function Block*)
	VAR_INPUT
		Execute : BOOL; (*execution*)
		InstNr : USINT; (*instance number*)
		pUser : UDINT; (*user name*)
		Timestamp : UDINT; (*timestamp*)
		TableType : USINT; (*table type*)
		EntryCnt : UDINT; (*number of entries*)
		pTableHeader : UDINT; (*table header input*)
		pTableData : UDINT; (*table data input*)
		pTableHeaderOut : UDINT; (*table header output buffer*)
		pTableDataOut : UDINT; (*table data output buffer*)
		pFileDataOut : UDINT; (*file data output buffer*)
		AckData : USINT; (*1 .. acknowledge table data, 2 .. NOT acknowledge table data, abort FUB*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		CheckErrorCode : UDINT; (*table check error code*)
		CheckErrorLine : UDINT; (*table check error line*)
		CheckErrorColumn : UDINT; (*table check error column*)
		pCrcOut : UDINT; (*returns pointer to CRC data*)
		CrcCntOut : UDINT; (*returns number of CRCs*)
	END_VAR
	VAR
		i_step : UINT; (*internal*)
		i_tmp : UDINT; (*internal*)
		i_clean : BOOL; (*internal*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeFileInfo (*File Info Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,...*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION safeGetTableLength : UDINT (*Function returns size of table data*)
	VAR_INPUT
		TableType : USINT; (*table type*)
		EntryCnt : UDINT; (*number of entries*)
		pTableHeader : UDINT; (*pointer to table header*)
	END_VAR
END_FUNCTION

{REDUND_ERROR} FUNCTION_BLOCK safeGetDataLength (*Function Block returns size of download file*)
	VAR_INPUT
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,... *)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		Length : UDINT; (*calculated length of download file*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeCreateData (*Create Data Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeDATA_TYPE_MAOP, safeDATA_TYPE_EXTMAOP,... *)
		pCommandData : UDINT; (*pointer to command data*)
		FileDataOutLen : UDINT; (*size of buffer for file data*)
		pFileDataOut : UDINT; (*pointer to memory buffer for file data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
		UnlockRequired : BOOL; (*unlock required*)
		Timestamp : UDINT; (*timestamp from data*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_ERROR} FUNCTION_BLOCK safeLogicInfo (*Remote Control Function Block*)
	VAR_INPUT
		SafeLOGICID : UINT; (*SafeLOGIC ID*)
		Execute : BOOL; (*execution*)
		Type : UINT; (*type of data: safeINFO_TYPE_PWD_INFO, safeINFO_TYPE_PWD_CHK, safeINFO_TYPE_UDID_INFO*)
		pCommandData : UDINT; (*pointer to command data*)
	END_VAR
	VAR_OUTPUT
		Done : BOOL; (*execution done*)
		Busy : BOOL; (*execution busy*)
		Error : BOOL; (*execution error*)
		StatusID : UINT; (*execution status: ERR_OK, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		Internal : AsSafetyInternalType; (*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
