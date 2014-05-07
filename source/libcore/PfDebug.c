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
#include <stdio.h>

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

PF_STATUS PFAPI PfPrintLogMessage(const PF_DEBUG_CLASS debugClass, const PF_DEBUG_LEVEL debugLevel,
	const char* const format, ...)
{
	PF_STATUS result = PF_STATUS_OK;
	PfOutputDebugString(NULL, format);
	return result;
}

void PfOutputDebugString(PfDebugContext* const pContext, const char* const pMessage)
{
	printf("[%p]: %s", pContext, pMessage);
}