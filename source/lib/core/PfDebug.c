/**
********************************************************************************
* @file         PfDebug.c
* @brief        Penguin Framework [PF] debug and log mechanism implementation
* @ingroup      PfCore
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         Apr 23, 2014
* @copyright    Maksym Koshel (c) 2014. All rights reserved.
********************************************************************************
*/

#include "core/PfDebug.h"
#include "core/PfTime.h"

#include <stdio.h>
#include <stdarg.h>

#ifndef PF_LOG_LEVEL_CONFIGURED


#define PF_LOG_LEVEL_CONFIGURED PF_LOG_LEVEL_MAX
#endif  /* !PF_LOG_LEVEL_CONFIGURED */

#ifndef PF_LOG_MESSAGE_SIZE
/**
********************************************************************************
* @def          PF_LOG_MESSAGE_SIZE
* @brief        Specifies log message size. This parameter may be passed as
*               external variable from build system
* @note         PF_LOG_MESSAGE_SIZE designed to be set in the make file
********************************************************************************
*/
#define PF_LOG_MESSAGE_SIZE 512
#endif

/**
********************************************************************************
* @brief        This array is used to map debug level to corresponding string
*               for output
* @see          PF_LOG_LEVEL
********************************************************************************
*/
static const char* s_logLevelAliases[] =
{
    /**
    ****************************************************************************
    * @brief    Log tag for error messages   
    * @see      PF_LOG_LEVEL_ERROR
    ****************************************************************************
    */
    "E",

    /**
    ****************************************************************************
    * @brief    Log tag for warning messages
    * @see      PF_LOG_LEVEL_WARNING
    ****************************************************************************
    */
    "W",

    /**
    ****************************************************************************
    * @brief    Log tag for information messages
    * @see      PF_LOG_LEVEL_INFO
    ****************************************************************************
    */
    "I",

    /**
    ****************************************************************************
    * @brief    Log tag for debug messages
    * @see      PF_LOG_LEVEL_DEBUG
    ****************************************************************************
    */
    "D"
};

/**
********************************************************************************
* @brief        This array is used to map debug class to corresponding string
*               for output
* @see          PF_LOG_CLASS
********************************************************************************
*/
static const char* s_logClassAliases[] =
{
    /**
    ****************************************************************************
    * @brief    Log tag for unknown module (enabled by default)
    * @see      PF_LOG_CLASS_UNDEFINED
    ****************************************************************************
    */
    "????",

    /**
    ****************************************************************************
    * @brief    Log tag for Core module of the Penguin Framework
    * @see      PF_LOG_CLASS_CORE
    ****************************************************************************
    */
    "CORE",

    /**
    ****************************************************************************
    * @brief    Log tag for Protocol module of the Penguin Framework
    * @see      PF_LOG_CLASS_PROTOCOL
    ****************************************************************************
    */ 
    "PRTL",

    /**
    ****************************************************************************
    * @brief    Log tag for Transport module of the Penguin Framework
    * @see      PF_LOG_CLASS_TRANSPORT
    ****************************************************************************
    */
    "TRST",

    /**
    ****************************************************************************
    * @brief    Log tag for general purposes of the Penguin Framework
    * @see      PF_LOG_CLASS_PENGUIN
    ****************************************************************************
    */
    "PENG"
};

/**
********************************************************************************
* @brief        Output debug string to the stream defined in the context
* @param        [in] pMessage Message to output
* @todo         Implement output based on context
* @return       PF_STATUS_OK on success, SF_STATUS_FAIL otherwise
********************************************************************************
*/
static PF_STATUS PfOutputDebugString(const char* const pMessage)
{
    PF_STATUS result = PF_STATUS_OK;
    fprintf(stdout, "%s\n", pMessage);
    fflush(stdout);
    return result;
}

/**
********************************************************************************
* @brief        Convert debug class (module type) to string for loging
* @param        [in] moduleClass Debug class of the message to be print
* @return       Constant C-style string
********************************************************************************
*/
static const char* PfConvertDebugClassToString(PF_LOG_CLASS moduleClass)
{
    return s_logClassAliases[moduleClass];
}

