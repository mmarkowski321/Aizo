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
};

template<typename T>
void SortingMethods::sortingMethod(std::vector<std::vector<T>>& arrays, int choosenMethod) {
    if (choosenMethod != 2 && choosenMethod != 4) {
        for (auto &array: arrays) {
            switch (choosenMethod) {
                case 1: {
                    InsertionSort<T> sorter;
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                    break;
                }
                case 3: {
                    HeapSort<T> sorter;
                    sorter.sort(array);
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
    std::cout << "1. Klasyczna sekwencja Shella (początkowa wartość gap równa połowie długości tablicy, redukcja gapu o połowę w każdym kroku)\n";
    std::cout << "2. Sekwencja Sedgewicka (zaawansowana sekwencja oparta na połączeniu dwóch serii wzorów, zapewniająca lepszą efektywność)\n";
    std::cin>>choice;
    switch (choice) {
        case 1:
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Shell);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Shell);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Shell);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
            break;

        case 2:
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Sedgewick);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
            break;
        default:
            std::cout<<"Niepoprawny wybor, domyslnie przyjme sortowanie jako klasyczna sekwencje Shella"<<std::endl;
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    ShellSort<ValueType> sorter(ShellSort<int>::GapSequence::Shell);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    ShellSort<ValueType> sorter(ShellSort<double>::GapSequence::Shell);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    ShellSort<ValueType> sorter(ShellSort<char>::GapSequence::Shell);
                    sorter.sort(array);
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
    std::cout << "3. Element środkowy\n";
    std::cout << "4. Losowy element\n";
    std::cin >> choice;
    switch (choice) {
        case 1:
        {
            for(auto& array : arrays){
                using ValueType = typename std::decay<decltype(array)>::type::value_type;
                if constexpr (std::is_same_v<ValueType, int>) {
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::FIRST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::FIRST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::FIRST);
                    sorter.sort(array);
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
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::LAST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::LAST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::LAST);
                    sorter.sort(array);
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
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::MIDDLE);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::MIDDLE);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::MIDDLE);
                    sorter.sort(array);
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
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::RANDOM);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::RANDOM);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::RANDOM);
                    sorter.sort(array);
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
                    QuickSort<ValueType> sorter(QuickSort<int>::PivotType::LAST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, double>) {
                    QuickSort<ValueType> sorter(QuickSort<double>::PivotType::LAST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else if constexpr (std::is_same_v<ValueType, char>) {
                    QuickSort<ValueType> sorter(QuickSort<char>::PivotType::LAST);
                    sorter.sort(array);
                    sorter.checkCorrectnessOfSorting(array);
                } else {
                    std::cout<<"Bład";
                }
            }
    }
}


#endif // SORTINGMETHODS_H
