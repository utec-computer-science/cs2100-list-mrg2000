//
// Created by Maor Roizman Gheiler on 5/11/20.
//

#ifndef TEST_LISTAS_FINAL_LISTHELPER_H
#define TEST_LISTAS_FINAL_LISTHELPER_H


#include <iostream>
#include "List.h"
#include "Node.h"
#include "forwardNode.h"
#include "doubleNode.h"
#include "circularNode.h"
using namespace std;

template <typename Node, typename ValueNode, int nodeType>
class ListHelper{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size);
    static void push_front(Node** head, Node** tail, ValueNode element, int& size);
    static void pop_back(Node** head, Node** tail, int& size);
    static void pop_front(Node** head, Node** tail, int& size);
    static void clear(Node** head, Node** tail, int& size);
    static void erase(Node** head, Node** tail, ValueNode element, int& size);

    static void print(Node** head, Node** tail, ValueNode element);

    //ITERATORS

    friend Node** begin(Node** head);
    friend Node** end(Node** tail);

};



template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,FOWARD_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){

        auto * new_node = new ForwardListNode<ValueNode>(element);
        new_node->next = nullptr;
        new_node->value = element;

        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;

        }else{
            auto temp = (*head);
            (*tail)-> next = new_node;
            (*tail) = new_node;

        }
        size++;
    }

    static void push_front(Node** head, Node** tail, ValueNode element, int& size){

        auto * new_node = new ForwardListNode<ValueNode>(element);
        new_node->value = element;
        new_node->next = nullptr;

        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;

        }else{
            new_node->next = *head;
            *head = new_node;

        }
        size++;
    }


    static void pop_back(Node** head, Node** tail, int& size){

        if(size){
            auto * temp = (*head);

            for(int i = 0; i < (size-2); ++i){
                temp = temp->next;
            }

            temp->next = (*head);
            delete (*tail);
            (*tail) = temp;

            --size;
        }
    }


    static void pop_front(Node** head, Node** tail, int& size){

        if (*head) {
            auto * temp = (*head);
            (*head) = temp->next;
            temp->next = nullptr;
            delete temp;

        }
        --size;

    }


    static void clear(Node** head, Node** tail, int& size){

        while(size) {
            pop_front(head, tail, size);
        }

    }

    static void print(Node** head, Node** tail, ValueNode element){


    }


    //ITERATORS
    static Node** begin(Node** head){
        return head;
    }

    static Node** end(Node** tail){
        return tail;
    }

};



template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,DOUBLE_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){

        auto new_node = new DoubleListNode<ValueNode>(element);
        new_node->value = element;

        if (!(*head)) {
            (*head) = new_node;
        } else {
            new_node->prev = (*tail);
            new_node->next = nullptr;
            (*tail)->next = new_node;
        }
        *tail = new_node;
        size++;
    }

    static void pop_back(Node** head, Node** tail, int& size){

        if(size){
            DoubleListNode<ValueNode>* temp = *tail;
            *tail = (*tail)->prev;
            (*tail)->next = nullptr;
            delete temp;
            size--;
        }
    }

    static void pop_front(Node** head, Node** tail, int& size){

        if (*head) {
            auto * temp = (*head);
            (*head) = temp->next;
            temp->next = nullptr;
            delete temp;

        }
        size--;

    }


    static void clear(Node** head, Node** tail, int& size){

        while(size)
            pop_front(head,tail,size);

    }

    static void erase(Node** head, Node** tail, ValueNode element, int& size){
        auto * temp = (*head);

        if (!element){
            pop_front(head, tail, size);

        }
        else{
            for (int i = 0; i < element; ++i){
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp = nullptr;
            delete temp;
        }

        size --;
    }

    //ITERATORS
    static Node** begin(Node** head){
        return head;
    }

    static Node** end(Node** tail){
        return tail;
    }


};

template <typename Node, typename ValueNode>
class ListHelper<Node,ValueNode,CIRCULAR_NODE>{
public:
    static void push_back(Node** head, Node** tail, ValueNode element, int& size){

        auto * new_node = new CircularListNode<ValueNode>(element);
        new_node->value = element;
        new_node->next = (*head);

        if(*head == nullptr){
            *head = new_node;
            *tail = new_node;
        }else{
            (*tail)->next = new_node;
            (*tail) = new_node;
        }
        size++;
    }

    static void pop_back(Node** head, Node** tail, int& size){

        if(size > 0){
            auto * temp = (*head);

            for(int i = 0; i < size -2; ++i){
                temp = temp->next;
            }

            temp->next = (*head);
            delete (*tail);
            (*tail) = temp;

            size--;
        }
    }


    //ITERATORS
    static Node** begin(Node** head){
        return head;
    }

    static Node** end(Node** tail){
        return tail;
    }

};


template< typename Node>  template <int nodeType>
void List<Node>::__push_back__(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element,
        int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_back(head,tail,element, size);
}


template< typename Node>  template <int nodeType>
void List<Node>::__push_front__(
        typename List<Node>::node_t ** head,
        typename List<Node>::node_t ** tail,
        typename List<Node>::value_t element,
        int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::push_front(head,tail,element, size);
}

template< typename Node>  template <int nodeType>
void List<Node>::__pop_back__(typename List<Node>::node_t ** head,
                              typename List<Node>::node_t ** tail,
                              int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_back(head,tail,size);
}

template< typename Node>  template <int nodeType>
void List<Node>::__pop_front__(typename List<Node>::node_t ** head,
                               typename List<Node>::node_t ** tail,
                               int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::pop_front(head,tail,size);
}

template< typename Node>  template <int nodeType>
void List<Node>::__clear__(typename List<Node>::node_t ** head,
                           typename List<Node>::node_t ** tail,
                           int& size) {

        ListHelper<List<Node>::node_t, List<Node>::value_t, nodeType>::clear(head, tail, size);
}


template< typename Node>  template <int nodeType>
void List<Node>::__erase__(typename List<Node>::node_t ** head,
                           typename List<Node>::node_t ** tail,
                           typename List<Node>::value_t element,
                           int& size){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::erase(head,tail, element, size);
}





// ITERATORS
template< typename Node>  template <int nodeType>
Node** List<Node>::__begin__(typename List<Node>::node_t ** head){

        ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::begin(head);
}

template< typename Node>  template <int nodeType>
Node** List<Node>::__end__(typename List<Node>::node_t ** tail){

    ListHelper<List<Node>::node_t,List<Node>::value_t,nodeType>::end(tail);
}




#endif //LISTAS_LISTHELPER_H
