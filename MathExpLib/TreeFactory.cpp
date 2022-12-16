//--------------------------------------------------
// Implementation of class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "TreeFactory.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Initializer Constructor
 * @param properties Initialize variable <properties>
 */
TreeFactory::TreeFactory(TreeProperties *& properties)
{
	_properties = properties;
}

/**
 * @brief Main Terminator
 */
TreeFactory::~TreeFactory()
{
	// TODO: Add terminator logic here
}

//--------------------------------------------------
// Methods
//--------------------------------------------------

/**
 * @brief Create a solution
 * @param initializer The initializer that we are going to use
 * @return SolutionBase * Returns a SolutionBase *
 */
SolutionBase * TreeFactory::Create(InitializerBase * initializer)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Breed two solutions to get a child
 * @param initializer The initializer that we will use to make the choices for the breeding
 * @param mother The `mother` of the child solution that we are creating
 * @param father The `father` of the child solution that we are creating
 * @return SolutionBase * Returns a SolutionBase *
 */
SolutionBase * TreeFactory::Breed(InitializerBase * initializer, SolutionBase * mother, SolutionBase * father)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Mutate a solution
 * @param initializer The initailizer that we will use to make the choices for the mutation
 * @param probability The probability that a mutation occurs
 * @return SolutionBase * Returns a SolutionBase *
 */
SolutionBase * TreeFactory::Mutate(InitializerBase * initializer, double probability)
{
	throw runtime_error("Not implemented");
}
