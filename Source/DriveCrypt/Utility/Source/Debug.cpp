#include "../Headers/stdafx.h"
#include "../Headers/Utility.h"
#include <iostream>

#ifdef UNICODE
void Debug::PrintLine(wstring value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}

void Debug::PrintLine(wstring& value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}
#else
void Debug::PrintLine(string value)
{
	cout << "A" << endl;
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}

void Debug::PrintLine(string& value)
{
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}
#endif