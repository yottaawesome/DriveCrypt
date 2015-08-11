#include "../Headers/Console.h"

IConsole* System::GetConsole()
{
	return new Console();
}

void System::Initialize()
{
	ComponentFactory::RegisterFactory(new ConsoleFactory());
	//ComponentFactory2::RegisterFactory(new ConsoleFactory2());
}