// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>

#ifndef _link_list
#define _link_list

#include <string>

using namespace std;

struct linkNode{
    int data;
    linkNode* next;
    
    linkNode(int data, linkNode* next=NULL){
        this->data = data;
        this->next = next;
    }
    
};

class LinkedList{
    public:
    LinkedList();
    ~LinkedList();
    void add(int value);
    void clear(void);
    void insert(int index, int value);
    int get(int index);
    void set(int index, int value);
    void mySize(void) const;
    void isEmpty(void) const;
    void remove(int index);
    void toString();

    private:
    linkNode* front;
};




#endif
