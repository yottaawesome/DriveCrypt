#pragma once

#include "Common.h"
#include "IWin32Application.h"

class COMPONENTMODEL_API IWin32Window
{
public:
	virtual void Initialize() = 0;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void SetHwnd(HWND hWnd) = 0;
	virtual HWND GetHwnd() = 0;
	virtual ~IWin32Window() = 0;
};

class COMPONENTMODEL_API IWin32Control : public IWin32Window
{
public:
	virtual ~IWin32Control() = 0;
};

class COMPONENTMODEL_API IButton : public IWin32Control
{
public:
	virtual ~IButton() = 0;
};