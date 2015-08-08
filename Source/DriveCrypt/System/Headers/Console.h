#pragma once

#include "../Headers/System.h"
#include "../../Concurrency/Headers/Concurrency.h"
#include <string>

using namespace std;

class Console : public IConsole
{
public:
	Console();
	virtual ~Console();
	virtual void Free();

#ifdef UNICODE
	virtual void Print(wstring value) override;
	virtual void Print(wstring& value) override;
	virtual void PrintLine(wstring value) override;
	virtual void PrintLine(wstring& value) override;
#else
	virtual void Print(string value) override;
	virtual void Print(string& value) override;
	virtual void PrintLine(string value) override;
	virtual void PrintLine(string& value) override;
#endif

protected:
	static bool ConsoleCreated;
	static CriticalSection SectionLock;
	virtual void InternalPrint(wstring& value);
};