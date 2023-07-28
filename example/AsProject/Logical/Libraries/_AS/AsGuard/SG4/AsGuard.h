/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASGUARD_
#define _ASGUARD_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define guardCUSTOMER_OP_TIME_COUNTER 2U
 #define guardGENERAL_OP_TIME_COUNTER 1U
 #define guardREGISTER_IF_AVAILABLE 2U
 #define guardREGISTER_ALWAYS 1U
 #define guardLIC_REACT_SERVICE 8U
 #define guardLIC_REACT_BOOT_SERVICE 4U
 #define guardLIC_REACT_BLINK_CPU_LED 2U
 #define guardLIC_REACT_LOGBOOK 1U
 #define guardLIC_REACT_NONE 0U
 #define guardBR_FIRMCODE 101652U
 #define guardERR_ALREADY_STARTED 37323U
 #define guardERR_LICENSE_STATUS_UNKNOWN 37322U
 #define guardERR_DATA_SIZE 37321U
 #define guardERR_UNAVAILABLE 37317U
 #define guardERR_INVALID_PARAM 37316U
 #define guardERR_CONTEXT_SIZE 37315U
 #define guardERR_DONGLE_NOT_FOUND 37314U
 #define guardERR_TASK 37313U
 #define guardERR_LIC_NOT_INITIALIZED 37312U
 #define guardERR_FILE_NOT_FOUND 37311U
 #define guardERR_EXECUTE_UPDATE 37310U
 #define guardERR_CREATE_CONTEXT_FILE 37309U
 #define guardERR_CREATE_UPDATE_CONTEXT 37308U
 #define guardERR_SERVICE_VIOLATION 37307U
 #define guardERR_VIOLATION 37306U
 #define guardERR_ACCESS 37305U
 #define guardERR_NOT_STARTED 37304U
 #define guardERR_MEMORY 37303U
 #define guardERR_BUFFERSIZE 37302U
 #define guardERR_GENERAL 37301U
 #define guardERR_NULLPOINTER 37300U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned long guardCUSTOMER_OP_TIME_COUNTER;
 _GLOBAL_CONST unsigned long guardGENERAL_OP_TIME_COUNTER;
 _GLOBAL_CONST plcdword guardREGISTER_IF_AVAILABLE;
 _GLOBAL_CONST plcdword guardREGISTER_ALWAYS;
 _GLOBAL_CONST plcdword guardLIC_REACT_SERVICE;
 _GLOBAL_CONST plcdword guardLIC_REACT_BOOT_SERVICE;
 _GLOBAL_CONST plcdword guardLIC_REACT_BLINK_CPU_LED;
 _GLOBAL_CONST plcdword guardLIC_REACT_LOGBOOK;
 _GLOBAL_CONST plcdword guardLIC_REACT_NONE;
 _GLOBAL_CONST unsigned long guardBR_FIRMCODE;
 _GLOBAL_CONST unsigned short guardERR_ALREADY_STARTED;
 _GLOBAL_CONST unsigned short guardERR_LICENSE_STATUS_UNKNOWN;
 _GLOBAL_CONST unsigned short guardERR_DATA_SIZE;
 _GLOBAL_CONST unsigned short guardERR_UNAVAILABLE;
 _GLOBAL_CONST unsigned short guardERR_INVALID_PARAM;
 _GLOBAL_CONST unsigned short guardERR_CONTEXT_SIZE;
 _GLOBAL_CONST unsigned short guardERR_DONGLE_NOT_FOUND;
 _GLOBAL_CONST unsigned short guardERR_TASK;
 _GLOBAL_CONST unsigned short guardERR_LIC_NOT_INITIALIZED;
 _GLOBAL_CONST unsigned short guardERR_FILE_NOT_FOUND;
 _GLOBAL_CONST unsigned short guardERR_EXECUTE_UPDATE;
 _GLOBAL_CONST unsigned short guardERR_CREATE_CONTEXT_FILE;
 _GLOBAL_CONST unsigned short guardERR_CREATE_UPDATE_CONTEXT;
 _GLOBAL_CONST unsigned short guardERR_SERVICE_VIOLATION;
 _GLOBAL_CONST unsigned short guardERR_VIOLATION;
 _GLOBAL_CONST unsigned short guardERR_ACCESS;
 _GLOBAL_CONST unsigned short guardERR_NOT_STARTED;
 _GLOBAL_CONST unsigned short guardERR_MEMORY;
 _GLOBAL_CONST unsigned short guardERR_BUFFERSIZE;
 _GLOBAL_CONST unsigned short guardERR_GENERAL;
 _GLOBAL_CONST unsigned short guardERR_NULLPOINTER;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct dongleInfo_t
{	unsigned short boxMask;
	unsigned long serNo;
	unsigned char majorFirmwareVersion;
	unsigned char minorFirmwareVersion;
} dongleInfo_t;

