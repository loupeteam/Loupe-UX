(********************************************************************
 * COPYRIGHT -- Automation Resources Group
 ********************************************************************
 * Library: HMITools
 * File: HMI_Trend.typ
 * Author: David Blackburn
 * Created: April 01, 2013
 ********************************************************************
 * Data types of library HMITools
 ********************************************************************)

TYPE
	HMI_TrendValueScale_typ : 	STRUCT 
		ColorDP : UINT;
		ScrollManual : REAL;
		ZoomManual : REAL;
		ZoomScroll : Trend_ZoomScroll;
		StatusDP : UINT;
	END_STRUCT;
	HMI_TrendTimeContainer_typ : 	STRUCT 
		ColorDP : UINT;
		CursorTimeDP : ARRAY[0..HMI_TREND_MAI_CURSOR]OF REAL; (*Time at the current Trend.CursorPositionDP.*)
		ZoomManual : REAL;
		ScrollManual : REAL;
		ModeManual : UINT;
		ZoomScroll : Trend_ZoomScroll;
		StatusDP : UINT;
	END_STRUCT;
	HMI_TrendScaleContainer_typ : 	STRUCT 
		ColorDP : UINT;
		StatusDP : UINT;
	END_STRUCT;
	HMI_TrendCurve_typ : 	STRUCT 
		ColorDP : UINT;
		CursorValueDP : ARRAY[0..HMI_TREND_MAI_CURSOR]OF REAL; (*Value of the current curve data at the current Trend.CursorPositionDP.*)
		StatusDP : UINT;
	END_STRUCT;
	HMI_TrendGrid_typ : 	STRUCT 
		ColorDP : UINT;
		StatusDP : UINT;
	END_STRUCT;
	HMI_Trend_typ : 	STRUCT 
		ColorDP : UINT; (*ColorDP should be mapped to the ColorDatapoint in the Trend object on the page.*)
		SelectItemDP : UINT; (*SelectItemDP should be mapped to the SelectItemDatapoint in the Trend object on the page.*)
		StatusDP : UINT; (*StatusDP should be mapped to the StatusDatapoint in the Trend object on the page.*)
		CursorPositionDP : ARRAY[0..HMI_TREND_MAI_CURSOR]OF REAL; (*CursorPositionDP should be mapped to the Cursor PositionDatapoint in the Trend object in the trend editor.
This is used to set the current position of the cursor, as a percentage within full range.*)
		CursorStatusDP : ARRAY[0..HMI_TREND_MAI_CURSOR]OF UINT; (*CursorStatusDP should be mapped to the Cursor StatusDatapoint in the Trend object in the trend editor.*)
		Grid : HMI_TrendGrid_typ; (*Grid variables should be mapped to the TrendGrid in the trend editor.*)
		Curve : ARRAY[0..HMI_TREND_MAI_CURVE]OF HMI_TrendCurve_typ; (*Curve variables should be mapped to the TrendCurve objects in the trend editor.*)
		ScaleContainer : ARRAY[0..HMI_TREND_MAI_SCALECONTAINER]OF HMI_TrendScaleContainer_typ; (*ScaleContainer variables should be mapped to the TrendScaleContainer objects in the trend editor.*)
		TimeContainer : HMI_TrendTimeContainer_typ; (*TimeContainer variables should be mapped to the TrendTimeContainer object in the trend editor.*)
		ValueScale : ARRAY[0..HMI_TREND_MAI_VALUESCALE]OF HMI_TrendValueScale_typ; (*ValueScale variables should be mapped to the TrendValueScale objects in the trend editor.*)
		GlobalXZoomManual : REAL; (*Global zoom and scroll datapoints can be mapped to the zoom and scroll datapoints of ALL TrendTimeContainer and TrendValueScale objects in the trend editor.
This allows for one command to affect the ENTIRE trend.
Local zoom and scroll datapoints in the Trend.TimeContainer and Trend.ValueScale structures can be used to perform zooming and scrolling independently for each TrendTimeContainer and TrendValueScale object.
For manual operation, use the manual datapoints. For automatic operation, use the respective ZoomScroll FUB instance.*)
		GlobalXScrollManual : REAL;
		GlobalXScrollModeManual : UINT;
		GlobalXZoomScroll : Trend_ZoomScroll;
		GlobalYScrollManual : REAL;
		GlobalYZoomManual : REAL;
		GlobalYZoomScroll : Trend_ZoomScroll;
	END_STRUCT;
END_TYPE
