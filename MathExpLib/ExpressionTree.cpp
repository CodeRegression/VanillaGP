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
 * @param dna The "dna" string that characterizes this tree
 */
ExpressionTree::ExpressionTree(NodeBase * root, const vector<int>& dna) : _root(root), SolutionBase(dna)
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
