#ifndef BST_H
#define BST_H
#include <stdlib.h>
#include <iostream>
#include "Node.h"

using namespace std;

class BST{
    // private:
    //     int data;
    //     BST *left;
    //     BST *right;

    public:
        // BST();
        // BST(int newData);
        // ~BST();

        Node* insert(Node*& parent, int data);
        bool findExist(Node*& parent, int data);
        Node* find(Node* parent, int data);
        Node* findMin(Node* parent);
        Node* removeNode(Node* parent, int data);
 
        vector<int> insertIntoVector(Node*parent);
        vector<int> removeOutVector(vector<int> v);
        vector<int> shuffle(vector<int> v, int swap);
        vector<int> shake(vector<int> v, int S, int R);
        int averageDepth(Node* parent);
        int height(Node* parent);
        void print(Node* parent, int space);
        // void print2DUtil(Node* parent, int space);
        // void print2D(Node* parent); 
        // void printVector(vector<int> v);

};
#endif