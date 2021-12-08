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
    void printTree(Node*);
    void deleteTree(Node*);

public:
    Container(TYPE,int);
    ~Container();

    void print();
    bool find(TYPE);
    void insert(TYPE, int);
    inline int getSize() { return size; };

    virtual int use(ENEMY) { return 0; };
    virtual bool isArtefact() { return true; };
    virtual std::string getname() { return "ww"; };
};