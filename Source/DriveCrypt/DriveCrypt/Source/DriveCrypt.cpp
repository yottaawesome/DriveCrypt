#include "../Headers/DriveCrypt.h"
#include "../Headers/DriveCryptApplication.h"
#include "DynamicLibrary.h"
#include "IFactory.h"

template<typename T>
class Proxy
{
public:
	Proxy(T t);
	T& operator->();
	T* create();
protected:
	T t;
};

template<typename T>
Proxy<T>::Proxy(T t)
{

}

template<typename T>
T& Proxy<T>::operator->()
{
	return t;
}

template<typename T>
T* Proxy<T>::create()
{
	return new T();
}

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	IFactory<AB> a;
	a();

	//

	IWin32Application& application = DriveCrypt(nCmdShow);
	application.Initialize();

	return application.MainLoop();
}
