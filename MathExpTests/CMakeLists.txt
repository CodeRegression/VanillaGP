#--------------------------------------------------------
# CMake for generating MathExpLib Testing Suite
#
# @author: Wild Boar
#
# Date Created: 2022-12-14
#--------------------------------------------------------

# Add Google Test to the test group
find_package(GTest REQUIRED)

# Setup the includes
include_directories("../")

# Add the UnitTestLib library to the folder
add_library(UnitTestLib STATIC IMPORTED)
set_target_properties(UnitTestLib PROPERTIES
    IMPORTED_LOCATION "${LIBRARY_BASE}/UnitTestLib/build/UnitTestLib/libUnitTestLib.a"
    INTERFACE_INCLUDE_DIRECTORIES "${LIBRARY_BASE}/UnitTestLib"
)

# Create the executable
add_executable (MathExpTests
	Tests/ParameterNode_Tests.cpp
	Tests/AddNode_Tests.cpp
	Tests/NodeFactory_Tests.cpp
	Tests/ConstantNode_Tests.cpp
	Tests/MultiplyNode_Tests.cpp
	Tests/PowerNode_Tests.cpp
	Tests/NegateNode_Tests.cpp
	Tests/InvertNode_Tests.cpp
	Tests/TreeFactory_Tests.cpp
	Tests/TreeCalculator_Tests.cpp
	Tests/Population_Tests.cpp
	Tests/TreeRenderer_Tests.cpp
)


# Add link libraries
target_link_libraries(MathExpTests MathExpLib VanillaGPLib NVLib ${OpenCV_LIBS} UnitTestLib GTest::Main)

# Find the associated unit tests
gtest_discover_tests(MathExpTests)