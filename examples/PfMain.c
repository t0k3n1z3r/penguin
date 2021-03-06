/**
****************************************************************************************************
* @file 	PfMain.c
* @brief 	Penguin Framework [PF] entry point
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "core/PfDebug.h"
#include "transport/PfTransport.h"

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

	PF_LOG_I("Hello from penguin module");
	PF_LOG_W("Hello from penguin module");
	PF_LOG_E("Hello from penguin module");

	PfDBusControllerContext context;

	PfOpenDBusControllerContext(&context);
	PfCloseDBusControllerContext(&context);

	return result;
}