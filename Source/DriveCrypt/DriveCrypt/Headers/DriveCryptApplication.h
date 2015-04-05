#pragma once

#include "Common.h"
#include "IWin32Application.h"
#include "Win32Window.h"
#include "../../Static.Win32Application/Headers/Win32Application.h"

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt(int nCmdShow);
	virtual void Initialize() override;

protected:
	HACCEL hAccelTable;

	Win32Window mainWindow;
	virtual HACCEL GetAccelerator() override;
	virtual void LoadWin32Accelerators() override;
};