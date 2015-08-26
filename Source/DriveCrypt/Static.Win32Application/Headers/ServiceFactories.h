#pragma once
#include "stdafx.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
//#include "../../ComponentModel/Headers/IFactory.h"
#include "../Headers/Environment.h"

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