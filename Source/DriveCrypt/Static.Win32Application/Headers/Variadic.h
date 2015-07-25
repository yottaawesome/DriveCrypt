#pragma once

#include "Common.h"
#include "../Headers/Win32Application.h"
#include "IFactory.h"

template<typename... T>
class Injectable
{
public:
	Injectable(T... Params) 
	{
	}
};

class A
{
};

class Creator
{
public:
	template<typename T>
	static T Create() 
	{ 
		return new T() 
	};
};

template<typename T>
class SimpleInjectable
{
public:
	SimpleInjectable()
	{
		IFactory<T> a;
		this->param = a(); //Creator::Create<T>();
	}
protected:
	T* param;
};

class X : SimpleInjectable<AB>
{
public:
	X();
};

X::X()
{

}