//--------------------------------------------------
// A node that inverts the value that it "wrappers"
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
	class InvertNode : public MonoNode
	{
	public:
		InvertNode();

		virtual double Evaluate(const vector<double>& params);
		virtual string GetCode();
		virtual string GetType();
	};
}
