/**
\file Container.h
\brief Header-file with a description of the container-class.
*/
#pragma once
#include "Tools.h"

/**
 *  \brief     Template structure that desribes the nodes of the binary tree.
 *  \details   Holds the pointers for the left, right and parent branches, also containes key, its value and the value 'passed' that helps to overload the ++ operator.
 *  \details   Builds with the key and its value.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
template <typename T>
struct Node {
private:
    int passed = 0;

    Node* left;
    Node* right;
    Node* parent = nullptr;
public:
    T key;
    int value;

    /**
    * Builds with the key and its value.
    */
    Node(T t,int val){
        left = nullptr;
        right = nullptr;
        key = t;
        value = val;
    }

    template <typename T>
    friend class Container;
};


/**
* Friend-class for the class node.
 *  \brief     Template class that holds the binary tree that describes the map template-class.
 *  \details   Holds the root of the tree, its size and the own iterator-class.
 *  \details   Builds with the key and its value of the node or as an empty-container without any parameters.
 *  \author    LinaAngelinaG
 *  \date      15.12.2021
 */
template <typename T>
class Container {
private:
    Node<T> * mapOfParameters;
    int size;

    void printTree(Node<T> *) const;
    void deleteTree(Node<T> *);
    Node<T>* iter(Node<T>*) const;
    void makeZeros(Node<T>*) const;

public:
    Container(T,int);

    /** Builds with as an empty-container without any parameters.
    */
    Container() :mapOfParameters(nullptr), size(0) {}
    ~Container();

    void print() const;
    bool find(T) const;
    void insert(T, int);
    int at(T) const;

    /**
    Lets to know the amount of nodes in the tree.
    \param No arguments.
    \return Integer value of the nodes.
    */
    inline int getSize() { return size; };

    /**
     *  \brief     Class that desribes the iterator for the container-class.
     *  \details   Holds the pointer to the current node.
     *  \details   Builds with the current node or without any parameters.
     *  \author    LinaAngelinaG
     *  \date      15.12.2021
     */
    class Iterator {
    protected:
        Node<T>* curr;
    public:
        /** Builds with the current node.
            */
        Iterator(Node<T>* first) : curr(first) { }

        /** Builds without any parameters.
            */
        Iterator() : curr(nullptr) {}

        Node<T>* operator++ ();
        Node<T>* operator++ (int n);

        /**
        Overloaded operator != that allows to compare the iterators.
        \param Constant iterator for comparing.
        \return Bool value.
        */
        inline bool operator !=(const Iterator& it)const { return curr != it.curr; }

        /**
        Overloaded operator == that allows to compare the iterators.
        \param Constant iterator for comparing.
        \return Bool value.
        */
        inline bool operator ==(const Iterator& it)const { return curr == it.curr; }

        /**
        Overloaded operator * that allows to gain the current node.
        \param No arguments.
        \return Reference to the current node.
        */
        inline Node<T>& operator *() { return *curr; }
    };

    /**
     *  \brief     Class that desribes the const_iterator.
     *  \details   The same as the simple iterator except the thing that this one doesn't allow to change the node-information.
     *  \author    LinaAngelinaG
     *  \date      15.12.2021
     */
    class ConstIterator: public Iterator {
    protected:
        Node<T>* curr;
    public:
        /** Builds with the current node.
            */
        ConstIterator(Node<T>* first) : Iterator(first), curr(first) { }

        /** Builds without any parameters.
            */
        ConstIterator() : Iterator() {}
        
        const Node<T>* operator++ ();
        const Node<T>* operator++ (int n);

        /**
        The same as for the simple iterator.
        */
        inline bool operator != (const ConstIterator& it) {return curr != it.curr; }
        /**
        The same as for the simple iterator.
        */
        inline bool operator ==(const ConstIterator& it) { return curr == it.curr; }
        /**
        The same as for the simple iterator.
        */
        inline const Node<T>& operator *() { return *curr; }
    };

    /**
    Allows to gain the first element for the iteration. Makes of the nodes' passed-parameter (except the current) = 0.
    \param No arguments.
    \return Iterator with the current node.
    */
    Iterator begin() {
        makeZeros(mapOfParameters);
        Node<T>* node(iter(mapOfParameters));
        if (node != nullptr) {
            node->passed = 1;
            return Iterator(node);
        }
        return nullptr;
    }

    /**
    Allows to gain the first element for the iteration. Makes of the nodes' passed-parameter (except the current) = 0.
    \param No arguments.
    \return Constant iterator with the current node.
    */
    ConstIterator cbegin() const {
        makeZeros(mapOfParameters);
        Node<T>* node(iter(mapOfParameters));
        if (node != nullptr) {
            node->passed = 1;
            return ConstIterator(node);
        }
        return nullptr;
    }

    /**
    \param No arguments.
    \return Always return null pointer.
    */
    inline Iterator end() { return nullptr; }

    /**
    \param No arguments.
    \return Always return null pointer.
    */
    inline ConstIterator cend() const { return nullptr; }
};