//--------------------------------------------------
// Defines a function for getting the factory for the given grammar
//
// @author: Wild Boar
//
// @date: 2022-12-30
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/ARFF/ARFFHeader.h>

#include <MathExpLib/TreeFactory.h>

namespace NVL_AI
{
	class GrammarFinder
	{
	public:

		static SolutionFactoryBase * Get(const string& grammarName, NVLib::ARFFHeader * header, int depthLimit) 
		{
			if (grammarName == "ETREE") 
            {
                auto available = vector<int>(); NodeFactory::GetAllNodeTypes(available);
	            auto properties = new TreeProperties(available, depthLimit, header->GetFields().size());
	            return new TreeFactory(properties);
            }
			else throw runtime_error("Unknown Grammar: " + grammarName);
		}
	};
}
