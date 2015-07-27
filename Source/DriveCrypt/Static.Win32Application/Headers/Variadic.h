#pragma once

#include "Common.h"
#include "../Headers/Win32Application.h"
#include "../../Shared/ExportedHeaders/IFactory.h"

template<typename... T>
class Injectable
{
public:
	Injectable(T... Params) 
	{
	}
};