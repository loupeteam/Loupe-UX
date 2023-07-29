(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Library: AsSafety
 * File: AsSafety.typ
 * Author: B&R
 * Created: May 25, 2012
 ********************************************************************
 * Data types of library AsSafety
 ********************************************************************)

TYPE
	FileReferenceType : 	STRUCT  (*file reference*)
		Device : STRING[80]; (*pointer to the device name*)
		File : STRING[80]; (*pointer to the file name*)
	END_STRUCT;
	AsSafetyInternalType : 	STRUCT  (*internal data type*)
		Clean : BOOL;
		State : UINT;
		Result : UINT;
		Tmp : UDINT;
		pThis : UDINT;
		pFcn : UDINT;
	END_STRUCT;
	SourceLocalDataTypeV1 : 	STRUCT  (*local data source type*)
		pFileData : UDINT; (*pointer to data buffer*)
		FileLength : UDINT; (*data length*)
	END_STRUCT;
	SourceLocalFileTypeV1 : 	STRUCT  (*local file source*)
		SourceFile : FileReferenceType; (*path to local file*)
	END_STRUCT;
	DataSourceTypeV1 : 	STRUCT  (*source data type*)
		Type : UINT; (*0 .. file upload from safeLOGIC, 1 .. local data buffer, 2 .. local file*)
		LocalData : SourceLocalDataTypeV1; (*arguments for local data*)
		LocalFile : SourceLocalFileTypeV1; (*arguments for local file*)
	END_STRUCT;
	InfoCmdPwdInfoTypeV1 : 	STRUCT  (*password info data from SafeLOGIC command structure*)
		Version : UINT; (*used version*)
		PasswordSet : BOOL; (*0 .. no password set, 1 .. password is set*)
	END_STRUCT;
	InfoCmdPwdChkTypeV1 : 	STRUCT  (*password check data from SafeLOGIC command structure*)
		Version : UINT; (*used version*)
		Password : STRING[16]; (*password for check*)
		PasswordEqual : BOOL; (*0 .. no password set, 1 .. password is set*)
	END_STRUCT;
	ConfigurationAddParaTypeV2 : 	STRUCT  (*additional parameter data from SafeLOGIC*)
		SADR : UINT; (*safety address*)
		ID : USINT; (*id*)
		pParaData : UDINT; (*pointer to additional parameter data*)
		Length : UDINT; (*size of parameter buffer*)
		LengthOut : UDINT; (*length of parameter*)
		CRC : UDINT; (*CRC*)
		Timestamp : UDINT; (*timestamp*)
	END_STRUCT;
	ConfigurationAddParaTypeV1 : 	STRUCT  (*additional parameter data from SafeLOGIC*)
		SADR : UINT; (*safety address*)
		ID : USINT; (*id*)
		pParaData : UDINT; (*pointer to additional parameter data*)
		Length : UDINT; (*size of parameter buffer*)
		CRC : UDINT; (*CRC*)
		Timestamp : UDINT; (*timestamp*)
	END_STRUCT;
	ConfigurationBitOptionsTypeV1 : 	STRUCT  (*bit machine options*)
		BitData : ARRAY[0..63]OF USINT; (*bit array*)
	END_STRUCT;
	ConfigurationCmdAddParaTypeV2 : 	STRUCT  (*additional parameter data from SafeLOGIC command structure*)
		Version : UINT; (*input data: used version*)
		Password : STRING[16]; (*input data: password*)
		pParaDataOutput : UDINT; (*input data: pointer to list of type ConfigurationAddParaTypeV2*)
		NumberParaSetsOutput : UINT; (*input data: number of available entries in pParaDataOutput*)
		NumberParaSetsOutputOut : UINT; (*return value: number of returned entries*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	ConfigurationCmdAddParaTypeV1 : 	STRUCT  (*additional parameter data from SafeLOGIC command structure*)
		Version : UINT; (*input data: used version*)
		Password : STRING[16]; (*input data: password*)
		pParaDataOutput : UDINT; (*return value: pointer to list of type ConfigurationAddParaTypeV1*)
		NumberParaSetsOutput : UINT; (*return value: number of returned entries*)
	END_STRUCT;
	ConfigurationCmdExtMaOpTypeV2 : 	STRUCT  (*extended machine options from SafeLOGIC command structure*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		pIntDataOutput : UDINT; (*input data: pointer to list of type ConfigurationIntOptionsTypeV1*)
		NumberIntOutput : UINT; (*input data: number of available entries in INT buffer*)
		NumberIntOutputOut : UINT; (*return value: number of returned INT data entries*)
		pUintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationUintOptionsTypeV1*)
		NumberUintOutput : UINT; (*input data: number of available entries in UINT buffer*)
		NumberUintOutputOut : UINT; (*return value: number of returned UINT data entries*)
		pDintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationDintOptionsTypeV1*)
		NumberDintOutput : UINT; (*input data: number of available DINT data entries*)
		NumberDintOutputOut : UINT; (*return value: number of returned DINT data entries*)
		pUdintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationUdintOptionsTypeV1*)
		NumberUdintOutput : UINT; (*input data: number of available UDINT data entries*)
		NumberUdintOutputOut : UINT; (*return value: number of returned UDINT data entries*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	ConfigurationCmdExtMaOpTypeV1 : 	STRUCT  (*extended machine options from SafeLOGIC command structure*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		pIntDataOutput : UDINT; (*return value: pointer to list of type ConfigurationIntOptionsTypeV1*)
		NumberIntOutput : UINT; (*return value: number of returned INT data entries*)
		pUintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationUintOptionsTypeV1*)
		NumberUintOutput : UINT; (*return value: number of returned UINT data entries*)
		pDintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationDintOptionsTypeV1*)
		NumberDintOutput : UINT; (*return value: number of returned DINT data entries*)
		pUdintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationUdintOptionsTypeV1*)
		NumberUdintOutput : UINT; (*return value: number of returned UDINT data entries*)
	END_STRUCT;
	ConfigurationCmdMaOpTypeV2 : 	STRUCT  (*machine options from SafeLOGIC command structure Version 2*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		pDeviceListOutput : UDINT; (*input data: pointer to device list buffer of type ConfigurationDeviceTypeV1*)
		NumberDevicesOutput : UINT; (*input data: number of available device entries in devices list buffer*)
		NumberDevicesOutputOut : UINT; (*return value: number of returned device entries*)
		pMachineOptionsOutput : UDINT; (*input data: pointer to bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsOutput : UDINT; (*input data: pointer to module flags of type ConfigurationModuleFlagsTypeV1*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	ConfigurationCmdMaOpTypeV1 : 	STRUCT  (*machine options from SafeLOGIC command structure Version 1*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		pDeviceListOutput : UDINT; (*return value: pointer to device list of type ConfigurationDeviceTypeV1*)
		NumberDevicesOutput : UINT; (*return value: number of returned entries*)
		pMachineOptionsOutput : UDINT; (*return value: pointer to bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsOutput : UDINT; (*return value: pointer to module flags of type ConfigurationModuleFlagsTypeV1*)
	END_STRUCT;
	ConfigurationCmdTableTypeV2 : 	STRUCT  (*table data from SafeLOGIC command structure*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		pTableDataOutput : UDINT; (*input data: pointer to list of type ConfigurationTableTypeV1*)
		NumberTablesOutput : UINT; (*input data: number of available entries in pTableDataOutput*)
		NumberTablesOutputOut : UINT; (*return value: number of returned table entries*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	ConfigurationCmdTableTypeV1 : 	STRUCT  (*table data from SafeLOGIC command structure*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		pTableDataOutput : UDINT; (*return value: pointer to list of type ConfigurationTableTypeV1*)
		NumberTablesOutput : UINT; (*return value: number of returned table entries*)
	END_STRUCT;
	FileInfoCmdTypeV1 : 	STRUCT  (*file info command structure*)
		Version : UINT; (*used version*)
		DataSource : DataSourceTypeV1; (*data source*)
		Timestamp : UDINT; (*timestamp*)
		pCrcs : UDINT; (*buffer for CRCs*)
		NumberOfCrcs : UINT; (*size of CRC buffer*)
		NumberOfCrcsOut : UINT; (*number of CRCs*)
	END_STRUCT;
	ConfigurationDeviceTypeV1 : 	STRUCT  (*safety device from SafeLOGIC*)
		SADR : UINT; (*safety address*)
		UDID : ARRAY[0..5]OF USINT; (*UDID*)
	END_STRUCT;
	ConfigurationDintOptionsTypeV1 : 	STRUCT  (*DINT machine options*)
		ID : UINT; (*id*)
		Value : DINT; (*value*)
	END_STRUCT;
	ConfigurationIntOptionsTypeV1 : 	STRUCT  (*INT machine options*)
		ID : UINT; (*id*)
		Value : INT; (*value*)
	END_STRUCT;
	ConfigurationModuleFlagsTypeV1 : 	STRUCT  (*module flags*)
		Optional : ARRAY[0..127]OF USINT; (*optional*)
		Startup : ARRAY[0..127]OF USINT; (*startup*)
		NotPresent : ARRAY[0..127]OF USINT; (*not present*)
	END_STRUCT;
	ConfigurationTableTypeV2 : 	STRUCT  (*table data for command struct V1*)
		ID : UINT; (*table id*)
		Type : USINT; (*table type*)
		NumberOfCRCs : UINT; (*input data: number of available entries in pCRCData*)
		NumberOfCRCsOut : UINT; (*return value: number of returned CRC entries*)
		pCRCData : UDINT; (*input data: pointer to table CRC buffer*)
	END_STRUCT;
	ConfigurationTableTypeV1 : 	STRUCT  (*table data for command struct V2*)
		ID : UINT; (*table id*)
		Type : USINT; (*table type*)
		NumberOfCRCs : UINT; (*return value: number of returned CRCs*)
		pCRCData : UDINT; (*return value: pointer to table CRC buffer*)
	END_STRUCT;
	ConfigurationUdintOptionsTypeV1 : 	STRUCT  (*UDINT machine options*)
		ID : UINT; (*id*)
		Value : UDINT; (*value*)
	END_STRUCT;
	ConfigurationUintOptionsTypeV1 : 	STRUCT  (*UINT machine options*)
		ID : UINT; (*id*)
		Value : UINT; (*value*)
	END_STRUCT;
	DownloadAcknExtMaOpTypeV1 : 	STRUCT  (*acknowledge extended machine options structure*)
		AcknIntOptions : ARRAY[0..63]OF BOOL; (*acknowledge INT*)
		AcknUintOptions : ARRAY[0..63]OF BOOL; (*acknowledge UINT*)
		AcknDintOptions : ARRAY[0..63]OF BOOL; (*acknowledge DINT*)
		AcknUdintOptions : ARRAY[0..63]OF BOOL; (*acknowledge UDINT*)
	END_STRUCT;
	DownloadAcknMaOpTypeV1 : 	STRUCT  (*acknowledge bit machine options structure*)
		AcknBitOptions : ARRAY[0..63]OF USINT; (*acknowledge bit*)
	END_STRUCT;
	DownloadAcknAddParaTypeV1 : 	STRUCT  (*acknowledge bit additional parameter*)
		AcknBitAddPara : ARRAY[0..63]OF USINT; (*acknowledge bit*)
	END_STRUCT;
	DownloadCmdAddParaTypeV2 : 	STRUCT  (*additional paramater command structure*)
		Version : UINT; (*input data: used version*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pParaListInput : UDINT; (*input data: pointer to additional parameter input data list of type DownloadAddParaTypeV1*)
		NumberParaSetsInput : UINT; (*input data: number of input parameter entries in pParaListInput*)
		pParaDataOutput : UDINT; (*input data: pointer to list of type ConfigurationAddParaTypeV2*)
		NumberParaSetsOutput : UINT; (*input data: number of available entries in pParaDataOutput*)
		NumberParaSetsOutputOut : UINT; (*return value: number of returned entries*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	DownloadCmdAddParaTypeV1 : 	STRUCT  (*additional paramater command structure*)
		Version : UINT; (*input data: used version*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pParaListInput : UDINT; (*input data: pointer to additional parameter input data list of type DownloadAddParaTypeV1*)
		NumberParaSetsInput : UINT; (*input data: number of input parameter entries in pParaListInput*)
		pParaDataOutput : UDINT; (*return value: pointer to list of type ConfigurationAddParaTypeV1*)
		NumberParaSetsOutput : UINT; (*return value: number of returned entries*)
	END_STRUCT;
	DownloadCmdApplicationTypeV1 : 	STRUCT  (*application command structure*)
		Version : UINT; (*used version*)
		Password : STRING[16]; (*password*)
		UDID_Low : UDINT; (*UDID low*)
		UDID_High : UINT; (*UDID high*)
		ApplicationID : UINT; (*application id*)
		Device : STRING[80]; (*device for file*)
		File : STRING[80]; (*file name*)
		Unlock : USINT; (*unlock application*)
	END_STRUCT;
	DownloadCmdExtMaOpTypeV2 : 	STRUCT  (*extended machine options command structure*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pIntDataInput : UDINT; (*input data: pointer to INT input data list from type ConfigurationIntOptionsTypeV1*)
		NumberIntInput : UINT; (*input data: number of INT input entries in pIntDataInput*)
		pUintDataInput : UDINT; (*input data: pointer to UINT input data list from type ConfigurationUintOptionsTypeV1*)
		NumberUintInput : UINT; (*input data: number of UINT input entries in pUintDataInput*)
		pDintDataInput : UDINT; (*input data: pointer to DINT input data list from type ConfigurationDintOptionsTypeV1*)
		NumberDintInput : UINT; (*input data: number of DINT input entries in pDintDataInput*)
		pUdintDataInput : UDINT; (*input data: pointer to UDINT input data list from type ConfigurationUdintOptionsTypeV1*)
		NumberUdintInput : UINT; (*input data: number of UDINT input entries in pUdintDataInput*)
		pAcknMachineOptions : UDINT; (*input data: pointer to acknowledge information of type DownloadAcknMaOpTypeV1*)
		pIntDataOutput : UDINT; (*input data: pointer to list of type ConfigurationIntOptionsTypeV1*)
		NumberIntOutput : UINT; (*input data: number of available entries in INT buffer*)
		NumberIntOutputOut : UINT; (*return value: number of returned INT data entries*)
		pUintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationUintOptionsTypeV1*)
		NumberUintOutput : UINT; (*input data: number of available entries in UINT buffer*)
		NumberUintOutputOut : UINT; (*return value: number of returned UINT data entries*)
		pDintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationDintOptionsTypeV1*)
		NumberDintOutput : UINT; (*input data: number of available DINT data entries*)
		NumberDintOutputOut : UINT; (*return value: number of returned DINT data entries*)
		pUdintDataOutput : UDINT; (*input data: pointer to list of type ConfigurationUdintOptionsTypeV1*)
		NumberUdintOutput : UINT; (*input data: number of available UDINT data entries*)
		NumberUdintOutputOut : UINT; (*number of UDINT channels from SafeLOGIC*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	DownloadCmdExtMaOpTypeV1 : 	STRUCT  (*return value: number of returned UDINT data entries*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pIntDataInput : UDINT; (*input data: pointer to INT input data list from type ConfigurationIntOptionsTypeV1*)
		NumberIntInput : UINT; (*input data: number of INT input entries in pIntDataInput*)
		pUintDataInput : UDINT; (*input data: pointer to UINT input data list from type ConfigurationUintOptionsTypeV1*)
		NumberUintInput : UINT; (*input data: number of UINT input entries in pUintDataInput*)
		pDintDataInput : UDINT; (*input data: pointer to DINT input data list from type ConfigurationDintOptionsTypeV1*)
		NumberDintInput : UINT; (*input data: number of DINT input entries in pDintDataInput*)
		pUdintDataInput : UDINT; (*input data: pointer to UDINT input data list from type ConfigurationUdintOptionsTypeV1*)
		NumberUdintInput : UINT; (*input data: number of UDINT input entries in pUdintDataInput*)
		pAcknMachineOptions : UDINT; (*input data: pointer to acknowledge information of type DownloadAcknMaOpTypeV1*)
		pIntDataOutput : UDINT; (*return value: pointer to list of type ConfigurationIntOptionsTypeV1*)
		NumberIntOutput : UINT; (*return value: number of returned INT data entries*)
		pUintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationUintOptionsTypeV1*)
		NumberUintOutput : UINT; (*return value: number of returned UINT data entries*)
		pDintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationDintOptionsTypeV1*)
		NumberDintOutput : UINT; (*return value: number of returned DINT data entries*)
		pUdintDataOutput : UDINT; (*return value: pointer to list of type ConfigurationUdintOptionsTypeV1*)
		NumberUdintOutput : UINT; (*return value: number of returned UDINT data entries*)
	END_STRUCT;
	DownloadCmdMaOpTypeV2 : 	STRUCT  (*machine options command structure*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low from SafeLOGIC*)
		UDID_High : UINT; (*input data: UDID high from SafeLOGIC*)
		Unlock : USINT; (*input data: unlock data*)
		pDeviceListInput : UDINT; (*input data: pointer to input device list of type DownloadDeviceTypeV1*)
		NumberDevicesInput : UINT; (*input data: number of input devices*)
		pMachineOptionsInput : UDINT; (*input data: pointer to input bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsInput : UDINT; (*input data: pointer to input module flags of type ConfigurationModuleFlagsTypeV1*)
		pAcknMachineOptions : UDINT; (*input data: pointer to acknowledge information of type DownloadAcknMaOpTypeV1*)
		pDeviceListOutput : UDINT; (*input data: pointer to device list buffer of type ConfigurationDeviceTypeV1*)
		NumberDevicesOutput : UINT; (*input data: number of available device entries in devices list buffer*)
		NumberDevicesOutputOut : UINT; (*return value: number of returned device entries*)
		pMachineOptionsOutput : UDINT; (*input data: pointer to bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsOutput : UDINT; (*input data: pointer to module flags of type ConfigurationModuleFlagsTypeV1*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	DownloadCmdMaOpTypeV1 : 	STRUCT  (*machine options command structure*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low from SafeLOGIC*)
		UDID_High : UINT; (*input data: UDID high from SafeLOGIC*)
		Unlock : USINT; (*input data: unlock data*)
		pDeviceListInput : UDINT; (*input data: pointer to input device list of type DownloadDeviceTypeV1*)
		NumberDevicesInput : UINT; (*input data: number of input devices*)
		pMachineOptionsInput : UDINT; (*input data: pointer to input bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsInput : UDINT; (*input data: pointer to input module flags of type ConfigurationModuleFlagsTypeV1*)
		pAcknMachineOptions : UDINT; (*input data: pointer to acknowledge information of type DownloadAcknMaOpTypeV1*)
		pDeviceListOutput : UDINT; (*return value: pointer to device list of type ConfigurationDeviceTypeV1*)
		NumberDevicesOutput : UINT; (*return value: number of returned entries*)
		pMachineOptionsOutput : UDINT; (*return value: pointer to bit machine options of type ConfigurationBitOptionsTypeV1*)
		pModuleFlagsOutput : UDINT; (*return value: pointer to module flags of type ConfigurationModuleFlagsTypeV1*)
	END_STRUCT;
	DownloadCmdTableTypeV2 : 	STRUCT  (*table command structure*)
		Version : UINT; (*input data: safeVERSION_R110*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pTableDataInput : UDINT; (*input data: pointer to input table data list of type DownloadTableTypeV2*)
		NumberTablesInput : UINT; (*input data: number of input entries in pTableDataInput*)
		pTableDataOutput : UDINT; (*input data: pointer to list of type ConfigurationTableTypeV1*)
		NumberTablesOutput : UINT; (*input data: number of available entries in pTableDataOutput*)
		NumberTablesOutputOut : UINT; (*return value: number of returned table entries*)
		pBackupFile : UDINT; (*input data: 0 .. no backup, otherwise pointer to struct of type FileReferenceType *)
		pXmlOutputFile : UDINT; (*input data: 0 .. don't create XML output data, otherwise pointer to struct of type FileReferenceType*)
	END_STRUCT;
	DownloadCmdTableTypeV1 : 	STRUCT  (*table command structure*)
		Version : UINT; (*input data: safeVERSION_R107*)
		Password : STRING[16]; (*input data: password*)
		UDID_Low : UDINT; (*input data: UDID low*)
		UDID_High : UINT; (*input data: UDID high*)
		Unlock : USINT; (*input data: unlock data*)
		pTableDataInput : UDINT; (*input data: pointer to input table data list of type DownloadTableTypeV1*)
		NumberTablesInput : UINT; (*input data: number of input entries in pTableDataInput*)
		pTableDataOutput : UDINT; (*return value: pointer to list of type ConfigurationTableTypeV1*)
		NumberTablesOutput : UINT; (*return value: number of returned table entries*)
	END_STRUCT;
	DownloadCmdFileTypeV1 : 	STRUCT  (*file command structure*)
		Version : UINT; (*used version*)
		Password : STRING[16]; (*password*)
		UDID_Low : UDINT; (*UDID low*)
		UDID_High : UINT; (*UDID high*)
		Unlock : USINT; (*unlock data*)
		DataSource : DataSourceTypeV1; (*local data or local file available, file upload from safeLOGIC not available*)
		pCrcs : UDINT; (*pointer to CRC data buffer*)
		NumberOfCrcs : UINT; (*size of CRC data Buffer*)
		NumberOfCrcsOut : UINT; (*number of CRCs*)
	END_STRUCT;
	DownloadAddParaTypeV1 : 	STRUCT  (*additional parameter data*)
		SADR : UINT; (*safety address*)
		ID : USINT; (*id*)
		pParaData : UDINT; (*pointer to additional parameter data*)
		Length : UDINT; (*length*)
		pAcknAddPara : UDINT; (*pointer to acknowledge information*)
	END_STRUCT;
	DownloadDeviceTypeV1 : 	STRUCT  (*safety device*)
		SADR : UINT; (*safety address*)
		UDID_Low : UDINT; (*UDID low*)
		UDID_High : UINT; (*UDID high*)
	END_STRUCT;
	DownloadTableTypeV1 : 	STRUCT  (*table data*)
		Device : STRING[80]; (*device for file*)
		File : STRING[80]; (*file name*)
	END_STRUCT;
	DownloadTableTypeV2 : 	STRUCT  (*table data*)
		Type : UINT; (*safeTABLE_FILE_TYPE .. use Device / File, safeTABLE_DATA_TYPE .. use pData / DataLen*)
		Device : STRING[80]; (*device for file*)
		File : STRING[80]; (*file name*)
		pData : UDINT; (*pointer to table data *)
		DataLen : UDINT; (*length of table data*)
	END_STRUCT;
	RemoteControlCmdTypeV1 : 	STRUCT  (*remote control command structure*)
		Version : UINT; (*used version*)
		Command : UINT; (*command*)
		Number : UINT; (*actual number*)
		Data : UINT; (*data*)
		Password : STRING[16]; (*password*)
		NewPassword : STRING[16]; (*new password*)
	END_STRUCT;
	RemoteControlStatusTypeV1 : 	STRUCT  (*remote control status from SafeLOGIC*)
		Command : UINT; (*last received command*)
		Number : UINT; (*running number of last received command*)
		Status : UINT; (*status of command*)
		State : UINT; (*state of the last ENTER command*)
		EnterData : UINT; (*last received ENTER command that was correct executed*)
		EnterNumber : UINT; (*running number of the last received ENTER command*)
		EnterExecuteStatus : UINT; (*state of the last received ENTER command*)
		SafeOSState : USINT; (*status of the safety application*)
		SafeKEYChanged : USINT; (*SafeKEY has been exchanged*)
		LedTestActive : USINT; (*LED test active*)
		Scanning : USINT; (*module scan active*)
		openSAFETYstate : USINT; (*status of openSAFETY stack*)
		FailSafe : USINT; (*Fail-Safe status*)
		NumberOfMissingModules : UINT; (*number of missing modules*)
		NumberOfUDIDMismatches : UINT; (*number of mismatched modules*)
		NumberOfDifferentFirmware : UINT; (*number of modules with different firmware*)
		SADR : ARRAY[0..100]OF UINT; (*safety address array*)
		MissingModules : ARRAY[0..15]OF USINT; (*missing modules array*)
		UDIDMismatches : ARRAY[0..15]OF USINT; (*udid mismatch array*)
		DifferentFirmware : ARRAY[0..15]OF USINT; (*different firmware array*)
	END_STRUCT;
	RemoteControlStatusTypeV2 : 	STRUCT  (*remote control status from SafeLOGIC*)
		Command : UINT; (*last received command*)
		Number : UINT; (*running number of last received command*)
		Status : UINT; (*status of command*)
		State : UINT; (*state of the last ENTER command*)
		EnterData : UINT; (*last received ENTER command that was correct executed*)
		EnterNumber : UINT; (*running number of the last received ENTER command*)
		EnterExecuteStatus : UINT; (*state of the last received ENTER command*)
		SafeOSState : USINT; (*status of the safety application*)
		SafeKEYChanged : USINT; (*SafeKEY has been exchanged*)
		LedTestActive : USINT; (*LED test active*)
		Scanning : USINT; (*module scan active*)
		openSAFETYstate : USINT; (*status of openSAFETY stack*)
		FailSafe : USINT; (*Fail-Safe status*)
		NumberOfMissingModules : UINT; (*number of missing modules*)
		NumberOfUDIDMismatches : UINT; (*number of mismatched modules*)
		NumberOfDifferentFirmware : UINT; (*number of modules with different firmware*)
		SADR : ARRAY[0..299]OF UINT; (*safety address array*)
		MissingModules : ARRAY[0..39]OF USINT; (*missing modules array*)
		UDIDMismatches : ARRAY[0..39]OF USINT; (*udid mismatch array*)
		DifferentFirmware : ARRAY[0..39]OF USINT; (*different firmware array*)
		NumberOfConfiguredModules : UINT; (*number of configured modules*)
		SetupModeActive : USINT; (*setup mode active*)
		ProjectPresent : USINT; (*project present*)
		PasswordSet : USINT; (*password set*)
		IsSL81xx : USINT; (*SCM is part of SL81xx*)
		IsSCMar : USINT; (*SCM is part of SCMar*)
		SetupModeSupported : USINT; (*setup mode is supported*)
	END_STRUCT;
	TableHeaderATypeV1 : 	STRUCT  (*header struct for table type A version 1*)
		xTol : DINT;
		yTol : DINT;
	END_STRUCT;
	TableEntryATypeV1 : 	STRUCT  (*entry struct for table type A version 1*)
		xVal : DINT;
		yVal : DINT;
		resVal : USINT;
	END_STRUCT;
	TableEntryBTypeV1 : 	STRUCT  (*entry struct for table type B version 1*)
		xVal : DINT;
		yVal : DINT;
		zVal : DINT;
		resVal : DINT;
	END_STRUCT;
	TableEntryCTypeV1 : 	STRUCT  (*entry struct for table type C version 1*)
		Zone : UINT;
		Position : UINT;
		Dimension : UINT;
	END_STRUCT;
	TableHeaderDTypeV1 : 	STRUCT  (*header struct for table type A version 1*)
		Surveillance : BYTE;
	END_STRUCT;
	TableEntryDTypeV1 : 	STRUCT  (*entry struct for table type D version 1*)
		Object : UINT;
		Type : UINT;
		MinimumBeam : UINT;
		MaximumBeam : UINT;
		Dimension : UINT;
		DimensionTolerance : UINT;
	END_STRUCT;
	TableHeaderDTypeV2 : 	STRUCT  (*header struct for table type D version 2*)
		Surveillance : BYTE;
	END_STRUCT;
	TableEntryDTypeV2 : 	STRUCT  (*entry struct for table type D version 2*)
		Object : UINT;
		MinimumBeam : UINT;
		MaximumBeam : UINT;
		Dimension : UINT;
		DimensionTolerance : UINT;
	END_STRUCT;
	TableHeaderETypeV1 : 	STRUCT  (*header struct for table type E version 1*)
		xDim : INT;
		yDim : INT;
	END_STRUCT;
	TableEntryETypeV1 : 	STRUCT  (*entry struct for table type D version 1*)
		Entry : DINT;
	END_STRUCT;
	TableEntrySTypeV1 : 	STRUCT  (*entry struct for table type S version 1*)
		LinkTargetObjectID : DINT;
		LinkTargetAxisType : DINT;
		LinkSourceObjectID : DINT;
		LinkSourceAxisType : DINT;
		LinkFactorNum : DINT;
		LinkFactorDenom : DINT;
	END_STRUCT;
	TableHeaderTTypeV1 : 	STRUCT  (*header struct for table type T version 1*)
		NumberOfActiveAxes : DINT; (*number of active axes*)
	END_STRUCT;
	TableEntryTTypeV1 : 	STRUCT  (*entry struct for table type T version 1*)
		KinObjID : DINT;
		KinObjType : DINT;
		KinObjTransX : DINT;
		KinObjTransY : DINT;
		KinObjTransZ : DINT;
		KinObjRotAngle1 : DINT;
		KinObjRotAngle2 : DINT;
		KinObjRotAngle3 : DINT;
		KinObjRotaryAxisDecRamp : DINT;
		KinObjRotaryAxisMaxAcc : DINT;
		KinObjLinearAxisDecRamp : DINT;
		KinObjLinearAxisMaxAcc : DINT;
	END_STRUCT;
	TableHeaderTTypeV2 : 	STRUCT  (*header struct for table type T version 2*)
		NumberOfTableObjects : UINT;
		VersionNumber : UINT;
		NumberOfActiveAxes : DINT;
	END_STRUCT;
	TableEntryTTypeV2 : 	STRUCT  (*entry struct for table type T version 2*)
		KinObjID : DINT;
		KinObjType : DINT;
		KinObjTransX : DINT;
		KinObjTransY : DINT;
		KinObjTransZ : DINT;
		KinObjRotAngle1 : DINT;
		KinObjRotAngle2 : DINT;
		KinObjRotAngle3 : DINT;
		KinObjRotaryAxisDecRamp : DINT;
		KinObjRotaryAxisMaxAcc : DINT;
		KinObjLinearAxisDecRamp : DINT;
		KinObjLinearAxisMaxAcc : DINT;
		KinObjActivateWireFrameModel : DINT;
		KinObjDistanceToBndElements : DINT;
	END_STRUCT;
	TableHeaderTTypeV3 : 	STRUCT  (*header struct for table type T version 3*)
		NumberOfTableObjects : UINT;
		VersionNumber : UINT;
		NumberOfActiveAxes : DINT;
	END_STRUCT;
	TableEntryTTypeV3 : 	STRUCT  (*entry struct for table type T version 3*)
		KinObjID : DINT;
		KinObjType : DINT;
		KinObjTransX : DINT;
		KinObjTransY : DINT;
		KinObjTransZ : DINT;
		KinObjRotAngle1 : DINT;
		KinObjRotAngle2 : DINT;
		KinObjRotAngle3 : DINT;
		KinObjRotaryAxisDecRamp : DINT;
		KinObjRotaryAxisMaxAcc : DINT;
		KinObjLinearAxisDecRamp : DINT;
		KinObjLinearAxisMaxAcc : DINT;
		KinObjActivateWireFrameModel : DINT;
		KinObjDistanceToBndElements : DINT;
	END_STRUCT;
	TableHeaderTTypeV4 : 	STRUCT  (*header struct for table type T version 4*)
		NumberOfTableObjects : UINT;
		VersionNumber : UINT;
		NumberOfActiveAxes : DINT;
		ParallelConfiguration : DINT;
	END_STRUCT;
	TableEntryTTypeV4 : 	STRUCT  (*entry struct for table type T version 4*)
		KinObjID : DINT;
		KinObjType : DINT;
		KinObjTransX : DINT;
		KinObjTransY : DINT;
		KinObjTransZ : DINT;
		KinObjRotAngle1 : DINT;
		KinObjRotAngle2 : DINT;
		KinObjRotAngle3 : DINT;
		KinObjRotaryAxisDecRamp : DINT;
		KinObjRotaryAxisMaxAcc : DINT;
		KinObjLinearAxisDecRamp : DINT;
		KinObjLinearAxisMaxAcc : DINT;
		KinObjActivateWireFrameModel : DINT;
		KinObjDistanceToBndElements : DINT;
	END_STRUCT;
	TableEntryUTypeV1 : 	STRUCT  (*entry struct for table type U version 1*)
		SpaceID : DINT;
		SpaceType : DINT;
		SpaceTransX : DINT;
		SpaceTransY : DINT;
		SpaceTransZ : DINT;
		SpaceRotAngle1 : DINT;
		SpaceRotAngle2 : DINT;
		SpaceRotAngle3 : DINT;
		SpaceDimensionX : DINT;
		SpaceDimensionY : DINT;
		SpaceDimensionZ : DINT;
	END_STRUCT;
	TableEntryVTypeV1 : 	STRUCT  (*entry struct for table type V version 1*)
		SpaceID : DINT;
		SpaceType : DINT;
		KinObjID : DINT;
		KinObjJointAxisType : DINT;
		SpaceMaxLimit : DINT;
		SpaceMinLimit : DINT;
	END_STRUCT;
	TableEntryWTypeV1 : 	STRUCT  (* entry struct for table type W version 1*)
		OrientID : DINT;
		OrientType : DINT;
		OrientTransX_RotAngle1 : DINT;
		OrientTransY_RotAngle2 : DINT;
		OrientTransZ_RotAngle3 : DINT;
	END_STRUCT;
END_TYPE
