/**
 *
 * AVL.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement AVL (balance binary tree)
*/


#ifndef _AVL_H_
#define _AVL_H_

#include "AVLNode.h"

template<class T>
class AVL {
protected:
    AVLNode<T>* _root;
private:
    void preOrderTraversal(AVLNode<T>* root);
    void inOrderTraversal(AVLNode<T>* root);
    void posOrderTraversal(AVLNode<T>* root);

    AVLNode<T>* search(AVLNode<T>* root, const T& key);

    void insert(AVLNode<T>*& root, const T& key);

    void removeNode(AVLNode<T>*& root, const T& key);
    AVLNode<T>* predecessor(AVLNode<T>* root); //Find the right most node of left subtree, root is the root of the left subtree

    void rotateLeft(AVLNode<T>*& root);
    void rotateRight(AVLNode<T>*& root);
    void rotate(AVLNode<T>*& root);

    void clear(AVLNode<T>*& root);

public:
    AVL() : _root(nullptr) {}
    AVL(const T& key) {
        _root = AVLNode<T>::init(key);
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

    ~AVL() {
        this->clear(_root);
    }
};


#ifndef _AVL_CPP_
#include "AVL.cpp"
#endif

#endif