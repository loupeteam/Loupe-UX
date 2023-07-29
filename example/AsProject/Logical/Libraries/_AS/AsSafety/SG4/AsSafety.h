/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASSAFETY_
#define _ASSAFETY_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>
#include <standard.h>
#include <FileIO.h>
#include <AsXml.h>
#include <astime.h>
#include <DataObj.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define safeERR_TC_INVALID_STEP 36190U
 #define safeERR_TC_ACK_SET 36189U
 #define safeERR_TC_LOCK_FAILED 36188U
 #define safeERR_TC_EXTRACT_FAILED 36187U
 #define safeERR_TC_CHECK_FAILED 36186U
 #define safeWRN_TC_WAIT_FOR_ACK 36191U
 #define safeERR_TC_TYPE_CPY_FCT 36185U
 #define safeERR_TC_INV_USER 36184U
 #define safeERR_TC_INV_TAB_LEN 36183U
 #define safeERR_TC_INV_INPUT_PTR 36182U
 #define safeERR_TC_INV_INST 36181U
 #define safeERR_TC_INV_TABTYPE 36180U
 #define safeERR_COT_PWD_ERR 36138U
 #define safeERR_SLINFO_RET_ERR 36137U
 #define safeERR_SLINFO_TYPE_ERR 36136U
 #define safeERR_FI_TYPE_ERR 36135U
 #define safeERR_FILE_EMPTY 36134U
 #define safeERR_BUFFER_TOO_SMALL 36133U
 #define safeERR_BUFFER_NULL 36132U
 #define safeERR_COT_READING_FILE 36131U
 #define safeERR_COT_TYPE_ERR 36130U
 #define safeERR_DLDATA_ERR_DATA 36129U
 #define safeERR_DLDATA_TYPE_ERR 36128U
 #define safeERR_DL_COMPARE_FAILED 36127U
 #define safeERR_DL_STATIC_UNLOCK 36126U
 #define safeERR_DL_UNLOCK_WRITE 36125U
 #define safeERR_DL_UNLOCK_READ 36124U
 #define safeERR_DL_UNLOCK_FILE_INFO 36123U
 #define safeERR_DL_NO_RIGHTS_TO_WRITE 36122U
 #define safeERR_DL_WRONG_FILE_SIZE 36121U
 #define safeERR_DL_UDID 36120U
 #define safeERR_DL_CHECKSUM 36119U
 #define safeERR_DL_STREAM 36118U
 #define safeERR_DL_WRITE 36117U
 #define safeERR_DL_FILE_TOO_BIG 36116U
 #define safeERR_DL_FILE_INVALID 36115U
 #define safeERR_DL_FILE_OPEN 36114U
 #define safeERR_DL_PROTOCOL 36113U
 #define safeERR_DL_NO_PASSWORD 36112U
 #define safeERR_RC_DATA_LENGTH 36111U
 #define safeERR_RC_STATUS_DATA 36110U
 #define safeERR_RC_ENTER_SK_PW 36109U
 #define safeERR_RC_ENTER_PW 36108U
 #define safeERR_RC_ENTER_DATA 36107U
 #define safeERR_RC_CMD 36106U
 #define safeERR_TIMEOUT 36105U
 #define safeERR_INTERNAL_ERROR 36104U
 #define safeERR_ALLOC_MEM 36103U
 #define safeERR_UDID 36102U
 #define safeERR_PW_LENGTH 36101U
 #define safeERR_VERSION 36100U
 #define safeRET_NO_TIMESTAMP 4294967295U
 #define safeCMD_VERSION_INFO 61440U
 #define safeCMD_SETUP_MODE_DEACT 37120U
 #define safeCMD_SETUP_MODE_ACT 36864U
 #define safeCMD_CLEAR_DATA 32768U
 #define safeCMD_RESET 28672U
 #define safeCMD_SK_FORMAT 24576U
 #define safeCMD_SK_PW 20480U
 #define safeCMD_SCAN 8192U
 #define safeCMD_TEST 4096U
 #define safeCMD_SK_XCHG 512U
 #define safeCMD_FW_ACKN 256U
 #define safeCMD_1_UDID_ACKN 96U
 #define safeCMD_2_UDID_ACKN 80U
 #define safeCMD_3_UDID_ACKN 64U
 #define safeCMD_4_UDID_ACKN 48U
 #define safeCMD_N_UDID_ACKN 32U
 #define safeCMD_STATUS_SL 0U
 #define safeCMD_STATUS 512U
 #define safeCMD_ENTER 256U
 #define safeSRC_TYPE_LOCAL_FILE 2U
 #define safeSRC_TYPE_LOCAL_DATA 1U
 #define safeSRC_TYPE_UPLOAD_FILE 0U
 #define safeTABLE_DATA_TYPE 1U
 #define safeTABLE_FILE_TYPE 0U
 #define safeINFO_TYPE_PWD_CHK 2U
 #define safeINFO_TYPE_PWD_INFO 1U
 #define safeDATA_TYPE_APPLICATION 4608U
 #define safeDATA_TYPE_ADDPARA 1024U
 #define safeDATA_TYPE_TABLE 768U
 #define safeDATA_TYPE_EXTMAOP 512U
 #define safeDATA_TYPE_MAOP 256U
 #define safeVERSION_R110 272U
 #define safeVERSION_R107 263U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short safeERR_TC_INVALID_STEP;
 _GLOBAL_CONST unsigned short safeERR_TC_ACK_SET;
 _GLOBAL_CONST unsigned short safeERR_TC_LOCK_FAILED;
 _GLOBAL_CONST unsigned short safeERR_TC_EXTRACT_FAILED;
 _GLOBAL_CONST unsigned short safeERR_TC_CHECK_FAILED;
 _GLOBAL_CONST unsigned short safeWRN_TC_WAIT_FOR_ACK;
 _GLOBAL_CONST unsigned short safeERR_TC_TYPE_CPY_FCT;
 _GLOBAL_CONST unsigned short safeERR_TC_INV_USER;
 _GLOBAL_CONST unsigned short safeERR_TC_INV_TAB_LEN;
 _GLOBAL_CONST unsigned short safeERR_TC_INV_INPUT_PTR;
 _GLOBAL_CONST unsigned short safeERR_TC_INV_INST;
 _GLOBAL_CONST unsigned short safeERR_TC_INV_TABTYPE;
 _GLOBAL_CONST unsigned short safeERR_COT_PWD_ERR;
 _GLOBAL_CONST unsigned short safeERR_SLINFO_RET_ERR;
 _GLOBAL_CONST unsigned short safeERR_SLINFO_TYPE_ERR;
 _GLOBAL_CONST unsigned short safeERR_FI_TYPE_ERR;
 _GLOBAL_CONST unsigned short safeERR_FILE_EMPTY;
 _GLOBAL_CONST unsigned short safeERR_BUFFER_TOO_SMALL;
 _GLOBAL_CONST unsigned short safeERR_BUFFER_NULL;
 _GLOBAL_CONST unsigned short safeERR_COT_READING_FILE;
 _GLOBAL_CONST unsigned short safeERR_COT_TYPE_ERR;
 _GLOBAL_CONST unsigned short safeERR_DLDATA_ERR_DATA;
 _GLOBAL_CONST unsigned short safeERR_DLDATA_TYPE_ERR;
 _GLOBAL_CONST unsigned short safeERR_DL_COMPARE_FAILED;
 _GLOBAL_CONST unsigned short safeERR_DL_STATIC_UNLOCK;
 _GLOBAL_CONST unsigned short safeERR_DL_UNLOCK_WRITE;
 _GLOBAL_CONST unsigned short safeERR_DL_UNLOCK_READ;
 _GLOBAL_CONST unsigned short safeERR_DL_UNLOCK_FILE_INFO;
 _GLOBAL_CONST unsigned short safeERR_DL_NO_RIGHTS_TO_WRITE;
 _GLOBAL_CONST unsigned short safeERR_DL_WRONG_FILE_SIZE;
 _GLOBAL_CONST unsigned short safeERR_DL_UDID;
 _GLOBAL_CONST unsigned short safeERR_DL_CHECKSUM;
 _GLOBAL_CONST unsigned short safeERR_DL_STREAM;
 _GLOBAL_CONST unsigned short safeERR_DL_WRITE;
 _GLOBAL_CONST unsigned short safeERR_DL_FILE_TOO_BIG;
 _GLOBAL_CONST unsigned short safeERR_DL_FILE_INVALID;
 _GLOBAL_CONST unsigned short safeERR_DL_FILE_OPEN;
 _GLOBAL_CONST unsigned short safeERR_DL_PROTOCOL;
 _GLOBAL_CONST unsigned short safeERR_DL_NO_PASSWORD;
 _GLOBAL_CONST unsigned short safeERR_RC_DATA_LENGTH;
 _GLOBAL_CONST unsigned short safeERR_RC_STATUS_DATA;
 _GLOBAL_CONST unsigned short safeERR_RC_ENTER_SK_PW;
 _GLOBAL_CONST unsigned short safeERR_RC_ENTER_PW;
 _GLOBAL_CONST unsigned short safeERR_RC_ENTER_DATA;
 _GLOBAL_CONST unsigned short safeERR_RC_CMD;
 _GLOBAL_CONST unsigned short safeERR_TIMEOUT;
 _GLOBAL_CONST unsigned short safeERR_INTERNAL_ERROR;
 _GLOBAL_CONST unsigned short safeERR_ALLOC_MEM;
 _GLOBAL_CONST unsigned short safeERR_UDID;
 _GLOBAL_CONST unsigned short safeERR_PW_LENGTH;
 _GLOBAL_CONST unsigned short safeERR_VERSION;
 _GLOBAL_CONST unsigned long safeRET_NO_TIMESTAMP;
 _GLOBAL_CONST unsigned short safeCMD_VERSION_INFO;
 _GLOBAL_CONST unsigned short safeCMD_SETUP_MODE_DEACT;
 _GLOBAL_CONST unsigned short safeCMD_SETUP_MODE_ACT;
 _GLOBAL_CONST unsigned short safeCMD_CLEAR_DATA;
 _GLOBAL_CONST unsigned short safeCMD_RESET;
 _GLOBAL_CONST unsigned short safeCMD_SK_FORMAT;
 _GLOBAL_CONST unsigned short safeCMD_SK_PW;
 _GLOBAL_CONST unsigned short safeCMD_SCAN;
 _GLOBAL_CONST unsigned short safeCMD_TEST;
 _GLOBAL_CONST unsigned short safeCMD_SK_XCHG;
 _GLOBAL_CONST unsigned short safeCMD_FW_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_1_UDID_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_2_UDID_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_3_UDID_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_4_UDID_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_N_UDID_ACKN;
 _GLOBAL_CONST unsigned short safeCMD_STATUS_SL;
 _GLOBAL_CONST unsigned short safeCMD_STATUS;
 _GLOBAL_CONST unsigned short safeCMD_ENTER;
 _GLOBAL_CONST unsigned short safeSRC_TYPE_LOCAL_FILE;
 _GLOBAL_CONST unsigned short safeSRC_TYPE_LOCAL_DATA;
 _GLOBAL_CONST unsigned short safeSRC_TYPE_UPLOAD_FILE;
 _GLOBAL_CONST unsigned short safeTABLE_DATA_TYPE;
 _GLOBAL_CONST unsigned short safeTABLE_FILE_TYPE;
 _GLOBAL_CONST unsigned short safeINFO_TYPE_PWD_CHK;
 _GLOBAL_CONST unsigned short safeINFO_TYPE_PWD_INFO;
 _GLOBAL_CONST unsigned short safeDATA_TYPE_APPLICATION;
 _GLOBAL_CONST unsigned short safeDATA_TYPE_ADDPARA;
 _GLOBAL_CONST unsigned short safeDATA_TYPE_TABLE;
 _GLOBAL_CONST unsigned short safeDATA_TYPE_EXTMAOP;
 _GLOBAL_CONST unsigned short safeDATA_TYPE_MAOP;
 _GLOBAL_CONST unsigned short safeVERSION_R110;
 _GLOBAL_CONST unsigned short safeVERSION_R107;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct FileReferenceType
{	plcstring Device[81];
	plcstring File[81];
} FileReferenceType;

