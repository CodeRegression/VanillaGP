//--------------------------------------------------
// The set of properties associated with the generation of trees
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

namespace NVL_AI
{
	class TreeProperties
	{
	private:
		vector<int> _availableNodes;
		int _depthLimit;
		int _paramCount;
	public:
		TreeProperties(vector<int>& availableNodes, int depthLimit, int paramCount) :
			_availableNodes(availableNodes), _depthLimit(depthLimit), _paramCount(paramCount) {}

		inline vector<int>& GetAvailableNodes() { return _availableNodes; }
		inline int& GetDepthLimit() { return _depthLimit; }
		inline int& GetParamCount() { return _paramCount; }
	};
}
