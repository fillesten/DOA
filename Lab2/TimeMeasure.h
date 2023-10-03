//
// Created by margi on 2023-09-06.
//

#ifndef LABORATION_2_TIMEMEASURE_H
#define LABORATION_2_TIMEMEASURE_H
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <chrono>
#include <fstream>
#include <cmath>
#include "ListGeneration.h"
#include "Sorts.h"


///
/// \param vec vector to sort
/// \param fileNameList a list of filenames
void TimeAllAlgorithms(std::vector<int>& vec, std::vector<std::string> fileNameList);


/// \param sortFunk a pointer to a sorting algorithm function. Can be regular function or lambda, this case its lambda.
/// \param vec vector to sort
/// \param fileName filename to print out result to
void TimeCalculation(void (*sortFunk)(std::vector<int>&sortVec), std::vector<int> &vec, std::string fileName);


/// \param sortFunk a pointer to a sorting algorithm function. Can be regular function or lambda, this case its lambda.
/// \param vec vector to sort
/// \returns time to sort in milliseconds
double SortingTime(void (*sortFunk)(std::vector<int>&sortVec), std::vector<int> vec);

#endif //LABORATION_2_TIMEMEASURE_H
