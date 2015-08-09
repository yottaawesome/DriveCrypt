#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../System/Headers/PointerWrapper.h"
#include "../../Static.Win32Application/Headers/ClientService.h"
#include "../../System/Headers/DynamicLibrary.h"
#include "../../MemoryModel/Headers/Pointer.h"
#include "../../Concurrency/Headers/Concurrency.h"

#include "../../Utility/Headers/Utility.h"
#include "../../System/Headers/System.h"

//MEMORYMODEL_API int fnMemoryModel();

class Test : public FactoryService
{
public:
	Test()
	{
		prop = TypeFactory.Get<A>()();
	}
	PointerWrapper<A> prop;
};

class IInterface
{
public:
	virtual void Do() = 0;
};

class Concrete1 : public IInterface
{
public:
	virtual void Do() { OutputDebugString(L"1. Do\n"); };
};

class Concrete2: public Concrete1
{
public:
	virtual void Do() override { OutputDebugString(L"2. Do\n"); };
};

PointerWrapper<Concrete1> Make()
{
	return new Concrete2();
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//DynamicLibrary dll = DynamicLibrary(_T("MemoryModel.dll"));

	//IFactory<AB> a;
	//a();
	//PointerWrapper<AB> pw = new AB();

	CriticalSection s;

	//Test a;
	//a.prop->Blah();
	//fnMemoryModel();
	//MEMORYMODEL_API Pointer<A> a = Pointer<A>();

	//Memo<ILogger> logger = UtilityFactory::ConstructLogger();
	//logger->PrintLine("Hello world!");
	Memo<IConsole> console = System::GetConsole();
	console->PrintLine(L"Hello world!");

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
