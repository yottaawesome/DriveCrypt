#include "../Headers/stdafx.h"
#include "../Headers/Win32GUI.h"

WIN32GUI_API int meaningOfLife = 0;

long Win32GUI::Count = 0;

void Win32GUI::Initialize()
{
	InterlockedIncrement(&Count);
	if(Count == 1)
		ComponentFactory::RegisterFactory(new FormBuilderFactory());
}