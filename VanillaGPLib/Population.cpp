//--------------------------------------------------
// Implementation of class Population
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include "Population.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Main Constructor
 * @param factory A factory for generating solutions
 * @param codeDash A link to the CodeDash engine
 * @param populationSize The size that we want the population to be
 * @param generationLimit The maximum generations we want before termination
 * @param sameScoreLimit The number of times we can not have progress before we give up
 * @param reuseRatio The number of initial 'promising' solutions we can reuse
 */
Population::Population(SolutionFactoryBase * factory, CodeDash * codeDash, int populationSize, int generationLimit, int sameScoreLimit, double reuseRatio)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Main Terminator
 */
Population::~Population()
{
	// TODO: Add terminator logic here
}

//--------------------------------------------------
// Evaluate
//--------------------------------------------------

/**
 * @brief Evaluate the population
 * @param evaluator Used to evaluate the solutions within the popluation
 * @param retainCount The number of good solutions to keep for the next generation
 */
void Population::Evaluate(EvaluatorBase * evaluator, int retainCount)
{
	throw runtime_error("Not implemented");
}

//--------------------------------------------------
// Next Generation
//--------------------------------------------------

/**
 * @brief Creates the next generation
 * @param mutate The percentage of elements to mutate
 */
void Population::NextGeneration(double mutate)
{
	throw runtime_error("Not implemented");
}

//--------------------------------------------------
// Terminate Check
//--------------------------------------------------

/**
 * @brief Checks to see if we should terminate the process or not
 * @return bool Returns a bool
 */
bool Population::Terminate()
{
	throw runtime_error("Not implemented");
}
