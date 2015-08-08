#pragma once

#include "Utility.h"
#include <string>

using namespace std;

class Logger : public ILogger
{
public:
#ifdef UNICODE
	virtual void PrintLine(wstring value) override;
	virtual void PrintLine(wstring& value) override;
#else
	virtual void PrintLine(string value) override;
	virtual void PrintLine(string& value) override;
#endif

	virtual ~Logger();
};