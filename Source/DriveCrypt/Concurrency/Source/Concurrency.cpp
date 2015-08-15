// Concurrency.cpp : Defines the exported functions for the DLL application.
//

#include "../Headers/stdafx.h"
#include "../Headers/Concurrency.h"

IThread* ThreadFactory::operator()() 
{ 
	return new Thread(nullptr, false);
};

void* ThreadFactory::Construct() 
{
	return new Thread(nullptr, false);
}

ThreadFactory::~ThreadFactory() { }

void Concurrency::Initialize()
{
	ComponentFactory::RegisterFactory<IThread>(new ThreadFactory());
}