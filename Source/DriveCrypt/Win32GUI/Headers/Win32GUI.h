#pragma once
#include "../../ComponentModel/Headers/ComponentModel.h"

#ifdef WIN32GUI_EXPORTS
#define WIN32GUI_API __declspec(dllexport)
#else
#define WIN32GUI_API __declspec(dllimport)
#endif

extern WIN32GUI_API int meaningOfLife;

class WIN32GUI_API FormBuilder : public IFormBuilder
{
	virtual IWin32Window* CreateMainWindow();
	virtual void AddButton(IWin32Window* window);

	virtual ~FormBuilder();
};

class WIN32GUI_API FormBuilderFactory : public IVirtualComponentFactory<IFormBuilder>
{
	virtual IFormBuilder* operator() () override;
	virtual void* Construct() override;
	virtual ~FormBuilderFactory();
};

class WIN32GUI_API Win32GUI final
{
public:
	static void Initialize();

private:
	static long Count;
};