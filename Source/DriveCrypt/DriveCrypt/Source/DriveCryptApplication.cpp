#include "../Headers/DriveCryptApplication.h"

/// DriveCrypt
DriveCrypt::DriveCrypt() : mainWindow(nullptr)
{
	this->callBack =
		[]() -> void
		{
			MessageBox(nullptr, L"It's the Blah", L"Oh yeah!", MB_OK);
		};
	this->callBack2 =
		[]() -> void
		{
			MessageBox(nullptr, L"You rock!", L"Brilliant", MB_OK);
		};

	this->hInstance = GetModuleHandle(nullptr);
	formBuilder = ComponentFactory::Instantiate<IFormBuilder>();
	mainWindow = formBuilder->CreateMainWindow(L"DriveCrypt Main Window", 1000, 700);
	secondaryWindow = formBuilder->CreateMainWindow(L"DriveCrypt Secondary Window", 1000, 700);
}

DriveCrypt::~DriveCrypt() { }

void DriveCrypt::Initialize()
{
	mainWindow->Initialize();
	secondaryWindow->Initialize();
	formBuilder->AddButton(*mainWindow, L"Blah", callBack, 100, 100);
	formBuilder->AddButton(*secondaryWindow, L"The second blah", callBack2, 200, 200);
}

void DriveCrypt::LoadWin32Accelerators()
{
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRIVECRYPT));
}

HACCEL DriveCrypt::GetAccelerator()
{
	return hAccelTable;
}