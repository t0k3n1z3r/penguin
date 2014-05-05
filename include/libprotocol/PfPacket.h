/**
****************************************************************************************************
* @file 	PfPacket.h
* @brief 	Penguin Framework [PF] protocol message definition
* @ingroup	PfProtocol
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_PACKET_H_
#define _PF_PACKET_H_

#include "libcore/PfHeader.h"

/**
****************************************************************************************************
* @struct PfPacket
* @brief Communication protocol message definition
****************************************************************************************************
*/
typedef struct
{
	PfHeader header; ///< Packet header
	Udword data; ///< Packet data
} PfPacket;

#endif /* !_PF_PACKET_H_ */
