/* Automation Studio generated header file */
/* Do not edit ! */
/* vartools 0.11.3 */

#ifndef _VARTOOLS_
#define _VARTOOLS_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _vartools_VERSION
#define _vartools_VERSION 0.11.3
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "AsBrWStr.h"
		#include "stringext.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "AsBrWStr.h"
		#include "stringext.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "sys_lib.h"
		#include "AsBrWStr.h"
		#include "stringext.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define VAR_STRLEN_NAME 120U
 #define VAR_STRLEN_VALUE 120U
 #define VAR_MAI_MEMBERS 49U
 #define VAR_MAI_VARLIST 99U
 #define VAR_MIN_SINT (-128)
 #define VAR_MAX_SINT 127
 #define VAR_MIN_INT (-32768)
 #define VAR_MAX_INT 32767
 #define VAR_MIN_DINT (-2147483647)
 #define VAR_MAX_DINT 2147483647
 #define VAR_MIN_USINT 0
 #define VAR_MAX_USINT 255
 #define VAR_MIN_UINT 0
 #define VAR_MAX_UINT 65535
 #define VAR_MIN_UDINT 0U
 #define VAR_MAX_UDINT 4294967295U
 #define VAR_MIN_REAL (-3.4e+38f)
 #define VAR_MAX_REAL 3.4e+38f
#else
 _GLOBAL_CONST unsigned char VAR_STRLEN_NAME;
 _GLOBAL_CONST unsigned char VAR_STRLEN_VALUE;
 _GLOBAL_CONST unsigned short VAR_MAI_MEMBERS;
 _GLOBAL_CONST unsigned char VAR_MAI_VARLIST;
 _GLOBAL_CONST signed long VAR_MIN_SINT;
 _GLOBAL_CONST signed long VAR_MAX_SINT;
 _GLOBAL_CONST signed long VAR_MIN_INT;
 _GLOBAL_CONST signed long VAR_MAX_INT;
 _GLOBAL_CONST signed long VAR_MIN_DINT;
 _GLOBAL_CONST signed long VAR_MAX_DINT;
 _GLOBAL_CONST signed long VAR_MIN_USINT;
 _GLOBAL_CONST signed long VAR_MAX_USINT;
 _GLOBAL_CONST signed long VAR_MIN_UINT;
 _GLOBAL_CONST signed long VAR_MAX_UINT;
 _GLOBAL_CONST unsigned long VAR_MIN_UDINT;
 _GLOBAL_CONST unsigned long VAR_MAX_UDINT;
 _GLOBAL_CONST float VAR_MIN_REAL;
 _GLOBAL_CONST float VAR_MAX_REAL;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum VAR_ERR_enum
{	VAR_ERR_PV_NOT_FOUND = 14710,
	VAR_ERR_PVITEM_ENUM = 14713,
	VAR_ERR_INVALIDINPUT = 50000,
	VAR_ERR_INVALIDVALUE,
	VAR_ERR_UNSUPPORTEDTYPE,
	VAR_ERR_INVALIDTYPE,
	VAR_ERR_TOO_MANY_ITEMS,
	VAR_ERR_
} VAR_ERR_enum;

typedef enum VAR_TYPE_enum
{	VAR_TYPE_STRUCT = 0,
	VAR_TYPE_BOOL,
	VAR_TYPE_SINT,
	VAR_TYPE_INT,
	VAR_TYPE_DINT,
	VAR_TYPE_USINT,
	VAR_TYPE_UINT,
	VAR_TYPE_UDINT,
	VAR_TYPE_REAL,
	VAR_TYPE_STRING,
	VAR_TYPE_ULINT,
	VAR_TYPE_DATE_AND_TIME,
	VAR_TYPE_TIME,
	VAR_TYPE_DATE,
	VAR_TYPE_LREAL,
	VAR_TYPE_ARRAY_OF_STRUCT,
	VAR_TYPE_TIME_OF_DAY,
	VAR_TYPE_BYTE,
	VAR_TYPE_WORD,
	VAR_TYPE_DWORD,
	VAR_TYPE_LWORD,
	VAR_TYPE_WSTRING,
	VAR_TYPE_LINT = 23,
	VAR_TYPE_UNDEFINED = 999
} VAR_TYPE_enum;

typedef struct varVariable_typ
{	plcstring name[121];
	plcstring value[121];
	unsigned long address;
	unsigned long dataType;
	unsigned long length;
	unsigned short dimension;
} varVariable_typ;

typedef struct varVariableWatch
{
	/* VAR_INPUT (analog) */
	unsigned long pVariable;
	/* VAR_OUTPUT (analog) */
	unsigned short Status;
	/* VAR (analog) */
	plcstring iName[121];
	plcstring iValue[121];
} varVariableWatch_typ;

typedef struct variableBrowser
{
	/* VAR_INPUT (analog) */
	plcstring VariableName[121];
	signed short MemberIndex;
	/* VAR_OUTPUT (analog) */
	plcstring CurrentVariable[121];
	plcstring MemberName[50][121];
	plcstring MemberValue[50][121];
	struct varVariable_typ MemberInfo[50];
	unsigned short NumberMembers;
	struct varVariable_typ info;
	/* VAR (analog) */
	struct varVariableWatch iMemberWatch[50];
	struct varVariableWatch iCurrentWatch;
	plcstring iLevel[20][33];
	unsigned char iLevelIndex;
	unsigned char iMemberIndex;
	/* VAR_INPUT (digital) */
	plcbit Back;
} variableBrowser_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void varVariableWatch(struct varVariableWatch* inst);
_BUR_PUBLIC void variableBrowser(struct variableBrowser* inst);
_BUR_PUBLIC unsigned short varGetInfo(unsigned long pVariable);
_BUR_PUBLIC unsigned short varGetValue(unsigned long pVariable);
_BUR_PUBLIC unsigned short varGetLrealValue(unsigned long pVariable, unsigned long pValue);
_BUR_PUBLIC unsigned short varGetRealValue(unsigned long pVariable, unsigned long pValue);
_BUR_PUBLIC unsigned short varRefresh(unsigned long pVariable);
_BUR_PUBLIC unsigned short varSetValue(unsigned long pVariable);
_BUR_PUBLIC unsigned short varGetVariableList(unsigned long pVariableName, unsigned long List);
_BUR_PUBLIC plcbit varPopulateMemberNames(plcstring* PVName, unsigned char prefix);


#ifdef __cplusplus
};
#endif
#endif /* _VARTOOLS_ */

