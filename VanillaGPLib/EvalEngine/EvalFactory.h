//--------------------------------------------------
// Defines a factory that produces evaluators
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/ARFF/ARFFHeader.h>

#include "EvaluatorBase.h"
#include "EuclidEvaluator.h"

namespace NVL_AI
{
	class EvalFactory
	{
	public:
		static EvaluatorBase * Get(const string& name, NVLib::ARFFHeader * header, const Mat& data) 
		{
			if (name == "EUCLID") return new EuclidEvaluator(header, data);
			else throw runtime_error("Unknown Evaluator: " + name);
		}
	};
}
