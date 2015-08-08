#include "../Headers/Concurrency.h"

Runnable::Runnable(function<int()> func, bool runImmediately) : Thread(this, runImmediately, false), func(func) { }

Runnable::Runnable(int (*simpleFunc)(), bool runImmediately) : Thread(this, runImmediately, false), func(simpleFunc) { }

int Runnable::run()
{
	return func();
}

void Runnable::RunThread(int(*simpleFunc)())
{
	auto r = Runnable(simpleFunc, true);
}

void Runnable::RunThread(function<int()> func)
{
	auto r = Runnable(func, true);
}