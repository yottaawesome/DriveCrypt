#pragma once

#include "../Headers/ServiceFactories.h"
#include "../../Static.MemoryManagement/Headers/PointerWrapper.h"

template<typename T>
class ClientService
{
public:
	ClientService() : param(typeFactory()) { }

protected:
	static IFactory<T> typeFactory;
	PointerWrapper<T> param;
};

template<typename T>
IFactory<T> ClientService<T>::typeFactory = IFactory<T>();

class FactoryService
{
public:

protected:
	 static Factories TypeFactory;
};

Factories FactoryService::TypeFactory = Factories();