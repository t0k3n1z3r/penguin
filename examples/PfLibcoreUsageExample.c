/**
****************************************************************************************************
* @example	PfLibcoreUsageExample.c
* @file 	PfLibcoreUsageExample.c
* @brief 	Penguin Framework [PF] libcore usage example
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	Apr 23, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include <stdio.h>
#include "libcore/PfDebug.h"

/**
****************************************************************************************************
* @brief Entry point of the libcore usage example
* @param argc Number of input arguments
* @param argv pointer to the array of arguments
* @todo  Implement examples when interfaces will be done
* @return Error code
****************************************************************************************************
*/
int main(int argc, char* argv[])
{
	WD_LOG_D("This is an example of the libcore usage");
	WD_LOG_I("This is an example of the libcore usage");
	WD_LOG_W("This is an example of the libcore usage");
	WD_LOG_E("This is an example of the libcore usage");
	return 0;
}