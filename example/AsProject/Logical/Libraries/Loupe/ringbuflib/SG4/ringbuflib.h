/* Automation Studio generated header file */
/* Do not edit ! */
/* ringbuflib 0.02.4 */

#ifndef _RINGBUFLIB_
#define _RINGBUFLIB_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _ringbuflib_VERSION
#define _ringbuflib_VERSION 0.02.4
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
#endif


/* Datatypes and datatypes of function blocks */
typedef enum RING_BUF_ERR
{	RING_BUF_ERR_INVALID_BUFFER,
	RING_BUF_ERR_INVALID_BUF_POINTER,
	RING_BUF_ERR_DATA_NOT_INIT,
	RING_BUF_ERR_MAX_VALUES_ZERO,
	RING_BUF_ERR_INDEX_OUTSIDE_RANGE,
	RING_BUF_ERR_NUM_ENTRIES_ZERO,
	RING_BUF_ERR_DEST_INVALID,
	RING_BUF_ERR_
} RING_BUF_ERR;

typedef struct Buffer_typ
{	unsigned long Data;
	unsigned long DataSize;
	signed short TopIndex;
	unsigned short MaxValues;
	unsigned short NumberValues;
} Buffer_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short BufferCopyItems(unsigned long Buffer, unsigned short Offset, unsigned short NumEntries, unsigned long Destination, unsigned long Status);
_BUR_PUBLIC unsigned long BufferGetItemAdr(unsigned long Buffer, unsigned short Offset, unsigned long Status);
_BUR_PUBLIC unsigned short BufferAddToBottom(unsigned long Buffer, unsigned long Data);
_BUR_PUBLIC unsigned short BufferAddToTop(unsigned long Buffer, unsigned long Data);
_BUR_PUBLIC unsigned short BufferRemoveBottom(unsigned long Buffer);
_BUR_PUBLIC unsigned short BufferRemoveTop(unsigned long Buffer);
_BUR_PUBLIC unsigned short BufferRemoveOffset(unsigned long Buffer, unsigned short Offset, unsigned long Status);
_BUR_PUBLIC unsigned short BufferBottom(unsigned long Buffer);
_BUR_PUBLIC unsigned short BufferInit(unsigned long Buffer, unsigned short MaxValues, unsigned long DataSize);
_BUR_PUBLIC unsigned short BufferDestroy(unsigned long Buffer);
_BUR_PUBLIC unsigned short BufferClear(unsigned long Buffer);
_BUR_PUBLIC plcbit BufferFull(unsigned long Buffer);
_BUR_PUBLIC plcbit BufferValid(unsigned long Buffer);
_BUR_PUBLIC unsigned short BufferStatus(unsigned long Buffer);
_BUR_PUBLIC unsigned short GetTopIndex(unsigned long Buffer);
_BUR_PUBLIC unsigned short GetBottomIndex(unsigned long Buffer);
_BUR_PUBLIC unsigned long GetNextBottomIndex(unsigned long Buffer);
_BUR_PUBLIC plcbit SetStatusPointer(unsigned long pStatus, unsigned short Status);
_BUR_PUBLIC unsigned long GetNextTopIndex(unsigned long Buffer);


#ifdef __cplusplus
};
#endif
#endif /* _RINGBUFLIB_ */

