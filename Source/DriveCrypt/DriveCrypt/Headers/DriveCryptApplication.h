#pragma once

#include "Common.h"
#include "DriveCryptMainWindow.h"
#include "../../Win32GUI/Headers/Win32Application.h"

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt();
	virtual void Initialize() override;

protected:
	HACCEL hAccelTable;

	DriveCryptMainWindow mainWindow;
	virtual HACCEL GetAccelerator() override;
	virtual void LoadWin32Accelerators() override;
};