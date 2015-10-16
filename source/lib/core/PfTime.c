/**
********************************************************************************
* @file         PfTime.c
* @brief        Penguin Framework [PF] implementation mechanism to work with
*               system time
* @ingroup      PfCore
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         May 07, 2014
* @copyright    Maksym Koshel (c) 2014. All rights reserved.
********************************************************************************
*/

#include "core/PfTime.h"
#include <time.h>

/*
********************************************************************************
*
********************************************************************************
*/
uint64_t PFAPI PfGetSystemTimeUsec(void)
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return ((uint64_t)t.tv_sec) * 1000000L + ((uint64_t)t.tv_nsec) / 1000;
}

/*
********************************************************************************
*
********************************************************************************
*/
uint64_t PFAPI PfGetRealTimeUsec(void)
{
    struct timespec t;
    clock_gettime(CLOCK_REALTIME, &t);

    struct tm tm;
    localtime_r(&t.tv_sec, &tm);

    /**
    ****************************************************************************
    * @todo     Investigate why localtime function is not working
    ****************************************************************************
    */
    return (tm.tm_sec
            + (tm.tm_min * 60)
            + (tm.tm_hour * 3600)
            + (tm.tm_yday * 86400)
            + ((tm.tm_year -70 ) * 31536000)
            + (((tm.tm_year - 69) / 4) * 86400)
            - (((tm.tm_year - 1) / 100) * 86400)
            + (((tm.tm_year + 299) / 400) * 86400))
            * 1000000LL;
}

/*
********************************************************************************
*
********************************************************************************
*/
void PFAPI SfParseTimeStructure(PfTime* const pTime, uint64_t rsec)
{
    pTime->usec = rsec % 1000;
    rsec /= 1000;
    pTime->msec = rsec % 1000;
    rsec /= 1000;
    pTime->sec = rsec % 60;
    rsec /= 60;
    pTime->minutes = rsec % 60;
    rsec /= 60;
    pTime->hours    = rsec % 24;
    rsec /= 24;
    pTime->days = (uint8_t)rsec;
}

/*
********************************************************************************
*
********************************************************************************
*/
PfTime PFAPI PfGetTimeStructure(uint64_t rsec)
{
    PfTime currentTime;
    
    currentTime.usec = rsec % 1000;
    rsec /= 1000;
    currentTime.msec = rsec % 1000;
    rsec /= 1000;
    currentTime.sec = rsec % 60;
    rsec /= 60;
    currentTime.minutes = rsec % 60;
    rsec /= 60;
    currentTime.hours   = rsec % 24;
    rsec /= 24;
    currentTime.days = (uint64_t)rsec;

    return currentTime;
}
