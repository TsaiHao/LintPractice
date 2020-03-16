# CMakeList.txt: LintCodes 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

add_subdirectory(LintCode)
add_subdirectory(LeetCode)
set(CMAKE_BUILD_TYPE "Debug") 
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
# 将源代码添加到此项目的可执行文件。
add_executable (LintCodes main.cpp)

target_link_libraries(LintCodes LintFuns LeetFuns)