// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include <cmath>
#include "console.h"


#include "hashSet.h"

hashSet::hashSet(){
    this->size = 0;
    this->capacity = 10;
    this->hashTable = new hashNode*[capacity]();
}

int hashSet::hash(int data){
    return abs(data)%capacity;
}

void hashSet::add(int data){
    int location = this->hash(data);
    if(hashTable[location] == NULL){
        hashTable[location] = new hashNode(data);
    }else{
        hashTable[location] = new hashNode(data, hashTable[location]);
    }
    this->size++;
}

bool hashSet::contains(int data) {
    int location = hash(data);
    hashNode* current = hashTable[location];
    while(current != NULL){
        if(current->data == data){
            return true;
        }
        current = current->next;
    }
    return false;
}

void hashSet::remove(int data){
    int location = hash(data);
    hashNode* trash = hashTable[location];
    if(hashTable[location]->data == data){
        hashTable[location] = hashTable[location]->next;
        size--;
        delete trash;
    }else{
        while(trash->next->data != data){
            trash->next = trash->next->next;
        }
        trash->next = trash->next->next;
    }
}

int hashSet::mySize() const{
    return size;
}

bool hashSet::isEmpty() const{
    return size;
}

void hashSet::rehash(){
    hashNode** oldHashTable = hashTable;
    int oldCap = capacity;
    if(size/capacity > 0.75){
        capacity *= 2;
        hashTable = new hashNode*[capacity]();
        for(int i = 0; i < oldCap; i++){
            hashNode* current = oldHashTable[i];
            while(current != NULL){
                add(current->data);
                current = current->next;
            }
        }

        for(int i = 0; i < oldCap; i++){
            hashNode* current = oldHashTable[i];
            while(current != NULL){
                hashNode* trash = current;
                current = current->next;
                delete trash;
            }
        }
    }

    delete oldHashTable;
}








