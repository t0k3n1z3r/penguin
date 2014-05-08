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
	PF_LOG_I(PF_DEBUG_CLASS_PENGUIN, "Hello from penguin module");
	return 0;
}