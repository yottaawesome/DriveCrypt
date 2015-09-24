#include "../Headers/stdafx.h"
#include "../Headers/Button.h"
#include "../../Win32GUI/Headers/StaticFunctions.h"
#include  <Commctrl.h>

Button::Button(unsigned int controlId, wstring& text, FunctionHandler& onClick, unsigned int width, unsigned int height)
	: parent(nullptr), text(text), onClick(onClick), controlId(controlId), width(width), height(height)  
{
	width = width > 0 ? width : 100;
	height = height > 0 ? height : 100;
	if (text.length() == 0)
		this->text = L"Default";
}

void Button::Initialize(IWin32Window* parent)
{
	if (parent == nullptr) 
	{
		OutputDebugString(L"Cannot initialize a control without a parent");
		return;
	}
	this->parent = parent;

	HWND parentHwnd = parent->GetHwnd();
	hwndButton = CreateWindow
	(
		L"BUTTON",  // Predefined class; Unicode assumed 
		this->text.c_str(),      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		10,         // x position 
		10,         // y position 
		width,        // Button width
		height,        // Button height
		parentHwnd,     // Parent window
		(HMENU)controlId,       // No menu.
		(HINSTANCE)GetWindowLongPtr(parentHwnd, GWL_HINSTANCE),
		this
	);
	
	SetWindowSubclass(hwndButton, Static::DefCtrlProc, 0, (DWORD_PTR)this);
}

int Button::Process(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_LBUTTONUP:
			this->onClick();
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

Button::~Button() { }