//--------------------------------------------------
// Implementation of class MultiplyNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "MultiplyNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
MultiplyNode::MultiplyNode() : BinaryNode()
{
	// Extra implementation can go here
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Evaluate this node (along with children)
 * @param params The input parameters associated with the application
 * @return double Returns a double
 */
double MultiplyNode::Evaluate(const vector<double>& params)
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot evaluate if not complete");
	auto value1 = GetChild(0)->Evaluate(params); 
	auto value2 = GetChild(1)->Evaluate(params);
	return value1 * value2;
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string MultiplyNode::GetCode()
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot generate code if not complete");
	auto formatter = stringstream();
	auto child1 = GetChild(0)->GetCode();
	auto child2 = GetChild(1)->GetCode();
	formatter << "(" << child1 << " * " << child2 << ")";
	return formatter.str();
}

/**
 * @brief Retrieve the name associated with the node
 * @return string Returns a string
 */
string MultiplyNode::GetType()
{
	return "multiply_node";
}

/**
 * @brief Add the functionality to get a particular node
 * @param dna The DNA elements that we are adding to
 */
void MultiplyNode::GetGenes(vector<int>& dna) 
{
	dna.push_back(4);
}

/**
 * @brief Clone this node
 * @return NodeBase* The newly generated node
 */
NodeBase* MultiplyNode::Clone() 
{
	return new MultiplyNode();
}