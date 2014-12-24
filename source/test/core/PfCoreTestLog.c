
#include "core/PfCore.h"
#include <stdlib.h>

static inline void PrintUsameMessage(void)
{
	PF_LOG_I("Usage example: PfCoreTestLog <PF_DEBUG_LEVEL value> <string>");
}

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		PrintUsameMessage();
	}
	else
	{
		int level = atoi(argv[1]);	
		switch(level)
		{
			case PF_DEBUG_LEVEL_ERROR:
				PF_LOG_E("%s", argv[2]);
			break;

			case PF_DEBUG_LEVEL_WARNING:
				PF_LOG_W("%s", argv[2]);
			break;

			case PF_DEBUG_LEVEL_INFO:
				PF_LOG_I("%s", argv[2]);
			break;

			default:
				PrintUsameMessage();
			break;
		}
	}

	return 0;
}