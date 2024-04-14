#include "RandomArrayGenerator.h"
#include <cstdlib>
#include <ctime>

template<typename T>
std::vector<T> RandomArrayGenerator::generateRandomArray(int size) {
    std::vector<T> arr(size);
    for (T& val : arr) {
        if constexpr (std::is_same_v<T, int>) {
            val = rand() % 1000000;
        } else if constexpr (std::is_same_v<T, double>) {
            val = static_cast<double>(rand()) / RAND_MAX * 1000000.0;
        } else if constexpr (std::is_same_v<T, char>) {
            val = static_cast<char>('a' + (rand() % 26));
        }
    }
    return arr;
}

// Zdefiniuj alias typu dla łatwiejszego odniesienia
using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;

// Funkcja do tworzenia tablic losowych danych o określonym rozmiarze i zwracania ich
ArrayTriple RandomArrayGenerator::createTripleArrayWithDifTypes(const std::vector<int>& sizes) {
    std::vector<std::vector<int>> allVectorsOfInteger;
    std::vector<std::vector<double>> allVectorsOfDoubles;
    std::vector<std::vector<char>> allVectorsOfChars;

    for (int size : sizes) {
        allVectorsOfInteger.push_back(RandomArrayGenerator::generateRandomArray<int>(size));
        allVectorsOfDoubles.push_back(RandomArrayGenerator::generateRandomArray<double>(size));
        allVectorsOfChars.push_back(RandomArrayGenerator::generateRandomArray<char>(size));
    }
    // Zwróć wszystkie trzy wektory jako jeden obiekt typu std::tuple
    return {allVectorsOfInteger, allVectorsOfDoubles, allVectorsOfChars};
}
