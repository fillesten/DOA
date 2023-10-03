//
// Created by margi on 2023-09-06.
//

#include <cassert>
#include "TimeMeasure.h"
#include "FileManager.h"

void TimeAllAlgorithms(std::vector<int>& vec, std::vector<std::string> fileNameList){

    //info/experiment regarding lambda functions
    /*
    auto assigns it into: void (*selectionsortfunktionsvariabel)(std::vector<int> &) = [](std::vector<int> &vec) { SelectionSort(vec); };
    and so forth, i was confused trying to understand what the auto
    keyword would assign the variable into.
    void (*selectionSort)(std::vector<int> &vec) = [](std::vector<int> &vec) { SelectionSort(vec); };
    is the same as
    auto selectionSort = [](std::vector<int> &vec) { SelectionSort(vec); };
    or
    std::function<void(std::vector<int>&)> selectionSort2 = [](std::vector<int>& vec) { SelectionSort(vec); };
    */
    //lambda functions for all the sorting methods
    auto selectionSort = [](std::vector<int> &sortVec) { SelectionSort(sortVec); };
    auto insertionSort = [](std::vector<int>& sortVec) { InsertionSort(sortVec); };
    auto quickSort = [](std::vector<int>& sortVec) { QuickSort(sortVec, 0, sortVec.size()-1, true); };
    auto quickSortMedian3 = [](std::vector<int>& sortVec) { QuickSort(sortVec, 0, sortVec.size() - 1, false); };
    auto stdSort = [](std::vector<int>& sortVec) { std::sort(sortVec.begin(), sortVec.end()); };

    std::vector<void (*)(std::vector<int>&)> sortingMethods = { selectionSort, insertionSort, quickSort, quickSortMedian3, stdSort };

    for (size_t i = 0; i < sortingMethods.size(); ++i) {
        TimeCalculation(sortingMethods[i], vec, fileNameList[i]);
    }
}



void TimeCalculation(void (*sortFunk)(std::vector<int>&sortVec), std::vector<int> &vec, std::string fileName) {

    //CHANGE BACK TO 5
    int samples = 5;
    double squareTime = 0;
    double totalTime = 0;
    double standardDeviation;
    double diffTime;
    double averageTime;


    for (int i = 0; i < samples; i++) {
//        PrintVector(vec, "Before the 'sortFunk'");
        auto currentTime = SortingTime(sortFunk, vec);
//        PrintVector(vec, "After the 'sortFunk'");
//        std::cout<<std::endl;
//        std::cout<<std::endl;
        totalTime += currentTime;
        squareTime += pow(currentTime, 2);
    }
    averageTime = totalTime / samples;

    diffTime = pow(totalTime, 2) / samples;
    standardDeviation = sqrt((squareTime - diffTime) / (samples - 1));


    //output is N: vector size, T[ms] the average time in milliseconds, Stdev[ms]: standarddeviation in milliseconds   Samples: the amount of samples used for calculating the previous two
    std::string output = std::to_string(vec.size()) + "\t" + std::to_string(averageTime) + "\t" + std::to_string(standardDeviation) + "\t" + std::to_string(samples) + "\n";
    std::cout<<averageTime<<std::endl;
    WriteFile(fileName, output);

}

double SortingTime(void (*sortFunk)(std::vector<int>&sortVec), std::vector<int> vec){

    auto startTime = std::chrono::steady_clock::now();
    sortFunk(vec);
    auto endTime = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> timeTaken = (endTime - startTime);
    return timeTaken.count();

}





