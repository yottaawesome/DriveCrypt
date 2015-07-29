#pragma once
#include "../../Shared/ExportedHeaders/IFactory.h"
#include "../Headers/Environment.h"

class AB { };

class A
{
public:
	A() { }

	~A()
	{
		OutputDebugString(_T("Destroyed\n"));
	}

	void Blah()
	{
		OutputDebugString(_T("Blah blah\n"));
	}
};

template<>
class IFactory<A>
{
public:
	IFactory()
	{
	}

	virtual A* operator()()
	{
		return new A();
	};
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

template<>
class IFactory<ApplicationEnvironment>
{
public:
	virtual ApplicationEnvironment* operator()()
	{
		return new ApplicationEnvironment();
	};
};