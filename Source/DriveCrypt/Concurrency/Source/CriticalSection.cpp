#include "../Headers/Concurrency.h"

//
// SimpleCriticalSection
SimpleCriticalSection::SimpleCriticalSection(LPCRITICAL_SECTION cs) : cs(cs)
{
    EnterCriticalSection(cs);
}

SimpleCriticalSection::~SimpleCriticalSection()
{
    LeaveCriticalSection(cs);
}

//
// CriticalSection
CriticalSection::CriticalSection() : inCriticalSection(false)
{
	InitializeCriticalSection(&cs);
}

CriticalSection::CriticalSection(unsigned int spinCount) : inCriticalSection(false)
{
	InitializeCriticalSectionAndSpinCount(&cs, spinCount);
}

CriticalSection::~CriticalSection()
{
	if (this->inCriticalSection)
		this->Exit();
	DeleteCriticalSection(&cs);
}

bool CriticalSection::TryEnter()
{
	// TryEnterCriticalSection will return non-zero if it succeeds, zero otherwise
	return TryEnterCriticalSection(&cs) != 0 ? inCriticalSection = true : inCriticalSection = false;
}

void CriticalSection::Enter()
{
	EnterCriticalSection(&cs);
}

void CriticalSection::Exit()
{
	this->inCriticalSection = false;
	LeaveCriticalSection(&cs);
}