#pragma once

#include "Common.h"
#include "../../Win32GUI/Headers/DriveCryptMainWindow.h"
#include "../../Win32GUI/Headers/Win32Application.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../MemoryModel/Headers/Pointer.h"

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt();
	virtual void Initialize() override;
	virtual ~DriveCrypt();

protected:
	HACCEL hAccelTable;
	Memo<IWin32Window> mainWindow;
	
	virtual HACCEL GetAccelerator() override;
	virtual void LoadWin32Accelerators() override;
};