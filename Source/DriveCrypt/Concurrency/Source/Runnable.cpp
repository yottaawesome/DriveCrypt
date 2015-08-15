#include "../Headers/Concurrency.h"

Runnable::Runnable(IExecutionPackage* executionPackage) : Thread(this, false), executionPackage(executionPackage) { }

Runnable::Runnable(function<int()> func) : Thread(this, false), executionPackage(nullptr), func(func) { }

Runnable::Runnable(int (*simpleFunc)()) : Thread(this, false), executionPackage(nullptr), func(simpleFunc) { }

int Runnable::run()
{
	if (executionPackage != nullptr)
		return executionPackage->Run();
	return func();
}

void Runnable::RunThread(int(*simpleFunc)())
{
	auto r = Runnable(simpleFunc);
}

void Runnable::RunThread(function<int()> func)
{
	auto r = Runnable(func);
}