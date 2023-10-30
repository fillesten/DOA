//
// Created by margi on 2023-10-04.
//

#include "BinarySearch.h"

int BinarySearch(std::vector<int> &primeVec, int targetInt) {
    int low = 0;
    int high = primeVec.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if targetInt is present at mid
        if (primeVec[mid] == targetInt)
            return mid;

        // If targetInt greater, ignore left half
        if (primeVec[mid] < targetInt)
            low = mid + 1;

            // If targetInt is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
