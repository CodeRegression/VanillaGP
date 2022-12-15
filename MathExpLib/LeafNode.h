//--------------------------------------------------
// A base class for a node without children
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
	class LeafNode : public NodeBase
	{
	public:
		LeafNode() : NodeBase(0) {}

		virtual bool IsComplete() override { return true; }
	};
}
