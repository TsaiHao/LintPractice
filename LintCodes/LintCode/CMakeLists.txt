cmake_minimum_required(VERSION 3.8)

aux_source_directory(. ALGO_DIR)
set(CMAKE_BUILD_TYPE "Debug") 
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_library(LintFuns ${ALGO_DIR})