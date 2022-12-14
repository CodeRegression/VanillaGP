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
	private:
		vector<int> _available;
	public:
		SolutionFactoryBase(vector<int>& available) :
			_available(available) {}

		virtual SolutionBase * Create(InitializerBase * initializer) = 0;
		virtual SolutionBase * Breed(SolutionBase * mother, SolutionBase * father) = 0;
		virtual SolutionBase * Mutate(double probability) = 0;
	};
}
