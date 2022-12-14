//--------------------------------------------------
// Unit Tests for class DNAInitializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/GrammarBase/DNAInitializer.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that DNA retrieval + reset is working correctly
 */
TEST(DNAInitializer_Test, test_dna_retrieval)
{
	// Setup
	auto initializer = new DNAInitializer(vector<int> {1, 2, 3, 4, 5, 6});

	// Execute
	ASSERT_EQ(initializer->GetNext(0,10), 1);
	ASSERT_EQ(initializer->GetNext(0,10), 2);
	ASSERT_EQ(initializer->GetNext(0,10), 3);

	auto dna_1 = vector<int>(initializer->GetDNA());
	initializer->ResetDNA();

	ASSERT_EQ(initializer->GetNext(0,10), 4);
	auto dna_2 = vector<int>(initializer->GetDNA());

	// Confirm
	ASSERT_EQ(dna_1.size(), 3);
	ASSERT_EQ(dna_1[0], 1);
	ASSERT_EQ(dna_1[1], 2);
	ASSERT_EQ(dna_1[2], 3);

	ASSERT_EQ(dna_2.size(), 1);
	ASSERT_EQ(dna_2[0],4);

	// Teardown
	delete initializer;
}

/**
 * @brief Confirm that the pointer wrap is working correctly
 */
TEST(DNAInitializer_Test, test_dna_pointer_wrap)
{
	// Setup
	auto initializer = new DNAInitializer(vector<int> {1, 2, 3});

	// Execute
	ASSERT_EQ(initializer->GetNext(0,10), 1);
	initializer->ResetPointer();

	ASSERT_EQ(initializer->GetNext(0,10), 1);
	ASSERT_EQ(initializer->GetNext(0,10), 2);
	ASSERT_EQ(initializer->GetNext(0,10), 3);
	ASSERT_EQ(initializer->GetNext(0,10), 1);

	auto dna = vector<int>(initializer->GetDNA());

	// Confirm
	ASSERT_EQ(dna.size(), 5);
	ASSERT_EQ(dna[0], 1);
	ASSERT_EQ(dna[1], 1);
	ASSERT_EQ(dna[2], 2);
	ASSERT_EQ(dna[3], 3);
	ASSERT_EQ(dna[4], 1);

	// Teardown
	delete initializer;
}

/**
 * @brief Confirm that the range exception functionality is working correctly
 */
TEST(DNAInitializer_Test, test_range_exception)
{
	// Setup
	auto initializer = new DNAInitializer(vector<int> {1, 2, 3});

	// Execute
	try 
	{
		auto value = initializer->GetNext(5, 10);
		FAIL() << "Expected an exception to be thrown, and it was not";
	}
	catch(runtime_error exception) 
	{
		ASSERT_EQ(exception.what(), string("Predefined DNA failed range test"));
	}
	catch(...) 
	{
		FAIL() << "Expected runtime_error exception, but another exception was raised";
	}

	// Teardown
	delete initializer;
}
