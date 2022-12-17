//--------------------------------------------------
// Unit Tests for class InvertNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ConstantNode.h>
#include <MathExpLib/InvertNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * Confirm that the DNA that we are using correct
 */
TEST(InvertNode_Test, node_dna) 
{
	auto node = InvertNode();
	auto gene = vector<int>(); node.GetGenes(gene);
	ASSERT_EQ(gene.size(), 1);
	ASSERT_EQ(gene[0], 3);
}

/**
 * @brief Test retrieval of the node type
 */
TEST(InvertNode_Test, node_type)
{
	auto node = InvertNode();
	ASSERT_EQ(node.GetType(), "invert_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(InvertNode_Test, evaluate)
{
	auto parameters = vector<double> {1, 2, 3};
	auto child = new ConstantNode(200);
	auto node = InvertNode(); node.AddChild(0, child);
	ASSERT_EQ(node.Evaluate(parameters), 0.5);
}

/**
 * @brief Test that the code generation is working effectively
 */
TEST(InvertNode_Test, code_generation)
{
	auto child = new ConstantNode(200);
	auto node = InvertNode(); node.AddChild(0, child);
	ASSERT_EQ(node.GetCode(), "(1.0 / 2)");
}

/**
 * @brief Determine if the child count is correct
 */
TEST(InvertNode_Test, child_count)
{
	auto node = InvertNode();
	ASSERT_EQ(node.GetChildCount(), 1);
}