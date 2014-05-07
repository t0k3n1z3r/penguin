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
* @enum PF_CONTEXT_STATE
* @brief Defines states of the PF structures and classes that contain PfHeader.
* @ingroup	PfCore
****************************************************************************************************
*/
typedef enum
{
	PF_CONTEXT_STATE_INITIALIZED = 0, ///< Owner structure is initialized
	PF_CONTEXT_STATE_UNINITIALIZED = 1 ///< Owner structure is uninitialized
} PF_CONTEXT_STATE;

/**
****************************************************************************************************
* @struct PfHeader
* @brief Penguin Framework header structure. It contains owner structure size, type and state.
* @ingroup	PfCore
****************************************************************************************************
*/
typedef struct
{
	Udword size; ///< Owner structure size
	Udword type; ///< Owner structure type
	PF_CONTEXT_STATE state : 32; ///< Owner structure state
} PfHeader;

#endif /* !_PF_HEADER_H_ */