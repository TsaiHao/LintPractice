cmake_minimum_required (VERSION 3.8)

add_subdirectory(LintCode)
add_subdirectory(LeetCode)
set(CMAKE_BUILD_TYPE "Debug") 
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

add_executable (LintCodes main.cpp)

target_link_libraries(LintCodes LintFuns LeetFuns)