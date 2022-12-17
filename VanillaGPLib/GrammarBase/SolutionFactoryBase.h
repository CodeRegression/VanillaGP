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

#include "SolutionBase.h"

namespace NVL_AI
{
	class SolutionFactoryBase
	{
	public:
		SolutionFactoryBase() {}

		virtual SolutionBase * Create(InitializerBase * initializer, int level) = 0;
		virtual SolutionBase * Breed(InitializerBase * initializer, SolutionBase * mother, SolutionBase * father) = 0;
		virtual SolutionBase * Mutate(InitializerBase * initializer, double probability) = 0;
	};
}
