#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../MemoryModel/Headers/Pointer.h"
#include "../../Concurrency/Headers/Concurrency.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../Win32GUI/Headers/Win32GUI.h"
#include "../../System/Headers/System.h"

//MEMORYMODEL_API int fnMemoryModel();

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	System::Initialize();
	Concurrency::Initialize();
	Win32GUI::Initialize();

	Memo<IConsole> console = ComponentFactory::Instantiate<IConsole>();
	console->PrintLine(L"Hello, world!");
	IThread* t = ComponentFactory::Instantiate<IThread>();
	t->start(
		[&console]() -> int
		{ 
			console->PrintLine(L"Thread says, \"Hello, world!\""); 
			return 0; 
		});

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
