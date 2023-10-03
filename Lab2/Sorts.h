//
// Created by margi on 2023-09-06.
//
#pragma once
#ifndef LABORATION_2_SORTS_H
#define LABORATION_2_SORTS_H
#include <istream>
#include <vector>
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cmath>
#include <fstream>

///
/// \param vec vector to do the sort on
void InsertionSort(std::vector<int> &vec);

///
/// \param vec vector to do the sort on
void SelectionSort(std::vector<int> &vec);

///
/// \param vec vector to do the sort on
/// \param low starting index
/// \param high ending index
/// \param rightSidePivot bool on whether to USE the RightSidedPivot, true for yes
/// \returns index of partition element
int Partition(std::vector<int> &vec, int low, int high, bool rightSidePivot);

/// \param vec vector to do the sort on
/// \param low starting index
/// \param high ending index
/// \param rightSidePivot bool on whether to USE the RightSidedPivot, true for yes
void QuickSort(std::vector<int> &vec, int low, int high, bool rightSidePivot);

/// \param vec vector to do the sort on
/// \param low starting index
/// \param high ending index
/// \returns median of 3 values
int MedianPivot(std::vector<int> &vec, int low, int high);

/// prints a vector. used for debugging
/// \param vec vector to print
/// \param vecName name of vector for easy read in terminal
void PrintVector(const std::vector<int>& vec, const std::string& vecName);
#endif //LABORATION_2_SORTS_H
