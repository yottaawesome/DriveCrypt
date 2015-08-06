// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"
#include "../Headers/Logger.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	Logger logger;
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			logger.PrintLine(L"Utility.dll -> PROCESS_ATTACH");
			break;
		case DLL_THREAD_ATTACH:
			logger.PrintLine(L"Utility.dll -> THREAD_ATTACH");
			break;
		case DLL_THREAD_DETACH:
			logger.PrintLine(L"Utility.dll -> THREAD_ATTACH");
			break;
		case DLL_PROCESS_DETACH:
			logger.PrintLine(L"Utility.dll -> PROCESS_DETACH");
			break;
	}
	return TRUE;
}