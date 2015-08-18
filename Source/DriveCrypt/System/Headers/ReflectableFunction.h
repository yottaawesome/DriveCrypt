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

#include "Invocable.h"
#include "TemplatePoly.h"
#include "PublicInvocable.h"

class RT
{
public:
	RT();
	RT(int g);
	PublicInvocable<int, int> f;// = [this](int i) -> int { return x; };
	PublicInvocable<int, int> t;// = [this](int i) -> int { return x; };

protected:
	Invocable<int, int> inner_f;// = [this](int i) -> int { return x; };
	Invocable<int, int> inner_t;// = [this](int i) -> int { return x; };
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

RT::RT(function<int(int)> param_f, function<int(int)> param_t) : inner_f(param_f), inner_t(param_t), f(inner_f), t(inner_t) { }

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
	inner_f = [this](int i) -> int
	{
		jabber();
		return z;
	};
}

void RT::jabber() 
{ 
}