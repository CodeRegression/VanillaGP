//--------------------------------------------------
// Implementation of class TreeFactory
//
// @author: Wild Boar
//
// @date: 2022-12-16
//--------------------------------------------------

#include "TreeFactory.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Initializer Constructor
 * @param properties Initialize variable <properties>
 */
TreeFactory::TreeFactory(TreeProperties * properties)
{
	_properties = properties; InitializeNodeCollections(_properties->GetAvailableNodes());
	if (_availableTerminals.size() == 0) throw runtime_error("The collection needs to include at least one terminal node");
}

/**
 * @brief Main Terminator
 */
TreeFactory::~TreeFactory()
{
	delete _properties;
}

//--------------------------------------------------
// Create Functionality
//--------------------------------------------------

/**
 * @brief Create a solution
 * @param initializer The initializer that we are going to use
 * @param level The level that we are starting from
 * @return SolutionBase * Returns a SolutionBase 
 */
Solution * TreeFactory::Generate(InitializerBase * initializer, int level)
{
	// Build the tree
	auto tree = BuildTree(initializer, level);

	// Extract solution and return
	auto solution = Tree2Solution(tree);

	// Free the memory
	delete tree;

	// Return the solution
	return solution;
}

//--------------------------------------------------
// Breed Functionality
//--------------------------------------------------

/**
 * @brief Breed two solutions to get a child
 * @param initializer The initializer that we will use to make the choices for the breeding
 * @param mother The `mother` of the child solution that we are creating
 * @param father The `father` of the child solution that we are creating
 * @return Solution * Returns a Solution
 */
Solution * TreeFactory::Breed(InitializerBase * initializer, Solution * mother, Solution * father)
{
	// Setup a factory (in case we need it)
	auto factory = NodeFactory(_properties->GetParamCount()); 

	// Get the mother and father trees
	auto motherTree = Solution2Tree(mother);
	auto fatherTree = Solution2Tree(father);

	// Get the mother and father node lists
	auto motherNodes = vector<NodeBase *>(); auto motherLevels = vector<int>(); ExtractNodes(motherTree, motherNodes, motherLevels);
	auto fatherNodes = vector<NodeBase *>(); auto fatherLevels = vector<int>(); ExtractNodes(fatherTree, fatherNodes, fatherLevels);
	if (motherNodes.size() == 0 || fatherNodes.size() == 0) throw runtime_error("Empty tree passed to the breed function");

	// Pick the root node
	auto nodeIndex = 0;
	auto rootChoice = initializer->GetNext(0, 2); if (rootChoice == 2) throw runtime_error("Invalid root choice");
	auto root = rootChoice == 0 ? motherNodes[nodeIndex]->Clone() : fatherNodes[nodeIndex]->Clone(); nodeIndex++;
	auto needChildren = vector<NodeBase *>(); if (root->GetChildCount() > 0) needChildren.push_back(root);

	// Setup the level
	auto level = 0;

	// Perform construction root
	while( needChildren.size() > 0) 
	{
		auto nextChildren = vector<NodeBase *>();
		
		for (auto node : needChildren) 
		{
			for (auto i = 0; i < node->GetChildCount(); i++) 
			{
				auto child = ChooseNode(initializer, nodeIndex, factory, motherNodes, fatherNodes);

				if (level >= _properties->GetDepthLimit() - 1 && node->GetChildCount() != 0) 
				{
					delete child; child = GenerateNode(initializer, factory, _availableTerminals);
				}

				//cout << "Selected Node: " << node->GetType() << endl;
				//cout << "Selected Child: " << child->GetType() << " at index " << i << endl;

				node->AddChild(i, child);
				if (child->GetChildCount() > 0) nextChildren.push_back(child); 
			}
		}

		level++; needChildren.clear(); for(auto node : nextChildren) needChildren.push_back(node); nextChildren.clear();
	}

	// Free Memory
	delete motherTree; delete fatherTree;

	// return the result
	auto solution = Tree2Solution(root); delete root;
	return solution;
}

