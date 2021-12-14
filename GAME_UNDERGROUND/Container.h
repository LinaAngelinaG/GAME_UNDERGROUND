#pragma once
#include "Tools.h"

template <typename T>
struct Node {
protected:
    int passed = 0;

    Node* left;
    Node* right;
    Node* parent = nullptr;
public:
    T key;
    int value;
    Node(T t,int val){
        left = nullptr;
        right = nullptr;
        key = t;
        value = val;
    }

    /*
    int getValue() { return value; }
    T getKey() { return key; }
    int getpassed() { return passed; }
    Node* getLeft(){return }*/
    template <typename T>
    friend class Container;
};


template <typename T>
class Container { //: virtual public Tool 
protected:
    Node<T> * mapOfParameters;
    int size;

    void printTree(Node<T> *) const;
    void deleteTree(Node<T> *);
    Node<T>* iter(Node<T>*) const;
    void makeZeros(Node<T>*) const;

public:
    Container(T,int);
    Container() :mapOfParameters(nullptr), size(0) {}
    ~Container();

    void print() const;
    bool find(T) const;
    void insert(T, int);
    inline int getSize() { return size; };
    int at(T) const;

    class Iterator {
    protected:
        Node<T>* curr;
    public:
        Iterator(Node<T>* first) : curr(first) { }
        Iterator() : curr(nullptr) {}
        //Node<T>& operator+ (int n);
        //Node<T>& operator- (int n);

        Node<T>* operator++ ();
        //Node<T>& operator-- ();
        Node<T>* operator++ (int n);
        //Node<T>& operator-- (int n);

        inline bool operator !=(const Iterator& it)const { return curr != it.curr; }
        inline bool operator ==(const Iterator& it)const { return curr == it.curr; }
        inline Node<T>& operator *() { return *curr; }
    };

    class ConstIterator: public Iterator {
    protected:
        Node<T>* curr;
    public:
        ConstIterator(Node<T>* first) : Iterator(first), curr(first) { }
        ConstIterator() : Iterator() {}
        //Node<T>& operator+ (int n);
        //Node<T>& operator- (int n);

        const Node<T>* operator++ ();
        //Node<T>& operator-- ();
        //const Node<T>* operator++ (int n);
        //Node<T>& operator-- (int n);

        inline bool operator != (const ConstIterator& it) {return curr != it.curr; }
        inline bool operator ==(const ConstIterator& it) { return curr == it.curr; }
        inline const Node<T>& operator *() { return *curr; }
    };
    
    //class Iterator;

    Iterator begin() {
        makeZeros(mapOfParameters);
        Node<T>* node(iter(mapOfParameters));
        if (node != nullptr) {
            node->passed = 1;
            return Iterator(node);
        }
        return nullptr;
    }

    ConstIterator cbegin() const {
        makeZeros(mapOfParameters);
        Node<T>* node(iter(mapOfParameters));
        if (node != nullptr) {
            node->passed = 1;
            return ConstIterator(node);
        }
        return nullptr;
    }
    inline Iterator end() { return nullptr; }
    inline ConstIterator cend() const { return nullptr; }

    //”¡–¿“‹  Œ√ƒ¿ «¿–¿¡Œ“¿≈“!!
    /*virtual int use(ENEMY) { return 0; };
    virtual bool isArtefact() { return true; };
    virtual std::string getname() { return "ww"; };*/
};