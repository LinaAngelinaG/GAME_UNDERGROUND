#pragma once
#include "Tools.h"

template <typename T>
struct Node {
    T key;
    int value;

    Node* left;
    Node* right;
    Node* parent = nullptr;

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

    class Iterator;
    Iterator begin();
    Iterator end();

    void print();
    bool find(T);
    void insert(T, int);
    inline int getSize() { return size; };
    int at(T);

    class Iterator {
    private:
        Node<T>* curr;
    public:
        Iterator(Node<T>* first) : curr(first) {}

        Node& operator+ (int n);
        Node& operator- (int n);

        Node& operator++ () { return curr.right != nullptr ? curr->right : curr.parent != nullptr ? curr.parent : nullptr; }
        Node& operator-- () { return curr.parent != nullptr ? curr->parent : curr.left != nullptr ? curr.left : nullptr; }
        Node& operator++ (int n);
        Node& operator-- (int n);

        bool operator !=(const Iterator& it) { return curr != it.curr; }
        bool operator ==(const Iterator& it) { return curr == it.curr; }
        Node& operator *() { return *jcurr; }
    };

    virtual int use(ENEMY) { return 0; };
    virtual bool isArtefact() { return true; };
    virtual std::string getname() { return "ww"; };
};