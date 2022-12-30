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
#include <VanillaGPLib/GrammarBase/DNAInitializer.h>

#include "NodeFactory.h"
#include "TreeProperties.h"
#include "TreeCalculator.h"
#include "TreeRenderer.h"

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

		virtual Solution * Generate(InitializerBase * initializer, int level = 0) override;
		virtual Solution * Breed(InitializerBase * initializer, Solution * mother, Solution * father) override;
		virtual Solution * Mutate(InitializerBase * initializer, Solution * solution, double probability) override;

		virtual CalculatorBase * GetCalculator(const Mat& params) override;
		virtual RendererBase * GetRenderer() override;

		virtual string GetGrammarName() override { return "ETREE"; }
		virtual int GetDepthLimit() { return _properties->GetDepthLimit(); }

		Solution * Tree2Solution(NodeBase * root);
		NodeBase * Solution2Tree(Solution * solution);

	private:
		NodeBase * GenerateNode(InitializerBase * initializer, NodeFactory& factory, const vector<int>& available);
		void InitializeNodeCollections(vector<int>& available);
		NodeBase * BuildTree(InitializerBase * initializer, int level);
		void ExtractNodes(NodeBase* tree, vector<NodeBase *>& nodes, vector<int>& levels);
		NodeBase * ChooseNode(InitializerBase * initializer, int& nodeIndex, NodeFactory& factory, const vector<NodeBase *>& motherNodes, const vector<NodeBase *>& fatherNodes);
	};
}
