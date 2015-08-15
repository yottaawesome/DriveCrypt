#pragma once
#include "stdafx.h"
#include <functional>

using namespace std;

enum COMPONENTMODEL_API ThreadStatus
{
	SUCCESS = 0,
	FAILURE = 1,
	READY = 2,
	RUNNING = 3,
	SUSPENDED = 4,
	ABNORMAL_TERMINATION = 5
};

class COMPONENTMODEL_API IExecutionPackage
{
public:
	virtual int Run() = 0;
	virtual ~IExecutionPackage() = 0;
};

class COMPONENTMODEL_API IThread
{
public:
	virtual ~IThread() = 0;
	virtual void start(function<int()>* func) = 0;
	virtual void start(int(*simpleFunc)()) = 0;
	virtual void start(IExecutionPackage* executionPackage) = 0;
	virtual int getStatus() = 0;
	virtual void terminate() = 0;
	virtual void suspend() = 0;
	virtual void resume() = 0;
};