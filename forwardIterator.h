//
// Created by Maor Roizman Gheiler on 4/15/20.
//

#ifndef ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H
#define ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H

#include "iostream"
#include "Node.h"
#include "iterator.h"



template <typename T>
class forwardIterator : public mrg::iterator<T> {

public:
    forwardIterator() : mrg::iterator<T>() {};
    forwardIterator(Node<T> *node) : mrg::iterator<T>(node) {};

    forwardIterator<T> operator=(forwardIterator<T> other) {
        return (*this);
    }

    bool operator!=(forwardIterator<T> other) {
        return this->current!=other.current;
    }

    forwardIterator<T> operator++() {
        this->current=this->current->next;
        return (*this);
    }

    T operator*() {
        return this->current->value;
    }

};

#endif //ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H
