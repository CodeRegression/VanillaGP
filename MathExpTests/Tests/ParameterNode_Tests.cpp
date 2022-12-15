//--------------------------------------------------
// Unit Tests for class ParameterNode
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ParameterNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test retrieval of the node name
 */
TEST(ParameterNode_Test, node_name)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(ParameterNode_Test, evaluate)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Test 
 */
TEST(ParameterNode_Test, code_generation)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Attempt to add a child to the system
 */
TEST(ParameterNode_Test, add_child)
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
 * @brief Attempt to retrieve a child from the system
 */
TEST(ParameterNode_Test, retrieve_child)
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
