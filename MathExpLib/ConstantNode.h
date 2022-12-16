//--------------------------------------------------
// A node that wrappers a constant
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

#include <NVLib/StringUtils.h>

#include "LeafNode.h"

namespace NVL_AI
{
	class ConstantNode : public LeafNode
	{
	private:
		double _value;
	public:
		ConstantNode(int value);

		virtual double Evaluate(const vector<double>& params);
		virtual string GetCode();
		virtual string GetType();

		inline double& GetValue() { return _value; }
	};
}
