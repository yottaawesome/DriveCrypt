#pragma once

#include "Common.h"
#include "IWin32Application.h"

#define MAX_LOADSTRING 100

class Win32Window
{
public:
	Win32Window(IWin32Application& app);

	virtual void Initialize();
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam);
	virtual void SetHwnd(HWND hWnd);

protected:
	IWin32Application& app;
	TCHAR title[MAX_LOADSTRING];					// The title bar text
	TCHAR windowClass[MAX_LOADSTRING];			// the main window class name
	HWND hWnd;
	MSG msg;

	virtual ATOM RegisterWindowClass();
	virtual BOOL InitInstance();

	static INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
};