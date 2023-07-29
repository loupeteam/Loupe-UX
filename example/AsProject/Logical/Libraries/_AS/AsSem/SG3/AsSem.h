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

#ifndef _IEC_CONST
#define _IEC_CONST _WEAK const
#endif

/* Constants */
#ifdef _REPLACE_CONST
 #define semERR_CREATE 33320U
 #define semERR_DELETE 33321U
 #define semERR_NOT_EXIST 33322U
 #define semERR_NOT_FREE 33323U
 #define semERR_ALREADY_FREE 33324U
#else
 _IEC_CONST unsigned short semERR_CREATE = 33320U;
 _IEC_CONST unsigned short semERR_DELETE = 33321U;
 _IEC_CONST unsigned short semERR_NOT_EXIST = 33322U;
 _IEC_CONST unsigned short semERR_NOT_FREE = 33323U;
 _IEC_CONST unsigned short semERR_ALREADY_FREE = 33324U;
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
void SemCreate(struct SemCreate* inst);
void SemDelete(struct SemDelete* inst);
void SemGetInfo(struct SemGetInfo* inst);
unsigned short SemAcquire(unsigned long ident);
unsigned short SemRelease(unsigned long ident);


#ifdef __cplusplus
};
#endif
#endif /* _ASSEM_ */

                                                           
