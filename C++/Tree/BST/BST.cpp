#ifndef _BST_CPP_
#define _BST_CPP_

#include "BST.h"
#include <iostream>
using namespace std;

template<class T>
void BST<T>::preOrderTraversal(BSTNode<T>* root) {
    if (!root)
        return;
    cout << root->getKey() << " ";
    preOrderTraversal(root->left());
    preOrderTraversal(root->right());
}

template<class T>
void BST<T>::inOrderTraversal(BSTNode<T>* root) {
    if (!root)
        return;
    inOrderTraversal(root->left());
    cout << root->getKey() << " ";
    inOrderTraversal(root->right());
}

template<class T>
void BST<T>::posOrderTraversal(BSTNode<T>* root) {
    if (!root)
        return;
    posOrderTraversal(root->left());
    posOrderTraversal(root->right());
    cout << root->getKey() << " ";
}

template<class T>
BSTNode<T>* BST<T>::search(BSTNode<T>* root, const T& key) {
    if (!_root)
        return nullptr;

    BSTNode<T>* p = root;
    while (p) {
        if (p->getKey() == key)
            return p;
        p = (key < p->getKey()) ? p->left() : p->right();
    }
    return nullptr;
}

template<class T>
void BST<T>::insert(BSTNode<T>*& root, const T& key) {
    if (!root) {
        root = new BSTNode<T>(key);
        return;
    }
    if (root->getKey() == key)
        return;
    else if (root->getKey() > key)
        insert(root->left(), key);
    else 
        insert(root->right(), key);
}

template<class T>
void BST<T>::removeNode(BSTNode<T>*& root, const T& key) {
    if (!root)
        return;
    
    if (root->getKey() > key)
        removeNode(root->left(), key);
    else if (root->getKey() < key)
        removeNode(root->right(), key);
    else {
        if (!root->left() && !root->right()) {
            delete root;
            root = nullptr;
        }
        else if (!root->left() || root->right()) {
            BSTNode<T>* p = root;
            root = (root->left()) ? root->left() : root->right();
            delete p;
        }
        else {
            BSTNode<T>* predecessorNode = this->predecessor(root->left());
            root->setKey(predecessorNode->getKey());
            removeNode(root->left(), predecessorNode->getKey());
        }
    }
}

template<class T>
BSTNode<T>* BST<T>::predecessor(BSTNode<T>* root) {
    if (!root)
        return nullptr;
    BSTNode<T>* p = root;
    while (p->right())
        p = p->right();
    return p;
}

template<class T>
void BST<T>::clear(BSTNode<T>*& root) {
    if (!root)
        return;
    clear(root->left());
    clear(root->right());
    delete root;
}

#endif