#include <iostream>
#include <chrono>
#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "FileManager.h"
#include "Generation.h"
#include "HashTable.h"
#include "LinearSearch.h"
#include "TimeMeasure.h"




int main() {
    std::cout << std::setiosflags(std::ios_base::fixed);;

    int start = 10000;
    int increment = 10000;
    int end = 100000;

    std::vector<std::vector<int>> primeVectors;
    for (int vectorSize = start; vectorSize <= end; vectorSize+= increment) {
        std::vector<int> primeVec = GeneratePrimes(vectorSize);
        primeVectors.push_back(primeVec);
        std::cout<<"done"<<std::endl;
    }

    std::vector<std::string> fileNamesVec = { "BinarySearch.txt", "BinarySearchTree.txt", "HashTable.txt", "LinearSearch.txt" };
    ClearFiles(fileNamesVec);


    auto binarySearch = [](std::vector<int> &primeVec, int targetInt)  { BinarySearch(primeVec, targetInt); };
    auto bstSearch = [](std::vector<int> &primeVec, int targetInt) { BSTSearch(BuildBalancedBST(primeVec, 0, primeVec.size() - 1), targetInt); };
    auto hashtable  = [](std::vector<int> &primeVec , int targetInt) { HashTable hashTable(primeVec, primeVec.size()); hashTable.Search(targetInt); };
    auto linearSearch = [](std::vector<int> &primeVec, int targetInt) { LinearSearch(primeVec, targetInt); };



    for (auto primeVector : primeVectors) {

//      Binary Search
        TimeCalculation(binarySearch, primeVector, fileNamesVec[0]);

//      BST Search
        TimeCalculation(bstSearch, primeVector, fileNamesVec[1]);

//      Hash Search
        TimeCalculation(hashtable, primeVector, fileNamesVec[2]);

//      Linear Search
        TimeCalculation(linearSearch, primeVector, fileNamesVec[3]);
        std::cout<<std::endl;

    }

    int debuggstop = 1;
    return 0;
}
