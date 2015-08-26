#include "../Headers/stdafx.h"
#include <Wincon.h>
#include <iostream>
#include "../Headers/Console.h"
#include "../Headers/PolyFactory.h"
#include "../../Utility/Headers/Utility.h"

bool Console::ConsoleCreated = false;
CriticalSection Console::SectionLock = CriticalSection();

Console::Console()
{
	if (!ConsoleCreated && SectionLock.TryEnter())
	{
		if (!ConsoleCreated && !AllocConsole())
		{
			wchar_t messageBuffer[256];
			DWORD errorCode = GetLastError();
			FormatMessage(
				FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				nullptr,
				errorCode,
				MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				messageBuffer,
				256,
				nullptr);

			wstring s = L"AllocConsole() failed! ";
			s += messageBuffer;
			throw runtime_error(StringConverter::convertWStringToString(s));
		}
		ConsoleCreated = true;

		SectionLock.Exit();
	}
}

Console::~Console()
{
}

void Console::Free()
{
	if (ConsoleCreated)
	{
		if (SectionLock.TryEnter())
		{
			FreeConsole();
			SectionLock.Exit();
			ConsoleCreated = false;
		}
	}
}

void Console::Print(wstring value)
{
	InternalPrint(value);
}

void Console::Print(wstring& value)
{
	InternalPrint(value);
}

void Console::PrintLine(wstring value)
{
	value.append(L"\n");
	InternalPrint(value);
}

void Console::PrintLine(wstring& value)
{
	value.append(L"\n");
	InternalPrint(value);
}

void Console::InternalPrint(wstring& value)
{
	
	HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned long charsWritten = 0;
	WriteConsole(
		outHandle, //_In_             HANDLE  hConsoleOutput,
		value.c_str(),//_In_       const VOID    *lpBuffer,
		value.length(), //_In_             DWORD   nNumberOfCharsToWrite,
		&charsWritten,//_Out_            LPDWORD lpNumberOfCharsWritten,
		nullptr//_Reserved_       LPVOID  lpReserved
		);
}