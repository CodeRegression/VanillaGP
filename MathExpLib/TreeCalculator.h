//--------------------------------------------------
// Used to calculate the score of a given solution
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <VanillaGPLib/GrammarBase/CalculatorBase.h>

#include "TreeFactory.h"

namespace NVL_AI
{
	class TreeCalculator : public CalculatorBase
	{
    public:
		TreeCalculator(SolutionFactoryBase * factory, Mat& params);
		virtual Mat Eval(Solution * solution) override;
	};
}
