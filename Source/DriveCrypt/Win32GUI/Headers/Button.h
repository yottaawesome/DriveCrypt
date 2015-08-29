#pragma once
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../Headers/Win32GUI.h"

class WIN32GUI_API Button : public IButton
{
public:
	Button(IWin32Window& parent, unsigned int controlId);
	Button(IWin32Window* parent, unsigned int controlId);
	Button(IWin32Window* parent, unsigned int controlId, unsigned int width, unsigned int height);

	virtual void Initialize() override;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void SetHwnd(HWND hWnd) override;
	virtual HWND GetHwnd() override;
	
	virtual ~Button();

protected:
	HWND hwndButton;
	IWin32Window& parent;
	unsigned int const controlId;
	unsigned int width;
	unsigned int height;
};