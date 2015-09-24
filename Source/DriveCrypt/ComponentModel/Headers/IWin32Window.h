#pragma once

#include "stdafx.h"
#include <string>
#include <functional>

using namespace std;

class COMPONENTMODEL_API IWin32Window;

class COMPONENTMODEL_API IWin32Control
{
public:
	virtual void Initialize(IWin32Window* window) = 0;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void SetHwnd(HWND hWnd) = 0;
	virtual HWND GetHwnd() = 0;
	virtual ~IWin32Control() = 0;
};

class COMPONENTMODEL_API IWin32Window
{
public:
	virtual void Initialize() = 0;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) = 0;
	virtual void SetHwnd(HWND hWnd) = 0;
	virtual HWND GetHwnd() = 0;
	virtual void AddControl(IWin32Control* control) = 0;
	virtual void SetTitle(wstring& title) = 0;
	virtual void SetTitle(wstring&& title) = 0;
	virtual ~IWin32Window() = 0;
};

class COMPONENTMODEL_API IButton : public IWin32Control
{
public:
	virtual ~IButton() = 0;
};

class COMPONENTMODEL_API IFormBuilder
{
public:
	virtual IWin32Window* CreateMainWindow(wstring& title, unsigned int width = 0, unsigned int height = 0) = 0;
	virtual IWin32Window* CreateMainWindow(wstring&& title, unsigned int width = 0, unsigned int height = 0) = 0;

	virtual void AddButton(IWin32Window* window, wstring& text, function<void(void)>& onClick, unsigned int width = 0, unsigned int height = 0) = 0;
	virtual void AddButton(IWin32Window* window, wstring&& text, function<void(void)>& onClick, unsigned int width = 0, unsigned int height = 0) = 0;

	virtual ~IFormBuilder() = 0;
};