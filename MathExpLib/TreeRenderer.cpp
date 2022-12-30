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
	throw runtime_error("Not implemented");
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
	throw runtime_error("Not implemented");
}
