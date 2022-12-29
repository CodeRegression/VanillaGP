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

namespace NVL_AI
{
	struct Solution
	{
	public:
		double Score;
		vector<int> DNA;
		Solution(const vector<int>& dna) : DNA(dna), Score(-1) {}
	};
}
