//--------------------------------------------------
// Unit Tests for class CodeDash
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include <gtest/gtest.h>

#include <NVLib/StringUtils.h>

#include <VanillaGPLib/CodeDash.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm that we can retrieve a given problem
 */
TEST(CodeDash_Test, problem_retrieval)
{
    // Retrieve CodeDash
    auto dash = CodeDash("127.0.0.1", "/codedash/", "80");

    // Retrieve the problem Details
    auto details = dash.GetProblemDetails("Test_Problem");

    // Break the problem into parts
    auto parts = vector<string>(); NVLib::StringUtils::Split(details, ',', parts);

    // Validation
    ASSERT_EQ(parts.size(), 5);
    ASSERT_GT(NVLib::StringUtils::String2Int(parts[0]), 0); // Make sure that the ID is great than 0
    ASSERT_EQ(parts[1], "Test Problem");
    ASSERT_EQ(parts[2], "This is a problem for unit test purposes");
    ASSERT_EQ(parts[3], "../uploads/28BF210293042CBA864D4C6380877A.arff");
    ASSERT_EQ(parts[4], "68068ad7a30abc9b11bbd2fcb49ea161");
}

/**
 * @brief Confirm that an invalid problem is retrieved in the correct way
 */
TEST(CodeDash_Test, invalid_problem_retrieval) 
{
    auto message = "Unable to find problem code";

    try 
    {
        auto dash = CodeDash("127.0.0.1", "/codedash/", "80");
        auto details = dash.GetProblemDetails("invalid_problem");
        FAIL() << "Expected Exception: " << message;
    }
    catch(runtime_error exception) 
    {
        ASSERT_EQ(string(exception.what()), message);
    }
    catch(...) 
    {
        FAIL() << "Expected Exception: " << message;
    }
}