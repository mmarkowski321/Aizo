#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include "Sort.h"
#include <chrono>
#include <windows.h>
template<typename T>
class HeapSort : public Sort<T> {
public:
    void sort(std::vector<T> &arr) override {
        auto start = std::chrono::high_resolution_clock ::now();
        int n = arr.size();

        // Budowanie kopca (przestawienie tablicy)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Jeden po drugim wyjmujemy elementy z kopca
        for (int i = n - 1; i >= 1; i--) {
            // Przenosimy aktualny korzeń na koniec
            std::swap(arr[0], arr[i]);

            // Wywołujemy procedurę heapify na zredukowanym kopcu
            heapify(arr, i, 0);
        }
        auto end = std::chrono::high_resolution_clock::now(); // Zakończenie pomiaru czasu
        std::chrono::duration<double, std::milli> elapsed = end - start; // Obliczenie czasu trwania
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); // Ustaw kolor tekstu na zielony
        std::string type = identrifyType(arr);
        std::cout<<"Sortowanie tablicy o rozmiarze "<<arr.size()<<" i typie "<< type <<std::endl;
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
    void heapify(std::vector<T> &arr, int n, int i) {
        int largest = i; // Inicjalizacja największego jako korzeń
        int l = 2 * i + 1; // lewy = 2*i + 1
        int r = 2 * i + 2; // prawy = 2*i + 2

        // Jeśli lewe dziecko jest większe niż korzeń
        if (l < n && arr[l] > arr[largest]) {
            largest = l;
        }

        // Jeśli prawe dziecko jest większe niż największe do tej pory
        if (r < n && arr[r] > arr[largest]) {
            largest = r;
        }

        // Jeśli największy nie jest korzeniem
        if (largest != i) {
            std::swap(arr[i], arr[largest]);

            // Rekurencyjnie heapify dotknięty podkopiec
            heapify(arr, n, largest);
        }

    }
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
        std::ofstream file("sort_results_heapSort.csv", std::ios::app); // Otwiera plik do dopisywania
        if (file.is_open()) {
            file << typeName << "," << size << "," << elapsedTime << "\n";
            file.close();
        } else {
            std::cerr << "Nie udało się otworzyć pliku do zapisu wyników.\n";
        }
    }
};
#endif // HEAPSORT_H

