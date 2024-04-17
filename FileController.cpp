#include "FileController.h"
#include <fstream>
#include <iostream>
std::vector<int> FileController::readSizesDataFromFile() {
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
        FileController::readSizesDataFromFile();
    }
    return values;
}
template<typename T>
void FileController::saveSortedArray(const std::vector<T>& arr, const std::string& fileName, const std::string& arrayType){
    std::ifstream fileStream(fileName);
    if (fileStream.is_open()){
        fileStream << arr.size() << ", " << arrayType << std::endl;
        for (const auto &item: arr){
            fileStream << item << " ";
        }
        fileStream.close();
    }
}
