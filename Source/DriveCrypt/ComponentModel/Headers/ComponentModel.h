#pragma once
#include "stdafx.h"
#include <string>
#include <map>

#ifdef COMPONENTMODEL_EXPORTS
#define COMPONENTMODEL_API __declspec(dllexport)
#else
#define COMPONENTMODEL_API __declspec(dllimport)
#endif

using namespace std;

class COMPONENTMODEL_API IBasicFactory
{
public:
	virtual void* Construct() = 0;
	virtual ~IBasicFactory() = 0;
};

class COMPONENTMODEL_API IConsole
{
public:
#ifdef UNICODE
	virtual void Print(wstring value) = 0;
	virtual void Print(wstring& value) = 0;
	virtual void PrintLine(wstring value) = 0;
	virtual void PrintLine(wstring& value) = 0;
#else
	virtual void PrintLine(string value) = 0;
	virtual void PrintLine(string& value) = 0;
	virtual void Print(string value) = 0;
	virtual void Print(string& value) = 0;
#endif
	virtual ~IConsole() = 0;
};

template<typename T>
class COMPONENTMODEL_API IComponentFactory : public IBasicFactory
{
public:
	virtual T* operator() () = 0;
	virtual ~IComponentFactory() = 0;
};

//template<>
//class COMPONENTMODEL_API IComponentFactory<IConsole>
//{
//public:
//	virtual IConsole* operator() () = 0;
//	virtual ~IComponentFactory() = 0;
//};

// We need this due to the factories being defined in other DLLs
class COMPONENTMODEL_API IConsoleFactory : public IComponentFactory<IConsole> 
{
public:
	virtual ~IConsoleFactory() = 0;
};

class ComponentFactory
{
public:
	static COMPONENTMODEL_API void RegisterIConsoleFactory(IConsoleFactory* factory);

	template<typename T>
	static COMPONENTMODEL_API T* Instantiate();
	template<>
	static COMPONENTMODEL_API IConsole* Instantiate<IConsole>();
protected:
	static map<size_t, IBasicFactory*>* Mapper;
};