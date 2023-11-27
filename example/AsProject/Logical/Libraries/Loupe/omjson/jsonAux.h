/*
 * File: jsonAux.h
 * Copyright (c) 2009 - 2023 Loupe, Dave Gamble, and cJSON contributors 
 * https://loupe.team
 * 
 * This file is part of OMJSON, licensed under the MIT License.
 */

#ifndef __JSONAUX_H__
#define __JSONAUX_H__

#include <bur/plctypes.h>

#ifdef __cplusplus
	extern "C"
	{
#endif

	#include "OMJSON.h"
	#include <string.h>

#ifdef __cplusplus
	};
#endif

// Library internal constants
//----------------------------

#define JSON_INT_DEFAULTMAXLENGTH 10000


// Helper functions from cJSON library
//-------------------------------------

// Skip whitespace
char *skip(char *in);

// Parse the input text into an unescaped cstring
char *parse_string(char *pDest, char *pSrc, unsigned long maxLength);

// UnStringify the input text from an escaped JSON strin
unsigned long unescape_string(char *pDest, char *pSrc, unsigned long maxLength, char **reentry);

// Stringify the input text into an escaped JSON string
unsigned long stringify_string(char *pDest, char *pSrc, unsigned long maxLength, char** reentry);

// Stringify the input text as WString into an escaped JSON string
unsigned long stringify_wstring(char *pDest, unsigned short *pSrc, unsigned long maxLength, unsigned short **reentry);

// Parse the input text into a number string
char *parse_number(char *pDest, char *pSrc);

// Parser core - when encountering text, process appropriately
char *parse_value(varVariable_typ *pVariable, char *value);

#endif
