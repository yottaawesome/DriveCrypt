#pragma once
#include "stdafx.h"
#include <string>
#include "../../ComponentModel/Headers/ComponentModel.h"

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

class SYSTEM_API ConsoleFactory : public IComponentFactory<IConsole>
{
public:
	virtual IConsole* operator() () override;
	virtual void* Construct() override;
	virtual ~ConsoleFactory(); 
};

class SYSTEM_API System final
{
public:
	static IConsole* GetConsole();
	static void Initialize();
};