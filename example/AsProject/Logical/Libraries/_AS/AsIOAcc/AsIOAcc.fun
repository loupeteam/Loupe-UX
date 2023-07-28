                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK AsIOAccRead				(*reads noncyclical register (only inputs); asynchronous execution*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		pDeviceName	:UDINT;				(*device name given as a pointer*)
		pChannelName	:UDINT;			(*pointer to the channel name*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		value	:UDINT;					(*value read*)
	END_VAR
	VAR
		intern	:IOAC_I_TYPE;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK AsIOAccWrite				(*writes noncyclical register (ONLY outputs); asynchronous execution*)
	VAR_INPUT
		enable	:BOOL;					(*enables execution*)
		pDeviceName	:UDINT;				(*device name given as a pointer*)
		pChannelName	:UDINT;			(*pointer to the channel name*)
		value	:UDINT;					(*value to be written*)
	END_VAR
	VAR_OUTPUT
		status	:UINT;					(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
	VAR
		intern	:IOAC_I_TYPE;			(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK AsIOAccReadReg			(*reads noncyclical register (SGC only); asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		nodeNr			: USINT;		(*node number of x2x module*)
		registerNr		: UINT;			(*register number*)
		size			: USINT;		(*register size*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		value			: UDINT;		(*regsiter value*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK AsIOAccWriteReg			(*writes noncyclical register (SGC only); asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		nodeNr			: USINT;		(*node number of x2x module*)
		registerNr		: UINT;			(*register number*)
		size			: USINT;		(*register size*)
		value			: UDINT;		(*new register value*)
	END_VAR
	
	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
