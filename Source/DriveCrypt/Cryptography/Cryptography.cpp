// Cryptography.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Cryptography.h"


// This is an example of an exported variable
CRYPTOGRAPHY_API int nCryptography=0;

// This is an example of an exported function.
CRYPTOGRAPHY_API int fnCryptography(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see Cryptography.h for the class definition
CCryptography::CCryptography()
{
    return;
}
