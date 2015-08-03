// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		OutputDebugString(L"DLL process attached\n");
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		OutputDebugString(L"DLL process detached\n");
		break;
	}
	return TRUE;
}

