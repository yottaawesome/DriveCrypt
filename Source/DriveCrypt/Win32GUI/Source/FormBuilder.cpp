#include "../Headers/Win32GUI.h"
#include "../Headers/Window.h"
#include "../Headers/Button.h"
#include "../Headers/StaticFunctions.h"
#include "../Headers/Resource.h"

//TODO
IWin32Window* FormBuilder::CreateMainWindow(wstring& title, unsigned int width, unsigned int height)
{
	if(width > 0 && height > 0)
		return new Window(title, Static::WndProc, GetModuleHandle(nullptr), width, height);

	return new Window(title, Static::WndProc, GetModuleHandle(nullptr));
}

IWin32Window* FormBuilder::CreateMainWindow(wstring&& title, unsigned int width, unsigned int height)
{
	if (width > 0 && height > 0)
		return new Window(title, Static::WndProc, GetModuleHandle(nullptr), width, height);
	
	return new Window(title, Static::WndProc, GetModuleHandle(nullptr));
}

//TODO
FormBuilder::FormBuilder() { }

void FormBuilder::AddButton(IWin32Window* window, wstring& text, function<void(void)>& onClick, unsigned int width, unsigned int height)
{
	Button* button = new Button(ID_BUTTON1, text, onClick, width, height);
	window->AddControl(button);
}

void FormBuilder::AddButton(IWin32Window* window, wstring&& text, function<void(void)>& onClick, unsigned int width, unsigned int height)
{
	Button* button = new Button(ID_BUTTON1, text, onClick, width, height);
	window->AddControl(button);
}

FormBuilder::~FormBuilder() { }