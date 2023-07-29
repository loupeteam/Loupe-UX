/* Automation Studio generated header file */
/* Do not edit ! */
/* hmitools 0.11.4 */

#ifndef _HMITOOLS_
#define _HMITOOLS_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _hmitools_VERSION
#define _hmitools_VERSION 0.11.4
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
#ifdef _SG3
		#include "AsArLog.h"
		#include "AsBrStr.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "LogThat.h"
		#include "RingBufLib.h"
		#include "StringExt.h"
#endif
#ifdef _SG4
		#include "AsArLog.h"
		#include "AsBrStr.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "LogThat.h"
		#include "RingBufLib.h"
		#include "StringExt.h"
#endif
#ifdef _SGC
		#include "AsArLog.h"
		#include "AsBrStr.h"
		#include "FileIO.h"
		#include "standard.h"
		#include "LogThat.h"
		#include "RingBufLib.h"
		#include "StringExt.h"
#endif


/* Constants */
#ifdef _REPLACE_CONST
 #define ASCII_BACKSLASH 92U
 #define HMI_TREND_MAI_VALUESCALE 3U
 #define HMI_TREND_MAI_SCALECONTAINER 4U
 #define HMI_TREND_MAI_CURVE 15U
 #define HMI_TREND_MAI_CURSOR 1U
 #define HMI_LED_BLINKFAST 3U
 #define HMI_LED_BLINKSLOW 2U
 #define HMI_LED_ON 1U
 #define HMI_LED_OFF 0U
 #define HMI_COMPLETE 1U
 #define HMI_INCOMPLETE 0U
 #define HMI_COLOR_GREEN 10U
 #define HMI_COLOR_YELLOW 46U
 #define HMI_COLOR_RED 4U
 #define HMI_COLOR_GRAY255 255U
 #define HMI_COLOR_GRAY 7U
 #define HMI_COLOR_WHITE 15U
 #define HMI_COLOR_BLACK 0U
 #define HMI_COLOR_FOREGROUND 256U
 #define HMI_INVISIBLE 1
 #define HMI_VISIBLE 0
 #define HMI_LOCKED 1
 #define HMI_UNLOCKED 0
 #define HMI_STRLEN_TIME 9U
 #define HMI_STRLEN_IN 260U
 #define HMI_INVALIDTAB 255U
 #define HMI_MAI_TABS 9U
 #define LIST_BOX_STRING_SIZE 260U
 #define fiEXTENSION 3U
#else
 _GLOBAL_CONST unsigned char ASCII_BACKSLASH;
 _GLOBAL_CONST unsigned char HMI_TREND_MAI_VALUESCALE;
 _GLOBAL_CONST unsigned char HMI_TREND_MAI_SCALECONTAINER;
 _GLOBAL_CONST unsigned char HMI_TREND_MAI_CURVE;
 _GLOBAL_CONST unsigned char HMI_TREND_MAI_CURSOR;
 _GLOBAL_CONST unsigned char HMI_LED_BLINKFAST;
 _GLOBAL_CONST unsigned char HMI_LED_BLINKSLOW;
 _GLOBAL_CONST unsigned char HMI_LED_ON;
 _GLOBAL_CONST unsigned char HMI_LED_OFF;
 _GLOBAL_CONST unsigned short HMI_COMPLETE;
 _GLOBAL_CONST unsigned short HMI_INCOMPLETE;
 _GLOBAL_CONST unsigned short HMI_COLOR_GREEN;
 _GLOBAL_CONST unsigned short HMI_COLOR_YELLOW;
 _GLOBAL_CONST unsigned short HMI_COLOR_RED;
 _GLOBAL_CONST unsigned short HMI_COLOR_GRAY255;
 _GLOBAL_CONST unsigned short HMI_COLOR_GRAY;
 _GLOBAL_CONST unsigned short HMI_COLOR_WHITE;
 _GLOBAL_CONST unsigned short HMI_COLOR_BLACK;
 _GLOBAL_CONST unsigned short HMI_COLOR_FOREGROUND;
 _GLOBAL_CONST plcbit HMI_INVISIBLE;
 _GLOBAL_CONST plcbit HMI_VISIBLE;
 _GLOBAL_CONST plcbit HMI_LOCKED;
 _GLOBAL_CONST plcbit HMI_UNLOCKED;
 _GLOBAL_CONST unsigned char HMI_STRLEN_TIME;
 _GLOBAL_CONST unsigned short HMI_STRLEN_IN;
 _GLOBAL_CONST unsigned char HMI_INVALIDTAB;
 _GLOBAL_CONST unsigned char HMI_MAI_TABS;
 _GLOBAL_CONST unsigned short LIST_BOX_STRING_SIZE;
 _GLOBAL_CONST unsigned char fiEXTENSION;
