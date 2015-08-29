#pragma once
#include "Common.h"
#include "../../ComponentModel/Headers/IWin32Window.h"

#define MAX_LOADSTRING 100

class DriveCryptMainWindow : public IWin32Window 
{
public:
	DriveCryptMainWindow(IWin32Application* application);
	DriveCryptMainWindow(IWin32Application& application);

	virtual void Initialize() override;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void SetHwnd(HWND hWnd) override;
	virtual HWND GetHwnd() override;
private:
	HWND hWnd;
	IWin32Application* application;
	TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
	TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
};