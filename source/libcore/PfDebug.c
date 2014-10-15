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
static const char* s_debugLevelAliases[] = {"E","W", "I"};

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

const char* PfConvertTimeToString(void)
{
	return "[00:00:00:000]";
}

const char* PfConvertDebugClassToString(PF_DEBUG_CLASS moduleClass)
{
	return s_debugClassAliases[moduleClass];
}

const char* PfConvertLevelToString(PF_DEBUG_LEVEL debugLevel)
{
	return s_debugLevelAliases[debugLevel];
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
PF_STATUS PFAPI PfPrintLogMessage(const char* const pMessage)
{
	PF_STATUS result = PF_STATUS_OK;
	printf("%s\n", pMessage);
	return result;
}