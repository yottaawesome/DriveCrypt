#include "../Headers/DriveCryptApplication.h"

/// DriveCrypt
DriveCrypt::DriveCrypt(int nCmdShow) : mainWindow(*this)
{
	this->hInstance = GetModuleHandle(nullptr);
	this->nCmdShow = nCmdShow;
}

void DriveCrypt::Initialize()
{
	mainWindow.Initialize();
}

void DriveCrypt::LoadWin32Accelerators()
{
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRIVECRYPT));
}

HACCEL DriveCrypt::GetAccelerator()
{
	return hAccelTable;
}