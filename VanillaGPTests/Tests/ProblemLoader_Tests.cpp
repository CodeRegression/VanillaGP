//--------------------------------------------------
// Unit Tests for class ProblemLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include <gtest/gtest.h>

#include <VanillaGPLib/ProblemLoader.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Handles invalid problem loading
 */
TEST(ProblemLoader_Test, invalid_problem)
{
	// Setup
	auto expected = string("Unable to find problem code");

	// Execute
	try
	{
		auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
		auto filePath = "../VanillaGP/Input/2C2DFCBBB98241BD9177CB878B6EEA6.arff";
		auto problem = ProblemLoader("invalid_problem", filePath);
		problem.Load(&codeDash);
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
 * @brief Handles the problem that the data file is missing
 */
TEST(ProblemLoader_Test, missing_file)
{
	// Setup
	auto expected = string("Unable to find the provided data file");

	// Execute
	try
	{
		auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
		auto filePath = "test.txt";
		auto problem = ProblemLoader("Test_Problem", filePath);
		problem.Load(&codeDash);
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
 * @brief Handles the problem that the hashcode of the problem is missing
 */
TEST(ProblemLoader_Test, invalid_hash)
{
	// Setup
	auto expected = string("The data file does not appear to be valid - please download the proper one");

	// Execute
	try
	{
		auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
		auto filePath = "../VanillaGP/config.xml";
		auto problem = ProblemLoader("Test_Problem", filePath);
		problem.Load(&codeDash);
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
 * @brief Defines a normal loading of the functionality
 */
TEST(ProblemLoader_Test, valid_load)
{
	// Setup the load elements
	auto codeDash = CodeDash("127.0.0.1", "/codedash/", "80");
	auto filePath = "../VanillaGP/Input/2C2DFCBBB98241BD9177CB878B6EEA6.arff";
	
	// Load the given problem
	auto problem = ProblemLoader("Test_Problem", filePath);
	problem.Load(&codeDash);

	// Validate
	ASSERT_EQ(problem.GetId(), 3);
	ASSERT_EQ(problem.GetCode(), "Test_Problem"); 
    ASSERT_EQ(problem.GetName(), "Test Problem");
    ASSERT_EQ(problem.GetDescription(), "This is a problem for unit test purposes");
    ASSERT_EQ(problem.GetFile(), "../VanillaGP/Input/2C2DFCBBB98241BD9177CB878B6EEA6.arff");
    ASSERT_EQ(problem.GetFileHash(), "68068ad7a30abc9b11bbd2fcb49ea161");

	ASSERT_EQ(problem.GetFileHeader()->GetAuthor(), "WildBoar");
	ASSERT_EQ(problem.GetFileHeader()->GetDescription(), "Describes the equation p[0] + p[1] * p[2]");
	ASSERT_EQ(problem.GetFileHeader()->GetDataName(), "equation");
	ASSERT_EQ(problem.GetFileHeader()->GetFields()[0], "p0");
	ASSERT_EQ(problem.GetFileHeader()->GetFields()[1], "p1");
	ASSERT_EQ(problem.GetFileHeader()->GetFields()[2], "p2");
	ASSERT_TRUE(problem.GetFileHeader()->GetHasOutput());

	ASSERT_EQ(problem.GetData().rows, 500);
	ASSERT_EQ(problem.GetData().cols, 4);
	ASSERT_EQ(((double *) problem.GetData().data)[1999], -2259); 
}
