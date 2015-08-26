#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "../../System/Headers/PointerWrapper.h"
//#include "../../Static.Win32Application/Headers/ClientService.h"
#include "../../System/Headers/DynamicLibrary.h"
#include "../../MemoryModel/Headers/Pointer.h"
#include "../../Concurrency/Headers/Concurrency.h"
#include "../../Utility/Headers/Utility.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../System/Headers/System.h"

//MEMORYMODEL_API int fnMemoryModel();

class Z
{
public:
	Z() 
	{
		OutputDebugString(L"\nZ created");
	}
	~Z()
	{
		OutputDebugString(L"\nZ destroyed");
	}
};

class Y
{
public:
	Y() : z(Z())
	{
		OutputDebugString(L"\nY created\n");
	}

	Y(Z& z) : z(z) 
	{
		OutputDebugString(L"\nY created\n");
	}

	void Add(Z& z)
	{
		//OutputDebugString(L"\nZ assigned");
		this->z = z;
		//OutputDebugString(L"\nZ postassigned");
	}
	void Add(Z* z)
	{
		//OutputDebugString(L"\nZ assigned");
		this->z = *z;
		//OutputDebugString(L"\nZ postassigned");
	}

	~Y()
	{
		//z.~Z();
		OutputDebugString(L"\nY destroyed");
	}
protected:
	Z& z;
};

void Blah()
{
	Z z;
	Y y = z;
	OutputDebugString(L"\nBlah destroyed");
	//Y y;// = (Z());
	//Y y2;
	//y.Add(Z());
	//y.Add(Z());
}

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
	Concurrency::Initialize();

	Memo<IConsole> console = ComponentFactory::Instantiate<IConsole>();
	console->PrintLine(L"Hello, world!");
	IThread* t = ComponentFactory::Instantiate<IThread>();
	t->start(
		[&console]() -> int
		{ 
			console->PrintLine(L"Thread says, \"Hello, world!\""); 
			return 0; 
		});

	Blah();

	IWin32Application& application = DriveCrypt();
	application.Initialize();

	return application.MainLoop();
}
