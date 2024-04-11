#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"
#include <algorithm> // Dla std::swap
#include <cstdlib> // Dla std::rand
#include <ctime> // Dla std::time
#include <chrono>
#include <iostream>
#include <windows.h>
template<typename T>
class QuickSort : public Sort<T> {
public:
    enum PivotType { FIRST, LAST, MIDDLE, RANDOM };

    QuickSort(PivotType type = PivotType::LAST) : pivotType(type) {}

    void sort(std::vector<T>& arr) override {
        auto start = std::chrono::high_resolution_clock ::now();
        quickSort(arr, 0, arr.size() - 1);
        auto end = std::chrono::high_resolution_clock::now(); // Zakończenie pomiaru czasu
        std::chrono::duration<double, std::milli> elapsed = end - start; // Obliczenie czasu trwania
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); // Ustaw kolor tekstu na zielony
        std::string type = identrifyType(arr);
        std::cout<<"Sortowanie tablicy o rozmiarze "<<arr.size()<<" i typie "<<type<<std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Ustaw kolor tekstu na zielony
        std::cout << "Czas sortowania: " << elapsed.count() << " ms\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset do domyślnych kolorów
        saveResultsToFile(arr.size(), identrifyType(arr), elapsed.count());
    }

    void setPivotType(PivotType type) {
        pivotType = type;
    }

private:
    std::string identrifyType(std::vector<T> &arr){
        std::string typeName = typeid(T).name();
        if constexpr (std::is_same_v<T, int>) {
            return "int";
        } else if constexpr (std::is_same_v<T, double>) {
            return "double";
        } else if constexpr (std::is_same_v<T, char>) {
            return "char";
        } else {
            return "Undefined";
        }
    }
    PivotType pivotType;

    int partition(std::vector<T>& arr, int low, int high) {
        T pivot;
        int pivotIndex = low;
        switch (pivotType) {
            case FIRST:
                pivot = arr[low];
                pivotIndex = low;
                break;
            case LAST:
                pivot = arr[high];
                pivotIndex = high;
                break;
            case MIDDLE:
                pivotIndex = low + (high - low) / 2;
                pivot = arr[pivotIndex];
                break;
            case RANDOM:
                pivotIndex = low + std::rand() % (high - low + 1);
                pivot = arr[pivotIndex];
                break;
        }


        std::swap(arr[pivotIndex], arr[high]);
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] <= pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    void quickSort(std::vector<T>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    void saveResultsToFile(size_t size, const std::string& typeName, double elapsedTime) {
        std::ofstream file("sort_results_quickSort.csv", std::ios::app); // Otwiera plik do dopisywania
        if (file.is_open()) {
            file << typeName << "," << size << "," << elapsedTime << "\n";
            file.close();
        } else {
            std::cerr << "Nie udało się otworzyć pliku do zapisu wyników.\n";
        }
    }
};

#endif // QUICKSORT_H

