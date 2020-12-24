/**
 *
 * Node.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement a Node of a Linked List
*/


#ifndef _NODE_H_
#define _NODE_H_

template<class T>
class Node
{
protected:
    T _key;
    Node* _next;
public:
    Node() : _next(nullptr) {}
    Node(const T& key) : _key(key), _next(nullptr) {}

    Node*& operator =(Node* p);

    T& getKey();
    void setKey(const T& key);
    Node*& next();

    static Node* init(const T& key);
};

template<class T>
Node<T>*& Node<T>::operator =(Node* p) {
    if (!p) {
        Node<T>::Node();
        return *this;
    }
    this->~Node();
    this->_key = p->_key;
    this->_next = p->_next;
    return *this;
}

template<class T>
T& Node<T>::getKey() {
    return this->_key;
}

template<class T>
void Node<T>::setKey(const T& key) {
    this->_key = key;
}

template<class T>
Node<T>*& Node<T>::next() {
    return this->_next;
}

template<class T>
Node<T>* Node<T>::init(const T& key) {
    Node<T>*& p = new Node(key);
    return p;
}

#endif