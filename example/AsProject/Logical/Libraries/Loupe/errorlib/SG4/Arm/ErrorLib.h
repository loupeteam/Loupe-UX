/* Automation Studio generated header file */
/* Do not edit ! */
/* ErrorLib 0.23.3 */

#ifndef _ERRORLIB_
#define _ERRORLIB_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _ErrorLib_VERSION
#define _ErrorLib_VERSION 0.23.3
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "astime.h"
		#include "sys_lib.h"
		#include "AsBrStr.h"
		#include "logthat.h"
		#include "stringext.h"
		#include "hmitools.h"
#endif
#ifdef _SG4
		#include "astime.h"
		#include "sys_lib.h"
		#include "AsBrStr.h"
		#include "logthat.h"
		#include "stringext.h"
		#include "hmitools.h"
#endif
#ifdef _SGC
		#include "astime.h"
		#include "sys_lib.h"
		#include "AsBrStr.h"
		#include "logthat.h"
		#include "stringext.h"
		#include "hmitools.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define ERRCOL_DEFAULT_LOGGERNAME "Errors"
 #define ERRCOL_DEFAULT_ELEM_ACKNOWLEDGE "IN.CMD.AcknowledgeError"
 #define ERRCOL_DEFAULT_ELEM_ERRORID "OUT.STAT.ErrorID"
 #define ERRCOL_DEFAULT_ELEM_ERRORSTRING "OUT.STAT.ErrorString"
 #define ERRCOL_DEFAULT_ELEM_ERRORACTIVE "OUT.STAT.Error"
 #define ERRCOL_DEFAULT_MAXSOURCES 100U
 #define ERRCOL_DEFAULT_ERRCOLSOURCENAME "Error Collector"
 #define ERRCOL_MAXITERATIONS 10U
 #define ERRCOL_MAI_ERRORINFO 99U
 #define ERRCOL_STRLEN_DISPLAYSTRING 484U
 #define ERRCOL_STRLEN_TIMESTAMP 19U
 #define ERRCOL_STRLEN_ERRORSTRING 329U
 #define ERRCOL_STRLEN_ELEMNAME 80U
 #define ERRCOL_STRLEN_VARNAME 120U
 #define ERRCOL_STRLEN_SOURCETASK 10U
 #define ERRCOL_STRLEN_SOURCENAME 120U
#else
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_LOGGERNAME[9];
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_ELEM_ACKNOWLEDGE[81];
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_ELEM_ERRORID[81];
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_ELEM_ERRORSTRING[81];
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_ELEM_ERRORACTIVE[81];
 _GLOBAL_CONST unsigned short ERRCOL_DEFAULT_MAXSOURCES;
 _GLOBAL_CONST plcstring ERRCOL_DEFAULT_ERRCOLSOURCENAME[121];
 _GLOBAL_CONST unsigned short ERRCOL_MAXITERATIONS;
 _GLOBAL_CONST unsigned short ERRCOL_MAI_ERRORINFO;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_DISPLAYSTRING;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_TIMESTAMP;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_ERRORSTRING;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_ELEMNAME;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_VARNAME;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_SOURCETASK;
 _GLOBAL_CONST unsigned short ERRCOL_STRLEN_SOURCENAME;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum ERRCOL_ERR_enum
{	ERRCOL_ERROR = 50000,
	ERRCOL_ERR_ALLOC,
	ERRCOL_ERR_INVALIDINPUT,
	ERRCOL_ERR_NOTINIT,
	ERRCOL_ERR_FULLSOURCES,
	ERRCOL_ERR_FULLERRORS,
	ERRCOL_ERR_INVALIDSOURCE,
	ERRCOL_ERR_INVALIDERROR,
	ERRCOL_ERR_EMPTYLIST,
	ERRCOL_ERR_INCONSISTENTERROR,
	ERRCOL_ERR_
} ERRCOL_ERR_enum;

typedef struct ErrorCollector_Int_Source_typ
{	plcstring SourceName[121];
	plcstring SourceTask[11];
	unsigned long pErrorActive;
	unsigned long pErrorString;
	unsigned long pErrorID;
	unsigned long pAcknowledge;
	plcbit OldErrorActive;
	unsigned short OldErrorID;
	plcbit Log;
	plcbit AddToList;
	plcstring Timestamp[20];
} ErrorCollector_Int_Source_typ;

typedef struct ErrorCollector_Internal_typ
{	plcbit Initialized;
	struct ErrorCollector_Int_Source_typ* pSource;
	unsigned short NumSources;
	unsigned short NumErrors;
	plcstring Timestamp[20];
} ErrorCollector_Internal_typ;

typedef struct ErrorCollector_OUT_ErrorInfo_typ
{	plcstring Timestamp[20];
	plcstring SourceName[121];
	plcstring ErrorString[330];
	unsigned short ErrorID;
	plcbit Active;
	plcbit Acknowledged;
	unsigned short SourceIndex;
	plcstring SourceTask[11];
	unsigned long pAcknowledge;
} ErrorCollector_OUT_ErrorInfo_typ;

