#include "../../ComponentModel/Headers/IWin32Window.h"
#include "../Headers/Common.h"
#include "../Headers/StaticFunctions.h"
#include  <Commctrl.h>

LRESULT CALLBACK Static::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	IWin32Window* pThis = nullptr;

	if (message == WM_NCCREATE)
	{
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
		IWin32Window* pThis = (IWin32Window*)pCreate->lpCreateParams;
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pThis);
		pThis->SetHwnd(hWnd);
	}
	else
	{
		pThis = (IWin32Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	}

	return pThis ? pThis->Process(message, wParam, lParam) : DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK Static::DefCtrlProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
	IWin32Window* btn = (IWin32Window*)dwRefData;

	if (btn)
		return btn->Process(message, wParam, lParam);

	return DefSubclassProc(hWnd, message, wParam, lParam);
}