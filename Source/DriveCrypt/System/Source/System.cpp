#include "../Headers/System.h"
#include "../Headers/Console.h"

IConsole* System::GetConsole()
{
	return new Console();
}