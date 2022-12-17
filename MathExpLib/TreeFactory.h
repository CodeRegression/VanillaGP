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
#include <VanillaGPLib/GrammarBase/RandomInitializer.h>

#include "NodeFactory.h"
#include "TreeProperties.h"

namespace NVL_AI
{
	class TreeFactory : public SolutionFactoryBase
	{
	private:
		TreeProperties * _properties;
		vector<int> _availableTerminals;
		vector<int> _availableFunctions;
	public:
		TreeFactory(TreeProperties * properties);
		~TreeFactory();

		virtual SolutionBase * Create(InitializerBase * initializer) override;
		virtual SolutionBase * Breed(InitializerBase * initializer, SolutionBase * mother, SolutionBase * father) override;
		virtual SolutionBase * Mutate(InitializerBase * initializer, double probability) override;

	private:
		NodeBase * GenerateNode(InitializerBase * initializer, const vector<int>& available);
		void InitializeNodeCollections(vector<int>& available);
	};
}
