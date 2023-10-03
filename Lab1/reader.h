#pragma once 
#ifndef READER_H
#define READER_H
#include<istream>
#include<map>
#include<vector>
#include <iostream>
#include <queue>


using node_id_t = int;
using weight_t = double;

using nodepairs = std::pair<node_id_t, node_id_t>;

using lineweight = std::pair <weight_t, node_id_t>;
using prio_queue = std::priority_queue<lineweight, std::vector<lineweight>, std::greater<lineweight>>;

using mway = std::map<node_id_t, lineweight>;

//adj.first.[index]
using meta_t = std::map<node_id_t, std::string>;
    
struct edge {
    node_id_t n1;
    node_id_t n2;
    weight_t weight;
    std::string description;
};


//adj.second 
using edge_list_t = std::vector<edge>;
using adjacency_list_t = std::pair<meta_t, edge_list_t>;
adjacency_list_t parse_file(std::string filename);



#endif