#include "../Headers/stdafx.h"
#include "../Headers/Concurrency.h"

SemaphoreEventThread::SemaphoreEventThread(void* param, bool destroyOnCompletion) 
: Thread(param, false, destroyOnCompletion)
{
    if(!(hSemaphore = CreateSemaphore(0, 0, 100, 0)))
        throw std::runtime_error("Failed to initialize semaphore");

    InitializeCriticalSection(&queueGuard);
}

SemaphoreEventThread::~SemaphoreEventThread()
{
    DeleteCriticalSection(&queueGuard);
    CloseHandle(hSemaphore);
}

void SemaphoreEventThread::addMessage(Message msg)
{
    SimpleCriticalSection cs(&queueGuard);
    messageQueue.push_back(msg);
    ReleaseSemaphore(hSemaphore, 1, 0);
}

int SemaphoreEventThread::run()
{
    Message msg(Message::NORMAL_PROCESSING, 0);
    while(msg.messageType != Message::THREAD_FINISH)
    {
        switch(msg.messageType)
        {
            case Message::COMMIT_TASK:
                OutputDebugString(L"\nCommitted the task\n");
            break;
            case Message::NORMAL_PROCESSING:
                OutputDebugString(L"\nNormal processing\n");
            break;
            default:
                OutputDebugString(L"\nError - unknown or corrupt message\n");
        }
        getMessage(&msg);
    }

    OutputDebugString(L"\nEventSemaphoreThread exiting\n");
    return Thread::SUCCESS;
}

void SemaphoreEventThread::getMessage(Message* msg)
{
    WaitForSingleObject(hSemaphore, INFINITE);
    SimpleCriticalSection cs(&queueGuard);

    msg->messageType = messageQueue[0].messageType;
    msg->parameter = messageQueue[0].parameter;
    msg->deferCount = messageQueue[0].deferCount;
    msg->deferred = messageQueue[0].deferred;
 
    messageQueue.erase(messageQueue.begin());
}