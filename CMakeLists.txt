cmake_minimum_required(VERSION 3.27)
project(Aizo)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aizo main.cpp
        sortingAlgorithm/Sort.h
        sortingAlgorithm/HeapSort.h
        sortingAlgorithm/QuickSort.h
        sortingAlgorithm/InsertionSort.h
        sortingAlgorithm/ShellSort.h
        AlgorithmTests.cpp
        AlgorithmTests.h
        FileReader.cpp
        FileReader.h
        RandomArrayGenerator.cpp
        RandomArrayGenerator.h
        UserInterface.cpp
        UserInterface.h
        SortingMethods.h
)
