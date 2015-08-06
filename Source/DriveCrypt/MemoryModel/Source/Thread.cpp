#include "../Headers/Thread.h"
#include <process.h>
#include <stdexcept>

using namespace std;

Thread::Thread(void* param, bool runImmediately, bool destroyOnCompletion) : destroyOnCompletion(destroyOnCompletion),
    status(Thread::READY),
    threadParam(param)
{
	if(runImmediately)
		this->start();
}

Thread::~Thread()
{
    CloseHandle(hThread);
}

void Thread::start()
{
    //hThread = CreateThread(NULL, 0, Thread::ThreadProc, this, 0, &threadId);
    hThread = (HANDLE) _beginthreadex(0, 0, Thread::ThreadProc, this, 0, &threadId);
}

int Thread::getStatus()
{
    return status;
}

void Thread::terminate()
{
    if(this->status != Thread::RUNNING)
        throw runtime_error("Thread was not running when request to terminate occurred.");

    TerminateThread(hThread, Thread::FAILURE);
}

void Thread::suspend()
{
    if(this->status != Thread::RUNNING)
        throw std::runtime_error("Thread was not running when request to suspend occurred.");

    this->status = Thread::SUSPENDED;
    SuspendThread(hThread);
}

void Thread::resume()
{
    if(this->status != Thread::SUSPENDED)
        throw std::runtime_error("Thread was not suspended when request to resume occurred.");

    this->status = Thread::RUNNING;
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