#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "BST.h"
// #include "Node.h"

using namespace std;

// BST::BST() {
//     data = 0;
//     left = nullptr;
//     right = nullptr;
// }
// BST::BST(int newData) {
//     data = newData;
//     left = nullptr;
//     right = nullptr;
// }

Node* BST::insert(Node*& currentNode, int data) {
    if(data > 0){ // checking if positive
        if(findExist(currentNode, data) == false){
            if (currentNode == nullptr) {
                Node* newNode = new Node(data);
                currentNode = newNode;
                return newNode;
            } else {
                if (data > currentNode->data) {
                    insert(currentNode->right, data);
                } else if(data < currentNode->data) {
                    insert(currentNode->left, data);
                }
            }
        }
    }
    return nullptr;
}

bool BST::findExist(Node*& parent, int data){
    Node* curr = new Node;
    curr = parent;

    while(curr != nullptr) {
        if(curr->data == data) {
            return true;
        }
        else if(curr->data < data) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return false;
}

Node* BST::find(Node* parent, int data){
    int height = 0;
    Node* curr = new Node;
    curr = parent;

    while(curr != nullptr) {
        height += 1;
        if(curr->data == data) {
            return curr;
        }
        else if(curr->data < data) {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
    }
    return curr;
}

Node* BST::findMin(Node* parent){
    Node* curr = new Node;
    curr = parent;

    while(curr != nullptr && curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

Node* BST::removeNode(Node* parent, int data){
    if(parent == nullptr) {
        return parent;
    }
    
    if(data < parent->data) {
        parent->left = removeNode(parent->left, data);
    }
    else if(data > parent->data) {
        parent->right = removeNode(parent->right, data);
    }
    else {
        if(parent->left == nullptr && parent->right == nullptr) {
            return nullptr;
        }
        else if(parent->left == nullptr) {
            Node* curr = parent->right;
            delete parent;
            return curr;
        }
        else if(parent->right == nullptr) {
            Node* curr = parent->left;
            delete parent;
            return curr;
        }
        else {
            // node with two children
            Node* curr = findMin(parent->right);
            parent->data = curr->data;
            parent->right = removeNode(parent->right, curr->data);
        }
    }
    return parent;
}

vector<int> BST::insertIntoVector(Node* parent){
    vector<int> v;

    Node* curr;
    curr = parent;

    if(curr != NULL){
        v.push_back(curr->data);
        while(curr->left != NULL) {
            v.push_back(curr->left->data);
            curr = curr->left;
        }
        curr = parent;
        while(curr->right != NULL) {
            v.push_back(curr->right->data);
            curr = curr->right;
        }
    }

    // print out vector
    cout << "After insertIntoVector(): ";
    return v;
}
vector<int> BST::removeOutVector(vector<int> v){
    v.clear();
    cout << "After removeOutVector(): ";
    return v;
}

vector<int> BST::shuffle(vector<int> v, int swap){
    srand(time(0));

    int random1 = rand() % v.size();
    int random2 = rand() % v.size();
    
    for(int i = 0; i < swap; i++) {
        int temp;
        cout << "swap: " << random1 << " " << random2 << endl;

        temp = v[random1];
        v[random1] = v[random2];
        v[random2] = temp;
        cout << "After shuffle(): "; 

        random1 = rand() % v.size();
        random2 = rand() % v.size();
    }

    return v;
}
vector<int> BST::shake(vector<int> v, int S, int R){
    // randomly select an element in the vector S times
    for(int j = 0; j < S; j++){
        int rdm = rand() % v.size();

        int temp = v[rdm]; // random # in vector
        int num_places = rand()%R+1; // random # btwn 1 and R

        remove(v.begin(),v.end(),temp); // removes random # in vector
        
        if(!(num_places > v.size())){ // if # places to move > size dont do anything
            v.insert(v.begin()+ num_places, temp); // if not: insert the random # in that spot

            // this is WRONG l o l
            // wants it to move (#) places left or right NOT insert at index (#)

            // left: curr index - amt move (if goes into negative)
            // right: curr index + amt move (if goes into negative)

        }
    }
    
    
    // each time it does, it should move that element a random # of places
    // btwn 1 and R to the left/right sliding elements it passes in behind it
    // if reach beginning or end of vector should not wrap around
    return v;
}

int BST::averageDepth(Node* parent) {
    if(parent == nullptr) {
        return 0;
    }

    int left = 1 + averageDepth(parent->left);
    int right = 1 + averageDepth(parent->right);

    int depth = (left + right)/2;

    return depth;
}

int BST::height(Node* parent) {
    if(parent == nullptr) {
        return -1;
    }

    int left = height(parent->left);
    int right = height(parent->right);

    return 1 + max(left, right);
}

void BST::print(Node* parent, int space){
    if (parent == nullptr)
        return;
 
    space += 10;

    print(parent->right, space);
    
    cout << endl;
    for(int i = 10; i < space; i++) {
        cout << " ";
    }
    cout << parent->data << "\n";
 
    print(parent->left, space);
}

// void BST::print2DUtil(Node* parent, int space) // DELETE  
// {
//     if (parent == NULL)
//         return;
 
//     space += 10;
 
//     print2DUtil(parent->right, space);
 
//     cout << endl;
//     for (int i = 10; i < space; i++)
//         cout << " ";
//     cout << parent->data << "\n";
 
//     print2DUtil(parent->left, space);
// }
 
// void BST::print2D(Node* parent) // DELETE
// {
//     print2DUtil(parent, 0);
// }
