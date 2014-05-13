/**
****************************************************************************************************
* @file 	PfDBus.c
* @brief 	Penguin Framework [PF] Data Bus interface implementation
* @ingroup	PfTransport
* @author	Maksym Koshel (maks.koshel@gmail.com)
* @date 	May 05, 2014
* @copyright Maksym Koshel (c) 2014. All rights reserved.
****************************************************************************************************
*/

#include "PfDBus.h"

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfOpenDBusControllerContext(PfDBusControllerContext* const pContext)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;

	return result;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PF_STATUS PFAPI PfCloseDBusControllerContext(PfDBusControllerContext* const pContext)
{
	PF_STATUS result = PF_STATUS_NOT_IMPLEMENTED;

	return result;
}

/*
****************************************************************************************************
*
****************************************************************************************************
*/
PfDBusNode* PFAPI CreateDBusNode(void)
{
	PfDbusNode* pDBusNode = NULL;
	pDBusNode = (PfDbusNode*) malloc(sizeof(PfDBusNode));

	if (NULL != pDBusNode)
	{
		
	}

	return pDBusNode;
}