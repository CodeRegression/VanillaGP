//--------------------------------------------------
// A node generate factory based on a given initializer
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <VanillaGPLib/GrammarBase/InitializerBase.h>

#include "AddNode.h"
#include "ConstantNode.h"
#include "InvertNode.h"
#include "MultiplyNode.h"
#include "NegateNode.h"
#include "ParameterNode.h"
#include "PowerNode.h"

namespace NVL_AI
{
	class NodeFactory
	{
	public:
		enum class NodeType 
		{ 
			ADD_NODE = 1, 
			CONSTANT_NODE = 2, 
			INVERT_NODE = 3,
			MULTIPLY_NODE = 4,
			NEGATE_NODE = 5,
			PARAMETER_NODE = 6,
			POWER_NODE = 7
		};
	private:
		int _paramCount;
	public:
		NodeFactory(int paramCount);
		NodeBase * CreateNode(NodeType nodeType, InitializerBase * initializer);
	};
}