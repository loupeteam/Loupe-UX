/* Automation Studio generated header file */
/* Do not edit ! */
/* csvfilelib 1.02.2 */

#ifndef _CSVFILELIB_
#define _CSVFILELIB_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _csvfilelib_VERSION
#define _csvfilelib_VERSION 1.02.2
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "fiowrap.h"
		#include "stringext.h"
		#include "hmitools.h"
		#include "logthat.h"
#endif
#ifdef _SG4
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "fiowrap.h"
		#include "stringext.h"
		#include "hmitools.h"
		#include "logthat.h"
#endif
#ifdef _SGC
		#include "AsBrStr.h"
		#include "astime.h"
		#include "FileIO.h"
		#include "runtime.h"
		#include "standard.h"
		#include "sys_lib.h"
		#include "fiowrap.h"
		#include "stringext.h"
		#include "hmitools.h"
		#include "logthat.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define CSV_MAX_LREAL 1.79769313486232e+308
 #define CSV_MIN_LREAL (-1.79769313486232e+308)
 #define CSV_MAX_REAL 3.4e+38f
 #define CSV_MIN_REAL (-3.4e+38f)
 #define CSV_MAX_UDINT 4294967295U
 #define CSV_MIN_UDINT 0U
 #define CSV_MAX_UINT 65535
 #define CSV_MIN_UINT 0
 #define CSV_MAX_USINT 255
 #define CSV_MIN_USINT 0
 #define CSV_MAX_DINT 2147483647
 #define CSV_MIN_DINT (-2147483647)
 #define CSV_MAX_INT 32767
 #define CSV_MIN_INT (-32768)
 #define CSV_MAX_SINT 127
 #define CSV_MIN_SINT (-128)
 #define CSV_DEFAULT_SIGFIGS 16U
 #define CSV_DEFAULT_LOGGERNAME "Files"
 #define CSV_DEFAULT_MAXLINESPERSCAN 500U
 #define CSV_DEFAULT_MAXLINELENGTH 500U
 #define CSV_DEFAULT_MAXFILESIZE 65536U
 #define CSV_STRLEN_HEADER 364U
 #define CSV_STRLEN_INFOSTRING 200U
 #define CSV_STRLEN_FILELIST 50U
 #define CSV_STRLEN_VARDESCRIPTION 120U
 #define CSV_STRLEN_VARVALUE 500U
 #define CSV_STRLEN_VARNAME 120U
 #define CSV_STRLEN_ERROR 99U
 #define CSV_STRLEN_TIMESTAMP 16U
 #define CSV_STRLEN_MINSPACING 4U
 #define CSV_STRLEN_FILENAMEDISPLAY 30U
 #define CSV_STRLEN_FILEDEVICE 260U
 #define CSV_STRLEN_TEMPFILENAME 263U
 #define CSV_STRLEN_FILENAME 260U
 #define CSV_MAI_FILELIST 299U
 #define CSV_MAI_VARLIST 99U
 #define CSV_MAI_LEVEL 29U
 #define CSV_PADDINGCHARS " \t\r\n\f\""
