//--------------------------------------------------
// Implementation of class NodeFactory
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "NodeFactory.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Initializer Constructor
 * @param paramCount Initialize variable <paramCount>
 */
NodeFactory::NodeFactory(int paramCount)
{
	_paramCount = paramCount;
}

//--------------------------------------------------
// Create
//--------------------------------------------------

/**
 * @brief Add the logic to create a new node
 * @param nodeType The type of node that we want to create
 * @param initializer An initializer for generating `extra` parameters to associated with the function
 * @return NodeBase * Returns a NodeBase *
 */
NodeBase * NodeFactory::CreateNode(NodeType nodeType, InitializerBase * initializer)
{
	throw runtime_error("Not implemented");
}