#ifndef SORTINGMETHODS_H
#define SORTINGMETHODS_H

#include <vector>
#include "UserInterface.h"
#include "sortingAlgorithm/Sort.h"
#include "sortingAlgorithm/InsertionSort.h"
#include "sortingAlgorithm/QuickSort.h"
#include "sortingAlgorithm/HeapSort.h"
#include "sortingAlgorithm/ShellSort.h"

class SortingMethods {
public:
    template<typename T>
    static void getPivotChoice(std::vector<T> &arrays);
    template<typename T>
    static void sortingMethod(std::vector<std::vector<T>>& arrays, int choosenMethod);

    template<typename T>
    static void getShellChoice(std::vector<T> &arrays);

    template<typename T>
    static void saveTableToFile(std::string fileName,std::vector<T> array,std::string sortingMethodName);

};


template<typename T>
void SortingMethods::saveTableToFile(std::string filename, std::vector<T> array,std::string sortingMethodName) {
    std::ofstream fileStream(filename, std::ios::app); // Użyj ofstream z flagą app do dopisywania

    if (fileStream.is_open()) {
        fileStream << "\n\n" <<sortingMethodName << "\n\n"; // Dodaj nazwę metody sortowania jako nagłówek
        for (const auto &item : array) {
            fileStream << item << " "; // Zapisz elementy tablicy do pliku
        }
        fileStream << "\n"; // Dodaj nową linię na końcu zapisu każdej tablicy
        std::cout << "\n\n"; // Wyświetl nową linię w konsoli (jeśli to potrzebne)
    } else {
        std::cerr << "Nie udało się otworzyć pliku: " << filename << std::endl; // Informacja o błędzie
    }
}

template<typename T>
void SortingMethods::sortingMethod(std::vector<std::vector<T>>& arrays, int choosenMethod) {
    if (choosenMethod != 2 && choosenMethod != 4) {
        for (auto &array: arrays) {
            switch (choosenMethod) {
                case 1: {
                    saveTableToFile("unsortedAllTables.txt",array,"InsertionSort");
                    InsertionSort<T> sorter;
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"InsertionSort");
                    sorter.checkCorrectnessOfSorting(array);
                    break;
                }
                case 3: {
                    saveTableToFile("unsortedAllTables.txt",array,"HeapSort");
                    HeapSort<T> sorter;
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"HeapSort");
                    sorter.checkCorrectnessOfSorting(array);
                    break;
                }
            }
        }
    } else if (choosenMethod == 2){
        getPivotChoice(arrays);
    }else{
        getShellChoice(arrays);
    }
}
template<typename T>
void SortingMethods::getShellChoice(std::vector<T> &arrays){
    int choice;
    std::cout << "Wybierz typ sekwencji Shella:\n";
    std::cout << "1. Klasyczna sekwencja Shella (poczatkowa wartosc gap rowna polowie dlugosci tablicy, redukcja gapu o polowe w kazdym kroku)\n";
    std::cout << "2. Sekwencja Sedgewicka (zaawansowana sekwencja oparta na polaczeniu dwoch serii wzorow, zapewniajaca lepsza efektywnosc)\n";
    std::cin>>choice;
    switch (choice) {
        case 1:
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Blad";
                }
            }
            break;

        case 2:
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Blad";
                }
            }
            break;
        default:
            std::cout<<"Niepoprawny wybor, domyslnie przyjme sortowanie jako klasyczna sekwencje Shella"<<std::endl;
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"ShellSort");
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Shell);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"ShellSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
            break;
    }

}

template<typename T>
void SortingMethods::getPivotChoice(std::vector<T> &arrays) {
    int choice;
    std::cout << "Wybierz typ pivota:\n";
    std::cout << "1. Pierwszy element\n";
    std::cout << "2. Ostatni element\n";
    std::cout << "3. Element srodkowy\n";
    std::cout << "4. Losowy element\n";
    std::cin >> choice;
    switch (choice) {
        case 1:
        {
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::FIRST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::FIRST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::FIRST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
        }
            break;
        case 2:
        {
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
        }
            break;
        case 3:
        {
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::MIDDLE);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::MIDDLE);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::MIDDLE);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
        }
            break;
        case 4:
        {
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::RANDOM);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::RANDOM);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::RANDOM);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
        }
            break;
        default:
            std::cout << "Niepoprawny wybór, używam ostatniego elementu jako pivot." << std::endl;
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    saveTableToFile("unsortedAllTables.txt",array,"QuickSort");
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::LAST);
                    sorter.sort(array);
                    saveTableToFile("sortedAllTables.txt",array,"QuickSort");
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
    }
}


#endif // SORTINGMETHODS_H
