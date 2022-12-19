//--------------------------------------------------
// Implementation of class AddNode
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include "AddNode.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Default Constructor
 */
AddNode::AddNode() : BinaryNode()
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
double AddNode::Evaluate(const vector<double>& params)
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot evaluate if not complete");
	auto value1 = GetChild(0)->Evaluate(params); 
	auto value2 = GetChild(1)->Evaluate(params);
	return value1 + value2;
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string AddNode::GetCode()
{
	auto complete = IsComplete(); if (!complete) throw runtime_error("Cannot generate code if not complete");
	auto formatter = stringstream();
	auto child1 = GetChild(0)->GetCode();
	auto child2 = GetChild(1)->GetCode();
	formatter << "(" << child1 << " + " << child2 << ")";
	return formatter.str();
}

/**
 * @brief Retrieve the name assiociated with the node
 * @return string Returns a string
 */
string AddNode::GetType()
{
	return "add_node";
}

/**
 * @brief Add the functionality to get a particular node
 * @param dna The DNA elements that we are adding to
 */
void AddNode::GetGenes(vector<int>& dna) 
{
	dna.push_back(1);
}

/**
 * @brief Clone this node
 * @return NodeBase* The newly generated node
 */
NodeBase* AddNode::Clone() 
{
	return new AddNode();
}