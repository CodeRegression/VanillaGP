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
using namespace NVL_AI;

//--------------------------------------------------
// Function Prototypes
//--------------------------------------------------

int GetTreeDepth(NodeBase * tree);
void GetTreeParameters(NodeBase * tree, vector<int>& parameters);
void GetNodeTypes(NodeBase * tree, vector<int>& nodeTypes);
void ShowSolution(Solution * solution);

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
	auto initializer = DNAInitializer(vector<int> { 1, 4, 5, 6, 0, 2, 100, 6, 1 });
	auto solution = factory.Generate(&initializer);
	auto tree = factory.Solution2Tree(solution);

	// Confirm the tree shape
	ASSERT_EQ(tree->GetType(), "add_node");
	auto node_1 = tree->GetChild(0);
	auto node_2 = tree->GetChild(1);
	ASSERT_EQ(node_1->GetType(), "multiply_node");
	ASSERT_EQ(node_2->GetType(), "negate_node");
	auto node_3 = node_1->GetChild(0);
	auto node_4 = node_1->GetChild(1);
	auto node_5 = node_2->GetChild(0);
	ASSERT_EQ(node_3->GetType(), "parameter_node");
	ASSERT_EQ(((ParameterNode *)node_3)->GetParamIndex(), 0);
	ASSERT_EQ(node_4->GetType(), "constant_node");
	ASSERT_EQ(((ConstantNode *)node_4)->GetValue(), 1);
	ASSERT_EQ(node_5->GetType(), "parameter_node");
	ASSERT_EQ(((ParameterNode *)node_5)->GetParamIndex(), 1);

	// Free working memory
	delete tree; delete solution;
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
		auto solution = factory.Generate(&initializer);
		auto tree = factory.Solution2Tree(solution); 
		auto depth = GetTreeDepth(tree);
		ASSERT_LE(depth, DEPTH_LIMIT);
		delete tree; delete solution;
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
		auto solution = factory.Generate(&initializer);
		auto tree = factory.Solution2Tree(solution);
		auto parameters = vector<int>();
		GetTreeParameters(tree, parameters);
		
		for (auto parameter : parameters) ASSERT_TRUE(parameter >= 0 && parameter < PARAM_COUNT);

		delete tree; delete solution;
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
		auto solution = factory.Generate(&initializer);
		auto tree = factory.Solution2Tree(solution);
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
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto expected_dna = vector<int> { 4, 7, 5, 6, 0, 2, 200, 6, 1 };
	auto initializer = DNAInitializer( expected_dna );
	auto solution = factory.Generate(&initializer);

	// Perform the mutation logic
	auto mute_initializer = DNAInitializer( vector<int> { 40, 2, 1, 6, 0, 6, 1 } );
	auto mute_solution = factory.Mutate(&mute_initializer, solution, 0.2);

	// Verify that the format is as expected
	for (auto i = 0; i < expected_dna.size(); i++) 
	{
		auto expected = expected_dna[i];
		auto actual = mute_solution->DNA[i];
		ASSERT_EQ(expected, actual);
	}

	// Free up some working variables
	delete solution; delete mute_solution;
}

/**
 * @brief Confirm that mutation happens as expected
 */
TEST(TreeFactory_Test, mutation)
{
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto original_dna = vector<int> { 4, 7, 5, 6, 0, 2, 200, 6, 1 };
	auto initializer = DNAInitializer( original_dna );
	auto solution = factory.Generate(&initializer);

	// Perform the mutation logic
	auto mute_initializer = DNAInitializer( vector<int> { 10, 2, 1, 6, 0, 6, 1} );
	auto mute_solution = factory.Mutate(&mute_initializer, solution, 0.5);
	auto expected_dna = vector<int> { 4, 7, 1, 6, 0, 2, 200, 6, 0, 6, 1 };

	// Verify that the format is as expected
	for (auto i = 0; i < original_dna.size(); i++) 
	{
		auto expected = expected_dna[i];
		auto actual = mute_solution->DNA[i];
		ASSERT_EQ(expected, actual);
	}

	// Free up some working variables
	delete solution; delete mute_solution;
}

