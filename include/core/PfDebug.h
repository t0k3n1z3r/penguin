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
* @enum 	PF_DEBUG_COLOR
* @brief 	This enum defines color number may be used by the log system.
****************************************************************************************************
*/
typedef enum
{
	PF_DEBUG_COLOR_BLACK 		= 30, ///< Black color number
	PF_DEBUG_COLOR_RED 			= 31, ///< Red color number
	PF_DEBUG_COLOR_GREEN 		= 32, ///< Green color number
	PF_DEBUG_COLOR_YELLOW 		= 33, ///< Yellow color number
	PF_DEBUG_COLOR_BLUE 		= 34, ///< Blue color number
	PF_DEBUG_COLOR_MAGENTA 		= 35, ///< Magenta color number
	PF_DEBUG_COLOR_CYAN 		= 36, ///< Cyan color number
	PF_DEBUG_COLOR_WHITE 		= 37  ///< White color number

} PF_DEBUG_COLOR;

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
	/**
	* @brief 	Header structure of the debug context.
	*/
	PfHeader header;

	/**
	* @brief 	Debug class to be selected for output message using debug context structure.
	*/
	PF_DEBUG_CLASS debugClass;

	/**
	* @brief 	Debug level to be selected and filtered message using debug context structure.
	*/
	PF_DEBUG_LEVEL debugLevel;

	/**
	* @brief 	Message color for debug messages.
	*/
	PF_DEBUG_COLOR debugColor;

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
* @ingroup 	PfCore
* @param 	[in] pFunctionName Pointer to the string with function name where message will be
*			printed.
* @param 	[in] lineNumber Line number of the function called.
* @param 	[in] debugClass Debug class related to the message going to be printed.
* @param 	[in] debugLevel Debug level related to the message going to be printed.
* @param 	[in] pFormatMessage Pointer to the format string.
* @param 	[in] ... Arguments will be passed to message construction routines.
* @return 	SF_STATUS_OK on success, SF_STATUS_FAIL otherwise.
****************************************************************************************************
*/
PF_STATUS PFAPI PfPrintLogMessage(const char* const pFunctionName, const int lineNumber,
	PF_DEBUG_CLASS debugClass, PF_DEBUG_LEVEL debugLevel, const char* const pFormatMessage, ...);

#ifndef PF_DEBUG_CLASS_DEFAULT

/**
****************************************************************************************************
* @def 		PF_DEBUG_CLASS_DEFAULT
* @brief 	Specifies default module tag
* @note 	PF_DEBUG_CLASS_DEFAULT designed to be set in the make file
****************************************************************************************************
*/
#define PF_DEBUG_CLASS_DEFAULT PF_DEBUG_CLASS_UNDEFINED
#endif /* !PF_DEBUG_CLASS_DEFAULT */

/**
****************************************************************************************************
* @brief 	Print log message on information level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_I(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
													PF_DEBUG_CLASS_DEFAULT, PF_DEBUG_LEVEL_INFO, \
													format, ##args)

/**
****************************************************************************************************
* @brief 	Print log message on warning level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_W(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
													PF_DEBUG_CLASS_DEFAULT, PF_DEBUG_LEVEL_WARNING,\
													format, ##args)

/**
****************************************************************************************************
* @brief 	Print log message on error level
* @param 	[in] debugClass module tag
****************************************************************************************************
*/
#define PF_LOG_E(format, args...) PfPrintLogMessage(__FUNCTION__, __LINE__, \
													PF_DEBUG_CLASS_DEFAULT, PF_DEBUG_LEVEL_ERROR, \
													format, ##args)

#endif	/* !_PF_DEBUG_H_ */