typedef struct AsSafetyInternalType
{	plcbit Clean;
	unsigned short State;
	unsigned short Result;
	unsigned long Tmp;
	unsigned long pThis;
	unsigned long pFcn;
} AsSafetyInternalType;

typedef struct SourceLocalDataTypeV1
{	unsigned long pFileData;
	unsigned long FileLength;
} SourceLocalDataTypeV1;

typedef struct SourceLocalFileTypeV1
{	struct FileReferenceType SourceFile;
} SourceLocalFileTypeV1;

typedef struct DataSourceTypeV1
{	unsigned short Type;
	struct SourceLocalDataTypeV1 LocalData;
	struct SourceLocalFileTypeV1 LocalFile;
} DataSourceTypeV1;

typedef struct InfoCmdPwdInfoTypeV1
{	unsigned short Version;
	plcbit PasswordSet;
} InfoCmdPwdInfoTypeV1;

typedef struct InfoCmdPwdChkTypeV1
{	unsigned short Version;
	plcstring Password[17];
	plcbit PasswordEqual;
} InfoCmdPwdChkTypeV1;

typedef struct ConfigurationAddParaTypeV2
{	unsigned short SADR;
	unsigned char ID;
	unsigned long pParaData;
	unsigned long Length;
	unsigned long LengthOut;
	unsigned long CRC;
	unsigned long Timestamp;
} ConfigurationAddParaTypeV2;

