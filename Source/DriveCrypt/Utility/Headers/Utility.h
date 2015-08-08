#pragma once

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the UTILITY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// UTILITY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef UTILITY_EXPORTS
#define UTILITY_API __declspec(dllexport)
#else
#define UTILITY_API __declspec(dllimport)
#endif

#include <string>

using namespace std;

class UTILITY_API StringConverter
{
public:
	static string convertWStringToString(wstring& stringToConvert);
	static string convertWStringToString(wstring&& stringToConvert);
	static wstring convertStringToWString(string& stringToConvert);
	static wstring convertStringToWString(string&& stringToConvert);
	//static wstring convertCharToWString(char* stringToConvert);
};

class UTILITY_API ILogger
{
public:
#ifdef UNICODE
	virtual void PrintLine(wstring value) = 0;
	virtual void PrintLine(wstring& value) = 0;
#else
	virtual void PrintLine(string value) = 0;
	virtual void PrintLine(string& value) = 0;
#endif
	virtual ~ILogger() = 0;
};

class UTILITY_API Debug final
{
public:
#ifdef UNICODE
	static void PrintLine(wstring value);
	static void PrintLine(wstring& value);
#else
	static void PrintLine(string value);
	static void PrintLine(string& value);
#endif

private:
	virtual void Abstract() = 0;
};

class UTILITY_API UtilityFactory final
{
public:
	static ILogger* ConstructLogger();
};