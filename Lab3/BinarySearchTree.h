//
// Created by margi on 2023-10-04.
//

#ifndef LABORATION_3_BINARYSEARCHTREE_H
#define LABORATION_3_BINARYSEARCHTREE_H

#include <vector>

/// Must assign all variables
/// else segmentation fault
/// \param value of the Node
struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int value);

};

Node* BuildBalancedBST(std::vector<int> &vec, int start, int end);

Node* BSTSearch(Node* nodePtr, int targetInt);

void Inorder(Node *root);

//Node* Insert(Node* nodePtr, int value);





#endif //LABORATION_3_BINARYSEARCHTREE_H
