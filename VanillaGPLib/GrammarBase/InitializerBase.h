//--------------------------------------------------
// A base class of a grammar initializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
using namespace std;

namespace NVL_AI
{
	class InitializerBase
	{
	public:
		InitializerBase() {}

		virtual int GetNext(int minValue, int maxValue) = 0;
	};
}
