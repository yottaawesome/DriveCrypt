#pragma once
#include "stdafx.h"
#include <string>

using namespace std;

class COMPONENTMODEL_API IConsole
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