#include "RandomArrayGenerator.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "UserInterface.h"
#include "FileController.h"
#include <random>
#include <type_traits>
#include <limits>

template<typename T>
std::vector<T> RandomArrayGenerator::generateArray(int size) {
    std::vector<T> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_same_v<T, int>) {
        std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        for (T& val : arr) {
            val = dist(gen);
        }
    } else if constexpr (std::is_same_v<T, double>) {
        std::uniform_real_distribution<double> dist(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
        for (T& val : arr) {
            val = dist(gen);
        }
    } else if constexpr (std::is_same_v<T, char>) {
        std::uniform_int_distribution<int> dist(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
        for (T& val : arr) {
            val = static_cast<char>(dist(gen));
        }
    }
    return arr;
}
template<typename T>
std::vector<T> RandomArrayGenerator::generateRandomArray(int size) {
    std::vector<T> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());

    if constexpr (std::is_same_v<T, int>) {
        std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
        for (T& val : arr) {
            val = dist(gen);
        }
    } else if constexpr (std::is_same_v<T, double>) {
        std::uniform_real_distribution<double> dist(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max());
        for (T& val : arr) {
            val = dist(gen);
        }
    } else if constexpr (std::is_same_v<T, char>) {
        std::uniform_int_distribution<int> dist(std::numeric_limits<char>::min(), std::numeric_limits<char>::max());
        for (T& val : arr) {
            val = static_cast<char>(dist(gen));
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
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<T> arr(size);
    T current_value = std::numeric_limits<T>::min();
    int sortedSize = static_cast<int>(size * 0.33);  // Obliczenie 33% rozmiaru tablicy, konwersja na int

    // Wypełnienie początkowej części tablicy liczbami posortowanymi
    if constexpr (std::is_arithmetic<T>::value) {

        for (int i = 0; i < sortedSize; ++i) {
            arr[i] = current_value;
            ++current_value; // Inkrementacja wartości dla kolejnych elementów
        }
    }

    // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dis(current_value, std::numeric_limits<T>::max());
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = dis(gen);
        }
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> dis(static_cast<T>(current_value), std::numeric_limits<T>::max());
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = dis(gen);
        }
    } else if constexpr (std::is_same<T, char>::value) {
        // Przykład, gdybyśmy chcieli generować losowe znaki
        std::uniform_int_distribution<int> dis('a', 'z');  // Zakres dla małych liter a-z
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = static_cast<char>(dis(gen));
        }
    }

    return arr;
}

template<typename T>
std::vector<T> RandomArrayGenerator::generatePartiallySortedArray66(int size)  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::vector<T> arr(size);
    T current_value = std::numeric_limits<T>::min();
    int sortedSize = static_cast<int>(size * 0.66);  // Obliczenie 33% rozmiaru tablicy, konwersja na int

    // Wypełnienie początkowej części tablicy liczbami posortowanymi
    if constexpr (std::is_arithmetic<T>::value) {

        for (int i = 0; i < sortedSize; ++i) {
            arr[i] = current_value;
            ++current_value; // Inkrementacja wartości dla kolejnych elementów
        }
    }

    // Wypełnienie pozostałej części tablicy losowymi liczbami większymi od już wypełnionych
    if constexpr (std::is_integral<T>::value) {
        std::uniform_int_distribution<T> dis(current_value, std::numeric_limits<T>::max());
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = dis(gen);
        }
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> dis(static_cast<T>(current_value), std::numeric_limits<T>::max());
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = dis(gen);
        }
    } else if constexpr (std::is_same<T, char>::value) {
        // Przykład, gdybyśmy chcieli generować losowe znaki
        std::uniform_int_distribution<int> dis('a', 'z');  // Zakres dla małych liter a-z
        for (int i = sortedSize; i < size; ++i) {
            arr[i] = static_cast<char>(dis(gen));
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
