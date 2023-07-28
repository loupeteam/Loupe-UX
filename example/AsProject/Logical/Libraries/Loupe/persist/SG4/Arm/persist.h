/* Automation Studio generated header file */
/* Do not edit ! */
/* persist 0.00.7 */

#ifndef _PERSIST_
#define _PERSIST_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _persist_VERSION
#define _persist_VERSION 0.00.7
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "sys_lib.h"
#endif
#ifdef _SG4
		#include "sys_lib.h"
#endif
#ifdef _SGC
		#include "sys_lib.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define PERSIST_MAI_VARLIST 99U
 #define PERSIST_STRLEN_VARNAME 120U
 #define PERSIST_STRLEN_ERRORSTRING 320U
#else
 _GLOBAL_CONST unsigned char PERSIST_MAI_VARLIST;
 _GLOBAL_CONST unsigned char PERSIST_STRLEN_VARNAME;
 _GLOBAL_CONST unsigned short PERSIST_STRLEN_ERRORSTRING;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum PERSIST_ERR_enum
{	PERSIST_ERR_INVALIDINPUT = 50000,
	PERSIST_ERR_OUTOFMEMORY,
	PERSIST_ERR_DATAMOVED_CHANGED
} PERSIST_ERR_enum;

typedef struct Persistence_Int_VarInfo_typ
{	unsigned long pWorkingVariable;
	unsigned long sizeofWorkingVariable;
	unsigned long pPersistentMemory;
} Persistence_Int_VarInfo_typ;

typedef struct Persistence_Internal_typ
{	struct Persistence_Int_VarInfo_typ WorkingVariableInfo[100];
	struct Persistence_Int_VarInfo_typ ValidWorkingVariable;
	unsigned char iVariable;
	plcbit DataValid;
} Persistence_Internal_typ;

typedef struct Persistence_OUT_STAT_typ
{	unsigned long RequiredMemory;
	plcbit Initialized;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[321];
} Persistence_OUT_STAT_typ;

typedef struct Persistence_OUT_typ
{	struct Persistence_OUT_STAT_typ STAT;
} Persistence_OUT_typ;

typedef struct Persistence_IN_typ
{	unsigned long pPersistentVariable;
	unsigned long sizeofPersistentVariable;
	unsigned long pDataValid;
	plcstring WorkingVariableList[100][121];
} Persistence_IN_typ;

typedef struct Persistence_typ
{	struct Persistence_IN_typ IN;
	struct Persistence_OUT_typ OUT;
	struct Persistence_Internal_typ Internal;
} Persistence_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short PersistFn_Init(struct Persistence_typ* Persistence);
_BUR_PUBLIC unsigned short PersistFn_Cyclic(struct Persistence_typ* Persistence);
_BUR_PUBLIC unsigned short persistInternalMapMemory(struct Persistence_typ* Persistence);
_BUR_PUBLIC unsigned short persistInternalBackup(struct Persistence_typ* Persistence);
_BUR_PUBLIC unsigned short persistInternalRestore(struct Persistence_typ* Persistence);


#ifdef __cplusplus
};
#endif
#endif /* _PERSIST_ */

