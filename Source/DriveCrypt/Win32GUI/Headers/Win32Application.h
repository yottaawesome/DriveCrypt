#pragma once

#include "Common.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../Headers/WIN32GUI.h"
#include  <Commctrl.h>

/// Abstract base class for Win32 GUI Application
class WIN32GUI_API Win32Application : public IWin32Application
{
public:
	virtual WNDPROC GetWindowMessagePump() override;
	virtual HINSTANCE GetInstance() override;
	virtual SUBCLASSPROC GetControlMessagePump() override;
	virtual int MainLoop() override;

protected:
	int nCmdShow;
	HINSTANCE hInstance; // current instance
	MSG msg;
	
	virtual void LoadWin32Accelerators() = 0;
	virtual HACCEL GetAccelerator() = 0;	
};