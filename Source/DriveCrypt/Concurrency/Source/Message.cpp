#include "../Headers/stdafx.h"
#include "../Headers/Concurrency.h"

Message::Message(Message::MessageType messageType, void* parameter) :
messageType(messageType),
parameter(parameter),
deferred(false),
deferCount(0)
{}

Message::~Message(){}

void Message::zero()
{
    ::SecureZeroMemory(this, sizeof(this));
}