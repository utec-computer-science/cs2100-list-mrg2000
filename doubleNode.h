//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_DOUBLENODE_H
#define TEST_LISTAS_FINAL_DOUBLENODE_H

#include<iostream>
#include "Node.h"
using namespace std;

template <typename T>
class DoubleListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    DoubleListNode<T>* next;
    DoubleListNode<T>* prev;

public:
    DoubleListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~DoubleListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const DoubleListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};

#endif //TEST_LISTAS_FINAL_DOUBLENODE_H
