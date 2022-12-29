//--------------------------------------------------
// Unit Tests for class Population
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/TreeFactory.h>
#include <VanillaGPLib/Population.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirms that the generation process worked as expected
 */
TEST(Population_Test, generation_check)
{
	// Setup: Create a tree factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);	

	// Setup: CodeDash
	auto dash = CodeDash("127.0.0.1", "/codedash/", "80");

	// Execute	
	auto population = Population(&factory, &dash, "Test_Problem", "EUCLID", 2, 10, 5, 0.5);

	// Confirm
	ASSERT_EQ(population.GetPopulation().size(), 2);
	ASSERT_EQ(population.GetPopulation()[0]->DNA.size(), 9);
	ASSERT_EQ(population.GetPopulation()[0]->DNA[0], 1);
	ASSERT_EQ(population.GetPopulation()[0]->DNA[6], 200);
	ASSERT_GT(population.GetPopulation()[1]->DNA.size(), 1);
}