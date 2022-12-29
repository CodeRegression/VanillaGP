//--------------------------------------------------
// Implementation of class EuclidEvaluator
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#include "EuclidEvaluator.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param header The header that we are getting
 * @param data The data that we are evaluating against
 */
EuclidEvaluator::EuclidEvaluator(NVLib::ARFFHeader * header, Mat& data) : EvaluatorBase(header, data)
{
	if (!header->GetHasOutput()) throw runtime_error("This is a continuous evaluator - an output field is required!");
	BuildParameters(); BuildExpected();
}

//--------------------------------------------------
// Evaluation
//--------------------------------------------------

/**
 * @brief Evaluate the fitness of a given solution
 * @param solution The solution that we are evaluating
 * @return double Returns a double
 */
double EuclidEvaluator::Eval(Solution * solution)
{
	if (GetCalculator() == nullptr) throw runtime_error("Please set the calculator before evaluation");

	Mat actual = GetCalculator()->Eval(solution);
	auto input = (double *) actual.data; auto output = (double *) _expected.data;

	auto total = 0.0;
	for (auto row = 0; row < actual.rows; row++) 
	{
		auto difference = input[row] - output[row];
		auto sqrtDiff = sqrt(difference * difference);
		total += sqrtDiff;
	}
	
	auto average = total / actual.rows;
	solution->Score = average;

	return average;
}

//--------------------------------------------------
// Extract the params component of the data
//--------------------------------------------------

/**
 * @brief Retrieve the parameters from the data
 * @return Mat The parameter part of the data
 */
Mat EuclidEvaluator::GetParams() 
{
	return _params;
}

//--------------------------------------------------
// What is the optimal score?
//--------------------------------------------------

/**
 * @brief Retrieve the optimal score for this "phase"
 * @return double The optimal score that we are getting
 */
double EuclidEvaluator::GetOptimalScore() 
{
	return 0;
}

//--------------------------------------------------
// Helper Methods
//--------------------------------------------------

/**
 * @brief Build the actual values
 */
void EuclidEvaluator::BuildParameters() 
{
	_params = Mat_<double>(GetData().rows, GetHeader()->GetFields().size()); 
	auto input = (double *) GetData().data; auto output = (double *) _params.data;

	for (auto row = 0; row < _params.rows; row++) 
	{
		for (auto column = 0; column < _params.cols; column++) 
		{
			output[column + row * _params.cols] = input[column + row * GetData().cols];
		}
	}
}

/**
 * @brief Build expected values
 */
void EuclidEvaluator::BuildExpected() 
{
	_expected = Mat_<double>(GetData().rows, 1); 

	auto input = (double *) GetData().data; auto output = (double *) _expected.data;
	auto column = GetHeader()->GetFields().size();

	for (auto row = 0; row < _params.rows; row++) 
	{
		output[row] = input[column + row * GetData().cols];
	}
}
