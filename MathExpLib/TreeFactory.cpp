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
 * @return SolutionBase * Returns a SolutionBase 
 */
SolutionBase * TreeFactory::Create(InitializerBase * initializer)
{
	throw runtime_error("Not implemented");
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
 * @param available The available list of nodes
 * @return NodeBase* The node that was returned
 */
NodeBase * TreeFactory::GenerateNode(InitializerBase * initializer, const vector<int>& available) 
{
	throw runtime_error("Not Implemented");
}
