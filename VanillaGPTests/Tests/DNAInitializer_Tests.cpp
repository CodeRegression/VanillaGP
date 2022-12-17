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
