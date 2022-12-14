//--------------------------------------------------
// A base class of a grammar initializer
//
// @author: Wild Boar
//
// @date: 2022-12-15
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <NVLib/RandomUtils.h>

#include "InitializerBase.h"

namespace NVL_AI
{
	class DNAInitializer : public InitializerBase
	{
	private:
		vector<int> _source;
		int _position;
	public:
		DNAInitializer(const vector<int>& dna);

		virtual int GetNext(int minValue, int maxValue);
		void ResetPointer();

		inline int& GetPosition() { return _position; }
	};
}
