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

	~A()
	{
		OutputDebugString(L"Destroyed\n");
	}

	void Blah()
	{
		OutputDebugString(L"Blah blah\n");
	}
};

//template<>
//class ITypeFactory<A>
//{
//public:
//	ITypeFactory()
//	{
//	}
//
//	virtual A* operator()()
//	{
//		return new A();
//	};
//};

//template<>
//class ITypeFactory<AB>
//{
//public:
//	ITypeFactory()
//	{
//		MessageBox(nullptr, L"Blah", L"Blah", MB_OK);
//	};
//
//	virtual AB* operator()()
//	{
//		return new AB();
//	};
//};
//
//template<>
//class ITypeFactory<ApplicationEnvironment>
//{
//public:
//	virtual ApplicationEnvironment* operator()()
//	{
//		return new ApplicationEnvironment();
//	};
//};