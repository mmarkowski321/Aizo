#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include <vector>

class FileController {
public:
    static std::vector<int> readSizesDataFromFile();

    template<typename T>
    static void saveSortedArray(const std::vector<T>& arr, const std::string& fileName, const std::string& arrayType);
};

#endif // FILEREADER_H

