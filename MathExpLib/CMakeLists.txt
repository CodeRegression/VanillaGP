#--------------------------------------------------------
# CMake for generating the MathExpLib
#
# @author: Wild Boar
#
# Date Created: 2022-12-14
#--------------------------------------------------------

# Setup includes directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library (MathExpLib STATIC
	ParameterNode.cpp
	AddNode.cpp
	NodeFactory.cpp
	ConstantNode.cpp
	MultiplyNode.cpp
	PowerNode.cpp
	NegateNode.cpp
)
