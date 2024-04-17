#include <iostream>
#include "AlgorithmTests.h"
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "UserInterface.h"
#include "FileController.h"
#include "RandomArrayGenerator.h"
#include "SortingMethods.h"

using namespace std;

int main() {
    std::cout << "Program sie uruchomil" << std::endl;
    srand(static_cast<unsigned int>(time(nullptr)));
    int choice;
    int exit = 0;

    do {
        UserInterface::printAllOptions();
        choice = UserInterface::getUserInput();
        switch (choice) {
            case 1:
                displayAlgorithmTest();
                break;
            case 2: {
                std::vector<int> sizes = FileController::readSizesDataFromFile();
                using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;
                ArrayTriple arrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                UserInterface::printAllSortingMethods();
                int choosenSortingMethod = UserInterface::getUserInput();
                SortingMethods::sortingMethod(std::get<0>(arrays), choosenSortingMethod);
                SortingMethods::sortingMethod(std::get<1>(arrays), choosenSortingMethod);
                SortingMethods::sortingMethod(std::get<2>(arrays), choosenSortingMethod);
                break;
            }
            case 3:
                cout<<"Wpisz rozmiar tablicy "<<endl;
                int size = UserInterface::getUserInput();
                std::vector<int> sizes;
                sizes.push_back(size);
                using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;
                ArrayTriple  arrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                UserInterface::printAllSortingMethods();
                int choosenSortingMethod = UserInterface::getUserInput();
                SortingMethods::sortingMethod(std::get<0>(arrays), choosenSortingMethod);
                SortingMethods::sortingMethod(std::get<1>(arrays), choosenSortingMethod);
                SortingMethods::sortingMethod(std::get<2>(arrays), choosenSortingMethod);
        }
    } while (choice != exit);

    return 0;
}
