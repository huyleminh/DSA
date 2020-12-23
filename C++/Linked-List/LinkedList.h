#ifndef _LIST_H_
#define _LIST_H_

#include "Node.h"

template<class T>
bool ascendingOrder(const T& leftEle, const T& rightEle) {
    return leftEle < rightEle;
}

template<class T>
bool descendingOrder(const T& leftEle, const T& rightEle) {
    return leftEle > rightEle;
}

template<class T>
class LinkedList {
protected:
    Node<T>* _head;
    Node<T>* _tail;
    int _elements;
public:
    LinkedList() : _head(nullptr), _tail(nullptr), _elements(0) {}
    LinkedList(const T& key) {
        Node<T>* p = new Node<T>(key);
        _head = _tail = p;
        _elements = 1;
    }

    //Copy ctor
    LinkedList(const LinkedList& list);

    //Assignment
    LinkedList& operator =(const LinkedList& list);

    bool isEmpty() const;
    int size() const;

    void push(const T& key);
    void pop();
    void unShift(const T& key);
    void shift();
    
    Node<T>* front();
    Node<T>* back();

    void remove(const T& key);
    void clear();
    //TODO: finish these functions below
    void print();
    void printReverse();
    void reverse();
    
    void sort(bool (*compare)(const T&, const T&));
    //TODO:----------------------------------------------
    ~LinkedList();
};

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    LinkedList<T>::LinkedList();
    this->_elements = list._elements;
    for (Node<T>* p = list._head; p; p = p->next())
        this->push(p->getKey());
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& list) {
    if (!isEmpty())
        this->clear();
    this->_elements = list._elements;
    for (Node<T>* p = list._head; p; p = p->next())
        this->push(p->getKey());
    
    return *this;
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    return (_elements == 0) ? true : false;
}

template<class T>
int LinkedList<T>::size() const {
    return _elements;
}

template<class T>
void LinkedList<T>::push(const T& key) {
    Node<T>* p = new Node<T>(key);
    if (!_head) {
        _head = _tail = p;
        _elements = 1;
        return;
    }
    _tail->next() = p;
    _tail = p;
    ++_elements;
}

template<class T>
void LinkedList<T>::pop() {
    if (!_head) {
        _elements = 0;
        return;
    }
    Node<T>* p;
    p = _head;
    while (p->next() != _tail)
        p = p->next();
    
    delete _tail;
    _tail = p;
    _tail->next() = nullptr;
    --_elements;
}

template<class T>
void LinkedList<T>::unShift(const T& key) {
    Node<T>* p = new Node<T>*(key);
    if (!_head) {
        _head = _tail = p;
        _elements = 1;
        return;
    }
    p->next() = _head;
    _head = p;
    ++_elements;
}

template<class T>
void LinkedList<T>::shift() {
    if (!_head) {
        _elements = 0;
        return;
    }
    Node<T>* p;
    p = _head;
    if (p->next() == nullptr) 
        _head = _tail = nullptr;
    else 
        _head = _head->next();
    p->next() = nullptr;
    delete p;
    --_elements;
}

template<class T>
void LinkedList<T>::remove(const T& key) {
    if (isEmpty())
        return;

    Node<T>* curr;
    Node<T>* prev;
    curr = _head;
    prev = nullptr;

    while (curr && curr->getKey() == key) {
        prev = curr;
        curr = curr->next();
    }
    
    if (!curr) return;
    prev->next() = curr->next();
    curr->next() = nullptr;
    delete curr;
    --_elements;
}

template<class T>
void LinkedList<T>::clear() {
    while (_head)
        this->shift();
}

template<class T>
Node<T>* LinkedList<T>::front() {
    return _head;
}

template<class T>
Node<T>* LinkedList<T>::back() {
    return _tail;
}

template<class T>
LinkedList<T>::~LinkedList() {
    this->clear();
}

#endif