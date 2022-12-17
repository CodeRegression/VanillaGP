//--------------------------------------------------
// A base solution for the given project
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include "InitializerBase.h"

namespace NVL_AI
{
	class SolutionBase
	{
	private:
		double _score;
	public:
		SolutionBase() : _score(-1) {}

		virtual string GetCode() = 0;
		virtual double Evaluate(const vector<double>& param) = 0;

		inline double GetScore() { return _score; }
		inline void SetScore(double value) { _score = value; }
	};
}
