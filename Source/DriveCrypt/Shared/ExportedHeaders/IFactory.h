#pragma once

#include "Common.h"
#include "IWin32Control.h"

class AB { };

template<typename T>
class IFactory
{
public:
	IFactory() {}
	virtual T* operator() () = 0;
};

template<>
class IFactory<AB>
{
public: 
	IFactory()
	{
		MessageBox(nullptr, L"Blah", L"Blah", MB_OK);
	};

	virtual AB* operator()()
	{ 
		return new AB(); 
	};
};
