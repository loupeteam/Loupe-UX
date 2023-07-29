/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: OMJSON
 * File: jsonAux.h
 * Author: davidblackburn
 * Created: October 20, 2014
 *******************************************************************/

/*
  Copyright (c) 2009-2017 David Blackburn, Dave Gamble, and cJSON contributors 

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
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
