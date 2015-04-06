#pragma once

#include "Common.h"
#include "IWin32Application.h"
#include "DriveCryptMainWindow.h"
#include "../../Static.Win32Application/Headers/Win32Application.h"

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt(int nCmdShow);
	virtual void Initialize() override;

protected:
	HACCEL hAccelTable;

	DriveCryptMainWindow mainWindow;
	virtual HACCEL GetAccelerator() override;
	virtual void LoadWin32Accelerators() override;
};