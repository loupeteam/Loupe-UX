/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _ASXML_
#define _ASXML_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Constants */
#ifdef _REPLACE_CONST
 #define xmlNODE_TYPE_ENDELEMENT 15U
 #define xmlNODE_TYPE_SIGN_WHITESPACE 14U
 #define xmlNODE_TYPE_WHITESPACE 13U
 #define xmlNODE_TYPE_COMMENT 8U
 #define xmlNODE_TYPE_PI 7U
 #define xmlNODE_TYPE_CDATA 4U
 #define xmlNODE_TYPE_TEXT 3U
 #define xmlNODE_TYPE_ELEMENT 1U
 #define xmlERR_DOCUMENT_NOT_OPEN 33825U
 #define xmlERR_UNSUPPORTED_ENCODING 33824U
 #define xmlERR_CONVERT_TEXT 33823U
 #define xmlERR_CONVERT 33822U
 #define xmlERR_INVALID_POSITION 33821U
 #define xmlERR_NO_ELEMENT_OPEN 33820U
 #define xmlERR_INVALID_IDENT 33819U
 #define xmlERR_XML_DATA_INVALID 33818U
 #define xmlERR_NO_ATTRIBUTES 33817U
 #define xmlERR_INVALID_ATTRIBUTE_INDEX 33816U
 #define xmlERR_VALUE_BUFFER_TOO_SMALL 33815U
 #define xmlERR_NAME_BUFFER_TOO_SMALL 33814U
 #define xmlERR_NO_FURTHER_XML_NODE 33813U
 #define xmlERR_GENERAL 33812U
 #define xmlERR_INVALID_PARAMETER 33811U
 #define xmlERR_MEMORY 33810U
#else
 #ifndef _GLOBAL_CONST
   #define _GLOBAL_CONST _WEAK const
 #endif
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_ENDELEMENT;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_SIGN_WHITESPACE;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_WHITESPACE;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_COMMENT;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_PI;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_CDATA;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_TEXT;
 _GLOBAL_CONST unsigned short xmlNODE_TYPE_ELEMENT;
 _GLOBAL_CONST unsigned short xmlERR_DOCUMENT_NOT_OPEN;
 _GLOBAL_CONST unsigned short xmlERR_UNSUPPORTED_ENCODING;
 _GLOBAL_CONST unsigned short xmlERR_CONVERT_TEXT;
 _GLOBAL_CONST unsigned short xmlERR_CONVERT;
 _GLOBAL_CONST unsigned short xmlERR_INVALID_POSITION;
 _GLOBAL_CONST unsigned short xmlERR_NO_ELEMENT_OPEN;
 _GLOBAL_CONST unsigned short xmlERR_INVALID_IDENT;
 _GLOBAL_CONST unsigned short xmlERR_XML_DATA_INVALID;
 _GLOBAL_CONST unsigned short xmlERR_NO_ATTRIBUTES;
 _GLOBAL_CONST unsigned short xmlERR_INVALID_ATTRIBUTE_INDEX;
 _GLOBAL_CONST unsigned short xmlERR_VALUE_BUFFER_TOO_SMALL;
 _GLOBAL_CONST unsigned short xmlERR_NAME_BUFFER_TOO_SMALL;
 _GLOBAL_CONST unsigned short xmlERR_NO_FURTHER_XML_NODE;
 _GLOBAL_CONST unsigned short xmlERR_GENERAL;
 _GLOBAL_CONST unsigned short xmlERR_INVALID_PARAMETER;
 _GLOBAL_CONST unsigned short xmlERR_MEMORY;
#endif




/* Datatypes and datatypes of function blocks */
typedef struct xmlCreateMemoryReader
{
	/* VAR_INPUT (analog) */
	unsigned long pXmlMemory;
	unsigned long memorySize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlCreateMemoryReader_typ;

typedef struct xmlCloseMemoryReader
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlCloseMemoryReader_typ;

typedef struct xmlReadNextNode
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pName;
	unsigned long nameSize;
	unsigned long pValue;
	unsigned long valueSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long nodeType;
	unsigned long depth;
	unsigned long attributeCount;
	unsigned long neededNameSize;
	unsigned long neededValueSize;
	/* VAR_INPUT (digital) */
	plcbit enable;
	plcbit forceRead;
	plcbit skipSubtree;
	/* VAR_OUTPUT (digital) */
	plcbit isEmpty;
} xmlReadNextNode_typ;

