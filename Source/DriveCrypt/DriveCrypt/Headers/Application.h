#pragma once
#include <windows.h>
#include "Resource.h"
#include "targetver.h"

#define MAX_LOADSTRING 100

class Window
{
public:
	Window();
	void Show();
};

class IWin32Application
{
public:
	virtual int Initialize() = 0;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) = 0;
};

class Win32Application : public IWin32Application
{
public:
	static LRESULT CALLBACK	WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
protected:
	HWND hWnd;
};

class DriveCryptApplication : public Win32Application
{
public:
	DriveCryptApplication(HINSTANCE hinst, int nCmdShow);
	virtual int Initialize() override;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam);

protected:
	MSG msg;
	HACCEL hAccelTable;
	int nCmdShow;
	HINSTANCE hInstance;								// current instance
	TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

	ATOM MyRegisterClass(HINSTANCE hInstance);
	BOOL InitInstance(HINSTANCE, int);
	
	static INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
};