// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"
#include "../Headers/Win32GUI.h"

class X
{
public:
	int i = 1;
	void operator=(X x)
	{
		OutputDebugString(L"\nYep\n");
		x.i++;
	}
};

class Y
{
public:
	Y() : public_x(protected_x) { }

	const X& public_x;

	void G()
	{
		protected_x = X();
	}
protected:
	X protected_x;
};

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	Y y = Y();
	y.G();
	OutputDebugString(L"\nYeeeeeeeeeeeeeeeeeeeeeeeeeeep\n");

	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			OutputDebugString(L"\nYeah!.dll -> PROCESS_ATTACH");
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}
