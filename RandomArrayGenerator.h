#ifndef RANDOMARRAYGENERATOR_H
#define RANDOMARRAYGENERATOR_H

#include <vector>

class RandomArrayGenerator {
public:
    template<typename T>
    static std::vector<T> generateRandomArray(int size);
    using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;
    static ArrayTriple createTripleArrayWithDifTypes(const std::vector<int>& sizes);
};

#endif // RANDOMARRAYGENERATOR_H

