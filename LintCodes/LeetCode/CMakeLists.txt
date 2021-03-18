cmake_minimum_required(VERSION 3.8)

aux_source_directory(. Leet_DIR)
set(CMAKE_BUILD_TYPE "Debug") 

add_library(LeetFuns ${Leet_DIR} 0045jump.cpp 0122maxProfit.cpp)