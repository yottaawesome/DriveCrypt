// ComponentModel.cpp : Defines the exported functions for the DLL application.

#include "../Headers/stdafx.h"
#include "../Headers/ComponentModel.h"
#include <typeinfo>

map<size_t, IBasicFactory*>* ComponentFactory::Mapper = new map<size_t, IBasicFactory*>();

inline IConsole::~IConsole() { }
inline IBasicFactory::~IBasicFactory() { };
inline IThread::~IThread() { };
inline IExecutionPackage::~IExecutionPackage() { }