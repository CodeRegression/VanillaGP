#--------------------------------------------------------
# CMake for generating the VanillaGPLib
#
# @author: Wild Boar
#
# Date Created: 2022-12-14
#--------------------------------------------------------

# Setup include directories
include_directories("../" "${LIBRARY_BASE}/NVLib")

# Create Library
add_library(VanillaGPLib STATIC
    ArgUtils.cpp
)
