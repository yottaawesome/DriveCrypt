#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../System/Headers/PointerWrapper.h"
#include "../../Static.Win32Application/Headers/ClientService.h"
#include "../../System/Headers/DynamicLibrary.h"
#include "../../MemoryModel/Headers/Pointer.h"
#include "../../Concurrency/Headers/Concurrency.h"
#include "../../Utility/Headers/Utility.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../System/Headers/System.h"

//MEMORYMODEL_API int fnMemoryModel();

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//DynamicLibrary dll = DynamicLibrary(_T("MemoryModel.dll"));

	//ITypeFactory<AB> a;
	//a();
	//PointerWrapper<AB> pw = new AB();

	CriticalSection s;

	//Test a;
	//a.prop->Blah();
	//fnMemoryModel();
	//MEMORYMODEL_API Pointer<A> a = Pointer<A>();

	//Memo<IConsole> console = System::GetConsole();
	//console->PrintLine(L"Hello world!");

	System::Initialize();
	IConsole* a = ComponentFactory::Instantiate<IConsole>();
	Memo<IConsole> mem = a;
	mem->PrintLine(L"Hello, world!");

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
