//--------------------------------------------------
// A node that negates the value that it "wrappers"
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#include "MonoNode.h"

namespace NVL_AI
{
	class NegateNode : public MonoNode
	{
	public:
		NegateNode();

		virtual double Evaluate(const vector<double>& params);
		virtual string GetCode();
		virtual string GetType();
		virtual void GetGenes(vector<int>& dna);
		virtual NodeBase* Clone() override;
	};
}
