#pragma once
#include <string>

using namespace std;

namespace Shared
{
	class ILogger
	{
		public:
			virtual void info(short value) = 0;
			virtual void info(int value) = 0;
			virtual void info(float value) = 0;
			virtual void info(double value) = 0;
			virtual void info(string value) = 0;
			virtual void info(wstring value) = 0;
			virtual void info(string& value) = 0;
			virtual void info(wstring& value) = 0;

			virtual ~ILogger() {};
	};
}