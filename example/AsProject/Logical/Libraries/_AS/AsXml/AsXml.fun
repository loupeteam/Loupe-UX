                                                                      
{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlCreateMemoryReader	(*creates an xml memory reader*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		pXmlMemory		: UDINT;		(*pointer to the XML data*)
		memorySize		: UDINT;		(*size of the XML data*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*identifier*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlCloseMemoryReader		(*closes the xml memory reader*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlReadNextNode			(*reads the next XML node*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		forceRead		: BOOL;			(*reads next Node even if last node could not be read successfully*)
		skipSubtree		: BOOL;			(*avoids XML nodes in the subtree*)
		pName			: UDINT;		(*pointer to buffer for the XML node name*)
		nameSize		: UDINT;		(*size of the buffer for the XML node name*)
		pValue			: UDINT;		(*pointer to buffer for the XML node value*)
		valueSize		: UDINT;		(*size of the buffer for the XML node value*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		nodeType		: UDINT;		(*type of the XML node*)
		depth			: UDINT;		(*depth of the XML node*)
		isEmpty			: BOOL;			(*empty XML node?*)
		attributeCount	: UDINT;		(*number of attributes*)
		neededNameSize	: UDINT;		(*needed name buffer size*)
		neededValueSize	: UDINT;		(*needed value buffer size*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlReadAttributeNr		(*reads the next attribute of the XML node*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		index			: UDINT;		(*index of the attribute to read*)
		pName			: UDINT;		(*pointer to buffer for the attribute name*)
		nameSize		: UDINT;		(*size of the buffer for the XML attribute name*)
		pValue			: UDINT;		(*pointer to buffer for the attribute value*)
		valueSize		: UDINT;		(*size of the buffer for the XML attribute value*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		neededNameSize	: UDINT;		(*needed name buffer size*)
		neededValueSize	: UDINT;		(*needed value buffer size*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlCreateMemoryWriter	(*creates an xml memory writer*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
		ident			: UDINT;		(*identifier*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlGetMemoryInfo			(*gets the pointer to and the size of the created XML data*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, 0xXXXX = see help*)
		pXmlData		: UDINT;		(*pointer to the created XML data*)
		xmlDataSize		: UDINT;		(*size of the created XML data*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlCloseMemoryWriter		(*closes the xml memory writer and releases the allocated memory*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteStartDocument	(*writes the version and the encoding of the document*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pVersion		: UDINT;		(*pointer to the version*)
		pEncoding		: UDINT;		(*pointer to the encoding*)
		pStandalone		: UDINT;		(*pointer to the standalone text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteStartDocEnc		(*writes the version and the encoding of the document and sets the input encoding*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pVersion		: UDINT;		(*pointer to the version*)
		pInputEncoding	: UDINT;		(*pointer to the input encoding e.g. "ISO-8859-1"*)
		pOutputEncoding	: UDINT;		(*pointer to the output encoding e.g. "UTF-8"*)
		pStandalone		: UDINT;		(*pointer to the standalone text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteEndDocument		(*finishes the document*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteStartElement		(*starts a new XML element*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pName			: UDINT;		(*pointer to the XML element name*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteAttribute		(*adds an attribute to the current XML element*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pName			: UDINT;		(*pointer to the XML attribute name*)
		pValue			: UDINT;		(*pointer to the XML attribute value*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteElementText		(*writes an XML element text*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pText			: UDINT;		(*pointer to the element text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteElementTextEx	(*writes an XML element text*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pText			: UDINT;		(*pointer to the element text*)
		textLen			: UDINT;		(*length of the element text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteEndElement		(*closes the current XML element*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteComment			(*writes an XML comment*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pText			: UDINT;		(*pointer to the comment text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteCommentEx		(*writes an XML comment*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pText			: UDINT;		(*pointer to the comment text*)
		textLen			: UDINT;		(*length of the comment text*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteCData			(*writes an XML CDATA Section*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pCData			: UDINT;		(*pointer to the CDATA data*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWriteCDataEx			(*writes an XML CDATA Section*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pCData			: UDINT;		(*pointer to the CDATA*)
		cdataLen		: UDINT;		(*length of the CDATA*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK

{REDUND_CONTEXT} {REDUND_UNREPLICABLE}  FUNCTION_BLOCK xmlWritePI				(*writes an XML process instruction*)
	VAR_INPUT							
		enable			: BOOL;			(*enables execution*)
		ident			: UDINT;		(*identifier*)
		pTarget			: UDINT;		(*pointer to the process instruction*)
		pValue			: UDINT;		(*pointer to the pi value*)
	END_VAR

	VAR_OUTPUT
		status			: UINT;			(*execution status: ERR_OK, ERR_FUB_ENABLE_FALSE, ERR_FUB_BUSY, 0xXXXX = see help*)
	END_VAR
END_FUNCTION_BLOCK
