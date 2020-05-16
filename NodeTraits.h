//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_NODETRAITS_H
#define TEST_LISTAS_FINAL_NODETRAITS_H


#include <iostream>
#include "forwardNode.h"
#include "doubleNode.h"
#include "circularNode.h"


#define DEFAULT_NODE 0
#define FOWARD_NODE 1
#define DOUBLE_NODE 2
#define CIRCULAR_NODE 3

using namespace std;

template <typename T, typename NT>
struct NodeTraits{
    static const int nodeType = DEFAULT_NODE;
};

template <typename NT>
struct NodeTraits< ForwardListNode<NT>, NT >{
static const int nodeType = FOWARD_NODE;
};

template <typename NT>
struct NodeTraits< DoubleListNode<NT>, NT >{
static const int nodeType = DOUBLE_NODE;
};

template <typename NT>
struct NodeTraits< CircularListNode<NT>, NT >{
    static const int nodeType = CIRCULAR_NODE;
};




#endif //TEST_LISTAS_FINAL_NODETRAITS_H
