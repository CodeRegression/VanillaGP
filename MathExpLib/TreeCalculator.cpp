//--------------------------------------------------
// Implementation of the tree calculator
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include "TreeCalculator.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Main Constructor
 * @param factory The factory that we are using
 * @param params Input parameters
 */
TreeCalculator::TreeCalculator(SolutionFactoryBase * factory, Mat& params) : CalculatorBase(factory, params)
{
    // Extra implementation can go here
}

//--------------------------------------------------
// Evaluation
//--------------------------------------------------

/**
 * @brief Evaluation function for a solution goes here
 * @param solution The solution that we are evaluating
 * @return Mat The resultant solution
 */
Mat TreeCalculator::Eval(Solution * solution) 
{
    auto treeFactory = (TreeFactory *) GetFactory();
    auto tree = treeFactory->Solution2Tree(solution);
    auto input = (double *) GetParams().data;

    Mat result = Mat_<double>(GetParams().rows, 1);
    auto output = (double *) result.data;

    for (auto row = 0; row < GetParams().rows; row++) 
    {
        auto params = vector<double>();
        for (auto column = 0; column < GetParams().cols; column++) 
        {
            auto index = column + row * GetParams().cols;
            params.push_back(input[index]);
        }

        auto value = tree->Evaluate(params);
        output[row] = value;
    }

    return result;
}