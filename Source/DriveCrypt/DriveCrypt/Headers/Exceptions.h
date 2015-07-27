#pragma once
#include <stdexcept>

using namespace std;

class DriveCryptException : virtual public exception
{
public:
	DriveCryptException(const char* const& what) : exception(what) { }
};

