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
 * @param paramIndex The index of the parameter that this node "wrappers"
 */
ParameterNode::ParameterNode(int paramIndex) : LeafNode(), _paramIndex(paramIndex)
{
	// Extra initialization can happen here
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
	if (_paramIndex < 0 || _paramIndex >= params.size()) throw runtime_error("The parameter index appears to be out of range");
	return params[_paramIndex];
}

/**
 * @brief Generate source code for this node (including children)
 * @return string Returns a string
 */
string ParameterNode::GetCode()
{
	auto formatter = stringstream();
	formatter << "p[" << _paramIndex << "]";
	return formatter.str();
}

/**
 * @brief Retrieve the name assiociated with the node
 * @return string Returns a string
 */
string ParameterNode::GetType()
{
	return "parameter_node";
}

/**
 * @brief Add the functionality to get a particular node
 * @param dna The DNA elements that we are adding to
 */
void ParameterNode::GetGenes(vector<int>& dna) 
{
	dna.push_back(6); dna.push_back(_paramIndex);
}

/**
 * @brief Clone this node
 * @return NodeBase* The newly generated node
 */
NodeBase* ParameterNode::Clone() 
{
	return new ParameterNode(_paramIndex);
}