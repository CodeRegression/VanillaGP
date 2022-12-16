//--------------------------------------------------
// Unit Tests for class NegateNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ConstantNode.h>
#include <MathExpLib/NegateNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test retrieval of the node type
 */
TEST(NegateNode_Test, node_type)
{
	auto node = NegateNode();
	ASSERT_EQ(node.GetType(), "negate_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(NegateNode_Test, evaluate)
{
	auto parameters = vector<double> { 1, 2, 3 };
	auto child = new ConstantNode(100);
	auto node = NegateNode(); node.AddChild(0, child);
	ASSERT_EQ(node.Evaluate(parameters), -1);
}

/**
 * @brief Test that the code generation is working effectively
 */
TEST(NegateNode_Test, code_generation)
{
	auto child = new ConstantNode(100);
	auto node = NegateNode(); node.AddChild(0, child);
	ASSERT_EQ(node.GetCode(), "-1");
}

/**
 * @brief Determine if the child count is correct
 */
TEST(NegateNode_Test, child_count)
{
	auto node = NegateNode();
	ASSERT_EQ(node.GetChildCount(), 1);
}