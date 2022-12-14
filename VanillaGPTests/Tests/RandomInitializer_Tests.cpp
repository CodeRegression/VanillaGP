//--------------------------------------------------
// Unit Tests for class RandomInitializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/GrammarBase/RandomInitializer.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that DNA retrieval + reset is working correctly
 */
TEST(RandomInitializer_Test, test_dna_retrieval)
{
	// Setup
	auto initializer = new RandomInitializer(1000);

	// Execute: Set_1
	auto set_1 = vector<int>();
	for (auto i = 0; i < 4; i++) 
	{
		auto value = initializer->GetNext(i+1, i+5);
		set_1.push_back(value);
	}
	auto dna_1 = vector<int>(initializer->GetDna());

	// Execute: Reset the DNA stuff
	initializer->ResetDNA();

	// Execute: Set_1
	auto set_2 = vector<int>();
	for (auto i = 0; i < 4; i++) 
	{
		auto value = initializer->GetNext(i+1, i+5);
		set_2.push_back(value);
	}
	auto dna_2 = vector<int>(initializer->GetDna());

	// Confirm: Set_1
	ASSERT_EQ(set_1.size(), dna_1.size());
	for (auto i = 0; i < set_1.size(); i++) 
	{
		ASSERT_EQ(set_1[i], dna_1[i]);
		ASSERT_GE(set_1[i], i+1);
		ASSERT_LE(set_1[i], i+5);
	}

	// Confirm: Set_2
	ASSERT_EQ(set_2.size(), dna_2.size());
	for (auto i = 0; i < set_2.size(); i++) 
	{
		ASSERT_EQ(set_2[i], dna_2[i]);
		ASSERT_GE(set_2[i], i+1);
		ASSERT_LE(set_2[i], i+5);
	}

	// Teardown
	delete initializer;
}