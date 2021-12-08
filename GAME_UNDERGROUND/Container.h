#pragma once
#include "Tools.h"

struct Node {
    TYPE type;
    int value;

    Node* left;
    Node* right;

    Node(TYPE t,int val){
        left = nullptr;
        right = nullptr;
        type = t;
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
    void erase(TYPE);
    int getSize();
};