#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

namespace Infrastructure
{
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
}
