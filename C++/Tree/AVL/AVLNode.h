/**
 *
 * AVLNode.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement a Node of a AVL (balance binary tree)
*/


#ifndef _AVL_NODE_H_
#define _AVL_NODE_H_

#include <iostream>
using namespace std;

template<class T>
class AVLNode {
protected:
    T _key;
    AVLNode* _left;
    AVLNode* _right;
    int _height;
public:
    AVLNode() : _left(nullptr), _right(nullptr), _height(0) {}
    AVLNode(const T& key) : _key(key), _left(nullptr), _right(nullptr), _height(1) {}

    AVLNode*& operator =(AVLNode* p);

    T& getKey();
    void setKey(const T& key);

    int& getHeight();
    void fixHeight();

    AVLNode*& left();
    AVLNode*& right();

    static AVLNode* init(const T& key);
};

template<class T>
AVLNode<T>*& AVLNode<T>::operator=(AVLNode<T>* p) {
    if (!p) {
        AVLNode<T>::AVLNode();
        return *this;
    }
    this->_key = p->_key;
    this->_left = p->_left;
    this->_right = p->_right;
    this->_height = p->_height;
    return *this;
}

template<class T>
T& AVLNode<T>::getKey() {
    return _key;
}

template<class T>
void AVLNode<T>::setKey(const T& key) {
	_key = key;
}

template<class T>
int& AVLNode<T>::getHeight() {
    return _height;
}

template<class T>
void AVLNode<T>::fixHeight() {
    int lheight, rheight;
    lheight = (!_left) ? 0 : _left->getHeight();
    rheight = (!_right) ? 0 : _right->getHeight();
	_height = 1 + std::max(lheight, rheight);
}

template<class T>
AVLNode<T>*& AVLNode<T>::left() {
	return this->_left;
}

template<class T>
AVLNode<T>*& AVLNode<T>::right() {
	return this->_right;
}

template<class T>
AVLNode<T>* AVLNode<T>::init(const T& key) {
	AVLNode<T>* p = new AVLNode<T>(key);
	return p;
}

#endif