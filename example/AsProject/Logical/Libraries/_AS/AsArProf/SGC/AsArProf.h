/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASARPROF_
#define _ASARPROF_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <runtime.h>

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define profERR_PARAMETER 31050U
 #define profERR_DATMODINVALID 31019U
 #define profERR_NOTCYCCTX 31018U
 #define profERR_DATMODREAD 31017U
 #define profERR_STOP 31016U
 #define profERR_START 31015U
 #define profERR_DATMODSIZE 31014U
 #define profERR_ARCHDELETE 31013U
 #define profERR_ARCHCREATE 31012U
 #define profERR_ARCHEXIST 31011U
 #define profERR_NODATMOD 31010U
 #define profERR_DATMODINSTALL 31009U
 #define profERR_DEFMODREAD 31008U
 #define profERR_DEFMODCREATE 31007U
 #define profERR_SETUPBUFFER 31006U
 #define profERR_CYCGETTAB 31005U
 #define profERR_NOMEMORY 31004U
 #define profERR_NOTR2R 31003U
 #define profERR_NOTRUNNING 31002U
 #define profERR_RUNNING 31001U
 #define profERR_INACTIVE 31000U
 #define profSTATE_R2R_MAN 9U
 #define profSTATE_R2R 8U
 #define profSTATE_READY 6U
 #define profSTATE_RUNNING 5U
 #define profSTATE_STOPPED 4U
 #define profSTATE_ACTIVE 3U
 #define profSTATE_INACTIVE 2U
 #define profBKPLEVEL_SHUTDOWN 1U
 #define profBKPLEVEL_EXCEPTION 0U
 #define profMEMTYPE_USERRAM 3U
 #define profMEMTYPE_USERROM 2U
 #define profMEMTYPE_DRAM 65U
 #define profLOGMOD_STARTUPINST 8U
 #define profLOGMOD_NOAUTOSTART 4U
 #define profLOGMOD_GETSTACK 2U
 #define profLOGMOD_CONTINUOUS 1U
 #define profLOGMOD_UNTILFULL 0U
 #define profLOGGRP_ALL 4169007119U
 #define profLOGGRP_TC 2013265920U
 #define profLOGGRP_EXCP 786432U
 #define profLOGGRP_SYSTEM 1179651U
 #define profLOGGRP_USER 2147483660U
 #define profLOGGRP_USEREVENT 2147483648U
 #define profLOGGRP_TASKCLASS_CYCLIC 1073741824U
 #define profLOGGRP_TASKCLASS_EXC 536870912U
 #define profLOGGRP_TASKCLASS_EXITUP 268435456U
 #define profLOGGRP_TASKCLASS_INITUP 134217728U
 #define profLOGGRP_NMIEVENT 4194304U
 #define profLOGGRP_SYSEVENT 2097152U
 #define profLOGGRP_LOGGER 1048576U
 #define profLOGGRP_PROCESSOR_EXC 524288U
 #define profLOGGRP_SYSTEM_EXC 262144U
 #define profLOGGRP_OS_TASK 131072U
 #define profLOGGRP_LIB_FUNC 8U
 #define profLOGGRP_TC_TASK 4U
 #define profLOGGRP_IRQ_HANDLER 2U
 #define profLOGGRP_TASK_SWITCH 1U
 #define profARCHMOD_OPT_NODEL 8U
 #define profARCHMOD_OPT_STOP 4U
 #define profARCHMOD_OPT_FILE 2U
 #define profARCHMOD_OPT_ERROR 1U
 #define profUSER_EVENT_STOP 1U
 #define profUSER_EVENT_START 0U
 #define profUSER_EVENT_MAX 16777215U
 #define profIDLE_MEAS_PERIOD_MIN 100U
 #define profIDLE_MEAS_PERIOD_MAX 60000U
 #define profIDLE_MEAS_LEVEL_3 189U
 #define profIDLE_MEAS_LEVEL_2 50U
 #define profIDLE_MEAS_LEVEL_1 1U
