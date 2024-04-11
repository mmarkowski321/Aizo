#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <iostream>
#include "Sort.h"
#include <chrono>
#include <windows.h>
template<typename T>
class ShellSort : public Sort<T> {
public:
    void sort(std::vector<T>& arr) override {
        auto start = std::chrono::high_resolution_clock ::now();
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                T temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
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
    void saveResultsToFile(size_t size, const std::string& typeName, double elapsedTime) {
        std::ofstream file("sort_results_shellSort.csv", std::ios::app); // Otwiera plik do dopisywania
        if (file.is_open()) {
            file << typeName << "," << size << "," << elapsedTime << "\n";
            file.close();
        } else {
            std::cerr << "Nie udało się otworzyć pliku do zapisu wyników.\n";
        }
    }
};

#endif // SHELLSORT_H
