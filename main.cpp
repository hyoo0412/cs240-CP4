#include <string>
#include <cassert> 
#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;

int main(){

    BST bst;
    Node *root = nullptr;
    bst.insert(root, 5);
    // bst.insert(root, );
    bst.insert(root, 2);
    bst.insert(root, 3);
    bst.insert(root, 1);
    bst.insert(root, 7);
    bst.insert(root, 8);
    bst.insert(root, 4);
    // for(int i = 0; i < 10; i++) {
    //     bst.insert(root, i);
    // }
    bst.print(root, 0);

    cout << endl;
    cout << endl;

    cout << "averageDepth: " << bst.averageDepth(root) << endl;
    cout << "height: " << bst.height(root) << endl;

    // vector<int> v = bst.insertIntoVector(root);
    // bst.shuffle(v, 3);

}

// #endif