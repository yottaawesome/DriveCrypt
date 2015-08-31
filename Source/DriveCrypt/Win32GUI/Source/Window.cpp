#include "../Headers/stdafx.h"
#include "../Headers/Resource.h"
#include "../Headers/Window.h"
#include "../Headers/WindowClassManager.h"

using namespace std;

Window::Window(wstring& title, WNDPROC wndProc, HINSTANCE hInstance, unsigned int width, unsigned int height)
	: width(width), height(height), title(title), wndProc(wndProc), hInstance(hInstance) { }

Window::Window(wstring&& title, WNDPROC wndProc, HINSTANCE hInstance, unsigned int width, unsigned int height)
	: width(width), height(height), title(title), wndProc(wndProc), hInstance(hInstance) { }

void Window::SetTitle(wstring& title)
{
	this->title = title;
	SetWindowText(hWnd, this->title.c_str());
}

void Window::SetTitle(wstring&& title)
{
	this->title = title;
	SetWindowText(hWnd, this->title.c_str());
}

void Window::Initialize()
{
	//LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	//LoadString(hInstance, IDC_DRIVECRYPT, szWindowClass, MAX_LOADSTRING);

	auto wcex = WindowClassManager::GetDefaultWindowClass();

	hWnd = CreateWindow
		(
			wcex.ClassName.c_str(), // class name
			title.c_str(), // window title
			WS_OVERLAPPEDWINDOW, // window styles
			CW_USEDEFAULT, // initial horizontal x position
			0,  // initial horizontal y position
			width,  // window width
			height, // window height
			NULL, // parent HWND
			NULL, // HWND menu/child
			hInstance, // instance of the module
			this // additional data
		);

	if (!hWnd)
		return;

	// See https://msdn.microsoft.com/en-us/library/windows/desktop/ms633548%28v=vs.85%29.aspx
	ShowWindow(hWnd, SW_SHOWDEFAULT);
	UpdateWindow(hWnd);
}

void Window::AddControl(IWin32Control* control)
{
	if(control != nullptr)
		control->Initialize(this);
}

int Window::Process(UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			//DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void Window::SetHwnd(HWND hWnd)
{
	this->hWnd = hWnd;
}

HWND Window::GetHwnd()
{
	return this->hWnd;
}