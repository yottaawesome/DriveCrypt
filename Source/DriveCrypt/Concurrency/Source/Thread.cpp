#include "../Headers/Concurrency.h"
#include <process.h>
#include <stdexcept>

using namespace std;

Thread::Thread(void* param, bool destroyOnCompletion) : destroyOnCompletion(destroyOnCompletion), status(ThreadStatus::READY), threadParam(param)
{
}

Thread::~Thread()
{
    CloseHandle(hThread);
}

void Thread::start(int(*simpleFunc)())
{
	this->executionPackage = nullptr;
	this->func = new function<int()>(*simpleFunc);
	hThread = (HANDLE)_beginthreadex(0, 0, Thread::ThreadProc, this, 0, &threadId);
}

void Thread::start(function<int()>* func)
{
	this->executionPackage = nullptr;
	this->func = func;
    //hThread = CreateThread(NULL, 0, Thread::ThreadProc, this, 0, &threadId);
    hThread = (HANDLE) _beginthreadex(0, 0, Thread::ThreadProc, this, 0, &threadId);
}

void Thread::start(IExecutionPackage* executionPackage)
{
	this->executionPackage = executionPackage;
	this->func = nullptr;
	hThread = (HANDLE)_beginthreadex(0, 0, Thread::ThreadProc, this, 0, &threadId);
}

int Thread::run()
{
	if (executionPackage != nullptr)
		return executionPackage->Run();
	return func->operator()();
}

int Thread::getStatus()
{
    return status;
}

void Thread::terminate()
{
    if(this->status != ThreadStatus::RUNNING)
        throw runtime_error("Thread was not running when request to terminate occurred.");

    TerminateThread(hThread, ThreadStatus::FAILURE);
}

void Thread::suspend()
{
    if(this->status != ThreadStatus::RUNNING)
        throw std::runtime_error("Thread was not running when request to suspend occurred.");

    this->status = ThreadStatus::SUSPENDED;
    SuspendThread(hThread);
}

void Thread::resume()
{
    if(this->status != ThreadStatus::SUSPENDED)
        throw std::runtime_error("Thread was not suspended when request to resume occurred.");

    this->status = ThreadStatus::RUNNING;
    ResumeThread(hThread);
}

unsigned int WINAPI Thread::ThreadProc(void* param)
{
    Thread* t = (Thread*) param;
    t->status = t->run();
    int stat = t->status;

    if(t->destroyOnCompletion)
        delete t;
    return stat;
}