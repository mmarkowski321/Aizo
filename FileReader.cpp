#include "FileReader.h"
#include <fstream>
#include <iostream>
std::vector<int> FileReader::readDataFromFile() {
    std::cout<<"Podaj sciezke do pliku"<<std::endl;
    std::string filePath;
    std::cin>>filePath;
    std::ifstream fileStream(filePath);
    std::vector<int> values;

    if (fileStream.is_open()) {
        int value;
        while (fileStream >> value) {
            std::cout<<"Odczytano wartosc "<< value<<std::endl;
            values.push_back(value);
        }
        fileStream.close();
    }else{
        std::cout<<"Nie mozna otworzyc pliku podaj sciezke jeszcze raz"<<std::endl;
        FileReader::readDataFromFile();
    }
    return values;
}
