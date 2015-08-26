#pragma once
#include <functional>
#include <typeinfo>
#include <tuple>
#include <iostream>
#include <vector>

using namespace std;

template<typename R, typename... Args>
class Invocable
{
public:
	Invocable(function<R(Args...)> f);
	virtual ~Invocable();
	virtual R operator()(Args... arg) const;
	virtual R Invoke(Args... arg) const;
	virtual const vector<string>& Typenames();
	virtual void operator=(function<R(Args...)> rhs);
	void g() {}
protected:
	// Extracting the definitions causes compiler errors, specifically "no matching definition"
	//string* typeNames = new string[sizeof...(Args)];
	vector<string> v;
	bool typesResolved = false;

	function<R(Args...)> f;

	template<std::size_t I = 0, typename... Tp>
	typename std::enable_if<(I == sizeof...(Tp)), void>::type EnumIf(std::tuple<Tp...>& typeTuple) { }

	template<std::size_t I = 0, typename... Tp>
	typename std::enable_if<(I<sizeof...(Tp)), void>::type EnumIf(std::tuple<Tp...>& typeTuple)
	{
		v.push_back(typeid(std::get<I>(typeTuple)).name());
		EnumIf<I + 1, Tp...>(typeTuple);
	}
};

template<typename R, typename... Args>
Invocable<R, Args...>::~Invocable()
{
}
template<typename R, typename... Args>
Invocable<R, Args...>::Invocable(const function<R(Args...)> f) : f(f)
{
}

template<typename R, typename... Args>
R Invocable<R, Args...>::operator()(Args... arg) const
{
	return f(arg...);
}

template<typename R, typename... Args>
R Invocable<R, Args...>::Invoke(Args... arg) const
{
	return f(arg...);
}

template<typename R, typename... Args>
const vector<string>& Invocable<R, Args...>::Typenames()
{
	if (!typesResolved)
	{
		std::tuple<Args...> t;
		//print(t, s);
		EnumIf(t);
		typesResolved = true;
	}
	return v;
}

template<typename R, typename... Args>
void Invocable<R, Args...>::operator=(function<R(Args...)> rhs)
{
	this->f = rhs;
}