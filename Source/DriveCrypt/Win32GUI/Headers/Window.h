#pragma once
#include "Common.h"
#include "../Headers/Win32GUI.h"

#define MAX_LOADSTRING 100

class Window : public IWin32Window 
{
public:
	WIN32GUI_API Window(wstring& title, WNDPROC wndProc, HINSTANCE hInstance, unsigned int width = CW_USEDEFAULT, unsigned int height = 0);
	WIN32GUI_API Window(wstring&& title, WNDPROC wndProc, HINSTANCE hInstance, unsigned int width = CW_USEDEFAULT, unsigned int height = 0);

	WIN32GUI_API virtual void Initialize() override;
	WIN32GUI_API virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	WIN32GUI_API virtual void SetHwnd(HWND hWnd) override;
	WIN32GUI_API virtual HWND GetHwnd() override;

	WIN32GUI_API virtual void SetTitle(wstring&& title) override;
	WIN32GUI_API virtual void SetTitle(wstring& title) override;

	WIN32GUI_API virtual void AddControl(IWin32Control* control) override;

private:
	HWND hWnd;
	WNDPROC wndProc;
	HINSTANCE hInstance;
	IWin32Application* application;
	//TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	//TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
	wstring title = L"Default";
	unsigned int width;
	unsigned int height;
};