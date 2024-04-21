#include "RandomArrayGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "UserInterface.h"
#include "FileController.h"


template<typename T>
std::vector<T> RandomArrayGenerator::generateArray(int size) {
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
// Funkcja generująca tablicę z wartościami rosnącymi
template<typename T>
std::vector<T> RandomArrayGenerator::generateIncreasingArray(int size) {
    std::vector<T> arr = RandomArrayGenerator::generateArray<T>(size);
    std::sort(arr.begin(), arr.end());
    return arr;
}

// Funkcja generująca tablicę z wartościami malejącymi
template<typename T>
std::vector<T> RandomArrayGenerator::generateDecreasingArray(int size) {
    std::vector<T> arr = RandomArrayGenerator::generateArray<T>(size);
    std::reverse(arr.begin(), arr.end());
    return arr;
}

// Funkcja generująca tablicę, gdzie 33% jest posortowane rosnąco
template<typename T>
std::vector<T> RandomArrayGenerator::generatePartiallySortedArray33(int size) {
    std::vector<T> arr = RandomArrayGenerator::generateArray<T>(size);
    std::sort(arr.begin(), arr.begin() + (size / 3));
    return arr;
}

// Funkcja generująca tablicę, gdzie 66% jest posortowane rosnąco
template<typename T>
std::vector<T> RandomArrayGenerator::generatePartiallySortedArray66(int size) {
    std::vector<T> arr = RandomArrayGenerator::generateArray<T>(size);
    std::sort(arr.begin(), arr.begin() + (2 * size / 3));
    return arr;
}

// Zdefiniuj alias typu dla łatwiejszego odniesienia
using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;

// Funkcja do tworzenia tablic losowych danych o określonym rozmiarze i zwracania ich
ArrayTriple RandomArrayGenerator::createTripleArrayWithDifTypes(const std::vector<int>& sizes) {
    std::vector<std::vector<int>> allVectorsOfInteger;
    std::vector<std::vector<double>> allVectorsOfDoubles;
    std::vector<std::vector<char>> allVectorsOfChars;
    UserInterface::printAllKindOfTables();
    int choice = UserInterface::getUserInput();
    switch (choice) {
        case 1 :
            for (int size : sizes) {
                allVectorsOfInteger.push_back(RandomArrayGenerator::generateRandomArray<int>(size));
                allVectorsOfDoubles.push_back(RandomArrayGenerator::generateRandomArray<double>(size));
                allVectorsOfChars.push_back(RandomArrayGenerator::generateRandomArray<char>(size));
            }

            break;
        case 2 :
            //funkcja generujaca cala tablice rosnaco
            for (int size : sizes) {
                allVectorsOfInteger.push_back(RandomArrayGenerator::generateIncreasingArray<int>(size));
                allVectorsOfDoubles.push_back(RandomArrayGenerator::generateIncreasingArray<double>(size));
                allVectorsOfChars.push_back(RandomArrayGenerator::generateIncreasingArray<char>(size));
            }
            break;
        case 3 :
            //funkcja generujaca cala tablice malejaco
            for (int size : sizes) {
                allVectorsOfInteger.push_back(RandomArrayGenerator::generateDecreasingArray<int>(size));
                allVectorsOfDoubles.push_back(RandomArrayGenerator::generateDecreasingArray<double>(size));
                allVectorsOfChars.push_back(RandomArrayGenerator::generateDecreasingArray<char>(size));
            }
            break;
        case 4 :
            //funkcja generujaca cala tablice posortowana w 33%
            for (int size : sizes) {
                allVectorsOfInteger.push_back(RandomArrayGenerator::generatePartiallySortedArray33<int>(size));
                allVectorsOfDoubles.push_back(RandomArrayGenerator::generatePartiallySortedArray33<double>(size));
                allVectorsOfChars.push_back(RandomArrayGenerator::generatePartiallySortedArray33<char>(size));
            }
            break;
        case 5 :
            //funkcja generujaca cala tablice posortowana w 66%
            for (int size : sizes) {
                allVectorsOfInteger.push_back(RandomArrayGenerator::generatePartiallySortedArray66<int>(size));
                allVectorsOfDoubles.push_back(RandomArrayGenerator::generatePartiallySortedArray66<double>(size));
                allVectorsOfChars.push_back(RandomArrayGenerator::generatePartiallySortedArray66<char>(size));
            }
            break;
        default:
            std::cout<<"Niepoprawny numer, sprobuj jeszcze raz"<<std::endl;
            RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
    }

    // Zwróć wszystkie trzy wektory jako jeden obiekt typu std::tuple
    return {allVectorsOfInteger, allVectorsOfDoubles, allVectorsOfChars};
}
