#ifndef SHELLSORT_H
#define SHELLSORT_H
#include <iostream>
#include "Sort.h"
#include <chrono>
#include <windows.h>
// Define gap sequences available for ShellSort
enum class GapSequence {
    Shell,
    Sedgewick
};
template<typename T>
class ShellSort : public Sort<T> {
public:
    enum class GapSequence {
        Shell,
        Sedgewick
    };
    void checkCorrectnessOfSorting(std::vector<T>& arr) override {
        if (arr.size() > 1) { // Sprawdzenie czy tablica ma więcej niż jeden element
            for (int i = 0; i < arr.size() - 1; ++i) { // Pętla po wszystkich elementach poza ostatnim
                if (arr[i] > arr[i + 1]) { // Jeśli znaleziono element w złej kolejności
                    std::cout << "Bład w sortowaniu: arr[" << i << "] = " << arr[i] << " > arr[" << i + 1 << "] = " << arr[i + 1] << std::endl;
                    return; // Przerwanie funkcji, gdy znaleziono błąd
                }
            }
            std::cout << "Tablica posortowana poprawnie" << std::endl;
        } else {
            std::cout << "Tablica ma mniej niż dwa elementy, więc jest automatycznie posortowana" << std::endl;
        }
    }
    GapSequence sequence;

    // Constructor to select the gap sequence
    ShellSort(GapSequence seq = GapSequence::Shell) : sequence(seq) {}

    void sort(std::vector<T>& arr) override {
        auto start = std::chrono::high_resolution_clock::now();
        int n = arr.size();
        std::vector<int> gaps = getGaps(n);

        for (int gap : gaps) {
            for (int i = gap; i < n; i++) {
                T temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = end - start;
        printResults(arr, elapsed);
    }
private:
    std::string identifyType(std::vector<T> &arr){
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
//    void saveResultsToFile(size_t size, const std::string& typeName, double elapsedTime) {
//        std::ofstream file("sort_results_shellSort.csv", std::ios::app); // Otwiera plik do dopisywania
//        if (file.is_open()) {
//            file << typeName << "," << size << "," << elapsedTime << "\n";
//            file.close();
//        } else {
//            std::cerr << "Nie udało się otworzyć pliku do zapisu wyników.\n";
//        }
//    }
    // Generate the gap sequence based on the selected type
    std::vector<int> getGaps(int n) {
        std::vector<int> gaps;
        if (sequence == GapSequence::Shell) {
            for (int gap = n / 2; gap > 0; gap /= 2) {
                gaps.push_back(gap);
            }
        } else if (sequence == GapSequence::Sedgewick) {
            int k = 0;
            int nextGap;
            while ((nextGap = sedgewickGap(k)) < n) {
                gaps.push_back(nextGap);
                k++;
            }
        }
        std::reverse(gaps.begin(), gaps.end());
        return gaps;
    }

    // Calculate the Sedgewick gap for the given index
    int sedgewickGap(int k) {
        if (k % 2 == 0) {
            return 9 * (1 << k) - 9 * (1 << (k / 2)) + 1;
        } else {
            return 8 * (1 << k) - 6 * (1 << ((k + 1) / 2)) + 1;
        }
    }

    // Print the results and save to a file
    void printResults(const std::vector<T>& arr, std::chrono::duration<double, std::milli> elapsed) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
        std::cout<<"Sortowanie tablicy o rozmiarze "<<arr.size()<<" i typie "<<std::endl;
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        std::cout << "Czas sortowania: " << elapsed.count() << " ms\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        saveResultsToFile(arr.size(), elapsed.count());
    }

    // Save sorting results to a file
    void saveResultsToFile(size_t size, double elapsedTime) {
        std::ofstream file("sort_results_shellSort.csv", std::ios::app);
        if (file.is_open()) {
            file << "Shell" << "," << size << "," << elapsedTime << "\n";
            file.close();
        } else {
            std::cerr << "Blad zapisania danych z sortowania ShellSort.\n";
        }
    }
};

#endif // SHELLSORT_H
