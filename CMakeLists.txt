cmake_minimum_required(VERSION 3.8)
project(Assignment5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Simulator.cpp Simulator.h pageReplacementAlgorithms/Paging.cpp pageReplacementAlgorithms/Paging.h Page.cpp Page.h Utils.cpp Utils.h Process.cpp Process.h PageCache.cpp PageCache.h MemorySlot.cpp MemorySlot.h pageReplacementAlgorithms/LeastRecentlyUsed.cpp pageReplacementAlgorithms/LeastRecentlyUsed.h pageReplacementAlgorithms/RandomReplacement.cpp pageReplacementAlgorithms/RandomReplacement.h pageReplacementAlgorithms/FIFOReplacement.cpp pageReplacementAlgorithms/FIFOReplacement.h)
add_executable(Assignment5 ${SOURCE_FILES})