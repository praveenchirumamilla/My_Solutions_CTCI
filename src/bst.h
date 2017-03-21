// This header file doesn't do much, but it's good to demonstrate that it's
// possible to create and edit header files

#include <iostream>

#ifndef _bst
#define _bst

struct treeNode{
    int data;
    treeNode* right;
    treeNode* left;

    treeNode(int data, treeNode* left = NULL, treeNode*right = NULL){
        this->data =  data;
        this->left = left;
        this->right = right;
    }

    bool isLeaf(){
        return (this->left == NULL) && (this->right == NULL);
    }

};


class binarySearchTree{
    public:
        binarySearchTree(treeNode* head);
        ~binarySearchTree();
        bool contains(int data);
        void add(int data);
        int min();
        void remove(int data);


    private:
        bool dataContains(treeNode* head, int data);
        void addData(treeNode*& head, int data);
        int  getMin(treeNode* head);
        void removeData(treeNode*& head, int data);

        treeNode* root;

};


#endif
