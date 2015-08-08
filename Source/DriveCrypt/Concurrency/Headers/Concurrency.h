#pragma once
#include "stdafx.h"
#include <functional>

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

using namespace std;

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

class CONCURRENCY_API SimpleCriticalSection
{
public:
	SimpleCriticalSection(LPCRITICAL_SECTION cs);
	SimpleCriticalSection(CriticalSection& ics);
	virtual ~SimpleCriticalSection();
protected:
	bool usingLpCriticalSection;
	CRITICAL_SECTION* cs;
	CriticalSection ics;
};

class CONCURRENCY_API Thread
{
public:
	enum status
	{
		SUCCESS = 0,
		FAILURE = 1,
		READY = 2,
		RUNNING = 3,
		SUSPENDED = 4,
		ABNORMAL_TERMINATION = 5
	};
	Thread(void* param, bool runImmediately, bool destroyOnCompletion);
	virtual ~Thread();
	virtual void start();
	virtual int getStatus();
	virtual void terminate();
	virtual void suspend();
	virtual void resume();
	int priority;
protected:
	bool runImmediately;
	int status;
	unsigned int threadId;
	HANDLE hThread;
	bool destroyOnCompletion;
	void* threadParam;
	virtual int run() = 0;
	static unsigned int WINAPI ThreadProc(void* param);
};

typedef void (Thread::*toRun)(void*);

class Runnable : public Thread
{
public:
	CONCURRENCY_API Runnable(int(*simpleFunc)(), bool runImmediately = false);
	CONCURRENCY_API Runnable(function<int()> func, bool runImmediately = false);

	CONCURRENCY_API static void RunThread(int(*simpleFunc)());
	CONCURRENCY_API static void RunThread(function<int()> func);
protected:
	virtual int run() override;
	function<int()> func;
};