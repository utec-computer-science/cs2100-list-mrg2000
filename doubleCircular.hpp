#include <iostream>
#include "List.h"

using namespace std;


namespace mrg {

    template<typename T>
    class circularLinkedList : public list<T> {
    public:

        circularLinkedList<T>() : list<T>() {};


        T front() {
            if (this->head == nullptr) {
                cout << "No se puede realizar funcion front, circularList VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->head->value;
        };

        T back_tail() {
            if (this->tail == nullptr) {
                cout << "No se puede realizar funcion back, circularList VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->tail->value;
        };

        T back_no_tail() {
            if (this->head != nullptr)
                return this->head->prev->value;
            throw out_of_range("Lista vacia");

        };

        void push_front(T value) {
            node<T> *temp=new node<T>;
            temp->value=value;
            if (this->head==nullptr){
                this->head=temp;
                this->tail=temp;
            }else{
                temp->next=this->head;
                (this->head)->prev=temp;
                this->head=temp;
                this->head->prev=this->tail;
                this->tail->next=this->head;
            }
            this->number_nodes++;
        };

        void push_back_tail(T value) {
            node<T>* temp=new node<T>;
            temp->value=value;
            temp->next=this->head;
            if(this->head==nullptr){
                temp->prev=temp;
                this->head=temp;
                this->tail=temp;
            }
            else{
                temp->prev=this->tail;
                this->tail->next=temp;
                this->tail=temp;
            }
            this->number_nodes++;
            this->head->prev=temp;

        };

        void push_back_no_tail(T) {
            //No es necesario, no utiliza el tail
        };

        void pop_front() {
            if(this->head!= nullptr){
                auto temp=this->head;
                this->number_nodes--;

                if(this->number_nodes==0){
                    this->head= nullptr;
                }else{
                    this->head->prev->next=this->head->next;
                    this->head->next->prev=this->head->prev;
                    this->head=this->head->next;
                }
                delete temp;
            }
        };


        void pop_back_tail() {
            if(this->head!= nullptr){
                auto temp=this->head->prev;
                this->number_nodes--;

                if(this->number_nodes==0){
                    this->head= nullptr;
                } else{
                    this->head->prev->prev->next=this->head;
                    this->head->prev=this->head->prev->prev;
                }
                delete temp;
            }
        };

        void pop_back_no_tail() {
            //No es necesario, no utiliza tail
        };


        virtual T operator[](int index) {

            if (index < this->number_nodes && this->head != nullptr) {
                auto cont = 0;
                auto temp = this->head;
                if (index <= (this->number_nodes / 2)) {
                    while (cont != index) {
                        temp = temp->next;
                        cont++;
                    }
                } else { //Evaluar la mitad a la que pertenece para optimizar recursos.
                    temp = this->tail;
                    while ((index + cont) < this->size() - 1) {
                        temp = temp->prev;
                        cont++;
                    }
                }
                return temp->value;
            }
            throw out_of_range("El indice esta fuera del rango");
        };


        simpleIterator<T> begin() {
            return simpleIterator<T> (this->head);
        }

        simpleIterator<T> end() {
            return simpleIterator<T> (this->head);
        }


    };
}