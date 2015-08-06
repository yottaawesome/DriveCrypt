// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"
#include "../../Utility/Headers/Utility.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			Console::PrintLine("Concurrency.dll -> PROCESS_ATTACH");
			return true;
		case DLL_THREAD_ATTACH:
			Console::PrintLine("Concurrency.dll -> THREAD_ATTACH");
			return true;
		case DLL_THREAD_DETACH:
			Console::PrintLine("Concurrency.dll -> PROCESS_DETACH");
			return true;
		case DLL_PROCESS_DETACH:
			Console::PrintLine("Concurrency.dll -> PROCESS_DETACH");
			return true;
	}
}
