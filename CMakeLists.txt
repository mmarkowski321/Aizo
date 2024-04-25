cmake_minimum_required(VERSION 3.27)
project(Aizo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
MATH(EXPR stack_size "16 * 1024 * 1024")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--stack,${stack_size}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,16777216")

#set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(Aizo main.cpp
        sortingAlgorithm/Sort.h
        sortingAlgorithm/HeapSort.h
        sortingAlgorithm/QuickSort.h
        sortingAlgorithm/InsertionSort.h
        sortingAlgorithm/ShellSort.h
        AlgorithmTests.cpp
        AlgorithmTests.h
        FileController.cpp
        FileController.h
        RandomArrayGenerator.cpp
        RandomArrayGenerator.h
        UserInterface.cpp
        UserInterface.h
        SortingMethods.h
)
