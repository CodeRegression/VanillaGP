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
SolutionBase * TreeFactory::Create(InitializerBase * initializer, int level)
{
	// Initialize working variables
	auto factory = NodeFactory(_properties->GetParamCount()); 
	auto root = _availableFunctions.size() > 0 ? GenerateNode(initializer, factory, _availableFunctions) : GenerateNode(initializer, factory, _availableTerminals);
	auto needChildren = vector<NodeBase *>(); if (root->GetChildCount() > 0) needChildren.push_back(root);

	// Perform construction root
	while( needChildren.size() > 0) 
	{
		auto nextChildren = vector<NodeBase *>();
		for (auto node : needChildren) 
		{
			for (auto i = 0; i < node->GetChildCount(); i++) 
			{
				auto& selectSet = level < _properties->GetDepthLimit() ? _properties->GetAvailableNodes() : _availableTerminals;
				auto child = GenerateNode(initializer, factory, selectSet);
				node->AddChild(i, child);
				if (child->GetChildCount() > 0) nextChildren.push_back(child); 
			}
			level++; needChildren.clear(); for(auto node : nextChildren) needChildren.push_back(node);
		}
	}

	// Return the result
	return new ExpressionTree(root);
}

//--------------------------------------------------
// Breed Functionality
//--------------------------------------------------

/**
 * @brief Breed two solutions to get a child
 * @param initializer The initializer that we will use to make the choices for the breeding
 * @param mother The `mother` of the child solution that we are creating
 * @param father The `father` of the child solution that we are creating
 * @return SolutionBase * Returns a SolutionBase
 */
SolutionBase * TreeFactory::Breed(InitializerBase * initializer, SolutionBase * mother, SolutionBase * father)
{
	throw runtime_error("Not implemented");
}

//--------------------------------------------------
// Mutate Functionality
//--------------------------------------------------

/**
 * @brief Mutate a solution
 * @param initializer The initailizer that we will use to make the choices for the mutation
 * @param probability The probability that a mutation occurs
 * @return SolutionBase * Returns a SolutionBase *
 */
SolutionBase * TreeFactory::Mutate(InitializerBase * initializer, double probability)
{
	throw runtime_error("Not implemented");
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
	auto index = initializer->GetNext(0, available.size() - 1);
	auto nodeIndex = available[index];
	return factory.CreateNode((NodeFactory::NodeType)nodeIndex, initializer);
}
