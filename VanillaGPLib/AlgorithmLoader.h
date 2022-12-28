//--------------------------------------------------
// Verifies the algorithm details as per the database
//
// @author: Wild Boar
//
// @date: 2022-12-28
//--------------------------------------------------

#pragma once

#include <iostream>
using namespace std;

#include "CodeDash.h"

namespace NVL_AI
{
	class AlgorithmLoader
	{
	private:
		int _id;
		string _code;
		string _name;
		string _details;
		string _program;
		string _evaluation;
		string _grammar;
		string _version;
	public:
		AlgorithmLoader(const string& code);

		void Load(CodeDash * codeDash);

		inline int& GetId() { return _id; }
		inline string& GetCode() { return _code; }
		inline string& GetName() { return _name; }
		inline string& GetDetails() { return _details; }
		inline string& GetProgram() { return _program; }
		inline string& GetEvaluation() { return _evaluation; }
		inline string& GetGrammar() { return _grammar; }
		inline string& GetVersion() { return _version; }
	};
}
