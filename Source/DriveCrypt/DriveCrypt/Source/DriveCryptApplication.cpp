#include "../Headers/DriveCryptApplication.h"

/// DriveCrypt
DriveCrypt::DriveCrypt() : mainWindow(*this)
{
	this->hInstance = GetModuleHandle(nullptr);
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