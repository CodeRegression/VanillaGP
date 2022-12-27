//--------------------------------------------------
// Unit Tests for class ProblemLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/ProblemLoader.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Handles invalid problem loading
 */
TEST(ProblemLoader_Test, invalid_problem)
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
 * @brief Handles the problem that the data file is missing
 */
TEST(ProblemLoader_Test, missing_file)
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
 * @brief Handles the problem that the hashcode of the problem is missing
 */
TEST(ProblemLoader_Test, invalid_hash)
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
 * @brief Defines a normal loading of the functionality
 */
TEST(ProblemLoader_Test, valid_load)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}
