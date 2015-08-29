#include "../Headers/Win32GUI.h"
#include "../Headers/DriveCryptMainWindow.h"
#include "../Headers/StaticFunctions.h"

//TODO
IWin32Window* FormBuilder::CreateMainWindow()
{
	return new DriveCryptMainWindow(Static::WndProc, GetModuleHandle(nullptr));
}

//TODO
void FormBuilder::AddButton(IWin32Window* window) { }

FormBuilder::~FormBuilder() { }