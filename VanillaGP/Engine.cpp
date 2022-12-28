//--------------------------------------------------
// Implementation code for the Engine
//
// @author: Wild Boar
//
// @date: 2022-12-14
//--------------------------------------------------

#include "Engine.h"
using namespace NVL_App;

//--------------------------------------------------
// Constructor and Terminator
//--------------------------------------------------

/**
 * Main Constructor
 * @param logger The logger that we are using for the system
 * @param parameters The input parameters
 */
Engine::Engine(NVLib::Logger* logger, NVLib::Parameters* parameters) 
{
    // Basic initialization
    _logger = logger; _parameters = parameters; _problem = nullptr; _algorithm = nullptr;

    // Load up code_dash here
    _logger->Log(1, "Connecting to the server machine");
    _machineName = ArgUtils::GetString(_parameters, "machine");
    auto server = ArgUtils::GetString(_parameters, "server");
    auto port = ArgUtils::GetString(_parameters, "port");
    auto uri = ArgUtils::GetString(_parameters, "uri");
    _codeDash = new NVL_AI::CodeDash(server, uri, port);
    auto connection = _codeDash->Ping(); 
    if (connection == string()) throw runtime_error("Connection with server failed");
    _logger->Log(1, "Server connection established");
}

/**
 * Main Terminator 
 */
Engine::~Engine() 
{
    delete _parameters; 
    delete _codeDash;
    if (_problem != nullptr) delete _problem;
    if (_algorithm != nullptr) delete _algorithm;
}

//--------------------------------------------------
// Execution Entry Point
//--------------------------------------------------

/**
 * Entry point function
 */
void Engine::Run()
{
    _logger->Log(1, "Loading problem");
    auto problemCode = ArgUtils::GetString(_parameters, "problem_code"); auto problemFile = ArgUtils::GetString(_parameters, "problem_file");
    _problem = new NVL_AI::ProblemLoader(problemCode, problemFile); _problem->Load(_codeDash);
    _logger->Log(1, "Problem Loaded: %s", _problem->GetDescription().c_str());
    _logger->Log(1, "Number of test records: %i", _problem->GetData().rows);

    _logger->Log(1, "Loading Algorithm");
    auto algorithmCode = ArgUtils::GetString(_parameters, "algorithm_code");
    _algorithm = new NVL_AI::AlgorithmLoader(algorithmCode); _algorithm->Load(_codeDash);
    _logger->Log(1, "Algorithm Loaded: %s", _algorithm->GetDetails().c_str());
    _logger->Log(1, "Grammar to be used: %s", _algorithm->GetGrammar().c_str());
    _logger->Log(1, "Evaluator to be used: %s", _algorithm->GetEvaluation().c_str());

    //_logger->Log(1, "Creating a session");
    //_codeDash->CreateSession()

}
