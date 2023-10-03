//
// Created by fist2000 on 2023-09-06.
//

#include "Sorts.h"


void SelectionSort(std::vector<int> &vec) {
    int min, check, index;
    for (min = 0; min < vec.size()-1; min++) {
        index = min;
        for (check = min+1; check < vec.size() ; check++) {
            if (vec[check] < vec[index]) {
                index = check; }
        }
        std::swap(vec[index], vec[min]);
    }
}

void InsertionSort(std::vector<int> &vec) {
    int insertionIndex, currentElement, comparisonIndex;
    for (insertionIndex = 1; insertionIndex < vec.size(); insertionIndex++) {
        currentElement = vec[insertionIndex];
        comparisonIndex = insertionIndex - 1;
        while (comparisonIndex >= 0 && vec[comparisonIndex] > currentElement) {
            vec[comparisonIndex + 1] = vec[comparisonIndex];
            comparisonIndex--;
        }

        vec[comparisonIndex + 1] = currentElement;
    }
}

int MedianPivot(std::vector<int> &vec, int low, int high) {
    int mid = (low + high) / 2;
    if (vec[mid] < vec[low]) {
        std::swap(vec[low], vec[mid]);
    }
    if (vec[high] < vec[low]) {
        std::swap(vec[low], vec[high]);
    }
    if (vec[mid] < vec[high]) {
        std::swap(vec[mid], vec[high]);
    }
    //median is at vec[high]
    return vec[high];
}

int Partition(std::vector<int> &vec, int low, int high, bool rightSidePivot ) {
    int pivot;
    if (rightSidePivot) { pivot = vec[high]; }
    else {
        pivot = MedianPivot(vec, low, high);
    }

    int lowIndex = (low - 1);
    for (int element = low; element <= high - 1 ; element++) {
        if ((vec[element] < pivot)){
            lowIndex++;
            std::swap(vec[lowIndex], vec[element]);
        }
    }
    std::swap(vec[lowIndex + 1], vec[high]);
    return (lowIndex + 1);
}

void QuickSort(std::vector<int> &vec, int low, int high, bool rightSidePivot) {
    if (low < high) {
        //split is the partitioning index
        int split = Partition(vec, low, high, rightSidePivot);
        QuickSort(vec, low, split - 1, rightSidePivot);
        QuickSort(vec, split + 1, high, rightSidePivot);
    }
}

void PrintVector(const std::vector<int>& vec, const std::string& vecName) {
    std::cout<<"PRINTING LIST "<<vecName<<": ";
    for (int i : vec) {
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}


