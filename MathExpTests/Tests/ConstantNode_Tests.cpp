//--------------------------------------------------
// Unit Tests for class ConstantNode
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/ConstantNode.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * Confirm that the DNA that we are using correct
 */
TEST(ConstantNode_Test, node_dna) 
{
	auto node = ConstantNode(3);
	auto gene = vector<int>(); node.GetGenes(gene);
	ASSERT_EQ(gene.size(), 2);
	ASSERT_EQ(gene[0], 2);
	ASSERT_EQ(gene[1], 3);
}

/**
 * @brief Test retrieval of the node type
 */
TEST(ConstantNode_Test, node_type)
{
	auto node = ConstantNode(1);
	ASSERT_EQ(node.GetType(), "constant_node");
}

/**
 * @brief Confirm the evaluation functionality
 */
TEST(ConstantNode_Test, evaluate)
{
	auto parameters = vector<double> {1, 2, 3};
	auto node = ConstantNode(1);
	ASSERT_EQ(node.Evaluate(parameters), 1e-2);
}

/**
 * @brief Test 
 */
TEST(ConstantNode_Test, code_generation)
{
	auto node = ConstantNode(1);
	ASSERT_EQ(node.GetCode(), "0.01");
}