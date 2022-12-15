//--------------------------------------------------
// Unit Tests for class NodeFactory
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/GrammarBase/DNAInitializer.h>

#include <MathExpLib/NodeFactory.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Create a parameter attribute
 */
TEST(NodeFactory_Test, create_parameter)
{
	auto initializer = DNAInitializer(vector<int> {2});
	auto factory = NodeFactory(5);
	auto node = factory.CreateNode(NodeFactory::NodeType::PARAMETER_NODE, &initializer);

	ASSERT_EQ(node->GetType(), "parameter_node");
	ASSERT_EQ(((ParameterNode *)node)->GetParamIndex(), 2);

	delete node;
}

/**
 * @brief Create an attribute
 */
TEST(NodeFactory_Test, create_add)
{
	auto initializer = DNAInitializer(vector<int> {2});
	auto factory = NodeFactory(5);
	auto node = factory.CreateNode(NodeFactory::NodeType::ADD_NODE, &initializer);

	ASSERT_EQ(node->GetType(), "add_node");

	delete node;
}