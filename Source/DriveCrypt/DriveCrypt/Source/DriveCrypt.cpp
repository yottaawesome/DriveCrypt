// DriveCrypt.cpp : Defines the entry point for the application.
//

#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "DynamicLibrary.h"

#define MAX_LOADSTRING 100

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR    lpCmdLine, _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	DriveCrypt s(hInstance, nCmdShow);
	return s.Initialize();
}