#else
 _GLOBAL_CONST double CSV_MAX_LREAL;
 _GLOBAL_CONST double CSV_MIN_LREAL;
 _GLOBAL_CONST float CSV_MAX_REAL;
 _GLOBAL_CONST float CSV_MIN_REAL;
 _GLOBAL_CONST unsigned long CSV_MAX_UDINT;
 _GLOBAL_CONST unsigned long CSV_MIN_UDINT;
 _GLOBAL_CONST signed long CSV_MAX_UINT;
 _GLOBAL_CONST signed long CSV_MIN_UINT;
 _GLOBAL_CONST signed long CSV_MAX_USINT;
 _GLOBAL_CONST signed long CSV_MIN_USINT;
 _GLOBAL_CONST signed long CSV_MAX_DINT;
 _GLOBAL_CONST signed long CSV_MIN_DINT;
 _GLOBAL_CONST signed long CSV_MAX_INT;
 _GLOBAL_CONST signed long CSV_MIN_INT;
 _GLOBAL_CONST signed long CSV_MAX_SINT;
 _GLOBAL_CONST signed long CSV_MIN_SINT;
 _GLOBAL_CONST unsigned char CSV_DEFAULT_SIGFIGS;
 _GLOBAL_CONST plcstring CSV_DEFAULT_LOGGERNAME[9];
 _GLOBAL_CONST unsigned long CSV_DEFAULT_MAXLINESPERSCAN;
 _GLOBAL_CONST unsigned long CSV_DEFAULT_MAXLINELENGTH;
 _GLOBAL_CONST unsigned long CSV_DEFAULT_MAXFILESIZE;
 _GLOBAL_CONST unsigned short CSV_STRLEN_HEADER;
 _GLOBAL_CONST unsigned char CSV_STRLEN_INFOSTRING;
 _GLOBAL_CONST unsigned char CSV_STRLEN_FILELIST;
 _GLOBAL_CONST unsigned char CSV_STRLEN_VARDESCRIPTION;
 _GLOBAL_CONST unsigned short CSV_STRLEN_VARVALUE;
 _GLOBAL_CONST unsigned char CSV_STRLEN_VARNAME;
 _GLOBAL_CONST unsigned char CSV_STRLEN_ERROR;
 _GLOBAL_CONST unsigned char CSV_STRLEN_TIMESTAMP;
 _GLOBAL_CONST unsigned char CSV_STRLEN_MINSPACING;
 _GLOBAL_CONST unsigned char CSV_STRLEN_FILENAMEDISPLAY;
 _GLOBAL_CONST unsigned short CSV_STRLEN_FILEDEVICE;
 _GLOBAL_CONST unsigned short CSV_STRLEN_TEMPFILENAME;
 _GLOBAL_CONST unsigned short CSV_STRLEN_FILENAME;
 _GLOBAL_CONST unsigned short CSV_MAI_FILELIST;
 _GLOBAL_CONST unsigned char CSV_MAI_VARLIST;
 _GLOBAL_CONST unsigned char CSV_MAI_LEVEL;
 _GLOBAL_CONST plcstring CSV_PADDINGCHARS[7];
#endif




/* Datatypes and datatypes of function blocks */
typedef enum CSV_ERR_enum
{	CSV_ERR_PVITEM_ENUM = 14713,
	CSV_ERR_INVALIDINPUT = 50000,
	CSV_ERR_MEMCFG,
	CSV_ERR_MEMALLOC,
	CSV_ERR_NOTINITIALIZED,
	CSV_ERR_LINEFAILURE,
	CSV_ERR_BUFFERFULL,
	CSV_ERR_LOGNOTAVAILABLE,
	CSV_ERR_LOGFULL,
	CSV_ERR_INVALIDOPERATION,
	CSV_ERR_COMMENT,
	CSV_ERR_NOVARNAMEFOUND,
	CSV_ERR_NOVALUEFOUND,
	CSV_ERR_INVALIDVALUE,
	CSV_ERR_UNSUPPORTEDTYPE,
	CSV_ERR_INVALIDTYPE,
	CSV_ERR_MAXLEVELREACHED,
	CSV_ERR_PREFIXNOTSTRUCTURE,
	CSV_ERR_EMPTYFILENAME,
	CSV_ERR_BUSY = 65535
} CSV_ERR_enum;

typedef enum CSV_TYPE_enum
{	CSV_TYPE_STRUCT = 0,
	CSV_TYPE_BOOL,
	CSV_TYPE_SINT,
	CSV_TYPE_INT,
	CSV_TYPE_DINT,
	CSV_TYPE_USINT,
	CSV_TYPE_UINT,
	CSV_TYPE_UDINT,
	CSV_TYPE_REAL,
	CSV_TYPE_STRING,
	CSV_TYPE_ULINT,
	CSV_TYPE_DATE_AND_TIME,
	CSV_TYPE_TIME,
	CSV_TYPE_DATE,
	CSV_TYPE_LREAL,
	CSV_TYPE_ARRAY_OF_STRUCT,
	CSV_TYPE_TIME_OF_DAY,
	CSV_TYPE_BYTE,
	CSV_TYPE_WORD,
	CSV_TYPE_DWORD,
	CSV_TYPE_LWORD,
	CSV_TYPE_WSTRING,
	CSV_TYPE_LINT = 23
} CSV_TYPE_enum;

