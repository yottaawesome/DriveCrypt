#pragma once
#include <string>

using namespace std;

// Import/export
#ifdef DIAGNOSTICS_EXPORTS
#define DIAGNOSTICS_API __declspec(dllexport)
#else
#define DIAGNOSTICS_API __declspec(dllimport)
#endif

class DIAGNOSTICS_API Debug final
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