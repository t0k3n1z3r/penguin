/**
****************************************************************************************************
* @file 	PfTime.h
* @brief 	Penguin Framework [PF] declaration structures and function for working with system time.
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 07, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_TIME_H_
#define _PF_TIME_H_

#include "PfConfig.h"
#include "PfTypes.h"

/**
****************************************************************************************************
* @brief This struct represent system time
* @ingroup	PfCore
****************************************************************************************************
*/
typedef struct
{
    Udword	days; 		///< Days
    Ubyte	hours; 		///< Hours
    Ubyte	minutes; 	///< Minutes
    Ubyte	sec; 		///< Seconds
    Udword	msec; 		///< Miliseconds
    Udword	usec; 		///< Microseconds
} PfTime;

/**
****************************************************************************************************
* @brief Get time in nanosecod from system start
* @ingroup	PfCore
* @return System timestamp in nanosecond
****************************************************************************************************
*/
Uqword PFAPI PfGetSystemTimeUsec(void);

/**
****************************************************************************************************
* @brief Convert nanosecond timestamp into time structure
* @ingroup	PfCore
* @param [out] pTime pointer to the time structure
* @param [in] rsec time in nanoseconds
* @return void
****************************************************************************************************
*/
void PFAPI PfParseTimeStructure(PfTime* const pTime, Uqword rsec);

/**
****************************************************************************************************
* @brief Convert nanosecond timestamp into time structure
* @ingroup	PfCore
* @param [in] rsec time in nanoseconds
* @return PfTime structure
****************************************************************************************************
*/
PfTime PFAPI PfGetTimeStructure(Uqword rsec);

#endif	/* !_PF_TIME_H_ */
