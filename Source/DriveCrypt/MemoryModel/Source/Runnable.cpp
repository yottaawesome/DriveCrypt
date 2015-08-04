#include "../Headers/Thread.h"

Runnable::Runnable(function<int()> func) : Thread(this, false), func(func) { }

int Runnable::run()
{
	return func();
}