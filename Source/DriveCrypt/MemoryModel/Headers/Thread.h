#pragma once
#include "stdafx.h"
#include <functional>

using namespace std;

class Thread
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
		Runnable(int (*simpleFunc)(), bool runImmediately = false);
		Runnable(function<int()> func, bool runImmediately = false);

		static void RunThread(int(*simpleFunc)());
		static void RunThread(function<int()> func);
	protected:
		virtual int run() override;
		function<int()> func;
};