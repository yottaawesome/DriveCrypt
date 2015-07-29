#pragma once

#include "Common.h"

template<typename T>
class IFactory
{
public:
	virtual T* operator() () = 0;
};

class Factories
{
public:
	template<typename T>
	IFactory<T> Get() 
	{ 
		return IFactory<T>(); 
	}
};