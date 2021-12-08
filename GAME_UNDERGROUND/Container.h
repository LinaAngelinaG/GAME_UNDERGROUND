#pragma once
#include "Tools.h"

struct Node {
    TYPE key;
    int value;

    Node* left;
    Node* right;

    Node(TYPE t,int val){
        left = nullptr;
        right = nullptr;
        key = t;
        value = val;
    }
};

class Container : virtual public Tool {
private:
    Node* root;
    int size;
    void printTree(tree_elem*);
    void deleteTree(tree_elem*);

public:
    Container(TYPE,int);
    ~Container();

    void print();
    bool find(TYPE);
    void insert(TYPE, int);
    inline int getSize() { return size; };
};