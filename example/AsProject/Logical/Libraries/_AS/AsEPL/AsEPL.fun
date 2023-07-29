                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK EplSDORead					(*reads node's object entries when using an SDO transfer*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDevice	:REFERENCE TO STRING[80];	(*device name given as a pointer, e.g., "SL<x>.SS<y>.IF<z>"*)
		node	:USINT;						(*address of the node to be read (1-255 or 0 for local OD)*)
		index	:UINT;						(*number of the index entry to be read*)
		subindex	:USINT;					(*number of the subindex entry to be read*)
		pData	:UDINT;						(*pointer to the buffer for read data*)
		datalen	:UDINT;						(*maximum length of the data to be read*)
	END_VAR
	
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		errorinfo	:UDINT;					(*SDO Abort Code, e.g., EPL_ERR_SDO_PROTOCOL_TIMEOUT, EPL_ERR_SDO_COMMAND_ID_INVALID, ..*)
		readlen	:UDINT;						(*length of the entry read*)
	END_VAR
	
	VAR
		intern	:EPL_I_TYPE;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK EplSDOWrite					(*writes a node's object entries when using an SDO transfer*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDevice	:REFERENCE TO STRING[80];	(*device name given as a pointer, e.g., "SL<x>.SS<y>.IF<z>"*)
		node	:USINT;						(*address of the node to be written (1-255 or 0 for local OD)*)
		index	:UINT;						(*number of the index entry to be written*)
		subindex	:USINT;					(*number of the subindex entry to be written*)
		pData	:UDINT;						(*pointer to the data to be written*)
		datalen	:UDINT;						(*length of the data to be written*)
	END_VAR
	
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		errorinfo	:UDINT;					(*SDO abort code, e.g., EPL_ERR_SDO_PROTOCOL_TIMEOUT, EPL_ERR_SDO_COMMAND_ID_INVALID, ..*)
	END_VAR
	
	VAR
		intern	:EPL_I_TYPE;				(*internal variable*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK EplGetLocalNodeID			(*queries the local node address of the PLC*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDevice	:REFERENCE TO STRING[80];	(*device name given as a pointer, e.g., "SL<x>.SS<y>.IF<z>"*)
	END_VAR
	
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		nodeid	:USINT;						(*local node number of the PLC*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK EplCreateObject				(*creates a object at the given index/subindex*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDevice	:REFERENCE TO STRING[80];	(*device name given as a pointer, e.g., "SL<x>.SS<y>.IF<z>"*)
		index	:UINT;						(*index of object*)
		subindex:USINT;						(*subindex of object*)
		datalen	:UDINT;						(*length of the object in octets*)
	END_VAR
	
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE} FUNCTION_BLOCK EplDeleteObject				(*creates a object at the given index/subindex*)
	VAR_INPUT
		enable	:BOOL;						(*enables execution*)
		pDevice	:REFERENCE TO STRING[80];	(*device name given as a pointer, e.g., "SL<x>.SS<y>.IF<z>"*)
		index	:UINT;						(*index of object*)
		subindex:USINT;						(*subindex of object*)
	END_VAR
	
	VAR_OUTPUT
		status	:UINT;						(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

