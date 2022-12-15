//--------------------------------------------------
// A base class for the given node
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

#include "LeafNode.h"

namespace NVL_AI
{
	class ParameterNode : public LeafNode
	{
		private:
			int _paramIndex;
		public:
			ParameterNode(int paramIndex);

			virtual double Evaluate(const vector<double>& params) override;
			virtual string GetCode() override;
			virtual string GetType() override;

			inline int& GetParamIndex() { return _paramIndex; }
	};
}
