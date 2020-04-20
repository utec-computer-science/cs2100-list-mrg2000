//
// Created by Maor Roizman Gheiler on 4/15/20.
//

#ifndef ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H
#define ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H

#include "iostream"
#include "Node.h"
#include "iterator.h"



template <typename T>
class simpleIterator : public mrg::iterator<T> {

public:
    simpleIterator() : mrg::iterator<T>() {};
    simpleIterator(Node<T> *node) : mrg::iterator<T>(node) {};

    void operator ++(){
        this->current = this->current->next;
    }


    T operator *(){
        if(this->current!= nullptr)
            return this->current->value;
        std::cout << "LISTA VACIA";
        exit(EXIT_FAILURE);
    }


    bool operator == (const simpleIterator & it){
        return this->current == it.current;
    }

    bool operator != (const simpleIterator & it){
        return this->current != it.current;
    }

    /* //Probando impresion desde el iterador
    friend void operator <<(ostream &os, simpleIterator& it){
        while(it.current->next != nullptr){
            os << " " << *it;
            it.current = it.current->next;
        }
    }
     */

};

#endif //ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_SIMPLE_H