#else
 _IEC_CONST unsigned short profERR_PARAMETER = 31050U;
 _IEC_CONST unsigned short profERR_DATMODINVALID = 31019U;
 _IEC_CONST unsigned short profERR_NOTCYCCTX = 31018U;
 _IEC_CONST unsigned short profERR_DATMODREAD = 31017U;
 _IEC_CONST unsigned short profERR_STOP = 31016U;
 _IEC_CONST unsigned short profERR_START = 31015U;
 _IEC_CONST unsigned short profERR_DATMODSIZE = 31014U;
 _IEC_CONST unsigned short profERR_ARCHDELETE = 31013U;
 _IEC_CONST unsigned short profERR_ARCHCREATE = 31012U;
 _IEC_CONST unsigned short profERR_ARCHEXIST = 31011U;
 _IEC_CONST unsigned short profERR_NODATMOD = 31010U;
 _IEC_CONST unsigned short profERR_DATMODINSTALL = 31009U;
 _IEC_CONST unsigned short profERR_DEFMODREAD = 31008U;
 _IEC_CONST unsigned short profERR_DEFMODCREATE = 31007U;
 _IEC_CONST unsigned short profERR_SETUPBUFFER = 31006U;
 _IEC_CONST unsigned short profERR_CYCGETTAB = 31005U;
 _IEC_CONST unsigned short profERR_NOMEMORY = 31004U;
 _IEC_CONST unsigned short profERR_NOTR2R = 31003U;
 _IEC_CONST unsigned short profERR_NOTRUNNING = 31002U;
 _IEC_CONST unsigned short profERR_RUNNING = 31001U;
 _IEC_CONST unsigned short profERR_INACTIVE = 31000U;
 _IEC_CONST unsigned char profSTATE_R2R_MAN = 9U;
 _IEC_CONST unsigned char profSTATE_R2R = 8U;
 _IEC_CONST unsigned char profSTATE_READY = 6U;
 _IEC_CONST unsigned char profSTATE_RUNNING = 5U;
 _IEC_CONST unsigned char profSTATE_STOPPED = 4U;
 _IEC_CONST unsigned char profSTATE_ACTIVE = 3U;
 _IEC_CONST unsigned char profSTATE_INACTIVE = 2U;
 _IEC_CONST unsigned long profBKPLEVEL_SHUTDOWN = 1U;
 _IEC_CONST unsigned long profBKPLEVEL_EXCEPTION = 0U;
 _IEC_CONST unsigned long profMEMTYPE_USERRAM = 3U;
 _IEC_CONST unsigned long profMEMTYPE_USERROM = 2U;
 _IEC_CONST unsigned long profMEMTYPE_DRAM = 65U;
 _IEC_CONST unsigned long profLOGMOD_STARTUPINST = 8U;
 _IEC_CONST unsigned long profLOGMOD_NOAUTOSTART = 4U;
 _IEC_CONST unsigned long profLOGMOD_GETSTACK = 2U;
 _IEC_CONST unsigned long profLOGMOD_CONTINUOUS = 1U;
 _IEC_CONST unsigned long profLOGMOD_UNTILFULL = 0U;
 _IEC_CONST unsigned long profLOGGRP_ALL = 4169007119U;
 _IEC_CONST unsigned long profLOGGRP_TC = 2013265920U;
 _IEC_CONST unsigned long profLOGGRP_EXCP = 786432U;
 _IEC_CONST unsigned long profLOGGRP_SYSTEM = 1179651U;
 _IEC_CONST unsigned long profLOGGRP_USER = 2147483660U;
 _IEC_CONST unsigned long profLOGGRP_USEREVENT = 2147483648U;
 _IEC_CONST unsigned long profLOGGRP_TASKCLASS_CYCLIC = 1073741824U;
 _IEC_CONST unsigned long profLOGGRP_TASKCLASS_EXC = 536870912U;
 _IEC_CONST unsigned long profLOGGRP_TASKCLASS_EXITUP = 268435456U;
 _IEC_CONST unsigned long profLOGGRP_TASKCLASS_INITUP = 134217728U;
 _IEC_CONST unsigned long profLOGGRP_NMIEVENT = 4194304U;
 _IEC_CONST unsigned long profLOGGRP_SYSEVENT = 2097152U;
 _IEC_CONST unsigned long profLOGGRP_LOGGER = 1048576U;
 _IEC_CONST unsigned long profLOGGRP_PROCESSOR_EXC = 524288U;
 _IEC_CONST unsigned long profLOGGRP_SYSTEM_EXC = 262144U;
 _IEC_CONST unsigned long profLOGGRP_OS_TASK = 131072U;
 _IEC_CONST unsigned long profLOGGRP_LIB_FUNC = 8U;
 _IEC_CONST unsigned long profLOGGRP_TC_TASK = 4U;
 _IEC_CONST unsigned long profLOGGRP_IRQ_HANDLER = 2U;
 _IEC_CONST unsigned long profLOGGRP_TASK_SWITCH = 1U;
 _IEC_CONST unsigned long profARCHMOD_OPT_NODEL = 8U;
 _IEC_CONST unsigned long profARCHMOD_OPT_STOP = 4U;
 _IEC_CONST unsigned long profARCHMOD_OPT_FILE = 2U;
 _IEC_CONST unsigned long profARCHMOD_OPT_ERROR = 1U;
 _IEC_CONST unsigned long profUSER_EVENT_STOP = 1U;
 _IEC_CONST unsigned long profUSER_EVENT_START = 0U;
 _IEC_CONST unsigned long profUSER_EVENT_MAX = 16777215U;
 _IEC_CONST unsigned long profIDLE_MEAS_PERIOD_MIN = 100U;
 _IEC_CONST unsigned long profIDLE_MEAS_PERIOD_MAX = 60000U;
 _IEC_CONST unsigned long profIDLE_MEAS_LEVEL_3 = 189U;
 _IEC_CONST unsigned long profIDLE_MEAS_LEVEL_2 = 50U;
 _IEC_CONST unsigned long profIDLE_MEAS_LEVEL_1 = 1U;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct PROFILER_DEFINITION
{	unsigned long logGroup;
	unsigned long logMode;
	unsigned long archMode;
	unsigned long memTypeDef;
	unsigned long memTypeDat;
	unsigned long bufferSize;
	unsigned long backupLevel;
	unsigned long addDataSize;
	unsigned long addOsTskCnt;
	unsigned long libFctCnt;
	unsigned long pLibFunctions;
	unsigned long pArchDevice;
} PROFILER_DEFINITION;