/**
 * @brief Add the functionality to choose a new node from the system
 * @param initializer The initializer The generator of random numbers for the system
 * @param factory The factory for generating new nodes for the system
 * @param motherNodes The mother nodes 
 * @param fatherNodes The father nodes
 * @return NodeBase* The selected node
 */
NodeBase * TreeFactory::ChooseNode(InitializerBase * initializer, int& nodeIndex, NodeFactory& factory, const vector<NodeBase *>& motherNodes, const vector<NodeBase *>& fatherNodes) 
{
	if (nodeIndex < motherNodes.size() && nodeIndex < fatherNodes.size()) 
	{
		auto choose = initializer->GetNext(0, 2); if (choose == 2) throw runtime_error("Invalid Choice!");
		auto& result = choose == 0 ? motherNodes[nodeIndex] : fatherNodes[nodeIndex]; nodeIndex++;
		return result->Clone();
	}
	else if (nodeIndex >= motherNodes.size() && nodeIndex < fatherNodes.size()) 
	{
		auto result = fatherNodes[nodeIndex]; nodeIndex++;
		return result->Clone();
	}
	else if (nodeIndex < motherNodes.size() && nodeIndex >= fatherNodes.size()) 
	{
		auto result = motherNodes[nodeIndex]; nodeIndex++;
		return result->Clone();
	}
	else 
	{
		return GenerateNode(initializer, factory, _properties->GetAvailableNodes());
	}
}

//--------------------------------------------------
// Mutate Functionality
//--------------------------------------------------

/**
 * @brief Mutate a solution
 * @param initializer The initailizer that we will use to make the choices for the mutation
 * @param solution The solution that we are working with
 * @param probability The probability that a mutation occurs
 * @return SolutionBase * Returns a SolutionBase *
 */
Solution * TreeFactory::Mutate(InitializerBase * initializer, Solution * solution, double probability)
{
	// Check to see if we should do anything
	auto spin = initializer->GetNext(0, 100); auto spinProb = spin / 100.0;
	if (spinProb > probability) return new Solution(solution->DNA);
	
	// Extract a tree
	auto tree = Solution2Tree(solution);

	// Get the nodes
	auto nodes = vector<NodeBase *>(); auto levels = vector<int>(); ExtractNodes(tree, nodes, levels);

	// Select the node that we want to replace
	auto nodeIndex = initializer->GetNext(0, nodes.size());
	
	// Get the node and the parent
	auto node = nodes[nodeIndex]; auto parent = node->GetParent(); auto childIndex = node->GetChildIndex();
	if (parent == nullptr) return new Solution(solution->DNA);

	// Generate a new subtree
	auto newNode = BuildTree(initializer, levels[nodeIndex]);
	parent->AddChild(childIndex, newNode);
	
	// Extract the solution and return
	auto result = Tree2Solution(tree); delete tree;
	return result;
}

/**
 * @brief Add the functionality to extract nodes
 * @param tree The tree that we are getting the nodes for
 * @param nodes The nodes that we have extracted
 * @param levels The levels associated with each node
 */
void TreeFactory::ExtractNodes(NodeBase* tree, vector<NodeBase *>& nodes, vector<int>& levels) 
{
	auto current = vector<NodeBase *>(); current.push_back(tree); auto level = 0; nodes.clear();

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			//cout << node->GetType() << endl;
			nodes.push_back(node); levels.push_back(level);
			for (auto i = 0; i < node->GetChildCount(); i++) 
			{
				auto child = node->GetChild(i);
				if (child == nullptr) throw runtime_error("Child is not initialized!");
				next.push_back(child);
			}
		}

		current.clear(); for (auto node : next) current.push_back(node); level++;
	}
}

//--------------------------------------------------
// Generate a calculator for the system
//--------------------------------------------------

/**
 * @brief Generate a calculator for the system
 * @param params The parameters that we are calculating against
 * @return CalculatorBase The generated calculator
 */
CalculatorBase * TreeFactory::GetCalculator(Mat& params) 
{
	return new TreeCalculator(this, params);
}

//--------------------------------------------------
// Generate a renderer for the system
//--------------------------------------------------

