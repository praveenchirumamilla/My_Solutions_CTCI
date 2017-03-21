// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include "vector.h"


#ifndef _hash_set
#define _hash_set

struct hashNode{
    int data;
    hashNode* next;

    hashNode(int data, hashNode* next=NULL){
        this->data = data;
        this->next = next;
    }
};

class hashSet{
    public:
    hashSet();
    ~hashSet();

    void add(int data);
    void remove(int data);
    void clear();
    bool contains(int data);
    int mySize() const;
    bool isEmpty() const;
    void rehash();

    private:
    hashNode** hashTable;
    int capacity;
    int size;
    int hash(int data);
};

#endif

