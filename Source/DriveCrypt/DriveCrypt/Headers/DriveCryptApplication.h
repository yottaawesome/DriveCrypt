#pragma once

#include "Common.h"
#include "IWin32Application.h"
#include "Win32Window.h"
#include "Win32Application.h"

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt(int nCmdShow);
	virtual void Initialize() override;

protected:
	Win32Window mainWindow;
};