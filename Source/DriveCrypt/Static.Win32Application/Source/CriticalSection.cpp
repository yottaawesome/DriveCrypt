#include "../Headers/Common.h"
#include "../../Shared/ExportedHeaders/CriticalSection.h"

CriticalSection::CriticalSection(LPCRITICAL_SECTION cs) : cs(cs)
{
    EnterCriticalSection(cs);
}

CriticalSection::~CriticalSection()
{
    LeaveCriticalSection(cs);
}

CriticalSectionController::CriticalSectionController()
{
	EnterCriticalSection(cs);
}

CriticalSectionController::~CriticalSectionController()
{
	LeaveCriticalSection(cs);
}
