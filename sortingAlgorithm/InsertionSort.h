#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream> // Dla std::ofstream
template<typename T>
class InsertionSort : public Sort<T> {
public:
    void sort(std::vector<T>& arr) override {
        auto start = std::chrono::high_resolution_clock ::now();
        for (size_t i = 1; i < arr.size(); i++) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
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
    void checkCorrectnessOfSorting(std::vector<T>& arr) override {
        if (arr.size() > 1) { // Sprawdzenie czy tablica ma więcej niż jeden element
            for (int i = 0; i < arr.size() - 1; ++i) { // Pętla po wszystkich elementach poza ostatnim
                if (arr[i] > arr[i + 1]) { // Jeśli znaleziono element w złej kolejności
                    std::cout << "Błąd w sortowaniu: arr[" << i << "] = " << arr[i] << " > arr[" << i + 1 << "] = " << arr[i + 1] << std::endl;
                    return; // Przerwanie funkcji, gdy znaleziono błąd
                }
            }
            std::cout << "Tablica posortowana poprawnie" << std::endl;
        } else {
            std::cout << "Tablica ma mniej niż dwa elementy, więc jest automatycznie posortowana" << std::endl;
        }
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
        std::ofstream file("sort_results_insertionSort.csv", std::ios::app); // Otwiera plik do dopisywania
        if (file.is_open()) {
            file << typeName << "," << size << "," << elapsedTime << "\n";
            file.close();
        } else {
            std::cerr << "Nie udało się otworzyć pliku do zapisu wyników.\n";
        }
    }
};

#endif // INSERTIONSORT_H
