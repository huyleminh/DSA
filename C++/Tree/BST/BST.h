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


#ifndef _BST_CPP_
#include "BST.cpp"
#endif

#endif