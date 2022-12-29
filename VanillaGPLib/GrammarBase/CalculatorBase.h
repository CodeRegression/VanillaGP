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
        SolutionFactoryBase * _factory;
    public:
		CalculatorBase(SolutionFactoryBase* factory, Mat& params) : _params(params), _factory(factory) {}

		virtual Mat Eval(Solution * solution) = 0;
    protected:
        inline Mat& GetParams() { return _params; }
        inline SolutionFactoryBase * GetFactory() { return _factory; }
        inline int Rows() { return _params.rows; }
        inline int Cols() { return _params.cols; }
	};
}