/**
 * @brief Defines a renderer for the system
 * @return RendererBase* The renderer that we are returning
 */
RendererBase * TreeFactory::GetRenderer() 
{
	return new TreeRenderer(this);
}

//--------------------------------------------------
// Conversion functionality
//--------------------------------------------------

/**
 * @brief Convert a Tree into a solution
 * @param root The root node that we are converting
 * @return The solution that we are returning
 */
Solution * TreeFactory::Tree2Solution(NodeBase * root) 
{
	auto dna = vector<int>();

	auto current = vector<NodeBase *>(); current.push_back(root);

	while (current.size() > 0) 
	{
		auto next = vector<NodeBase *>();

		for (auto node : current) 
		{
			node->GetGenes(dna);
			for (auto i = 0; i < node->GetChildCount(); i++) next.push_back(node->GetChild(i));
		}

		current.clear(); for (auto node : next) current.push_back(node); 
	}

	return new Solution(dna);
}

/**
 * @brief Functionality to convert a solution into a tree
 * @param solution The solution that we are converting
 * @return NodeBase* The root node of the tree that we have extracted
 */
NodeBase * TreeFactory::Solution2Tree(Solution * solution) 
{
	auto initializer = DNAInitializer(solution->DNA);
	return BuildTree(&initializer, 0);
}

/**
 * @brief Add the functionality to construct a tree from the given initializer
 * @param initializer The initializer that we have been given
 * @param level The level at which to construct the tree
 * @return NodeBase* The resultant root node
 */
NodeBase * TreeFactory::BuildTree(InitializerBase * initializer, int level) 
{
	// Initialize working variables
	auto factory = NodeFactory(_properties->GetParamCount()); 
	auto &initialSet = (_availableFunctions.size() == 0 || level >= _properties->GetDepthLimit()) ? _availableTerminals : _availableFunctions;
	auto root = GenerateNode(initializer, factory, initialSet);
	auto needChildren = vector<NodeBase *>(); if (root->GetChildCount() > 0) needChildren.push_back(root);

	// Perform construction root
	while( needChildren.size() > 0) 
	{
		auto nextChildren = vector<NodeBase *>();
		
		for (auto node : needChildren) 
		{
			for (auto i = 0; i < node->GetChildCount(); i++) 
			{
				auto& selectSet = level < _properties->GetDepthLimit() - 1 ? _properties->GetAvailableNodes() : _availableTerminals;
				auto child = GenerateNode(initializer, factory, selectSet);
				node->AddChild(i, child);
				if (child->GetChildCount() > 0) nextChildren.push_back(child); 
			}
		}

		level++; needChildren.clear(); for(auto node : nextChildren) needChildren.push_back(node); nextChildren.clear();
	}

	// return the result
	return root;
}

//--------------------------------------------------
// Initialize Node Collections
//--------------------------------------------------

/**
 * @brief Add the logic to initialize given node collections
 * @param available The list of available nodes
 */
void TreeFactory::InitializeNodeCollections(vector<int>& available) 
{
	auto factory = NodeFactory(_properties->GetParamCount());
	auto initializer = RandomInitializer(0);

	for (auto nodeIndex : available) 
	{
		auto node = factory.CreateNode((NodeFactory::NodeType)nodeIndex, &initializer);
		auto childCount = node->GetChildCount();
		if (childCount > 0) _availableFunctions.push_back(nodeIndex);
		else _availableTerminals.push_back(nodeIndex); 
	}
}

//--------------------------------------------------
// Generate Node Helper
//--------------------------------------------------

/**
 * @brief Generate a node from the given available list 
 * @param initializer The initializer that we are using
 * @param factory The node factory that we are dealing with
 * @param available The available list of nodes
 * @return NodeBase* The node that was returned
 */
NodeBase * TreeFactory::GenerateNode(InitializerBase * initializer, NodeFactory & factory, const vector<int>& available) 
{
	auto nodeIndex = initializer->GetNext(available);
	return factory.CreateNode((NodeFactory::NodeType)nodeIndex, initializer);
}
