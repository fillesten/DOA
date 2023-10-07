//
// Created by margi on 2023-10-04.
//

#include "BinarySearch.h"

int BinarySearch(std::vector<int> &vec, int targetInt) {
    int low = 0;
    int high = vec.size()-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if targetInt is present at mid
        if (vec[mid] == targetInt)
            return mid;

        // If targetInt greater, ignore left half
        if (vec[mid] < targetInt)
            low = mid + 1;

            // If targetInt is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
