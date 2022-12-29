//--------------------------------------------------
// An evaluator that uses the Euclidean distance norm
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "EvaluatorBase.h"

namespace NVL_AI
{
	class EuclidEvaluator : public EvaluatorBase
	{
	private:
		Mat _params;
		Mat _expected;
	public:
		EuclidEvaluator(NVLib::ARFFHeader * header, Mat& data);
		
		virtual double Eval(Solution * solution) override;
		virtual Mat GetParams() override;
		virtual double GetOptimalScore() override; 
		
	private:
		void BuildParameters();
		void BuildExpected();
	};
}
