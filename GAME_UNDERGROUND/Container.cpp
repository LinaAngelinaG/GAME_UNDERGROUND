/**
\file Container.cpp
\brief File with some methods of the container-class.
*/
#include "Container.h"

/**
    Constractor for the container-class.
    \param Builds with the key and its value.
    */
template <typename T>
Container<T>::Container(T key,int value)
{
    mapOfParameters = new Node<T>(key, value);
    size = 1;
}

/**
    Destructor for the container.
    Delete all the nodes.
    */
template <typename T>
Container<T>::~Container()
{
    deleteTree(mapOfParameters);
}

/**
    Lets to delete the whole tree.
    \param The root pointer.
    \return Nothing.
    */
template <typename T>
void Container<T>::deleteTree(Node<T>* curr){
    if (curr){
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }
}

/**
    Lets to print all the nodes of the tree.
    \param No arguments.
    \return Nothing.
    */
template <typename T>
void Container<T>::print()const {
    printTree(mapOfParameters);
    std::cout << std::endl;
}

/**
    Recursive fuction to help to print() function.
    \param Pointer to the current node.
    \return Nothing.
    */
template <typename T>
void Container<T>::printTree(Node<T>* curr)const {
    if (curr){
        printTree(curr->left);
        std::cout << curr->key << " " << curr->value << "   ";
        printTree(curr->right);
    }
}

/**
    Lets to say: does the tree contain the value with the exact key.
    \param The key of the typename T.
    \return Boollean answer.
    */
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

/**
    Lets to know the value with the exact key.
    \param The key of the typename T.
    \return Integer value of the key.
    */
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

/**
    Lets to create the node with the exact key and value and insert it into the tree.
    \param The key and its value.
    \return Nothing.
    */
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

/**
    Lets to iterate to the left node of the tree.
    \param The pointer of th current node.
    \return The pointer to the node that we are looking for.
    */
template <typename T>
Node<T>* Container<T>::iter(Node<T>* root) const {
    if (root != nullptr && root->left != nullptr) {
        return iter(root->left);
    }
    return root;
}

/**
    Lets to make all the passed-values equal to 0.
    \param Root of the tree.
    \return Nothing.
    */
template <typename T>
void Container<T>::makeZeros(Node<T>* node) const {
    if (node) {
        makeZeros(node->left);
        node->passed = 0;
        makeZeros(node->right);
    }
}

/**
    Overloaded operator ++ for the iterator: the prefix increment
    \param No arguments.
    \return The pointer to the next node.
    */
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

/**
    Overloaded operator ++ for the const_iterator: the prefix increment
    \param No arguments.
    \return The constant pointer to the next node.
    */
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

/**
    Overloaded operator ++ for the const_iterator: the postfix increment.
    \param Integer unimportant value.
    \return The constant pointer to the node that is previous to the next node.
    */
template <typename T>
const Node<T>* Container<T>::ConstIterator::operator++ (int d) {
    Node<T>* prev = curr;
    ++(*this);
    return prev;
}

/**
    Overloaded operator ++ for the iterator: the postfix increment.
    \param Integer unimportant value.
    \return The pointer to the node that is previous to the next node.
    */
template <typename T>
Node<T>* Container<T>::Iterator::operator++ (int d) {
    Node<T>* prev = curr;
    ++(*this);
    return prev;
}

/**
    The fuction that defines the types for the template class.
    \param No arguments.
    \return Nothing.
    */
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