typedef struct xmlReadAttributeNr
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long index;
	unsigned long pName;
	unsigned long nameSize;
	unsigned long pValue;
	unsigned long valueSize;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long neededNameSize;
	unsigned long neededValueSize;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlReadAttributeNr_typ;

typedef struct xmlCreateMemoryWriter
{
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long ident;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlCreateMemoryWriter_typ;

typedef struct xmlGetMemoryInfo
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	unsigned long pXmlData;
	unsigned long xmlDataSize;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlGetMemoryInfo_typ;

typedef struct xmlCloseMemoryWriter
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlCloseMemoryWriter_typ;

typedef struct xmlWriteStartDocument
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pVersion;
	unsigned long pEncoding;
	unsigned long pStandalone;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteStartDocument_typ;

typedef struct xmlWriteStartDocEnc
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pVersion;
	unsigned long pInputEncoding;
	unsigned long pOutputEncoding;
	unsigned long pStandalone;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteStartDocEnc_typ;

typedef struct xmlWriteEndDocument
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteEndDocument_typ;

typedef struct xmlWriteStartElement
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pName;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteStartElement_typ;

typedef struct xmlWriteAttribute
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pName;
	unsigned long pValue;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteAttribute_typ;

typedef struct xmlWriteElementText
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pText;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteElementText_typ;

typedef struct xmlWriteElementTextEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pText;
	unsigned long textLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteElementTextEx_typ;

typedef struct xmlWriteEndElement
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteEndElement_typ;

typedef struct xmlWriteComment
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pText;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteComment_typ;

typedef struct xmlWriteCommentEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pText;
	unsigned long textLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteCommentEx_typ;

typedef struct xmlWriteCData
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pCData;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteCData_typ;

typedef struct xmlWriteCDataEx
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pCData;
	unsigned long cdataLen;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWriteCDataEx_typ;

typedef struct xmlWritePI
{
	/* VAR_INPUT (analog) */
	unsigned long ident;
	unsigned long pTarget;
	unsigned long pValue;
	/* VAR_OUTPUT (analog) */
	unsigned short status;
	/* VAR_INPUT (digital) */
	plcbit enable;
} xmlWritePI_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void xmlCreateMemoryReader(struct xmlCreateMemoryReader* inst);
_BUR_PUBLIC void xmlCloseMemoryReader(struct xmlCloseMemoryReader* inst);
_BUR_PUBLIC void xmlReadNextNode(struct xmlReadNextNode* inst);
_BUR_PUBLIC void xmlReadAttributeNr(struct xmlReadAttributeNr* inst);
_BUR_PUBLIC void xmlCreateMemoryWriter(struct xmlCreateMemoryWriter* inst);
_BUR_PUBLIC void xmlGetMemoryInfo(struct xmlGetMemoryInfo* inst);
_BUR_PUBLIC void xmlCloseMemoryWriter(struct xmlCloseMemoryWriter* inst);
_BUR_PUBLIC void xmlWriteStartDocument(struct xmlWriteStartDocument* inst);
_BUR_PUBLIC void xmlWriteStartDocEnc(struct xmlWriteStartDocEnc* inst);
_BUR_PUBLIC void xmlWriteEndDocument(struct xmlWriteEndDocument* inst);
_BUR_PUBLIC void xmlWriteStartElement(struct xmlWriteStartElement* inst);
_BUR_PUBLIC void xmlWriteAttribute(struct xmlWriteAttribute* inst);
_BUR_PUBLIC void xmlWriteElementText(struct xmlWriteElementText* inst);
_BUR_PUBLIC void xmlWriteElementTextEx(struct xmlWriteElementTextEx* inst);
_BUR_PUBLIC void xmlWriteEndElement(struct xmlWriteEndElement* inst);
_BUR_PUBLIC void xmlWriteComment(struct xmlWriteComment* inst);
_BUR_PUBLIC void xmlWriteCommentEx(struct xmlWriteCommentEx* inst);
_BUR_PUBLIC void xmlWriteCData(struct xmlWriteCData* inst);
_BUR_PUBLIC void xmlWriteCDataEx(struct xmlWriteCDataEx* inst);
_BUR_PUBLIC void xmlWritePI(struct xmlWritePI* inst);


#ifdef __cplusplus
};
#endif
#endif /* _ASXML_ */