typedef struct ConfigurationAddParaTypeV1
{	unsigned short SADR;
	unsigned char ID;
	unsigned long pParaData;
	unsigned long Length;
	unsigned long CRC;
	unsigned long Timestamp;
} ConfigurationAddParaTypeV1;

typedef struct ConfigurationBitOptionsTypeV1
{	unsigned char BitData[64];
} ConfigurationBitOptionsTypeV1;

typedef struct ConfigurationCmdAddParaTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pParaDataOutput;
	unsigned short NumberParaSetsOutput;
	unsigned short NumberParaSetsOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} ConfigurationCmdAddParaTypeV2;

typedef struct ConfigurationCmdAddParaTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pParaDataOutput;
	unsigned short NumberParaSetsOutput;
} ConfigurationCmdAddParaTypeV1;

typedef struct ConfigurationCmdExtMaOpTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pIntDataOutput;
	unsigned short NumberIntOutput;
	unsigned short NumberIntOutputOut;
	unsigned long pUintDataOutput;
	unsigned short NumberUintOutput;
	unsigned short NumberUintOutputOut;
	unsigned long pDintDataOutput;
	unsigned short NumberDintOutput;
	unsigned short NumberDintOutputOut;
	unsigned long pUdintDataOutput;
	unsigned short NumberUdintOutput;
	unsigned short NumberUdintOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} ConfigurationCmdExtMaOpTypeV2;

typedef struct ConfigurationCmdExtMaOpTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pIntDataOutput;
	unsigned short NumberIntOutput;
	unsigned long pUintDataOutput;
	unsigned short NumberUintOutput;
	unsigned long pDintDataOutput;
	unsigned short NumberDintOutput;
	unsigned long pUdintDataOutput;
	unsigned short NumberUdintOutput;
} ConfigurationCmdExtMaOpTypeV1;

typedef struct ConfigurationCmdMaOpTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pDeviceListOutput;
	unsigned short NumberDevicesOutput;
	unsigned short NumberDevicesOutputOut;
	unsigned long pMachineOptionsOutput;
	unsigned long pModuleFlagsOutput;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} ConfigurationCmdMaOpTypeV2;

typedef struct ConfigurationCmdMaOpTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pDeviceListOutput;
	unsigned short NumberDevicesOutput;
	unsigned long pMachineOptionsOutput;
	unsigned long pModuleFlagsOutput;
} ConfigurationCmdMaOpTypeV1;

typedef struct ConfigurationCmdTableTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pTableDataOutput;
	unsigned short NumberTablesOutput;
	unsigned short NumberTablesOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} ConfigurationCmdTableTypeV2;

typedef struct ConfigurationCmdTableTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long pTableDataOutput;
	unsigned short NumberTablesOutput;
} ConfigurationCmdTableTypeV1;

typedef struct FileInfoCmdTypeV1
{	unsigned short Version;
	struct DataSourceTypeV1 DataSource;
	unsigned long Timestamp;
	unsigned long pCrcs;
	unsigned short NumberOfCrcs;
	unsigned short NumberOfCrcsOut;
} FileInfoCmdTypeV1;

typedef struct ConfigurationDeviceTypeV1
{	unsigned short SADR;
	unsigned char UDID[6];
} ConfigurationDeviceTypeV1;

typedef struct ConfigurationDintOptionsTypeV1
{	unsigned short ID;
	signed long Value;
} ConfigurationDintOptionsTypeV1;

typedef struct ConfigurationIntOptionsTypeV1
{	unsigned short ID;
	signed short Value;
} ConfigurationIntOptionsTypeV1;

typedef struct ConfigurationModuleFlagsTypeV1
{	unsigned char Optional[128];
	unsigned char Startup[128];
	unsigned char NotPresent[128];
} ConfigurationModuleFlagsTypeV1;

typedef struct ConfigurationTableTypeV2
{	unsigned short ID;
	unsigned char Type;
	unsigned short NumberOfCRCs;
	unsigned short NumberOfCRCsOut;
	unsigned long pCRCData;
} ConfigurationTableTypeV2;

typedef struct ConfigurationTableTypeV1
{	unsigned short ID;
	unsigned char Type;
	unsigned short NumberOfCRCs;
	unsigned long pCRCData;
} ConfigurationTableTypeV1;

typedef struct ConfigurationUdintOptionsTypeV1
{	unsigned short ID;
	unsigned long Value;
} ConfigurationUdintOptionsTypeV1;

typedef struct ConfigurationUintOptionsTypeV1
{	unsigned short ID;
	unsigned short Value;
} ConfigurationUintOptionsTypeV1;

