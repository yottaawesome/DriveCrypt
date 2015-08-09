#include "../Headers/System.h"
#include "../Headers/Console.h"

IConsole* ConsoleFactory::operator() ()
{
	return new Console();
};

void* ConsoleFactory::Construct()
{
	return (void*)new Console();
}

ConsoleFactory::~ConsoleFactory()
{
}