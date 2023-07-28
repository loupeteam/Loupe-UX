/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASSEM_
#define _ASSEM_
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
 #define semERR_ALREADY_FREE 33324U
 #define semERR_NOT_FREE 33323U
 #define semERR_NOT_EXIST 33322U
 #define semERR_DELETE 33321U
 #define semERR_CREATE 33320U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short semERR_ALREADY_FREE;
 _GLOBAL_CONST unsigned short semERR_NOT_FREE;
 _GLOBAL_CONST unsigned short semERR_NOT_EXIST;
 _GLOBAL_CONST unsigned short semERR_DELETE;
 _GLOBAL_CONST unsigned short semERR_CREATE;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct SemCreate
{
	/* VAR_INPUT (analog) */
	unsigned long initCount;
	unsigned long maxCount;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SemCreate_typ;

typedef struct SemDelete
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SemDelete_typ;

typedef struct SemGetInfo
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long maxCount;
	unsigned long curCount;
	/* VAR_INPUT (digital) */
	plcbit enable;
} SemGetInfo_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void SemCreate(struct SemCreate* inst);
_BUR_PUBLIC void SemDelete(struct SemDelete* inst);
_BUR_PUBLIC void SemGetInfo(struct SemGetInfo* inst);
_BUR_PUBLIC unsigned short SemAcquire(unsigned long ident);
_BUR_PUBLIC unsigned short SemRelease(unsigned long ident);


#ifdef __cplusplus
};
#endif
#endif /* _ASSEM_ */

