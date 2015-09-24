#pragma once
#include "Win32GUI.h"
#include <functional>

using namespace std;

typedef function<void(void)> FunctionHandler;

class EventHandler
{
public:
	static FunctionHandler& GetEmptyEvent();

protected:
	static FunctionHandler EmptyEvent;
};