cmake_minimum_required(VERSION 3.8)

aux_source_directory(. ALGO_DIR)

add_library(AlgorithmsFuns ${ALGO_DIR})