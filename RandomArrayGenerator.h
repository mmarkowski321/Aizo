#ifndef RANDOMARRAYGENERATOR_H
#define RANDOMARRAYGENERATOR_H

#include <vector>
#include <string>
#include "UserInterface.h"

class RandomArrayGenerator {
public:
    template<typename T>
    static std::vector<T> generateRandomArray(int size);
    using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;
    static ArrayTriple createTripleArrayWithDifTypes(const std::vector<int>& sizes);
    template<typename T>
    static std::vector<T> generateIncreasingArray(int size);
    template<typename T>
    static std::vector<T> generateDecreasingArray(int size);
    template<typename T>
    static std::vector<T> generatePartiallySortedArray33(int size);
    template<typename T>
    static std::vector<T> generatePartiallySortedArray66(int size);
    template<typename T>
    static void saveArrayToFile(const std::vector<T>& arr, const std::string& filename, const std::string& arrayType);
    template<typename T>
    static std::vector<T> generateArray(int size);
};

#endif // RANDOMARRAYGENERATOR_H