typedef struct DownloadAcknExtMaOpTypeV1
{	plcbit AcknIntOptions[64];
	plcbit AcknUintOptions[64];
	plcbit AcknDintOptions[64];
	plcbit AcknUdintOptions[64];
} DownloadAcknExtMaOpTypeV1;

typedef struct DownloadAcknMaOpTypeV1
{	unsigned char AcknBitOptions[64];
} DownloadAcknMaOpTypeV1;

typedef struct DownloadAcknAddParaTypeV1
{	unsigned char AcknBitAddPara[64];
} DownloadAcknAddParaTypeV1;

typedef struct DownloadCmdAddParaTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pParaListInput;
	unsigned short NumberParaSetsInput;
	unsigned long pParaDataOutput;
	unsigned short NumberParaSetsOutput;
	unsigned short NumberParaSetsOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} DownloadCmdAddParaTypeV2;

typedef struct DownloadCmdAddParaTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pParaListInput;
	unsigned short NumberParaSetsInput;
	unsigned long pParaDataOutput;
	unsigned short NumberParaSetsOutput;
} DownloadCmdAddParaTypeV1;

typedef struct DownloadCmdApplicationTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned short ApplicationID;
	plcstring Device[81];
	plcstring File[81];
	unsigned char Unlock;
} DownloadCmdApplicationTypeV1;

typedef struct DownloadCmdExtMaOpTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pIntDataInput;
	unsigned short NumberIntInput;
	unsigned long pUintDataInput;
	unsigned short NumberUintInput;
	unsigned long pDintDataInput;
	unsigned short NumberDintInput;
	unsigned long pUdintDataInput;
	unsigned short NumberUdintInput;
	unsigned long pAcknMachineOptions;
	unsigned long pIntDataOutput;
	unsigned short NumberIntOutput;
	unsigned short NumberIntOutputOut;
	unsigned long pUintDataOutput;
	unsigned short NumberUintOutput;
	unsigned short NumberUintOutputOut;
	unsigned long pDintDataOutput;
	unsigned short NumberDintOutput;
	unsigned short NumberDintOutputOut;
	unsigned long pUdintDataOutput;
	unsigned short NumberUdintOutput;
	unsigned short NumberUdintOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} DownloadCmdExtMaOpTypeV2;

typedef struct DownloadCmdExtMaOpTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pIntDataInput;
	unsigned short NumberIntInput;
	unsigned long pUintDataInput;
	unsigned short NumberUintInput;
	unsigned long pDintDataInput;
	unsigned short NumberDintInput;
	unsigned long pUdintDataInput;
	unsigned short NumberUdintInput;
	unsigned long pAcknMachineOptions;
	unsigned long pIntDataOutput;
	unsigned short NumberIntOutput;
	unsigned long pUintDataOutput;
	unsigned short NumberUintOutput;
	unsigned long pDintDataOutput;
	unsigned short NumberDintOutput;
	unsigned long pUdintDataOutput;
	unsigned short NumberUdintOutput;
} DownloadCmdExtMaOpTypeV1;

typedef struct DownloadCmdMaOpTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pDeviceListInput;
	unsigned short NumberDevicesInput;
	unsigned long pMachineOptionsInput;
	unsigned long pModuleFlagsInput;
	unsigned long pAcknMachineOptions;
	unsigned long pDeviceListOutput;
	unsigned short NumberDevicesOutput;
	unsigned short NumberDevicesOutputOut;
	unsigned long pMachineOptionsOutput;
	unsigned long pModuleFlagsOutput;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} DownloadCmdMaOpTypeV2;

typedef struct DownloadCmdMaOpTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pDeviceListInput;
	unsigned short NumberDevicesInput;
	unsigned long pMachineOptionsInput;
	unsigned long pModuleFlagsInput;
	unsigned long pAcknMachineOptions;
	unsigned long pDeviceListOutput;
	unsigned short NumberDevicesOutput;
	unsigned long pMachineOptionsOutput;
	unsigned long pModuleFlagsOutput;
} DownloadCmdMaOpTypeV1;

typedef struct DownloadCmdTableTypeV2
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pTableDataInput;
	unsigned short NumberTablesInput;
	unsigned long pTableDataOutput;
	unsigned short NumberTablesOutput;
	unsigned short NumberTablesOutputOut;
	unsigned long pBackupFile;
	unsigned long pXmlOutputFile;
} DownloadCmdTableTypeV2;

typedef struct DownloadCmdTableTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	unsigned long pTableDataInput;
	unsigned short NumberTablesInput;
	unsigned long pTableDataOutput;
	unsigned short NumberTablesOutput;
} DownloadCmdTableTypeV1;

