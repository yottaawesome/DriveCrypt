#pragma once
#include "Common.h"
#include "../Headers/Win32GUI.h"

#define MAX_LOADSTRING 100

class WIN32GUI_API DriveCryptMainWindow : public IWin32Window 
{
public:
	DriveCryptMainWindow(WNDPROC wndProc, HINSTANCE hInstance);

	virtual void Initialize() override;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void SetHwnd(HWND hWnd) override;
	virtual HWND GetHwnd() override;
private:
	HWND hWnd;
	WNDPROC wndProc;
	HINSTANCE hInstance;
	IWin32Application* application;
	TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
};