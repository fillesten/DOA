//
// Created by margi on 2023-10-06.
//

#include <algorithm>
#include <functional>
#include <valarray>
#include <chrono>
#include "TimeMeasure.h"

void TimeAllAlgorithms(std::vector<int> &vec, std::vector<std::string> fileNameList) {

    //more experimenting with lambda functions and std::function:
    /*
    auto linearSearch = [](std::vector<int> &searchVec, int targetInt) { LinearSearch(searchVec, targetInt); };
    auto binarySearch = [](std::vector<int> &searchVec, int targetInt) { BinarySearch(searchVec, targetInt); };
    std::vector<void (*)(std::vector<int>&searchVec, int targetInt)> sortingMethods = { linearSearch, binarySearch };
     * OR
    std::function<int(std::vector<int> &searchVec, int targetInt)> linearSearch2 =
            [](std::vector<int> &searchVec, int targetInt) { return LinearSearch(searchVec, targetInt); };
    std::function<int(std::vector<int> &searchVec, int targetInt)> binarySearch2 =
            [](std::vector<int> &searchVec, int targetInt) { return BinarySearch(searchVec, targetInt); };
    auto sortMethods2 = { linearSearch2, binarySearch2};
     *
     * from my testing i need to explicitly call one of the two things, either the lambda functions or the
     * container for all the lambda functions
     * */


//    void (*linearSearch)(std::vector<int> &vec, int targetInt) = reinterpret_cast<void (*)(std::vector<int> &, int)>([](
//            std::vector<int> &vec) { LinearSearch(vec) });
//    std::function<int(std::vector<int> &searchVec, int targetInt)> linearSearch1 = [](std::vector<int> &searchVec, int targetInt) { return LinearSearch(searchVec, targetInt); };
//    std::function<int(std::vector<int> &searchVec, int targetInt)> binarySearch1 = [](std::vector<int> &searchVec, int targetInt) { return BinarySearch(searchVec, targetInt); };
//
//    auto BSTSearch = [&rootBST](Node* root, int targetInt  ) {
//        BSTSearch(rootBST, targetInt);
//    };

//    auto sortmeths = {linearSearch1, binarySearch1, BSTSearch};
//    std::vector<void (*)(std::vector<int>&searchVec, int targetInt)> sortingMethods =
//            { linearSearch, binarySearch };




}

void TimeCalculation(void (*searchFunk)(std::vector<int>&searchVec), std::vector<int> &vec, std::string fileName){

    //CHANGE BACK TO 5
    int samples = 10;
    double squareTime = 0;
    double totalTime = 0;
    double standardDeviation;
    double diffTime;
    double averageTime;


    for (int i = 0; i < samples; i++) {
//        PrintVector(vec, "Before the 'sortFunk'");
        auto currentTime = SortingTime(searchFunk, vec);
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

double SortingTime(void (*searchFunk)(std::vector<int>&searchVec), std::vector<int> vec){
    auto startTime = std::chrono::steady_clock::now();
    searchFunk(vec);
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> timeTaken = (endTime - startTime);
    return timeTaken.count();
}
