//--------------------------------------------------
// A factory for generating new expression trees in various ways
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <VanillaGPLib/GrammarBase/SolutionFactoryBase.h>

#include "TreeProperties.h"

namespace NVL_AI
{
	class TreeFactory : public SolutionFactoryBase
	{
	private:
		TreeProperties * _properties;

	public:
		TreeFactory(TreeProperties *& properties);
		~TreeFactory();

		virtual SolutionBase * Create(InitializerBase * initializer) override;
		virtual SolutionBase * Breed(InitializerBase * initializer, SolutionBase * mother, SolutionBase * father) override;
		virtual SolutionBase * Mutate(InitializerBase * initializer, double probability) override;
	};
}
