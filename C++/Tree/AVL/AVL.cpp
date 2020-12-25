#ifndef _AVL_CPP_
#define _AVL_CPP_

#include "AVL.h"
#include <iostream>
using namespace std;

template<class T>
void AVL<T>::preOrderTraversal(AVLNode<T>* root) {
    if (!root)
        return;
    cout << "{ " << root->getKey() << ", " << root->getHeight() << " } ";
    preOrderTraversal(root->left());
    preOrderTraversal(root->right());
}

template<class T>
void AVL<T>::inOrderTraversal(AVLNode<T>* root) {
    if (!root)
        return;
    inOrderTraversal(root->left());
    cout << "{ " << root->getKey() << ", " << root->getHeight() << " } ";
    inOrderTraversal(root->right());
}

template<class T>
void AVL<T>::posOrderTraversal(AVLNode<T>* root) {
    if (!root)
        return;
    posOrderTraversal(root->left());
    posOrderTraversal(root->right());
    cout << "{ " << root->getKey() << ", " << root->getHeight() << " } ";
}

template<class T>
AVLNode<T>* AVL<T>::search(AVLNode<T>* root, const T& key) {
    if (!_root)
        return nullptr;

    AVLNode<T>* p = root;
    while (p) {
        if (p->getKey() == key)
            return p;
        p = (key < p->getKey()) ? p->left() : p->right();
    }
    return nullptr;
}

template<class T>
void AVL<T>::insert(AVLNode<T>*& root, const T& key) {
    if (!root) {
        root = new AVLNode<T>(key);
        return;
    }
    if (root->getKey() == key)
        return;
    else if (root->getKey() > key)
        insert(root->left(), key);
    else 
        insert(root->right(), key);

    if (!root)
        return;
    root->fixHeight();
    rotate(root);
}

template<class T>
void AVL<T>::removeNode(AVLNode<T>*& root, const T& key) {
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
        else if (!root->left() || !root->right()) {
            AVLNode<T>* p = root;
            root = (root->left()) ? root->left() : root->right();
            delete p;
        }
        else if (root->left() && root->right()) {
            AVLNode<T>* predecessorNode = this->predecessor(root->left());
            root->setKey(predecessorNode->getKey());
            removeNode(root->left(), predecessorNode->getKey());
        }
    }

    if (!root)
        return;
    root->fixHeight();
    rotate(root);
}

template<class T>
AVLNode<T>* AVL<T>::predecessor(AVLNode<T>* root) {
    if (!root)
        return nullptr;
    AVLNode<T>* p = root;
    while (p->right())
        p = p->right();
    return p;
}

template<class T>
void AVL<T>::rotateLeft(AVLNode<T>*& root) {
    if (!root)
        return;
    AVLNode<T>* rright = root->right();

    root->right() = rright->left();
    root->fixHeight();

    rright->left() = root;
    root = rright;
    root->fixHeight();
}

template<class T>
void AVL<T>::rotateRight(AVLNode<T>*& root) {
    if (!root)
        return;
    AVLNode<T>* rleft = root->left();

    root->left() = rleft->right();
    root->fixHeight();

    rleft->right() = root;
    root = rleft;
    root->fixHeight();
}

template<class T>
void AVL<T>::rotate(AVLNode<T>*& root) {
    if (!root)
        return;

    int balance = 0; //Check left or right case
    int sbalance = 0; //Continue from balance, check left-right or right-left
    int lheight, rheight;
    AVLNode<T>* leftNode = root->left();
    AVLNode<T>* rightNode = root->right();

    lheight = (!leftNode) ? 0 : leftNode->getHeight();
    rheight = (!rightNode) ? 0 : rightNode->getHeight();
    balance = lheight - rheight;

    if (balance > 1) {
        if (!leftNode) {
            sbalance = 0;
        }
        else {
            lheight = (!leftNode->left()) ? 0 : leftNode->left()->getHeight();
            rheight = (!leftNode->right()) ? 0 : leftNode->left()->getHeight();
            sbalance = lheight - rheight;
        }

        if (sbalance >= 0)
            rotateRight(root);
        else {
            rotateLeft(root->right());
            rotateRight(root);
        }
    }
    else if (balance < -1) {
        if (!rightNode) {
            sbalance = 0;
        }
        else {
            lheight = (!rightNode->left()) ? 0 : rightNode->left()->getHeight();
            rheight = (!rightNode->right()) ? 0 : rightNode->right()->getHeight();
            sbalance = rheight - lheight;
        }

        if (sbalance >= 0)
            rotateLeft(root);
        else {
            rotateRight(root->left());
            rotateLeft(root);
        }
    }
}

template<class T>
void AVL<T>::clear(AVLNode<T>*& root) {
    if (!root)
        return;
    clear(root->left());
    clear(root->right());
    delete root;
}

#endif