//--------------------------------------------------
// Add a solution renderer (for making a "sourcecode" version of the model)
//
// @author: Wild Boar
//
// @date: 2022-12-30
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

	class RendererBase
	{
    private:
        SolutionFactoryBase * _factory;
    public:
		RendererBase(SolutionFactoryBase* factory) : _factory(factory) {}

		virtual string Render(Solution * solution) = 0;

        virtual string GetDNAString(Solution * solution) 
        {
            auto result = stringstream();
            for (auto i = 0; i < solution->DNA.size(); i++) 
            {
                if (i != 0) result << ",";
                result << solution->DNA[i];
            }
            return result.str();
        }

    protected:
        inline SolutionFactoryBase * GetFactory() { return _factory; }
	};
}
