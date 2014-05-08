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

/**
****************************************************************************************************
* @brief	Print debug prepared string to the output buffer using PfDebugContext.
* @param	[in] pContext pointer to the debugging context.
* @param 	[in] pMessage pointer to the message that should be printed.
* @return 	void
****************************************************************************************************
*/
static void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage);

/**
****************************************************************************************************
* @brief	Construct message header to be printed (Time, debug class and debug level).
* @param	[out] pBuffer pointer to the output buffer.
* @param 	[in] bufferSize size in bytes of the output buffer
* @return 	number for written bytes that was started from pBuffer.
****************************************************************************************************
*/
static size_t PfConstructMessageHeader(char* const pBuffer, size_t bufferSize,
	const PF_DEBUG_CLASS debugClass, const PF_DEBUG_LEVEL debugLevel);

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

	size_t lengthOfMessage = PfConstructMessageHeader(pCurrentPosition, bufferLeft,
		debugClass, debugLevel);

	bufferLeft -= lengthOfMessage;
	pCurrentPosition += lengthOfMessage;

	// Use std API to parse the function arguments
	va_list args;
	va_start(args, format);
	lengthOfMessage = vsnprintf(pCurrentPosition, bufferLeft, format, args);
	va_end(args);

	PfOutputDebugString(&s_debugContextArray[debugClass], outputBuffer);
	return result;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
static void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage)
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

/*
****************************************************************************************************
*
****************************************************************************************************
*/
static size_t PfConstructMessageHeader(char* const pBuffer, size_t bufferSize,
	const PF_DEBUG_CLASS debugClass, const PF_DEBUG_LEVEL debugLevel)
{
	size_t result = 0;

	size_t writtenBytes = 0;
	char* pCurrentBufferPosition = pBuffer;
	size_t availableSpaceInBuffer = bufferSize;

	// Put the time of the event into output message 
	PfTime currentTime = PfGetTimeStructure(PfGetSystemTimeUsec());
	writtenBytes = snprintf(pCurrentBufferPosition, availableSpaceInBuffer, "[%.2d:%.2d:%.2d:%.3d]",
		currentTime.hours, currentTime.minutes, currentTime.sec, currentTime.msec);

	// Calculate actual buffer size and new position
	availableSpaceInBuffer -= writtenBytes;
	pCurrentBufferPosition += writtenBytes;

	// Put debug class and debug level into
	writtenBytes = snprintf(pCurrentBufferPosition, availableSpaceInBuffer, "[%s][%s]: ",
		s_debugClassAliases[debugClass], s_debugLevelAliases[debugLevel]);

	availableSpaceInBuffer -= writtenBytes;
	result = bufferSize - availableSpaceInBuffer;

	return result;
}