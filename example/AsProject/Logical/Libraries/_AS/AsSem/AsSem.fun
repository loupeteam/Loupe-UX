                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SemCreate				(*create semaphore; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		initCount		: UDINT;		(*initial value*)
		maxCount		: UDINT;		(*maximum value*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*semaphore ident*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SemDelete				(*delete semaphore; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*semaphore ident*)
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

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK SemGetInfo				(*get semaphore info*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*semaphore ident*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: 0xXXXX = see help*)
		maxCount		: UDINT;		(*maximum value*)
		curCount		: UDINT;		(*current value*)
	END_VAR

END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION SemAcquire : UINT				(*acquire semaphore*)
	VAR_INPUT
		ident		:UDINT;				(*semaphore ident*)
	END_VAR
END_FUNCTION

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION SemRelease : UINT				(*release semaphore*)
	VAR_INPUT
		ident		:UDINT;				(*semaphore ident*)
	END_VAR
END_FUNCTION
