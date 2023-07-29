/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _MTLOOKUP_
#define _MTLOOKUP_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#include <Sys_lib.h>
#include <brsystem.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define mtBCD_WRN_LOOKUP_MEM_ALLOC (-2131754002)
 #define mtBCD_WRN_LOOKUP_MODE_INVALID (-2131754003)
 #define mtBCD_WRN_NODES_Y_INVALID (-2131754004)
 #define mtBCD_WRN_NODES_X_INVALID (-2131754005)
 #define mtBCD_WRN_YVAL_NOT_SORTED (-2131754006)
 #define mtBCD_WRN_XVAL_NOT_SORTED (-2131754007)
 #define mtBCD_WRN_NODES_INVALID (-2131754008)
 #define mtBCD_ERR_LOOKUP_MEM_ALLOC (-1058012178)
 #define mtBCD_ERR_LOOKUP_MODE_INVALID (-1058012179)
 #define mtBCD_ERR_NODES_Y_INVALID (-1058012180)
 #define mtBCD_ERR_NODES_X_INVALID (-1058012181)
 #define mtBCD_ERR_YVAL_NOT_SORTED (-1058012182)
 #define mtBCD_ERR_XVAL_NOT_SORTED (-1058012183)
 #define mtBCD_ERR_NODES_INVALID (-1058012184)
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST signed long mtBCD_WRN_LOOKUP_MEM_ALLOC;
 _GLOBAL_CONST signed long mtBCD_WRN_LOOKUP_MODE_INVALID;
 _GLOBAL_CONST signed long mtBCD_WRN_NODES_Y_INVALID;
 _GLOBAL_CONST signed long mtBCD_WRN_NODES_X_INVALID;
 _GLOBAL_CONST signed long mtBCD_WRN_YVAL_NOT_SORTED;
 _GLOBAL_CONST signed long mtBCD_WRN_XVAL_NOT_SORTED;
 _GLOBAL_CONST signed long mtBCD_WRN_NODES_INVALID;
 _GLOBAL_CONST signed long mtBCD_ERR_LOOKUP_MEM_ALLOC;
 _GLOBAL_CONST signed long mtBCD_ERR_LOOKUP_MODE_INVALID;
 _GLOBAL_CONST signed long mtBCD_ERR_NODES_Y_INVALID;
 _GLOBAL_CONST signed long mtBCD_ERR_NODES_X_INVALID;
 _GLOBAL_CONST signed long mtBCD_ERR_YVAL_NOT_SORTED;
 _GLOBAL_CONST signed long mtBCD_ERR_XVAL_NOT_SORTED;
 _GLOBAL_CONST signed long mtBCD_ERR_NODES_INVALID;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum MTLookUpModeEnum
{	mtLOOKUP_CONSTANT_END_VALUE = 0,
	mtLOOKUP_LINEAR_EXTRAPOLATION = 1
} MTLookUpModeEnum;

typedef struct MTLookUpInternalNode2DType
{	float XValues;
	float YValues;
	float FcnValues;
	float k[2];
} MTLookUpInternalNode2DType;

typedef struct MTLookUpTable2DInternalType
{	float CycleTime;
	plcbit ParametersValid;
	unsigned char NumberOfNodesX;
	unsigned char NumberOfNodesY;
	signed char CoordinateOrderX;
	signed char CoordinateOrderY;
	float InX;
	float InY;
	signed char DisModeX;
	signed char DisModeY;
	plcbit UpdateOld;
	plcbit EnableOld;
	struct MTLookUpInternalNode2DType* Nodes;
} MTLookUpTable2DInternalType;

typedef struct MTLookUpInternalNodeType
{	float XValues;
	float FcnValues;
	float k;
	float d;
} MTLookUpInternalNodeType;

typedef struct MTLookUpTableInternalType
{	float CycleTime;
	plcbit ParametersValid;
	unsigned char NumberOfNodes;
	signed char CoordinateOrder;
	float InX;
	signed char DisMode;
	plcbit UpdateOld;
	plcbit EnableOld;
	struct MTLookUpInternalNodeType Nodes[50];
	enum MTLookUpModeEnum Mode;
} MTLookUpTableInternalType;

typedef struct MTLookUpTable
{
	/* VAR_INPUT (analog) */
	float NodeVectorX[50];
	float FcnValues[50];
	unsigned char NumberOfNodes;
	enum MTLookUpModeEnum Mode;
	float InX;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	float Out;
	/* VAR (analog) */
	struct MTLookUpTableInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Update;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
} MTLookUpTable_typ;

typedef struct MTLookUpTable2D
{
	/* VAR_INPUT (analog) */
	float NodeVectorX[20];
	float NodeVectorY[20];
	float FcnValues[20][20];
	unsigned char NumberOfNodesX;
	unsigned char NumberOfNodesY;
	float InX;
	float InY;
	/* VAR_OUTPUT (analog) */
	signed long StatusID;
	float Out;
	/* VAR (analog) */
	struct MTLookUpTable2DInternalType Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Update;
	/* VAR_OUTPUT (digital) */
	plcbit Active;
	plcbit Error;
	plcbit UpdateDone;
} MTLookUpTable2D_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void MTLookUpTable(struct MTLookUpTable* inst);
_BUR_PUBLIC void MTLookUpTable2D(struct MTLookUpTable2D* inst);


#ifdef __cplusplus
};
#endif
#endif /* _MTLOOKUP_ */

