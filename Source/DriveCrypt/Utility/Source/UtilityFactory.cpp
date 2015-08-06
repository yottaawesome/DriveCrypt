#include "../Headers/stdafx.h"
#include "../Headers/Utility.h"
#include "../Headers/Logger.h"

ILogger* UtilityFactory::ConstructLogger()
{
	return new Logger();
}