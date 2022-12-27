//--------------------------------------------------
// Implementation of class ProblemLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include "ProblemLoader.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param problemCode The code of the problem we are processing
 * @param dataFile The path to the associated data file
 */
ProblemLoader::ProblemLoader(const string& problemCode, const string& dataFile)
{
	throw runtime_error("Not implemented");
}

/**
 * @brief Main Terminator
 */
ProblemLoader::~ProblemLoader()
{
	// TODO: Add termination functionality
}

//--------------------------------------------------
// Loader
//--------------------------------------------------

/**
 * @brief Load problem details
 * @param codeDash Link to the code data database
 */
void ProblemLoader::Load(CodeDash * codeDash)
{
	throw runtime_error("Not implemented");
}