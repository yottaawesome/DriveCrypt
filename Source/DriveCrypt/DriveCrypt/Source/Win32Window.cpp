#include "../Headers/Common.h"
#include "../Headers/Win32Window.h"

/// Window
Win32Window::Win32Window(IWin32Application& app) : app(app)
{
}

int Win32Window::Process(UINT message, WPARAM wParam, LPARAM lParam)
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
					DialogBox(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
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

ATOM Win32Window::RegisterWindowClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = this->app.GetWindowMessagePump();
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = GetModuleHandle(nullptr);
	wcex.hIcon = LoadIcon(GetModuleHandle(nullptr), MAKEINTRESOURCE(IDI_DRIVECRYPT));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_DRIVECRYPT);
	wcex.lpszClassName = windowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

void Win32Window::SetHwnd(HWND hWnd)
{
	self.hWnd = hWnd;
}

BOOL Win32Window::InitInstance()
{
	hWnd = CreateWindow
	(
		windowClass,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		GetModuleHandle(nullptr),
		this
	);

	if (!hWnd)
		return FALSE;

	ShowWindow(hWnd, this->app.GetCmdShow());
	UpdateWindow(hWnd);

	return TRUE;
}

void Win32Window::Initialize()
{
	LoadString(GetModuleHandle(nullptr), IDS_APP_TITLE, title, MAX_LOADSTRING);
	LoadString(GetModuleHandle(nullptr), IDC_DRIVECRYPT, windowClass, MAX_LOADSTRING);
	RegisterWindowClass();

	// Perform application initialization:
	InitInstance();
}

INT_PTR CALLBACK Win32Window::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
		case WM_INITDIALOG:
			return (INT_PTR)TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
			{
				EndDialog(hDlg, LOWORD(wParam));
				return (INT_PTR)TRUE;
			}
			break;
	}
	return (INT_PTR)FALSE;
}
