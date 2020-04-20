//
// Created by Maor Roizman Gheiler on 4/15/20.
//

#ifndef ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_H
#define ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_H


#include "Node.h"


namespace mrg {
template<typename T>
class iterator {
protected:
    Node<T> *current;

public:
    iterator() : current(nullptr) {};

    iterator(Node<T> *node) : current(node) {};

};


};




#endif //ELEMENTARY_DATA_STRUCTURES_MRG2000_ITERATOR_H
