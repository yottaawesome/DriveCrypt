#pragma once

#include "Common.h"
#include "CriticalSection.h"
#include <map>

using namespace std;

template<typename T>
class Proxy
{
public:
	Proxy(T* val);
	virtual ~Proxy();
	virtual int GetRefCount();

protected:
	static map<T*, int> m;
	T* val;
	static long initializationCount;
	static CRITICAL_SECTION criticalSection;
};

// STATICS
template<typename T>
map<T*, int> Proxy<T>::m;

template<typename T>
long Proxy<T>::initializationCount = 0;

template<typename T>
CRITICAL_SECTION Proxy<T>::criticalSection;
// END STATICS

template<typename T>
int Proxy<T>::GetRefCount()
{
	return m[val];
}

template<typename T>
Proxy<T>::Proxy(T* val)
{
	InterlockedIncrement(&initializationCount);
	if (initializationCount == 1)
		InitializeCriticalSection(&(this->criticalSection));

	CriticalSection(&(this->criticalSection))
	if (m.find(val) == m.end())
		m[val] = 1;
	else
		m[val]++;

	this->val = val;
}

template<typename T>
Proxy<T>::~Proxy()
{
	CriticalSection(&(this->criticalSection))
	m[val]--;
	if (m[val] < 1)
	{
		m.erase(val);
		delete val;
	}
}