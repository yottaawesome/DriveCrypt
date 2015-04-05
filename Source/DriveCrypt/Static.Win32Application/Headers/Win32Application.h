#pragma once

#include "Common.h"
#include "IWin32Application.h"

/// Abstract base class for Win32 GUI Application
class Win32Application : public IWin32Application
{
public:
	virtual WNDPROC GetWindowMessagePump();
	virtual HINSTANCE GetInstance();
	virtual int GetCmdShow();

protected:
	int nCmdShow;
	HINSTANCE hInstance; // current instance
	MSG msg;

	virtual int MainLoop() override;
	virtual void LoadWin32Accelerators() = 0;
	virtual HACCEL GetAccelerator() = 0;
	static LRESULT CALLBACK	WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};