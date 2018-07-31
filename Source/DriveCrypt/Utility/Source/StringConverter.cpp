#include <string>
#include <locale>
#include <codecvt>
#include <memory>
#include <Windows.h>
#include "../Headers/Utility.h"

//codecvt_utf8_utf16 has been deprecated in C++17
string StringConverter::convertWStringToString(wstring& wstr)
{
	//static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	//return string(converter.to_bytes(stringToConvert));
	if (wstr.empty()) 
		return std::string();

	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	return strTo;
}

string StringConverter::convertWStringToString(wstring&& wstr)
{
	//static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	//return string(converter.to_bytes(stringToConvert));
	if (wstr.empty())
		return std::string();

	int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
	std::string strTo(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
	
	return strTo;
}

wstring StringConverter::convertStringToWString(string& str)
{
	//static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	//return wstring(converter.from_bytes(stringToConvert));

	if (str.empty()) 
		return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	
	return wstrTo;
}

wstring StringConverter::convertStringToWString(string&& str)
{
	//static wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
	//return wstring(converter.from_bytes(stringToConvert));

	if (str.empty()) 
		return std::wstring();
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
	std::wstring wstrTo(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
	
	return wstrTo;
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