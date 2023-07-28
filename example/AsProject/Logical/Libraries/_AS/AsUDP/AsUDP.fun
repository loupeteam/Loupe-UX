                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpOpen					(*opens a UDP port; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		pIfAddr			: UDINT;		(*pointer to the IP address of the ethernet interface where the UDP socket should be connected*)
		port			: UINT;			(*port number that the UDP socket should connect to*)
		options			: UDINT;		(*options that can be set during opening, e.g., udpOPT_REUSEADDR*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*identifier used for all other UDP FBKs as an input parameter*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpClose					(*closes a UDP port and frees up all required resources; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
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

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpConnect				(*connects a UDP port to an opposite station; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
		pHost			: UDINT;		(*pointer to the ip address of the receiver*)
		port			: UINT;			(*port number of the receiver*)
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

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpDisconnect			(*connects a UDP port and the opposite station; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
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

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpSend					(*sends udp datagrams; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
		pHost			: UDINT;		(*pointer to the ip address or name of the receiver*)
		port			: UINT;			(*port number of the receiver*)
		pData			: UDINT;		(*pointer to the send datagram*)
		datalen			: UDINT;		(*length of send datagram*)
		flags			: UDINT;		(*send flags*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		sentlen			: UDINT;		(*number of bytes sent*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpRecv					(*receives udp datagrams; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
		pData			: UDINT;		(*pointer to the buffer where to store received datagram*)
		datamax			: UDINT;		(*buffer size (max. length of received datagram)*)
		flags			: UDINT;		(*receive flags*)
		pIpAddr			: UDINT;		(*pointer where to store the ip address of the sender*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		recvlen			: UDINT;		(*lentgh of received datagram*)
		port			: UINT;			(*port number of transmitter*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK UdpIoctl					(*changes or retrieves settings; asynchronous execution*)
	VAR_INPUT
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier returned from UdpOpen*)
		ioctl			: UDINT;		(*io control code*)
		pData			: UDINT;		(*pointer to the input/output data buffer*)
		datalen			: UDINT;		(*lentgh of io control input data*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		outlen			: UDINT;		(*length of the input data or maximum length of the output data*)
	END_VAR

	VAR
        i_state			: UINT;			(*internal variable*)
		i_result		: UINT;			(*internal variable*)
        i_tmp			: UDINT;		(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK
