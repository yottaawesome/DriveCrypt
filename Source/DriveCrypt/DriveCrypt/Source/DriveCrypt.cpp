#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../Static.MemoryManagement/Headers/PointerWrapper.h"
#include "../../Static.Win32Application/Headers/ClientService.h"
#include "../../Shared/ExportedHeaders/DynamicLibrary.h"
#include "../../MemoryModel/Headers/Pointer.h"

MEMORYMODEL_API int fnMemoryModel();

class Test : public FactoryService
{
public:
	Test()
	{
		prop = TypeFactory.Get<A>()();
	}
	Pointer<A> prop;
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//DynamicLibrary dll = DynamicLibrary(_T("MemoryModel.dll"));

	//IFactory<AB> a;
	//a();
	//PointerWrapper<AB> pw = new AB();

	Test a;
	a.prop->Blah();
	//fnMemoryModel();
	//MEMORYMODEL_API Pointer<A> a = Pointer<A>();
	//a = new A();
	//CMemoryModel a;

	Test b;
	Test c;

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