typedef struct licenseInfo_t
{	unsigned long firmCode;
	unsigned long productCode;
	unsigned long count;
	plcstring orderNumber[256];
	plcstring description[256];
} licenseInfo_t;

typedef struct neededLicenseInfo_t
{	unsigned long firmCode;
	unsigned long productCode;
	unsigned long neededCount;
	unsigned long count;
	plcdword reaction;
	plcstring orderNumber[256];
	plcstring description[256];
} neededLicenseInfo_t;

typedef struct guardRegisterLicense
{
	/* VAR_INPUT (analog) */
	unsigned long firmCode;
	unsigned long productCode;
	plcstring orderNumber[256];
	plcstring description[256];
	plcdword registerType;
	plcdword reaction;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardRegisterLicense_typ;

typedef struct guardCheckLicense
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long availableLicenses;
	unsigned long neededLicenses;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardCheckLicense_typ;

typedef struct guardDeregisterLicense
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardDeregisterLicense_typ;

typedef struct guardGetContext
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	unsigned long firmCode;
	unsigned long maxContextDataCount;
	unsigned long pContextData;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long contextDataCount;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardGetContext_typ;

typedef struct guardUpdateLicenses
{
	/* VAR_INPUT (analog) */
	unsigned long licenseDataCount;
	unsigned long pLicenseData;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardUpdateLicenses_typ;

typedef struct guardGetDongles
{
	/* VAR_INPUT (analog) */
	struct dongleInfo_t* pDongleInfos;
	unsigned long dongleInfoSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long neededSize;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardGetDongles_typ;

typedef struct guardReadOperatingTime
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	unsigned long counterType;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long operatingTime;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardReadOperatingTime_typ;

typedef struct guardStartCustomOpTimeCounter
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	unsigned long counterType;
	unsigned long cfgUpdateSeconds;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardStartCustomOpTimeCounter_typ;

typedef struct guardStopCustomOpTimeCounter
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardStopCustomOpTimeCounter_typ;

typedef struct guardReadData
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char userData[242];
	unsigned long usedSize;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardReadData_typ;

typedef struct guardWriteData
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	unsigned char userData[242];
	unsigned long userDataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardWriteData_typ;

typedef struct guardGetStatus
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	plcdword reactionStatus;
	/* VAR_INPUT (digital) */
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit licenseOk;
} guardGetStatus_typ;

typedef struct guardGetLicenses
{
	/* VAR_INPUT (analog) */
	unsigned long maxNumLicenses;
	unsigned long pLicenses;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long numLicenses;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardGetLicenses_typ;

typedef struct guardGetDongleLicenses
{
	/* VAR_INPUT (analog) */
	unsigned short boxMask;
	unsigned long serNo;
	unsigned long maxNumLicenses;
	unsigned long pLicenses;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long numLicenses;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardGetDongleLicenses_typ;

typedef struct guardGetNeededLicenses
{
	/* VAR_INPUT (analog) */
	unsigned long maxNumNeededLicenses;
	unsigned long pNeededLicenses;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long numNeededLicenses;
	/* VAR (analog) */
	unsigned short _statemachine;
	unsigned short _result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} guardGetNeededLicenses_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void guardRegisterLicense(struct guardRegisterLicense* inst);
_BUR_PUBLIC void guardCheckLicense(struct guardCheckLicense* inst);
_BUR_PUBLIC void guardDeregisterLicense(struct guardDeregisterLicense* inst);
_BUR_PUBLIC void guardGetContext(struct guardGetContext* inst);
_BUR_PUBLIC void guardUpdateLicenses(struct guardUpdateLicenses* inst);
_BUR_PUBLIC void guardGetDongles(struct guardGetDongles* inst);
_BUR_PUBLIC void guardReadOperatingTime(struct guardReadOperatingTime* inst);
_BUR_PUBLIC void guardStartCustomOpTimeCounter(struct guardStartCustomOpTimeCounter* inst);
_BUR_PUBLIC void guardStopCustomOpTimeCounter(struct guardStopCustomOpTimeCounter* inst);
_BUR_PUBLIC void guardReadData(struct guardReadData* inst);
_BUR_PUBLIC void guardWriteData(struct guardWriteData* inst);
_BUR_PUBLIC void guardGetStatus(struct guardGetStatus* inst);
_BUR_PUBLIC void guardGetLicenses(struct guardGetLicenses* inst);
_BUR_PUBLIC void guardGetDongleLicenses(struct guardGetDongleLicenses* inst);
_BUR_PUBLIC void guardGetNeededLicenses(struct guardGetNeededLicenses* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASGUARD_ */

