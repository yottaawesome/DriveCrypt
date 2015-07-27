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
	virtual SUBCLASSPROC GetControlMessagePump() override;

protected:
	int nCmdShow;
	HINSTANCE hInstance; // current instance
	MSG msg;

	virtual int MainLoop() override;
	virtual void LoadWin32Accelerators() = 0;
	virtual HACCEL GetAccelerator() = 0;	
};