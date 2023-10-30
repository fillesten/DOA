//
// Created by margi on 2023-10-05.
//

#include <iostream>
#include "HashTable.h"

HashNode::HashNode(int value) :
    value(value), next(nullptr) { }

int HashTable::Hash(int key) const {
    return key % size;
}

HashTable::HashTable(std::vector<int> primeVec, int reservedSize ) : size(reservedSize) {
    hashtable.resize(size);
    for (int prime : primeVec ) {
        Insert(prime);
    }
}

void HashTable::Insert(int data) {
    int hash_value = Hash(data);
    HashNode* new_node = new HashNode(data);
    new_node->next = std::move(hashtable[hash_value]);
    hashtable[hash_value] = std::move(new_node);
}

//hittar en bucket å sen kollar varje värde, om inte hittar gå djupare i bucketen.
//ex med primes till 30; bucket 7 håller value = 17 och value = 7
int HashTable::Search(int targetData) {
    int hashValue = Hash(targetData);
    HashNode* current = hashtable[hashValue];

    while (current != nullptr) {
        if (current->value == targetData) {
            return current->value;
        }
        current = current->next;
    }
    return false; //false defaults to 0
}




