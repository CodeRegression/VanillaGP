//--------------------------------------------------
// Unit Tests for class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/NodeFactory.h>
#include <MathExpLib/TreeFactory.h>
#include <MathExpLib/ExpressionTree.h>
#include <VanillaGPLib/GrammarBase/RandomInitializer.h>
#include <VanillaGPLib/GrammarBase/DNAInitializer.h>
using namespace NVL_AI;

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------

int GetTreeDepth(ExpressionTree * tree);
void GetParameters(ExpressionTree * tree, vector<int>& parameters);
void GetNodeTypes(ExpressionTree * tree, vector<int>& nodeTypes);

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Test the generation of a tree
 */
TEST(TreeFactory_Test, tree_generation)
{
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = DNAInitializer(vector<int> { 1, 4, 5, 6, 0, 2, 200, 6, 1 });
	auto tree = (ExpressionTree *)factory.Create(&initializer);

	// Confirm the tree shape
	ASSERT_EQ(tree->GetRoot()->GetType(), "add_node");
	auto node_1 = tree->GetRoot()->GetChild(0);
	auto node_2 = tree->GetRoot()->GetChild(1);
	ASSERT_EQ(node_1->GetType(), "multiply_node");
	ASSERT_EQ(node_2->GetType(), "negate_node");
	auto node_3 = node_1->GetChild(0);
	auto node_4 = node_1->GetChild(1);
	auto node_5 = node_2->GetChild(0);
	ASSERT_EQ(node_3->GetType(), "parameter_node");
	ASSERT_EQ(((ParameterNode *)node_3)->GetParamIndex(), 0);
	ASSERT_EQ(node_4->GetType(), "constant_node");
	ASSERT_EQ(((ConstantNode *)node_4)->GetValue(), 2);
	ASSERT_EQ(node_5->GetType(), "parameter_node");
	ASSERT_EQ(((ParameterNode *)node_5)->GetParamIndex(), 1);

	// Free working memory
	delete tree;
}

/**
 * @brief Confirm the operation of the depth limiting functionality
 */
TEST(TreeFactory_Test, depth_limit)
{
	// Define variables
	auto DEPTH_LIMIT = 4;
	auto PARAM_COUNT = 3;

	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, DEPTH_LIMIT, PARAM_COUNT);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = RandomInitializer(1000);

	// Perform testing across 100 randomly generated expression trees
	for (auto i = 0; i < 100; i++) 
	{
		auto tree = (ExpressionTree *)factory.Create(&initializer);
		auto depth = GetTreeDepth(tree);
		ASSERT_LE(depth, DEPTH_LIMIT);
		delete tree;
	}
}

/**
 * @brief Confirm the parameter limitation functionality
 */
TEST(TreeFactory_Test, parameter_limit)
{
	// Define variables
	auto DEPTH_LIMIT = 4;
	auto PARAM_COUNT = 3;

	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, DEPTH_LIMIT, PARAM_COUNT);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = RandomInitializer(1000);

	// Perform testing across 100 randomly generated expression trees
	for (auto i = 0; i < 100; i++) 
	{
		auto tree = (ExpressionTree *)factory.Create(&initializer);
		auto parameters = vector<int>();
		auto depth = GetTreeDepth(tree);
		GetParameters(tree, parameters);

		for (auto parameter : parameters) ASSERT_TRUE(parameter >= 0 && parameter < PARAM_COUNT);

		ASSERT_LE(depth, DEPTH_LIMIT);
		delete tree;
	}
}

/**
 * @brief Confirm that we are able to restrict nodes in the generation
 */
TEST(TreeFactory_Test, node_limit_test) 
{
	// Define variables
	auto DEPTH_LIMIT = 4;
	auto PARAM_COUNT = 3;

	// Initialize the factory
	auto available = vector<int> {1, 6 };
	auto properties = new TreeProperties(available, DEPTH_LIMIT, PARAM_COUNT);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = RandomInitializer(1000);

	// Perform testing across 100 randomly generated expression trees
	for (auto i = 0; i < 100; i++) 
	{
		auto tree = (ExpressionTree *)factory.Create(&initializer);
		auto nodes = vector<int>();
		auto depth = GetTreeDepth(tree);
		GetNodeTypes(tree, nodes);

		for (auto node : nodes) ASSERT_TRUE(node == 1 || node == 6);

		ASSERT_LE(depth, DEPTH_LIMIT);
		delete tree;
	}
}

/**
 * @brief Confirm no mutation
 */
TEST(TreeFactory_Test, no_mutation)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Confirm that mutation happens as expected
 */
TEST(TreeFactory_Test, mutation)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Confirm controlled breeding
 */
TEST(TreeFactory_Test, controlled_breeding)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

/**
 * @brief Confirm the operation of breeding when new nodes need to be generated
 */
TEST(TreeFactory_Test, depth_difference_breeding)
{
	FAIL() << "Not implemented";

	// Setup

	// Execute

	// Confirm

	// Teardown
}

//--------------------------------------------------
// Helper Methods
//--------------------------------------------------

/**
 * @brief Attempts to determine the depth of the given tree
 * @param tree The tree that we are getting values for
 * @return int The depth that was calculated
 */
int GetTreeDepth(ExpressionTree * tree) 
{
	auto current = vector<NodeBase *>(); current.push_back(tree->GetRoot());
	auto level = 0;

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			for (auto i = 0; i < node->GetChildCount(); i++) next.push_back(node->GetChild(i));
		}

		current.clear(); for (auto node : next) current.push_back(node); level++;
	}

	return level - 1;
}

/**
 * @brief Retrieve the parameters that I am updating
 * @param tree The tree that we are extracting the parameters from
 * @param parameters The the parameters that we have extracted
 */
void GetParameters(ExpressionTree * tree, vector<int>& parameters) 
{
	parameters.clear();
	
	auto current = vector<NodeBase *>(); current.push_back(tree->GetRoot());

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			if (node->GetType() == "parameter_node") parameters.push_back(((ParameterNode *) node)->GetParamIndex());

			for (auto i = 0; i < node->GetChildCount(); i++) next.push_back(node->GetChild(i));
		}

		current.clear(); for (auto node : next) current.push_back(node); 
	}
}

/**
 * @brief Retrieve the types of node that make up the tree
 * @param tree The tree that we are testing
 * @param nodeTypes The list of node types that make up this tree
 */
void GetNodeTypes(ExpressionTree * tree, vector<int>& nodeTypes) 
{
	nodeTypes.clear();
	
	auto current = vector<NodeBase *>(); current.push_back(tree->GetRoot());

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			auto genes = vector<int>(); node->GetGenes(genes);
			nodeTypes.push_back(genes[0]);
			for (auto i = 0; i < node->GetChildCount(); i++) next.push_back(node->GetChild(i));
		}

		current.clear(); for (auto node : next) current.push_back(node); 
	}
}