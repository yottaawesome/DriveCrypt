#include "Common.h"
#include "CriticalSection.h"

CriticalSection::CriticalSection(LPCRITICAL_SECTION cs) : cs(cs)
{
    EnterCriticalSection(cs);
}

CriticalSection::~CriticalSection()
{
    LeaveCriticalSection(cs);
}