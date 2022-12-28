//--------------------------------------------------
// A base class for a solution evaluator
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include <NVLib/ARFFHeader.h>
#include "../GrammarBase/Solution.h"

namespace NVL_AI
{
	class EvaluatorBase
	{
	private:
		ARFFHeader * _header;
		Mat _data;
	public:
		EvaluatorBase(ARFFHeader * header, Mat data) : _header(header), _data(data) {}

		virtual double Eval(Solution * solution) = 0;

		inline ARFFHeader *& GetHeader() { return _header; }
		inline Mat& GetData() { return _data; }
	};
}
