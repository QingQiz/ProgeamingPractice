cmake_minimum_required(VERSION 2.8)

# Project Name
project(foo)

# Source Directory
aux_source_directory(. Foo)

# Make executable
add_executable(foo ${Foo})

# Debug module
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
