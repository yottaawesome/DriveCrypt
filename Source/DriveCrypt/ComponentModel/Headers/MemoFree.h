#pragma once

#include <map>

using namespace std;

template<typename T>
class SystemFree
{
public:
	SystemFree();
	SystemFree(T* newObject);
	SystemFree(SystemFree<T>& newPointerWrapper);
	virtual ~SystemFree();

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
map<T*, int> SystemFree<T>::memMap = map<T*, int>();

template<typename T>
SystemFree<T>::SystemFree() : hasValidPointer(false), object(nullptr)
{
}

template<typename T>
SystemFree<T>::SystemFree(T* newObject) : hasValidPointer(false), object(nullptr)
{
	//OutputDebugString(_T("2\n"));
	AssignAndIncrement(newObject);
}

template<typename T>
SystemFree<T>::SystemFree(SystemFree<T>& newPointerWrapper) : hasValidPointer(false), object(nullptr)
{
	//OutputDebugString(_T("3\n"));
	AssignAndIncrement(newPointerWrapper->);
}

template<typename T>
SystemFree<T>::~SystemFree()
{
	deIncrementAndCleanUp();
}

template<typename T>
T* SystemFree<T>::operator->()
{
	return object;
}

template<typename T>
bool SystemFree<T>::operator==(T* comparison)
{
	return object == comparison;
}

template<typename T>
void SystemFree<T>::operator=(T* newObject)
{
	AssignAndIncrement(newObject);
}

template<typename T>
void SystemFree<T>::AssignAndIncrement(T* newObject)
{
	if (object == newObject)
		return;

	deIncrementAndCleanUp();

	object = newObject;
	if (object != nullptr)
		memMap[object]++;
}

template<typename T>
void SystemFree<T>::deIncrementAndCleanUp()
{
	if (object != nullptr)
	{
		memMap[object]--;
		if (memMap[object] == 0)
		{
			delete object;
			hasValidPointer = false;
		}
	}
}