#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../Static.MemoryManagement/Headers/PointerWrapper.h"
#include "../../Static.Win32Application/Headers/ClientService.h"

class Test 
{
public:
	Test()
	{
		IFactory<A> a;
		prop = a();
	}
	PointerWrapper<A> prop;
};

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//IFactory<AB> a;
	//a();
	//PointerWrapper<AB> pw = new AB();

	Test a;
	a.prop->Blah();

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
