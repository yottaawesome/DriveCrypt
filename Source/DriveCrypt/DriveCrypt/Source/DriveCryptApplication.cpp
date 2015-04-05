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