#endif




/* Datatypes and datatypes of function blocks */
typedef enum HMI_ERR_enum
{	HMI_ERR_OK = 0,
	HMI_ERR_INVALIDINPUT = 50000,
	HMI_ERR_BUSY = 65535
} HMI_ERR_enum;

typedef enum HMI_StatusBits_enum
{	HMI_STATBIT_VIS = 0,
	HMI_STATBIT_LOCK,
	HMI_STATBIT_FOCUS,
	HMI_STATBIT_TOUCHPAD
} HMI_StatusBits_enum;

typedef enum HMI_EditControl_CMDS
{	EC_,
	EC_APPEND,
	EC_CLEAR,
	EC_DELETE,
	EC_GET_LINE,
	EC_GET_MARKED_TEXT,
	EC_GET_TEXT_SIZE,
	EC_GOTO,
	EC_HIGHLIGHT,
	EC_INSERT,
	EC_LOAD,
	EC_READ,
	EC_REPLACE_MARKED_TEXT,
	EC_SAVE,
	EC_UPDATE
} HMI_EditControl_CMDS;

typedef enum RecipeUpdater_STATE
{	RecipeUpdater_ST_IDLE,
	RecipeUpdater_ST_ReadDirectory,
	RecipeUpdater_ST_ReadFile,
	RecipeUpdater_ST_WAIT,
	RecipeUpdater_ST_UpdateFile,
	RecipeUpdater_ST_Done,
	RecipeUpdater_ST_
} RecipeUpdater_STATE;

typedef struct HMI_Layer_typ
{	unsigned short StatusDP;
} HMI_Layer_typ;

typedef struct HMI_Shape_typ
{	unsigned short StatusDP;
	unsigned short ColorDP;
} HMI_Shape_typ;

typedef struct HMI_Scale_typ
{	float Value;
	float MinDP;
	float MaxDP;
	float RangeStartDP;
	float RangeEndDP;
	unsigned short RangeColorDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
} HMI_Scale_typ;

typedef struct HMI_Listbox_typ
{	signed long IndexDP;
	unsigned short MinDP;
	unsigned short MaxDP;
	unsigned short OptionDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
	unsigned short CompletionDP;
	unsigned short PageSize;
} HMI_Listbox_typ;

typedef struct HMI_Bitmap_typ
{	unsigned short IndexDP;
	unsigned short StatusDP;
} HMI_Bitmap_typ;

typedef struct HMI_StringIn_typ
{	plcstring String[261];
	unsigned short StatusDP;
	unsigned short ColorDP;
	unsigned short CompletionDP;
} HMI_StringIn_typ;

typedef struct HMI_Dropdown_typ
{	unsigned short IndexDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
} HMI_Dropdown_typ;

typedef struct HMI_TextBox_typ
{	unsigned short IndexDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
} HMI_TextBox_typ;

typedef struct HMI_NumericIn_typ
{	float Value;
	float MinDP;
	float MaxDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
	unsigned short CompletionDP;
} HMI_NumericIn_typ;

typedef struct HMI_NumericOut_typ
{	float Value;
	unsigned short StatusDP;
	unsigned short ColorDP;
} HMI_NumericOut_typ;

typedef struct HMI_ButtonVC3_typ
{	unsigned char CMD;
	unsigned short Lock;
	unsigned short ColorDP;
	unsigned char LEDDP;
} HMI_ButtonVC3_typ;

typedef struct HMI_Button_typ
{	plcbit CMD;
	plcbit Confirm;
	unsigned short StatusDP;
	unsigned short IndexDP;
	unsigned short ColorDP;
	unsigned char LEDDP;
} HMI_Button_typ;

typedef struct HMI_SecondaryTab_typ
{	plcbit ChangeToSecondaryTab;
	unsigned short PageIndex;
} HMI_SecondaryTab_typ;

