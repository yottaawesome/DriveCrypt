#include "IWin32Window.h"
#include "../Headers/Win32Application.h"

/// Win32Application
HINSTANCE Win32Application::GetInstance()
{
	return this->hInstance;
}

int Win32Application::GetCmdShow()
{
	return this->nCmdShow;
}

WNDPROC Win32Application::GetWindowMessagePump()
{
	return Win32Application::WndProc;
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

LRESULT CALLBACK Win32Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	IWin32Window* pThis = nullptr;

	if (message == WM_NCCREATE)
	{
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
		IWin32Window* pThis = (IWin32Window*)pCreate->lpCreateParams;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis);
		pThis->SetHwnd(hWnd);
	}
	else
	{
		pThis = (IWin32Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	}

	return pThis ? pThis->Process(message, wParam, lParam) : DefWindowProc(hWnd, message, wParam, lParam);
}