typedef enum CSV_INFO_enum
{	CSV_INFO_NOVARNAMEFOUND,
	CSV_INFO_NOVALUEFOUND,
	CSV_INFO_ADDRESSNOTFOUND,
	CSV_INFO_DATATYPENOTFOUND,
	CSV_INFO_INVALIDVALUE,
	CSV_INFO_UNSUPPORTEDTYPE,
	CSV_INFO_INVALIDTYPE,
	CSV_INFO_INVALIDINPUT,
	CSV_INFO_FILEFULL,
	CSV_INFO_INFONOTFOUND,
	CSV_INFO_MAXLEVELREACHED,
	CSV_INFO_ITEMNOTFOUND,
	CSV_INFO_PREFIXNOTSTRUCTURE,
	CSV_INFO_VERBOSE_VARNAME,
	CSV_INFO_VERBOSE_VALUE,
	CSV_INFO_VERBOSE_DESCRIPTION,
	CSV_INFO_VERBOSE_VARADDRESS,
	CSV_INFO_VERBOSE_VARTYPE,
	CSV_INFO_VERBOSE_VARLENGTH,
	CSV_INFO_VERBOSE_VARDIMENSION,
	CSV_INFO_VERBOSE_COMMENT,
	CSV_INFO_DONE
} CSV_INFO_enum;

typedef enum CSV_FILELIST_ST_enum
{	CSV_FILELIST_ST_IDLE,
	CSV_FILELIST_ST_DIRINFO,
	CSV_FILELIST_ST_DIRREAD,
	CSV_FILELIST_ST_
} CSV_FILELIST_ST_enum;

typedef enum CSV_ST_enum
{	CSV_ST_IDLE = 0,
	CSV_ST_GET_TEMPLATE,
	CSV_ST_EXPANDVARS,
	CSV_ST_OPEN,
	CSV_ST_PROCESS,
	CSV_ST_DELETELOG,
	CSV_ST_SAVELOG,
	CSV_ST_DELETETEMP = 100,
	CSV_ST_SAVETEMP,
	CSV_ST_DELETEORIGINAL,
	CSV_ST_RENAMETEMP,
	CSV_ST_DELETEFILE = 200,
	CSV_ST_ERROR = 999
} CSV_ST_enum;

typedef enum CSV_OP_enum
{	CSV_OP_INVALID = 0,
	CSV_OP_OPEN,
	CSV_OP_SAVE,
	CSV_OP_DELETE
} CSV_OP_enum;

typedef struct CSVFileVariable_typ
{	plcstring Name[121];
	plcstring Value[501];
	plcstring Description[121];
	unsigned long Address;
	unsigned long DataType;
	unsigned long Length;
	unsigned short Dimension;
} CSVFileVariable_typ;

typedef struct CSVFileMgr_StructLevel_typ
{	plcstring Name[121];
	unsigned long DataType;
	unsigned long Length;
	unsigned short Dimension;
	unsigned short iItem;
} CSVFileMgr_StructLevel_typ;

typedef struct CSVFileMgr_StructData_typ
{	signed short iLevel;
	struct CSVFileMgr_StructLevel_typ Level[30];
} CSVFileMgr_StructData_typ;

typedef struct CSVFileMgr_Int_Buffer_typ
{	unsigned long pData;
	unsigned long CurrentLength;
	unsigned long MaxLength;
} CSVFileMgr_Int_Buffer_typ;

typedef struct CSVFileMgr_IN_CMD_typ
{	plcbit OpenFile;
	plcbit UpdateFile;
	plcbit SaveVariableListToFile;
	plcbit DeleteFile;
	plcbit AcknowledgeError;
} CSVFileMgr_IN_CMD_typ;

