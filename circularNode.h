//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_CIRCULARNODE_H
#define TEST_LISTAS_FINAL_CIRCULARNODE_H

#include<iostream>
#include "Node.h"
using namespace std;

template <typename T>
class CircularListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    CircularListNode<T>* next;

public:
    CircularListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~CircularListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const CircularListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p_next: " << _node.next << ", p_prev: " << _node.next << "]";
        return _out;
    }
};




#endif //TEST_LISTAS_FINAL_CIRCULARNODE_H
