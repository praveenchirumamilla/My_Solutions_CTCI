// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>

#ifndef _array_list
#define _array_list

#include <string>

using namespace std;

class ArrayList{
    public:
    ArrayList(int size, int capacity);
    ~ArrayList();
    void add(int value);
    void clear(void);
    void insert(int index, int value);
    void get(int index) const;
    void set(int index, int value);
    void mySize(void) const;
    void isEmpty(void) const;
    void remove(int index);
    void toString();

    private:
    int* elements;
    int size;
    int capacity;
};




#endif
