#include "Container.h"

template <typename T>
Container<T>::Container(T key,int value)
{
    root = new Node<T>(key, value);
    size = 1;
}

template <typename T>
Container<T>::Iterator Container<T>::begin() {
    Node<T> cur = root;
    Node<T> pr = nullptr;
    while (cur->left != nullptr) {
        pr = cur;
        cur = cur.left;
    }
    Container<T>::Iterator this.
    return cur;
}

template <typename T>
Container<T>::Iterator Container<T>::end() {
    Node<T> cur = root;

    while (cur->right != nullptr) {
        cur = cur.right;
    }
    return cur;
}

template <typename T>
Container<T>::~Container()
{
    deleteTree(root);
}

template <typename T>
void Container<T>::deleteTree(Node<T>* curr){
    if (curr){
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }
}

template <typename T>
void Container<T>::print() {
    printTree(root);
    std::cout << std::endl;
}

template <typename T>
void Container<T>::printTree(Node<T>* curr) {
    if (curr){
        printTree(curr->left);
        std::cout << curr->key << " " << curr->value << "   ";
        printTree(curr->right);
    }
}

template <typename T>
bool Container<T>::find(T keyToFind){
    Node<T>* curr = root;
    while (curr && curr->key != keyToFind)
    {
        if (curr->key > keyToFind)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr != nullptr;
}

template <typename T>
int Container<T>::at(T keyToFind) {
    Node<T>* curr = root;
    while (curr && curr->key != keyToFind)
    {
        if (curr->key > keyToFind)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return (curr!=nullptr && curr->key == keyToFind) ? curr->value : 0;
}

template <typename T>
void Container<T>::insert(T keyToInsert, int val) {
    Node<T>* curr = root;
    while (curr && curr->key != keyToInsert) {
        if (curr->key > keyToInsert && curr->left == nullptr) {
            curr->left = new Node<T>(keyToInsert, val);
            ++size;
            return;
        }
        if (curr->key < keyToInsert && curr->right == nullptr) {
            curr->right = new Node<T>(keyToInsert, val);
            ++size;
            return;
        }
        if (curr->key > keyToInsert)
            curr = curr->left;
        else
            curr = curr->right;
    }
    if (curr!= nullptr && curr->key == keyToInsert)
        curr->value = val;
}

void TemplateMap() {
    Container<CHARACTERS> container1(Power, 1);
    container1.insert(Power, 3);
    container1.find(Power);
    container1.print();
    Node<CHARACTERS> node1(Power, 1); 

    Container<CHARM> container2(Blessed, 1);
    container2.insert(Blessed, 3);
    container2.find(Blessed);
    container2.print();
    Node<CHARM> node2(Blessed, 1);
    
}