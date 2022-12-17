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
		vector<int> _dna;
	public:
		ExpressionTree(NodeBase * root);

		virtual string GetCode() override;
		virtual double Evaluate(const vector<double>& params) override;
	
		inline NodeBase * GetRoot() { return _root; }
		inline vector<int> GetDNA() { if (_dna.size() == 0) BuildDNA(); return _dna; }
	private:
		void BuildDNA();
	};
}
