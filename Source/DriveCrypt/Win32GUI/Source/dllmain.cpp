// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"
#include "../Headers/Win32GUI.h"

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			OutputDebugString(L"\nWin32GUI.dll -> PROCESS_ATTACH\n");
			break;

		case DLL_THREAD_ATTACH:
			OutputDebugString(L"\nWin32GUI.dll -> THREAD_ATTACH\n");
			break;

		case DLL_THREAD_DETACH:
			OutputDebugString(L"\nWin32GUI.dll -> THREAD_DETACH\n");
			break;

		case DLL_PROCESS_DETACH:
			OutputDebugString(L"\nWin32GUI.dll -> PROCESS_DETACH\n");
			break;
	}
	return TRUE;
}
