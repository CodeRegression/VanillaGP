//--------------------------------------------------
// Implementation of class RandomInitializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include "RandomInitializer.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param seed Set the random number seed that we are generating
 */
RandomInitializer::RandomInitializer(int seed)
{
	srand(seed);
}

//--------------------------------------------------
// Retrieve Random Selections
//--------------------------------------------------

/**
 * @brief Retrieve the next `gene`
 * @param minValue The minimum value that we should be retrieving
 * @param maxValue The maximumu value that we should be retrieving
 * @return int Returns a int
 */
int RandomInitializer::GetNext(int minValue, int maxValue)
{
	auto result = NVLib::RandomUtils::GetInteger(NVLib::Range(minValue, maxValue));
	return result;
}

/**
 * @brief Select a random element from a given range
 * @param available The available range that we are selecting from
 * @return int The value that we have selected from
 */
int RandomInitializer::GetNext(const vector<int>& available) 
{
	if (available.size() == 0) throw runtime_error("Cannot select from an empty group");
	auto index = GetNext(0, available.size());
	return available[index];
}