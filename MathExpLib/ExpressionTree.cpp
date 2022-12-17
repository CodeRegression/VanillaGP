//--------------------------------------------------
// Implementation of class ExpressionTree
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "ExpressionTree.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param root The root node of the expression tree that makes up this solution
 */
ExpressionTree::ExpressionTree(NodeBase * root) : _root(root), SolutionBase()
{
	// Extra implementation logic can go here
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Get the source code for this solution
 * @return string Returns a string
 */
string ExpressionTree::GetCode()
{
	return _root->GetCode();
}

/**
 * @brief Evaluate the solution for a given input
 * @param params The input parameters for which we are evaluating the expression
 * @return double Returns a double
 */
double ExpressionTree::Evaluate(const vector<double>& params)
{
	return _root->Evaluate(params);
}

//--------------------------------------------------
// DNA builder functionality
//--------------------------------------------------

/**
 * @brief Add the logic to build the given DNA of the tree
 */
void ExpressionTree::BuildDNA() 
{
	_dna.clear();

	auto current = vector<NodeBase *>(); current.push_back(_root);

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			node->GetGenes(_dna);
			for (auto i = 0; i < node->GetChildCount(); i++) next.push_back(node->GetChild(i));
		}

		current.clear(); for (auto node : next) current.push_back(node); 
	}
}