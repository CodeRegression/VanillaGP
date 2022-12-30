//--------------------------------------------------
// Defines a basic engine for a vanilla C++ project.
//
// @author: Wild Boar
//
// @date: 2022-12-14
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include <NVLib/Logger.h>

#include <VanillaGPLib/ArgUtils.h>
#include <VanillaGPLib/ProblemLoader.h>
#include <VanillaGPLib/AlgorithmLoader.h>
#include <VanillaGPLib/Population.h>

#include <VanillaGPLib/EvalEngine/EvalFactory.h>

#include "Helpers/GrammarFinder.h"

namespace NVL_App
{
	class Engine
	{
	private:
		NVLib::Parameters * _parameters;
		NVLib::Logger* _logger;

		NVL_AI::ProblemLoader * _problem;
		NVL_AI::AlgorithmLoader * _algorithm;
		NVL_AI::CodeDash * _codeDash;

		NVL_AI::SolutionFactoryBase * _solutionFactory;
		NVL_AI::Population * _population;
		NVL_AI::RendererBase * _renderer;
		NVL_AI::EvaluatorBase * _evaluator;

		string _machineName;
		int _sessionId;

		int _depthLimit;
		int _populationSize;
		int _generationLimit;
		int _flatLineLimit;
		int _eliteCount;
		int _tournamentSize;
		double _reuseRatio;
		double _mutationRatio;
	public:
		Engine(NVLib::Logger* logger, NVLib::Parameters * parameters);
		~Engine();

		void Run();
	private:
		void ControlLoop();
	};
}
