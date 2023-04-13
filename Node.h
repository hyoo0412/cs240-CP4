#ifndef NODE_H
#define NODE_H

class Node{
    public:
        int data; // only pos integers
        Node *left;
        Node *right;

        Node(){
            left = nullptr;
            right = nullptr;
        }

        Node(int new_contents){ // value constructor
            data = new_contents;
            left = nullptr;
            right = nullptr;
        }

        ~Node() {
            delete left;
            delete right;
        }
};

#endif