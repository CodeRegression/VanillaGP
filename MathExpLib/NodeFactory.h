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

#include "NodeBase.h"
#include "ParameterNode.h"
#include "AddNode.h"

namespace NVL_AI
{
	class NodeFactory
	{
	public:
		enum class NodeType { PARAMETER_NODE = 1, ADD_NODE = 2};
	private:
		int _paramCount;
	public:
		NodeFactory(int paramCount);
		NodeBase * CreateNode(NodeType nodeType, InitializerBase * initializer);
	};
}