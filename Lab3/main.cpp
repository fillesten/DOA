#include <iostream>
#include <list>
#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "FileManager.h"
#include "Generation.h"
#include "HashTable.h"
#include "LinearSearch.h"
#include "TimeMeasure.h"


int main() {

    int start = 20000;
    int increment = 20000;
    int end = 200000;

    std::vector<std::string> fileNamesVec = { "BinarySearch.txt", "BinarySearchTree.txt", "HashTable.txt", "LinearSearch.txt" };
    ClearFiles(fileNamesVec);

    auto linearSearch = [](std::vector<int> &searchVec, int targetInt) { LinearSearch(searchVec, targetInt); };
    auto binarySearch = [](std::vector<int> &searchVec, int targetInt) { BinarySearch(searchVec, targetInt); };
    auto bstSearch = [](std::vector<int> &searchVec, int targetInt) { BSTSearch(BuildBalancedBST(searchVec, 0, searchVec.size() - 1), targetInt); };
    auto hashtable  = [](std::vector<int> &searchVec ,int targetInt) { HashTable hashTable(searchVec, searchVec.size()); hashTable.Search(targetInt); };



    std::vector<std::vector<int>> primeVectors;
    for (int vectorSize = start; vectorSize <= end; vectorSize+= increment) {
        std::vector<int> primeVec = GeneratePrimes(vectorSize);
        primeVectors.push_back(primeVec);
    }

//    for (std::vector<int> primeVec : primeVectors) {
//    }

    std::vector<int> primeVec = GeneratePrimes(30);
    std::cout<<primeVec.size()<<std::endl;
    for (int i: primeVec) { std::cout<<i<<", "; } std::cout<<std::endl;


//   HashTable hashTable(primeVec, primeVec.size());
//
//
//
    // BST
    for (std::vector<int> primeVec : primeVectors) {
        Node* rootBST = BuildBalancedBST(primeVec, 0, primeVec.size() - 1);
        TimeCalculation(bstSearch, fileNamesVec[1]);
        BSTSearch(rootBST, 7);
    }

//
//
//    int linearPos = LinearSearch(primeVec, 11);
//    std::cout<<"the prime "<<primeVec[linearPos] <<" is found at position "<<linearPos<< std::endl;
//
//
//    int binaryPos = BinarySearch(primeVec, 13);
//    std::cout<<"the prime "<<primeVec[binaryPos] <<" is found at position "<<binaryPos<< std::endl;
//

//    Node* root = BuildBalancedBST(primeVec, 0, primeVec.size() - 1);
//    Node* BSTPos = BSTSearch(root, 17);
//    std::cout<<"the prime "<<BSTPos->value<<" is found using " << std::endl;
//    std::cout<<"root contains "<<root->value<<std::endl;
//    Inorder(root); std::cout << std::endl;


    //hashtable size ska göras på en subset av alla primes.
    //så skapa en vector från primeVec och ta från
    // primeVec.begin() tills primVec.begin() + dataSerieSize
//    int reserved_size = primeVec.size()* 2; // Justera storleken efter behov.
//    HashTable hashtable(reserved_size, primeVec);



//    std::cout << "BSTSearch result: "<<std::endl;
//    std::cout << "Does 7 exist? ";
//    if (hashtable.Search(7)) std::cout << "true" << std::endl;
//    else std::cout<<"false"<<std::endl;
//
//    std::cout << "Does 8 exist? ";
//    if (hashtable.Search(8)) std::cout << "true" << std::endl;
//    else std::cout<<"false"<<std::endl;




    /*HashTable h(primeVec.size());

    int key[] = {231, 321, 212, 321, 433, 262};
    int data[] = {123, 432, 523, 43, 423, 111};

    for (int i = 0; i < primeVec.size(); i++)
        h.insertItem(key[i], data[i]);
    int debugstop;

    h.displayHash();
    h.deleteItem(12);
    h.displayHash();*/

















    int debuggstop = 1;

    return 0;
}
