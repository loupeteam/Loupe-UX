
TYPE
	InteralLogFubs_typ : 	STRUCT 
		CreateLog : ArEventLogCreate;
		GetIdent : ArEventLogGetIdent;
		WriteLog : ArEventLogWrite;
	END_STRUCT;
	logLogger_Internal_typ : 	STRUCT 
		ID : UINT;
		Allocated : BOOL;
		AllocStatus : UINT;
		CyclicStatus : UINT;
		Ident : ArEventLogIdentType;
		Persistance : USINT;
		creationStatus : DINT;
	END_STRUCT;
	logLogger_typ : 	STRUCT 
		LoggerName : STRING[LOG_STRLEN_LOGGERNAME];
		LoggerSize : UDINT;
		MessageSize : UDINT;
		BufferedEntries : UDINT;
		Error : BOOL;
		ErrorID : UINT;
		Internal : logLogger_Internal_typ;
	END_STRUCT;
	LOG_SEVERITY_enum : 
		( (*Aligns with arEVENTLOG_SEVERITY_ constants*)
		LOG_SEVERITY_SUCCESS, (*severity code success*)
		LOG_SEVERITY_INFO, (*severity code informational*)
		LOG_SEVERITY_WARNING, (*severity code warning*)
		LOG_SEVERITY_ERROR (*severity code error*)
		);
	LOG_PERSISTENCE_enum : 
		( (*Aligns with arEVENTLOG_PERSISTENCE_ constants*)
		LOG_PERSISTENCE_VOLATILE, (*persistence volatile*)
		LOG_PERSISTENCE_REMANENT, (*persistence remanent*)
		LOG_PERSISTENCE_PERSIST (*persistence persistent*)
		);
	LOG_ERR_enum : 
		(
		LOG_ERR_INVALIDINPUT := 58300,
		LOG_ERR_NOTINITIALIZED, (*Deprecated*)
		LOG_ERR_LOGGERSFULL (*Deprecated*)
		);
END_TYPE
