//
// Created by margi on 2023-10-04.
//

#include <iostream>
#include "BinarySearchTree.h"


Node::Node(int value) :
    value(value), left(nullptr), right(nullptr) { }

Node *BuildBalancedBST(std::vector<int> &primeVec, int start, int end) {
    if (start > end) { return nullptr; }

    int mid = (start + end) / 2;
    Node* newNode = new Node(primeVec[mid]);

    newNode->left = BuildBalancedBST(primeVec, start, mid - 1);
    newNode->right = BuildBalancedBST(primeVec, mid + 1, end);

    return newNode;
}

Node* BSTSearch(Node* nodePtr, int targetInt) {
    while (nodePtr != nullptr && nodePtr->value != targetInt){
        if (targetInt < nodePtr->value){
            nodePtr = nodePtr->left;
        }
        else {
            nodePtr = nodePtr->right;
        }
    }
    return nodePtr;

    // Old search function, this one is recursive and thus increases the execution time and making the
    // search alg. slower.
    /*//    if (nodePtr == nullptr || nodePtr->value == targetInt)
//        return nodePtr;
//
//    // Key is greater than nodePtr's key
//    if (nodePtr->value < targetInt)
//        return BSTSearch(nodePtr->right, targetInt);
//
//    // Key is smaller than nodePtr's key
//    return BSTSearch(nodePtr->left, targetInt);*/
}

// Inorder Traversal; 2, 3, 5, 7, ... untill last prime
void Inorder(Node *root) {
    if (root != nullptr) {
        // Traverse left
        Inorder(root->left);
        // Traverse root
        std::cout << root->value << " -> ";
        // Traverse right
        Inorder(root->right);
    }
}










