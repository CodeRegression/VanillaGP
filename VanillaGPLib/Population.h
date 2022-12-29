//--------------------------------------------------
// Handler for a population of solutions
//
// @author: Wild Boar
//
// @date: 2022-12-29
//--------------------------------------------------

#pragma once

#include <vector>
#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

#include "CodeDash.h"
#include "EvalEngine/EvaluatorBase.h"
#include "GrammarBase/SolutionFactoryBase.h"

namespace NVL_AI
{
	class Population
	{
	private:
		SolutionFactoryBase * _factory;
		CodeDash * _codeDash;
		vector<Solution *> _population;
		vector<Solution *> _bestSolutions;
		int _generation;
		int _sameScore;
		int _generationLimit;
		int _sameScoreLimit;
		bool _solutionFound;

	public:
		Population(SolutionFactoryBase * factory, CodeDash * codeDash, int populationSize, int generationLimit, int sameScoreLimit, double reuseRatio);
		~Population();

		void Evaluate(EvaluatorBase * evaluator, int retainCount);
		void NextGeneration(double mutate);
		bool Terminate();

		inline SolutionFactoryBase * GetFactory() { return _factory; }
		inline CodeDash * GetCodeDash() { return _codeDash; }
		inline vector<Solution *>& GetPopulation() { return _population; }
		inline vector<Solution *>& GetBestSolutions() { return _bestSolutions; }
		inline int& GetGeneration() { return _generation; }
		inline int& GetSameScore() { return _sameScore; }
		inline int& GetGenerationLimit() { return _generationLimit; }
		inline int& GetSameScoreLimit() { return _sameScoreLimit; }
		inline bool GetSolutionFound() { return _solutionFound; }

		inline void SetGeneration(int value) { _generation = value; }
		inline void SetSameScore(int value) { _sameScore = value; }
	};
}
