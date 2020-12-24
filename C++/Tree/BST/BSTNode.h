/**
 *
 * BSTNode.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement a Node of a Binary Search Tree
*/


#ifndef _BST_NODE_H_
#define _BST_NODE_H_

template<class T>
class BSTNode {
protected:
    T _key;
    BSTNode* _left;
    BSTNode* _right;

public:
    BSTNode() : _left(nullptr), _right(nullptr) {}
    BSTNode(const T& key) : _key(key), _left(nullptr), _right(nullptr) {}

    BSTNode*& operator =(BSTNode* p);

    T& getKey();
    void setKey(const T& key);
    BSTNode*& left();
    BSTNode*& right();

    static BSTNode* init(const T& key);
};

template<class T>
BSTNode<T>*& BSTNode<T>::operator=(BSTNode<T>* p) {
    if (!p) {
        BSTNode<T>::BSTNode();
        return *this;
    }
    this->_key = p->_key;
    this->_left = p->_left;
    this->_right = p->_right;
    return *this;
}

template<class T>
T& BSTNode<T>::getKey() {
    return _key;
}

template<class T>
void BSTNode<T>::setKey(const T& key) {
	_key = key;
}

template<class T>
BSTNode<T>*& BSTNode<T>::left() {
	return this->_left;
}

template<class T>
BSTNode<T>*& BSTNode<T>::right() {
	return this->_right;
}

template<class T>
BSTNode<T>* BSTNode<T>::init(const T& key) {
	BSTNode<T>* p = new BSTNode<T>(key);
	return p;
}

#endif