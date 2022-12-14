//--------------------------------------------------
// A base class of a grammar initializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include <iostream>
using namespace std;

namespace NVL_App
{
	class InitializerBase
	{
	private:
		vector<int> _dna;
	public:
		InitializerBase() {}

		virtual int GetNext(int minValue, int maxValue) = 0;
		inline void ResetDNA() { _dna.clear(); }

		inline vector<int>& GetDna() { return _dna; }
	};
}
