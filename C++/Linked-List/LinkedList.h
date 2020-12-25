/**
 *
 * LinkedList.h
 *
 * Created by Huy Le Minh on 2020-12-24
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Linked List
*/


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
    T _trash;
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
    
    Node<T>*& front();
    Node<T>*& back();

    void remove(const T& key);
    void clear();

    void print();

    //TODO: finish these functions below
    void sort(bool (*compare)(const T&, const T&));
    //TODO:---------------------------------------------

    ~LinkedList();
};


#ifndef _LINKED_LIST_CPP_
#include "LinkedList.cpp"
#endif

#endif