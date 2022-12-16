//--------------------------------------------------
// Implementation of class PowerNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "PowerNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
PowerNode::PowerNode() : BinaryNode()
{
	// Extra implementation
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Evaluate this node (along with children)
 * @param params The input parameters associated with the application
 * @return double Returns a double
 */
double PowerNode::Evaluate(const vector<double>& params)
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot evaluate if not complete");
	auto value1 = GetChild(0)->Evaluate(params); 
	auto value2 = GetChild(1)->Evaluate(params);
	return pow(value1, value2);
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string PowerNode::GetCode()
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot generate code if not complete");
	auto formatter = stringstream();
	auto child1 = GetChild(0)->GetCode();
	auto child2 = GetChild(1)->GetCode();
	formatter << "pow(" << child1 << ", " << child2 << ")";
	return formatter.str();
}

/**
 * @brief Retrieve the name associated with the node
 * @return string Returns a string
 */
string PowerNode::GetType()
{
	return "power_node";
}