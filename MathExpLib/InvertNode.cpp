//--------------------------------------------------
// Implementation of class InvertNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "InvertNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
InvertNode::InvertNode() : MonoNode()
{
	// Extra implementation goes here
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Evaluate this node (along with children)
 * @param params The input parameters associated with the application
 * @return double Returns a double
 */
double InvertNode::Evaluate(const vector<double>& params)
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot evaluate if not complete");
	auto value = GetChild(0)->Evaluate(params); 
	return 1.0 / value;
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string InvertNode::GetCode()
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot generate code if not complete");
	auto formatter = stringstream();
	auto child = GetChild(0)->GetCode();
	formatter << "(1.0 / " << child << ")";
	return formatter.str();
}

/**
 * @brief Retrieve the name associated with the node
 * @return string Returns a string
 */
string InvertNode::GetType()
{
	return "invert_node";
}

/**
 * @brief Add the functionality to get a particular node
 * @param dna The DNA elements that we are adding to
 */
void InvertNode::GetGenes(vector<int>& dna) 
{
	dna.push_back(3);
}

/**
 * @brief Clone this node
 * @return NodeBase* The newly generated node
 */
NodeBase* InvertNode::Clone() 
{
	return new InvertNode();
}