// Init.cpp : Defines the exported functions for the DLL application.
//

#include "../Headers/stdafx.h"
#include "../Headers/Init.h"

// This is an example of an exported variable
INIT_API int nInit=0;

// This is an example of an exported function.
INIT_API int fnInit(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Init.h for the class definition
CInit::CInit()
{
    return;
}