typedef struct HMI_PrimaryTab_typ
{	unsigned short CurrentSecondaryTab;
	plcbit ChangeToPrimaryTab;
	unsigned short Group;
	struct HMI_SecondaryTab_typ SecondaryTabArray[10];
} HMI_PrimaryTab_typ;

typedef struct HMI_Tabs_typ
{	unsigned short CurrentPrimaryTab;
	struct HMI_PrimaryTab_typ PrimaryTabArray[10];
} HMI_Tabs_typ;

typedef struct HMI_Basic_typ
{	unsigned short PageChangeDP;
	unsigned short PageCurrentDP;
	unsigned short LanguageChangeDP;
	unsigned short LanguageCurrentDP;
	unsigned short ScreensaverDP;
	unsigned short ScreensaverTimeDP;
	unsigned short BacklightDP;
	unsigned short BacklightTimeDP;
	unsigned short CalibrationStateDP;
	unsigned long VCHandle;
	struct HMI_Tabs_typ Tabs;
} HMI_Basic_typ;

typedef struct ListBoxFub
{
	/* VAR_INPUT (analog) */
	unsigned long Selection;
	unsigned long SelectionList;
	signed long IndexDP;
	unsigned short MinDP;
	unsigned short MaxDP;
	unsigned short OptionDP;
	unsigned short StatusDP;
	unsigned short ColorDP;
	unsigned short PageSize;
	/* VAR (analog) */
	plcstring (*Files)[1][261];
	signed long intIndex;
	plcstring (*pValue);
	plcstring oValue[261];
	/* VAR_INPUT (digital) */
	plcbit Enable;
	/* VAR_OUTPUT (digital) */
	plcbit CompletionDP;
} ListBoxFub_typ;

typedef struct DirectoryFub
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	unsigned long pPath;
	unsigned long MaxValues;
	plcstring NameFilter[261];
	unsigned long FileList;
	plcstring FileExt[261];
	/* VAR_OUTPUT (analog) */
	unsigned short NumFiles;
	unsigned short status;
	/* VAR (analog) */
	struct DirOpen DirectoryOpen;
	struct DirReadEx DirectoryRead;
	struct DirClose DirectoryClose;
	unsigned long Ident;
	unsigned char State;
	unsigned short ListFileIndex;
	unsigned short index;
	plcstring (*Files)[1][261];
	struct fiDIR_READ_EX_DATA DirData;
	plcstring TempString[261];
	plcstring TempExtension[261];
	plcstring lcTempString[261];
	plcstring lcNameFilter[261];
	plcstring iNameFilter[261];
	struct TON UpdateTimer;
	unsigned short i;
	unsigned char IsolatedChar;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Refresh;
	plcbit EnableDirectorySearch;
	plcbit ShowHiddenFiles;
	/* VAR_OUTPUT (digital) */
	plcbit Updating;
	plcbit Initialized;
} DirectoryFub_typ;

typedef struct HMI_File_Browse_internal_typ
{	unsigned long TempFileList;
	plcstring TempFileSelection[261];
	signed long oldFileIndex;
	plcstring oldFileSelection[261];
	plcstring NameFilter[261];
	unsigned short PathStrSize;
	plcstring InternalBrowsingPath[261];
	unsigned short i;
	unsigned char IsolatedChar;
	struct ListBoxFub FileNameSelector;
	struct ListBoxFub FileExtensionSelector;
	struct DirectoryFub Directory;
	struct TON TON_0;
} HMI_File_Browse_internal_typ;

typedef struct LogView_HMI_internal_typ
{	signed long Offset;
	unsigned long SelectedAlarmIndex;
	unsigned short SelectedListIndex;
	unsigned short oSelectedListIndex;
	unsigned short NumberAlarms;
} LogView_HMI_internal_typ;

typedef struct LogView_HMI_typ
{	struct HMI_Listbox_typ ListBox;
	struct HMI_Button_typ GoToTopButton;
	struct HMI_Button_typ PageUpButton;
	struct HMI_Button_typ PageDownButton;
	struct HMI_Button_typ UpButton;
	struct HMI_Button_typ DownButton;
	plcstring Text[261];
	plcstring FilterString[81];
	unsigned long MaxAlarms;
	unsigned long AlarmList;
	struct LogView_HMI_internal_typ internal;
} LogView_HMI_typ;

typedef struct LogView_PAR_typ
{	plcstring LoggerName[81];
	signed long Offset;
} LogView_PAR_typ;

typedef struct LogView_CMD_typ
{	plcbit GoToTop;
} LogView_CMD_typ;

