/**
 *
 * BST.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement class Binay Search Tree
*/



#ifndef _BTS_H_
#define _BTS_H_

#include "BSTNode.h"
#include <iostream>
using namespace std;

template<class T>
class BST {
protected:
    BSTNode<T>* _root;
private:
    void preOrderTraversal(BSTNode<T>* root);
    void inOrderTraversal(BSTNode<T>* root);
    void posOrderTraversal(BSTNode<T>* root);

    BSTNode<T>* search(BSTNode<T>* root, const T& key);
    void insert(BSTNode<T>*& root, const T& key);

    void removeNode(BSTNode<T>*& root, const T& key);
    BSTNode<T>* predecessor(BSTNode<T>* root); //Find the right most node of left subtree

    void clear(BSTNode<T>*& root);

public:
    BST() : _root(nullptr) {}
    BST(const T& key) {
        _root = BSTNode<T>::init(key);
    }

    void preOrderTraversal() {
        this->preOrderTraversal(this->_root);
    }

    void inOrderTraversal() {
        this->inOrderTraversal(_root);
    }

    void posOrderTraversal() {
        this->posOrderTraversal(_root);
    }

    bool search(const T& key) {
        return (this->search(_root, key)) ? true : false;
    }
    
    void insert(const T& key) {
        this->insert(_root, key);
    }

    void removeNode(const T& key) {
        this->removeNode(_root, key);
    }

    void clear() {
        this->clear(_root);
    }

    ~BST() {
        this->clear(_root);
    }
};

//------------------------------------------------
//private

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