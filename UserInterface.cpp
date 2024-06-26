#include "UserInterface.h"
#include <iostream>

using namespace std;

void UserInterface::printAllOptions() {
    cout<<"Wybierz jedna z opcji"<<endl;
    cout<<"Wstepna weryfikacja metod sortowania - #1"<<endl;
    cout<<"Odczytywanie rozmiarow tablic z pliku i zapelnianie ich randomowymi wartosciami - #2"<<endl;
    cout<<"Wpisanie wielkosci tablicy i wygenerowanie o tym rozmiarze tablicy int char i double - #3"<<endl;
}

int UserInterface::getUserInput() {
    int choice;
    std::cin >> choice;
    return choice;
}
void UserInterface::printAllSortingMethods(){
    std::cout << "Wybierz algorytm sortowania:\n";
    std::cout << "1. Insertion Sort\n";
    std::cout << "2. Quick Sort\n";
    std::cout << "3. Heap Sort\n";
    std::cout << "4. Shell Sort\n";
}
void UserInterface::printAllKindOfTables(){
    std::cout<<"Posortowana randomowo - 1"<<std::endl;
    std::cout<<"Posortowana rosnaco - 2"<<std::endl;
    std::cout<<"Posortowana malejaco - 3"<<std::endl;
    std::cout<<"Posortowana w 33% - 4"<<std::endl;
    std::cout<<"Posortowana w 66% - 5"<<std::endl;
}
void UserInterface::printTypeOfTable(){
    std::cout<<"Wyjscie - 0"<<std::endl;
    std::cout<<"Generuj nowa tablice - 1"<<std::endl;
    std::cout<<"Wykorzystaj stara tablice - 2"<<std::endl;
}