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

class CriticalSectionController
{
public:
	CriticalSectionController();
	virtual ~CriticalSectionController();
protected:
	CRITICAL_SECTION* cs;
};