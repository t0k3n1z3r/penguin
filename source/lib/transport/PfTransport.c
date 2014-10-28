/**
****************************************************************************************************
* @file 	PfTransport.c
* @brief 	Penguin Framework [PF] Transport component entry point
* @ingroup	PfTransport
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	Oct 28, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "transport/PfTransport.h"
#include "core/PfDebug.h"

/**
****************************************************************************************************
* @brief 	Transport library entry point.
* @return 	void
****************************************************************************************************
*/
static void PfTransportInit(void) __attribute__((constructor));

/**
****************************************************************************************************
* @brief 	Transport library exit point.
* @return 	void
****************************************************************************************************
*/
static void PfTransportUninit(void) __attribute__((destructor));

/*
****************************************************************************************************
*
****************************************************************************************************
*/
void PfTransportInit(void)
{
	PF_LOG_I("Transport module was inited");
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
void PfTransportUninit(void)
{
	PF_LOG_I("Transport module was uninited");
}