//
// Created by margi on 2023-10-06.
//

#ifndef LABORATION_3_TIMEMEASURE_H
#define LABORATION_3_TIMEMEASURE_H

#include <string>
#include <iostream>
#include <vector>

#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "FileManager.h"
#include "Generation.h"
#include "HashTable.h"
#include "LinearSearch.h"



void TimeAllAlgorithms(std::vector<int>& vec, std::vector<std::string> fileNameList);

void TimeCalculation(void (*searchFunk)(std::vector<int>&searchVec), std::vector<int> &vec, std::string fileName);

double SortingTime(void (*searcFunk)(std::vector<int>&searchVec), std::vector<int> vec);


#endif //LABORATION_3_TIMEMEASURE_H
