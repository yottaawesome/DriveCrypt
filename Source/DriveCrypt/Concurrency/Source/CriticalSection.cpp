#include "../Headers/Concurrency.h"

//
// SimpleCriticalSection
SimpleCriticalSection::SimpleCriticalSection(LPCRITICAL_SECTION cs) : cs(cs), usingLpCriticalSection(true)
{
    EnterCriticalSection(cs);
}

SimpleCriticalSection::SimpleCriticalSection(CriticalSection& cs) : ics(cs), usingLpCriticalSection(false)
{
	ics.Enter();
}

SimpleCriticalSection::~SimpleCriticalSection()
{
	if (usingLpCriticalSection)
		LeaveCriticalSection(cs);
	else
		ics.Exit();
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
	this->inCriticalSection = true;
}

void CriticalSection::Exit()
{
	LeaveCriticalSection(&cs);
	this->inCriticalSection = false;
}