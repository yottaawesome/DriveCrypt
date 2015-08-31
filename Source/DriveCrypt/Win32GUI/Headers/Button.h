#pragma once
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../Headers/Win32GUI.h"

class Button : public IButton
{
public:
	WIN32GUI_API Button(unsigned int controlId, wstring& text, void (*onClick)(), unsigned int width, unsigned int height);

	WIN32GUI_API virtual void Initialize(IWin32Window* parent) override;
	WIN32GUI_API virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	WIN32GUI_API virtual void SetHwnd(HWND hWnd) override;
	WIN32GUI_API virtual HWND GetHwnd() override;
	
	WIN32GUI_API virtual ~Button();

protected:
	HWND hwndButton;
	IWin32Window* parent;
	wstring text;
	unsigned int const controlId;
	unsigned int width;
	unsigned int height;
	void (*onClick)();
};