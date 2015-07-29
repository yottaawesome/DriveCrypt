#pragma once

#include "Common.h"
#include "IWin32Control.h"

template<typename T>
class IFactory
{
public:
	IFactory() {}
	virtual T* operator() () = 0;
};
