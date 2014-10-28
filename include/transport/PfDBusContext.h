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

#ifndef _PF_DBUS_CONTEXT_H_
#define _PF_DBUS_CONTEXT_H_

#include "core/PfCore.h"

/**
****************************************************************************************************
* @struct 	PfDBusControllerContext
* @brief 	D-Bus controller context definition
* @ingroup	PfTransport
****************************************************************************************************
*/
typedef struct
{
	PfHeader header; ///< D-Bus controller header
} PfDBusControllerContext;

/**
****************************************************************************************************
* @brief	Open D-Bus controller context and alloc resources
* @param 	[in,out] pContext pointer to the D-Bus controller context
* @return 	PF_STATUS_OK on success, PF_STATUS_FAIL otherwise
* @ingroup	PfTransport
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDBusControllerContext(PfDBusControllerContext* const pContext);

/**
****************************************************************************************************
* @brief	Close D-Bus controller context and free resources
* @param 	[in,out] pContext pointer to the D-Bus controller context
* @return 	PF_STATUS_OK on success, PF_STATUS_FAIL otherwise
* @ingroup	PfTransport
****************************************************************************************************
*/
PF_STATUS PFAPI PfCloseDBusControllerContext(PfDBusControllerContext* const pContext);

#endif	/* !_PF_DBUS_CONTEXT_H_ */