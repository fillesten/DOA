#pragma once 
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<istream>
#include<map>
#include<vector>
#include"reader.h"
#include <iostream>
#include <stack>
#include <queue>
#include <map>



const double NOT_CONNECTED = -1;

std::vector < std::vector<double>> createMatrix(adjacency_list_t& lista, edge_list_t& paraKanter);

void DFS(std::vector <std::vector<double>>& matris, double startnod);
void BFS(std::vector <std::vector<double>>& matris, double startnod);
void dijkstra(std::vector <std::vector<double>>& matris, double startnod, double destination);



std::ostream& operator<<(std::ostream& os, adjacency_list_t& lista);
std::ostream& operator<<(std::ostream& os, std::vector <std::vector<double>>& matris);
void printMatrix(std::vector<std::vector<double>> matris);



bool neighCheck(std::vector <std::vector<double>>& matris);
double validNeighs(std::vector <std::vector<double>>& matris);

void testFunk(std::vector <std::vector<double>>& matris);

#endif