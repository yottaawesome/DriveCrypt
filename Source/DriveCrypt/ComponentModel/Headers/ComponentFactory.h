#pragma once
#include "stdafx.h"
#include <map>

using namespace std;

class COMPONENTMODEL_API IBasicFactory
{
public:
	virtual void* Construct() = 0;
	virtual ~IBasicFactory() = 0;
};

template<typename T>
class IVirtualComponentFactory : public IBasicFactory
{
public:
	virtual T* operator() () = 0;
	virtual ~IVirtualComponentFactory() = 0;
};

template<typename T>
IVirtualComponentFactory<T>::~IVirtualComponentFactory() { }

class AB { };

template<typename T>
class SpecializedFactory
{
public:
	SpecializedFactory() { }
	virtual T* operator()() { return nullptr; };
};

template<typename T, typename R>
class PolyFactory
{
public:
	PolyFactory() { }
	virtual T* operator()() { return t(); };
protected:
	T t;
};

template<typename T>
class BasicComponentFactory : public IVirtualComponentFactory<T>
{
public:
	virtual T* operator() () { return nullptr; };
	virtual ~BasicComponentFactory() { };
};

class ComponentFactory
{
public:
	template<typename T>
	static void RegisterFactory(IVirtualComponentFactory<T>* factory);

	template<typename T>
	static T* Instantiate();

protected:
	COMPONENTMODEL_API static map<size_t, IBasicFactory*>* Mapper;
};

template<typename T>
T* ComponentFactory::Instantiate()
{
	IVirtualComponentFactory<T>* factory = (IVirtualComponentFactory<T>*)Mapper->at(typeid(T).hash_code());
	if (factory == nullptr)
	{
		string s1 = "Service resolution exception for type ";
		string s2 = typeid(T).name();
		throw new runtime_error(s1 + s2);
	}

	return (*factory)();
}

template<typename T>
void ComponentFactory::RegisterFactory(IVirtualComponentFactory<T>* factory)
{
	if (factory == nullptr)
	{
		string s = "Null service registration for type ";
		s += typeid(T).name();
		throw new runtime_error(s);
	}

	Mapper->insert(std::make_pair(typeid(T).hash_code(), (IBasicFactory*)factory));
}