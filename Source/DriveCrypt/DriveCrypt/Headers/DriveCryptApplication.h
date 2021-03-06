#pragma once

#include "Common.h"
#include "../../Win32GUI/Headers/Win32Application.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../MemoryModel/Headers/Pointer.h"
#include <functional>

using namespace std;

class DriveCrypt : public Win32Application
{
public:
	DriveCrypt();
	virtual void Initialize() override;
	virtual ~DriveCrypt();

protected:
	HACCEL hAccelTable;
	Memo<IFormBuilder> formBuilder;
	Memo<IWin32Window> mainWindow;
	Memo<IWin32Window> secondaryWindow;
	
	virtual HACCEL GetAccelerator() override;
	virtual void LoadWin32Accelerators() override;
	function<void(void)> callBack;
	function<void(void)> callBack2;
};