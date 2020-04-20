//
// Created by Maor Roizman Gheiler on 4/19/20.
//

#ifndef CS2100_LIST_MRG2000_LIST_H
#define CS2100_LIST_MRG2000_LIST_H

#include <iostream>
#include "Node.h"

using namespace std;


template <typename T>
class List {
protected:
    Node<T> *head;
    Node<T>* tail;
    int nodes;

public:
    List(List& list){
        // Constructor copia
        for (int i=0;i<nodes;i++){
            push_back(list[i]);
        }
    }

    List(T*){
        //Constructor  parametro,
        //llena una lista a partir de un array
    }

    List(Node<T>* node){
        //Constructor por parametro,
        //retorna una lista con un nodo
        auto *temp = new Node<T>;
        temp->value = node->value;
        temp->next = this->head;
        this->head = temp;
        nodes++;
    }

    List(int n){
        //Constructor por parametro,
        //retorna un lista de randoms de tamaño n
        for(int i=0;i<n;i++){
            T num = i;
            push_front(num);
        }
    }

    //Constructor por defecto
    List() : head(nullptr), tail(nullptr), nodes(0) {};

    ~List(void){};

    // Retorna una referencia al primer elemento
    virtual T front() = 0;

    // Retorna una referencia al ultimo elemento
    virtual T back() = 0;

    // Inserta un elemento al final
    virtual void push_back(const T& element) = 0;

    // Inserta un elemento al inicio
    virtual void push_front(const T& element) = 0;

    // Quita el ultimo elemento y retorna una referencia
    virtual void pop_back() = 0;

    // Quita el primer elemento y retorna una referencia
    virtual void pop_front() = 0;

    // Acceso aleatorio
    T& operator[] (const int& index){
        if (index < this->nodes && this->head != nullptr) {
            auto temp = this->head;
            for (unsigned int i = 0; i < index; i++) temp = temp->next;
            return temp->value;
        }
        throw out_of_range("Index out of range");
    };

    // la lista esta vacia?
    bool empty(){
        return this->nodes == 0;
    };

    // retorna el tamaño de la lista
    unsigned int size(){
        return this->nodes;
    };

    // Elimina toda la lista
    void clear(){
        this->head->killSelf(nullptr);
        this->head=nullptr;
        this->tail=nullptr;
        this->nodes=0;
    };

    // Elimina un elemento en base a un puntero
    //virtual void erase(Node<T>*) = 0;

    // Inserta un elemento  en base a un puntero
    //virtual void insert(Node<T>*, const T&) = 0;

    // Elimina todos los elementos por similitud
    //virtual void remove(const T&) = 0;

    // ordena la lista
    //virtual void sort() = 0;

    // invierte la lista
    virtual void reverse() = 0;

    // Imprime la lista con cout
    friend ostream& operator << (ostream &os, List & list) {
        auto temp= list.head;
        for(int i=0;i< list.nodes;i++){
            cout<<list.operator[](i)<<" ";
        }
        return os;
    }
};

#endif //CS2100_LIST_MRG2000_LIST_H
