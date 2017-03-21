// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>
#include "console.h"


#include "bst.h"

binarySearchTree::binarySearchTree(treeNode* head){
    if(head == NULL){
        head = new treeNode(0);
    }
    this->root = head;
}

binarySearchTree::~binarySearchTree(){


}

bool binarySearchTree::contains(int data){
    return dataContains(this->root, data);
}

bool binarySearchTree::dataContains(treeNode *head, int data){
    if(head == NULL){
        return false;
    }else if(head->data == data){
        return true;
    }else if(head->data > data){
        return dataContains(head->left, data);
    }else{
        return (dataContains(head->right, data));
    }
}

void binarySearchTree::add(int data){
    addData(this->root, data);
}

void binarySearchTree::addData(treeNode*& head, int data){
    if(head == NULL){
        head = new treeNode(data);
    }else if(head->data > data){
        addData(head->left, data);
    }else{
        addData(head->right, data);
    }
}

int binarySearchTree::min(){
    if(this->root == NULL){
        throw "illegal BST";
    }else{
        return getMin(this->root);
    }
}

int binarySearchTree::getMin(treeNode* head){
    if(head->left == NULL){
        return head->data;
    }else{
        return getMin(head->left);
    }
}

void binarySearchTree::remove(int data){
    removeData(this->root, data);
}

void binarySearchTree::removeData(treeNode*& head, int data){
    if(head == NULL){
        return;
    }else if(head->data > data){
        removeData(head->left, data);
    }else if(head->data < data){
        removeData(head->right, data);
    }else{
        if(head->isLeaf()){
            delete head;
        }else if(head->left == NULL){
            treeNode* trash = head;
            head = head->right;
            delete trash;
        }else if(head->right == NULL){
            treeNode* trash = head;
            head = head->left;
            delete trash;
        }else{
            head->data = getMin(head->right);
            removeData(head->right, head->data);
        }
    }
}


