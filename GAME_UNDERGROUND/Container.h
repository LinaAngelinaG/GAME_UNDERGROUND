#pragma once
#include "Tools.h"

template <typename T>
struct Node {
    T key;
    int value;

    Node* left;
    Node* right;

    Node(T t,int val){
        left = nullptr;
        right = nullptr;
        key = t;
        value = val;
    }
};

template <typename T>
class Container : virtual public Tool {
private:
    Node<T> * root;
    int size;
    void printTree(Node<T> *);
    void deleteTree(Node<T> *);

public:
    Container(T,int);
    ~Container();

    void print();
    bool find(T);
    void insert(T, int);
    inline int getSize() { return size; };

    virtual int use(ENEMY) { return 0; };
    virtual bool isArtefact() { return true; };
    virtual std::string getname() { return "ww"; };
};