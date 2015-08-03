// MemoryModel.cpp : Defines the exported functions for the DLL application.
//

#include "../Headers/stdafx.h"
#include "../Headers/MemoryModel.h"
#include <map>

using namespace std;

// This is an example of an exported variable
unsigned int nMemoryModel=0;

// This is an example of an exported function.
int fnMemoryModel()
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see MemoryModel.h for the class definition
CMemoryModel::CMemoryModel()
{
    return;
}
