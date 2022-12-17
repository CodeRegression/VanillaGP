//--------------------------------------------------
// Implementation of class NegateNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "NegateNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
NegateNode::NegateNode() : MonoNode()
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
double NegateNode::Evaluate(const vector<double>& params)
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot evaluate if not complete");
	auto value = GetChild(0)->Evaluate(params); 
	return -value;
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string NegateNode::GetCode()
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot generate code if not complete");
	auto formatter = stringstream();
	auto child = GetChild(0)->GetCode();
	formatter << "-" << child;
	return formatter.str();
}

/**
 * @brief Retrieve the name associated with the node
 * @return string Returns a string
 */
string NegateNode::GetType()
{
	return "negate_node";
}

/**
 * @brief Add the functionality to get a particular node
 * @param dna The DNA elements that we are adding to
 */
void NegateNode::GetGenes(vector<int>& dna) 
{
	dna.push_back(5);
}