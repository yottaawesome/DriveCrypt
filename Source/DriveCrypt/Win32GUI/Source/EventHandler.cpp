#include "../Headers/EventHandler.h"

FunctionHandler EventHandler::EmptyEvent = []() -> void {};

FunctionHandler& EventHandler::GetEmptyEvent()
{
	return EventHandler::EmptyEvent;
}