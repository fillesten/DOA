//
// Created by margi on 2023-09-06.
//

#pragma once
#ifndef LABORATION_2_LISTGENERATION_H
#define LABORATION_2_LISTGENERATION_H
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<random>

/// \param storlek size of the vector
/// \return a monotonously falling vector
std::vector<int> FallingVec(int storlek);

/// \param storlek size of vector
/// \return a vector of random integers ranging from 1 to 10 000
std::vector<int> RandomVec(int storlek);

/// \param storlek size of the vector
/// \return a monotonously rising vector
std::vector<int> RisingVec(int storlek);

/// \param storlek size of vector
/// \return a vector containing the int 13
std::vector<int> SameVec(int storlek);

#endif //LABORATION_2_LISTGENERATION_H
