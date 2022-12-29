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

#include <NVLib/ARFF/ARFFReader.h>

#include "EvaluatorBase.h"
#include "EuclidEvaluator.h"

namespace NVL_AI
{
	class EvalFactory
	{
	public:
		static EvaluatorBase * Get(const string& name, NVLib::ARFFReader * reader) 
		{
			Mat data = reader->ReadAll();
			if (name == "EUCLID") return new EuclidEvaluator(reader->GetHeader(), data);
			else throw runtime_error("Unknown Evaluator: " + name);
		}
	};
}
