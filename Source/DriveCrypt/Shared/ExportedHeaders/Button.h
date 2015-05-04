#pragma once
#include "IWin32Control.h"

class Button : public IButton
{
public:
	Button(IWin32Window& parent, unsigned int controlId);
	Button(IWin32Window* parent, unsigned int controlId);
	Button(IWin32Window* parent, unsigned int controlId, unsigned int width, unsigned int height);

	virtual void Initialize() override;
	virtual int Process(UINT message, WPARAM wParam, LPARAM lParam) override;
	virtual void SetHwnd(HWND hWnd) override;
	virtual HWND GetHwnd() override;
	IWin32Window& parent;

protected:
	HWND hwndButton;
	unsigned int const controlId;
	unsigned int width;
	unsigned int height;
};