typedef struct CSVFileMgr_Internal_typ
{	plcbit Initialized;
	signed long CurrOperation;
	unsigned short ProcessStatus;
	unsigned short ExpandStatus;
	plcbit ExpandError;
	struct CSVFileMgr_Int_Buffer_typ ReadBuffer;
	struct CSVFileMgr_Int_Buffer_typ WriteBuffer;
	struct CSVFileMgr_Int_Buffer_typ LogBuffer;
	unsigned long pLine;
	unsigned long LineNumber;
	unsigned long pToken;
	unsigned long pString;
	unsigned long pReentry;
	unsigned long SuccessfulLineCount;
	unsigned long FailedLineCount;
	unsigned long ScanCount;
	struct CSVFileMgr_StructData_typ StructureData;
	unsigned char iVar;
	struct FileRename FileRename;
	struct FIOWrap_typ FIOWrap;
	struct CSVFileMgr_IN_CMD_typ CMD;
	plcstring TempFileName[264];
	struct CSVFileVariable_typ TemplateVariable;
	unsigned long pUserVariable;
	signed long StartState;
} CSVFileMgr_Internal_typ;

typedef struct CSVFileMgr_OUT_STAT_typ
{	plcbit Busy;
	plcbit Done;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[100];
	unsigned char ErrorLevel;
	signed long ErrorState;
	signed long State;
} CSVFileMgr_OUT_STAT_typ;

typedef struct CSVFileMgr_OUT_typ
{	struct CSVFileMgr_OUT_STAT_typ STAT;
} CSVFileMgr_OUT_typ;

typedef struct CSVFileMgr_IN_CFG_typ
{	unsigned long MaxFileSize;
	unsigned long MaxLineLength;
	unsigned long MaxLinesPerScan;
	plcbit VerboseLog;
	plcstring LogFileName[261];
	plcbit DisableLogging;
	plcstring LoggerName[9];
	unsigned char DoubleSigFigs;
} CSVFileMgr_IN_CFG_typ;

typedef struct CSVFileMgr_IN_PAR_typ
{	plcstring FileDevice[261];
	plcstring FileName[261];
	plcstring VariableList[100][121];
	plcstring Prefix[121];
	unsigned long pUserVariable;
} CSVFileMgr_IN_PAR_typ;

typedef struct CSVFileMgr_IN_typ
{	struct CSVFileMgr_IN_CMD_typ CMD;
	struct CSVFileMgr_IN_PAR_typ PAR;
	struct CSVFileMgr_IN_CFG_typ CFG;
} CSVFileMgr_IN_typ;

typedef struct CSVFileMgr_typ
{	struct CSVFileMgr_IN_typ IN;
	struct CSVFileMgr_OUT_typ OUT;
	struct CSVFileMgr_Internal_typ Internal;
} CSVFileMgr_typ;

typedef struct CSVFileMgr_HMI_Internal_typ
{	struct TON_10ms ProgressTimer;
	plcbit HMI_CMD_Active;
	plcbit HMI_CMD_Active_Old;
} CSVFileMgr_HMI_Internal_typ;

typedef struct CSVFileMgr_HMI_TextSnippets_typ
{	plcstring FileName[261];
	plcstring PopupHeader[261];
	plcstring Action[261];
	plcstring ProgressLabel[261];
	unsigned short ErrorID;
	plcstring ErrorString[100];
} CSVFileMgr_HMI_TextSnippets_typ;

typedef struct CSVFileMgr_HMI_ErrorStatus_typ
{	unsigned short StatusDP;
	struct HMI_Button_typ AcknowledgeError;
} CSVFileMgr_HMI_ErrorStatus_typ;

typedef struct CSVFileMgr_HMI_Progress_typ
{	unsigned short StatusDP;
	unsigned long Progress;
} CSVFileMgr_HMI_Progress_typ;

