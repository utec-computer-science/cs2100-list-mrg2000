#include <iostream>
#include "List.h"
#include "iterator_simple.h"

using namespace std;


namespace mrg {

    template<typename T>
    class circular : public List<T> {
    public:

        circular<T>() : List<T>() {};


        T front() {
            if (this->head == nullptr) {
                cout << "No se puede realizar funcion front, circularList VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->head->value;
        };

        T back() {
            if (this->tail == nullptr) {
                cout << "No se puede realizar funcion back, circularList VACIA" << endl;
                exit(EXIT_FAILURE);
            }
            return this->tail->value;
        };


        void push_back(const T& value) {
            Node<T>* temp=new Node<T>;
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
            this->nodes++;
            this->head->prev=temp;

        };

        void push_front(const T& value) {
            Node<T> *temp=new Node<T>;
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
            this->nodes++;
        };

        void pop_back() {
            if(this->head!= nullptr){
                auto temp=this->head->prev;
                this->nodes--;

                if(this->nodes==0){
                    this->head= nullptr;
                } else{
                    this->head->prev->prev->next=this->head;
                    this->head->prev=this->head->prev->prev;
                }
                delete temp;
            }
        };


        void pop_front() {
            if(this->head!= nullptr){
                auto temp=this->head;
                this->nodes--;

                if(this->nodes==0){
                    this->head= nullptr;
                }else{
                    this->head->prev->next=this->head->next;
                    this->head->next->prev=this->head->prev;
                    this->head=this->head->next;
                }
                delete temp;
            }
        };


        void reverse() {
            if(this->nodes){
                this->head->reverseDoubleAndCircular(this->head);
                swap(this->head,this->tail);
            }
        };



        simpleIterator<T> begin() {
            return simpleIterator<T> (this->head);
        }

        simpleIterator<T> end() {
            return simpleIterator<T> (this->head);
        }


    };
}