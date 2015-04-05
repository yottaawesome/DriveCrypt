#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "DynamicLibrary.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	IWin32Application& application = DriveCrypt(nCmdShow);
	application.Initialize();

	return application.MainLoop();
}
