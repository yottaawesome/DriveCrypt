#pragma once

#include <map>

using namespace std;

template<typename T>
class PointerWrapper
{
public:
	PointerWrapper();
	PointerWrapper(T* newObject);
	PointerWrapper(PointerWrapper<T>& newPointerWrapper);
	virtual ~PointerWrapper();

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
map<T*, int> PointerWrapper<T>::memMap = map<T*, int>();

template<typename T>
PointerWrapper<T>::PointerWrapper() : hasValidPointer(false), object(nullptr)
{
	OutputDebugString(_T("1\n"));
}

template<typename T>
PointerWrapper<T>::PointerWrapper(T* newObject) : hasValidPointer(false), object(nullptr)
{
	OutputDebugString(_T("2\n"));
	AssignAndIncrement(newObject);
}

template<typename T>
PointerWrapper<T>::PointerWrapper(PointerWrapper<T>& newPointerWrapper) : hasValidPointer(false), object(nullptr)
{
	OutputDebugString(_T("3\n"));
	AssignAndIncrement(newPointerWrapper->);
}

template<typename T>
PointerWrapper<T>::~PointerWrapper()
{
	deIncrementAndCleanUp();
}

template<typename T>
T* PointerWrapper<T>::operator->()
{
	return object;
}

template<typename T>
bool PointerWrapper<T>::operator==(T* comparison)
{
	return object == comparison;
}

template<typename T>
void PointerWrapper<T>::operator=(T* newObject)
{
	AssignAndIncrement(newObject);
}

template<typename T>
void PointerWrapper<T>::AssignAndIncrement(T* newObject)
{
	if (object == newObject)
		return;

	deIncrementAndCleanUp();

	object = newObject;
	if (object != nullptr)
		memMap[object]++;
}

template<typename T>
void PointerWrapper<T>::deIncrementAndCleanUp()
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