typedef struct DownloadCmdFileTypeV1
{	unsigned short Version;
	plcstring Password[17];
	unsigned long UDID_Low;
	unsigned short UDID_High;
	unsigned char Unlock;
	struct DataSourceTypeV1 DataSource;
	unsigned long pCrcs;
	unsigned short NumberOfCrcs;
	unsigned short NumberOfCrcsOut;
} DownloadCmdFileTypeV1;

typedef struct DownloadAddParaTypeV1
{	unsigned short SADR;
	unsigned char ID;
	unsigned long pParaData;
	unsigned long Length;
	unsigned long pAcknAddPara;
} DownloadAddParaTypeV1;

typedef struct DownloadDeviceTypeV1
{	unsigned short SADR;
	unsigned long UDID_Low;
	unsigned short UDID_High;
} DownloadDeviceTypeV1;

typedef struct DownloadTableTypeV1
{	plcstring Device[81];
	plcstring File[81];
} DownloadTableTypeV1;

typedef struct DownloadTableTypeV2
{	unsigned short Type;
	plcstring Device[81];
	plcstring File[81];
	unsigned long pData;
	unsigned long DataLen;
} DownloadTableTypeV2;

typedef struct RemoteControlCmdTypeV1
{	unsigned short Version;
	unsigned short Command;
	unsigned short Number;
	unsigned short Data;
	plcstring Password[17];
	plcstring NewPassword[17];
} RemoteControlCmdTypeV1;

typedef struct RemoteControlStatusTypeV1
{	unsigned short Command;
	unsigned short Number;
	unsigned short Status;
	unsigned short State;
	unsigned short EnterData;
	unsigned short EnterNumber;
	unsigned short EnterExecuteStatus;
	unsigned char SafeOSState;
	unsigned char SafeKEYChanged;
	unsigned char LedTestActive;
	unsigned char Scanning;
	unsigned char openSAFETYstate;
	unsigned char FailSafe;
	unsigned short NumberOfMissingModules;
	unsigned short NumberOfUDIDMismatches;
	unsigned short NumberOfDifferentFirmware;
	unsigned short SADR[101];
	unsigned char MissingModules[16];
	unsigned char UDIDMismatches[16];
	unsigned char DifferentFirmware[16];
} RemoteControlStatusTypeV1;

typedef struct RemoteControlStatusTypeV2
{	unsigned short Command;
	unsigned short Number;
	unsigned short Status;
	unsigned short State;
	unsigned short EnterData;
	unsigned short EnterNumber;
	unsigned short EnterExecuteStatus;
	unsigned char SafeOSState;
	unsigned char SafeKEYChanged;
	unsigned char LedTestActive;
	unsigned char Scanning;
	unsigned char openSAFETYstate;
	unsigned char FailSafe;
	unsigned short NumberOfMissingModules;
	unsigned short NumberOfUDIDMismatches;
	unsigned short NumberOfDifferentFirmware;
	unsigned short SADR[300];
	unsigned char MissingModules[40];
	unsigned char UDIDMismatches[40];
	unsigned char DifferentFirmware[40];
	unsigned short NumberOfConfiguredModules;
	unsigned char SetupModeActive;
	unsigned char ProjectPresent;
	unsigned char PasswordSet;
	unsigned char IsSL81xx;
	unsigned char IsSCMar;
	unsigned char SetupModeSupported;
} RemoteControlStatusTypeV2;

typedef struct TableHeaderATypeV1
{	signed long xTol;
	signed long yTol;
} TableHeaderATypeV1;

typedef struct TableEntryATypeV1
{	signed long xVal;
	signed long yVal;
	unsigned char resVal;
} TableEntryATypeV1;

typedef struct TableEntryBTypeV1
{	signed long xVal;
	signed long yVal;
	signed long zVal;
	signed long resVal;
} TableEntryBTypeV1;

typedef struct TableEntryCTypeV1
{	unsigned short Zone;
	unsigned short Position;
	unsigned short Dimension;
} TableEntryCTypeV1;

typedef struct TableHeaderDTypeV1
{	plcbyte Surveillance;
} TableHeaderDTypeV1;

typedef struct TableEntryDTypeV1
{	unsigned short Object;
	unsigned short Type;
	unsigned short MinimumBeam;
	unsigned short MaximumBeam;
	unsigned short Dimension;
	unsigned short DimensionTolerance;
} TableEntryDTypeV1;

typedef struct TableHeaderDTypeV2
{	plcbyte Surveillance;
} TableHeaderDTypeV2;

typedef struct TableEntryDTypeV2
{	unsigned short Object;
	unsigned short MinimumBeam;
	unsigned short MaximumBeam;
	unsigned short Dimension;
	unsigned short DimensionTolerance;
} TableEntryDTypeV2;

