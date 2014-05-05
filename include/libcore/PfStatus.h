/**
****************************************************************************************************
* @file 	PfStatus.h
* @brief 	Penguin Framework [PF] error and status codes
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	Apr 23, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_STATUS_H_
#define _PF_STATUS_H_

/**
****************************************************************************************************
* @enum PF_STATUS
* @brief PF error and status codes definition
****************************************************************************************************
*/
typedef enum
{
	PF_STATUS_OK = 0, ///< Operation was successfull
	PF_STATUS_NOT_IMPLEMENTED = 1, ///< Operation is not implemented
	PF_STATUS_FAIL = -(1) ///< Operation was failed
} PF_STATUS;

#endif	/* !_PF_STATUS_H_ */