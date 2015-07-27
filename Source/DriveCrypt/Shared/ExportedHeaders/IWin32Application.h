#pragma once
#include "Common.h"
#include  <Commctrl.h>

class IWin32Application
{
public:
	virtual void Initialize() = 0;
	virtual int MainLoop() = 0;
	virtual WNDPROC GetWindowMessagePump() = 0;
	virtual SUBCLASSPROC GetControlMessagePump() = 0;
	virtual HINSTANCE GetInstance() = 0;
};