#include "Sorts.h"
#include "TimeMeasure.h"
#include "ListGeneration.h"
#include "FileManager.h"
#include <iostream>
#include <algorithm>

int main() {
    std::cout << "Hello, World!" << std::endl;

    //alt skift insert for column selection.
    int start = 2000;
    int increment = 2000;
    int end = 20000;

    std::vector<std::string> fileNamesFalling = { "SelectionSortFalling.txt", "InsertionSortFalling.txt",  "QuickSortFalling.txt", "QuickSortMedian3Falling.txt", "stdSortFalling.txt"};
    std::vector<std::string> fileNamesRandom = { "SelectionSortRandom.txt", "InsertionSortRandom.txt",  "QuickSortRandom.txt", "QuickSortMedian3Random.txt", "stdSortRandom.txt"};
    std::vector<std::string> fileNamesRising = { "SelectionSortRising.txt", "InsertionSortRising.txt",  "QuickSortRising.txt", "QuickSortMedian3Rising.txt", "stdSortRising.txt"};
    std::vector<std::string> fileNamesSame = { "SelectionSortSame.txt", "InsertionSortSame.txt",  "QuickSortSame.txt", "QuickSortMedian3Same.txt", "stdSortSame.txt"};
    ClearFiles(fileNamesFalling);
    ClearFiles(fileNamesRandom);
    ClearFiles(fileNamesRising);
    ClearFiles(fileNamesSame);

    //containers for holding multiple vectors containing same data pattern
    std::vector<std::vector<int>> fallingVectors;
    std::vector<std::vector<int>> randomVectors;
    std::vector<std::vector<int>> risingVectors;
    std::vector<std::vector<int>> sameVectors;

    //creates vectors containing FALLING elements with size ranging from start to end and adds them into one vector.
    for (int vectorSize = start; vectorSize <= end; vectorSize += increment) { std::vector<int> fallingElements = FallingVec(vectorSize); fallingVectors.push_back(fallingElements); }
    //creates vectors containing RANDOM elements with size ranging from start to end and adds them into one vector.
    for (int vectorSize = start; vectorSize <= end; vectorSize += increment) { std::vector<int> randomElements = RandomVec(vectorSize); randomVectors.push_back(randomElements); }
    //creates vectors containing RISING elements with size ranging from start to end and adds them into one vector.
    for (int vectorSize = start; vectorSize <= end; vectorSize += increment) { std::vector<int> risingElements = RisingVec(vectorSize); risingVectors.push_back(risingElements); }
    //creates vectors containing THE SAME element with size ranging from start to end and adds them into one vector.
    for (int vectorSize = start; vectorSize <= end; vectorSize += increment) { std::vector<int> sameElements = SameVec(vectorSize); sameVectors.push_back(sameElements); }

    // ---------------------------------------------------------------------------------------------------------------------------------------------
    int i = 1;
    std::cout<<"Falling"<<std::endl;
    for (std::vector<int> &vec : fallingVectors) {
        TimeAllAlgorithms(vec, fileNamesFalling);
        std::cout<<"a vec is done "<<i++<<std::endl;
    }

    std::cout<<"Random"<<std::endl;
    for (std::vector<int> &vec : randomVectors) {
        TimeAllAlgorithms(vec, fileNamesRandom);
        std::cout<<"a vec is done "<<i++<<std::endl;
    }

    std::cout<<"Rising"<<std::endl;
    for (std::vector<int> &vec : risingVectors) {
        TimeAllAlgorithms(vec,fileNamesRising);
        std::cout<<"a vec is done "<<i++<<std::endl;
    }

    std::cout<<"Same"<<std::endl;
    for (std::vector<int> &vec : sameVectors) {
        TimeAllAlgorithms(vec, fileNamesSame);
        std::cout<<"a vec is done "<<i++<<std::endl;
    }

    int debuggstop = 0;
    return 0;
}
