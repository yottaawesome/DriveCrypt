#include "../Headers/DriveCryptApplication.h"

/// DriveCrypt
DriveCrypt::DriveCrypt() : mainWindow(nullptr)
{
	this->hInstance = GetModuleHandle(nullptr);
	Memo<IFormBuilder> formBuilder = ComponentFactory::Instantiate<IFormBuilder>();
	mainWindow = formBuilder->CreateMainWindow();
}

DriveCrypt::~DriveCrypt() { }

void DriveCrypt::Initialize()
{
	mainWindow->Initialize();
}

void DriveCrypt::LoadWin32Accelerators()
{
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRIVECRYPT));
}

HACCEL DriveCrypt::GetAccelerator()
{
	return hAccelTable;
}