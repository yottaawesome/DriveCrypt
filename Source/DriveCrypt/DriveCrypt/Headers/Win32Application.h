#pragma once

#include "Common.h"
#include "IWin32Application.h"

class Win32Application : public IWin32Application
{
public:
	virtual WNDPROC GetWindowMessagePump();
	virtual HINSTANCE GetInstance();
	virtual int GetCmdShow();

protected:
	int nCmdShow;
	HACCEL hAccelTable;
	HINSTANCE hInstance; // current instance
	MSG msg;

	virtual int MainLoop() override;
	static LRESULT CALLBACK	WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};