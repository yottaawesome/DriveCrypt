#pragma once
#include "Common.h"
#include <string>

using namespace std;

class DynamicLibrary
{
	public:
		DynamicLibrary(wstring& str);
		DynamicLibrary(wstring&& str);

		template<typename T> T resolve(string& s);
		template<typename T> T resolve(string&& s);
		virtual void* resolve(wstring& s);
		virtual void* resolve(wstring&& s);
		virtual ~DynamicLibrary();

	protected:
		HINSTANCE handle;
		wstring libName;
};
