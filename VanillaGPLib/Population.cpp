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
 * @param problemCode The name of the associated problem
 * @param grammar The name of the grammar that we are using
 * @param populationSize The size that we want the population to be
 * @param generationLimit The maximum generations we want before termination
 * @param sameScoreLimit The number of times we can not have progress before we give up
 * @param reuseRatio The number of initial 'promising' solutions we can reuse
 */
Population::Population(SolutionFactoryBase * factory, CodeDash * codeDash, const string& problemCode, const string& evaluation, int populationSize, int generationLimit, int sameScoreLimit, double reuseRatio) :
	_factory(factory), _codeDash(codeDash), _generationLimit(generationLimit), _sameScoreLimit(sameScoreLimit)
{
	// Extra initialization
	_generation = 0;
	_sameScore = 0;
	_solutionFound = false;

	// Load the "reuse" population from CodeDash
	auto reuseSize = (int)ceil(populationSize * reuseRatio);
	if (reuseSize > 0) LoadCodeDashPopulation(problemCode, factory->GetGrammarName(), evaluation, factory->GetDepthLimit(), reuseSize);

	// Fill the remaining population with random stuff
	FillPopulation(populationSize);
}

/**
 * @brief Add the the logic to fill a population from the given database
 * @param problemCode The problem code that we are using
 * @param grammar The grammar that we are using
 * @param depth The associated depth
 * @param size The size of the problem that we are using
 */
void Population::LoadCodeDashPopulation(const string& problemCode, const string& grammar, const string& evaluation, int depth, int size) 
{
	auto response = _codeDash->GetSolutions(problemCode, grammar, evaluation, depth, size);
	auto lines = vector<string>(); NVLib::StringUtils::Split(response, '|', lines);

	for (auto& line : lines) 
	{
		if (line == string()) continue;
		auto parts = vector<string>(); NVLib::StringUtils::Split(line, ',', parts);
		auto dna = vector<int>(); for (auto& part : parts) dna.push_back(NVLib::StringUtils::String2Int(part));
		_population.push_back(new Solution(dna));
	}
}

/**
 * @brief Use the factory to generate random members of the population
 * @param size The size of the population we are generation
 */
void Population::FillPopulation(int size) 
{
	auto initializer = RandomInitializer(time(0));

	while (_population.size() < size) 
	{
		auto solution = _factory->Generate(&initializer, 0);
		_population.push_back(solution);
	}
}

/**
 * @brief Main Terminator
 */
Population::~Population()
{
	for (auto solution : _population) delete solution;
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
