#pragma once
#include <map>

using namespace std;

class TestB
{
};

class TestA
{
public:
	TestA(TestB* val);
};

class TestC
{
};

template<typename T>
class Allocator
{
public:
	virtual T* operator() () = 0;
};

template<>
class Allocator<TestC>
{
public:
	virtual TestC* operator() ();
};

class TestAAllocator : public Allocator<TestA>
{
public:
	virtual TestA* operator() () override;
};

class TestBAllocator : public Allocator<TestB>
{
public:
	virtual TestB* operator() () override;
};

template<typename T>
class Proxy
{
public:
	Proxy(T* val);
	virtual ~Proxy();
	virtual int GetCount();

protected:
	static map<T*, int> m;
	T* val;
};