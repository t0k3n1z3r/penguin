/**
********************************************************************************
* @file         PfDebug.h
* @brief        Penguin Framework [PF] debug and log mechanism declaration
* @ingroup      PfCore
* @author       Maksym Koshel (maks.koshel@gmail.com)
* @date         May 05, 2014
* @copyright    Maksym Koshel (c) 2014. All rights reserved.
********************************************************************************
*/

#ifndef _PF_DEBUG_H_
#define _PF_DEBUG_H_

// Auto-generated includes
#include "auto-generated/PfConfig.h"
#include "auto-generated/PfStatus.h"
#include "auto-generated/PfLog.h"

// Local includes
#include "PfHeader.h"

/**
********************************************************************************
* @brief        Print log message to the output buffer.
* @ingroup      PfCore
* @param        [in] pFunctionName  Pointer to the string with function name
*                                   where message will be printed.
* @param        [in] lineNumber     Line number of the function called.
* @param        [in] debugClass     Debug class related to the message going to
*                                   be printed.
* @param        [in] debugLevel     Debug level related to the message going to
*                                   be printed.
* @param        [in] pFormatMessage Pointer to the format string.
* @param        [in] ...            Arguments will be passed to message
*                                   construction routines.
* @return       SF_STATUS_OK on success, SF_STATUS_FAIL otherwise.
********************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const char* const pFunctionName,
                                  const int lineNumber,
                                  PF_DEBUG_CLASS debugClass,
                                  PF_DEBUG_LEVEL debugLevel,
                                  const char* const pFormatMessage, ...);

#ifndef PF_DEBUG_CLASS_DEFAULT

/**
********************************************************************************
* @def      PF_DEBUG_CLASS_DEFAULT
* @brief    Specifies default module tag
* @note     PF_DEBUG_CLASS_DEFAULT designed to be set in the make file
********************************************************************************
*/
#define PF_DEBUG_CLASS_DEFAULT PF_DEBUG_CLASS_UNDEFINED
#endif /* !PF_DEBUG_CLASS_DEFAULT */

/**
********************************************************************************
* @brief    Print log message on information level
* @param    [in] debugClass module tag
********************************************************************************
*/
#define PF_LOG_I(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
                                                    PF_DEBUG_CLASS_DEFAULT, \
                                                    PF_DEBUG_LEVEL_INFO, \
                                                    format, ##args)

/**
********************************************************************************
* @brief    Print log message on warning level
* @param    [in] debugClass module tag
********************************************************************************
*/
#define PF_LOG_W(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
                                                    PF_DEBUG_CLASS_DEFAULT, \
                                                    PF_DEBUG_LEVEL_WARNING,\
                                                    format, ##args)

/**
********************************************************************************
* @brief    Print log message on error level
* @param    [in] debugClass module tag
********************************************************************************
*/
#define PF_LOG_E(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
                                                    PF_DEBUG_CLASS_DEFAULT, \
                                                    PF_DEBUG_LEVEL_ERROR, \
                                                    format, ##args)

#endif  /* !_PF_DEBUG_H_ */
