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
class IComponentFactory : public IBasicFactory
{
public:
	virtual T* operator() () = 0;
	virtual ~IComponentFactory() = 0;
};

template<typename T>
IComponentFactory<T>::~IComponentFactory() { }

class ComponentFactory
{
public:
	template<typename T>
	static void RegisterFactory(IComponentFactory<T>* factory);
	
	template<typename T>
	static T* Instantiate();

protected:
	COMPONENTMODEL_API static map<size_t, IBasicFactory*>* Mapper;
};

template<typename T>
T* ComponentFactory::Instantiate()
{
	IComponentFactory<T>* factory = (IComponentFactory<T>*)Mapper->at(typeid(T).hash_code());
	if (factory == nullptr)
	{
		string s1 = "Service resolution exception for type ";
		string s2 = typeid(T).name();
		throw new runtime_error(s1 + s2);
	}

	return (*factory)();
}

template<typename T>
void ComponentFactory::RegisterFactory(IComponentFactory<T>* factory)
{
	if (factory == nullptr)
	{
		string s = "Null service registration for type ";
		s += typeid(IConsole).name();
		throw new runtime_error(s);
	}

	Mapper->insert(std::make_pair(typeid(IConsole).hash_code(), (IBasicFactory*)factory));
}