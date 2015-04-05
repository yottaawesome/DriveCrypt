#pragma once

#include "Common.h"
#include "IWin32Application.h"

#define MAX_LOADSTRING 100

class IWin32Window
{
public:
	virtual void Initialize() = 0;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void SetHwnd(HWND hWnd) = 0;
};