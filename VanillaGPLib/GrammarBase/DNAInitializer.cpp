//--------------------------------------------------
// Implementation of class DNAInitializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include "DNAInitializer.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param dna The DNA that we are initializing with
 */
DNAInitializer::DNAInitializer(const vector<int>& dna) : _position(0)
{
	_source = vector<int>(dna);
	if (_source.size() == 0) throw runtime_error("No DNA was provided");
}

//--------------------------------------------------
// Extract Random Variables
//--------------------------------------------------

/**
 * @brief Retrieve the next `gene`
 * @param minValue The minimum value that we should be retrieving
 * @param maxValue The maximumu value that we should be retrieving
 * @return int Returns a int
 */
int DNAInitializer::GetNext(int minValue, int maxValue)
{
	if (_position >= _source.size()) ResetPointer();
	auto value = _source[_position++];
	if (value < minValue || value > maxValue) throw runtime_error("Predefined DNA failed range test");
	return value;
}

/**
 * @brief Retrieve the next gene (and confirm that it is from the given range)
 * @param available The available range
 * @return int The value taht we have
 */
int DNAInitializer::GetNext(const vector<int>& available) 
{
	// Get the next value in the sequence
	if (_position >= _source.size()) ResetPointer();
	auto value = _source[_position++];

	// If this is a valid value, then return it
	for (auto& valid : available) if (valid == value) return value;
	
	// No valid value was found - so throw an exception
	throw runtime_error("The supplied value does not appear to be from the supplied range");
}

//--------------------------------------------------
// Add the logic to reset a pointer
//--------------------------------------------------

/**
 * @brief Add the logic to reset the given pointer
 */
void DNAInitializer::ResetPointer()
{
	_position = 0;
}