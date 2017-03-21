#include <iostream>
#include "console.h"

#include "linkedlist.h"

using namespace std;

LinkedList::LinkedList(){
    front = NULL;
}

LinkedList::~LinkedList(){
    delete front;
}

void LinkedList::add(int data){
    if(front == NULL){
        front = new linkNode(data);
    }else{
        linkNode* temp = front;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = new linkNode(data);
    }
}

int LinkedList::get(int index){
    int temp = 0;
    linkNode* current = front;

    while(temp < index-1){
        current = current->next;
        temp++;
    }
    return current->next->data;

}

void LinkedList::insert(int index, int data){
    if(index == 0){
        front = new linkNode(data);
    }
    linkNode* current = front;
    for(int i = 0; i < index-1; i++){
        current = current->next;
    }

    linkNode* temp = new linkNode(data);
    temp->next = current->next;
    current->next = temp;
}

void LinkedList::remove(int index){
    if(index == 0){
        front = front->next;
    }else{
        linkNode* current = front;

        for(int i = 0; i < index-1; i++){
            current = current->next;
        }
        current->next = current->next->next;
    }

}
