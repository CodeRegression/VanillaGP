#--------------------------------------------------------
# CMake for generating the VanillaGPLib
#
# @author: Wild Boar
#
# Date Created: 2022-12-14
#--------------------------------------------------------

# Setup includes directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library (VanillaGPLib STATIC
	GrammarBase/RandomInitializer.cpp
	GrammarBase/DNAInitializer.cpp
	EvalEngine/EuclidEvaluator.cpp
	ArgUtils.cpp
	Socket.cpp
	CodeDash.cpp
	ProblemLoader.cpp
	AlgorithmLoader.cpp
)