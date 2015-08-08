#include "../Headers/System.h"

#include "../Headers/stdafx.h"
#include "../Headers/System.h"
#include <locale>
#include <codecvt>

SystemString::SystemString() : wStr(nullptr), str(nullptr)
{ }

SystemString::SystemString(string s) : wStr(nullptr), str(new string(s))
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	wStr = new wstring(converter.from_bytes(*str));
}

SystemString::SystemString(wstring s) : wStr(new wstring(s)), str(nullptr)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	str = new string(converter.to_bytes(*wStr));
}

SystemString::~SystemString()
{
	if (wStr != nullptr)
		delete wStr;
	if (str != nullptr)
		delete str;
}

wstring SystemString::ToWString()
{
	return wstring(*wStr);
}

string SystemString::ToString()
{
	return string(*str);
}

#ifdef UNICODE
wstring SystemString::Get()
{
	return wstring(*wStr);
}
#elif
string Get()
{
	return string(*str);
}
#endif