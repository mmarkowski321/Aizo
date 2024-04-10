#include <iostream>
#include "AlgorithmTests.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <type_traits>
#include <limits>
#include "AlgorithmTests.h"
#include "sortingAlgorithm/Sort.h"
#include "sortingAlgorithm/InsertionSort.h"
#include "sortingAlgorithm/QuickSort.h"
#include "sortingAlgorithm/HeapSort.h"
#include "sortingAlgorithm/ShellSort.h"
using namespace std;


//funkcja printujaca wszystkie mozliwosci
void printAllOptions(){
    cout<<"Wybierz jedna z opcji"<<endl;
    cout<<"Wyjscie - #0"<<endl;
    cout<<"Wyswietl testowe sortowanie na liczbach stworzonych losowo(dodatkowa opcja)- #1"<<endl;
    cout<<"Odczytywanie danych z pliku - #2"<<endl;
}


// Funkcja do odczytu danych z pliku i zwrócenia ich jako vector<int>
vector<int> readDataFromFile() {
    string filePath;
    cout << "Podaj sciezke do pliku: ";
    cin >> filePath;

    ifstream fileStream(filePath); // Otwieranie pliku
    vector<int> values; // Wektor na odczytane wartości

    if (fileStream.is_open()) {
        int value;
        while (fileStream >> value) {
            cout << "Odczytano wartosc: " << value << endl;
            values.push_back(value); // Dodawanie odczytanej wartości do wektora
        }
        fileStream.close();
    } else {
        cout << "Nie mozna otworzyc pliku!" << endl;
    }

    return values; // Zwracanie wektora z wartościami
}


// Funkcja do generowania losowych danych dla różnych typów
template<typename T>
vector<T> generateRandomArray(int size) {
    vector<T> arr(size);
    for (T &val : arr) {
        if constexpr (is_same<T, int>::value) {
            val = rand() % 1000000; // Losowa wartość dla int
        } else if constexpr (is_same<T, double>::value) {
            val = static_cast<double>(rand()) / RAND_MAX * 1000000.0; // Losowa wartość dla double
        } else if constexpr (is_same<T, char>::value) {
            val = static_cast<char>('a' + (rand() % 26)); // Losowa litera dla char
        }
    }
    return arr;
}


// Zdefiniuj alias typu dla łatwiejszego odniesienia
using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;

// Funkcja do tworzenia tablic losowych danych o określonym rozmiarze i zwracania ich
ArrayTriple createRandomArrays(const std::vector<int>& sizes) {
    std::vector<std::vector<int>> allVectorsOfInteger;
    std::vector<std::vector<double>> allVectorsOfDoubles;
    std::vector<std::vector<char>> allVectorsOfChars;

    for (int size : sizes) {
        allVectorsOfInteger.push_back(generateRandomArray<int>(size));
        allVectorsOfDoubles.push_back(generateRandomArray<double>(size));
        allVectorsOfChars.push_back(generateRandomArray<char>(size));
    }
    // Zwróć wszystkie trzy wektory jako jeden obiekt typu std::tuple
    return {allVectorsOfInteger, allVectorsOfDoubles, allVectorsOfChars};
}


void printAllSortingMethods(){
    std::cout << "Wybierz algorytm sortowania:\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Quick Sort\n";
    std::cout << "3. Heap Sort\n";
    std::cout << "4. Shell Sort\n";
    std::cout << "0. Wyjscie\n";
}


// Wybór metody sortowania
enum class SortingMethod {
    InsertionSort,
    QuickSort,
    HeapSort,
    ShellSort
};


SortingMethod getUserChoice() {
    printAllSortingMethods();
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            return SortingMethod::InsertionSort;
        case 2:
            return SortingMethod::QuickSort;
        case 3:
            return SortingMethod::HeapSort;
        case 4:
            return SortingMethod::ShellSort;
        default:
            std::cout << "Niepoprawny wybor, uzywam HeapSort." << std::endl;
            return SortingMethod::HeapSort;
    }
}


template<typename T>
typename QuickSort<T>::PivotType getPivotChoice() {
    int choice;
    std::cout << "Wybierz typ pivota:\n";
    std::cout << "1. Pierwszy element\n";
    std::cout << "2. Ostatni element\n";
    std::cout << "3. Element środkowy\n";
    std::cout << "4. Losowy element\n";
    std::cin >> choice;
    switch (choice) {
        case 1: return QuickSort<T>::PivotType::FIRST;
        case 2: return QuickSort<T>::PivotType::LAST;
        case 3: return QuickSort<T>::PivotType::MIDDLE;
        case 4: return QuickSort<T>::PivotType::RANDOM;
        default:
            std::cout << "Niepoprawny wybór, używam ostatniego elementu jako pivot." << std::endl;
            return QuickSort<T>::PivotType::LAST;
    }
}

// Zaktualizowana metoda sortingMethod
template<typename T>
void sortingMethod(std::vector<std::vector<T>>& arrays, SortingMethod method) {
    for (auto& array : arrays) {
        switch (method) {
            case SortingMethod::InsertionSort: {
                InsertionSort<T> sorter;
                sorter.sort(array);
                break;
            }
            case SortingMethod::QuickSort: {

                QuickSort<T> sorter;
                sorter.sort(array); // Sortuj tablicę
                break;
            }
            case SortingMethod::HeapSort: {
                HeapSort<T> sorter;
                sorter.sort(array);
                break;
            }
            case SortingMethod::ShellSort: {
                ShellSort<T> sorter;
                sorter.sort(array);
                break;
            }
        }
    }
}
int main() {
    std::cout<<"Witam w moim programie ktory polega na sortowaniu danych od najmniejszej wartosci do najwiekszej"<<std::endl<<endl;
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice;
    int exit = 0;
    do {
        printAllOptions();
        cin>>choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice) {
            case 1:
                displayAlgorithmTest();
                break;
            case 2: {
                vector<int> sizes = readDataFromFile();
                ArrayTriple arrays = createRandomArrays(sizes);
                SortingMethod chosenMethod = getUserChoice();
                sortingMethod(std::get<0>(arrays), chosenMethod);
                sortingMethod(std::get<1>(arrays), chosenMethod);
                sortingMethod(std::get<2>(arrays), chosenMethod);
                break;
            }
        }
    }while(choice != exit);

    return 0;
}

