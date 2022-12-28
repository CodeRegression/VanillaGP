//--------------------------------------------------
// Unit Tests for class AlgorithmLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/AlgorithmLoader.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Handles the case that an invalid algorithm code was used
 */
TEST(AlgorithmLoader_Test, invalid_code)
{
	// Setup
	auto expected = string("Invalid algorithm code");

	// Execute
	try
	{
		auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
		auto algorithm = AlgorithmLoader("Invalid Algorithm");
		algorithm.Load(&codeDash);
		FAIL() << "Expected exception: " << expected;
	}
	catch(runtime_error exception)
	{
		ASSERT_EQ(exception.what(), expected);
	}
	catch(...)
	{
		FAIL() << "Expected exception: " << expected;
	}
}

/**
 * @brief Confirm the case of a valid application load
 */
TEST(AlgorithmLoader_Test, valid_load)
{
	// Setup
	auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto algorithm = AlgorithmLoader("ETREE_C");
	algorithm.Load(&codeDash);

	// Confirm
	ASSERT_EQ(algorithm.GetId(), 1);
	ASSERT_EQ(algorithm.GetCode(), "ETREE_C");
	ASSERT_EQ(algorithm.GetName(), "Basic Continuous Tree");
	ASSERT_EQ(algorithm.GetDetails(), "Basic Syntax Expression Tree with Continuous Evaluation");
	ASSERT_EQ(algorithm.GetProgram(), "VanillaGP");
	ASSERT_EQ(algorithm.GetEvaluation(), "EUCLID");
	ASSERT_EQ(algorithm.GetGrammar(), "ETREE");
	ASSERT_EQ(algorithm.GetVersion(), "1.00");
}