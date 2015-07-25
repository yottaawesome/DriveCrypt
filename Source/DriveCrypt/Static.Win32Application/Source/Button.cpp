#include "../Headers/Common.h"
#include "IWin32Window.h"
#include "Button.h"
#include "../../Static.Win32Application/Headers/StaticFunctions.h"
#include  <Commctrl.h>
#include "../Headers/Variadic.h"

Button::Button(IWin32Window& parent, unsigned int controlId) : parent(parent), controlId(controlId) { }
Button::Button(IWin32Window* parent, unsigned int controlId) : parent(*parent), controlId(controlId)  { }
Button::Button(IWin32Window* parent, unsigned int controlId, unsigned int width, unsigned int height) : parent(*parent), controlId(controlId), width(width), height(height)  { }

void Button::Initialize()
{
	hwndButton = CreateWindow
	(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"OK",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		10,         // y position 
		100,        // Button width
		100,        // Button height
		parent.GetHwnd(),     // Parent window
		(HMENU)controlId,       // No menu.
		(HINSTANCE)GetWindowLong(parent.GetHwnd(), GWL_HINSTANCE),
		this
	);
	
	SetWindowSubclass(hwndButton, Static::DefCtrlProc, 0, (DWORD_PTR)this);
}

int Button::Process(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_LBUTTONUP:
			MessageBox(nullptr, L"Blah", L"Blah", MB_OK);
		default:
			return DefSubclassProc(hwndButton, message, wParam, lParam);
	}

	return DefSubclassProc(hwndButton, message, wParam, lParam);
}

void Button::SetHwnd(HWND hWnd)
{
	self.hwndButton = hWnd;
}

HWND Button::GetHwnd()
{
	return hwndButton;
}