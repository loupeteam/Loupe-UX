/* Automation Studio generated header file */
/* Do not edit ! */
/* fiowrap 0.09.1 */

#ifndef _FIOWRAP_
#define _FIOWRAP_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _fiowrap_VERSION
#define _fiowrap_VERSION 0.09.1
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "StringExt.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "StringExt.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "StringExt.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define FIOWRAP_STRLEN_ERROR 120U
 #define FIOWRAP_NUM_DELETE 10U
 #define FIOWRAP_MAI_DELETE 9U
 #define FIOWRAP_STRLEN_NAME 260U
 #define FIOWRAP_STAT_OK 0U
 #define FIOWRAP_STAT_DISABLED 65534U
#else
 _GLOBAL_CONST unsigned char FIOWRAP_STRLEN_ERROR;
 _GLOBAL_CONST unsigned char FIOWRAP_NUM_DELETE;
 _GLOBAL_CONST unsigned char FIOWRAP_MAI_DELETE;
 _GLOBAL_CONST unsigned short FIOWRAP_STRLEN_NAME;
 _GLOBAL_CONST unsigned short FIOWRAP_STAT_OK;
 _GLOBAL_CONST unsigned short FIOWRAP_STAT_DISABLED;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum FIOWRAP_ERR_enum
{	FIOWRAP_ERR_INVALIDOP = 50000,
	FIOWRAP_ERR_INVALIDFILTER,
	FIOWRAP_ERR_INVALIDDIR,
	FIOWRAP_ERR_MAXFILESIZE
} FIOWRAP_ERR_enum;

typedef enum FIOWRAP_OP_enum
{	FIOWRAP_OP_INVALID = 0,
	FIOWRAP_OP_OPEN,
	FIOWRAP_OP_SAVEAS,
	FIOWRAP_OP_APPEND,
	FIOWRAP_OP_APPEND_NEW,
	FIOWRAP_OP_SCAN,
	FIOWRAP_OP_DELETE,
	FIOWRAP_OP_DELETE_ALL,
	FIOWRAP_OP_ERROR
} FIOWRAP_OP_enum;

typedef enum FIOWRAP_ST_enum
{	FIOWRAP_ST_WAIT = 0,
	FIOWRAP_ST_OPEN,
	FIOWRAP_ST_CREATE,
	FIOWRAP_ST_READ,
	FIOWRAP_ST_WRITE,
	FIOWRAP_ST_CLOSE,
	FIOWRAP_ST_DELETE,
	FIOWRAP_ST_DELETE_FILE,
	FIOWRAP_ST_DELETE_DIR,
	FIOWRAP_ST_RENAME,
	FIOWRAP_ST_ERROR = 999,
	FIOWRAP_ST_
} FIOWRAP_ST_enum;

typedef struct FIOWrap_Int_FUB_typ
{	struct FileOpen Open;
	struct FileCreate Create;
	struct FileRead Read;
	struct FileWrite Write;
	struct FileClose Close;
	struct FileDelete Delete;
	struct FileRename Rename;
	struct DTGetTime GetTime;
} FIOWrap_Int_FUB_typ;

typedef struct FIOWrap_IN_CMD_typ
{	plcbit Open;
	plcbit SaveAs;
	plcbit AppendToFile;
	plcbit Delete;
	plcbit AcknowledgeError;
} FIOWrap_IN_CMD_typ;

typedef struct FIOWrap_Internal_typ
{	unsigned long FileID;
	unsigned long FileLen;
	plcbit FileCreated;
	plcbit ErrorClose;
	signed long CurrOperation;
	signed long State;
	plcstring Timestamp[31];
	plcstring newFileName[261];
	plcstring Name[261];
	plcstring Extension[261];
	struct FIOWrap_Int_FUB_typ FUB;
	struct FIOWrap_IN_CMD_typ CMD;
	struct DTStructure DTStruct;
	plcstring TempStr[261];
} FIOWrap_Internal_typ;

