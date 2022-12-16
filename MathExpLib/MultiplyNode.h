//--------------------------------------------------
// A function node that multiplies two nodes together
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

#include "BinaryNode.h"

namespace NVL_AI
{
	class MultiplyNode : public BinaryNode
	{
	public:
		MultiplyNode();

		virtual double Evaluate(const vector<double>& params);
		virtual string GetCode();
		virtual string GetType();
	};
}
