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

#include <NVLib/RandomUtils.h>

#include "InitializerBase.h"

namespace NVL_AI
{
	class RandomInitializer : public InitializerBase
	{
	public:
		RandomInitializer(int seed);
		virtual int GetNext(int minValue, int maxValue) override;
		virtual int GetNext(const vector<int>& available) override;
	};
}
