#include "../Headers/stdafx.h"
#include "../Headers/Logger.h"

Logger::~Logger() { }

//use std::to_wstring(value) to convert numbers to strings

void Logger::PrintLine(string value)
{
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}

void Logger::PrintLine(wstring value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}

void Logger::PrintLine(string& value)
{
	value.append("\n");
	OutputDebugString(StringConverter::convertStringToWString(value).c_str());
}

void Logger::PrintLine(wstring& value)
{
	value.append(L"\n");
	OutputDebugString(value.c_str());
}
