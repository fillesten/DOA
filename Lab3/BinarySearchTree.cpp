//
// Created by margi on 2023-10-04.
//

#include <iostream>
#include "BinarySearchTree.h"


Node::Node(int value) :
    value(value), left(nullptr), right(nullptr) { }


Node *BuildBalancedBST(std::vector<int> &vec, int start, int end) {
    if (start > end) { return nullptr; }

    int mid = (start + end) / 2;
    Node* newNode = new Node(vec[mid]);

    newNode->left = BuildBalancedBST(vec, start, mid - 1);
    newNode->right = BuildBalancedBST(vec, mid + 1, end);

    return newNode;
}

Node* BSTSearch(Node* nodePtr, int targetInt) {
    // Base Cases: nodePtr is null or key is present at nodePtr
    if (nodePtr == nullptr
        || nodePtr->value == targetInt)
        return nodePtr;

    // Key is greater than nodePtr's key
    if (nodePtr->value < targetInt)
        return BSTSearch(nodePtr->right, targetInt);

    // Key is smaller than nodePtr's key
    return BSTSearch(nodePtr->left, targetInt);
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










