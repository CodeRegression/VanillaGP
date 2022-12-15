//--------------------------------------------------
// Implementation of class ConstantNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "ConstantNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param value The value representing the constant
 */
ConstantNode::ConstantNode(int value)
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
double ConstantNode::Evaluate(const vector<double>& params)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string ConstantNode::GetCode()
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Retrieve the name assiociated with the node
 * @return string Returns a string
 */
string ConstantNode::GetType()
{
	throw runtime_error("Not implemented");
}
