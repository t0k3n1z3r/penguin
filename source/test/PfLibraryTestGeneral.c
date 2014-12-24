
#include "core/PfCore.h"
#include <dlfcn.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	PF_STATUS result = PF_STATUS_FAIL;

	void* pHandle = dlopen(argv[1], RTLD_LAZY);

	if (NULL != pHandle)
	{
		result = PF_STATUS_OK;
		dlclose(pHandle);
	}

	return result;
}