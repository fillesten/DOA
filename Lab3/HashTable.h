//
// Created by margi on 2023-10-05.
//

#ifndef LABORATION_3_HASHTABLE_H
#define LABORATION_3_HASHTABLE_H

#include <vector>


struct HashNode{
    int value;
    HashNode* next;
    HashNode(int value);
};



class HashTable {
private:
    int size;
    std::vector<HashNode*> hashtable;

    int Hash(int key) const;

public:

    HashTable(std::vector<int> primeVec, int reservedSize);

        // Lägg till ett element i hashtabellen.
    void Insert(int data);

    int Search(int targetData) const;
};



#endif //LABORATION_3_HASHTABLE_H
