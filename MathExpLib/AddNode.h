//--------------------------------------------------
// A function node that adds two nodes together
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#include "BinaryNode.h"

namespace NVL_AI
{
	class AddNode : public BinaryNode
	{
	public:
		AddNode();

		virtual double Evaluate(const vector<double>& params) override;
		virtual string GetCode() override;
		virtual string GetType() override;
		virtual void GetGenes(vector<int>& dna) override;
		virtual NodeBase* Clone() override;
	};
}
