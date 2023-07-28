
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "LogThat.h"
#ifdef __cplusplus
	};
#endif

#include <string.h>

// Writes to log from severity, code, and template string
// Use this when:
//		- You do NOT have an eventID
// 		- You are sure/NOT sure you have msgData
signed long LogInternalWrite(plcstring* loggerName, unsigned char severity, unsigned short facility, unsigned short code, plcstring* message, unsigned long pMsgData);

// Writes to log from event ID and template string
// Use this when:
//		- You have an eventID
// 		- You are NOT sure you have msgData
signed long LogInternalWriteMsgDataSwitch(plcstring* loggerName, signed long eventID, plcstring* message, unsigned long pMsgData);

// Formats message with message data then writes to logger
// Use this when:
//		- You have an eventID
// 		- You are sure you have msgData
signed long LogInternalWriteMsgData(plcstring* loggerName, signed long eventID, plcstring* message, unsigned long pMsgData);

// Writes to log from event ID and message
// Use this when:
//		- You have an eventID
// 		- You are sure you do NOT have msgData
signed long LogInternalWriteEvent(plcstring* loggerName, signed long eventID, plcstring* message);

