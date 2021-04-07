# CMakeList.txt : CMake project for aburbe, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("aburbe")

# Add source to this project's executable.
add_executable (aburbe "aburbe.cpp" "aburbe.h" "src/resources.h" "src/UBlock.cpp" "src/UBlock.h")

# TODO: Add tests and install targets if needed.
