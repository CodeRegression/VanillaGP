//--------------------------------------------------
// A base class for the factory that generates new solutions
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "Solution.h"

#include "InitializerBase.h"

namespace NVL_AI
{
	class SolutionFactoryBase
	{
	public:
		SolutionFactoryBase() {}

		virtual Solution * Generate(InitializerBase * initializer, int level) = 0;
		virtual Solution * Breed(InitializerBase * initializer, Solution * mother, Solution * father) = 0;
		virtual Solution * Mutate(InitializerBase * initializer, Solution * solution, double probability) = 0;	
	};
}
