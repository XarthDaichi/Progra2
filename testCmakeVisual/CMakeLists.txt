# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("testCmakeVisual")

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

# Include sub-projects.
add_subdirectory ("src")
