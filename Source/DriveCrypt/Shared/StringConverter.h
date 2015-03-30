#pragma once

//#include "stdafx.h"
#include <string>

using namespace std;

class StringConverter
{
public:
	static string convertWStringToString(wstring& stringToConvert);
	static string convertWStringToString(wstring&& stringToConvert);
	static wstring convertStringToWString(string& stringToConvert);
	static wstring convertStringToWString(string&& stringToConvert);
	//static wstring convertCharToWString(char* stringToConvert);
};