//--------------------------------------------------
// A base class for a node with exactly one child
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

#include "NodeBase.h"

namespace NVL_AI
{
	class MonoNode : public NodeBase
	{
	public:
		MonoNode() : NodeBase(1) {}

		virtual bool IsComplete() override 
		{
			auto child = GetChild(0);
			return child != nullptr;	
		}
	};
}