/**
****************************************************************************************************
* @file 	PfMain.c
* @brief 	Penguin Framework [PF] entry point
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "libcore/PfDebug.h"

/**
****************************************************************************************************
* @brief Entry point of the Penguin Framework binary
* @param argc Number of input arguments
* @param argv pointer to the array of arguments
* @return Error code
****************************************************************************************************
*/
int main(int argc, char* argv[])
{
	PF_STATUS result = PF_STATUS_FAIL;
	PfDebugContext debugContext;

	debugContext.header.size = sizeof(PfDebugContext);
	debugContext.debugClass = PF_DEBUG_CLASS_PENGUIN;
	debugContext.debugLevel = PF_DEBUG_LEVEL_MAX;

	result = PfOpenDebugContext(&debugContext);
	PF_LOG_I(PF_DEBUG_CLASS_PENGUIN, "Hello from penguin module");

	PF_LOG_I(PF_DEBUG_CLASS_CORE, "Hello from penguin module");

	result = PfCloseDebugContext(&debugContext);
	return result;
}