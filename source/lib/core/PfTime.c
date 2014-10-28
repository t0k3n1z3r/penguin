/**
****************************************************************************************************
* @file 	PfTime.c
* @brief 	Penguin Framework [PF] implementation mechanism to work with system time.
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 07, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "core/PfTime.h"
#include <time.h>

/*
****************************************************************************************************
*
****************************************************************************************************
*/
Uqword PFAPI PfGetSystemTimeUsec(void)
{
    struct timespec t;
    //clock_gettime(CLOCK_MONOTONIC, &t);
    return ((Uqword)t.tv_sec) * 1000000L + ((Uqword)t.tv_nsec) / 1000;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
void PFAPI SfParseTimeStructure(PfTime* const pTime, Uqword rsec)
{
    pTime->usec = rsec % 1000;
    rsec /= 1000;
    pTime->msec = rsec % 1000;
    rsec /= 1000;
    pTime->sec = rsec % 60;
    rsec /= 60;
    pTime->minutes = rsec % 60;
    rsec /= 60;
    pTime->hours	= rsec % 24;
    rsec /= 24;
    pTime->days = (Udword)rsec;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PfTime PFAPI PfGetTimeStructure(Uqword rsec)
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
    currentTime.hours	= rsec % 24;
    rsec /= 24;
    currentTime.days = (Udword)rsec;

    return currentTime;
}