typedef struct ErrorCollector_OUT_STAT_typ
{	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[330];
} ErrorCollector_OUT_STAT_typ;

typedef struct ErrorCollector_OUT_typ
{	struct ErrorCollector_OUT_STAT_typ STAT;
	unsigned short ErrorCount;
	struct ErrorCollector_OUT_ErrorInfo_typ ErrorInfo[100];
} ErrorCollector_OUT_typ;

typedef struct ErrorColl_IN_CFG_ElemNames_typ
{	plcstring ErrorActive[81];
	plcstring ErrorString[81];
	plcstring ErrorID[81];
	plcstring Acknowledge[81];
} ErrorColl_IN_CFG_ElemNames_typ;

typedef struct ErrorCollector_IN_CFG_typ
{	plcstring ErrorCollectorSourceName[121];
	unsigned short MaxSources;
	struct ErrorColl_IN_CFG_ElemNames_typ StructureElementNames;
	plcbit DisableLogging;
	plcstring LoggerName[9];
} ErrorCollector_IN_CFG_typ;

typedef struct ErrorCollector_IN_PAR_typ
{	unsigned short ErrorIndex;
} ErrorCollector_IN_PAR_typ;

typedef struct ErrorCollector_IN_CMD_typ
{	plcbit AcknowledgeError;
	plcbit AcknowledgeErrorAtIndex;
	plcbit AcknowledgeAllErrors;
} ErrorCollector_IN_CMD_typ;

typedef struct ErrorCollector_IN_typ
{	struct ErrorCollector_IN_CMD_typ CMD;
	struct ErrorCollector_IN_PAR_typ PAR;
	struct ErrorCollector_IN_CFG_typ CFG;
} ErrorCollector_IN_typ;

typedef struct ErrorCollector_typ
{	struct ErrorCollector_IN_typ IN;
	struct ErrorCollector_OUT_typ OUT;
	struct ErrorCollector_Internal_typ Internal;
} ErrorCollector_typ;

typedef struct ErrorCollector_HMI_Internal_typ
{	unsigned short ErrorIndex[100];
	unsigned short NumDisplayErrors;
	unsigned short OldNumErrors;
	plcstring OldSearchString[485];
} ErrorCollector_HMI_Internal_typ;

typedef struct ErrorCollector_HMI_typ
{	plcstring SearchString[485];
	plcstring ErrorList[100][485];
	struct HMI_Listbox_typ ErrorListbox;
	plcstring ErrorText[485];
	struct HMI_Button_typ Acknowledge;
	struct HMI_Button_typ AcknowledgeAll;
	struct ErrorCollector_HMI_Internal_typ Internal;
} ErrorCollector_HMI_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short errcolAddSourceByAddress(unsigned long pSourceName, unsigned long pErrorActive, unsigned long pErrorString, unsigned long pErrorID, unsigned long pAcknowledge, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolAddSourceByName(unsigned long pSourceName, unsigned long pVarName, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolAddError(unsigned long pSourceName, unsigned long pErrorString, unsigned short ErrorID, unsigned long pAcknowledge, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolAcknowledge(unsigned short ErrorIndex, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short ErrorCollectorFn_Init(struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short ErrorCollectorFn_Cyclic(struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short ErrorCollectorFn_HMI_Cyclic(struct ErrorCollector_HMI_typ* HMI, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolInternalSetError(unsigned short ErrorID, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolIntGenerateDisplayString(unsigned long pDisplayString, unsigned long DisplayStringLength, unsigned long pTimestamp, unsigned long pSourceName, unsigned short ErrorID, unsigned long pErrorString);
_BUR_PUBLIC unsigned short errcolInternalAddError(unsigned short SourceIndex, unsigned long pTimestamp, unsigned long pSourceName, unsigned long pSourceTask, unsigned short ErrorID, unsigned long pErrorString, unsigned long pAcknowledge, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolInternalLogError(unsigned long pSourceName, unsigned short ErrorID, unsigned long pErrorString, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolInternalLogAcknowledge(unsigned long pSourceName, unsigned short ErrorID, unsigned long pErrorString, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolInternalRemoveError(unsigned short ErrorIndex, struct ErrorCollector_typ* t);
_BUR_PUBLIC unsigned short errcolInternalRefreshHMIDisplay(struct ErrorCollector_HMI_typ* HMI, struct ErrorCollector_typ* t);


__asm__(".section \".plc\"");

/* Additional IEC dependencies */
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/logthat/Constants.var\\\" scope \\\"global\\\"\\n\"");

__asm__(".previous");

#ifdef __cplusplus
};
#endif
#endif /* _ERRORLIB_ */

