#pragma once
#include "Invocable.h"

template<class T, typename R, typename... Args>
class I
{
public:
	I(T t) :t(t) { }
	virtual R operator()(Args... arg);// { return t(arg...); };
	virtual void g() { t.g(); }
protected:
	T t;
};

template<typename R, typename... Args>
class O
{
public:
	O() { }
	virtual R operator()(Args... arg) { return 1; }
	virtual void g() { }
};

template<typename R, typename... Args>
class I<Invocable<R, Args...>, R, Args...>
{
public:
	I(Invocable<R, Args...> t) :t(t) { }
	virtual R operator()(Args... arg) { return t(arg...); }
	virtual void g() { t.g(); }
protected:
	Invocable<R, Args...> t;
};

template<typename R, typename... Args>
class M : public I<Invocable<R, Args...>, R, Args...>
{
public:
	M(Invocable<R, Args...> t) :I(t) { }
};

template<class T, typename R, typename... Args>
R I<T, R, Args...>::operator()(Args... arg) { return t(arg...); };

auto j = I<O<int, int>, int, int>(O<int, int>());

M<int, int> l = (Invocable<int, int>(
	[](int i) -> int
{
	return i;
}));