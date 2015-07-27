#include "..\Headers\DriveCryptMainWindow.h"
#include "../Headers/Exceptions.h"

using namespace std;

DriveCryptMainWindow::DriveCryptMainWindow(IWin32Application* application) : application(application)
{
	if (application == nullptr)
		throw DriveCryptException("Null Application pointer to Main Window");
}

DriveCryptMainWindow::DriveCryptMainWindow(IWin32Application& application) : application(&application)
{
}

void DriveCryptMainWindow::Initialize()
{
	auto hInstance = this->application->GetInstance();
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRIVECRYPT, szWindowClass, MAX_LOADSTRING);

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = this->application->GetWindowMessagePump();
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRIVECRYPT));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRIVECRYPT);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassEx(&wcex);

	hWnd = CreateWindow
		(
			szWindowClass, // class name
			szTitle, // window title
			WS_OVERLAPPEDWINDOW, // window styles
			CW_USEDEFAULT, // initial horizontal x position
			0,  // initial horizontal y position
			CW_USEDEFAULT,  // window width
			0, // window width
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

int DriveCryptMainWindow::Process(UINT message, WPARAM wParam, LPARAM lParam)
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

void DriveCryptMainWindow::SetHwnd(HWND hWnd)
{
	this->hWnd = hWnd;
}

HWND DriveCryptMainWindow::GetHwnd()
{
	return this->hWnd;
}