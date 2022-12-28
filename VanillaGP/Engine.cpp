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

    // Initialize the size
    _sessionId = -1;

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
    // Close the session (if it has not been closed already)
    if (_sessionId != -1) _codeDash->EndSession(_sessionId);

    // Free loaded entities
    if (_problem != nullptr) delete _problem;
    if (_algorithm != nullptr) delete _algorithm;

    // Free parameters and code dash
    delete _parameters;  delete _codeDash;
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

    _logger->Log(1, "Creating a session");
    _sessionId = _codeDash->CreateSession(algorithmCode, problemCode, _machineName);
    _logger->Log(1, "Created Session: %i", _sessionId);

    _logger->Log(1, "Starting the control loop");
    _codeDash->StartSession(_sessionId);
    ControlLoop();
}

/**
 * @brief Start the control loop
 */
void Engine::ControlLoop() 
{
    while (true) 
    {
        _logger->Log(1, "Polling Session State");
        auto state = _codeDash->GetSessionState(_sessionId);

        if (state == "STOP") 
        {
            _logger->Log(1, "Session Paused - waiting a second and then trying again");
            sleep(1);
            continue;
        }
        else if (state != "START") 
        {
            _logger->Log(1, "Session is no longer running - ending session");
            _sessionId = -1;
            break;
        }

        _logger->Log(1, "Normal Work Cycle Happens for session: %i", _sessionId);
        sleep(1);
    }
}