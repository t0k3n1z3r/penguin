/**
****************************************************************************************************
* @file 	PfDebug.h
* @brief 	Penguin Framework [PF] debug and log mechanism declaration
* @ingroup	PfCore
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#ifndef _PF_DEBUG_H_
#define _PF_DEBUG_H_

#include "PfHeader.h"
#include "PfStatus.h"
#include "PfConfig.h"

/**
****************************************************************************************************
* @enum 	PF_DEBUG_CLASS
* @brief 	This enum defines all possible debug classes. For each log message will be printed a tag
* 			which is mapped to corresponding debug class.
****************************************************************************************************
*/
typedef enum
{
	/**
	* @warning ATTENTION!: when you change this enumeration you should change
	* 	DEBUG_CLASS_ALIASES array. It is placed in PfDebug.c file.
    */
	PF_DEBUG_CLASS_UNDEFINED	= 0, ///< Undefined class
	PF_DEBUG_CLASS_CORE		 	= 1, ///< libcore debug class
	PF_DEBUG_CLASS_PROTOCOL 	= 2, ///< libprotocol class
	PF_DEBUG_CLASS_TRANSPORT 	= 3, ///< libtransport class
	PF_DEBUG_CLASS_PENGUIN		= 4, ///< Main application
	PF_DEBUG_CLASS_MAX 			= PF_DEBUG_CLASS_PENGUIN
} PF_DEBUG_CLASS;

/**
****************************************************************************************************
* @enum 	PF_DEBUG_LEVEL
* @brief 	This enum defines all possible debug levels. If project was compiled with MAX degug
*			level PF_DEBUG_LEVEL_ERROR, it means that only ERROR messages will be printed to the
*			output buffer.
****************************************************************************************************
*/
typedef enum
{
	/**
	* @warning ATTENTION!: when you change this enumeration you should change
	* 	DEBUG_CLASS_ALIASES array. It is placed in PfDebug.c file.
    */
    PF_DEBUG_LEVEL_ERROR 		= 0, ///< Debug level ERROR
    PF_DEBUG_LEVEL_WARNING 		= 1, ///< Debug level WARNING
    PF_DEBUG_LEVEL_INFO 		= 2, ///< Debug level INFORMATION
    PF_DEBUG_LEVEL_MAX 			= PF_DEBUG_LEVEL_INFO
} PF_DEBUG_LEVEL;

/**
****************************************************************************************************
* @struct 	PfDebugContext
* @brief 	Debug context structure is one of the most important things. This structure encapsulate
*			the logic of the logging, monitoring and debugging process. In release mode debuging
*			option disabled.
* @ingroup	PfCore
****************************************************************************************************
*/
typedef struct
{
	PfHeader header; ///< Debug context header
} PfDebugContext;

/**
****************************************************************************************************
* @brief 	Open and initialize debiging context.
* @ingroup	PfCore
* @param 	[in,out] context pointer to the debuging context.
* @return 	PF_STATUS_OK on success, PF_STATUS_FAIL otherwise.
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDebugContext(PfDebugContext* const context);

/**
****************************************************************************************************
* @brief 	Close and destroy resources of the debugging context.
* @ingroup	PfCore
* @param 	[in,out] context pointer to the debuging context.
* @return 	PF_STATUS_OK on success, PF_STATUS_FAIL otherwise.
****************************************************************************************************
*/
PF_STATUS PFAPI PfCloseDebugContext(PfDebugContext* const context);

/**
****************************************************************************************************
* @brief 	Print log message to the output buffer.
* @ingroup	PfCore
* @param 	[in] debugClass module tag
* @param 	[in] debugLevel message level
* @param 	[in] format format string
* @return 	PF_STATUS_OK on success, PF_STATUS_FAIL otherwise.
****************************************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const PF_DEBUG_CLASS debugClass, const PF_DEBUG_LEVEL debugLevel,
	const char* const format, ...);

/**
****************************************************************************************************
* @brief 	Print log message on information level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_I(debugClass, ...) PfPrintLogMessage(debugClass, PF_DEBUG_LEVEL_INFO, __VA_ARGS__)

/**
****************************************************************************************************
* @brief 	Print log message on warning level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_W(debugClass, ...) PfPrintLogMessage(debugClass, PF_DEBUG_LEVEL_WARNING, __VA_ARGS__)

/**
****************************************************************************************************
* @brief 	Print log message on error level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_E(debugClass, ...) PfPrintLogMessage(debugClass, PF_DEBUG_LEVEL_ERROR, __VA_ARGS__)

#endif	/* !_PF_DEBUG_H_ */