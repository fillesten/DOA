//
// Created by margi on 2023-10-06.
//

#ifndef LABORATION_3_TIMEMEASURE_H
#define LABORATION_3_TIMEMEASURE_H

#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

#include "BinarySearch.h"
#include "BinarySearchTree.h"
#include "FileManager.h"
#include "Generation.h"
#include "HashTable.h"
#include "LinearSearch.h"

void TimeCalculation(void (*searchFunk)(std::vector<int>&searchVec, int targetInt), std::vector<int> &vec, std::string fileName);

double SearchingTime(void (*searchFunk)(std::vector<int>&searchVec, int targetInt), std::vector<int> &vec, std::string searchMethod);

void LambdaExperimentation(std::vector<int>& vec, std::vector<std::string> fileNameList);

#endif //LABORATION_3_TIMEMEASURE_H
