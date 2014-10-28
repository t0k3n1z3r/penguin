/**
****************************************************************************************************
* @file 	PfDBusContext.h
* @brief 	Penguin Framework [PF] Data Bus definition
* @ingroup	PfTransport
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_DBUS_H_
#define _PF_DBUS_H_

#include "libprotocol/PfPacket.h"

/**
****************************************************************************************************
* @struct PfDBusControllerContext
* @brief D-Bus controller context definition
* @ingroup	PfTransport
****************************************************************************************************
*/
typedef struct
{
	PfHeader header; ///< D-Bus controller header
} PfDBusControllerContext;

#endif	/* !_PF_DBUS_H_ */