                                                                      
TYPE
    PROFILER_DEFINITION : STRUCT		(*profiler definition structure*)
        logGroup		: UDINT;		(*profiling groups*)
        logMode			: UDINT;		(*profiling mode*)
        archMode		: UDINT;		(*archive mode*)
		memTypeDef		: UDINT;		(*memory type for definition module*)
		memTypeDat		: UDINT;		(*memory type for data module*)
        bufferSize		: UDINT;		(*size of log buffer*)
		backupLevel		: UDINT;		(*backup level*)
        addDataSize		: UDINT;		(*max. size of additional data*)
        addOsTskCnt		: UDINT;		(*space for additional os task information*)
        libFctCnt		: UDINT;		(*number of library function names pointed by pLibFunctions*)
        pLibFunctions	: UDINT;		(*pointer to the series of library function names*)
		pArchDevice		: UDINT;		(*pointer to the archive file device name*)
	END_STRUCT;
	
	PROFILER_MODINFO	: STRUCT			(*module info structure*)
		name			: STRING[63];		(*module name*)
		length			: UDINT;			(*module length*)
		cTime			: DATE_AND_TIME;	(*time of creation*)
		mTime			: DATE_AND_TIME;	(*time of last modification*)
	END_STRUCT;
END_TYPE
