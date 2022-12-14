#--------------------------------------------------------
# CMake for generating VanillaGPLib Testing Suite
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
add_executable (VanillaGPTests
	Tests/Example_Tests.cpp
	Tests/RandomInitializer_Tests.cpp
	Tests/DNAInitializer_Tests.cpp
)


# Add link libraries
target_link_libraries(VanillaGPTests VanillaGPLib NVLib ${OpenCV_LIBS} UnitTestLib GTest::Main)

# Find the associated unit tests
gtest_discover_tests(VanillaGPTests)
