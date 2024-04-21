#include <iostream>
#include "AlgorithmTests.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "UserInterface.h"
#include "FileController.h"
#include "RandomArrayGenerator.h"
#include "SortingMethods.h"

using namespace std;
using ArrayTriple = std::tuple<std::vector<std::vector<int>>, std::vector<std::vector<double>>, std::vector<std::vector<char>>>;
ArrayTriple lastGeneratedArrays;
int choice;
int main() {
    std::cout << "Program sie uruchomil" << std::endl;
    srand(static_cast<unsigned int>(time(nullptr)));

    const int exit = 0;
    int choiceOfUsingTable;
    do {
        if (get<0>(lastGeneratedArrays).empty()){
            cout<<"Brak danych. Najpierw wygeneruj tablice";
            UserInterface::printAllOptions();
            choice = UserInterface::getUserInput();
            switch (choice) {
                case 1:
                    displayAlgorithmTest();
                    break;
                case 2: {
                    std::vector<int> sizes = FileController::readSizesDataFromFile();
                    lastGeneratedArrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
                    break;
                }
                case 3:
                    cout<<"Wpisz rozmiar tablicy "<<endl;
                    int size = UserInterface::getUserInput();
                    std::vector<int> sizes;
                    sizes.push_back(size);
                    lastGeneratedArrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
            }
        }else{
            UserInterface::printTypeOfTable();
            choiceOfUsingTable = UserInterface::getUserInput();
            if (choiceOfUsingTable == 1){
                if (choice == 2){
                    std::vector<int> sizes = FileController::readSizesDataFromFile();
                    lastGeneratedArrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
                }
                else if(choice == 3){
                    cout<<"Wpisz rozmiar tablicy "<<endl;
                    int size = UserInterface::getUserInput();
                    std::vector<int> sizes;
                    sizes.push_back(size);
                    lastGeneratedArrays = RandomArrayGenerator::createTripleArrayWithDifTypes(sizes);
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
                }
            }else if (choiceOfUsingTable == 2){
                if (choice == 2){
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
                }
                else if(choice == 3){
                    UserInterface::printAllSortingMethods();
                    int choosenSortingMethod = UserInterface::getUserInput();
                    ArrayTriple currentArrays = make_tuple(
                            std::vector<std::vector<int>>(get<0>(lastGeneratedArrays)),
                            std::vector<std::vector<double>>(get<1>(lastGeneratedArrays)),
                            std::vector<std::vector<char>>(get<2>(lastGeneratedArrays))
                    );
                    SortingMethods::sortingMethod(std::get<0>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<1>(currentArrays), choosenSortingMethod);
                    SortingMethods::sortingMethod(std::get<2>(currentArrays), choosenSortingMethod);
                }
            }else{
                cout<<"Do widzenia"<< endl;
                choice = 0;
            }
        }
    } while (choice != exit);

    return 0;
}
