//--------------------------------------------------
// Unit Tests for class TreeCalculator
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include <gtest/gtest.h>

#include <MathExpLib/TreeFactory.h>
#include <MathExpLib/TreeCalculator.h>
using namespace NVL_AI;

//--------------------------------------------------
// Test Methods
//--------------------------------------------------

/**
 * @brief Confirm the carrying out of basic calculations
 */
TEST(TreeCalculator_Test, basic_calculation)
{
    // Initialize the factory
	auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	auto properties = new TreeProperties(available, 4, 3);
	auto factory = TreeFactory(properties);

	// Generate a solution tree
	auto initializer = DNAInitializer(vector<int> { 1, 4, 5, 6, 0, 2, 200, 6, 1 });
	auto solution = factory.Generate(&initializer);

    // Initialize parameters
    Mat params = (Mat_<double>(3,2) << 1, 1, 2, 3, 4, 5);

    // Fire off the calculator and get the result
    auto calculator = factory.GetCalculator(params);
    Mat result = calculator->Eval(&factory, solution);
    auto output = (double *) result.data;

    // Confirm the result
    ASSERT_EQ(result.rows, 3);
    ASSERT_EQ(result.cols, 1);
    ASSERT_EQ(output[0], 1);
    ASSERT_EQ(output[1], 1);
    ASSERT_EQ(output[2], 3);

    // Free working memory
	delete solution; delete calculator;
}