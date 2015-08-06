#pragma once

#include "Utility.h"
#include <string>

using namespace std;

class Logger : public ILogger
{
public:
	virtual void PrintLine(string value) override;
	virtual void PrintLine(wstring value) override;
	virtual void PrintLine(string& value) override;
	virtual void PrintLine(wstring& value) override;

	virtual ~Logger();
};