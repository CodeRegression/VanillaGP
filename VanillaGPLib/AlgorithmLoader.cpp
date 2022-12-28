//--------------------------------------------------
// Implementation of class AlgorithmLoader
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#include "AlgorithmLoader.h"
using namespace NVL_AI;

//--------------------------------------------------
// Constructors and Terminators
//--------------------------------------------------

/**
 * @brief Custom Constructor
 * @param code The code of the algorithm that we are using
 */
AlgorithmLoader::AlgorithmLoader(const string& code) : _code(code)
{	
	_id = -1; _name = string(); _details = string(); _program = string();
	_evaluation = string(); _grammar = string(); _version = string();
}

//--------------------------------------------------
// Loader
//--------------------------------------------------

/**
 * @brief Invokes of a load of the details
 * @param codeDash A link to the server via the code_dash interface
 */
void AlgorithmLoader::Load(CodeDash * codeDash)
{
	auto details = codeDash->GetAlgorithmDetails(_code);

	auto parts = vector<string>(); NVLib::StringUtils::Split(details, ',', parts);

	_id = NVLib::StringUtils::String2Int(parts[0]);
	_name = parts[1];
	_details = parts[2];
	_program = parts[3];
	_evaluation = parts[4];
	_grammar = parts[5];
	_version = parts[6];
}
