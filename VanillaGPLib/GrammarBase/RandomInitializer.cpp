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
// Methods
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