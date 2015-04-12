// Experimental.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"
#include <iostream>
#include <map>

using namespace std;

TestA::TestA(TestB* val)
{
}

template<typename T>
map<T*, int> Proxy<T>::m;

template<typename T>
int Proxy<T>::GetCount() 
{
	return m[val];
}

template<typename T>
Proxy<T>::Proxy(T* val)
{
	if (m.find(val) == m.end())
		m[val] = 1;
	else
		m[val]++;
	this->val = val;
}

template<typename T>
Proxy<T>::~Proxy()
{
	m[val]--;
	if (m[val] < 1)
	{
		cout << "Deleting" << endl;
		m.erase(val);
		delete val;
	}
}

TestA* TestAAllocator::operator()()
{
	TestBAllocator factory;
	return new TestA(factory());
}

TestB* TestBAllocator::operator()()
{
	return new TestB();
}

TestC* Allocator<TestC>::operator()()
{
	return new TestC();
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestAAllocator aFactory;
	auto a = aFactory();
	auto b = aFactory();
	auto p_a = new Proxy<TestA>(a);
	auto p_b = new Proxy<TestA>(a);
	auto p_c = new Proxy<TestA>(b);

	Allocator<TestC> cFactory;
	cFactory();

	cout << p_a->GetCount() << endl;
	cout << p_b->GetCount() << endl;
	cout << p_c->GetCount() << endl;

	delete p_a;
	delete p_b;
	delete p_c;

	char c;
	cin >> c;

	return 0;
}
