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
	auto node = ParameterNode(1);
	ASSERT_EQ(node.GetType(), "parameter_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(ParameterNode_Test, evaluate)
{
	auto parameters = vector<double> {1, 2, 3, 4 };
	auto node = ParameterNode(1);
	ASSERT_EQ(node.Evaluate(parameters), 2);
}

/**
 * @brief Confirm that code evaulation is working as expected
 */
TEST(ParameterNode_Test, code_generation)
{
	auto node = ParameterNode(2);
	ASSERT_EQ(node.GetCode(), "p[2]");
}

/**
 * @brief Confirm that the child count is correct
 */
TEST(ParameterNode_Test, child_count)
{
	auto node = ParameterNode(2);
	ASSERT_EQ(node.GetChildCount(), 0);
}

/**
 * @brief Attempt to add a child to the system
 */
TEST(ParameterNode_Test, add_child)
{
	// Setup
	auto expected = string("Child index is out of range");

	// Execute
	try
	{
		auto node = ParameterNode(1);
		node.AddChild(0, nullptr);
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
	auto expected = string("Child index is out of range");

	// Execute
	try
	{
		auto node = ParameterNode(1);
		auto child = node.GetChild(0);
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
