//--------------------------------------------------
// Unit Tests for class MultiplyNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ConstantNode.h>
#include <MathExpLib/MultiplyNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test retrieval of the node type
 */
TEST(MultiplyNode_Test, node_type)
{
	auto node = MultiplyNode();
	ASSERT_EQ(node.GetType(), "multiply_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(MultiplyNode_Test, evaluate)
{
	auto parameters = vector<double> {1, 2, 3,};
	auto input_1 = new ConstantNode(200);
	auto input_2 = new ConstantNode(400);
	auto node = MultiplyNode(); node.AddChild(0, input_1); node.AddChild(1, input_2);
	ASSERT_EQ(node.Evaluate(parameters), 8);
}

/**
 * @brief Test that the code generation is working effectively
 */
TEST(MultiplyNode_Test, code_generation)
{
	auto input_1 = new ConstantNode(200);
	auto input_2 = new ConstantNode(400);
	auto node = MultiplyNode(); node.AddChild(0, input_1); node.AddChild(1, input_2);
	ASSERT_EQ(node.GetCode(), "(2 * 4)");
}

/**
 * @brief Determine if the child count is correct
 */
TEST(MultiplyNode_Test, child_count)
{
	auto node = MultiplyNode();
	ASSERT_EQ(node.GetChildCount(), 2);
}
