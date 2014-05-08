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

#include "PfDebug.h"
#include "PfTime.h"
#include <stdio.h>
#include <stdarg.h>

/**
****************************************************************************************************
* @brief	This array is used to map debug level to corresponding string for output
****************************************************************************************************
*/
static const char* s_debugLevelAliases[] = {"ERR","WARN", "INFO"};

/**
****************************************************************************************************
* @brief	This array is used to map debug class to corresponding string for output
****************************************************************************************************
*/
static const char* s_debugClassAliases[] = {"????", "CORE", "PRTL", "TRST", "PENG"};

/**
****************************************************************************************************
* @brief	Print debug prepared string to the output buffer using PfDebugContext.
* @param	[in] pContext pointer to the debugging context.
* @param 	[in] pMessage pointer to the message that should be printed.
* @return 	void
****************************************************************************************************
*/
void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage);

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDebugContext(PfDebugContext* const context)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;

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

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const PF_DEBUG_CLASS debugClass, const PF_DEBUG_LEVEL debugLevel,
	const char* const format, ...)
{
	PF_STATUS result = PF_STATUS_OK;

	/**
	* @brief	Allocation of 512 bytes on stack is very bad for kernel device drivers since it has
	*			single stack address space.
	* @todo: 	To change the memory for this buffer. 
	*/
	char outputBuffer[512] = {0,};
	char* pCurrentPosition = outputBuffer;
	size_t bufferLeft = sizeof(outputBuffer);

	// Put the time of the event into output message 
	PfTime currentTime = PfGetTimeStructure(PfGetSystemTimeUsec());
	Udword lengthOfMessage = snprintf(pCurrentPosition, bufferLeft, "[%.2d:%.2d:%.2d:%.3d]",
		currentTime.hours, currentTime.minutes, currentTime.sec, currentTime.msec);

	// Calculate actual buffer size and new position
	bufferLeft -= lengthOfMessage;
	pCurrentPosition += lengthOfMessage;

	// Put debug class and debug level into
	lengthOfMessage = snprintf(pCurrentPosition, bufferLeft, "[%s][%s]: ",
		s_debugClassAliases[debugClass], s_debugLevelAliases[debugLevel]);

	// Calculate actual buffer size and new position
	bufferLeft -= lengthOfMessage;
	pCurrentPosition += lengthOfMessage;

	// Use std API to parse the function arguments
	va_list args;
	va_start(args, format);
	lengthOfMessage = vsnprintf(pCurrentPosition, bufferLeft, format, args);
	va_end(args);

	PfDebugContext debugContext;
	debugContext.header.size = sizeof(PfDebugContext);
	debugContext.header.state = PF_CONTEXT_STATE_INITIALIZED;

	PfOutputDebugString(&debugContext, outputBuffer);
	return result;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage)
{
	if (NULL != pContext && pContext->header.size == sizeof(PfDebugContext))
	{
		if (PF_CONTEXT_STATE_INITIALIZED == pContext->header.state)
		{
			printf("%s\n", pMessage);
		}
		else
		{
			printf("Debug context was not initialized!\n");
		}
	}
	else
	{
		printf("Debug context for this module is %p\n", pContext);
	}
}