// ComponentModel.cpp : Defines the exported functions for the DLL application.

#include "../Headers/stdafx.h"
#include "../Headers/ComponentModel.h"
#include "../Headers/IWin32Window.h"
#include <typeinfo>

map<size_t, IBasicFactory*>* ComponentFactory::Mapper = new map<size_t, IBasicFactory*>();

inline IConsole::~IConsole() { }
inline IBasicFactory::~IBasicFactory() { };
inline IThread::~IThread() { };
inline IExecutionPackage::~IExecutionPackage() { }
inline IWin32Control::~IWin32Control() { }
inline IButton::~IButton() { }
inline IWin32Window::~IWin32Window() { };
inline IWin32Application::~IWin32Application() { };