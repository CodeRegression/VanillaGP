//--------------------------------------------------
// Used to calculate the score of a given solution
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

#include "SolutionFactoryBase.h"

namespace NVL_AI
{
    class SolutionFactoryBase; // For circular reference

	class CalculatorBase
	{
    private:
        Mat _params;
    public:
		CalculatorBase(Mat& params) : _params(params) {}

		virtual Mat Eval(SolutionFactoryBase * factory, Solution * solution) = 0;
    protected:
        inline Mat& GetParams() { return _params; }
	};
}
