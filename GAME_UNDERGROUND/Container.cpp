#include "Container.h"

Container::Container(TYPE key,int value)
{
    root = new Node(key, value);
    size = 1;
}

Container::~Container()
{
    deleteTree(root);
}

void Container::deleteTree(Node* curr){
    if (curr){
        deleteTree(curr->left);
        deleteTree(curr->right);
        delete curr;
    }
}

void Container::print() {
    printTree(root);
    std::cout << std::endl;
}

void Container::printTree(Node* curr) {
    if (curr){
        printTree(curr->left);
        std::cout << curr->key << " " << curr->value;
        printTree(curr->right);
    }
}

bool Container::find(TYPE keyToFind){
    Node* curr = root;
    while (curr && curr->key != keyToFind)
    {
        if (curr->key > keyToFind)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return curr != nullptr;
}

void Container::insert(TYPE keyToInsert, int val) {
    Node* curr = root;
    while (curr && curr->key != keyToInsert) {
        if (curr->key > keyToInsert && curr->left == nullptr) {
            curr->left = new Node(keyToInsert, val);
            ++size;
            return;
        }
        if (curr->key < keyToInsert && curr->right == nullptr) {
            curr->right = new Node(keyToInsert, val);
            ++size;
            return;
        }
        if (curr->key > keyToInsert)
            curr = curr->left;
        else
            curr = curr->right;
    }
}