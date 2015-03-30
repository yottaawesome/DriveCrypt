#include "stdafx.h"
#include <string>
#include <locale>
#include <codecvt>
#include <memory>
#include "StringConverter.h"

using namespace std;

string StringConverter::convertWStringToString(wstring& stringToConvert)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return string(converter.to_bytes(stringToConvert));
}

string StringConverter::convertWStringToString(wstring&& stringToConvert)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return string(converter.to_bytes(stringToConvert));
}

wstring StringConverter::convertStringToWString(string& stringToConvert)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return wstring(converter.from_bytes(stringToConvert));
}

wstring StringConverter::convertStringToWString(string&& stringToConvert)
{
	static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	return wstring(converter.from_bytes(stringToConvert));
}

/*wstring StringConverter::convertCharToWString(char* stringToConvert)
{
//Adapted from: http://msdn.microsoft.com/en-us/library/ms235631.aspx
// newsize describes the length of the
// wchar_t string called wcstring in terms of the number
// of wide characters, not the number of bytes.
size_t newsize = strlen(stringToConvert) + 1;

// The following creates a buffer large enough to contain
// the exact number of characters in the original string
// in the new format. If you want to add more characters
// to the end of the string, increase the value of newsize
// to increase the size of the buffer.
unique_ptr<wchar_t[]> wcstring(new wchar_t[newsize]);
wcstring.get();

// Convert char* string to a wchar_t* string.
size_t convertedChars = 0;
mbstowcs_s(&convertedChars, wcstring.get(), newsize, stringToConvert, _TRUNCATE);

return wstring(wcstring.get());
}*/