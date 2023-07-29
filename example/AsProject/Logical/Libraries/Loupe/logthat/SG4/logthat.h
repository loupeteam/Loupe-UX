/* Automation Studio generated header file */
/* Do not edit ! */
/* logthat 0.05.1 */

#ifndef _LOGTHAT_
#define _LOGTHAT_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _logthat_VERSION
#define _logthat_VERSION 0.05.1
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "ArEventLog.h"
		#include "AsBrStr.h"
		#include "StringExt.h"
#endif
#ifdef _SG4
		#include "ArEventLog.h"
		#include "AsBrStr.h"
		#include "StringExt.h"
#endif
#ifdef _SGC
		#include "ArEventLog.h"
		#include "AsBrStr.h"
		#include "StringExt.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define LOG_STRLEN_LOGGERNAME 8U
 #define LOG_STRLEN_MESSAGE 320U
 #define LOG_STRLEN_STATENAME 80U
 #define LOG_STRLEN_MODULENAME 20U
 #define LOG_DEFAULT_LOGGERSIZE 100000U
 #define LOG_DEFAULT_FACILITY 0U
#else
 _GLOBAL_CONST unsigned short LOG_STRLEN_LOGGERNAME;
 _GLOBAL_CONST unsigned short LOG_STRLEN_MESSAGE;
 _GLOBAL_CONST unsigned short LOG_STRLEN_STATENAME;
 _GLOBAL_CONST unsigned short LOG_STRLEN_MODULENAME;
 _GLOBAL_CONST unsigned long LOG_DEFAULT_LOGGERSIZE;
 _GLOBAL_CONST unsigned short LOG_DEFAULT_FACILITY;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum LOG_SEVERITY_enum
{	LOG_SEVERITY_SUCCESS,
	LOG_SEVERITY_INFO,
	LOG_SEVERITY_WARNING,
	LOG_SEVERITY_ERROR
} LOG_SEVERITY_enum;

typedef enum LOG_PERSISTENCE_enum
{	LOG_PERSISTENCE_VOLATILE,
	LOG_PERSISTENCE_REMANENT,
	LOG_PERSISTENCE_PERSIST
} LOG_PERSISTENCE_enum;

typedef enum LOG_ERR_enum
{	LOG_ERR_INVALIDINPUT = 58300,
	LOG_ERR_NOTINITIALIZED,
	LOG_ERR_LOGGERSFULL
} LOG_ERR_enum;

typedef struct InteralLogFubs_typ
{	struct ArEventLogCreate CreateLog;
	struct ArEventLogGetIdent GetIdent;
	struct ArEventLogWrite WriteLog;
} InteralLogFubs_typ;

typedef struct logLogger_Internal_typ
{	unsigned short ID;
	plcbit Allocated;
	unsigned short AllocStatus;
	unsigned short CyclicStatus;
	ArEventLogIdentType Ident;
	unsigned char Persistance;
	signed long creationStatus;
} logLogger_Internal_typ;

typedef struct logLogger_typ
{	plcstring LoggerName[9];
	unsigned long LoggerSize;
	unsigned long MessageSize;
	unsigned long BufferedEntries;
	plcbit Error;
	unsigned short ErrorID;
	struct logLogger_Internal_typ Internal;
} logLogger_typ;

typedef struct logDelete
{
	/* VAR_INPUT (analog) */
	plcstring name[9];
	/* VAR_OUTPUT (analog) */
	signed long errorID;
	/* VAR (analog) */
	struct ArEventLogGetIdent ident;
	struct ArEventLogDelete deletion;
	/* VAR_INPUT (digital) */
	plcbit execute;
	/* VAR_OUTPUT (digital) */
	plcbit done;
	plcbit busy;
	plcbit error;
} logDelete_typ;

typedef struct logStateChange
{
	/* VAR_INPUT (analog) */
	plcstring LoggerName[9];
	plcstring ModuleName[21];
	unsigned long State;
	plcstring StateName[81];
	/* VAR (analog) */
	unsigned long oldState;
	plcstring oldStateName[81];
	unsigned short Status;
	/* VAR (digital) */
	plcbit initialized;
} logStateChange_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void logDelete(struct logDelete* inst);
_BUR_PUBLIC void logStateChange(struct logStateChange* inst);
_BUR_PUBLIC signed long createLogInit(plcstring* loggerName, unsigned long size, enum LOG_PERSISTENCE_enum persistence);
_BUR_PUBLIC signed long logEventID(plcstring* loggerName, signed long eventID, plcstring* eventString, unsigned long pMsgData);
_BUR_PUBLIC signed long logSuccess(plcstring* loggerName, unsigned short errorID, plcstring* errorString, unsigned long pMsgData);
_BUR_PUBLIC signed long logWarning(plcstring* loggerName, unsigned short errorID, plcstring* errorString, unsigned long pMsgData);
_BUR_PUBLIC signed long logError(plcstring* loggerName, unsigned short errorID, plcstring* errorString, unsigned long pMsgData);
_BUR_PUBLIC signed long logInfo(plcstring* loggerName, unsigned short errorID, plcstring* errorString, unsigned long pMsgData);


#ifdef __cplusplus
};
#endif
#endif /* _LOGTHAT_ */