typedef struct TableHeaderETypeV1
{	signed short xDim;
	signed short yDim;
} TableHeaderETypeV1;

typedef struct TableEntryETypeV1
{	signed long Entry;
} TableEntryETypeV1;

typedef struct TableEntrySTypeV1
{	signed long LinkTargetObjectID;
	signed long LinkTargetAxisType;
	signed long LinkSourceObjectID;
	signed long LinkSourceAxisType;
	signed long LinkFactorNum;
	signed long LinkFactorDenom;
} TableEntrySTypeV1;

typedef struct TableHeaderTTypeV1
{	signed long NumberOfActiveAxes;
} TableHeaderTTypeV1;

typedef struct TableEntryTTypeV1
{	signed long KinObjID;
	signed long KinObjType;
	signed long KinObjTransX;
	signed long KinObjTransY;
	signed long KinObjTransZ;
	signed long KinObjRotAngle1;
	signed long KinObjRotAngle2;
	signed long KinObjRotAngle3;
	signed long KinObjRotaryAxisDecRamp;
	signed long KinObjRotaryAxisMaxAcc;
	signed long KinObjLinearAxisDecRamp;
	signed long KinObjLinearAxisMaxAcc;
} TableEntryTTypeV1;

typedef struct TableHeaderTTypeV2
{	unsigned short NumberOfTableObjects;
	unsigned short VersionNumber;
	signed long NumberOfActiveAxes;
} TableHeaderTTypeV2;

typedef struct TableEntryTTypeV2
{	signed long KinObjID;
	signed long KinObjType;
	signed long KinObjTransX;
	signed long KinObjTransY;
	signed long KinObjTransZ;
	signed long KinObjRotAngle1;
	signed long KinObjRotAngle2;
	signed long KinObjRotAngle3;
	signed long KinObjRotaryAxisDecRamp;
	signed long KinObjRotaryAxisMaxAcc;
	signed long KinObjLinearAxisDecRamp;
	signed long KinObjLinearAxisMaxAcc;
	signed long KinObjActivateWireFrameModel;
	signed long KinObjDistanceToBndElements;
} TableEntryTTypeV2;

typedef struct TableHeaderTTypeV3
{	unsigned short NumberOfTableObjects;
	unsigned short VersionNumber;
	signed long NumberOfActiveAxes;
} TableHeaderTTypeV3;

typedef struct TableEntryTTypeV3
{	signed long KinObjID;
	signed long KinObjType;
	signed long KinObjTransX;
	signed long KinObjTransY;
	signed long KinObjTransZ;
	signed long KinObjRotAngle1;
	signed long KinObjRotAngle2;
	signed long KinObjRotAngle3;
	signed long KinObjRotaryAxisDecRamp;
	signed long KinObjRotaryAxisMaxAcc;
	signed long KinObjLinearAxisDecRamp;
	signed long KinObjLinearAxisMaxAcc;
	signed long KinObjActivateWireFrameModel;
	signed long KinObjDistanceToBndElements;
} TableEntryTTypeV3;

typedef struct TableHeaderTTypeV4
{	unsigned short NumberOfTableObjects;
	unsigned short VersionNumber;
	signed long NumberOfActiveAxes;
	signed long ParallelConfiguration;
} TableHeaderTTypeV4;

typedef struct TableEntryTTypeV4
{	signed long KinObjID;
	signed long KinObjType;
	signed long KinObjTransX;
	signed long KinObjTransY;
	signed long KinObjTransZ;
	signed long KinObjRotAngle1;
	signed long KinObjRotAngle2;
	signed long KinObjRotAngle3;
	signed long KinObjRotaryAxisDecRamp;
	signed long KinObjRotaryAxisMaxAcc;
	signed long KinObjLinearAxisDecRamp;
	signed long KinObjLinearAxisMaxAcc;
	signed long KinObjActivateWireFrameModel;
	signed long KinObjDistanceToBndElements;
} TableEntryTTypeV4;

typedef struct TableEntryUTypeV1
{	signed long SpaceID;
	signed long SpaceType;
	signed long SpaceTransX;
	signed long SpaceTransY;
	signed long SpaceTransZ;
	signed long SpaceRotAngle1;
	signed long SpaceRotAngle2;
	signed long SpaceRotAngle3;
	signed long SpaceDimensionX;
	signed long SpaceDimensionY;
	signed long SpaceDimensionZ;
} TableEntryUTypeV1;

typedef struct TableEntryVTypeV1
{	signed long SpaceID;
	signed long SpaceType;
	signed long KinObjID;
	signed long KinObjJointAxisType;
	signed long SpaceMaxLimit;
	signed long SpaceMinLimit;
} TableEntryVTypeV1;

