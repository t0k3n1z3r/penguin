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
	PF_DEBUG_CLASS debugClass; ///< Debug class (module)
	PF_DEBUG_LEVEL debugLevel; ///< Debug level
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
PF_STATUS PFAPI PfPrintLogMessage(const char* const pMessage);

/**
****************************************************************************************************
* @brief 	Interpret debug class to string
* @param 	[in] moduleClass Module debug class
* @return 	const C-style string with current module name
****************************************************************************************************
*/
const char* PfConvertDebugClassToString(PF_DEBUG_CLASS moduleClass);

/**
****************************************************************************************************
* @brief 	Convert time to C string for log message
* @return 	const C-style string with time after application was started
****************************************************************************************************
*/
const char* PfConvertTimeToString(void);

/**
****************************************************************************************************
*
****************************************************************************************************
*/
const char* PfConvertLevelToString(PF_DEBUG_LEVEL debugLevel);

#ifndef PF_DEBUG_CLASS_DEFAULT

/**
****************************************************************************************************
* @def 		PF_DEBUG_CLASS_DEFAULT
* @brief 	Specifies default module tag
****************************************************************************************************
*/
#define PF_DEBUG_CLASS_DEFAULT PF_DEBUG_CLASS_UNDEFINED
#endif /* !PF_DEBUG_CLASS_DEFAULT */

#ifndef PF_DEBUG_MESSAGE_SIZE
/**
****************************************************************************************************
* @def 		PF_DEBUG_MESSAGE_SIZE
* @brief 	Specifies debug message size. This parameter may be passed as external variable from
*	build system
****************************************************************************************************
*/
#define PF_DEBUG_MESSAGE_SIZE 256
#endif

#define PF_CONSTRUCT_MESSAGE(func, line, level, colorTag, format, args...) \
({ \
	char buffer[PF_DEBUG_MESSAGE_SIZE] = {0}; \
	int currentPosition = 0; \
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition, \
		colorTag "%s:", PfConvertTimeToString()); \
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition, \
		"[%s]", PfConvertDebugClassToString(PF_DEBUG_CLASS_DEFAULT)); \
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition, \
		"[%s]", PfConvertLevelToString(level)); \
	currentPosition += snprintf(buffer + currentPosition, PF_DEBUG_MESSAGE_SIZE - currentPosition, \
		"[%s:%d]" format "\033[0m", func, line, ##args); \
	buffer; \
})

/**
****************************************************************************************************
* @brief 	Print log message on information level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_I(format, args...) PfPrintLogMessage(PF_CONSTRUCT_MESSAGE(__FUNCTION__, __LINE__, \
	PF_DEBUG_LEVEL_INFO, "\033[32m", format, ##args))

/**
****************************************************************************************************
* @brief 	Print log message on warning level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_W(format, args...) PfPrintLogMessage(PF_CONSTRUCT_MESSAGE(__FUNCTION__, __LINE__, \
	PF_DEBUG_LEVEL_WARNING, "\033[33m", format, ##args))

/**
****************************************************************************************************
* @brief 	Print log message on error level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_E(format, args...) PfPrintLogMessage(PF_CONSTRUCT_MESSAGE(__FUNCTION__, __LINE__, \
	PF_DEBUG_LEVEL_ERROR, "\033[31m", format, ##args))

#endif	/* !_PF_DEBUG_H_ */