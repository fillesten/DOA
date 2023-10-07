//
// Created by margi on 2023-10-04.
//

#include "LinearSearch.h"

int LinearSearch(std::vector<int> &vec, int targetInt) {
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == targetInt)
            return i;
    return -1;
}