typedef struct TableEntryWTypeV1
{	signed long OrientID;
	signed long OrientType;
	signed long OrientTransX_RotAngle1;
	signed long OrientTransY_RotAngle2;
	signed long OrientTransZ_RotAngle3;
} TableEntryWTypeV1;

typedef struct safeRemoteControl
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	struct RemoteControlStatusTypeV1 SafeLOGICStatus;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	unsigned long i_handle;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeRemoteControl_typ;

typedef struct safeRemoteControl_V2
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	struct RemoteControlStatusTypeV2 SafeLOGICStatus;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeRemoteControl_V2_typ;

typedef struct safeDownloadApplication
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long ApplicationCRC;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	unsigned long i_handle;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeDownloadApplication_typ;

typedef struct safeDownloadApplication_V2
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long ApplicationCRC;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeDownloadApplication_V2_typ;

typedef struct safeDownloadData
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	unsigned long i_handle;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeDownloadData_typ;

typedef struct safeDownloadData_V2
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeDownloadData_V2_typ;

typedef struct safeConfigurationOnTarget
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	unsigned long i_handle;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeConfigurationOnTarget_typ;

typedef struct safeConfigurationOnTarget_V2
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeConfigurationOnTarget_V2_typ;

typedef struct safeDownloadFile
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeDownloadFile_typ;

typedef struct safeCheckTable
{
	/* VAR_INPUT (analog) */
	unsigned char InstNr;
	unsigned long pUser;
	unsigned long Timestamp;
	unsigned char TableType;
	unsigned long EntryCnt;
	unsigned long pTableHeader;
	unsigned long pTableData;
	unsigned long pTableHeaderOut;
	unsigned long pTableDataOut;
	unsigned long pFileDataOut;
	unsigned char AckData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long CheckErrorCode;
	unsigned long CheckErrorLine;
	unsigned long CheckErrorColumn;
	unsigned long pCrcOut;
	unsigned long CrcCntOut;
	/* VAR (analog) */
	unsigned short i_step;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	/* VAR (digital) */
	plcbit i_clean;
} safeCheckTable_typ;

typedef struct safeFileInfo
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeFileInfo_typ;

typedef struct safeGetDataLength
{
	/* VAR_INPUT (analog) */
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Length;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeGetDataLength_typ;

typedef struct safeCreateData
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	unsigned long FileDataOutLen;
	unsigned long pFileDataOut;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	unsigned long Timestamp;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
	plcbit UnlockRequired;
} safeCreateData_typ;

typedef struct safeLogicInfo
{
	/* VAR_INPUT (analog) */
	unsigned short SafeLOGICID;
	unsigned short Type;
	unsigned long pCommandData;
	/* VAR_OUTPUT (analog) */
	unsigned short StatusID;
	/* VAR (analog) */
	struct AsSafetyInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Execute;
	/* VAR_OUTPUT (digital) */
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} safeLogicInfo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void safeRemoteControl(struct safeRemoteControl* inst);
_BUR_PUBLIC void safeRemoteControl_V2(struct safeRemoteControl_V2* inst);
_BUR_PUBLIC void safeDownloadApplication(struct safeDownloadApplication* inst);
_BUR_PUBLIC void safeDownloadApplication_V2(struct safeDownloadApplication_V2* inst);
_BUR_PUBLIC void safeDownloadData(struct safeDownloadData* inst);
_BUR_PUBLIC void safeDownloadData_V2(struct safeDownloadData_V2* inst);
_BUR_PUBLIC void safeConfigurationOnTarget(struct safeConfigurationOnTarget* inst);
_BUR_PUBLIC void safeConfigurationOnTarget_V2(struct safeConfigurationOnTarget_V2* inst);
_BUR_PUBLIC void safeDownloadFile(struct safeDownloadFile* inst);
_BUR_PUBLIC void safeCheckTable(struct safeCheckTable* inst);
_BUR_PUBLIC void safeFileInfo(struct safeFileInfo* inst);
_BUR_PUBLIC void safeGetDataLength(struct safeGetDataLength* inst);
_BUR_PUBLIC void safeCreateData(struct safeCreateData* inst);
_BUR_PUBLIC void safeLogicInfo(struct safeLogicInfo* inst);
_BUR_PUBLIC unsigned short safeLibraryVersion(void);
_BUR_PUBLIC unsigned long safeGetTableLength(unsigned char TableType, unsigned long EntryCnt, unsigned long pTableHeader);


#ifdef __cplusplus
};
#endif
#endif /* _ASSAFETY_ */

