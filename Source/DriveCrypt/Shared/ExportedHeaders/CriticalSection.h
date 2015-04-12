#pragma once
#include "Common.h"

class CriticalSection
{
    public:
        CriticalSection(LPCRITICAL_SECTION cs);
        virtual ~CriticalSection();
    protected:
        CRITICAL_SECTION* cs;
};