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
static const char* s_debugClassAliases[] = {"????", "CORE", "TRST", "PRTL", "PENG"};

/**
****************************************************************************************************
* @brief	Print debug prepared string to the output buffer using PfDebugContext.
* @param	[in] pContext pointer to the debugging context.
* @param 	[in] pMessage pointer to the message that should be printed.
* @return 	void
****************************************************************************************************
*/
void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage);
/**
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDebugContext(PfDebugContext* const context)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;

	return result;
}

/**
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


	va_list args;
	va_start(format, args);

	// Start constructing the output message


	PfOutputDebugString(NULL, outputBuffer);

	va_end(args);
	return result;
}

/**
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
			printf("[%p]: %s", pContext, pMessage);
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