#pragma once
#include "stdafx.h"

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CONCURRENCY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CONCURRENCY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CONCURRENCY_EXPORTS
#define CONCURRENCY_API __declspec(dllexport)
#else
#define CONCURRENCY_API __declspec(dllimport)
#endif

class CONCURRENCY_API SimpleCriticalSection
{
public:
	SimpleCriticalSection(LPCRITICAL_SECTION cs);
	virtual ~SimpleCriticalSection();
protected:
	CRITICAL_SECTION* cs;
};

class CONCURRENCY_API CriticalSection
{
public:
	CriticalSection();
	CriticalSection(unsigned int spinCount);
	virtual ~CriticalSection();
	virtual void Enter();
	virtual bool TryEnter();
	virtual void Exit();
protected:
	bool inCriticalSection;
	CRITICAL_SECTION cs;
};
