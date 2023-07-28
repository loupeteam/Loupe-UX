(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: LogExport
 * File: LogExport.typ
 * Author: Josh
 * Created: August 14, 2012
 ********************************************************************
 * Data types of library LogExport
 ********************************************************************)

TYPE
	LogView_HMI_typ : 	STRUCT 
		ListBox : HMI_Listbox_typ;
		GoToTopButton : HMI_Button_typ;
		PageUpButton : HMI_Button_typ;
		PageDownButton : HMI_Button_typ;
		UpButton : HMI_Button_typ;
		DownButton : HMI_Button_typ;
		Text : STRING[LIST_BOX_STRING_SIZE];
		FilterString : STRING[80];
		MaxAlarms : UDINT;
		AlarmList : UDINT;
		internal : LogView_HMI_internal_typ;
	END_STRUCT;
	LogView_HMI_internal_typ : 	STRUCT 
		Offset : DINT;
		SelectedAlarmIndex : UDINT;
		SelectedListIndex : UINT;
		oSelectedListIndex : UINT;
		NumberAlarms : UINT;
	END_STRUCT;
	LogView_typ : 	STRUCT 
		IN : LogView_IN_typ;
		OUT : LogView_OUT_typ;
		Internal : LogView_Internal_typ;
	END_STRUCT;
	LogView_IN_typ : 	STRUCT  (*Logger Variables*)
		PAR : LogView_PAR_typ;
		CMD : LogView_CMD_typ;
		CFG : LogView_CFG_typ;
	END_STRUCT;
	LogView_PAR_typ : 	STRUCT  (*Logger Variables*)
		LoggerName : STRING[80];
		Offset : DINT;
	END_STRUCT;
	LogView_CMD_typ : 	STRUCT  (*Logger Variables*)
		GoToTop : BOOL;
	END_STRUCT;
	LogView_CFG_typ : 	STRUCT  (*Logger Variables*)
		MaxLogs : UINT;
	END_STRUCT;
	LogView_OUT_typ : 	STRUCT  (*Logger Variables*)
		STAT : LogView_STAT_typ;
		NumberAlarms : UDINT;
	END_STRUCT;
	LogView_STAT_typ : 	STRUCT  (*Logger Variables*)
		Done : BOOL;
		Busy : BOOL;
		Error : BOOL;
		ErrorID : UINT;
		ErrorString : STRING[80];
	END_STRUCT;
	LogView_Internal_typ : 	STRUCT  (*Logger Variables*)
		GetInfo : AsArLogGetInfo; (*AsARLog: AsArLogGetInfo FUB*)
		GetTopAlarm : LogView_GetAlarm;
		GetBottomAlarm : LogView_GetAlarm;
		Buffer : Buffer_typ;
		OffsetIndex : UDINT;
		LoggerName : STRING[80];
		Ident : UDINT;
	END_STRUCT;
	asarlogREAD : 	STRUCT  (*Header data for log entry*)
		len : UDINT; (*Length of the entire entry*)
		lenBin : UDINT; (*Length fo the binary log data*)
		lenAscii : UDINT; (*Length of the ASCII log data*)
		logLevel : UDINT; (*Log level*)
		errornr : UDINT; (*Error number of the entry*)
		taskName : ARRAY[0..35]OF USINT; (*Task name*)
		errYear : UDINT; (*Year (date of error)*)
		errMonth : UDINT; (*Month (date of error)*)
		errDay : UDINT; (*Day (date of error)*)
		errHour : UDINT; (*Hour (date of error)*)
		errMinute : UDINT; (*Minute (date of error)*)
		errSecond : UDINT; (*Second (date of error)*)
		errMilliSec : UDINT; (*millisecond (date of error)*)
		errMicroSec : UDINT; (*microsendond (date of error)*)
	END_STRUCT;
	LogView_GetAlarm : 	STRUCT 
		ReadItem : AsArLogRead; (*AsARLog: AsArLogRead FUB*)
		ReadData : asarlogREAD;
		BinaryData : ARRAY[0..255]OF USINT;
		ASCIIData : ARRAY[0..255]OF USINT;
	END_STRUCT;
	LogData : 	STRUCT 
		String : STRING[LIST_BOX_STRING_SIZE];
		Index : UDINT;
	END_STRUCT;
END_TYPE
