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
public:
	FormBuilder();
	virtual IWin32Window* CreateMainWindow(wstring& title, unsigned int width = 0, unsigned int height = 0) override;
	virtual IWin32Window* CreateMainWindow(wstring&& title, unsigned int width = 0, unsigned int height = 0) override;

	virtual void AddButton(IWin32Window* window, wstring& text, void(*onClick)(), unsigned int width = 0, unsigned int height = 0) override;
	virtual void AddButton(IWin32Window* window, wstring&& text, void(*onClick)(), unsigned int width = 0, unsigned int height = 0) override;

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