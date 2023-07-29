                                                                      
TYPE
	IOAC_I_TYPE : STRUCT			(*internal use*)
		StateMan	: UINT ;
		ErrMan	: UINT ;
		Init	: UDINT ;
		Taskhandle	: UDINT ;
		Semaphore	: UDINT ;
		Requestsize	: UDINT ;
		Answersize	: UDINT ;
		pAccessObj	: UDINT ;
		Offset	: UDINT ;
		flags	: UDINT ;
	END_STRUCT;
END_TYPE
