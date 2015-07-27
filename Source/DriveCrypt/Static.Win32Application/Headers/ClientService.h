#pragma once

#include "../../Shared/ExportedHeaders/IFactory.h"
#include "../Headers/Environment.h"

template<>
class IFactory<ApplicationEnvironment>
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

template<typename T>
class ClientService
{
public:
	ClientService()
	{
		IFactory<T> a;
		this->param = a(); //Creator::Create<T>();
	}
protected:
	T* param;
};