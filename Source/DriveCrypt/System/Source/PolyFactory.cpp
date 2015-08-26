#include "../Headers/System.h"
#include "../Headers/PolyFactory.h"

ConsolePolyFactory::ConsolePolyFactory() { }

IConsole* ConsolePolyFactory::operator()() { return new Console(); };