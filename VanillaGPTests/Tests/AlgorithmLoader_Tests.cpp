//--------------------------------------------------
// Unit Tests for class AlgorithmLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/AlgorithmLoader.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Handles the case that an invalid algorithm code was used
 */
TEST(AlgorithmLoader_Test, invalid_code)
{
	// Setup
	auto expected = string("Not implemented");

	// Execute
	try
	{
		// TODO: Add call here
		FAIL() << "Expected exception: " << expected;
	}
	catch(runtime_error exception)
	{
		ASSERT_EQ(exception.what(), expected);
	}
	catch(...)
	{
		FAIL() << "Expected exception: " << expected;
	}
}

/**
 * @brief Confirm the case of a valid application load
 */
TEST(AlgorithmLoader_Test, valid_load)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}
