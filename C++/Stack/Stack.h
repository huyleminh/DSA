/**
 *
 * MyStack.h
 *
 * Created by Huy Le Minh on 2020-12-25
 *
 * Visit my github: https://github.com/huyleminh/
 * Contact me: leminhhuy.hcmus@gmail.com
 *
 *
 * File description: Implement Stack structure
*/


#ifndef _STACK_H_
#define _STACK_H_

#include "../Linked-List/LinkedList.h"

template <class T>
class Stack : protected LinkedList<T> {
public:
    //Constructors
    Stack() : LinkedList<T>() {}
    Stack(const T& key) : LinkedList<T>(key) {}

    //Copy constructor
    Stack(const Stack<T>& st) : LinkedList<T>(st) {}

    //Assignment operator
    Stack& operator=(const Stack& st);

    //Using inheritance method
    using LinkedList<T>::isEmpty;
    using LinkedList<T>::size;

    using LinkedList<T>::push;
    using LinkedList<T>::pop;

    using LinkedList<T>::clear;

    using LinkedList<T>::print;

    T& top();

    ~Stack() {
        this->clear();
    }
};

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& st) {
    (LinkedList<T>&)(*this) = st;
    return *this;
}

template<class T>
T& Stack<T>::top() {
    Node<T>* t = this->back();

    //!If stack is empty return a trash value of type T
    if (!t) {
        cout << "Warning trash value! : ";
        return this->_trash;
    }
    return t->getKey();
}

#endif