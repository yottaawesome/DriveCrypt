#pragma once
#include "stdafx.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
//#include "../../ComponentModel/Headers/IFactory.h"
#include "../Headers/Environment.h"

class AB { };

class A
{
public:
	A() { }

	virtual ~A()
	{
		OutputDebugString(L"Destroyed\n");
	}

	virtual void Blah()
	{
		OutputDebugString(L"Blah blah\n");
	}
};

template<typename T>
class SpecializedFactory
{
public:
	SpecializedFactory() { }
	virtual T* operator()() { };
};

template<>
class SpecializedFactory<AB>
{
public:
	SpecializedFactory()
	{
		MessageBox(nullptr, L"Blah", L"Blah", MB_OK);
	};

	virtual AB* operator()()
	{
		return new AB();
	};
};