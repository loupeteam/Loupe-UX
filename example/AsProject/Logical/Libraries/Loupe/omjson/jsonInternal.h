/*
 * File: jsonInternal.h
 * Copyright (c) 2023 Loupe
 * https://loupe.team
 * 
 * This file is part of OMJSON, licensed under the MIT License.
 */

#ifndef __JSON_INTERNAL_H__
#define __JSON_INTERNAL_H__

#ifdef __cplusplus
	extern "C"
	{
#endif

#include <bur/plctypes.h>
#include "OMJSON.h"

// Internal function prototypes
unsigned short jsonInternalSetWSServerError(unsigned short ErrorID, struct jsonWebSocketServer* t);
unsigned short jsonInternalSetHTTPServerError(unsigned short ErrorID, struct jsonHTTPServer* t);
unsigned short jsonInternalSetReadListError(unsigned short ErrorID, struct jsonReadVariableList* t);
unsigned short jsonInternalSetReadError(unsigned short ErrorID, struct jsonReadVariable* t);
unsigned short jsonInternalSetAddError(unsigned short ErrorID, struct jsonAddVariableToCache* t);
unsigned short jsonInternalSetReadNoCacheError(unsigned short ErrorID, struct jsonReadVariableNoCache* t);

#ifdef __cplusplus
	};
#endif

#endif
