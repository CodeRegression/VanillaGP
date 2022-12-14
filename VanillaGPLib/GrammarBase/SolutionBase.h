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
		vector<int> _dna;
	public:
		SolutionBase(InitializerBase * initializer) {}

		virtual string GetCode() = 0;
		virtual double Evaluate(const vector<double>& param) = 0;
		virtual void SetAvailableNodes(const vector<int>& available) = 0;
		virtual bool Validate(bool verbose) = 0;

		inline vector<int>& GetDNA() { return _dna; }
	};
}
