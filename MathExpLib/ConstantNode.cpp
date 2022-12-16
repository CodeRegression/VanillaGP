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
ConstantNode::ConstantNode(int value) : LeafNode()
{
	_value = value / 100.0;
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
	return _value;
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string ConstantNode::GetCode()
{
	return NVLib::StringUtils::Double2String(_value);
}

/**
 * @brief Retrieve the name assiociated with the node
 * @return string Returns a string
 */
string ConstantNode::GetType()
{
	return "constant_node";
}