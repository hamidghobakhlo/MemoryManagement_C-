#include <iostream>
#include "windows.h"
#include "stdlib.h"
#include "Winnetwk.h"

DWORDLONG MemoryLoad();

int main()
{
	printf("memory load = %u%% \n", MemoryLoad());
}

DWORDLONG MemoryLoad() {
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	DWORDLONG totalVirtMemory = memInfo.ullTotalPageFile;
	DWORDLONG VirtMemUsed = memInfo.ullTotalVirtual - memInfo.ullAvailVirtual;
	printf("size of memory = %I64u\nUsed space = %I64u\n", totalPhysMem, physMemUsed);
	printf("size of virtual memory = %I64u\nUsed space of virtual memory = %I64u\n", totalVirtMemory, VirtMemUsed);
	return memInfo.dwMemoryLoad;
}

