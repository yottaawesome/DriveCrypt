#pragma once
#include "stdafx.h"
#include "Win32GUI.h"

enum WIN32GUI_API WindowClassTypes
{
	DEFAULT
};

struct WindowClass 
{
	WNDCLASSEX WndClass;
	wstring ClassName;
};

class WindowClassManager 
{
public:
	WIN32GUI_API static WindowClass GetDefaultWindowClass();

protected:
	static WindowClass DefaultWindowClass;
};