typedef struct CSVFileMgr_HMI_DeleteConfirm_typ
{	unsigned short StatusDP;
	struct HMI_Button_typ Yes;
	struct HMI_Button_typ No;
} CSVFileMgr_HMI_DeleteConfirm_typ;

typedef struct CSVFileMgr_HMI_DialogBox_typ
{	unsigned short StatusDP;
	plcstring FileNameList[300][261];
	struct HMIFileBrowse FileBrowser;
	struct HMI_Button_typ PageUp;
	struct HMI_Button_typ PageDown;
	struct HMI_Button_typ Action;
	struct HMI_Button_typ Cancel;
} CSVFileMgr_HMI_DialogBox_typ;

typedef struct CSVFileMgr_HMI_Main_typ
{	struct HMI_Button_typ OpenFile;
	struct HMI_Button_typ UpdateFile;
	struct HMI_Button_typ SaveVariableListToFile;
	struct HMI_Button_typ DeleteFile;
} CSVFileMgr_HMI_Main_typ;

typedef struct CSVFileMgr_HMI_typ
{	struct CSVFileMgr_HMI_Main_typ Main;
	struct CSVFileMgr_HMI_DialogBox_typ DialogBox;
	struct CSVFileMgr_HMI_DeleteConfirm_typ DeleteConfirm;
	struct CSVFileMgr_HMI_Progress_typ Progress;
	struct CSVFileMgr_HMI_ErrorStatus_typ ErrorStatus;
	struct CSVFileMgr_HMI_TextSnippets_typ TextSnippets;
	struct CSVFileMgr_HMI_Internal_typ Internal;
} CSVFileMgr_HMI_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC unsigned short CSVFn_Init(struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short CSVOpenFile_Init(struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short CSVFn_Cyclic(struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvInitBuffer(unsigned long BufferLength, struct CSVFileMgr_Int_Buffer_typ* pBuffer);
_BUR_PUBLIC unsigned short csvClearBuffer(struct CSVFileMgr_Int_Buffer_typ* pBuffer);
_BUR_PUBLIC unsigned short csvAddToBuffer(unsigned long pData, unsigned long DataLength, struct CSVFileMgr_Int_Buffer_typ* pBuffer);
_BUR_PUBLIC unsigned short csvSetError(unsigned short ErrorID, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvExpandVar(unsigned long pVarName, struct CSVFileMgr_Int_Buffer_typ* pBuffer, struct CSVFileMgr_StructData_typ* pStructData, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvProcessData(struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvAddLogInfo(unsigned short InfoID, unsigned long LineNumber, unsigned long pAddInfo, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvParseLine(unsigned long pLine, unsigned long LineNumber, struct CSVFileVariable_typ* pVariable, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvGetVarInfo(unsigned long LineNumber, struct CSVFileVariable_typ* pVariable, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvOpenVar(unsigned long LineNumber, struct CSVFileVariable_typ* pVariable, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvSaveVar(unsigned long LineNumber, struct CSVFileVariable_typ* pVariable, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvWriteHeader(struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvRemovePrefix(unsigned long MaxLength, plcstring* String, plcstring* Prefix);
_BUR_PUBLIC unsigned short csvAddPrefix(unsigned long MaxLength, plcstring* String, plcstring* Prefix);
_BUR_PUBLIC unsigned short CSVFn_HMI_Cyclic(struct CSVFileMgr_HMI_typ* HMI, struct CSVFileMgr_typ* t);
_BUR_PUBLIC unsigned short csvhmiGenerateFileListString(unsigned long pFileListString, struct fiDIR_READ_DATA* pDirReadData);
_BUR_PUBLIC unsigned long csvDTOA(double value, unsigned long pString, unsigned char numSigFigs);


__asm__(".section \".plc\"");

/* Additional IEC dependencies */
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/logthat/Constants.var\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/hmitools/HMITools.var\\\" scope \\\"global\\\"\\n\"");

__asm__(".previous");

#ifdef __cplusplus
};
#endif
#endif /* _CSVFILELIB_ */

