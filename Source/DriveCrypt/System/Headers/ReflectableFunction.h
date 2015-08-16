#pragma once
#include <functional>
#include <typeinfo>
#include <tuple>
#include <iostream>
#include <vector>

/*
Reading:
http://stackoverflow.com/questions/6972368/stdenable-if-to-conditionally-compile-a-member-function
https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/c_templates_what_is_a_variadic_template_function41?lang=en
http://stackoverflow.com/questions/15953139/get-the-nth-type-of-variadic-template-templates
http://stackoverflow.com/questions/8827171/how-to-inspect-the-types-of-a-functions-parameters
http://stackoverflow.com/questions/41453/how-can-i-add-reflection-to-a-c-application
http://stackoverflow.com/questions/1974682/using-reference-as-class-members-for-dependencies
http://www.informit.com/articles/article.aspx?p=1852519
http://stackoverflow.com/questions/31368699/iterating-variadic-template-types?rq=1
http://stackoverflow.com/questions/21180346/variadic-template-unpacking-arguments-to-typename
http://stackoverflow.com/questions/12515616/expression-contains-unexpanded-parameter-packs/12515637#12515637
*/

using namespace std;

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type print(std::tuple<Tp...>& t, string* arr) { }

template<std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I<sizeof...(Tp), void>::type print(std::tuple<Tp...>& t, string* arr)
{
	arr[I] = typeid(std::get<I>(t)).name();
	print<I + 1, Tp...>(t, arr);
}

template<typename R, typename... Args>
class Invocable
{
public:
	Invocable(const function<R(Args...)> f);
	~Invocable();
	R operator()(Args... arg);
	R Invoke(Args... arg);
	const vector<string>& Typenames();

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

private:
	// Completely disable assignments
	void operator=(Invocable a) = delete;
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
R Invocable<R, Args...>::operator()(Args... arg)
{
	return f(arg...);
}

template<typename R, typename... Args>
R Invocable<R, Args...>::Invoke(Args... arg)
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

class RT
{
public:
	RT();
	RT(int g);
	Invocable<int, int> f;// = [this](int i) -> int { return x; };
	Invocable<int, int> t;// = [this](int i) -> int { return x; };

protected:
	// This allows multiple constructors to initialize the Invocables and minimize duplication of lambdas
	RT(function<int(int)> f, function<int(int)> t);
	int z = 5;
	void jabber();
	int x = 3;
	int Test(int i);
};

int RT::Test(int i)
{
	//this->f = ReflectableFunction<int, int>([this](int i) -> int { return x; });
	return 1;
}

RT::RT(function<int(int)> f, function<int(int)> t) : f(f), t(t) { }

RT::RT() : RT(
	[this](int i) -> int
	{
		jabber();
		return z;
	},
	[this](int i) -> int
	{
		this->z = 5;
		return this->f(z);
	})
{ }

RT::RT(int g) : RT()
{
}

void RT::jabber() 
{ 
}