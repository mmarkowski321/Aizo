#include "AlgorithmTests.h"
#include "sortingAlgorithm/Sort.h"
#include "sortingAlgorithm/InsertionSort.h"
#include "sortingAlgorithm/QuickSort.h"
#include "sortingAlgorithm/HeapSort.h"
#include "sortingAlgorithm/ShellSort.h"
#include <iostream>
#include <memory>
#include <cstdlib>
#include <random>
#include <ctime>
#include <type_traits>

//generowanie losowych danych o typach double int char
template<typename T>
std::vector<T> generateRandomData(int size, T min, T max) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::vector<T> randomData;

    if constexpr (std::is_integral<T>::value && !std::is_same<T, char>::value && !std::is_same<T, unsigned char>::value && !std::is_same<T, signed char>::value) {
        std::uniform_int_distribution<T> distribution(min, max);
        for (int i = 0; i < size; ++i) {
            randomData.push_back(distribution(generator));
        }
    } else if constexpr (std::is_floating_point<T>::value) {
        std::uniform_real_distribution<T> distribution(min, max);
        for (int i = 0; i < size; ++i) {
            randomData.push_back(distribution(generator));
        }
    } else if constexpr (std::is_same<T, char>::value || std::is_same<T, unsigned char>::value || std::is_same<T, signed char>::value) {
        std::uniform_int_distribution<int> distribution(static_cast<int>(min), static_cast<int>(max));
        for (int i = 0; i < size; ++i) {
            randomData.push_back(static_cast<T>(distribution(generator)));
        }
    }
    return randomData;
}
//wyswietlanie wszystkich danych roznych typow przed i po sortowaniu
void displayVector(const std::vector<int>& vecInt,const std::vector<double>& vecDouble,const std::vector<char>& vecChar,std::string text) {
    std::cout <<text <<" sortowaniem (int): ";
    std::cout<<std::endl;
    for (const auto& elem : vecInt) {
        std::cout << elem << " ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<text << " sortowaniem (char): ";
    std::cout<<std::endl;
    for (const auto& elem : vecChar) {
        std::cout << elem << " ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<text << " sortowaniem (double): ";
    std::cout<<std::endl;
    for (const auto& elem : vecDouble) {
        std::cout << elem << " ";
    }
    std::cout<<std::endl<<std::endl;

}
//funkcja testowa gdzie mozna zobaczyc "golym okiem" jak działają algorytmy
void displayAlgorithmTest(){
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Inicjalizacja generatora liczb losowych

    int choice;

    do {
        std::cout << "Wybierz algorytm sortowania:\n";
        std::cout << "1. Insertion Sort\n";
        std::cout << "2. Quick Sort\n";
        std::cout << "3. Heap Sort\n";
        std::cout << "4. Shell Sort\n";
        std::cout << "0. Wyjscie\n";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::vector<int> tableTestInt1 = generateRandomData(30,0,100);
                std::vector<double> tableTestDouble1 = generateRandomData(30,0.0,100.0);
                std::vector<char> tableTestChar1 = generateRandomData(30,'a','z');

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Przed");

                std::unique_ptr<Sort<int>> sorterInt = std::make_unique<InsertionSort<int>>();
                std::unique_ptr<Sort<char>> sorterChar = std::make_unique<InsertionSort<char>>();
                std::unique_ptr<Sort<double>> sorterDouble = std::make_unique<InsertionSort<double>>();

                sorterInt->sort(tableTestInt1);
                sorterChar->sort(tableTestChar1);
                sorterDouble->sort(tableTestDouble1);

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Po");

                break;
            }
            case 2: {
                std::vector<int> tableTestInt1 = generateRandomData(30,0,10000);
                std::vector<double> tableTestDouble1 = generateRandomData(30,0.0,100.0);
                std::vector<char> tableTestChar1 = generateRandomData(30,'a','z');

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Przed");

                int choose;
                std::cout << "Wybierz numer:" << std::endl;
                std::cout << "Pivot od przodu #1" << std::endl;
                std::cout << "Pivot od tyłu #2" << std::endl;
                std::cout << "Pivot od środka #3" << std::endl;
                std::cout << "Pivot losowy #4" << std::endl;
                std::cout << "Wyjście #0" << std::endl;
                std::cin>>choose;

                std::unique_ptr<Sort<int>> sorterInt;
                std::unique_ptr<Sort<double>> sorterDouble;
                std::unique_ptr<Sort<char>> sorterChar;
                switch (choose) {
                    case 1:
                        sorterInt = std::make_unique<QuickSort<int>>(QuickSort<int>::FIRST);
                        sorterDouble = std::make_unique<QuickSort<double>>(QuickSort<double>::FIRST);
                        sorterChar = std::make_unique<QuickSort<char>>(QuickSort<char>::FIRST);
                        break;
                    case 2:
                        sorterInt = std::make_unique<QuickSort<int>>(QuickSort<int>::LAST);
                        sorterDouble = std::make_unique<QuickSort<double>>(QuickSort<double>::LAST);
                        sorterChar = std::make_unique<QuickSort<char>>(QuickSort<char>::LAST);
                        break;
                    case 3:
                        sorterInt = std::make_unique<QuickSort<int>>(QuickSort<int>::MIDDLE);
                        sorterDouble = std::make_unique<QuickSort<double>>(QuickSort<double>::MIDDLE);
                        sorterChar = std::make_unique<QuickSort<char>>(QuickSort<char>::MIDDLE);
                        break;
                    case 4:
                        sorterInt = std::make_unique<QuickSort<int>>(QuickSort<int>::RANDOM);
                        sorterDouble = std::make_unique<QuickSort<double>>(QuickSort<double>::RANDOM);
                        sorterChar = std::make_unique<QuickSort<char>>(QuickSort<char>::RANDOM);
                    default:
                        std::cout << "Nie ma takiej opcji, spróbuj jeszcze raz" << std::endl;
                }
                sorterInt->sort(tableTestInt1);
                sorterDouble->sort(tableTestDouble1);
                sorterChar->sort(tableTestChar1);

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Po");
                break;
            }
            case 3: {
                std::vector<int> tableTestInt1 = generateRandomData(30,0,10000);
                std::vector<double> tableTestDouble1 = generateRandomData(30,0.0,10000.0);
                std::vector<char> tableTestChar1 = generateRandomData(30,'a','z');

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Przed");

                std::unique_ptr<Sort<int>> sorterInt = std::make_unique<HeapSort<int>>();
                std::unique_ptr<Sort<char>> sorterChar = std::make_unique<HeapSort<char>>();
                std::unique_ptr<Sort<double>> sorterDouble = std::make_unique<HeapSort<double>>();

                sorterInt->sort(tableTestInt1);
                sorterChar->sort(tableTestChar1);
                sorterDouble->sort(tableTestDouble1);

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Po");

                break;
            }
            case 4: {
                std::vector<int> tableTestInt1 = generateRandomData(30,0,10000);
                std::vector<double> tableTestDouble1 = generateRandomData(30,0.0,10000.0);
                std::vector<char> tableTestChar1 = generateRandomData(30,'a','z');

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Przed");

                std::unique_ptr<Sort<int>> sorterInt = std::make_unique<ShellSort<int>>();
                std::unique_ptr<Sort<char>> sorterChar = std::make_unique<ShellSort<char>>();
                std::unique_ptr<Sort<double>> sorterDouble = std::make_unique<ShellSort<double>>();

                sorterInt->sort(tableTestInt1);
                sorterChar->sort(tableTestChar1);
                sorterDouble->sort(tableTestDouble1);

                displayVector(tableTestInt1,tableTestDouble1,tableTestChar1,"Po");

                break;
            }
            case 0:
                break;
            default:
                std::cout << "Nieprawidłowy wybór, spróbuj ponownie.\n";
                continue;
        }

    } while (choice != 0);
}