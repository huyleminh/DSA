/**
 *
 * Queue.h
 *
 * Created by Huy Le Minh on 2020-12-25
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Queue structure
*/


#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../Linked-List/LinkedList.h"

template <class T>
class Queue : protected LinkedList<T> {
public:
    //Constructors
    Queue() : LinkedList<T>() {}
    Queue(const T& key) : LinkedList<T>(key) {}

    //Copy constructor
    Queue(const Queue<T>& q) : LinkedList<T>(q) {}

    //Assignment operator
    Queue& operator=(const Queue& q);

    //Using inheritance method
    using LinkedList<T>::isEmpty;
    using LinkedList<T>::size;

    using LinkedList<T>::push;
    using LinkedList<T>::shift;

    using LinkedList<T>::clear;

    using LinkedList<T>::print;

    T& deQueue();

    ~Queue() {
        this->clear();
    }   
};

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& st) {
    (LinkedList<T>&)(*this) = st;
    return *this;
}

template<class T>
T& Queue<T>::deQueue() {
    Node<T>* fr = this->front();

    //!If queue is empty return a trash value of type T
    if (!fr) {
        cout << "Warning trash value! : ";
        return this->_trash;
    }
    return fr->getKey();
}

#endif