typedef struct FIOWrap_OUT_STAT_typ
{	plcbit Busy;
	plcbit Done;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[121];
	unsigned char ErrorLevel;
	plcbit ReadyForCMD;
	plcbit NewFile;
	unsigned long FileLen;
} FIOWrap_OUT_STAT_typ;

typedef struct FIOWrap_OUT_typ
{	struct FIOWrap_OUT_STAT_typ STAT;
} FIOWrap_OUT_typ;

typedef struct FIOWrap_IN_PAR_typ
{	plcstring FileDevice[261];
	plcstring FileName[261];
	plcstring Suffix[261];
	unsigned long pData;
	unsigned long len;
	unsigned long offset;
	unsigned long MaxFileSize;
	plcbit MultiFile;
} FIOWrap_IN_PAR_typ;

typedef struct FIOWrap_IN_typ
{	struct FIOWrap_IN_CMD_typ CMD;
	struct FIOWrap_IN_PAR_typ PAR;
} FIOWrap_IN_typ;

typedef struct FIOWrap_typ
{	struct FIOWrap_IN_typ IN;
	struct FIOWrap_OUT_typ OUT;
	struct FIOWrap_Internal_typ Internal;
} FIOWrap_typ;

typedef struct FIOManage_Int_FUB_typ
{	struct DirOpen DirOpen;
	struct DirClose DirClose;
	struct DirReadEx DirRead;
	struct DirDeleteEx DeleteDir;
	struct FileDelete Delete;
} FIOManage_Int_FUB_typ;

typedef struct FIOManage_IN_CMD_typ
{	plcbit Scan;
	plcbit DeleteAll;
	plcbit AcknowledgeError;
} FIOManage_IN_CMD_typ;

typedef struct FIOManage_Internal_typ
{	unsigned long DirID;
	unsigned long NumDirs;
	unsigned long NumItems;
	enum FIOWRAP_OP_enum CurrOperation;
	plcbit ErrorClose;
	signed long State;
	unsigned char index;
	plcstring FilterName[261];
	plcstring ItemName[261];
	plcstring FileExtension[261];
	plcstring Name[261];
	plcstring Extension[261];
	signed long NumItemsDelete;
	struct fiDIR_READ_EX_DATA ItemInfo;
	struct fiDIR_READ_EX_DATA ItemInfoCache[10];
	unsigned char NewestIndex;
	unsigned char OldestIndex;
	struct FIOManage_Int_FUB_typ FUB;
	struct FIOManage_IN_CMD_typ CMD;
} FIOManage_Internal_typ;

typedef struct FIOManage_OUT_STAT_typ
{	plcbit Busy;
	plcbit Done;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[121];
	unsigned char ErrorLevel;
	plcbit ReadyForCMD;
} FIOManage_OUT_STAT_typ;

typedef struct FIOManage_OUT_typ
{	struct FIOManage_OUT_STAT_typ STAT;
} FIOManage_OUT_typ;

typedef struct FIOManage_IN_PAR_typ
{	plcstring FileDevice[261];
	plcstring Directory[261];
	plcstring ItemName[261];
	unsigned long MaxNumItems;
	unsigned char Mode;
} FIOManage_IN_PAR_typ;

typedef struct FIOManage_IN_typ
{	struct FIOManage_IN_CMD_typ CMD;
	struct FIOManage_IN_PAR_typ PAR;
} FIOManage_IN_typ;

typedef struct FIOManage_typ
{	struct FIOManage_IN_typ IN;
	struct FIOManage_OUT_typ OUT;
	struct FIOManage_Internal_typ Internal;
} FIOManage_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC plcbit FIOManageFn_Cyclic(struct FIOManage_typ* t);
_BUR_PUBLIC plcbit FIOWrapFn_Cyclic(struct FIOWrap_typ* t);
_BUR_PUBLIC plcbit fiowSetError(unsigned short ErrorID, struct FIOWrap_typ* t);
_BUR_PUBLIC plcbit fiomSetError(unsigned short ErrorID, struct FIOManage_typ* t);
_BUR_PUBLIC unsigned short fioOpenFile_Init(struct FIOWrap_typ* t);


#ifdef __cplusplus
};
#endif
#endif /* _FIOWRAP_ */

