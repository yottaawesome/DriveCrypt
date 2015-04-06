#pragma once

#include "Common.h"
#include "IWin32Control.h"

template<typename T>
class IFactory
{
public:
	virtual T operator() () = 0;
};

//class UIFactory
//{
//public:
//	virtual IWin32Control CreateButton();
//};