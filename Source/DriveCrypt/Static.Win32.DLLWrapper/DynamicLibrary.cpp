//#include "stdafx.h"
#include <string>
#include "../Shared/ExportedHeaders/DynamicLibrary.h"
#include "../Utility/Headers/Utility.h"

using namespace std;

DynamicLibrary::DynamicLibrary(wstring& str)
	: libName(str)
{
	this->handle = LoadLibrary(str.c_str());
	if (handle == nullptr)
		throw runtime_error("Could not load library");
}

DynamicLibrary::DynamicLibrary(wstring&& str)
	: libName(std::move(str))
{
	this->handle = LoadLibrary(libName.c_str());
	if (handle == nullptr)
		throw runtime_error("Could not load library");
}

template <typename T>
T DynamicLibrary::resolve(string& s)
{
	return (T)GetProcAddress(this->handle, s.c_str());
}

template <typename T>
T DynamicLibrary::resolve(string&& s)
{
	return (T)GetProcAddress(this->handle, s.c_str());
}

void* DynamicLibrary::resolve(wstring& s)
{
	return GetProcAddress(this->handle, StringConverter::convertWStringToString(s).c_str());
}

void* DynamicLibrary::resolve(wstring&& s)
{
	return GetProcAddress(this->handle, StringConverter::convertWStringToString(s).c_str());
}

DynamicLibrary::~DynamicLibrary()
{
	FreeLibrary(this->handle);
}