typedef struct PROFILER_MODINFO
{	plcstring name[64];
	unsigned long length;
	plcdt cTime;
	plcdt mTime;
} PROFILER_MODINFO;

typedef struct LogInstall
{
	/* VAR_INPUT (analog) */
	unsigned long pVersion;
	unsigned long pDefinition;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogInstall_typ;

typedef struct LogDeInstall
{
	/* VAR_INPUT (analog) */
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogDeInstall_typ;

typedef struct LogStateGet
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char logstate;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogStateGet_typ;

typedef struct LogArchCreate
{
	/* VAR_INPUT (analog) */
	unsigned long pDevice;
	unsigned long pName;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogArchCreate_typ;

typedef struct LogArchDelete
{
	/* VAR_INPUT (analog) */
	unsigned long pName;
	unsigned long option;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogArchDelete_typ;

typedef struct LogStart
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogStart_typ;

typedef struct LogStop
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogStop_typ;

typedef struct LogEvent
{
	/* VAR_INPUT (analog) */
	unsigned long objIdent;
	unsigned long userEvent;
	unsigned long pAddData;
	unsigned long addDataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} LogEvent_typ;



/* Prototyping of functions and function blocks */
void LogInstall(struct LogInstall* inst);
void LogDeInstall(struct LogDeInstall* inst);
void LogStateGet(struct LogStateGet* inst);
void LogArchCreate(struct LogArchCreate* inst);
void LogArchDelete(struct LogArchDelete* inst);
void LogStart(struct LogStart* inst);
void LogStop(struct LogStop* inst);
void LogEvent(struct LogEvent* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASARPROF_ */

                                                           
