#pragma once
#include "Invocable.h"
#include "TemplatePoly.h"

// PublicInvocable
template<typename R, typename... Args>
class PublicInvocable
{
public:
	PublicInvocable(Invocable<R, Args...>& f);
	~PublicInvocable();
	R operator()(Args... arg);
	R Invoke(Args... arg);
	const vector<string>& Typenames();

protected:
	Invocable<R, Args...>& f;

private:
	// Completely disable assignments
	void operator=(PublicInvocable a) = delete;
};

template<typename R, typename... Args>
PublicInvocable<R, Args...>::PublicInvocable(Invocable<R, Args...>& f) : f(f) { }

template<typename R, typename... Args>
PublicInvocable<R, Args...>::~PublicInvocable() { }

template<typename R, typename... Args>
R PublicInvocable<R, Args...>::operator()(Args... arg)
{
	return f(arg...);
}

template<typename R, typename... Args>
R PublicInvocable<R, Args...>::Invoke(Args... arg)
{
	return f(arg...);
}

template<typename R, typename... Args>
const vector<string>& PublicInvocable<R, Args...>::Typenames()
{
	return f.Typenames();
}
//