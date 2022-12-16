//--------------------------------------------------
// The solution that we are adding to the system
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <VanillaGPLib/GrammarBase/SolutionBase.h>
#include "NodeBase.h"

namespace NVL_AI
{
	class ExpressionTree : public SolutionBase
	{
	private:
		NodeBase * _root;

	public:
		ExpressionTree(NodeBase * root, const vector<int>& dna);

		virtual string GetCode() override;
		virtual double Evaluate(const vector<double>& params) override;

		inline NodeBase *& GetRoot() { return _root; }
	};
}
