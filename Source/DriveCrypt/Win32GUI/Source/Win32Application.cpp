#include "../../ComponentModel/Headers/IWin32Window.h"
#include "../Headers/Win32Application.h"
#include "../Headers/StaticFunctions.h"
#include "../../System/Headers/PointerWrapper.h"
#include  <Commctrl.h>

/// Win32Application
HINSTANCE Win32Application::GetInstance()
{
	return this->hInstance;
}

WNDPROC Win32Application::GetWindowMessagePump()
{
	return Static::WndProc;
}

int Win32Application::MainLoop()
{
	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, this->GetAccelerator(), &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	this->LoadWin32Accelerators();

	return (int)msg.wParam;
}

SUBCLASSPROC Win32Application::GetControlMessagePump()
{
	return Static::DefCtrlProc;
}