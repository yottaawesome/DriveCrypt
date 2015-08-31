#pragma once
#include "../Headers/stdafx.h"
#include "MemoryModel.h"
#include <map>

using namespace std;

template<typename T>
class Memo
{
public:
	Memo();
	Memo(T* newObject);
	Memo(Memo<T>& newPointerWrapper);
	virtual ~Memo();

	virtual T* operator->();
	virtual T* operator*();
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
map<T*, int> Memo<T>::memMap = map<T*, int>();

template<typename T>
Memo<T>::Memo() : hasValidPointer(false), object(nullptr)
{
	InterlockedIncrement(&nMemoryModel);
	//std::wstring s = std::to_wstring(nMemoryModel) + L"\n";
	//OutputDebugString(s.c_str());
//	OutputDebugString(_T("1\n"));
}

template<typename T>
T* Memo<T>::operator*()
{
	return object;
}

template<typename T>
Memo<T>::Memo(T* newObject) : hasValidPointer(false), object(nullptr)
{
	//OutputDebugString(_T("2\n"));
	AssignAndIncrement(newObject);
}

template<typename T>
Memo<T>::Memo(Memo<T>& newPointerWrapper) : hasValidPointer(false), object(nullptr)
{
	//OutputDebugString(_T("3\n"));
	AssignAndIncrement(newPointerWrapper->);
}

template<typename T>
Memo<T>::~Memo()
{
	deIncrementAndCleanUp();
}

template<typename T>
T* Memo<T>::operator->()
{
	return object;
}

template<typename T>
bool Memo<T>::operator==(T* comparison)
{
	return object == comparison;
}

template<typename T>
void Memo<T>::operator=(T* newObject)
{
	AssignAndIncrement(newObject);
}

template<typename T>
void Memo<T>::AssignAndIncrement(T* newObject)
{
	if (object == newObject)
		return;

	deIncrementAndCleanUp();

	object = newObject;
	if (object != nullptr)
		memMap[object]++;
}

template<typename T>
void Memo<T>::deIncrementAndCleanUp()
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