typedef struct LogView_CFG_typ
{	unsigned short MaxLogs;
} LogView_CFG_typ;

typedef struct LogView_IN_typ
{	struct LogView_PAR_typ PAR;
	struct LogView_CMD_typ CMD;
	struct LogView_CFG_typ CFG;
} LogView_IN_typ;

typedef struct LogView_STAT_typ
{	plcbit Done;
	plcbit Busy;
	plcbit Error;
	unsigned short ErrorID;
	plcstring ErrorString[81];
} LogView_STAT_typ;

typedef struct LogView_OUT_typ
{	struct LogView_STAT_typ STAT;
	unsigned long NumberAlarms;
} LogView_OUT_typ;

typedef struct asarlogREAD
{	unsigned long len;
	unsigned long lenBin;
	unsigned long lenAscii;
	unsigned long logLevel;
	unsigned long errornr;
	unsigned char taskName[36];
	unsigned long errYear;
	unsigned long errMonth;
	unsigned long errDay;
	unsigned long errHour;
	unsigned long errMinute;
	unsigned long errSecond;
	unsigned long errMilliSec;
	unsigned long errMicroSec;
} asarlogREAD;

typedef struct LogView_GetAlarm
{	struct AsArLogRead ReadItem;
	struct asarlogREAD ReadData;
	unsigned char BinaryData[256];
	unsigned char ASCIIData[256];
} LogView_GetAlarm;

typedef struct LogView_Internal_typ
{	struct AsArLogGetInfo GetInfo;
	struct LogView_GetAlarm GetTopAlarm;
	struct LogView_GetAlarm GetBottomAlarm;
	struct Buffer_typ Buffer;
	unsigned long OffsetIndex;
	plcstring LoggerName[81];
	unsigned long Ident;
} LogView_Internal_typ;

typedef struct LogView_typ
{	struct LogView_IN_typ IN;
	struct LogView_OUT_typ OUT;
	struct LogView_Internal_typ Internal;
} LogView_typ;

typedef struct LogData
{	plcstring String[261];
	unsigned long Index;
} LogData;

typedef struct HMI_Editor_Controller_CMD_typ
{	plcbit Load;
	plcbit Save;
	plcbit Clear;
} HMI_Editor_Controller_CMD_typ;

typedef struct HMI_EditControl_Value_typ
{	plcstring Content[1001];
	plcstring URLDp[81];
} HMI_EditControl_Value_typ;

typedef struct HMI_EditControl_Runtime_Cmds_typ
{	plcstring ResponseDp[81];
	plcstring RequestDp[81];
	unsigned short StatusDP;
} HMI_EditControl_Runtime_Cmds_typ;

typedef struct HMI_EditControl_Runtime_Comp_typ
{	unsigned short CompletionDP;
} HMI_EditControl_Runtime_Comp_typ;

typedef struct HMI_EditControl_Runtime_Edit_typ
{	unsigned short CursorLineDp;
	unsigned short CursorColumnDp;
	unsigned short InsertModeDp;
	unsigned short ModifiedDp;
	unsigned short SelectionModeDp;
} HMI_EditControl_Runtime_Edit_typ;

typedef struct HMI_EditControl_Runtime_typ
{	unsigned short StatusDp;
	unsigned short BusyDp;
	struct HMI_EditControl_Runtime_Cmds_typ Commands;
	struct HMI_EditControl_Runtime_Comp_typ Completion;
	struct HMI_EditControl_Runtime_Edit_typ Edit;
} HMI_EditControl_Runtime_typ;

typedef struct HMI_EditControl_Internal_typ
{	plcstring CurrentLineText[201];
	unsigned short CurrentLineIndex;
	unsigned char CommandState;
	plcstring EditText[81];
	unsigned char DesiredLine;
	unsigned char DesiredColumn;
	unsigned char Offset;
	unsigned char Count;
	unsigned char highlightmode;
} HMI_EditControl_Internal_typ;

typedef struct HMI_EditControl_typ
{	struct HMI_EditControl_Value_typ Value;
	struct HMI_EditControl_Runtime_typ Runtime;
	struct HMI_EditControl_Internal_typ internal;
	enum HMI_EditControl_CMDS Command;
} HMI_EditControl_typ;

typedef struct HMI_Editor_Controller_int_typ
{	struct HMI_Editor_Controller_CMD_typ CMD;
} HMI_Editor_Controller_int_typ;

