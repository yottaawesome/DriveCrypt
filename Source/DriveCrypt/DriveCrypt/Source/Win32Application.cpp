#include "../Headers/Win32Application.h"
#include "../Headers/Win32Window.h"

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
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRIVECRYPT));

	return (int)msg.wParam;
}

LRESULT CALLBACK Win32Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	Win32Window* pThis = nullptr;

	if (message == WM_NCCREATE)
	{
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
		Win32Window* pThis = (Win32Window*)pCreate->lpCreateParams;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis);
		pThis->SetHwnd(hWnd);
	}
	else
	{
		pThis = (Win32Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	}

	if (pThis)
		return pThis->Process(message, wParam, lParam);
	else
		return DefWindowProc(hWnd, message, wParam, lParam);
}
