// ComponentModel.cpp : Defines the exported functions for the DLL application.
//

#include "../Headers/stdafx.h"
#include "../Headers/ComponentModel.h"
#include <typeinfo>

using namespace std;

IConsole::~IConsole() { }

IBasicFactory::~IBasicFactory() { };

template<typename T>
IComponentFactory<T>::~IComponentFactory() { }

IConsoleFactory::~IConsoleFactory() {  }

map<size_t, IBasicFactory*>* ComponentFactory::Mapper = new map<size_t, IBasicFactory*>();

void ComponentFactory::RegisterIConsoleFactory(IConsoleFactory* factory)
{
	if (factory == nullptr) 
	{
		string s = "Null service registration for type ";
		s += typeid(IConsole).name();
		throw new runtime_error(s);
	}

	Mapper->insert(std::make_pair(typeid(IConsole).hash_code(), (IBasicFactory*)factory));
}

template<typename T>
T* ComponentFactory::Instantiate()
{
	IComponentFactory<T>* factory = Mapper[typeid(T).hash_code()];
	if (factory == nullptr)
		throw new runtime_error("Service resolution exception for type " + typeid(T).name());
	
	return factory();
}

template<>
IConsole* ComponentFactory::Instantiate<IConsole>()
{
	IComponentFactory<IConsole>* factory = (IComponentFactory<IConsole>*)Mapper->at(typeid(IConsole).hash_code());
	//if (factory == nullptr)
	//	throw new runtime_error("Service resolution exception for type " + typeid(IConsole).name());

	return (*factory)();
}