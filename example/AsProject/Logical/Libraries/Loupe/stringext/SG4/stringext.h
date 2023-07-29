/* Automation Studio generated header file */
/* Do not edit ! */
/* stringext 0.14.4 */

#ifndef _STRINGEXT_
#define _STRINGEXT_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _stringext_VERSION
#define _stringext_VERSION 0.14.4
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "astime.h"
		#include "AsBrWStr.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "astime.h"
		#include "AsBrWStr.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "astime.h"
		#include "AsBrWStr.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define STREXT_INVALID_CHAR 221U
 #define STREXT_MAX_UDINT 4294967295U
#else
 _GLOBAL_CONST unsigned char STREXT_INVALID_CHAR;
 _GLOBAL_CONST unsigned long STREXT_MAX_UDINT;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum STREXT_ERR_enum
{	STREXT_ERR_INVALID_INPUT = -1
} STREXT_ERR_enum;

typedef struct StrExtArgs_typ
{	float r[5];
	unsigned long s[5];
	plcbit b[5];
	signed long i[5];
} StrExtArgs_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned long lstrip(unsigned long pString, unsigned long pChars);
_BUR_PUBLIC unsigned long rstrip(unsigned long pString, unsigned long pChars);
_BUR_PUBLIC unsigned long atoui(unsigned long pString);
_BUR_PUBLIC unsigned long uitoa(unsigned long Value, unsigned long pString);
_BUR_PUBLIC unsigned long ByteToHexString(unsigned long pByte, unsigned long NumBytes, unsigned long pString);
_BUR_PUBLIC signed long HexStringToDINT(unsigned long pHexStr);
_BUR_PUBLIC unsigned short GenerateTimestampMS_1(unsigned long pDTStructure, unsigned long pTimestamp, unsigned long TimestampLength);
_BUR_PUBLIC unsigned short GenerateTimestampMS(unsigned long pDTStructure, unsigned long pTimestamp, unsigned long TimestampLength);
_BUR_PUBLIC unsigned short GenerateTimestamp(plcdt DT1, unsigned long pTimestamp, unsigned long TimestampLength);
_BUR_PUBLIC unsigned short strncat4(unsigned long pDest, unsigned long pSource1, unsigned long pSource2, unsigned long pSource3, unsigned long pSource4, unsigned long MaxLength);
_BUR_PUBLIC unsigned long ToUpper(unsigned long pString);
_BUR_PUBLIC unsigned long ToLower(unsigned long pString);
_BUR_PUBLIC plcdt Timestamp_TO_DT(unsigned long pDT, unsigned long pTimestamp);
_BUR_PUBLIC unsigned long appendArrayIndex(unsigned long Value, unsigned long pString);
_BUR_PUBLIC unsigned long SplitFileName(unsigned long pFileName, unsigned long pName, unsigned long pExtension);
_BUR_PUBLIC unsigned long stringlcpy(unsigned long pDest, unsigned long pSrc, unsigned long dSize);
_BUR_PUBLIC unsigned long stringlcat(unsigned long pDest, unsigned long pSrc, unsigned long dSize);
_BUR_PUBLIC unsigned long string2wstring(unsigned long pDest, unsigned long pSrc, unsigned long dSize);
_BUR_PUBLIC unsigned long wstring2string(unsigned long pDest, unsigned long pSrc, unsigned long dSize);
_BUR_PUBLIC unsigned short char2wchar(unsigned char character);
_BUR_PUBLIC unsigned char wchar2char(unsigned short wcharacter);
_BUR_PUBLIC signed long formatString(plcstring* dest, unsigned long destSize, plcstring* format, struct StrExtArgs_typ* pArgs);
_BUR_PUBLIC unsigned long stringfTime(unsigned long dest, unsigned long destSize, unsigned long format, plcdt time);
_BUR_PUBLIC plcdt stringpTime(unsigned long src, unsigned long format);


#ifdef __cplusplus
};
#endif
#endif /* _STRINGEXT_ */

