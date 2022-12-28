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
    _logger = logger; _parameters = parameters; _problem = nullptr;

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
    auto problem = new NVL_AI::ProblemLoader(problemCode, problemFile); problem->Load(_codeDash);
    _logger->Log(1, "Problem Loaded: %s", problem->GetDescription().c_str());
    _logger->Log(1, "Number of test records: %i", problem->GetData().rows);

    //_logger->Log(1, "Creating a session");
    //_codeDash->CreateSession()

}
