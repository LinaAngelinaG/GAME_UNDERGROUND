#include "Container.h"

template <typename T>
Container<T>::Container(T key,int value)
{
    mapOfParameters = new Node<T>(key, value);
    size = 1;
}
/*
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
*/
template <typename T>
Container<T>::~Container()
{
    deleteTree(mapOfParameters);
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
void Container<T>::print()const {
    printTree(mapOfParameters);
    std::cout << std::endl;
}

template <typename T>
void Container<T>::printTree(Node<T>* curr)const {
    if (curr){
        printTree(curr->left);
        std::cout << curr->key << " " << curr->value << "   ";
        printTree(curr->right);
    }
}

template <typename T>
bool Container<T>::find(T keyToFind)const {
    Node<T>* curr = mapOfParameters;
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
int Container<T>::at(T keyToFind) const {
    Node<T>* curr = mapOfParameters;
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
    if (!mapOfParameters) {
        mapOfParameters = new Node<T>(keyToInsert, val);
        return;
    }
    Node<T>* curr = mapOfParameters;
    while (curr && curr->key != keyToInsert) {
        if (curr->key > keyToInsert && curr->left == nullptr) {
            curr->left = new Node<T>(keyToInsert, val);
            curr->left->parent = curr;
            ++size;
            return;
        }
        if (curr->key < keyToInsert && curr->right == nullptr) {
            curr->right = new Node<T>(keyToInsert, val);
            curr->right->parent = curr;
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

template <typename T>
Node<T>* Container<T>::iter(Node<T>* root) const {
    if (root != nullptr && root->left != nullptr) {
        return iter(root->left);
    }
    return root;
}

template <typename T>
void Container<T>::makeZeros(Node<T>* node) const {
    if (node) {
        makeZeros(node->left);
        node->passed = 0;
        makeZeros(node->right);
    }
}

/*
template <typename T>
Container<T>::Iterator Container<T>::begin() {
    makeZeros(root);
    Node<T>* node(iter(root));
    node->passed = 1;
    return Iterator(node);
}*/

template <typename T>
Node<T>* Container<T>::Iterator::operator++ () {
    if (curr->left != nullptr && curr->left->passed == 0) {
        curr = curr->left;
        return ++(*this);
    }
    if (curr->right != nullptr && curr->right->passed == 0) {
        curr = curr->right;
        return ++(*this);
    }
    if (curr->passed == 0) {
        curr->passed = 1;
        return curr;
    }
    if (curr->parent != nullptr) {
        curr = curr->parent;
        return ++(*this);
    }
    else {
        *this = nullptr;
        return nullptr;
    }
}

template <typename T>
const Node<T>* Container<T>::ConstIterator::operator++ () {
    if (curr->left != nullptr && curr->left->passed == 0) {
        curr = curr->left;
        return ++(*this);
    }
    if (curr->right != nullptr && curr->right->passed == 0) {
        curr = curr->right;
        return ++(*this);
    }
    if (curr->passed == 0) {
        curr->passed = 1;
        return curr;
    }
    if (curr->parent != nullptr) {
        curr = curr->parent;
        return ++(*this);
    }
    else {
        *this = nullptr;
        return nullptr;
    }
}

template <typename T>
Node<T>* Container<T>::Iterator::operator++ (int d) {
    if (curr->left != nullptr && curr->left->passed == 0) {
        curr = curr->left;
        Iterator it(curr);
        
        return it++;
    }
    if (curr->right != nullptr && curr->right->passed == 0) {
        curr = curr->right;
        return curr++;
    }
    if (curr->passed == 0) {
        curr->passed = 1;
        return curr;
    }
    if (curr->parent != nullptr) {
        curr = curr->parent;
        return curr++;
    }
    else {
        *this = nullptr;
        return nullptr;
    }
}


void TemplateMap() {
    Container<CHARACTERS> container1(Power, 1);
    container1.insert(Power, 3);
    container1.find(Power);
    container1.print();
    Container<CHARACTERS>::Iterator it;
    it = container1.begin();
    container1.at(Power);
    Container<CHARACTERS>::Iterator it1(container1.begin());
    Container<CHARACTERS>::ConstIterator itt;
    ++itt;
    it++;
    ++it;
    Node<CHARACTERS> node1(Power, 1); 
    
    Container<CHARM> container2(Blessed, 1);
    Container<CHARM>::Iterator it2;
    Container<CHARM>::ConstIterator itt1;
    it2 = container2.begin();
    container2.at(Blessed);
    Container<CHARM>::Iterator it3(container2.begin());
    ++itt1;
    it2++;
    ++it2;
    container2.insert(Blessed, 3);
    container2.find(Blessed);
    container2.print();
    Node<CHARM> node2(Blessed, 1);
    
}