typedef struct HMI_Editor_Controller_typ
{	struct HMI_Editor_Controller_CMD_typ CMD;
	struct HMI_EditControl_typ HMI;
	struct HMI_Editor_Controller_int_typ Internal;
} HMI_Editor_Controller_typ;

typedef struct Trend_ZoomScroll
{
	/* VAR_INPUT (analog) */
	float ZoomBase;
	float ScrollBase;
	/* VAR_OUTPUT (analog) */
	float ZoomDP;
	float ScrollDP;
	unsigned short ModeDP;
	/* VAR (analog) */
	float Midpt;
	/* VAR_INPUT (digital) */
	plcbit ZoomIn;
	plcbit ZoomOut;
	plcbit ScrollPos;
	plcbit ScrollNeg;
	plcbit Reset;
	/* VAR (digital) */
	plcbit Init;
} Trend_ZoomScroll_typ;

typedef struct HMI_TrendValueScale_typ
{	unsigned short ColorDP;
	float ScrollManual;
	float ZoomManual;
	struct Trend_ZoomScroll ZoomScroll;
	unsigned short StatusDP;
} HMI_TrendValueScale_typ;

typedef struct HMI_TrendTimeContainer_typ
{	unsigned short ColorDP;
	float CursorTimeDP[2];
	float ZoomManual;
	float ScrollManual;
	unsigned short ModeManual;
	struct Trend_ZoomScroll ZoomScroll;
	unsigned short StatusDP;
} HMI_TrendTimeContainer_typ;

typedef struct HMI_TrendScaleContainer_typ
{	unsigned short ColorDP;
	unsigned short StatusDP;
} HMI_TrendScaleContainer_typ;

typedef struct HMI_TrendCurve_typ
{	unsigned short ColorDP;
	float CursorValueDP[2];
	unsigned short StatusDP;
} HMI_TrendCurve_typ;

typedef struct HMI_TrendGrid_typ
{	unsigned short ColorDP;
	unsigned short StatusDP;
} HMI_TrendGrid_typ;

typedef struct HMI_Trend_typ
{	unsigned short ColorDP;
	unsigned short SelectItemDP;
	unsigned short StatusDP;
	float CursorPositionDP[2];
	unsigned short CursorStatusDP[2];
	struct HMI_TrendGrid_typ Grid;
	struct HMI_TrendCurve_typ Curve[16];
	struct HMI_TrendScaleContainer_typ ScaleContainer[5];
	struct HMI_TrendTimeContainer_typ TimeContainer;
	struct HMI_TrendValueScale_typ ValueScale[4];
	float GlobalXZoomManual;
	float GlobalXScrollManual;
	unsigned short GlobalXScrollModeManual;
	struct Trend_ZoomScroll GlobalXZoomScroll;
	float GlobalYScrollManual;
	float GlobalYZoomManual;
	struct Trend_ZoomScroll GlobalYZoomScroll;
} HMI_Trend_typ;

typedef struct RecMgr_HMI_typ
{	struct HMI_Button_typ RetrieveFromSystem;
	struct HMI_Button_typ ApplyToSystem;
	struct HMI_Bitmap_typ Modified;
} RecMgr_HMI_typ;

typedef struct RecMgr_IN_typ
{	unsigned long pHMIRecipe;
	unsigned long pSystemRecipe;
	unsigned long RecipeLength;
	plcstring LoggerName[9];
} RecMgr_IN_typ;

typedef struct RecipeMgr_typ
{	struct RecMgr_IN_typ IN;
	struct RecMgr_HMI_typ HMI;
} RecipeMgr_typ;

typedef struct RecipeUpdater_Internal_typ
{	enum RecipeUpdater_STATE State;
	struct DirRead DirRead;
	struct fiDIR_READ_DATA CurrentFile;
} RecipeUpdater_Internal_typ;

typedef struct HMIFileBrowse
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	unsigned long pDirectorySearchPath;
	unsigned long pFileList;
	unsigned long MaxFiles;
	unsigned long pFileExtList;
	unsigned short MaxExt;
	signed long FileIndex;
	plcstring FileSelection[261];
	signed long FileExtIndex;
	plcstring FileExtSelection[261];
	/* VAR_OUTPUT (analog) */
	plcstring CurrentPath[261];
	unsigned short NumFiles;
	plcstring Status[261];
	/* VAR (analog) */
	struct HMI_File_Browse_internal_typ Internal;
	/* VAR_INPUT (digital) */
	plcbit Enable;
	plcbit Refresh;
	plcbit EnableDirectorySearch;
	plcbit EnableDataObjects;
	plcbit BrowseToDirectory;
	/* VAR_OUTPUT (digital) */
	plcbit CompletionDP;
} HMIFileBrowse_typ;

