//--------------------------------------------------
// Unit Tests for class AddNode
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ParameterNode.h>
#include <MathExpLib/AddNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * Confirm that the DNA that we are using correct
 */
TEST(AddNode_Test, node_dna) 
{
	auto node = AddNode();
	auto gene = vector<int>(); node.GetGenes(gene);
	ASSERT_EQ(gene.size(), 1);
	ASSERT_EQ(gene[0], 1);
}

/**
 * @brief Test retrieval of the node name
 */
TEST(AddNode_Test, node_name)
{
	auto node = AddNode();
	ASSERT_EQ(node.GetType(), "add_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(AddNode_Test, evaluate)
{
	auto parameters = vector<double> {2, 3};
	auto child1 = new ParameterNode(0);
	auto child2 = new ParameterNode(1);
	auto adder = AddNode(); adder.AddChild(0, child1); adder.AddChild(1, child2);
	ASSERT_EQ(adder.Evaluate(parameters), 5);
}

/**
 * @brief Evaluation Fail
 */
TEST(AddNode_Test, evaluation_fail)
{
	// Setup
	auto expected = string("Cannot evaluate if not complete");

	// Execute
	try
	{
		auto parameters = vector<double> {2, 3};
		auto adder = AddNode();
		ASSERT_EQ(adder.Evaluate(parameters), 5);
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
 * @brief Test that the code generation is working effectively
 */
TEST(AddNode_Test, code_generation)
{
	auto child1 = new ParameterNode(0);
	auto child2 = new ParameterNode(1);
	auto adder = AddNode(); adder.AddChild(0, child1); adder.AddChild(1, child2);
	ASSERT_EQ(adder.GetCode(), "(p[0] + p[1])");
}

/**
 * @brief Determine if the child count is correct
 */
TEST(AddNode_Test, child_count)
{
	auto node = AddNode();
	ASSERT_EQ(node.GetChildCount(), 2);
}

/**
 * @brief Attempt to add a child to the system
 */
TEST(AddNode_Test, add_child)
{
	// Setup
	auto expected = string("Child index is out of range");

	// Execute
	try
	{
		auto node = AddNode();
		node.AddChild(2, nullptr);
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
TEST(AddNode_Test, retrieve_child)
{
	// Setup
	auto expected = string("Child index is out of range");

	// Execute
	try
	{
		auto node = AddNode();
		auto child = node.GetChild(2);
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
