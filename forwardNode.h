//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_FORWARDNODE_H
#define TEST_LISTAS_FINAL_FORWARDNODE_H

#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class ForwardListNode : public Node<T> {
public:
    typedef typename Node<T>::value_t value_t;

public:
    ForwardListNode<T>* next;

public:
    ForwardListNode(const T& _value):Node<T>(_value),next(nullptr){
    }

    ~ForwardListNode(void){
    }

    template <typename _T>
    inline friend ostream& operator<< (ostream& _out, const ForwardListNode<_T>& _node){
        _out << "Nodo: [v: " <<  _node.value << ", p: " << _node.next << "]";
        return _out;
    }
};

#endif //TEST_LISTAS_FINAL_FORWARDNODE_H
