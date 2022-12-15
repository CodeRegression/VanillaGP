//--------------------------------------------------
// Implementation of class ParameterNode
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include "ParameterNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
ParameterNode::ParameterNode()
{
	throw runtime_error("Not implemented");
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Evaluate this node (along with children)
 * @param params The input parameters associated with the application
 * @return double Returns a double
 */
double ParameterNode::Evaluate(const vector<double>& params)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string ParameterNode::GetCode()
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Retrieve the name assiociated with the node
 * @return string Returns a string
 */
string ParameterNode::GetNodeName()
{
	throw runtime_error("Not implemented");
}
