//--------------------------------------------------
// Implementation of class TreeRenderer
//
// @author: Wild Boar
//
// @date: 2022-12-30
//--------------------------------------------------

#include "TreeRenderer.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param factory The factory for reconstruction purposes
 */
TreeRenderer::TreeRenderer(SolutionFactoryBase * factory) : RendererBase(factory)
{
	// Extra implementation can go here
}

//--------------------------------------------------
// Render
//--------------------------------------------------

/**
 * @brief Render the solution
 * @param solution The solution that we are rendering
 * @return string Returns a string
 */
string TreeRenderer::Render(Solution * solution)
{
	auto treeFactory = (TreeFactory *) GetFactory();
    auto tree = treeFactory->Solution2Tree(solution);

	auto result = tree->GetCode();

	delete tree;

	return result;
}
