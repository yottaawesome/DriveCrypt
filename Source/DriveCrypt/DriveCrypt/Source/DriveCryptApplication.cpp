#include "../Headers/DriveCryptApplication.h"

/// DriveCrypt
DriveCrypt::DriveCrypt(HINSTANCE hinst, int nCmdShow) : mainWindow(*this)
{
	this->hInstance = hinst;
	this->nCmdShow = nCmdShow;
}

int DriveCrypt::Initialize()
{
	mainWindow.Initialize();
	return this->MainLoop();
}
