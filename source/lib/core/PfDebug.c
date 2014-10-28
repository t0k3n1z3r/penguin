/**
****************************************************************************************************
* @file 	PfDebug.c
* @brief 	Penguin Framework [PF] debug and log mechanism implementation
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	Apr 23, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "core/PfDebug.h"
#include "core/PfTime.h"

#include <stdio.h>
#include <stdarg.h>

#ifndef PF_DEBUG_MESSAGE_SIZE
/**
****************************************************************************************************
* @def 		PF_DEBUG_MESSAGE_SIZE
* @brief 	Specifies debug message size. This parameter may be passed as external variable from
*			build system
* @note		PF_DEBUG_MESSAGE_SIZE designed to be set in the make file
****************************************************************************************************
*/
#define PF_DEBUG_MESSAGE_SIZE 256
#endif

/**
****************************************************************************************************
* @brief	This array is used to map debug level to corresponding string for output
* @see 		PF_DEBUG_LEVEL
****************************************************************************************************
*/
static const char* s_debugLevelAliases[] =
{
	/**
	* @brief 	Log tag for error message	
	* @see 		PF_DEBUG_LEVEL_ERROR
	*/
	"E",

	/**
	* @brief 	Log tag for warning message
	* @see 		PF_DEBUG_LEVEL_WARNING
	*/
	"W",

	/**
	* @brief 	Log tag for informational message
	* @see 		PF_DEBUG_LEVEL_INFO
	*/
	"I"
};

/**
****************************************************************************************************
* @brief 	This array is used to map message color to it's type and class
* @see 		PF_DEBUG_LEVEL
* @see 		PF_DEBUG_CLASS
****************************************************************************************************
*/
static const char* s_debugColorAliases[] =
{
	/**
	* @brief 	Log tag for error message (Red color)
	* @see 		PF_DEBUG_LEVEL_ERROR
	*/
	"\031[0m",

	/**
	* @brief 	Log tag for warning message (Yellow color)
	* @see 		PF_DEBUG_LEVEL_WARNING
	*/
	"\032[0m",

	/**
	* @brief 	Log tag for informational message (green/white)
	* @see 		PF_DEBUG_LEVEL_INFO
	*/
	"\033[0m"
};

/**
****************************************************************************************************
* @brief	This array is used to map debug class to corresponding string for output
* @see 		PF_DEBUG_CLASS
****************************************************************************************************
*/
static const char* s_debugClassAliases[] =
{
	/**
	* @brief 	Log tag for unknown module (enabled by default)
	* @see 	 	PF_DEBUG_CLASS_UNDEFINED
	*/
	"????",

	/**
	* @brief 	Log tag for Core module of the Penguin Framework
	* @see 		PF_DEBUG_CLASS_CORE
	*/
	"CORE",

	/**
	* @brief 	Log tag for Protocol module of the Penguin Framework
	* @see 		PF_DEBUG_CLASS_PROTOCOL
	*/ 
	"PRTL",

	/**
	* @brief 	Log tag for Transport module of the Penguin Framework
	* @see 		PF_DEBUG_CLASS_TRANSPORT
	*/
	"TRST",

	/**
	* @brief 	Log tag for Test and other purposes of the Penguin Framework
	* @see 		PF_DEBUG_CLASS_PENGUIN
	*/
	"PENG"
};

/**
****************************************************************************************************
* @brief Array of debug contexts that may be used to split log message flow by modules
****************************************************************************************************
*/
static PfDebugContext s_debugContextArray[5] = 
{
	{
		.header = 
		{
			.size = sizeof(PfDebugContext),
			.state = PF_CONTEXT_STATE_INITIALIZED,
			.type = 0
		},
		.debugClass = PF_DEBUG_CLASS_UNDEFINED,
		.debugLevel = PF_DEBUG_LEVEL_MAX
	},
};

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDebugContext(PfDebugContext* const pContext)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;
	if (NULL != pContext && pContext->header.size == sizeof(PfDebugContext))
	{
		s_debugContextArray[pContext->debugClass] = *pContext;
	}
	else
	{
		printf("Debug context is invalid!");
	}
	return result;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfCloseDebugContext(PfDebugContext* const context)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;

	return result;
}

/**
****************************************************************************************************
* @brief 	Output debug string to the stream defined in the context
* @param 	[in] pMessage Message to output
* @todo 	Implement output based on context
* @return	PF_STATUS_OK on success, SF_STATUS_FAIL otherwise
****************************************************************************************************
*/
PF_STATUS PFAPI PfOutputDebugString(const char* const pMessage)
{
	PF_STATUS result = PF_STATUS_OK;

	printf("%s\n", pMessage);

	return result;
}

/**
****************************************************************************************************
* @brief 	Convert current time (time counting started on opening debug context) to string for
*			loging
* @return 	Constant C-style string
****************************************************************************************************
*/
static const char* PfConvertTimeToString(void)
{
	return "[00:00:00:000]";
}

/**
****************************************************************************************************
* @brief 	Convert debug class (module type) to string for loging
* @param 	[in] moduleClass Debug class of the message to be print
* @return	Constant C-style string
****************************************************************************************************
*/
static const char* PfConvertDebugClassToString(PF_DEBUG_CLASS moduleClass)
{
	return s_debugClassAliases[moduleClass];
}

/**
****************************************************************************************************
* @brief 	Convert debug level to string for loging
* @param 	[in] debugLevel Debug level of the message to be print
* @return	Constant C-style string
****************************************************************************************************
*/
static const char* PfConvertLevelToString(PF_DEBUG_LEVEL debugLevel)
{
	return s_debugLevelAliases[debugLevel];
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const char* const pFunctionName, const int lineNumber,
	PF_DEBUG_CLASS debugClass, PF_DEBUG_LEVEL debugLevel, const char* const pFormatMessage, ...)
{
	PF_STATUS result = PF_STATUS_OK;
	va_list argumentList;
	char buffer[PF_DEBUG_MESSAGE_SIZE] = {0};
	size_t currentPosition = 0;

	// Push time stamp to message header
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition,
		"%s", PfConvertTimeToString());

	// Push debug class to message header
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition,
		"[%s]", PfConvertDebugClassToString(debugClass));

	// Push debug level to message header
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition,
		"[%s]", PfConvertLevelToString(debugLevel));

	// Push function name and line number to message header
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition,
		"[%s:%d]", pFunctionName, lineNumber);

	va_start(argumentList, pFormatMessage);

	// Push format string and arguments to message body
	currentPosition += vsnprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition,
		pFormatMessage, argumentList);

	va_end(argumentList);

	result = PfOutputDebugString(buffer);

	return result;
}
