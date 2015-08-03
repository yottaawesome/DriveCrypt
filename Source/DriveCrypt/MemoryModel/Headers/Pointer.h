#pragma once
#include "../Headers/stdafx.h"
#include "MemoryModel.h"

#include <map>

using namespace std;

template<typename T>
class Pointer
{
public:
	Pointer();
	Pointer(T* newObject);
	Pointer(Pointer<T>& newPointerWrapper);
	virtual ~Pointer();

	virtual T* operator->();
	virtual bool operator==(T* comparison);
	virtual void operator=(T* newObject);

protected:
	bool hasValidPointer;
	T* object;
	static map<T*, int> memMap;

	virtual void AssignAndIncrement(T* newObject);
	virtual void deIncrementAndCleanUp();
};

template<typename T>
map<T*, int> Pointer<T>::memMap = map<T*, int>();

template<typename T>
Pointer<T>::Pointer() : hasValidPointer(false), object(nullptr)
{
	InterlockedIncrement(&nMemoryModel);
	std::wstring s = std::to_wstring(nMemoryModel) + L"\n";
	OutputDebugString(s.c_str());
//	OutputDebugString(_T("1\n"));
}

template<typename T>
Pointer<T>::Pointer(T* newObject) : hasValidPointer(false), object(nullptr)
{
	OutputDebugString(_T("2\n"));
	AssignAndIncrement(newObject);
}

template<typename T>
Pointer<T>::Pointer(Pointer<T>& newPointerWrapper) : hasValidPointer(false), object(nullptr)
{
	OutputDebugString(_T("3\n"));
	AssignAndIncrement(newPointerWrapper->);
}

template<typename T>
Pointer<T>::~Pointer()
{
	deIncrementAndCleanUp();
}

template<typename T>
T* Pointer<T>::operator->()
{
	return object;
}

template<typename T>
bool Pointer<T>::operator==(T* comparison)
{
	return object == comparison;
}

template<typename T>
void Pointer<T>::operator=(T* newObject)
{
	AssignAndIncrement(newObject);
}

template<typename T>
void Pointer<T>::AssignAndIncrement(T* newObject)
{
	if (object == newObject)
		return;

	deIncrementAndCleanUp();

	object = newObject;
	if (object != nullptr)
		memMap[object]++;
}

template<typename T>
void Pointer<T>::deIncrementAndCleanUp()
{
	if (object != nullptr)
	{
		memMap[object]--;
		if (memMap[object] == 0)
		{
			OutputDebugString(_T("Deleting\n"));
			delete object;
			hasValidPointer = false;
		}
	}
}