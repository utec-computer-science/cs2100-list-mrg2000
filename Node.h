
//
// Created by Maor Roizman Gheiler on 4/19/20.
//

#ifndef CS2100_LIST_MRG2000_NODE_H
#define CS2100_LIST_MRG2000_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T> * next;
    Node<T> * prev;

public:
    Node(){};

    ~Node(){};

    void killSelf(Node<T>* node) {
        if(next!=node)
            next->killSelf(node);
        delete this;
    }

    void reverseSingle(Node<T>* node){
        if(next->next!=node)
            next->reverseSingle(node);
        next->next=this;
    }

    void reverseDoubleAndCircular(Node<T>* node){
        if(next!=node){
            next->reverseDoubleAndCircular(node);
        }
        swap(prev,next);
    }
};




#endif //CS2100_LIST_MRG2000_NODE_H