typedef struct FileQueue
{
	/* VAR_INPUT (analog) */
	plcstring FileDevice[81];
	plcstring Path[321];
	/* VAR_OUTPUT (analog) */
	plcstring FileName[81];
	unsigned long ErrorID;
	/* VAR (analog) */
	struct RecipeUpdater_Internal_typ internal;
	/* VAR_INPUT (digital) */
	plcbit Next;
	plcbit Cancel;
	/* VAR_OUTPUT (digital) */
	plcbit Execute;
	plcbit Done;
	plcbit Busy;
	plcbit Error;
} FileQueue_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void HMIFileBrowse(struct HMIFileBrowse* inst);
_BUR_PUBLIC void ListBoxFub(struct ListBoxFub* inst);
_BUR_PUBLIC void DirectoryFub(struct DirectoryFub* inst);
_BUR_PUBLIC void Trend_ZoomScroll(struct Trend_ZoomScroll* inst);
_BUR_PUBLIC void FileQueue(struct FileQueue* inst);
_BUR_PUBLIC plcbit LogView_init(struct LogView_typ* LogView);
_BUR_PUBLIC plcbit LogView_cyclic(struct LogView_typ* LogView);
_BUR_PUBLIC plcbit LogView_HMI(struct LogView_typ* LogView, struct LogView_HMI_typ* LogViewHMI);
_BUR_PUBLIC plcbit Editor_fn(struct HMI_Editor_Controller_typ* EditorController);
_BUR_PUBLIC plcbit TrendFn(struct HMI_Trend_typ* t);
_BUR_PUBLIC plcbit HMI_TabControlFn_Cyclic(struct HMI_Basic_typ* t);
_BUR_PUBLIC plcbit HMI_Hide(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_Show(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_Lock(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_Unlock(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_SetFocus(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_ResetFocus(unsigned short* StatusDP);
_BUR_PUBLIC plcbit HMI_OpenTouchpad(unsigned short* StatusDP);
_BUR_PUBLIC plcbit EditorControl(struct HMI_EditControl_typ* Editor);
_BUR_PUBLIC unsigned short ControlTouch(unsigned short* StatusDP);
_BUR_PUBLIC plcbit ControlDismiss(unsigned short* StatusDP);
_BUR_PUBLIC unsigned long LogViewerGetAlarmString(struct LogView_GetAlarm* t, unsigned long AlarmIndex, unsigned long LoggerIdent, plcstring* OutputString);
_BUR_PUBLIC plcbit LogViewerCreateString(struct asarlogREAD* ReadData, unsigned char ASCIIData[256], plcstring* OutputString);
_BUR_PUBLIC unsigned long EditControl_CS_replaceline(plcstring* Text, unsigned short Line, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_append(plcstring* Text, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_getline(unsigned short Line, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_goto(unsigned short Line, unsigned short Col, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_highlight(unsigned short Value, unsigned short Mode, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_insert(plcstring* Text, unsigned short Line, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_read(unsigned short Offset, unsigned short Count, plcstring* Output);
_BUR_PUBLIC unsigned long EditControl_CS_replacemarked(plcstring* Text, plcstring* Output);
_BUR_PUBLIC plcbit HMI_FindCurrentTab(struct HMI_Basic_typ* t);
_BUR_PUBLIC signed long FindIndexOfString(plcstring* Value, unsigned long List, unsigned long MaxList);
_BUR_PUBLIC signed long RecipeMgr(struct RecipeMgr_typ* Rec);
_BUR_PUBLIC unsigned short GetDataObjectList(unsigned long List, unsigned long MaxObjects);


__asm__(".section \".plc\"");

/* Additional IEC dependencies */
__asm__(".ascii \"iecdep \\\"Logical/Libraries/Loupe/LogThat/Constants.var\\\" scope \\\"global\\\"\\n\"");

__asm__(".previous");

#ifdef __cplusplus
};
#endif
#endif /* _HMITOOLS_ */

