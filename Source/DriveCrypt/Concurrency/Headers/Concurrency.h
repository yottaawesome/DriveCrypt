#pragma once
#include "stdafx.h"
#include "../../ComponentModel/Headers/ComponentModel.h"
#include "../../ComponentModel/Headers/MemoFree.h"
#include <functional>
#include <vector>

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

class CONCURRENCY_API Message
{
public:
	enum MessageType
	{
		NORMAL_PROCESSING,
		CEDE_RESOURCE,
		COMMIT_TASK,
		THREAD_FINISH,
	};
	Message(MessageType messageType, void* parameter);
	virtual ~Message();
	virtual void zero();
	MessageType messageType;
	void* parameter;
	bool deferred;
	int deferCount;
protected:
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

class Thread : public IThread
{
public:
	CONCURRENCY_API Thread(void* param, bool destroyOnCompletion);
	CONCURRENCY_API virtual ~Thread() override;
	CONCURRENCY_API virtual void start(int(*simpleFunc)()) override;
	CONCURRENCY_API virtual void start(function<int()>* func) override;
	CONCURRENCY_API virtual void start(function<int()> func) override;
	CONCURRENCY_API virtual void start(IExecutionPackage* executionPackage) override;
	CONCURRENCY_API virtual int getStatus() override;
	CONCURRENCY_API virtual void terminate() override;
	CONCURRENCY_API virtual void suspend() override;
	CONCURRENCY_API virtual void resume() override;

protected:
	int status;
	unsigned int threadId;
	HANDLE hThread;
	bool destroyOnCompletion;
	void* threadParam;
	SystemFree<function<int()>> func;
	function<int()> func2;
	IExecutionPackage* executionPackage;

	CONCURRENCY_API virtual int run();
	CONCURRENCY_API static unsigned int WINAPI ThreadProc(void* param);
};

typedef void (Thread::*toRun)(void*);

class Runnable : public Thread
{
public:
	CONCURRENCY_API Runnable(IExecutionPackage* executionPackage);
	CONCURRENCY_API Runnable(int(*simpleFunc)());
	CONCURRENCY_API Runnable(function<int()> func);

	CONCURRENCY_API static void RunThread(int(*simpleFunc)());
	CONCURRENCY_API static void RunThread(function<int()> func);
protected:
	CONCURRENCY_API virtual int run() override;
	function<int()> func;
	IExecutionPackage* executionPackage;
};

class SemaphoreEventThread : public Thread
{
public:
	CONCURRENCY_API SemaphoreEventThread(void* param, bool destroyOnCompletion);
	CONCURRENCY_API virtual ~SemaphoreEventThread();
	CONCURRENCY_API virtual void addMessage(Message msg);
protected:
	vector<Message> messageQueue;
	CRITICAL_SECTION queueGuard;
	HANDLE hSemaphore;
	CONCURRENCY_API virtual int run();
	CONCURRENCY_API virtual void getMessage(Message* msg);
};

class CONCURRENCY_API ThreadFactory : public IVirtualComponentFactory<IThread>
{
public:
	virtual IThread* operator() () override;
	virtual void* Construct() override;
	virtual ~ThreadFactory();
};

class CONCURRENCY_API Concurrency final
{
public:
	static void Initialize();
};