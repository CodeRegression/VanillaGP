//--------------------------------------------------
// A base class for a node with exactly two children
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "NodeBase.h"

namespace NVL_AI
{
	class BinaryNode : public NodeBase
	{
		public:
			BinaryNode() : NodeBase(2) {}

			virtual bool IsComplete() override 
			{
				auto child1 = GetChild(0);
				auto child2 = GetChild(1);
				return child1 != nullptr && child2 != nullptr;				
			}
	};
}
