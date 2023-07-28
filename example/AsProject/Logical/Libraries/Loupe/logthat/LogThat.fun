(*!!!PRE-RELEASE!!!*)
(*Proposed API*)

FUNCTION_BLOCK logDelete
	VAR_INPUT
		name : STRING[LOG_STRLEN_LOGGERNAME]; (*Name of logger to be deleted*)
		execute : BOOL; (*Start deleting*)
	END_VAR
	VAR_OUTPUT
		done : BOOL; (*Done*)
		busy : BOOL; (*Busy*)
		error : BOOL; (*Error has occured*)
		errorID : DINT; (*Error ID*)
	END_VAR
	VAR
		ident : ArEventLogGetIdent;
		deletion : ArEventLogDelete;
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} FUNCTION createLogInit : DINT (*Only supported in INIT*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Name of the logbook to be created*)
		size : UDINT; (*Length of the log data area in bytes (min 4096)*)
		persistence : LOG_PERSISTENCE_enum; (*Persistence of logbook*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} FUNCTION logEventID : DINT (*Write an event message to the logger*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Pointer to string containing name of logger for message to be added*)
		eventID : DINT; (*Event ID containing severity, facility, and code*)
		eventString : STRING[LOG_STRLEN_MESSAGE]; (*Event message*)
		pMsgData : UDINT; (*Pointer to format arguments*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} FUNCTION logSuccess : DINT (*Write a success message to the logger*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Pointer to string containing name of logger for message to be added*)
		errorID : UINT; (*Code for logger entry*)
		errorString : STRING[LOG_STRLEN_MESSAGE]; (*Message for logger entry*)
		pMsgData : UDINT; (*Pointer to format arguments*)
	END_VAR
END_FUNCTION
(*Legacy*)

{REDUND_CONTEXT} FUNCTION logWarning : DINT (*Write a warning message to the logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Pointer to string containing name of logger for message to be added*)
		errorID : UINT; (*Code for logger entry*)
		errorString : STRING[LOG_STRLEN_MESSAGE]; (*Message for logger entry*)
		pMsgData : UDINT; (*Pointer to format arguments*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} FUNCTION logError : DINT (*Write a fatal error message to the logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Pointer to string containing name of logger for message to be added*)
		errorID : UINT; (*Code for logger entry*)
		errorString : STRING[LOG_STRLEN_MESSAGE]; (*Message for logger entry*)
		pMsgData : UDINT; (*Pointer to format arguments*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} FUNCTION logInfo : DINT (*Write an info message to the logger*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		loggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Pointer to string containing name of logger for message to be added*)
		errorID : UINT; (*Code for logger entry*)
		errorString : STRING[LOG_STRLEN_MESSAGE]; (*Message for logger entry*)
		pMsgData : UDINT; (*Pointer to format arguments*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} FUNCTION_BLOCK logStateChange (*pass in state value and logger name. *) (*$GROUP=User*)
	VAR_INPUT
		LoggerName : STRING[LOG_STRLEN_LOGGERNAME]; (*Name of logger for messages to be added*)
		ModuleName : STRING[LOG_STRLEN_MODULENAME]; (*Name of module with state changes*)
		State : UDINT; (*Current state*)
		StateName : STRING[LOG_STRLEN_STATENAME]; (*State name or description*)
	END_VAR
	VAR
		oldState : UDINT;
		oldStateName : STRING[LOG_STRLEN_STATENAME];
		Status : UINT;
		initialized : BOOL;
	END_VAR
END_FUNCTION_BLOCK
