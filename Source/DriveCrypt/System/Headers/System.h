#pragma once
#include <string>

// Import/export
#ifdef SYSTEM_EXPORTS
#define SYSTEM_API __declspec(dllexport)
#else
#define SYSTEM_API __declspec(dllimport)
#endif

using namespace std;

class SYSTEM_API SystemString
{
public:
	SystemString();
	SystemString(string s);
	SystemString(wstring s);
	virtual ~SystemString();

#ifdef UNICODE
	virtual wstring Get();
#elif
	virtual string Get();
#endif

	virtual wstring ToWString();
	virtual string ToString();
protected:
	wstring* wStr;
	string* str;
};

class SYSTEM_API IConsole
{
public:
#ifdef UNICODE
	virtual void Print(wstring value) = 0;
	virtual void Print(wstring& value) = 0;
	virtual void PrintLine(wstring value) = 0;
	virtual void PrintLine(wstring& value) = 0;
#else
	virtual void PrintLine(string value) = 0;
	virtual void PrintLine(string& value) = 0;
	virtual void Print(string value) = 0;
	virtual void Print(string& value) = 0;
#endif
	virtual ~IConsole() = 0;
};

class SYSTEM_API System final
{
public:
	static IConsole* GetConsole();
};