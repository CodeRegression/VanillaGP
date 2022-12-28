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

		string _machineName;
		int _sessionId;
	public:
		Engine(NVLib::Logger* logger, NVLib::Parameters * parameters);
		~Engine();

		void Run();
	};
}
