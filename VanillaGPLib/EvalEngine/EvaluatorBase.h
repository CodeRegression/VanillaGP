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

#include <NVLib/ARFF/ARFFHeader.h>
#include "../GrammarBase/Solution.h"
#include "../GrammarBase/CalculatorBase.h"

namespace NVL_AI
{
	class EvaluatorBase
	{
	private:
		CalculatorBase * _calculator;
		NVLib::ARFFHeader * _header;
		Mat _data;
	public:
		EvaluatorBase(NVLib::ARFFHeader * header, Mat& data) : _calculator(nullptr), _header(header), _data(data) {}
		~EvaluatorBase() { delete _calculator; }

		virtual double Eval(Solution * solution) = 0;
		virtual Mat GetParams() = 0;

		inline NVLib::ARFFHeader *& GetHeader() { return _header; }
		inline Mat& GetData() { return _data; }
		inline CalculatorBase * GetCalculator() { return _calculator; }
		inline void SetCalculator(CalculatorBase * calculator) { _calculator = calculator; }
	};
}
