/**
****************************************************************************************************
* @file 	PfHeader.h
* @image	html classdiagram.png
* @brief 	Penguin Framework [PF] structure and classes header definition
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_HEADER_H_
#define _PF_HEADER_H_

#include "PfTypes.h"

/**
****************************************************************************************************
* @struct PfHeader
* @brief Penguin Framework header structure. It contains owner structure size, type and state.
****************************************************************************************************
*/
typedef struct
{
	Udword size; ///< Owner structure size
	Udword type; ///< Owner structure type
	Udword state; ///< Owner structure state
} PfHeader;

#endif /* !_PF_HEADER_H_ */