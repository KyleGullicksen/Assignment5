cmake_minimum_required(VERSION 3.8)
project(Assignment5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Simulator.cpp Simulator.h pageReplacementAlgorithms/PageReplacementAlgorithm.cpp pageReplacementAlgorithms/PageReplacementAlgorithm.h Page.cpp Page.h Utils.cpp Utils.h Process.cpp Process.h PageMemory.cpp PageMemory.h PageMemorySlot.cpp PageMemorySlot.h)
add_executable(Assignment5 ${SOURCE_FILES})