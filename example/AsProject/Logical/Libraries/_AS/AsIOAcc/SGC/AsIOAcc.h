/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASIOACC_
#define _ASIOACC_
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
 #define ioacERR_ACCESS 30196U
 #define ioacERR_PARAMETER 30195U
 #define ioacERR_NOTSUPPORTED 30194U
 #define ioacERR_TIMEOUT 30193U
 #define ioacERR_CHANNEL 30192U
 #define ioacERR_DEVICE 30191U
 #define ioacERR_INTERNAL 30190U
#else
 _IEC_CONST unsigned short ioacERR_ACCESS = 30196U;
 _IEC_CONST unsigned short ioacERR_PARAMETER = 30195U;
 _IEC_CONST unsigned short ioacERR_NOTSUPPORTED = 30194U;
 _IEC_CONST unsigned short ioacERR_TIMEOUT = 30193U;
 _IEC_CONST unsigned short ioacERR_CHANNEL = 30192U;
 _IEC_CONST unsigned short ioacERR_DEVICE = 30191U;
 _IEC_CONST unsigned short ioacERR_INTERNAL = 30190U;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct IOAC_I_TYPE
{	unsigned short StateMan;
	unsigned short ErrMan;
	unsigned long Init;
	unsigned long Taskhandle;
	unsigned long Semaphore;
	unsigned long Requestsize;
	unsigned long Answersize;
	unsigned long pAccessObj;
	unsigned long Offset;
	unsigned long flags;
} IOAC_I_TYPE;

typedef struct AsIOAccReadReg
{
	/* VAR_INPUT (analog) */
	unsigned char nodeNr;
	unsigned short registerNr;
	unsigned char size;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long value;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} AsIOAccReadReg_typ;

typedef struct AsIOAccWriteReg
{
	/* VAR_INPUT (analog) */
	unsigned char nodeNr;
	unsigned short registerNr;
	unsigned char size;
	unsigned long value;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR (analog) */
	unsigned short i_state;
	unsigned short i_result;
	unsigned long i_tmp;
	/* VAR_INPUT (digital) */
	plcbit enable;
} AsIOAccWriteReg_typ;



/* Prototyping of functions and function blocks */
void AsIOAccReadReg(struct AsIOAccReadReg* inst);
void AsIOAccWriteReg(struct AsIOAccWriteReg* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASIOACC_ */

                                                           
