// dllmain.cpp : Defines the entry point for the DLL application.
#include "../Headers/stdafx.h"
#include "../Headers/ReflectableFunction.h"
#include <locale>
#include <codecvt>

wstring SyString(string s)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return wstring(converter.from_bytes(s));
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	Invocable<void, int> f = [](int i) 
	{
	};
	f.Invoke(1);
	RT r;
	//r.f = ReflectableFunction<int, int>([](int i) -> int { return 1; });
	if(r.t(5) == 5)
		OutputDebugString(L"\nWorked\n");
	auto s = f.Typenames();
	for (unsigned int i = 0; i < s.size(); i++)
	{
		wstring w = SyString(s[i]);
		w += L"\n";
		OutputDebugString(w.c_str());
	}

	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			break;
	}
	return TRUE;
}