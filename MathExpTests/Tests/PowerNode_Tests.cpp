//--------------------------------------------------
// Unit Tests for class PowerNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ConstantNode.h>
#include <MathExpLib/PowerNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * Confirm that the DNA that we are using correct
 */
TEST(PowerNode_Test, node_dna) 
{
	auto node = PowerNode();
	auto gene = vector<int>(); node.GetGenes(gene);
	ASSERT_EQ(gene.size(), 1);
	ASSERT_EQ(gene[0], 7);
}

/**
 * @brief Test retrieval of the node type
 */
TEST(PowerNode_Test, node_type)
{
	auto node = PowerNode();
	ASSERT_EQ(node.GetType(), "power_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(PowerNode_Test, evaluate)
{
	auto parameters = vector<double> {1, 2, 3};
	auto child_1 = new ConstantNode(400);
	auto child_2 = new ConstantNode(200);
	auto node = PowerNode(); node.AddChild(0, child_1); node.AddChild(1, child_2);
	ASSERT_EQ(node.Evaluate(parameters), 16);
}

/**
 * @brief Test that the code generation is working effectively
 */
TEST(PowerNode_Test, code_generation)
{
	auto child_1 = new ConstantNode(400);
	auto child_2 = new ConstantNode(200);
	auto node = PowerNode(); node.AddChild(0, child_1); node.AddChild(1, child_2);
	ASSERT_EQ(node.GetCode(), "pow(4, 2)");
}

/**
 * @brief Determine if the child count is correct
 */
TEST(PowerNode_Test, child_count)
{
	auto node = PowerNode();
	ASSERT_EQ(node.GetChildCount(), 2);
}
