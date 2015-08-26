#pragma once
#include "stdafx.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "Console.h"

class ConsolePolyFactory
{
public:
	ConsolePolyFactory();
	virtual IConsole* operator()();
};