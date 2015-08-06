#include "../Headers/stdafx.h"
#include "../Headers/Utility.h"

UTILITY_API void Console::PrintLine(string value)
{
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}

void Console::PrintLine(wstring value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}

void Console::PrintLine(string& value)
{
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}

void Console::PrintLine(wstring& value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}

void V::X()
{

}