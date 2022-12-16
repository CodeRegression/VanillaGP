//--------------------------------------------------
// A function node that calculates the value to a given power
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <cmath>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

#include "BinaryNode.h"

namespace NVL_AI
{
	class PowerNode : public BinaryNode
	{
	public:
		PowerNode();

		virtual double Evaluate(const vector<double>& params);
		virtual string GetCode();
		virtual string GetType();
	};
}
