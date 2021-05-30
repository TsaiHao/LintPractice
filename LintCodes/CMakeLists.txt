cmake_minimum_required (VERSION 3.8)

add_subdirectory(LintCode)
add_subdirectory(LeetCode)

add_executable (LintCodes main.cpp)

target_link_libraries(LintCodes LintFuns LeetFuns)