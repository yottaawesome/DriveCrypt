#pragma once

#include "Common.h"
#include "IWin32Application.h"
#include  <Commctrl.h>

/// Abstract base class for Win32 GUI Application
class Win32Application : public IWin32Application
{
public:
	virtual WNDPROC GetWindowMessagePump() override;
	virtual HINSTANCE GetInstance() override;
	virtual int GetCmdShow() override;
	virtual SUBCLASSPROC GetControlMessagePump() override;

	//static LRESULT CALLBACK	WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	//static LRESULT CALLBACK DefCtrlProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

protected:
	int nCmdShow;
	HINSTANCE hInstance; // current instance
	MSG msg;

	virtual int MainLoop() override;
	virtual void LoadWin32Accelerators() = 0;
	virtual HACCEL GetAccelerator() = 0;	
};