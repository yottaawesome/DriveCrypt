// ComponentModel.cpp : Defines the exported functions for the DLL application.

#include "../Headers/stdafx.h"
#include "../Headers/ComponentModel.h"
#include <typeinfo>

IConsole::~IConsole() { }

IBasicFactory::~IBasicFactory() { };

map<size_t, IBasicFactory*>* ComponentFactory::Mapper = new map<size_t, IBasicFactory*>();
