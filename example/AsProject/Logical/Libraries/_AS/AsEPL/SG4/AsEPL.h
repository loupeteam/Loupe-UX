/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASEPL_
#define _ASEPL_
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
 #define ERR_ASEPL_NOT_IMPLEMENTED 31399U
 #define ERR_ASEPL_NILPOINTER 31392U
 #define ERR_ASEPL_SUBINDEX_DOESNOTEXIST 31349U
 #define ERR_ASEPL_INDEX_DOESNOTEXIST 31348U
 #define ERR_ASEPL_SUBINDEX_EXISTS 31347U
 #define ERR_ASEPL_INDEX_EXISTS 31346U
 #define ERR_ASEPL_PARAM_OUTOFRANGE 31345U
 #define ERR_ASEPL_ACCESS_FAILED 31344U
 #define ERR_ASEPL_CN_ONLY 31343U
 #define ERR_ASEPL_MN_ONLY 31342U
 #define ERR_ASEPL_WRONG_DEVICE 31341U
 #define ERR_ASEPL_BASE 31340U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short ERR_ASEPL_NOT_IMPLEMENTED;
 _GLOBAL_CONST unsigned short ERR_ASEPL_NILPOINTER;
 _GLOBAL_CONST unsigned short ERR_ASEPL_SUBINDEX_DOESNOTEXIST;
 _GLOBAL_CONST unsigned short ERR_ASEPL_INDEX_DOESNOTEXIST;
 _GLOBAL_CONST unsigned short ERR_ASEPL_SUBINDEX_EXISTS;
 _GLOBAL_CONST unsigned short ERR_ASEPL_INDEX_EXISTS;
 _GLOBAL_CONST unsigned short ERR_ASEPL_PARAM_OUTOFRANGE;
 _GLOBAL_CONST unsigned short ERR_ASEPL_ACCESS_FAILED;
 _GLOBAL_CONST unsigned short ERR_ASEPL_CN_ONLY;
 _GLOBAL_CONST unsigned short ERR_ASEPL_MN_ONLY;
 _GLOBAL_CONST unsigned short ERR_ASEPL_WRONG_DEVICE;
 _GLOBAL_CONST unsigned short ERR_ASEPL_BASE;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct EPL_I_TYPE
{	unsigned long init;
	unsigned long hdl;
	unsigned long st;
	unsigned long errInfo;
	unsigned long size;
	unsigned char bus;
	unsigned char sl;
	unsigned char ss;
	unsigned char if_;
	unsigned char nd;
	unsigned long tid;
} EPL_I_TYPE;

typedef struct EplSDORead
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned char node;
	unsigned short index;
	unsigned char subindex;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long errorinfo;
	unsigned long readlen;
	/* VAR (analog) */
	struct EPL_I_TYPE intern;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplSDORead_typ;

typedef struct EplSDOWrite
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned char node;
	unsigned short index;
	unsigned char subindex;
	unsigned long pData;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long errorinfo;
	/* VAR (analog) */
	struct EPL_I_TYPE intern;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplSDOWrite_typ;

typedef struct EplGetLocalNodeID
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned char nodeid;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplGetLocalNodeID_typ;

typedef struct EplCreateObject
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned short index;
	unsigned char subindex;
	unsigned long datalen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplCreateObject_typ;

typedef struct EplDeleteObject
{
	/* VAR_INPUT (analog) */
	plcstring (*pDevice);
	unsigned short index;
	unsigned char subindex;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} EplDeleteObject_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void EplSDORead(struct EplSDORead* inst);
_BUR_PUBLIC void EplSDOWrite(struct EplSDOWrite* inst);
_BUR_PUBLIC void EplGetLocalNodeID(struct EplGetLocalNodeID* inst);
_BUR_PUBLIC void EplCreateObject(struct EplCreateObject* inst);
_BUR_PUBLIC void EplDeleteObject(struct EplDeleteObject* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASEPL_ */

