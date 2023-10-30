//
// Created by margi on 2023-10-06.
//

#include <functional>
#include <valarray>
#include <chrono>
#include "TimeMeasure.h"


void TimeCalculation(void (*searchFunk)(std::vector<int>&searchVec, int targetInt), std::vector<int> &vec, std::string fileName){

    int samples = 50;
    double squareTime = 0;
    double totalTime = 0;
    double standardDeviation;
    double diffTime;
    double averageTime;
    std::string searchMethod = fileName.substr(0, fileName.size()-4);

    std::cout << searchMethod<< std::endl;
    for (int i = 0; i < samples; i++) {
        auto currentTime = SearchingTime(searchFunk, vec, searchMethod);
        totalTime += currentTime;
        squareTime += pow(currentTime, 2);
//        std::cout << "Sample " << i << ": " << currentTime << "ms" << std::endl;

    }
    averageTime = totalTime / samples;
    diffTime = pow(totalTime, 2) / samples;
    standardDeviation = sqrt((squareTime - diffTime) / (samples - 1));

    //output is N: vector size, T[ms] the average time in milliseconds, Stdev[ms]: standarddeviation in milliseconds   Samples: the amount of samples used for calculating the previous two
    std::string output = std::to_string(vec.size()) + "\t" + std::to_string(averageTime) + "\t" + std::to_string(standardDeviation) + "\t" + std::to_string(samples) + "\n";

//    std::cout << std::setiosflags(std::ios_base::fixed);
    std::cout<<averageTime <<std::endl;

    WriteFile(fileName, output);
}

double SearchingTime(void (*searchFunk)(std::vector<int>&searchVec, int targetInt), std::vector<int> &vec, std::string searchMethod){

    std::chrono::duration<double, std::milli> timeTaken(0);
    int targetInt = rand() % vec.size();


    if (searchMethod == "BinarySearchTree") {
        Node* root = BuildBalancedBST(vec, 0, vec.size() - 1);

        auto startTime = std::chrono::steady_clock::now();
        BSTSearch(root, vec[targetInt]);
        auto endTime = std::chrono::steady_clock::now();

        timeTaken += (endTime-startTime);
    }
    else if (searchMethod == "HashTable") {


        HashTable hashTable(vec, vec.size());


        auto startTime = std::chrono::steady_clock::now();
        hashTable.Search(vec[targetInt]);
        auto endTime = std::chrono::steady_clock::now();

        timeTaken += (endTime-startTime);
    }
    else {
        auto startTime = std::chrono::steady_clock::now();
        searchFunk(vec,  vec[targetInt]);
        auto endTime = std::chrono::steady_clock::now();
        timeTaken += (endTime-startTime);
    }
    return timeTaken.count();
}

//  <<<<<<<<<<<<<<<< LAMBDA EXPERIMENTING >>>>>>>>>>>>>>>>
void LambdaExperimentation(std::vector<int> &vec, std::vector<std::string> fileNameList) {

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

//    auto binarySearch = [](std::vector<int> &primeVec, int targetInt)  { BinarySearch(primeVec, targetInt); };
//    auto bstSearch = [](std::vector<int> &primeVec, int targetInt) { BSTSearch(BuildBalancedBST(primeVec, 0, primeVec.size() - 1), targetInt); };
//    auto hashtable  = [](std::vector<int> &primeVec , int targetInt) { HashTable hashTable(primeVec, primeVec.size()); hashTable.Search(targetInt); };
//    auto linearSearch = [](std::vector<int> &primeVec, int targetInt) { LinearSearch(primeVec, targetInt); };
//    std::vector<void (*)(std::vector<int>&searchVec, int targetInt)> sortingMethods = { binarySearch, bstSearch, hashtable, linearSearch };
//    std::vector<void (*)(std::vector<int>&searchVec, int targetInt)> sortingMethods = { binarySearch, bstSearch, hashtable, linearSearch };

}