/**
 * @brief Confirm that the depth limit is respected for mutation
 */
TEST(TreeFactory_Test, mutation_depth) 
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
		auto solution = factory.Generate(&initializer);
		auto mute_solution = factory.Mutate(&initializer, solution, 1.0);
		ShowSolution(solution);
		ShowSolution(mute_solution);
		auto tree = factory.Solution2Tree(mute_solution); 
		auto depth = GetTreeDepth(tree);
		ASSERT_LE(depth, DEPTH_LIMIT);
		delete tree; delete solution; delete mute_solution;
	}
}

/**
 * @brief Confirm controlled breeding
 */
TEST(TreeFactory_Test, controlled_breeding)
{
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Create parents
	auto mother = Solution(vector<int> { 1, 4, 6, 0, 6, 1, 2, -200 } );
	auto father = Solution(vector<int> { 7, 1, 5, 6, 0, 6, 1, 6, 2} );

	// Perform the breeding
	auto breedCode = DNAInitializer( vector<int> { 0, 1, 1, 0, 0 } );
	auto child = factory.Breed( &breedCode, &mother, &father);

	// Verify
	auto expected = vector<int> { 1, 1, 5, 6, 1, 2, -200, 6, 2};
	ASSERT_EQ(child->DNA.size(), expected.size());
	for (auto i = 0; i < expected.size(); i++) ASSERT_EQ(expected[i], child->DNA[i]);

	// Clean up
	delete child;
}

/**
 * @brief Confirm the operation of breeding when new nodes need to be generated
 */
TEST(TreeFactory_Test, depth_difference_breeding)
{
	// Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 6, 4);
	auto factory = TreeFactory(properties);

	// Create parents
	auto mother = Solution(vector<int> { 1, 4, 3, 6, 0, 6, 1, 6, 2 } );
	auto father = Solution(vector<int> { 5, 3, 1, 6, 0, 7, 6, 2, 6, 3 } );

	// Perform the breeding
	auto breedCode = DNAInitializer( vector<int> { 0, 0, 1, 1, 1, 1, 6, 0, 6, 1 } );
	auto child = factory.Breed( &breedCode, &mother, &father);

	// Verify
	auto expected = vector<int> { 1, 4, 1, 6, 0, 7, 6, 2, 6, 3, 6, 0, 6, 1 };
	ASSERT_EQ(child->DNA.size(), expected.size());
	for (auto i = 0; i < expected.size(); i++) ASSERT_EQ(expected[i], child->DNA[i]);

	// Clean up
	delete child;
}

/**
 * @brief Confirm that depth values are consistency the values that they should be
 */
TEST(TreeFactory_Test, depth_consistency_testing) 
{
		// Define variables
	auto DEPTH_LIMIT = 5;
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
		auto mother = factory.Generate(&initializer);
		auto father = factory.Generate(&initializer);
		auto child = factory.Breed(&initializer, mother, father);

		auto tree = factory.Solution2Tree(child); 
		auto depth = GetTreeDepth(tree);
		ASSERT_LE(depth, DEPTH_LIMIT);

		delete tree; delete mother; delete father; delete child;
	}
}

//--------------------------------------------------
// Helper Methods
//--------------------------------------------------

/**
 * @brief Attempts to determine the depth of the given tree
 * @param tree The tree that we are getting values for
 * @return int The depth that was calculated
 */
int GetTreeDepth(NodeBase * tree) 
{
	auto current = vector<NodeBase *>(); current.push_back(tree);
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
void GetTreeParameters(NodeBase * tree, vector<int>& parameters) 
{
	parameters.clear();
	
	auto current = vector<NodeBase *>(); current.push_back(tree);

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
void GetNodeTypes(NodeBase * tree, vector<int>& nodeTypes) 
{
	nodeTypes.clear();
	
	auto current = vector<NodeBase *>(); current.push_back(tree);

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

/**
 * @brief Show the solution on the screen
 * @param solution The solution that we are showing
 */
void ShowSolution(Solution * solution) 
{
	for (auto i = 0; i < solution->DNA.size(); i++) 
	{
		cout << solution->DNA[i] << " ";
	}
	cout << endl;
}