#ifndef SORT_H
#define SORT_H

#include <vector>

template<typename T>
class Sort {
public:
    virtual void sort(std::vector<T>& arr) = 0;
    virtual ~Sort() {}
};

#endif // SORT_H
