// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include "console.h"

#include "ArrayList.h"


ArrayList::ArrayList(int size, int capacity){
    this->elements = new int[capacity]();
    this->size = size;
    this->capacity = capacity;
}

ArrayList::~ArrayList(){
    delete[] elements;
}

void ArrayList::add(int value){
    if(size >= capacity){
        capacity *= 2;
        int* temp = new int[capacity]();
        for(int i = 0; i < size; i++){
            temp[i] = elements[i];
         }
        delete[] elements;
        elements = temp;
    }

    this->elements[size] = value;
    size++;
}