/**
********************************************************************************
* @brief        Convert debug level to string for loging
* @param        [in] debugLevel Debug level of the message to be print
* @return       Constant C-style string
********************************************************************************
*/
static const char* PfConvertLevelToString(PF_LOG_LEVEL debugLevel)
{
    return s_logLevelAliases[debugLevel];
}

size_t PfPrintMessageHeader(char* const pBuffer,
    const char* const pFunctionName, const int lineNumber,
    PF_LOG_CLASS debugClass, PF_LOG_LEVEL debugLevel)
{
    size_t result = 0;

#ifdef PF_BUILD_TYPE_DEBUG

    // Get current time stamp
    PfTime timestamp = PfGetTimeStructure(PfGetRealTimeUsec());

    // Push time stamp to message header
    result += snprintf(pBuffer + result,
        PF_LOG_MESSAGE_SIZE - result, "[%.2d:%.2d:%.2d:%.3d]",
        timestamp.hours, timestamp.minutes, timestamp.sec, timestamp.msec);

    // Push debug class to message header
    result += snprintf(pBuffer + result,
        PF_LOG_MESSAGE_SIZE - result, "[%s]",
        PfConvertDebugClassToString(debugClass));

    // Push debug level to message header
    result += snprintf(pBuffer + result,
        PF_LOG_MESSAGE_SIZE - result, "[%s]",
        PfConvertLevelToString(debugLevel));

    // Push function name and line number to message header
    result += snprintf(pBuffer + result,
        PF_LOG_MESSAGE_SIZE - result, "[%s:%d]", pFunctionName,
        lineNumber);
#else
    (void)pBuffer;
    (void)pFunctionName;
    (void)lineNumber;
    PfConvertDebugClassToString(debugClass);
    PfConvertLevelToString(debugLevel);
#endif  /* !PF_BUILD_TYPE_DEBUG */

    return result;
}

/*
********************************************************************************
*
********************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const char* const pFunctionName,
    const int lineNumber, PF_LOG_CLASS debugClass, PF_LOG_LEVEL debugLevel,
    const char* const pFormatMessage, ...)
{
    PF_STATUS result = PF_STATUS_OK;
    va_list argumentList;
    char buffer[PF_LOG_MESSAGE_SIZE] = {0};
    size_t currentPosition = 0;
    
    if (debugLevel <= PF_LOG_LEVEL_CONFIGURED)
    {
        /*
        // Get current time stamp
        PfTime timestamp = PfGetTimeStructure(PfGetRealTimeUsec());

        // Push time stamp to message header
        currentPosition += snprintf(buffer + currentPosition,
            PF_LOG_MESSAGE_SIZE - currentPosition, "[%.2d:%.2d:%.2d:%.3d]",
            timestamp.hours, timestamp.minutes, timestamp.sec, timestamp.msec);

        // Push debug class to message header
        currentPosition += snprintf(buffer + currentPosition,
            PF_LOG_MESSAGE_SIZE - currentPosition, "[%s]",
            PfConvertDebugClassToString(debugClass));

        // Push debug level to message header
        currentPosition += snprintf(buffer + currentPosition,
            PF_LOG_MESSAGE_SIZE - currentPosition, "[%s]",
            PfConvertLevelToString(debugLevel));

        // Push function name and line number to message header
        currentPosition += snprintf(buffer + currentPosition,
            PF_LOG_MESSAGE_SIZE - currentPosition, "[%s:%d]", pFunctionName,
            lineNumber);
        */
        
        currentPosition += PfPrintMessageHeader(buffer, pFunctionName,
            lineNumber, debugClass, debugLevel);

        va_start(argumentList, pFormatMessage);

        // Push format string and arguments to message body
        currentPosition += vsnprintf(buffer + currentPosition,
            PF_LOG_MESSAGE_SIZE - currentPosition, pFormatMessage,
            argumentList);

        va_end(argumentList);

        result = PfOutputDebugString(buffer);
    }

    return result;
}
