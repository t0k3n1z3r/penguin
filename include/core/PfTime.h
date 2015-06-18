/**
****************************************************************************************************
* @file     PfTime.h
* @brief    Penguin Framework [PF] declaration structures and function for working with system time.
* @ingroup  PfCore
* @author   Maksym Koshel (maks.koshel@gmail.com)
* @date     May 07, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_TIME_H_
#define _PF_TIME_H_

#include "auto-generated/PfConfig.h"
#include "auto-generated/PfTypes.h"

/**
****************************************************************************************************
* @brief This struct represent system time
* @ingroup  PfCore
****************************************************************************************************
*/
typedef struct
{
    uint8_t     days;       ///< Days
    uint8_t     hours;      ///< Hours
    uint8_t     minutes;    ///< Minutes
    uint8_t     sec;        ///< Seconds
    uint32_t    msec;       ///< Miliseconds
    uint32_t    usec;       ///< Microseconds

} PfTime;

/**
****************************************************************************************************
* @brief Get time in nanosecod from system start
* @ingroup  PfCore
* @return System timestamp in nanosecond
****************************************************************************************************
*/
uint64_t PFAPI PfGetSystemTimeUsec(void);

/**
****************************************************************************************************
* @brief Convert nanosecond timestamp into time structure
* @ingroup  PfCore
* @param [out] pTime pointer to the time structure
* @param [in] rsec time in nanoseconds
* @return void
****************************************************************************************************
*/
void PFAPI PfParseTimeStructure(PfTime* const pTime, uint64_t rsec);

/**
****************************************************************************************************
* @brief Convert nanosecond timestamp into time structure
* @ingroup  PfCore
* @param [in] rsec time in nanoseconds
* @return PfTime structure
****************************************************************************************************
*/
PfTime PFAPI PfGetTimeStructure(uint64_t rsec);

#endif  /* !_PF_TIME_H_ */
